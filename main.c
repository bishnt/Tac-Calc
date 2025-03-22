#define DASHBOARD_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Added for SetConsoleTextAttribute
#include "dashboard.h"
#include "login.h"
#include "matrix.h"
#include "hero.h"
#include "circuit.h"
#include "game.h"
#include "normal_calculator.h"

// Function declarations
void line();
void color(int color_code);
void press_any_key();
void mainMenu(int *points);
void updatePointsInFile(int points);
int readPoints();
int checkCredentials(); // Added missing function declaration
void showMainMenu(); // Added missing function declaration

// Function to draw a line for UI
void line() {
    printf("\n\t  ___________________________________________________________________________\t\n\n");
}

// Function to set console text color
void color(int color_code) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code);
}

// Function to wait for user input to continue
void press_any_key() {
    printf("\n\t\t\t\tPress any key to continue...");
    while (getchar() != '\n');  // Clear buffer
    getchar();  // Wait for key press
}

// Function to update points in the file
void updatePointsInFile(const char* username, int points) {
    char fileUsername[50];
    char filePassword[50];
    int fileScore;
    FILE *oldFile = fopen("database.txt", "r");
    FILE *newFile = fopen("temp.txt", "w");
    
    if (oldFile == NULL || newFile == NULL) {
        printf("Error opening files!\n");
        return;
    }
    
    while (fscanf(oldFile, "%s %s %d", fileUsername, filePassword, &fileScore) == 3) {
        if (strcmp(username, fileUsername) == 0) {
            // Update this user's score
            fprintf(newFile, "%s %s %d\n", fileUsername, filePassword, points);
        } else {
            // Keep the other users as they are
            fprintf(newFile, "%s %s %d\n", fileUsername, filePassword, fileScore);
        }
    }
    
    fclose(oldFile);
    fclose(newFile);
    
    // Replace the old file with the new file
    remove("database.txt");
    rename("temp.txt", "database.txt");
}

// Function to read points for the current user
int readPoints(const char* username) {
    char fileUsername[50];
    char filePassword[50];
    int fileScore;
    FILE *file = fopen("database.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    
    while (fscanf(file, "%s %s %d", fileUsername, filePassword, &fileScore) == 3) {
        if (strcmp(username, fileUsername) == 0) {
            fclose(file);
            return fileScore;
        }
    }
    
    fclose(file);
    return 0; // User not found
}



// Implementation of showMainMenu function
void showMainMenu(const char* username) {
    int points = readPoints(username); // Read points for current user
    
    printf("\n\t\t\t\t===== DASHBOARD =====\n");
    printf("\t\t\t\tWelcome, %s!\n", username);
    printf("\t\t\t\tCurrent Points: %d\n", points);
    
    // Call the mainMenu function with username
    mainMenu(username);
}

// Main menu function
void mainMenu(const char* username) {
    int points = readPoints(username); // Read points for current user
    int choice;

    while (1) {
        line();
        printf("\n\n\n");
        printf("\t\t\t\t Choose any of the options:\n");
        printf("\t\t\t\t Press (1) for Tic-Tac-Toe (Free)\n");
        printf("\t\t\t\t Press (2) for Normal Calculations (Need 1 pt)\n");
        printf("\t\t\t\t Press (3) for Matrix Calculations (Need 2 pts)\n");
        printf("\t\t\t\t Press (4) for Circuit Calculations (Need 3 pts)\n");
        printf("\t\t\t\t Press (5) to Exit\n");

        printf("\t\t\t\t Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n\t\t\t\t Starting Tic-Tac-Toe...\n");
                int gameResult = game();
                if (gameResult > 0) {
                    points++;  // Increase points if game() returns positive (win)
                    printf("\n\t\t\t\t You won! Points increased by 1.\n");
                    updatePointsInFile(username, points);  // Update points
                } else if (gameResult < 0) {
                    printf("\n\t\t\t\t You lost.\n");
                } else {
                    printf("\n\t\t\t\t It's a tie.\n");
                }
                break;
            case 2:
                if (points >= 1) {
                    printf("\n\t\t\t\t Performing Normal Calculations...\n");
                    normal_calculator();
                    points -= 1;  // Deduct 1 point
                    updatePointsInFile(username, points);  // Update points
                } else {
                    printf("\n\t\t\t\t Not enough points! You need at least 1 point.\n");
                }
                break;
            case 3:
                if (points >= 2) {
                    printf("\n\t\t\t\t Performing Matrix Calculations...\n");
                    matrix();
                    (points) -= 2;  // Deduct 2 points
                    updatePointsInFile(username, points);  // Update points in the file
                } else {
                    printf("\n\t\t\t\t Not enough points! You need at least 2 points.\n");
                }
                break;
            case 4:
                if (points >= 3) {
                    printf("\n\t\t\t\t Performing Circuit Calculations...\n");
                    circuit();
                    (points) -= 3;  // Deduct 3 points
                    updatePointsInFile(username,points);  // Update points in the file
                } else {
                    printf("\n\t\t\t\t Not enough points! You need at least 3 points.\n");
                }
                break;
            case 5:
                printf("\n\t\t\t\t Exiting the program...\n");
                return;
            default:
                printf("\n\t\t\t\t Invalid choice! Please try again.\n");
        }

        printf("\n\t\t\t\t Remaining Points: %d\n", points);
        press_any_key();
    }
}

int main() {
    char current_username[50]; // Store the current user's username
    
    hero();
    line();

    color(6);
    while(1) {
        int loginSuccess = login(current_username); // Modify login to return the username
        
        if(loginSuccess) {
            // Show main menu with username
            color(7);
            showMainMenu(current_username);
            line();
        } else {
            printf("Login failed!\n");
            char retry;
            printf("Try again? (y/n): ");
            scanf(" %c", &retry);
            
            if(retry != 'y' && retry != 'Y') {
                printf("Exiting program. Goodbye!\n");
                return 0;
            }
        }
    }
    return 0;
}