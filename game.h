#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

// Function prototypes
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

// Game function
int game() {
    char winner = ' ';
    
    // Initialize the game once
    resetBoard();
    
    // Play a single game
    while (winner == ' ' && checkFreeSpaces() != 0) {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }
        computerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }
    }
    
    // Show final board and result
    printBoard();
    printWinner(winner);
    
    // Return different values based on the game outcome
    if (winner == PLAYER) {
        return 1;  // Player wins - add a point
    } else if (winner == COMPUTER) {
        return -1; // Computer wins - subtract a point
    } else {
        return 0;  // It's a tie - no change in points
    }
}

// Reset the board to empty spaces
void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the current state of the board
void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Check the number of free spaces on the board
int checkFreeSpaces() {
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

// Handle the player's move
void playerMove() {
    int x, y;
    while (1) {
        printf("Enter row #(1-3): ");
        
        // Validate input
        if (scanf("%d", &x) != 1) {
            printf("Invalid input! Please enter a number between 1-3.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        printf("Enter column #(1-3): ");
        if (scanf("%d", &y) != 1) {
            printf("Invalid input! Please enter a number between 1-3.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        x--; // Convert to zero-based index
        y--;

        // Check if input is valid
        if (x < 0 || x > 2 || y < 0 || y > 2) {
            printf("Invalid coordinates! Please try again.\n");
        } else if (board[x][y] != ' ') {
            printf("Invalid Move! That space is already taken.\n");
        } else {
            board[x][y] = PLAYER;
            break;
        }

        while (getchar() != '\n'); // Clear input buffer after valid/invalid input
    }
}

// Handle the computer's move
void computerMove() {
    srand(time(0));
    int x, y;
    if (checkFreeSpaces() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    } else {
        printWinner(' ');
    }
}

// Check for a winner
char checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    return ' ';  // No winner yet
}

// Print the winner
void printWinner(char winner) {
    if (winner == PLAYER) {
        printf("YOU WIN!!\n");
    } else if (winner == COMPUTER) {
        printf("YOU LOST!!\n");
    } else {
        printf("IT'S A TIE!!\n");
    }
}