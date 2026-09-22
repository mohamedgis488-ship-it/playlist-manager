#include "Playlist.h"
#include <iostream>

Playlist::Playlist()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
    current = nullptr;
}

void Playlist::add(MediaItem* item)
{
    Node* newNode = new Node(item);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        current = head;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    size++;
}

void Playlist::remove(string title)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->item->getTitle() == title)
        {
            if (current->prev != nullptr)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next != nullptr)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            delete current;
            size--;
            return;
        }

        current = current->next;
    }
}

void Playlist::printForward()
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->item->getInfo() << endl;
        current = current->next;
    }
}

void Playlist::printBackward()
{
    Node* current = tail;

    while (current != nullptr)
    {
        cout << current->item->getInfo() << endl;
        current = current->prev;
    }
}

int Playlist::totalDurationRecursive(Node* node)
{
    if (node == nullptr)
        return 0;

    return node->item->getDuration() +
           totalDurationRecursive(node->next);
}

int Playlist::getTotalDuration()
{
    return totalDurationRecursive(head);
}

void Playlist::play()
{
    if (current != nullptr)
        current->item->play();

}

void Playlist::next()
{
      if (current != nullptr && current->next != nullptr)
    {
        current = current->next;
        current->item->play();
    }


    
}

void Playlist::previous()
{
    if (current != nullptr && current->prev != nullptr)
    {
        current = current->prev;
        current->item->play();
    }
}

Playlist::~Playlist()
{
    Node* current = head;

    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
}