#include "PlayQueue.h"
#include <iostream>

PlayQueue::PlayQueue()
{
    front = nullptr;
    rear = nullptr;
    size = 0;
}

void PlayQueue::enqueue(MediaItem* item)
{
    Node* newNode = new Node(item);

    if (rear == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}

MediaItem* PlayQueue::dequeue()
{
    if (front == nullptr)
        return nullptr;

    Node* temp = front;
    MediaItem* item = temp->item;

    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete temp;
    size--;

    return item;
}

void PlayQueue::printQueue()
{
    Node* current = front;

    while (current != nullptr)
    {
        cout << current->item->getInfo() << endl;
        current = current->next;
    }
}

bool PlayQueue::isEmpty()
{
    return front == nullptr;
}

PlayQueue::~PlayQueue()
{
    Node* current = front;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}