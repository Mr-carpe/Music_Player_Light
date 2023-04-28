# 项目介绍 Project Introduction

本项目为基于C++的音乐播放器，实现了基本的音乐播放器功能，并可作为基类扩展具有个性化的功能。同时，提供了歌词文件的下载功能，并提供了静态IP地址以便使用者进行测试和开发者添加线程池，也可自行使用NGINX服务器进行测试。

本项目在Windows平台下使用Visual Studio 2022进行开发，MySQL和NGINX使用Docker容器进行托管。

为方便使用者，未提供Boost库的预编译二进制文件，使用者可自行进行安装编译链接。如果您在使用过程中遇到任何问题，欢迎联系我。

This project is a music player based on C++, which implements basic music player functions and can be used as a base class to extend personalized features. At the same time, it provides the function of downloading lyrics files and a static IP address for users to test. Developers can also add a thread pool or use an NGINX server for testing.

This project is developed using Visual Studio 2022 on the Windows platform, and MySQL and NGINX are hosted using Docker containers.

For the convenience of users, precompiled binary files of Boost library are not provided. Users need to install, compile and link them by themselves. If you encounter any problems during use, please feel free to contact me.

# 项目使用 Project Usage

## 依赖项 Dependencies

本项目依赖Boost库，使用者需自行安装编译链接。MySQL和NGINX使用Docker容器进行托管，使用者需自行配置相关环境。

This project depends on the Boost library, and users need to install, compile and link it themselves. MySQL and NGINX are hosted using Docker containers, and users need to configure the relevant environment themselves.

## 下载歌词文件 Downloading Lyrics Files

使用`Song`类提供的`LiricDownload`方法，使用者可从静态IP地址`192.168.139.100`上下载歌词文件，示例代码如下：

Users can download lyrics files from the static IP address 192.168.139.100 using the LiricDownload method provided by the Song class. The example code is as follows:

```cpp
void downloadLyric(Song& song)
{
    song.LiricDownload("192.168.139.100");
}

Song song("My Heart", "Celine Dion", "Album", "./Song_File/");
std::thread lyricThread(downloadLyric, std::ref(song));
```

执行上述代码后，控制台输出：

After executing the above code, the console will output:

```
GET /lyric/My%20Heart.txt HTTP/1.1
Host: 192.168.139.100
Connection: close

Lyric downloaded and saved to Song_File/My Heart.txt
```

## 扩展功能 Extending Functions

使用本项目作为基类，可扩展具有个性化的音乐播放器。欢迎开发者提出问题和改进建议。

By using this project as a base class, users can extend their own personalized music player. Developers are welcome to propose questions and suggestions for improvement.

## 反馈与建议 Feedback and Suggestions

如果您在使用过程中遇到任何问题或对本项目有任何建议和改进，欢迎与我联系。同时，欢迎分享您使用本项目扩展自己的项目的经验和心得。

If you encounter any problems during use or have any suggestions and improvements for this project, please feel free to contact me. At the same time, I welcome you to share your experience and insights in using this project to extend your own project.
