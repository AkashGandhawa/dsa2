#include "factory.h"

WarehouseItem* head = NULL;

// Function to add a new item to the warehouse
void add_warehouse_item(int slot, char* mat, float stock) {
    WarehouseItem* newNode = (WarehouseItem*)malloc(sizeof(WarehouseItem));
    newNode->slot_no = slot;
    strcpy(newNode->material_type, mat);
    newNode->stock_kg = stock;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Item added successfully to slot %d.\n", slot);
}

// Function to update stock in a specific slot
void update_warehouse_item(int slot, float new_stock) {
    WarehouseItem* curr = head;
    while (curr != NULL) {
        if (curr->slot_no == slot) {
            curr->stock_kg = new_stock;
            printf("Stock in slot %d updated to %.2f kg.\n", slot, new_stock);
            return;
        }
        curr = curr->next;
    }
    printf("Error: Slot %d not found.\n", slot);
}

// Function to delete an item from a specific slot
void delete_warehouse_item(int slot) {
    WarehouseItem* curr = head;
    while (curr != NULL) {
        if (curr->slot_no == slot) {
            if (curr->prev != NULL) {
                curr->prev->next = curr->next;
            } else {
                head = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }
            free(curr);
            printf("Slot %d deleted successfully.\n", slot);
            return;
        }
        curr = curr->next;
    }
    printf("Error: Slot %d not found.\n", slot);
}

// Function to display all warehouse items
void display_warehouse() {
    WarehouseItem* curr = head;
    if (curr == NULL) {
        printf("Warehouse is empty.\n");
        return;
    }
    printf("\n--- Main Warehouse Inventory (Doubly Linked List) ---\n");
    while (curr != NULL) {
        printf("Slot No: %d | Material: %s | Stock: %.2f kg\n", 
               curr->slot_no, curr->material_type, curr->stock_kg);
        curr = curr->next;
    }
    printf("----------------------------------------------------\n");
}
