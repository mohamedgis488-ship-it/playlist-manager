#ifndef PODCAST_H
#define PODCAST_H

#include "MediaItem.h"

class Podcast : public MediaItem
{
private:
    string host;
    int episodeNumber;

public:
    Podcast(string t, string h, int d, int e);

    void play() override;
    string getInfo() override;

    string getHost();
    int getEpisodeNumber();

    void setHost(string h);
    void setEpisodeNumber(int e);
};

#endif