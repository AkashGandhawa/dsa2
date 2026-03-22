#include "factory.h"

void show_menu() {
    printf("\n--- Garment Factory Management System (Group Project) ---\n");
    printf("1. Receiving Dock (Themiya - Queue)\n");
    printf("2. Main Warehouse (Anushka - Doubly Linked List)\n");
    printf("3. Secondary Stock (Sasadhara - Doubly Linked List)\n");
    printf("4. Production Floor (Dulaksha - Array)\n");
    printf("5. Sewing Operator (Akash - Linked List)\n");
    printf("6. Order Dispatch (Prabuddha - Linked List)\n");
    printf("7. Security (Yasiru - Array)\n");
    printf("0. Exit\n");
}

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice, subChoice, id;
    char mat[30];
    float stock;

    //Receiving Dock Variables
    int t_id,priority;
    char g_key;
    char supplier[50],material[50],date[20];
    bool con = true;
    
    while(1) {
        show_menu();
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { 
            printf("Invalid input.\n");
            clear_input(); 
            continue; 
        }
        
        switch(choice) {
            case 1: // Receiving Dock - Themiya
                printf("\n--- Receiving Dock ---\n");
                printf("1. Enqueue a Truck\n2. Dequeue a Truck\n3. Display Dock\n4. Sort by Priority\n5. Group Trucks\n0. Exit\n\n");

                Queue queue;
                initialize_queue(&queue);

                while(con){
                    printf("Enter the Subchoice: ");
                    scanf("%d", &subChoice);

                    switch(subChoice){
                        case 1:
                            printf("Enter the Truck Details (ID, Priority, Supplier, Material, Date):\n");
                            scanf("%d %d %s %s %s", &t_id, &priority, supplier, material, date);
                            enqueue_truck(&queue, t_id, priority, supplier, material, date);
                            printf("\n");
                            break;
                        case 2:
                            dequeue_truck(&queue);
                            printf("\n");
                            break;
                        case 3:
                            display_dock(&queue);
                            break;
                        case 4:
                            sortByPriority(&queue);
                            printf("\n");
                            break;
                        case 5:
                            printf("Enter the Grouping Selector (P-Priority, S-Supplier, M-Material): ");
                            scanf("%c", &g_key);
                            groupBy(&queue, g_key);
                            break;
                        case 0:
                            con = false;
                            printf("\n");
                            break;
                        default:
                            printf("Invalid Choice.\n\n");
                        }
                    }
                break;

            case 2: // Main Warehouse - Anushka
                printf("\n--- Main Warehouse ---\n");
                printf("1. Add Item\n2. Update Stock\n3. Delete Item\n4. Display\n5. Back\nChoice: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    printf("Slot No, Material, Stock(kg): ");
                    scanf("%d %s %f", &id, mat, &stock);
                    add_warehouse_item(id, mat, stock);
                } else if (subChoice == 2) {
                    printf("Slot No, New Stock: ");
                    scanf("%d %f", &id, &stock);
                    update_warehouse_item(id, stock);
                } else if (subChoice == 3) {
                    printf("Slot No: ");
                    scanf("%d", &id);
                    delete_warehouse_item(id);
                } else if (subChoice == 4) display_warehouse();
                break;

            case 3: // Secondary Stock - Sasadhara
                printf("\n--- Secondary Stock (Placeholder) ---\n");
                printf("Space for Sasadhara to add Add/Delete/Update logic.\n");
                break;

            case 4: // Production Floor - Dulaksha
                printf("\n--- Production Floor (Placeholder) ---\n");
                printf("Space for Dulaksha to add Add/Delete/Update logic.\n");
                break;

            case 5: // Sewing Operator - Akash
                printf("\n--- Sewing Operator (Placeholder) ---\n");
                printf("Space for Akash to add Add/Delete/Update (Sort by pieces) logic.\n");
                break;

            case 6: // Order Dispatch - Prabuddha
                printf("\n--- Order Dispatch (Placeholder) ---\n");
                printf("Space for Prabuddha to add Add/Delete/Update (Sort by priority) logic.\n");
                break;

            case 7: // Security - Yasiru
                printf("\n--- Security (Placeholder) ---\n");
                printf("Space for Yasiru to add Add/Delete/Update logic.\n");
                break;

            case 0: 
                printf("Exiting system...\n");
                exit(0);

            default: 
                printf("Invalid choice. Please select 0-7.\n");
        }
    }
    return 0;
}
