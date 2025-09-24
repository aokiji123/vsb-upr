#include <stdio.h>

int main() {
    int amount = 17920;
    int bills[] = { 5000, 2000, 1000, 500, 200, 100 };
    int numberOfBills = sizeof(bills) / sizeof(bills[0]);

    printf("Total: %d Kc\n", amount);

    for (int i = 0; i < numberOfBills; i++) {
        int count = amount / bills[i];
        printf("%dx %d Kc\n", count, bills[i]);
        amount = amount % bills[i];
    }

    if (amount > 0) {
        printf("Remaining: %d Kc (not covered by available bills)\n\n", amount);
    }

    return 0;
}
