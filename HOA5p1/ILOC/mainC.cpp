#include <iostream>
#include "Job.h"
#include "Printer.h"

int main() {
    Printer printer(5);

    std::cout << "------------- Adding Jobs -------------\n";

    // Add jobs
    printer.addJob(Job(1, "Ninya", 5));
    printer.addJob(Job(2, "Joma", 29));
    printer.addJob(Job(3, "Fenz", 8));

    std::cout << "\n------------- Current Printing Queue -------------\n";
    printer.displayQueue();

    // Process jobs one by one
    std::cout << "\n------------- Processing Jobs -------------\n";
    printer.processJob();  // Ninya
    printer.processJob();  // Joma

    std::cout << "\n------------- Queue After Processing -------------\n";
    printer.displayQueue();

    // Adds another job
    printer.addJob(Job(4, "Ella", 20));
    printer.addJob(Job(5, "Sir Jim", 1));

    std::cout << "\n------------- Final Queue -------------\n";
    printer.displayQueue();

    // Process remaining jobs
    std::cout << "\n------------- Processing Remaining Jobs -------------\n";
    printer.processJob();  // Fenz
    printer.processJob();  // Ella
    printer.processJob();  // Sir Jim

    // Checks if the queue is empty after processing all jobs
    std::cout << "\n------------- Queue After All Jobs -------------\n";
    printer.displayQueue();

    return 0;
}
 