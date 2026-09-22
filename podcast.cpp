#include "Podcast.h"
#include <iostream>

Podcast::Podcast(string t, string h, int d, int e)
    : MediaItem(t, d)
{
    host = h;
    episodeNumber = e;
}

void Podcast::play()
{
    playCount++;
    cout << "Playing podcast: " << title << endl;
}

string Podcast::getInfo()
{
    return title + " - " + host + " - Episode " + to_string(episodeNumber);
}

string Podcast::getHost()
{
    return host;
}

int Podcast::getEpisodeNumber()
{
    return episodeNumber;
}

void Podcast::setHost(string h)
{
    host = h;
}

void Podcast::setEpisodeNumber(int e)
{
    episodeNumber = e;
}