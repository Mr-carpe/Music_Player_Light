#include "../include/AudioPlayer.h"

bool AudioPlayer::open(const std::string& filePath) {

    std::cout << "Opening audio file: " << filePath << std::endl;

    filePath_ = filePath;

    return true;

}



void AudioPlayer::play() {

    std::cout << "Playing audio file: " << filePath_ << std::endl;

    isPlaying_ = true;

}



void AudioPlayer::pause() {

    std::cout << "Pausing audio file: " << filePath_ << std::endl;

    isPlaying_ = false;

}



void AudioPlayer::resume() {

    std::cout << "Resuming audio file: " << filePath_ << std::endl;

    isPlaying_ = true;

}



void AudioPlayer::stop() {

    std::cout << "Stopping audio file: " << filePath_ << std::endl;

    isPlaying_ = false;

}

