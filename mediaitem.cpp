#include "MediaItem.h"

MediaItem::MediaItem(string t, int d)
{
    title = t;
    duration = d;
    playCount = 0;
}

string MediaItem::getTitle()
{
    return title;
}

int MediaItem::getDuration()
{
    return duration;
}

int MediaItem::getPlayCount()
{
    return playCount;
}

void MediaItem::setTitle(string t)
{
    title = t;
}

void MediaItem::setDuration(int d)
{
    duration = d;
}

bool MediaItem::operator<(const MediaItem& other)
{
    return title < other.title;
}

MediaItem::~MediaItem()
{
}