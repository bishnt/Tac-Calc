#include <stdio.h>
#include<windows.h>

#define MAX_BRANCHES 10

// Function to calculate parallel resistance
double parallel_resistance(double r1, double r2) {
    return (r1 * r2) / (r1 + r2);
}


int circuit() {

    setColor(3);
    printf("\n\n Welcome to the Circuit Calculator..\n");
    setColor(7);

    double voltage, resistance, total_resistance;
    char choice;
    int branches = 1, resistors_in_branch[MAX_BRANCHES] = {0};
    double branch_resistances[MAX_BRANCHES] = {0};
    
    printf("Enter the voltage source (in volts): ");
    scanf("%lf", &voltage);
    
    printf("Enter a resistance (in ohms) to get started: ");
    scanf("%lf", &resistance);
    
    branch_resistances[0] = resistance;
    resistors_in_branch[0] = 1;
    
    // Draw the initial circuit
    printf("\nCircuit Representation:\n");
    printf(" ----l| ----");
    printf("|           |");
    printf("|           |");
    printf(" ----^^^---- ");
    printf(" --\n");
    
    do {
        printf("Do you want to add another resistor? (Y/N): ");
        scanf(" %c", &choice);
        
        if (choice == 'Y' || choice == 'y') {
            int location, series_parallel;
            printf("1) Add to the same branch or new branch? (1: Same, 2: New): ");
            scanf("%d", &location);
            
            if (location == 1) { // Same branch
                printf("Enter the resistance value (in ohms): ");
                scanf("%lf", &resistance);
                
                printf("In series (1) or parallel (2)?: ");
                scanf("%d", &series_parallel);
                
                if (series_parallel == 1) { // Series
                    branch_resistances[branches - 1] += resistance;
                } else if (series_parallel == 2) { // Parallel
                    branch_resistances[branches - 1] = parallel_resistance(branch_resistances[branches - 1], resistance);
                }
                resistors_in_branch[branches - 1]++;
                
            } else if (location == 2 && branches < MAX_BRANCHES) { // New branch
                printf("Enter the resistance value (in ohms): ");
                scanf("%lf", &resistance);
                branch_resistances[branches] = resistance;
                resistors_in_branch[branches] = 1;
                branches++;
            }
        }
        
    } while (choice == 'Y' || choice == 'y');
    
    // Compute equivalent resistance
    total_resistance = branch_resistances[0];
    for (int i = 1; i < branches; i++) {
        total_resistance = parallel_resistance(total_resistance, branch_resistances[i]);
    }
    
    // Compute current
    double current = voltage / total_resistance;
    
    // Display results
    printf("\nEquivalent Resistance: %.2f ohms\n", total_resistance);
    printf("Total Circuit Current: %.2f A\n", current);
    
    return 0;
}
