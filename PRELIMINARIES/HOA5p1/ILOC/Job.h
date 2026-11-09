#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <string>

class Job {
public:
    int id;
    std::string user;
    int pages;

    Job(int i = 0, std::string u = "", int p = 0) {
        id = i;
        user = u;
        pages = p;
    }

    void display() const {
        std::cout << "Job ID: " << id 
                  << "| User: " << user 
                  << "| Pages: " << pages << std::endl;
    }
};

#endif

