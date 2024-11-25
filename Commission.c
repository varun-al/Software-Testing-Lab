#include <stdio.h>

int main() {
    int locks, stocks, barrels;
    int tlocks = 0, tstocks = 0, tbarrels = 0;
    float lprice = 45.0, sprice = 30.0, bprice = 25.0;
    float sales = 0, comm;
    int c1, c2, c3, temp;

    printf("Enter the number of locks (press -1 to exit): ");
    scanf("%d", &locks);

    while (locks != -1) {
        // Validate locks input
        c1 = (locks <= 0 || locks > 70);
        
        printf("Enter the number of stocks and barrels: ");
        scanf("%d %d", &stocks, &barrels);
        
        // Validate stocks and barrels input
        c2 = (stocks <= 0 || stocks > 80);
        c3 = (barrels <= 0 || barrels > 90);

        if (c1) {
            printf("Error: Value of locks not in range 1--70.\n");
        } else {
            temp = locks + tlocks;
            if (temp > 70) {
                printf("Error: New value of locks = %d exceeds range 1--70.\n", temp);
            } else {
                tlocks = temp;
            }
        }
        printf("Total locks: %d\n", tlocks);

        if (c2) {
            printf("Error: Value of stocks not in range 1--80.\n");
        } else {
            temp = stocks + tstocks;
            if (temp > 80) {
                printf("Error: New value of stocks = %d exceeds range 1--80.\n", temp);
            } else {
                tstocks = temp;
            }
        }
        printf("Total stocks: %d\n", tstocks);

        if (c3) {
            printf("Error: Value of barrels not in range 1--90.\n");
        } else {
            temp = barrels + tbarrels;
            if (temp > 90) {
                printf("Error: New value of barrels = %d exceeds range 1--90.\n", temp);
            } else {
                tbarrels = temp;
            }
        }
        printf("Total barrels: %d\n", tbarrels);

        printf("Enter the number of locks (press -1 to exit): ");
        scanf("%d", &locks);
    }

    if (tlocks > 0 && tstocks > 0 && tbarrels > 0) {
        // Calculate total sales
        printf("Total locks: %d\nTotal stocks: %d\nTotal barrels: %d\n", tlocks, tstocks, tbarrels);
        sales = (tlocks * lprice) + (tstocks * sprice) + (tbarrels * bprice);
        printf("Total sales: %.2f\n", sales);

        // Calculate commission
        if (sales > 1800) {
            comm = 0.10 * 1000.0;
            comm += 0.15 * 800.0;
            comm += 0.20 * (sales - 1800);
        } else if (sales > 1000) {
            comm = 0.10 * 1000.0;
            comm += 0.15 * (sales - 1000);
        } else {
            comm = 0.10 * sales;
        }
        printf("Commission: %.2f\n", comm);
    } else {
        printf("No sales were made.\n");
    }

    return 0;
}
