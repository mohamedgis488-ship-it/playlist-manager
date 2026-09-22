#ifndef LIBRARY_H
#define LIBRARY_H

#include "MediaItem.h"

class Library
{
private:
    MediaItem* items[100];
    int count;

    int partition(int low, int high);
    void quickSort(int low, int high);

public:
    Library();

    void add(MediaItem* item);
    void remove(string title);
    void display();

    MediaItem* binarySearch(string title);
    MediaItem* findByTitle(string title);

    void filterByArtist(string artist);
    void filterByGenre(string genre);

    void sortByTitle();
    void sortByDuration();
    void sortByPlayCount();

    int getCount();
    int getTotalDuration();

    ~Library();
};

#endif