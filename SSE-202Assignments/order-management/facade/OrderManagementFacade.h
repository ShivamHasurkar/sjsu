#ifndef ORDERMANAGEMENTFACADE_H
#define ORDERMANAGEMENTFACADE_H

#include "../controllers/OrderController.h"

class OrderManagementFacade
{
public:
    OrderManagementFacade() : controller() {}

    int createOrder()
    {
        return controller.createOrder();
    }

    void addItemToOrder(int orderID, const std::string &itemName, double price, int quantity)
    {
        OrderItem item(itemName, price, quantity);
        controller.addItemToOrder(orderID, item);
    }

    void removeItemFromOrder(int orderID, const std::string &itemName)
    {
        controller.removeItemFromOrder(orderID, itemName);
    }

    void updateItemInOrder(int orderID, const std::string &itemName, int quantity)
    {
        controller.updateItemInOrder(orderID, itemName, quantity);
    }

    void finalizeOrder(int orderID)
    {
        controller.finalizeOrder(orderID);
    }

    // Add other methods as necessary to interact with the menu and billing subsystems.

private:
    OrderController controller;
};

#endif // ORDERMANAGEMENTFACADE_H
