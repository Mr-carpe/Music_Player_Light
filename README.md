# 项目介绍

本项目为基于C++的音乐播放器，实现了基本的音乐播放器功能，并可作为基类扩展具有个性化的功能。同时，提供了歌词文件的下载功能，并提供了静态IP地址以便使用者进行测试和开发者添加线程池，也可自行使用NGINX服务器进行测试。

本项目在Windows平台下使用Visual Studio 2022进行开发，MySQL和NGINX使用Docker容器进行托管。

为方便使用者，未提供Boost库的预编译二进制文件，使用者可自行进行安装编译链接。如果您在使用过程中遇到任何问题，欢迎联系我。

# 项目使用

## 依赖项

本项目依赖Boost库，使用者需自行安装编译链接。MySQL和NGINX使用Docker容器进行托管，使用者需自行配置相关环境。

## 下载歌词文件

使用`Song`类提供的`LiricDownload`方法，使用者可从静态IP地址`192.168.139.100`上下载歌词文件，示例代码如下：

```cpp
void downloadLyric(Song& song)
{
    song.LiricDownload("192.168.139.100");
}

Song song("My Heart", "Celine Dion", "Album", "./Song_File/");
std::thread lyricThread(downloadLyric, std::ref(song));
```

执行上述代码后，控制台输出：

```
GET /lyric/My%20Heart.txt HTTP/1.1
Host: 192.168.139.100
Connection: close

Lyric downloaded and saved to Song_File/My Heart.txt
```

## 扩展功能

使用本项目作为基类，可扩展具有个性化的音乐播放器。欢迎开发者提出问题和改进建议。

## 反馈与建议

如果您在使用过程中遇到任何问题或对本项目有任何建议和改进，欢迎与我联系。同时，欢迎分享您使用本项目扩展自己的项目的经验和心得。
