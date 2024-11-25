#include <stdio.h>

// Function to check if the day is valid for months with 30 days
int check(int day, int month) {
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
        return 1;
    return 0;
}

// Function to check if a year is a leap year
int isleap(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    return 0;
}

int main() {
    int day, month, year;
    int tday, tmonth, tyear;
    char flag;

    do {
        flag = 'y';

        // Input date
        printf("Enter today's date in dd mm yyyy format: ");
        scanf("%d %d %d", &day, &month, &year);

        tmonth = month;
        tyear = year;

        // Validate day
        if (day < 1 || day > 31) {
            printf("Error: Day value must be in the range 1--31.\n");
            flag = 'n';
        }

        // Validate month
        if (month < 1 || month > 12) {
            printf("Error: Month value must be in the range 1--12.\n");
            flag = 'n';
        } else if (check(day, month)) {
            printf("Error: Day value exceeds 30 for the given month.\n");
            flag = 'n';
        }

        // Validate year
        if (year < 1812 || year > 2018) {
            printf("Error: Year value must be in the range 1812--2018.\n");
            flag = 'n';
        }

        // Handle February for leap and non-leap years
        if (month == 2) {
            if (isleap(year) && day > 29) {
                printf("Error: Invalid day for a leap year.\n");
                flag = 'n';
            }
            if (!isleap(year) && day > 28) {
                printf("Error: Invalid day for a non-leap year.\n");
                flag = 'n';
            }
        }

    } while (flag == 'n');

    // Determine the next day
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10:
            if (day < 31) {
                tday = day + 1;
            } else {
                tday = 1;
                tmonth = month + 1;
            }
            break;

        case 4: case 6: case 9: case 11:
            if (day < 30) {
                tday = day + 1;
            } else {
                tday = 1;
                tmonth = month + 1;
            }
            break;

        case 12:
            if (day < 31) {
                tday = day + 1;
            } else {
                tday = 1;
                tmonth = 1;
                if (year == 2018) {
                    printf("Next year is out of the valid range.\n");
                } else {
                    tyear = year + 1;
                }
            }
            break;

        case 2:
            if (day < 28) {
                tday = day + 1;
            } else if (isleap(year) && day == 28) {
                tday = day + 1;
            } else if (day == 28 || day == 29) {
                tday = 1;
                tmonth = 3;
            }
            break;
    }

    // Print the next day
    printf("Next day is %d/%d/%d\n", tday, tmonth, tyear);
    return 0;
}
