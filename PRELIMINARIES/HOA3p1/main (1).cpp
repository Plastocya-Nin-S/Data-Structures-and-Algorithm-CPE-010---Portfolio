#include <iostream>
#include <string>
#include "ninsplaylist_LL.h"   // include the header file with playlist functions

using namespace std;

int main() {
    PlaylistNode<string>* playlist = nullptr;   // start with an empty playlist
    PlaylistNode<string>* current = nullptr;    // pointer to track the current song
    int choice;

    do {
        cout << "\n===== PLAYLIST MENU =====" << endl;
        cout << "1. Create playlist (sample songs)" << endl;
        cout << "2. Insert song at head" << endl;
        cout << "3. Insert song at end" << endl;
        cout << "4. Insert song after current" << endl;
        cout << "5. Play all songs" << endl;
        cout << "6. Show current song" << endl;
        cout << "7. Next song" << endl;
        cout << "8. Previous song" << endl;
        cout << "9. Delete a song" << endl;
        cout << "10. Delete entire playlist" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from input buffer

        switch (choice) {
            case 1: {
                // Create a Initial playlist
                string songs[] = {"Intertwined - The Ridleys", 
                    "Fallin All in You - Shawn Mendes", "Lemonade - Jeremy Passion",};
                int count = sizeof(songs) / sizeof(songs[0]);
                playlist = createPlaylist(songs, count);   // <-- function call: createPlaylist
                current = playlist;
                cout << "Initial playlist created." << endl;
                playlistTraverse(playlist);                // <-- function call: playlistTraverse
                break;
            }
            case 2: {
                // Insert at head
                string song;
                cout << "Enter song title: ";
                getline(cin, song);
                playlistInsertHead(song, &playlist);       // <-- function call: playlistInsertHead
                cout << "Inserted at head." << endl;
                playlistTraverse(playlist);                // <-- function call: playlistTraverse
                break;
            }
            case 3: {
                // Insert at end
                string song;
                cout << "Enter song title: ";
                getline(cin, song);
                playlistInsertEnd(song, &playlist);        // <-- function call: playlistInsertEnd
                cout << "Inserted at end." << endl;
                playlistTraverse(playlist);                // <-- function call: playlistTraverse
                break;
            }
            case 4: {
                // Insert after current song
                if (current == nullptr) {
                    cout << "No current song selected!" << endl;
                    break;
                }
                string song;
                cout << "Enter song title: ";
                getline(cin, song);
                playlistInsertAfter(song, current);        // <-- function call: playlistInsertAfter
                cout << "Inserted after current song." << endl;
                playlistTraverse(playlist);                // <-- function call: playlistTraverse
                break;
            }
            case 5: {
                // Play all songs
                playlistPlayAll(playlist);                 // <-- function call: playlistPlayAll
                break;
            }
            case 6: {
                // Show current song
                if (current == nullptr) cout << "No current song!" << endl;
                else cout << "Current song: " << current->data << endl;
                break;
            }
            case 7: {
                // Move to next song
                playlistNext(current);                     // <-- function call: playlistNext
                if (current != nullptr) cout << "Now playing: " << current->data << endl;
                break;
            }
            case 8: {
                // Move to previous song
                playlistPrevious(playlist, current);       // <-- function call: playlistPrevious
                if (current != nullptr) cout << "Now playing: " << current->data << endl;
                break;
            }
            case 9: {
                // Delete a song
                string song;
                cout << "Enter song title to delete: ";
                getline(cin, song);
                playlistDeleteSong(song, &playlist);       // <-- function call: playlistDeleteSong
                playlistTraverse(playlist);                // <-- function call: playlistTraverse
                break;
            }
            case 10: {
                // Delete entire playlist
                playlistDeleteList(&playlist);             // <-- function call: playlistDeleteList
                current = nullptr;
                cout << "Playlist deleted." << endl;
                playlistTraverse(playlist);                // <-- function call: playlistTraverse
                break;
            }
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}


