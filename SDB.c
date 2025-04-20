#include "STD.h"
#include "SDB.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 10
static student database[MAX_STUDENTS]; // database array to store student records
static uint8 current_size = 0; // initial size of the database and is static to limit the scope of the variable to this file only

bool SDB_IsFull() {
    return current_size >= MAX_STUDENTS; 
}
uint8 SDB_GetUsedSize() {
    return current_size;
}
bool SDB_AddEntry() {
    if (SDB_IsFull()) {
        return false; // Database is full, cannot add more entries
    }
    student s;
    printf("Enter Student ID: ");
    scanf("%u", &s.Student_ID);
    if (SDB_IsIdExist(s.Student_ID)) { // ID is special number so it should be unique
        // Check if ID already exists
        printf("Student ID already exists.\n");
        return false;
    }
    printf("Enter Student Year: ");
    scanf("%u", &s.Student_year);
    printf("Enter Course 1 ID: ");
    scanf("%u", &s.Course1_ID);
    printf("Enter Course 1 Grade: ");
    scanf("%u", &s.Course1_grade);
    printf("Enter Course 2 ID: ");
    scanf("%u", &s.Course2_ID);
    printf("Enter Course 2 Grade: ");
    scanf("%u", &s.Course2_grade);
    printf("Enter Course 3 ID: ");
    scanf("%u", &s.Course3_ID);
    printf("Enter Course 3 Grade: ");
    scanf("%u", &s.Course3_grade);
    database[current_size++] = s;
    return true;
}
void SDB_DeletEntry(uint32 id) {
    for (uint8 i = 0; i < current_size; i++) {
        if (database[i].Student_ID == id) {
            for (uint8 j = i; j < current_size - 1; j++) {// Shift all entries to the left
                database[j] = database[j + 1];
            }
            current_size--; // Decrease the size of the database by 1
            printf("Student ID %u deleted successfully.\n", id);
            return;
        }
    }
    printf("Student ID not found.\n");
}
bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < current_size; i++) {
        if (database[i].Student_ID == id) {// Check if the ID matches
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student Year: %u\n", database[i].Student_year);
            printf("Course 1 ID: %u, Grade: %u\n", database[i].Course1_ID, database[i].Course1_grade);
            printf("Course 2 ID: %u, Grade: %u\n", database[i].Course2_ID, database[i].Course2_grade);
            printf("Course 3 ID: %u, Grade: %u\n", database[i].Course3_ID, database[i].Course3_grade);
            return true;
        }
    }
    printf("Student ID not found.\n");
    return false;
}
void SDB_GetList(uint8* count, uint32* list) {
    *count = current_size; // Set the count to the current size of the database
    for (uint8 i = 0; i < current_size; i++) {
        list[i] = database[i].Student_ID; // Fill the list with student IDs
    }
}
bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < current_size; i++) {
        if (database[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}
