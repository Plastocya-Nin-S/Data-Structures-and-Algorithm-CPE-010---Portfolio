#include <iostream>
#include <vector>
#include <string>
#include <memory>   // for std::unique_ptr

using namespace std;

// Base class Item
class Item {
protected:
    string name;
    double price;
    int quantity;

public:
    Item(string n, double p, int q) : name(n), price(p), quantity(q) {}
    Item(const Item& other) : name(other.name), price(other.price), quantity(other.quantity) {}
    Item& operator=(const Item& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }
    virtual ~Item() {}

    virtual double calculateSum() const {
        return price * quantity;
    }

    virtual void display() const {
        cout << name << " | Price: PHP " << price
             << " | Quantity: " << quantity
             << " | Total: PHP " << calculateSum() << endl;
    }

    string getName() const { return name; }
};

// Derived classes
class Fruit : public Item {
public:
    Fruit(string n, double p, int q) : Item(n, p, q) {}
};

class Vegetable : public Item {
public:
    Vegetable(string n, double p, int q) : Item(n, p, q) {}
};

// Function to calculate total sum
double TotalSum(const vector<unique_ptr<Item>>& GroceryList) {
    double sum = 0;
    for (const auto& item : GroceryList) {
        sum += item->calculateSum();
    }
    return sum;
}

int main() {
    // Problem 2: GroceryList using vector of unique_ptr
    vector<unique_ptr<Item>> GroceryList;

    GroceryList.push_back(unique_ptr<Item>(new Fruit("Apple", 10, 7)));
    GroceryList.push_back(unique_ptr<Item>(new Fruit("Banana", 10, 8)));
    GroceryList.push_back(unique_ptr<Item>(new Vegetable("Broccoli", 60, 12)));
    GroceryList.push_back(unique_ptr<Item>(new Vegetable("Lettuce", 50, 10)));

    cout << "Jenna's Grocery List:" << endl;
    for (const auto& item : GroceryList) {
        item->display();
    }

    cout << "\nTotal Sum: PHP " << TotalSum(GroceryList) << endl;

    // Problem 4: Delete Lettuce safely
    cout << "\nDeleting Lettuce..." << endl;
    for (auto it = GroceryList.begin(); it != GroceryList.end(); ++it) {
        if ((*it)->getName() == "Lettuce") {
            GroceryList.erase(it); // unique_ptr automatically frees memory
		}
	}
	

    cout << "\nUpdated Grocery List:" << endl;
    for (const auto& item : GroceryList) {
        item->display();
    }

    cout << "\nUpdated Total Sum: PHP " << TotalSum(GroceryList) << endl;

    // No manual delete needed — unique_ptr handles cleanup
    return 0;
}

