#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits> // For input validation

using namespace std;

// Structure that stores item details
struct Item {
    string name;          // Name of the item
    int quantity;       // Quantity purchased
    double unit_price;  // Price per item
    double total_price; // Total price for this item
};

int main() {
    vector<Item> items(3); // A vector for holding the 3 purchased items
    double total_amount = 0.0; // Initialization of the total amount

    // Loop for the user input details for each item
    for (int i = 0; i < 3; ++i) {
        // Gets the item name
        cout << "Enter name of item " << (i + 1) << ": ";
        getline(cin, items[i].name);

        // Input validation for quantity
        do {
            cout << "Enter quantity of " << items[i].name << ": ";
            cin >> items[i].quantity;
            if (cin.fail() || items[i].quantity <= 0) {
                cout << "Invalid input. Quantity should be at least 1.\n";
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards invalid input
            } else {
                break; // Valid input received
            }
        } while (true);

        // Input validation for unit price
        do {
            cout << "Enter price of one " << items[i].name << ": P";
            cin >> items[i].unit_price;
            if (cin.fail() || items[i].unit_price < 0) {
                cout << "Invalid input. Price cannot be negative.\n";
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards invalid input
            } else {
                break; // Valid input received
            }
        } while (true);

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer after each item
        // Calculates total price for this item only
        items[i].total_price = items[i].unit_price * items[i].quantity;
        // Adds the item amount to the total amount
        total_amount += items[i].total_price;
    }

    // Displays the total amount
    cout << fixed << setprecision(2);
    cout << "\nTotal amount for the items: P" << total_amount << "\n";

    // Loop that only accepts payment until it is sufficient
    double payment = 0.0;
    do {
        cout << "Enter payment amount: P";
        cin >> payment;
        // Input Validation for Payment
        if (cin.fail() || payment < total_amount) {
            cout << "Insufficient payment. Please enter an amount equal to or greater than the total.\n";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards invalid input
        } else {
            break; // Valid payment received
        }
    } while (true);

    // Calculates change
    double change = payment - total_amount;

    // Displays the receipt with detailed info
    cout << "\n--------- RECEIPT ---------\n";
    for (const auto& item : items) {
        cout << item.name << " (x" << item.quantity << " | P" << item.unit_price << " each): P" << item.total_price << "\n";
    }
    cout << "Total: P" << total_amount << "\n";
    cout << "Payment: P" << payment << "\n";
    cout << "Change: P" << change << "\n";
    cout << "---------------------------\n";

    return 0; // End of program
}


