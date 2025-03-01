

#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Include dashboard.h without defining DASHBOARD_IMPLEMENTATION here
#include "dashboard.h"

// Function declarations
int old_user();
int new_user();
int login();

// Function implementations
int old_user() {
    char username[50];
    char password[50];
    char fileUsername[50];
    char filePassword[50];
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
        return 0; // Return failure if file can't be opened
    }
    
    // Read the file line by line to check credentials
    while (fscanf(file, "%s %s", fileUsername, filePassword) == 2) {
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            found = 1;
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

int new_user() {
    user i;
    FILE *fp;
    int exists = 0;
    
    fp = fopen("database.txt", "r");
    if (fp == NULL) {
        fp = fopen("database.txt", "a");
        if (fp == NULL) {
            printf("\nError: Could not open file.\n");
            return -1;
        }
    }
    
    printf("\n\n");
    while (1) {
        exists = 0;
        printf("\t\t\t\tUsername: ");
        scanf("%s", i.username);
        
        user temp;
        while (fscanf(fp, "%s %s %d", temp.username, temp.password, &temp.score) != EOF) {
            if (strcmp(temp.username, i.username) == 0) {
                exists = 1;
                printf("\n\t\t\t\tUsername already exists! Try another.\n");
                break;
            }
        }
        
        if (!exists) break;
        fseek(fp, 0, SEEK_SET);
    }
    
    fclose(fp);
    
    fp = fopen("database.txt", "a");
    if (fp == NULL) {
        printf("\nError: Could not open file.\n");
        return -1;
    }
    
    printf("\t\t\t\tPassword: ");
    scanf("%s", i.password);
    i.score = 0; // Default score
    
    fprintf(fp, "%s %s %d\n", i.username, i.password, i.score);
    fclose(fp);
    
    printf("\n\n\t\t\t\tRegistration successful!\n");
    dashboard(i.username);
    
    return i.score;
}

int login() {
    int choice;
    printf("\n\n");
    printf("\t\t\t\tENTER\n");
    printf("\t\t\t\t(1) to Login\n");
    printf("\t\t\t\t(2) to Register\n");
    printf("\t\t\t\tChoice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            return old_user();
        case 2:
            return new_user();
        default:
            printf("\nInvalid choice! Try again.\n");
            return login();
    }
}

#endif /* LOGIN_H */