#include <stdio.h>
#include<math.h>

int main() {
    int day, month, year;

    // Getting user input for the date
    printf("Enter date (day month year): ");
    scanf("%d %d %d", &day, &month, &year);


    if (month < 3) {
        month += 12;
        year--;
    }

    int K = year % 100;
    int J = year / 100;

    int dayOfWeek = (day + ((13 * (month + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;

    // Converting the result to match the day of the week (0 = Saturday, 1 = Sunday, ..., 6 = Friday)
    if (dayOfWeek < 0) {
        dayOfWeek += 7;
    }

    // Printing the day of the week
    switch (dayOfWeek) {
        case 0:
            printf("Saturday\n");
            break;
        case 1:
            printf("Sunday\n");
            break;
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
    }

    return 0;
}
