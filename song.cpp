#include "Song.h"
#include <iostream>

Song::Song(string t, string a, int d, string g)
    : MediaItem(t, d)
{
    artist = a;
    genre = g;
}

void Song::play()
{
    playCount++;
    cout << "Playing song: " << title << endl;
}

string Song::getInfo()
{
    return title + " - " + artist + " - " + genre;
}

string Song::getArtist()
{
    return artist;
}

string Song::getGenre()
{
    return genre;
}

void Song::setArtist(string a)
{
    artist = a;
}

void Song::setGenre(string g)
{
    genre = g;
}