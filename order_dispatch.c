#include <stdio.h>
#include <stdlib.h>
#include "factory.h"

Order *orderhead = NULL;

// Function to create a new order with the given order details
void add_order(int order_id, int receiver_id, int priority, char item_type[30], int item_count, float price)
{
    Order *newOrder = (struct Order *)malloc(sizeof(struct Order));
    if (newOrder == NULL)
    {
        printf("Memory Allocation Failed");
    }
    newOrder->order_id = order_id;
    newOrder->receiver_id = receiver_id;
    newOrder->priority = priority;
    strcpy(newOrder->item_type,item_type);
    newOrder->item_count = item_count;
    newOrder->price = price;

    newOrder->next = orderhead;
    orderhead = newOrder;
    printf("New Order Added Successfully!\n");
};
//    -----------------------------------------------------

// delete an order from the linked list based on the order_id
void delete_order(int order_id)
{
    if (orderhead == NULL)
    {
        printf("No orders to delete\n");
        return;
    }
    if (orderhead->order_id == order_id)
    {
        Order *temp = orderhead;
        orderhead = orderhead->next;
        free(temp);
        printf("Order deleted successfully from the first position\n");
        return;
    }
    Order *current = orderhead->next;
    Order *previous = orderhead;

    while (current != NULL)
    {
        if (current->order_id == order_id)
        {
            previous->next = current->next;
            free(current);
            printf("Order deleted successfully from the middle position\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Order not found\n");
};
// -----------------------------------------------------

// update an order in the linked list based on the order_id
void update_order(int order_id, int receiver_id, int priority, char item_type[], int item_count, float price)
{
    Order *current = orderhead;
    while (current != NULL)
    {
        if (current->order_id == order_id)
        {
            current->receiver_id = receiver_id;
            current->priority = priority;
            strcpy(current->item_type,item_type);
            current->item_count = item_count;
            current->price = price;
            printf("Order updated successfully\n");
            return;
        }
        current = current->next;
    }
    printf("Order not found\n");
};
// ------------------------------------------------------

// display all the orders in the linked list
void display_orders()
{
    struct Order *current = orderhead;
    if (current == NULL)
    {
        printf("No orders to display\n");
        return;
    }
    while (current != NULL)
    {
        printf("Order ID: %d, Receiver ID: %d, Priority: %d, Item Type: %c, Item Count: %d, Price: %.2f\n",
               current->order_id, current->receiver_id, current->priority, current->item_type, current->item_count, current->price);
        current = current->next;
    }
};
// ------------------------------------------------------

void sort_orders_by_priority()
{
    if (orderhead == NULL)
    {
        printf("No Orders to sort\n");
        return;
    }
    Order *curr = orderhead;
    while (curr != NULL)
    {
        Order *next = curr->next;
        Order *min = curr;

        while (next != NULL)
        {
            if (min->priority > next->priority)
            {
                min = next;
            }
            next = next->next;
        }

        Order temp = *curr;

        curr->order_id = min->order_id;
        curr->receiver_id = min->receiver_id;
        curr->priority = min->priority;
        strcpy(curr->item_type, min->item_type);
        curr->item_count = min->item_count;
        curr->price = min->price;

        min->order_id = temp.order_id;
        min->receiver_id = temp.receiver_id;
        min->priority = temp.priority;
        strcpy(min->item_type,temp.item_type);
        min->item_count = temp.item_count;
        min->price = temp.price;

        curr = curr->next;
    }
};
