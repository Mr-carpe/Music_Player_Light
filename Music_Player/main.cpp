#include "include/Song.h"
#include "include/Player.h"
#include <iostream>
#include <Windows.h>
#include <thread>
#include <string>
using namespace std;

void downloadLyric(Song& song)
{
    //  I set a static ip 192.168.139.100
    song.LiricDownload("192.168.139.100");
}


// test for connection with nginx server
int main() {
    // create a song object and set its properties
    Song song("My Heart", "Celine Dion", "Album", "./Song_File/");

    std::thread lyricThread(downloadLyric, std::ref(song));

    lyricThread.join();

    return 0;
}

//  you can write a test for AudioPlayer to control the state of Song by Player