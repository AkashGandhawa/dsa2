void receiving_dock_menu()
{
    printf("\n--- Receiving Dock ---\n");
    // TODO: add receiving dock menu and logic here
    // Integrated Themiya's enqueue/dequeue logic from main branch

    int subChoice, t_id, priority;
    char g_key;
    char supplier[50], material[50], date[20];
    int con = 1;

    Queue queue;
    initialize_queue(&queue);

    while (con)
    {
        printf("1. Enqueue a Truck\n2. Dequeue a Truck\n3. Display Dock\n4. Sort by Priority\n5. Group Trucks\n0. Back\n\n");
        printf("Enter the Subchoice: ");
        scanf("%d", &subChoice);

        switch (subChoice)
        {
        case 1:
            printf("Enter the Truck Details (ID, Priority, Supplier, Material, Date):\n");
            scanf("%d %d %s %s %s", &t_id, &priority, supplier, material, date);
            enqueue_truck(&queue, t_id, priority, supplier, material, date);
            break;
        case 2:
            dequeue_truck(&queue);
            break;
        case 3:
            display_dock(&queue);
            break;
        case 4:
            sortByPriority(&queue);
            break;
        case 5:
            printf("Enter the Grouping Selector (P-Priority, S-Supplier, M-Material): ");
            scanf(" %c", &g_key); // note space before %c to consume newline
            groupBy(&queue, g_key);
            break;
        case 0:
            con = 0; // exit submenu
            break;
        default:
            printf("Invalid Choice.\n");
        }
    }
}
