#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dashboard.h"

typedef struct {
    char username[50];
    char password[50];
    int score;
} user;

// Function declarations
// In login.h

// Updated function prototypes
int old_user(char* current_username);
int new_user(char* current_username);
int login(char* current_username);

// Function implementations
int old_user(char* current_username) {
    char username[50];
    char password[50];
    char fileUsername[50];
    char filePassword[50];
    int fileScore;
    int found = 0;
    
    printf("\n\t\t\t\t===== LOGIN =====\n");
    printf("\t\t\t\tUsername: ");
    scanf("%s", username);
    printf("\t\t\t\tPassword: ");
    scanf("%s", password);
    
    // Open the database file
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("\n\t\t\t\tError: Could not open database file!\n");
        return 0;
    }
    
    // Read the file line by line to check credentials
    while (fscanf(file, "%s %s %d", fileUsername, filePassword, &fileScore) == 3) {
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            found = 1;
            strcpy(current_username, username); // Store the username
            break;
        }
    }
    
    fclose(file);
    
    if (found) {
        printf("\n\t\t\t\tLogin successful!\n");
        return 1; // Success
    } else {
        printf("\n\t\t\t\tInvalid username or password!\n");
        return 0; // Failure
    }
}

int new_user(char* current_username) {
    user i;
    FILE *fp;
    
    printf("\n\n\t\t\t\t===== REGISTER =====\n");
    
    while (1) {
        int exists = 0;
        printf("\t\t\t\tUsername: ");
        scanf("%s", i.username);
        
        // Check if username already exists
        fp = fopen("database.txt", "r");
        if (fp != NULL) {  // Only check if file was opened successfully
            char tempUsername[50];
            char tempPassword[50];
            int tempScore;
            
            while (fscanf(fp, "%s %s %d", tempUsername, tempPassword, &tempScore) == 3) {
                if (strcmp(tempUsername, i.username) == 0) {
                    exists = 1;
                    printf("\n\t\t\t\tUsername already exists! Try another.\n");
                    break;
                }
            }
            fclose(fp);  // Close file after checking
        }
        
        if (!exists) break;  // If username doesn't exist, break out of the loop
    }
    
    // Now open in append mode to add the new user
    fp = fopen("database.txt", "a");
    if (fp == NULL) {
        printf("\nError: Could not open database file for writing.\n");
        return 0;
    }
    
    printf("\t\t\t\tPassword: ");
    scanf("%s", i.password);
    i.score = 0; // Default score
    
    fprintf(fp, "%s %s %d\n", i.username, i.password, i.score);
    fclose(fp);
    
    // Store the username for the caller
    strcpy(current_username, i.username);
    
    printf("\n\n\t\t\t\tRegistration successful!\n");
    
    return 1; // Return success
}

int login(char* current_username) {
    int choice;
    printf("\n\n");
    printf("\t\t\t\tENTER\n");
    printf("\t\t\t\t(1) to Login\n");
    printf("\t\t\t\t(2) to Register\n");
    printf("\t\t\t\tChoice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            return old_user(current_username);
        case 2:
            return new_user(current_username);
        default:
            printf("\nInvalid choice! Try again.\n");
            return login(current_username);
    }
}

#endif /* LOGIN_H */