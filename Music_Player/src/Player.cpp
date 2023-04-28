#include "../include/Player.h"

void Player::setSong(const Song& song) {

    song_ = song;

    audioPlayer_.open(song_.getFilePath());

}


void Player::play() {

    audioPlayer_.play();

    state_ = PlayerState::Playing;

}



void Player::pause() {

    audioPlayer_.pause();

    state_ = PlayerState::Paused;

}



void Player::stop() {

    audioPlayer_.stop();

    state_ = PlayerState::Stopped;

}

// implement other methods if needed
