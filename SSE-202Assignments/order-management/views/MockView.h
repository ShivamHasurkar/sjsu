#ifndef MOCKVIEW_H
#define MOCKVIEW_H
#include "OrderItem.h";

#include <iostream>

class MockView
{
public:
    static void displayMenu()
    {
        std::cout << "1. Create new order" << std::endl;
        std::cout << "2. Add item to order" << std::endl;
        std::cout << "3. Remove item from order" << std::endl;
        std::cout << "4. Update item quantity in order" << std::endl;
        std::cout << "5. Finalize order" << std::endl;
        std::cout << "6. Exit" << std::endl;
    }

    static int getUserChoice()
    {
        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        return choice;
    }

    static OrderItem getOrderItemDetails()
    {
        std::string name;
        double price;
        int quantity;

        std::cout << "Enter item name: ";
        std::cin >> name;

        std::cout << "Enter item price: ";
        std::cin >> price;

        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        return OrderItem(name, price, quantity);
    }

    // Add more static methods for different view operations as necessary
};

#endif // MOCKVIEW_H
