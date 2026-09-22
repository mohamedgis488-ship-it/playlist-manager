#ifndef PLAYQUEUE_H
#define PLAYQUEUE_H

#include "MediaItem.h"

class PlayQueue
{
private:
    struct Node
    {
        MediaItem* item;
        Node* next;

        Node(MediaItem* i)
        {
            item = i;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;
    int size;

public:
    PlayQueue();

    void enqueue(MediaItem* item);
    MediaItem* dequeue();

    void printQueue();
    bool isEmpty();

    ~PlayQueue();
};

#endif