#ifndef SONG_H
#define SONG_H

#include <string>
#include <fstream>
#include <iostream>
#include <boost\asio.hpp>
#include <boost\filesystem.hpp>

using boost::asio::ip::tcp;

class Song {

private:

    std::string title_;

    std::string artist_;

    std::string album_;

    std::string filePath_;

    std::string lyricFilePath_;



public:

    Song() = default;

    Song(const std::string& title, const std::string& artist, const std::string& album, const std::string& filePath);

    std::string getTitle() const;

    std::string getArtist() const;

    std::string getAlbum() const;

    std::string getFilePath() const;

    std::string getLyricFilePath() const;

    void setTitle(const std::string& Title);

    void setArtist(const std::string& Artist);

    void setAlbum(const std::string& Album);

    void setFilePath(const std::string& FilePath);

    void setLyricFilePath(const std::string& lyricFilePath);

    void LiricDownload(const std::string& url);


    // other methods if need
};

#endif // SONG_H
