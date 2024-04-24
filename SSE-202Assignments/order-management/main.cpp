#include "facade/OrderManagementFacade.h"
#include "views/MockView.h"

int main()
{
    OrderManagementFacade facade;
    bool running = true;
    int orderID = -1;

    while (running)
    {
        MockView::displayMenu();
        int choice = MockView::getUserChoice();

        switch (choice)
        {
        case 1:
        {
            orderID = facade.createOrder();
            std::cout << "Order " << orderID << " created." << std::endl;
            break;
        }
        case 2:
        {
            if (orderID != -1)
            {
                auto item = MockView::getOrderItemDetails();
                facade.addItemToOrder(orderID, item.getMenuItemName(), item.getUnitPrice(), item.getQuantity());
            }
            else
            {
                std::cout << "Please create an order first." << std::endl;
            }
            break;
        }
        // Handle other cases similarly
        case 6:
        {
            running = false;
            break;
        }
        default:
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }

    return 0;
}