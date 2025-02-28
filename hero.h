#include <stdio.h>

#include <windows.h>

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int hero() {
    setColor(3); 
    printf("\n \n \t \t  _______       _____       _____           _      _____ \n");
    printf("\t \t |__   __|/\\   / ____|    / ____|    /\\   | |    / ____|\n");
    printf("\t \t    | |  /  \\  | |  ______| |       /  \\  | |   | |     \n");
    printf("\t \t    | | / /\\ \\ | | |______| |      / /\\ \\ | |   | |     \n");
    printf("\t \t    | |/ ____ \\| |____    | |____ / ____ \\| |___| |____ \n");
    printf("\t \t    |_/_/    \\_\\______|    \\_____/_/    \\_\\______\\_____|\n");

    setColor(5);

    printf("\n\t  Welcome to our interactive Tic-Tac-Toe game, where fun meets functionality! \n\tPlay, earn points, and use them to perform circuit calculations, simple arithmetic,\n\t\t\t\tand more. Let the game begin!");

    setColor(6); 

    printf("\n\n\t\t\t\t Enter any key to continue.\n");

    setColor(7); 
    getchar();
    return 0;
}


