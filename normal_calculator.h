#ifndef NORMAL_CALCULATOR_H
#define NORMAL_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NOTE "Maze mat lo, enter the valid operation"

void normal_calculator() {
    int choice,count=3;
    printf("\t\t\t\tWelcome to the Scientific Calculator!\n\n");
    printf("\t\t\t\t you get 3 calculations, chooose them wisely\n");
    printf("\t\t\t\tEnter 1 for Addition\n");
    printf("\t\t\t\tEnter 2 for Subtraction\n");
    printf("\t\t\t\tEnter 3 for Multiplication\n");
    printf("\t\t\t\tEnter 4 for Division\n");
    printf("\t\t\t\tEnter 5 for Modulus\n");
    printf("\t\t\t\tEnter 6 for Power\n");
    printf("\t\t\t\tEnter 7 for Factorial\n");
    printf("\t\t\t\tEnter 8 for Square\n");
    printf("\t\t\t\tEnter 9 for Cube\n");
    printf("\t\t\t\tEnter 10 for Square Root\n\n");
    printf("\t\t\t\t******* Press 0 to quit the program ********\n");

    while (count) {
        printf("\nEnter the operation you want to perform: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                count--;
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d%d", &a, &b);
                printf("Sum: %d\n", a + b);
                break;
            }
            case 2: {
                count--;
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d%d", &a, &b);
                printf("Difference: %d\n", a - b);
                break;
            }
            case 3: {
                count--;
                int a, b;
                printf("Enter two numbers: ");
                scanf("%d%d", &a, &b);
                printf("Product: %d\n", a * b);
                break;
            }
            case 4: {
                count--;
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
                count--;
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
                count--;
                double base, exp;
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &base, &exp);
                printf("Result: %.2lf\n", pow(base, exp));
                break;
            }
            case 7: {
                count--;
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
                count--;
                double num;
                printf("Enter a number: ");
                scanf("%lf", &num);
                printf("Square: %.2lf\n", pow(num, 2));
                break;
            }
            case 9: {
                count--;
                double num;
                printf("Enter a number: ");
                scanf("%lf", &num);
                printf("Cube: %.2lf\n", pow(num, 3));
                break;
            }
            case 10: {
                count--;
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

                count--;
        }
    }
}

#endif // NORMAL_CALCULATOR_H
