/* dashboard.h */
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Shared user structure definition
typedef struct {
    char username[50];
    char password[50];
    int score;
} user_t;  // Renamed to user_t to avoid conflicts

// Function to fetch user details from file
void get_user_details(const char *username, user_t *u);

// Function to display the dashboard
void dashboard(const char *username);

#ifdef DASHBOARD_IMPLEMENTATION

void get_user_details(const char *username, user_t *u) {
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("\nError: Could not open file.\n");
        return;
    }

    while (fscanf(fp, "%s %s %d", u->username, u->password, &u->score) != EOF) {
        if (strcmp(u->username, username) == 0) {
            fclose(fp);
            return;
        }
    }

    fclose(fp);
}

void dashboard(const char *username) {
    // For Linux/macOS; use "cls" for Windows
    system("cls"); // Using cls for Windows, change to "clear" for Linux/macOS

    user_t u;  // Changed to user_t
    get_user_details(username, &u);

    printf("\n\n\t\t\t\tWelcome, %s!\n", u.username);
    printf("\t\t\t\t-------------------------------\n");
    printf("\t\t\t\tUsername: %s\n", u.username);
    printf("\t\t\t\tScore: %d\n", u.score);
    printf("\t\t\t\t-------------------------------\n");
}

#endif /* DASHBOARD_IMPLEMENTATION */

#endif /* DASHBOARD_H */
