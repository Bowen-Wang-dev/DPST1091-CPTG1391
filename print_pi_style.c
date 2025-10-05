#include <stdio.h>

#define MAX_DIGITS 10

void print_pi_style(int num_digits);

int main(void) {
    int n; // n = number of digits
    
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &n);
    
    print_pi_style(n);
    printf("\n");
    
    return 0;
}

void print_pi_style(int num_digits) {
    // DO NOT CHANGE THIS LINE
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    // TODO: Finish this function below
    
    int i; // i = counter
    
    // Print first digit and decimal point
    printf("%d.", pi[0]);
    
    // Print remaining digits
    i = 1;
    while (i < num_digits) {
        printf("%d", pi[i]);
        i = i + 1;
    }
}
