#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "MediaItem.h"

class Playlist
{
private:
    struct Node
    {
        MediaItem* item;
        Node* next;
        Node* prev;

        Node(MediaItem* i)
        {
            item = i;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

    Node* current;

    int totalDurationRecursive(Node* node);

public:
    Playlist();

    void add(MediaItem* item);
    void remove(string title);

    void printForward();
    void printBackward();

    int getTotalDuration();

    void play();
    void next();
    void previous();

    ~Playlist();
};

#endif