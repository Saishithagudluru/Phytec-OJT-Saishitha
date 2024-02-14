#include"vote.h"

int main()
{
    printf("Welcome to the Polling Booth.\n");
    printf("Enter your full name: ");
    fgets(voter.name, sizeof(voter.name), stdin);
    voter.name[strcspn(voter.name, "\n")] = '\0';
    printf("Hello, %s. Enter your age: ", voter.name);
    scanf("%d", &voter.age);

    if (voter.age >= 18)
    {
        printf("%s, you are eligible to vote.\n", voter.name);

        printf("Enter your 4-digit ID number: ");
        scanf("%d", &voter.id);

        // Calculate the length of the ID
        int idLength = snprintf(NULL, 0, "%d", voter.id);
        if (idLength != 4)
        {
            printf("Invalid ID number.\n");
            return 0;
        }

        if (!checkVoterID(voter.id))
        {
            printf("You don't belong to this booth. Please check your voter ID.\n");
            return 0;
        }
    }
    else
    {
        printf("%s, you are not eligible to vote.\n", voter.name);
        return 0;
    }

    list();
    options(voter);

    return 0;
}

