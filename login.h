#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dashboard.h"

void old_user() {
    char name[50], pass[50], ch;
    int found = 0,score;

    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("\nError: Could not open file.\n");
        return;
    }

    printf("\n\n");
    printf("\t\t\t\tUsername: ");
    scanf("%s", name);
    printf("\t\t\t\tPassword: ");
    scanf("%s", pass);

    user i;
    while (fscanf(fp, "%s %s %d", i.username, i.password, &i.score) != EOF) {
        if (strcmp(i.username, name) == 0 && strcmp(i.password, pass) == 0) {
            printf("\n\n\t\t\t\tUser found! Login successful.\n");
            found = 1;
            fclose(fp);
            dashboard(name);
            return;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\n\n\t\t\t\tIncorrect Username or Password!\n");
        printf("\n\n\t\t\t\tPress (E) to ESC | Press any other key to try again: ");
        getchar();  // Consume newline
        ch = getchar();
        if (ch != 'e' && ch != 'E') {
            old_user();
        }
    }
}

void new_user() {
    user i;
    FILE *fp;
    int exists = 0;

    fp = fopen("database.txt", "r");
    if (fp == NULL) {
        fp = fopen("database.txt", "a");
        if (fp == NULL) {
            printf("\nError: Could not open file.\n");
            return;
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
        return;
    }

    printf("\t\t\t\tPassword: ");
    scanf("%s", i.password);
    i.score = 0; // Default score

    fprintf(fp, "%s %s %d\n", i.username, i.password, i.score);
    fclose(fp);

    printf("\n\n\t\t\t\tRegistration successful!\n");

    dashboard(i.username);
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
            old_user();
            break;
        case 2:
            new_user();
            break;
        default:
            printf("\nInvalid choice! Try again.\n");
            login();
    }

    return 0;
}
