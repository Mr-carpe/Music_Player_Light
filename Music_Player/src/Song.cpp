#include "../include/Song.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>

Song::Song(const std::string& title, const std::string& artist, const std::string& album, const std::string& filePath)

    : title_(title), artist_(artist), album_(album), filePath_(filePath) {}



std::string Song::getTitle() const {

    return this->title_;

}



std::string Song::getArtist() const {

    return this->artist_;

}



std::string Song::getAlbum() const {

    return this->album_;

}



std::string Song::getFilePath() const {

    return this->filePath_;

}



std::string Song::getLyricFilePath() const {

    return this->lyricFilePath_;

}



void Song::setTitle(const std::string& Title) {

    this->title_ = Title;

}



void Song::setArtist(const std::string& Artist) {

    this->artist_ = Artist;

}


void Song::setAlbum(const std::string& Album) {

    this->album_ = Album;

}


void Song::setFilePath(const std::string& FilePath) {

    this->filePath_ = FilePath;

}



void Song::setLyricFilePath(const std::string& lyricFilePath) {

    this->lyricFilePath_ = lyricFilePath;

}


void Song::LiricDownload(const std::string& url) {
    try {
        // 创建 Boost.Asio 的 I/O 上下文
        boost::asio::io_context io_context;

        // 创建解析器解析 URL 中的主机名和端口
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve(url, "http");

        // 创建套接字连接到服务器
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // 构建 GET 请求
        std::string title = this->getTitle();

        // 解决服务器url资源空格化为%20
        boost::replace_all(title, " ", "%20");

        std::string request = boost::str(boost::format("GET /lyric/%s.txt HTTP/1.1\r\nHost: 192.168.139.100\r\nConnection: close\r\n\r\n") % title);
        std::cout << request << std::endl;

        // 发送请求并读取响应
        boost::system::error_code error;
        boost::asio::write(socket, boost::asio::buffer(request), error);
        if (error)
        {
            std::cerr << "Failed to send request: " << error.message() << "\n";
            return;
        }

        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n\r\n");

        io_context.run();

        // 检查响应是否成功
        std::istream response_stream(&response);
        std::string http_version;
        response_stream >> http_version;
        unsigned int status_code;
        response_stream >> status_code;
        std::string status_message;
        std::getline(response_stream, status_message);
        if (!response_stream || http_version.substr(0, 5) != "HTTP/")
        {
            std::cerr << "Invalid response\n";
            return;
        }
        if (status_code != 200)
        {
            std::cerr << "Response returned with status code "
                << status_code << "\n";
            return;
        }

        // 创建Song_File目录
        boost::filesystem::path song_dir("/Song_File");
        if (!boost::filesystem::exists(song_dir))
        {
            if (!boost::filesystem::create_directory(song_dir))
            {
                std::cerr << "Failed to create directory Song_File\n";
                return;
            }
        }

        // 读取响应正文并保存到文件中
        std::string lyric_filename = "Song_File/" + this->getTitle() + ".txt";
        std::ofstream lyric_file(lyric_filename);
        if (!lyric_file)
        {
            std::cerr << "Failed to open file for writing\n";
            return;
        }

        // 读取响应正文
        std::string content;
        while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error))
        {
            content.append(boost::asio::buffer_cast<const char*>(response.data()), response.size());
            response.consume(response.size());
        }

        // 写入歌词文件
        lyric_file << content;
        std::cout << "Lyric downloaded and saved to " << lyric_filename << "\n";

    }
    catch (const boost::system::system_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    
}


// implement other methods if needed
