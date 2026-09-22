#include "Library.h"
#include "Song.h"
#include "Podcast.h"
#include <iostream>

Library::Library()
{
    count = 0;
}

void Library::add(MediaItem* item)
{
    if (count < 100)
    {
        items[count] = item;
        count++;
    }
}

void Library::remove(string title)
{
    for (int i = 0; i < count; i++)
    {
        if (items[i]->getTitle() == title)
        {
            delete items[i];

            for (int j = i; j < count - 1; j++)
            {
                items[j] = items[j + 1];
            }

            count--;
            return;
        }
    }
}

void Library::display()
{
    for (int i = 0; i < count; i++)
    {
        cout << items[i]->getInfo() << endl;
    }
}

MediaItem* Library::binarySearch(string title)
MediaItem* Library::findByTitle(string title)
{
    for (int i = 0; i < count; i++)
    {
        if (items[i]->getTitle() == title)
        {
            return items[i];
        }
    }

    return nullptr;
}
{
    int low = 0;
    int high = count - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (items[mid]->getTitle() == title)
            return items[mid];

        if (items[mid]->getTitle() < title)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return nullptr;
}

void Library::filterByArtist(string artist)
{
    for (int i = 0; i < count; i++)
    {
        Song* song = dynamic_cast<Song*>(items[i]);

        if (song != nullptr && song->getArtist() == artist)
        {
            cout << song->getInfo() << endl;
        }
    }
}

void Library::filterByGenre(string genre)
{
    for (int i = 0; i < count; i++)
    {
        Song* song = dynamic_cast<Song*>(items[i]);

        if (song != nullptr && song->getGenre() == genre)
        {
            cout << song->getInfo() << endl;
        }
    }
}

void Library::sortByTitle()
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (items[j + 1]->getTitle() < items[j]->getTitle())
            {
                MediaItem* temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void Library::sortByDuration()
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (items[j + 1]->getDuration() < items[j]->getDuration())
            {
                MediaItem* temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void Library::sortByPlayCount()
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (items[j + 1]->getPlayCount() > items[j]->getPlayCount())
            {
                MediaItem* temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int Library::getCount()
{
    return count;
}

int Library::getTotalDuration()
{
    int total = 0;

    for (int i = 0; i < count; i++)
    {
        total += items[i]->getDuration();
    }

    return total;
}

Library::~Library()
{
    for (int i = 0; i < count; i++)
    {
        delete items[i];
    }
}