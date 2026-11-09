#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H

#include <iostream>
#include <string>
using namespace std;

// Playlist Node (Template)
template <typename T>
class PlaylistNode {
public:
    T data;                        // Song title or data
    PlaylistNode<T>* next = nullptr; // Pointer to next node 
};

// Node Creation
template <typename T>
PlaylistNode<T>* createNode(T newData) {
    PlaylistNode<T>* newNode = new PlaylistNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// Playlist Creation (Circular)
// Creates a circular linked list from an array of songs
template <typename T>
PlaylistNode<T>* createPlaylist(T songs[], int size) {
    if (songs == nullptr || size <= 0) return nullptr;

    PlaylistNode<T>* head = nullptr;
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            head = createNode(songs[i]);
            head->next = head; // circular link to itself
        } else {
            PlaylistNode<T>* newNode = createNode(songs[i]);
            PlaylistNode<T>* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = head;
        }
    }
    return head;
}

// Traversal
// Prints all songs in the playlist
template <typename T>
void playlistTraverse(PlaylistNode<T>* head) {
    if (head == nullptr) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    PlaylistNode<T>* current = head;
    do {
        cout << current->data;
        current = current->next;
        if (current != head) cout << " -> ";
    } while (current != head);
    cout << endl;
}

// Play All Songs
template <typename T>
void playlistPlayAll(PlaylistNode<T>* head) {
    cout << "Playing playlist:" << endl;
    playlistTraverse(head);
}

// Insert at Head
template <typename T>
void playlistInsertHead(T newData, PlaylistNode<T>** head) {
    PlaylistNode<T>* newNode = createNode(newData);
    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }
    PlaylistNode<T>* tail = *head;
    while (tail->next != *head) {
        tail = tail->next;
    }
    newNode->next = *head;
    tail->next = newNode;
    *head = newNode;
}

// Insert at End
template <typename T>
void playlistInsertEnd(T newData, PlaylistNode<T>** head) {
    PlaylistNode<T>* newNode = createNode(newData);
    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }
    PlaylistNode<T>* tail = *head;
    while (tail->next != *head) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->next = *head;
}

// Insert After a Given Node
template <typename T>
void playlistInsertAfter(T newData, PlaylistNode<T>* prevNode) {
    if (prevNode == nullptr) {
        cout << "Previous song node cannot be null!" << endl;
        return;
    }
    PlaylistNode<T>* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Next Song
template <typename T>
void playlistNext(PlaylistNode<T>*& current) {
    if (current == nullptr) return;
    current = current->next;
}

// Previous Song
// Finds the node before the current one
template <typename T>
void playlistPrevious(PlaylistNode<T>* head, PlaylistNode<T>*& current) {
    if (head == nullptr || current == nullptr) return;
    PlaylistNode<T>* prev = head;
    while (prev->next != current && prev->next != head) {
        prev = prev->next;
    }
    if (prev->next == current) current = prev;
}

// Delete a Song by Title
template <typename T>
void playlistDeleteSong(T findData, PlaylistNode<T>** head) {
    if (*head == nullptr) return;

    PlaylistNode<T>* current = *head;
    PlaylistNode<T>* prev = nullptr;
    bool found = false;

    // Search for the song
    do {
        if (current->data == findData) {
            found = true;
            break;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    if (!found) return;

    // Case 1: Only one node
    if (current->next == current) {
        delete current;
        *head = nullptr;
        return;
    }

    // Case 2: Deleting head in multi-node list
    if (prev == nullptr) {
        PlaylistNode<T>* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        tail->next = current->next;
        *head = current->next;
        delete current;
        return;
    }

    // Case 3: Deleting non-head node
    prev->next = current->next;
    if (current == *head) *head = current->next;
    delete current;
}

// Delete Entire Playlist
template <typename T>
void playlistDeleteList(PlaylistNode<T>** head) {
    if (*head == nullptr) return;

    PlaylistNode<T>* current = (*head)->next;
    while (current != *head) {
        PlaylistNode<T>* temp = current;
        current = current->next;
        delete temp;
    }
    delete *head;
    *head = nullptr;
}

#endif
