#include <iostream>
#include <iomanip>
#include <string>

//==================== BASE CLASS ====================//

class GroceryItem {
protected:
    std::string name;
    double price;
    int quantity;

public:
    // Constructor
    GroceryItem(std::string n = "", double p = 0, int q = 0)
        : name(n), price(p), quantity(q) {}

    // Copy Constructor
    GroceryItem(const GroceryItem& other)
        : name(other.name), price(other.price), quantity(other.quantity) {}

    // Copy Assignment Operator
    GroceryItem& operator=(const GroceryItem& other)
    {
        if (this != &other)
        {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    // Virtual Destructor
    virtual ~GroceryItem() {}

    double calculateSum() const
    {
        return price * quantity;
    }

    virtual std::string getType() const = 0;

    virtual void display() const
    {
        std::cout << std::left
                  << std::setw(12) << getType()
                  << std::setw(15) << name
                  << std::setw(10) << ("PHP " + std::to_string((int)price))
                  << std::setw(8) << ("x" + std::to_string(quantity))
                  << "PHP " << calculateSum()
                  << std::endl;
    }
};

//==================== FRUIT ====================//

class Fruit : public GroceryItem
{
public:
    Fruit(std::string n, double p, int q)
        : GroceryItem(n, p, q) {}

    Fruit(const Fruit& other)
        : GroceryItem(other) {}

    Fruit& operator=(const Fruit& other)
    {
        GroceryItem::operator=(other);
        return *this;
    }

    std::string getType() const override
    {
        return "Fruit";
    }

    ~Fruit() override
    {
        std::cout << "Fruit \"" << name << "\" deleted.\n";
    }
};

//==================== VEGETABLE ====================//

class Vegetable : public GroceryItem
{
public:
    Vegetable(std::string n, double p, int q)
        : GroceryItem(n, p, q) {}

    Vegetable(const Vegetable& other)
        : GroceryItem(other) {}

    Vegetable& operator=(const Vegetable& other)
    {
        GroceryItem::operator=(other);
        return *this;
    }

    std::string getType() const override
    {
        return "Vegetable";
    }

    ~Vegetable() override
    {
        std::cout << "Vegetable \"" << name << "\" deleted.\n";
    }
};

//==================== TOTAL SUM ====================//

double TotalSum(GroceryItem* GroceryList[], int size)
{
    double total = 0;

    for (int i = 0; i < size; i++)
    {
        if (GroceryList[i] != nullptr)
            total += GroceryList[i]->calculateSum();
    }

    return total;
}

//==================== DISPLAY ====================//

void DisplayList(GroceryItem* GroceryList[], int size)
{
    std::cout << "==============================================================\n";
    std::cout << "                  Jenna's Grocery List\n";
    std::cout << "==============================================================\n";

    std::cout << std::left
              << std::setw(12) << "Type"
              << std::setw(15) << "Item"
              << std::setw(10) << "Price"
              << std::setw(8) << "Qty"
              << "Subtotal\n";

    std::cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < size; i++)
    {
        if (GroceryList[i] != nullptr)
            GroceryList[i]->display();
    }

    std::cout << "--------------------------------------------------------------\n";
    std::cout << "Total Amount: PHP " << TotalSum(GroceryList, size) << "\n";
    std::cout << "==============================================================\n\n";
}

//==================== MAIN ====================//

int main()
{
    const int SIZE = 4;

    GroceryItem* GroceryList[SIZE];

    // Dynamic Memory Allocation
    GroceryList[0] = new Fruit("Apple", 10, 7);
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

    std::cout << "ORIGINAL GROCERY LIST\n\n";
    DisplayList(GroceryList, SIZE);

    // Delete Lettuce
    std::cout << "Deleting Lettuce...\n\n";

    delete GroceryList[3];
    GroceryList[3] = nullptr;

    std::cout << "UPDATED GROCERY LIST\n\n";
    DisplayList(GroceryList, SIZE);

    // Memory Cleanup
    for (int i = 0; i < SIZE; i++)
    {
        delete GroceryList[i];
        GroceryList[i] = nullptr;
    }

    return 0;
}



