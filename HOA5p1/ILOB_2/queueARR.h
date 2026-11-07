#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <iostream>

class Queue {
private:
    int* q_array;      // pointer to array
    int q_capacity;    // max capacity
    int q_size;        // current size
    int q_front;       // index of front
    int q_back;        // index of back

public:
    // Constructor
    Queue(int capacity = 10) {
        q_capacity = capacity;
        q_array = new int[q_capacity];
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    // Destructor
    ~Queue() {
        delete[] q_array;
    }

    // Copy Constructor
    Queue(const Queue& queueToCopy) {
        q_capacity = queueToCopy.q_capacity;
        q_size = queueToCopy.q_size;
        q_front = queueToCopy.q_front;
        q_back = queueToCopy.q_back;
        q_array = new int[q_capacity];
        for (int i = 0; i < q_capacity; i++) {
            q_array[i] = queueToCopy.q_array[i];
        }
    }

    // Copy Assignment Operator
    Queue& operator=(const Queue& queueToCopy) {
        if (this != &queueToCopy) {
            delete[] q_array;
            q_capacity = queueToCopy.q_capacity;
            q_size = queueToCopy.q_size;
            q_front = queueToCopy.q_front;
            q_back = queueToCopy.q_back;
            q_array = new int[q_capacity];
            for (int i = 0; i < q_capacity; i++) {
                q_array[i] = queueToCopy.q_array[i];
            }
        }
        return *this;
    }

    // Check if empty
    bool Empty() {
        return q_size == 0;
    }

    // Return size
    int Size() {
        return q_size;
    }

    // Clear queue
    void Clear() {
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    // Get front element
    int Front() {
        if (Empty()) throw std::runtime_error("Queue is empty!");
        return q_array[q_front];
    }

    // Get back element
    int Back() {
        if (Empty()) throw std::runtime_error("Queue is empty!");
        return q_array[q_back];
    }

    // Enqueue
    void Enqueue(int value) {
        if (q_size == q_capacity) throw std::runtime_error("Queue is full!");
        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = value;
        q_size++;
    }

    // Dequeue
    void Dequeue() {
        if (Empty()) throw std::runtime_error("Queue is empty!");
        q_front = (q_front + 1) % q_capacity;
        q_size--;
    }

    // Displays queue
    void Display() {
        if (Empty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        std::cout << "Queue: ";
        for (int i = 0; i < q_size; i++) {
            int index = (q_front + i) % q_capacity;
            std::cout << q_array[index] << " ";
        }
        std::cout << std::endl;
    }
};

#endif















