#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Forward declarations
void summation(int r1, int c1, int r2, int c2);
void subtraction(int r1, int c1, int r2, int c2);
void multiplication(int r1, int c1, int r2, int c2);

int matrix() {
    int r1, r2, c1, c2;
    char o;
    char again;
    
    top:
    system("cls");
    printf("Enter row and column of first matrix\n");
    scanf("%d%d", &r1, &c1);
    printf("Enter row and column of second matrix\n");
    scanf("%d%d", &r2, &c2);
    printf("\nAddition = +\nSubtraction = -\nMultiplication = *\nEnter the operation(+,-,*): ");
    scanf(" %c", &o);
    
    if(o == '+') {
        summation(r1, c1, r2, c2);
    }
    else if(o == '-') {
        subtraction(r1, c1, r2, c2);
    }
    else if(o == '*') {
        multiplication(r1, c1, r2, c2);
    }
    else {
        printf("Can't perform the operation!!!");
    }
    
    printf("\nDo you want to try again(Y/N): ");
    scanf(" %c", &again);
    again = toupper(again);
    if(again == 'Y') {
        goto top;
    }
    
    return 0;
}

void summation(int r1, int c1, int r2, int c2) {
    int i, j, a[10][10], b[10][10], sum[10][10];
    
    if((r1 == r2) && (c1 == c2)) {
        printf("Enter the first matrix element=\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        
        printf("Enter the second matrix element=\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                scanf("%d", &b[i][j]);
            }
        }

        for(i = 0; i < r1; ++i) {
            for(j = 0; j < c1; ++j) {
                sum[i][j] = a[i][j] + b[i][j];
            }
        }

        printf("\nSum of two matrix is: \n\n");
        for(i = 0; i < r1; ++i) {
            for(j = 0; j < c1; ++j) {
                printf("%d\t", sum[i][j]);
                if(j == c1-1) {
                    printf("\n\n");
                }
            }
        }
    }
    else {
        printf("Operation can't be performed!!!");
    }
    getchar();
}

void subtraction(int r1, int c1, int r2, int c2) {
    int i, j, a[10][10], b[10][10], sub[10][10];
    
    if((r1 == r2) && (c1 == c2)) {
        printf("Enter the first matrix element=\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        
        printf("Enter the second matrix element=\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                scanf("%d", &b[i][j]);
            }
        }

        for(i = 0; i < r1; ++i) {
            for(j = 0; j < c1; ++j) {
                sub[i][j] = a[i][j] - b[i][j];
            }
        }

        printf("\nSubtraction of two matrix is: \n\n");
        for(i = 0; i < r1; ++i) {
            for(j = 0; j < c1; ++j) {
                printf("%d\t", sub[i][j]);
                if(j == c1-1) {
                    printf("\n\n");
                }
            }
        }
    }
    else {
        printf("Operation can't be performed!!!");
    }
    getchar();
}

void multiplication(int r1, int c1, int r2, int c2) {
    int i, j, k, a[10][10], b[10][10], mul[10][10];
    
    if(c1 == r2) {
        printf("Enter the first matrix element=\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        
        printf("Enter the second matrix element=\n");
        for(i = 0; i < r2; i++) {
            for(j = 0; j < c2; j++) {
                scanf("%d", &b[i][j]);
            }
        }

        printf("multiply of the matrix=\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++) {
                mul[i][j] = 0;
                for(k = 0; k < r2; k++) {
                    mul[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++) {
                printf("%d\t", mul[i][j]);
            }
            printf("\n\n");
        }
    }
    else {
        printf("Operation can't be performed!!!");
    }
    getchar();
}

#endif /* MATRIX_H */