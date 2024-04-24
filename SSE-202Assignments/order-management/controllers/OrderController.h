#ifndef ORDERCONTROLLER_H
#define ORDERCONTROLLER_H

#include "../models/Order.h"
#include <unordered_map>
#include <memory>

class OrderController
{
public:
    OrderController() {}

    int createOrder()
    {
        int id = nextOrderID++;
        orders.emplace(id, std::make_unique<Order>());
        return id;
    }

    void addItemToOrder(int orderID, const OrderItem &item)
    {
        if (orders.find(orderID) != orders.end())
        {
            orders[orderID]->addItem(item);
        }
    }

    void removeItemFromOrder(int orderID, const std::string &itemName)
    {
        if (orders.find(orderID) != orders.end())
        {
            orders[orderID]->removeItem(itemName);
        }
    }

    void updateItemInOrder(int orderID, const std::string &itemName, int newQuantity)
    {
        if (orders.find(orderID) != orders.end())
        {
            orders[orderID]->updateItemQuantity(itemName, newQuantity);
        }
    }

    void finalizeOrder(int orderID)
    {
        if (orders.find(orderID) != orders.end())
        {
            orders[orderID]->closeOrder();
        }
    }

private:
    std::unordered_map<int, std::unique_ptr<Order>> orders;
    static int nextOrderID;
};

int OrderController::nextOrderID = 1;

#endif // ORDERCONTROLLER_H
