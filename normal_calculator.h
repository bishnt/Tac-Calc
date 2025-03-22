#ifndef NORMAL_CALCULATOR_H
#define NORMAL_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NOTE "Maze mat lo, enter the valid operation"

void normal_calculator() {
    int choice;
    printf("\t\tWelcome to the Scientific Calculator!\n\n");
    printf("******* Press 0 to quit the program ********\n");
    printf("Enter 1 for Addition\n");
    printf("Enter 2 for Subtraction\n");
    printf("Enter 3 for Multiplication\n");
    printf("Enter 4 for Division\n");
    printf("Enter 5 for Modulus\n");
    printf("Enter 6 for Power\n");
    printf("Enter 7 for Factorial\n");
    printf("Enter 8 for Square\n");
    printf("Enter 9 for Cube\n");
    printf("Enter 10 for Square Root\n\n");

    while (1) {
        printf("\nEnter the operation you want to perform: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d%d", &a, &b);
                printf("Sum: %d\n", a + b);
                break;
            }
            case 2: {
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d%d", &a, &b);
                printf("Difference: %d\n", a - b);
                break;
            }
            case 3: {
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d%d", &a, &b);
                printf("Product: %d\n", a * b);
                break;
            }
            case 4: {
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d%d", &a, &b);
                if (b == 0) {
                    printf("Error! Division by zero.\n");
                } else {
                    printf("Quotient: %.2f\n", (float)a / b);
                }
                break;
            }
            case 5: {
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d%d", &a, &b);
                if (b == 0) {
                    printf("Error! Modulus by zero.\n");
                } else {
                    printf("Modulus: %d\n", a % b);
                }
                break;
            }
            case 6: {
                double base, exp;
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &base, &exp);
                printf("Result: %.2lf\n", pow(base, exp));
                break;
            }
            case 7: {
                int n, fact = 1;
                printf("Enter a number: ");
                scanf("%d", &n);
                for (int i = 1; i <= n; i++) {
                    fact *= i;
                }
                printf("Factorial: %d\n", fact);
                break;
            }
            case 8: {
                double num;
                printf("Enter a number: ");
                scanf("%lf", &num);
                printf("Square: %.2lf\n", pow(num, 2));
                break;
            }
            case 9: {
                double num;
                printf("Enter a number: ");
                scanf("%lf", &num);
                printf("Cube: %.2lf\n", pow(num, 3));
                break;
            }
            case 10: {
                double num;
                printf("Enter a number: ");
                scanf("%lf", &num);
                if (num < 0) {
                    printf("Error! Square root of a negative number is undefined.\n");
                } else {
                    printf("Square root: %.2lf\n", sqrt(num));
                }
                break;
            }
            case 0:
                printf("Exiting calculator...\n");
                exit(0);
            default:
                printf("\n********** %s ***********\n", NOTE);
        }
    }
}

#endif // NORMAL_CALCULATOR_H
