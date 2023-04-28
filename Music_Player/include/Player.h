#ifndef PLAYER_H
#define PLAYER_H

#include "Song.h"
#include "AudioPlayer.h"

enum class PlayerState {

    Stopped,

    Playing,

    Paused

};


class Player {

private:

    Song song_;

    AudioPlayer audioPlayer_;

    PlayerState state_ = PlayerState::Stopped;



public:
    Player() = default;

    ~Player() = default;

    void setSong(const Song& song);

    void play();

    void pause();

    void stop();

    //other methods if needed

};

#endif // PLAYER_H

