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
void updatePointsInFile(int points) {
    FILE *file = fopen("points.txt", "w");  // Open the file in write mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%d", points);  // Write the points to the file
    fclose(file);  // Close the file
}

// Function to read points from the file
int readPoints() {
    int points = 0;
    FILE *file = fopen("points.txt", "r");  // Open the file in read mode
    if (file == NULL) {
        // If the file doesn't exist, create it with 0 points
        file = fopen("points.txt", "w");
        fprintf(file, "%d", points);
        fclose(file);
        return points;
    }
    fscanf(file, "%d", &points);  // Read the points from the file
    fclose(file);  // Close the file
    return points;
}



// Implementation of showMainMenu function
void showMainMenu() {
    int points = readPoints(); // Read points from file
    
    printf("\n\t\t\t\t===== DASHBOARD =====\n");
    printf("\t\t\t\tWelcome to the Dashboard!\n");
    printf("\t\t\t\tCurrent Points: %d\n", points);
    
    // Call the existing mainMenu function
    mainMenu(&points);
}

// Main menu function
void mainMenu(int *points) {
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
                if (game()) {
                    (*points)++;  // Increase points if game() returns true (win)
                    printf("\n\t\t\t\t You won! Points increased by 1.\n");
                    updatePointsInFile(*points);  // Update points in the file
                }
                break;
            case 2:
                if (*points >= 1) {
                    printf("\n\t\t\t\t Performing Normal Calculations...\n");
                    normal_calculator();
                    (*points) -= 1;  // Deduct 1 point
                    updatePointsInFile(*points);  // Update points in the file
                } else {
                    printf("\n\t\t\t\t Not enough points! You need at least 1 point.\n");
                }
                break;
            case 3:
                if (*points >= 2) {
                    printf("\n\t\t\t\t Performing Matrix Calculations...\n");
                    matrix();
                    (*points) -= 2;  // Deduct 2 points
                    updatePointsInFile(*points);  // Update points in the file
                } else {
                    printf("\n\t\t\t\t Not enough points! You need at least 2 points.\n");
                }
                break;
            case 4:
                if (*points >= 3) {
                    printf("\n\t\t\t\t Performing Circuit Calculations...\n");
                    circuit();
                    (*points) -= 3;  // Deduct 3 points
                    updatePointsInFile(*points);  // Update points in the file
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

        printf("\n\t\t\t\t Remaining Points: %d\n", *points);
        press_any_key();
    }
}

int main() {

    hero();
    line();


    

    color(6);
    while(1) {
        int loginSuccess = login(); // Your existing credentials check function
        
        if(loginSuccess) {
            // Show main menu and handle menu options
            color(7);
            showMainMenu();
            line();
        } else {
            printf("Invalid credentials!\n");
            char retry;
            printf("Try again? (y/n): ");
            scanf(" %c", &retry);
            
            if(retry != 'y' && retry != 'Y') {
                printf("Exiting program. Goodbye!\n");
                return 0; // Exit the program completely
            }
        }
    }
    return 0;
}