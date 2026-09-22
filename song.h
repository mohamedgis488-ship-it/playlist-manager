#ifndef SONG_H
#define SONG_H

#include "MediaItem.h"

class Song : public MediaItem
{
private:
    string artist;
    string genre;

public:
    Song(string t, string a, int d, string g);

    void play() override;
    string getInfo() override;

    string getArtist();
    string getGenre();

    void setArtist(string a);
    void setGenre(string g);
};

#endif