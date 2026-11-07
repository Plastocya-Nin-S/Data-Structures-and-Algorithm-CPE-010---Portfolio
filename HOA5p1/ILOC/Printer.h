#ifndef PRINTER_H
#define PRINTER_H

#include "Job.h"

class Printer {
private:
    Job* q_array;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;

public:
    // Constructor
    Printer(int capacity = 10) {
        q_capacity = capacity;
        q_array = new Job[q_capacity];
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    // Destructor
    ~Printer() {
        delete[] q_array;
    }

    // Add new job
    void addJob(Job j) {
        if (q_size == q_capacity) {
            std::cout << "Queue is full! Cannot add job.\n";
            return;
        }
        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = j;
        q_size++;
        std::cout << "Added Job >> ";
        j.display();
    }

    // Process next job
    void processJob() {
        if (q_size == 0) {
            std::cout << "No jobs to process.\n";
            return;
        }
        std::cout << "Processing Job >> ";
        q_array[q_front].display();
        q_front = (q_front + 1) % q_capacity;
        q_size--;
    }

    // Display all jobs in queue
    void displayQueue() {
        if (q_size == 0) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Pending Jobs:\n";
        for (int i = 0; i < q_size; i++) {
            int index = (q_front + i) % q_capacity;
            q_array[index].display();
        }
    }
};

#endif
