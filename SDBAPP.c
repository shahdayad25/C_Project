#include <stdio.h>
#include "SDB.h"

void SDB_action(uint8 choice) {
    uint32 id;
    uint8 count;
    uint32 list[10];

    switch (choice) {
        case 1:
            if (!SDB_AddEntry())
                printf("Failed to add entry.\n");
            break;
        case 2:
            printf("Used size: %d\n", SDB_GetUsedSize());
            break;
        case 3:
            printf("Enter ID to read: ");
            scanf("%u", &id);
            if (!SDB_ReadEntry(id))
                printf("ID not found.\n");
            break;
        case 4:
            SDB_GetList(&count, list);
            printf("Total IDs: %d\n", count);
            for (uint8 i = 0; i < count; i++)
                printf("ID %d: %u\n", i + 1, list[i]);
            break;
        case 5:
            printf("Enter ID to check: ");
            scanf("%u", &id);
            printf(SDB_IsIdExist(id) ? "ID exists.\n" : "ID not found.\n");
            break;
        case 6:
            printf("Enter ID to delete: ");
            scanf("%u", &id);
            SDB_DeletEntry(id);
            break;
        case 7:
            printf(SDB_IsFull() ? "Database is full.\n" : "Database is not full.\n");
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option.\n");
    }
}

void SDB_APP() {
    uint8 choice;
    do {
        printf("\n1. Add Entry\n2. Get Used Size\n3. Read Student Data\n4. List All IDs\n5. Check ID Exists\n6. Delete Entry\n7. Check if Full\n0. Exit\nChoice: ");
        scanf("%hhu", &choice);
        SDB_action(choice);
    } while (choice != 0);
}