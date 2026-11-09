#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>

// STEP 1: Define the STUDENT class
class Student{
    private:
        std::pair<int, int> name;
        bool vaccinated;

    public:
        // Constructor
        Student (std::pair<int, int> n, bool v) : name(n), vaccinated(v) {
        }

        // Getters 
        auto get_name() { return name; }
        auto is_vaccinated () { return vaccinated; }

        bool is_vaccinated() const {
        return vaccinated;
        }


    // STEP 2: Overload the required operators

    // Two people are the same if they have the same name
    bool operator==(const Student& p) const {
        return this->name == p.name;
    }

    // Ordering is based on the student's name
    bool operator<(const Student& p) const {
        return this->name < p.name;
    }

    bool operator>(const Student& p) const {
        return this->name > p.name;
    }
};

// STEP 3: The following function lets us generate a student from random data:

auto generate_random_Student(int max) {
    std::random_device rd;
    std::mt19937 rand(rd());

    // Student IDs are in the range [1, max]
    std::uniform_int_distribution<std::mt19937::result_type>
        uniform_dist(1, max);

    // Generate random first and last names
    auto random_name = std::pair(uniform_dist(rand), uniform_dist(rand)); 

    // Random vaccination status
    bool is_vaccinated =
        uniform_dist(rand) % 2 ? true : false;

    return Student(random_name, is_vaccinated);
}

void search_test(int size, Student p) {
    std::vector<Student> poeple;

    // Create a list of random people
    for (auto i = 0; i < size; i++)
        people.push_back(generate_random_Student(size));

    std::sort (people.begin(), people.end());

    // To measure the time takenn, start the clock
    std::chrono::steady_clock::time_point
    begin = std::chrono::steady_clock::now();
    bool sarch_result = needs_vaccination(p, people);

    // Stop the clock 
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time taken to search = " <<
        std::chrono::duration_cast<std::chrono::microseconds>
        (end - begin).count() << " microseconds" << std::endl;
    if (search_result)
        std::cout << "Student (" << p.get_name().first << " " << p.get_name().second
        << ") " << "needs vaccination." << std::endl;
    else
        std::cout << "Student (" << p.get_name().first << " " << p.get_name().second
        << ") " << "does not need vaccination." << std::endl;
}





















// STEP 5: Determine whether a student needs vaccination

bool needs_vaccination(
    const Student& P,
    const std::vector<Student>& people
) {

    int first = 0;
    int last = people.size() - 1;

    // Binary search
    while (first <= last) {

        int mid = first + (last - first) / 2;

        // Student found
        if (people[mid] == P) {

            // Student is not vaccinated
            if (!people[mid].is_vaccinated()) {
                return true;
            }

            // Student is already vaccinated
            return false;
        }

        // Search in the right half
        if (people[mid] < P) {
            first = mid + 1;
        }

        // Search in the left half
        else {
            last = mid - 1;
        }
    }

    // Student is not in the list,
    // therefore vaccination is needed.
    return true;
}



