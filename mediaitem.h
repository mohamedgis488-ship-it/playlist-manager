#ifndef MEDIAITEM_H
#define MEDIAITEM_H

#include <string>
using namespace std;

class MediaItem
{
protected:
    string title;
    int duration;
    int playCount;

public:
    MediaItem(string t, int d);

    virtual void play() = 0;
    virtual string getInfo() = 0;

    string getTitle();
    int getDuration();
    int getPlayCount();

    void setTitle(string t);
    void setDuration(int d);

    bool operator<(const MediaItem& other);


    virtual ~MediaItem();
};

#endif