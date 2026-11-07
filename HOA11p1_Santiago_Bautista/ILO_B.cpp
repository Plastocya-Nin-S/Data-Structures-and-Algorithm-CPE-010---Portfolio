
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <utility>

class Student {
private:
    std::pair<int, int> name;
    bool vaccinated;

public:
    Student(std::pair<int, int> n, bool v)
        : name(n), vaccinated(v) {}

    std::pair<int, int> get_name() const {
        return name;
    }

    bool is_vaccinated() const {
        return vaccinated;
    }

    bool operator==(const Student& p) const {
        return name == p.name;
    }

    bool operator<(const Student& p) const {
        return name < p.name;
    }

    bool operator>(const Student& p) const {
        return name > p.name;
    }
};

// Generate a student with random information
Student generate_random_Student(int max) {
    static std::random_device rd;
    static std::mt19937 rand(rd());

    std::uniform_int_distribution<int> id_dist(1, max);
    std::uniform_int_distribution<int> vaccine_dist(0, 1);

    auto random_name = std::make_pair(
        id_dist(rand), id_dist(rand)
    );

    bool is_vaccinated = vaccine_dist(rand) == 1;

    return Student(random_name, is_vaccinated);
}

// Binary Search to determine whether vaccination is needed
bool needs_vaccination(
    const Student& p,
    const std::vector<Student>& people
) {
    auto it = std::lower_bound(
        people.begin(), people.end(), p
    );

    // Student is not found in the list
    if (it == people.end() || !(*it == p)) {
        return true;
    }

    // Student is found but has not been vaccinated
    return !it->is_vaccinated();
}

// Measure the search execution time
void search_test(int size, const Student& p) {
    std::vector<Student> people;
    people.reserve(size);

    // Generate the list of students
    for (int i = 0; i < size; i++) {
        people.push_back(generate_random_Student(size));
    }

    // Sort the list before searching
    std::sort(people.begin(), people.end());

    // Start measuring the search time
    auto begin = std::chrono::steady_clock::now();

    bool search_result = needs_vaccination(p, people);

    // Stop measuring the search time
    auto end = std::chrono::steady_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - begin
        ).count();

    std::cout << "Input size: " << size << '\n';
    std::cout << "Time taken to search = "
              << duration << " microseconds\n";

    std::cout << "Student ("
              << p.get_name().first << " "
              << p.get_name().second << ") ";

    if (search_result) {
        std::cout << "needs vaccination.\n";
    } else {
        std::cout << "does not need vaccination.\n";
    }

    std::cout << "-------------------------------------\n";
}

int main() {
    // Generate the student to be searched
    Student p = generate_random_Student(1000);

    // Test the three required input sizes
    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);

    return 0;
}
