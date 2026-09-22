#include <iostream>
#include "Library.h"
#include "Playlist.h"
#include "PlayQueue.h"
#include "Song.h"
#include "Podcast.h"

using namespace std;
void libraryMenu(Library& library, Playlist& playlist, PlayQueue& queue)
{
    int choice;

    do
    {
        cout << "\n===== LIBRARY =====\n";
        cout << "1. View all media\n";
        cout << "2. Add song\n";
        cout << "3. Add podcast\n";
        cout << "4. Delete media\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
        {
            library.display();
        }
        else if (choice == 2)
        {
            string title, artist, genre;
            int duration;

            cout << "Title: ";
            cin >> title;
            cout << "Artist: ";
            cin >> artist;
            cout << "Duration: ";
            cin >> duration;
            cout << "Genre: ";
            cin >> genre;

            library.add(new Song(title, artist, duration, genre));
        }
        else if (choice == 3)
        {
            string title, host;
            int duration, episode;

            cout << "Title: ";
            cin >> title;
            cout << "Host: ";
            cin >> host;
            cout << "Duration: ";
            cin >> duration;
            cout << "Episode number: ";
            cin >> episode;

            library.add(new Podcast(title, host, duration, episode));
        }
        else if (choice == 4)
        {
            string title;

            cout << "Title to delete: ";
            cin >> title;

            library.remove(title);
        }
        else if (choice != 0)
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
void playlistMenu(Playlist& playlist)
{
    int choice;

    do
    {
        cout << "\n===== PLAYLIST =====\n";
        cout << "1. Play current\n";
        cout << "2. Next\n";
        cout << "3. Previous\n";
        cout << "4. Print forward\n";
        cout << "5. Print backward\n";
        cout << "6. Total duration\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            playlist.play();
            break;

        case 2:
            playlist.next();
            break;

        case 3:
            playlist.previous();
            break;

        case 4:
            playlist.printForward();
            break;

        case 5:
            playlist.printBackward();
            break;

        case 6:
            cout << "Total duration: "
                 << playlist.getTotalDuration()
                 << " seconds\n";
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
void queueMenu(PlayQueue& queue, Library& library)
{
    int choice;

    do
    {
        cout << "\n===== UP NEXT QUEUE =====\n";
        cout << "1. Add item to queue\n";
        cout << "2. Play next item\n";
        cout << "3. Show queue\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {
    string title;

    cout << "Enter title: ";
    cin >> title;

    MediaItem* item = library.findByTitle(title);

    if (item != nullptr)
    {
        queue.enqueue(item);
        cout << "Item added to queue.\n";
    }
    else
    {
        cout << "Item not found.\n";
    }

    break;
}
            

        case 2:
        {
            MediaItem* item = queue.dequeue();

            if (item != nullptr)
            {
                item->play();
            }
            else
            {
                cout << "Queue is empty.\n";
            }

            break;
        }

        case 3:
            queue.printQueue();
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
void searchSortMenu(Library& library)
{
    int choice;

    do
    {
        cout << "\n===== SEARCH & SORT =====\n";
        cout << "1. Search by title\n";
        cout << "2. Search by artist\n";
        cout << "3. Search by genre\n";
        cout << "4. Sort by title\n";
        cout << "5. Sort by duration\n";
        cout << "6. Sort by play count\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title;
            cout << "Enter title: ";
            cin >> title;

            MediaItem* item = library.binarySearch(title);

            if (item != nullptr)
                cout << item->getInfo() << endl;
            else
                cout << "Item not found.\n";

            break;
        }

        case 2:
        {
            string artist;
            cout << "Enter artist: ";
            cin >> artist;

            library.filterByArtist(artist);
            break;
        }

        case 3:
        {
            string genre;
            cout << "Enter genre: ";
            cin >> genre;

            library.filterByGenre(genre);
            break;
        }

        case 4:
            library.sortByTitle();
            cout << "Sorted by title.\n";
            break;

        case 5:
            library.sortByDuration();
            cout << "Sorted by duration.\n";
            break;

        case 6:
            library.sortByPlayCount();
            cout << "Sorted by play count.\n";
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
void statsMenu(Library& library)
{
    int choice;

    do
    {
        cout << "\n===== STATS =====\n";
        cout << "1. Total items\n";
        cout << "2. Total duration\n";
        cout << "0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Total items: "
                 << library.getCount()
                 << endl;
            break;

        case 2:
            cout << "Total duration: "
                 << library.getTotalDuration()
                 << " seconds\n";
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

int main()
{
    Library library;
    Playlist playlist;
    PlayQueue queue;

    library.add(new Song("Shape of You", "Ed Sheeran", 234, "Pop"));
library.add(new Song("Believer", "Imagine Dragons", 204, "Rock"));
library.add(new Song("Perfect", "Ed Sheeran", 263, "Pop"));
library.add(new Podcast("Tech Talk", "John Smith", 1800, 1));

    int choice;

    do
    {
        cout << "\n===== PLAYLIST MANAGER =====\n";
        cout << "1. Library\n";
        cout << "2. Playlist\n";
        cout << "3. Up Next Queue\n";
        cout << "4. Search and Sort\n";
        cout << "5. Stats\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
              libraryMenu(library, playlist, queue);
              break;

        case 2:
            playlistMenu(playlist);
            break;
    
            

        case 3:
            queueMenu(queue, library);
            break;
    
            
    
            

        case 4:
             searchSortMenu(library);
             break;
    
            

        case 5:
            statsMenu(library);
            break;
    
            

        case 0:
            cout << "\nGoodbye!\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}