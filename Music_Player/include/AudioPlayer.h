#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include <string>
#include <iostream>


class AudioPlayer {

private:

    bool isPlaying_ = false;

    std::string filePath_;



public:

    AudioPlayer() = default;

    ~AudioPlayer() = default;

    bool open(const std::string& filePath);

    void play();

    void pause();

    void resume();

    void stop();
    // other methods if needed

};

#endif // AUDIO_PLAYER_H


