#include"vote.h"

//struct voterdetails voter;

// Function to check if the voter ID belongs to the booth
int checkVoterID(int voterID)
{
    FILE *file = fopen("voter_ids.txt", "r"); // Open the file in read mode

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 0;
    }

    int found = 0;
    int id;

    while (fscanf(file, "%d", &id) != EOF)
    {
        if (id == voterID)
        {
            found = 1;
            break;
        }
    }

    fclose(file); // Close the file

    return found;
}

void list()
{
    printf("Parties participating in the election are:\n1. PartyA\n2. PartyB\n3. PartyC\n");
}

int checkVoterStatus(int voterID)
{
    FILE *file = fopen("voting_details.txt", "r"); // Open the file in read mode

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 0;
    }

    char line[100];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strstr(line, "Voter ID: ") != NULL)
        {
            int id;
            sscanf(line, "Voter ID: %d", &id);
            if (id == voterID)
            {
                fclose(file); // Close the file
                return 1; // Voter has already voted
            }
        }
    }

    fclose(file); // Close the file

    return 0; // Voter has not voted yet
}

void cast()
{
    int partyChoice;

    printf("Enter the number corresponding to the party you want to vote for: ");
    scanf("%d", &partyChoice);
    
    if (checkVoterStatus(voter.id))
    {
        printf("You have already voted.\n");
        return;
    }

    FILE *file = fopen("voting_details.txt", "a"); // Open the file in append mode

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    switch(partyChoice)
    {
        case 1:
            strcpy(voter.votedFor, "PartyA");
            printf("You cast your vote for PartyA.\n");
            break;
        case 2:
            strcpy(voter.votedFor, "PartyB");
            printf("You cast your vote for PartyB.\n");
            break;
        case 3:
            strcpy(voter.votedFor, "PartyC");
            printf("You cast your vote for PartyC.\n");
            break;
        default:
            printf("Invalid party choice.\n");
            break;
    }

    fprintf(file, "Name: %s\nAge: %d\nVoter ID: %d\nVoted for: %s\n\n", voter.name, voter.age, voter.id, voter.votedFor);

    fclose(file); // Close the file
}

//USE ANY OF THE findleading FUNCTION
/*void findleading()
{
    FILE *file = fopen("voting_details.txt", "r"); // Open the file in read mode

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    int partyACount = 0;
    int partyBCount = 0;
    int partyCCount = 0;

    char line[100];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strstr(line, "PartyA") != NULL)
            partyACount++;
        else if (strstr(line, "PartyB") != NULL)
            partyBCount++;
        else if (strstr(line, "PartyC") != NULL)
            partyCCount++;
    }

    fclose(file); // Close the file

    printf("Vote count:\n");
    printf("PartyA: %d\n", partyACount);
    printf("PartyB: %d\n", partyBCount);
    printf("PartyC: %d\n", partyCCount);

    // Find the leading party
    if (partyACount > partyBCount && partyACount > partyCCount)
        printf("The leading party is: PartyA\n");
    else if (partyBCount > partyACount && partyBCount > partyCCount)
        printf("The leading party is: PartyB\n");
    else if (partyCCount > partyACount && partyCCount > partyBCount)
        printf("The leading party is: PartyC\n");
    else
        printf("There is a tie or no votes recorded.\n");
}*/

void findleading()
{
    FILE *file = fopen("voting_details.txt", "r"); // Open the file in read mode

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    int* partyACount = (int*)malloc(sizeof(int));  // Allocate memory for party counts
    int* partyBCount = (int*)malloc(sizeof(int));
    int* partyCCount = (int*)malloc(sizeof(int));

    *partyACount = 0;  // Initialize party counts
    *partyBCount = 0;
    *partyCCount = 0;

    char line[100];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strstr(line, "PartyA") != NULL)
            (*partyACount)++;
        else if (strstr(line, "PartyB") != NULL)
            (*partyBCount)++;
        else if (strstr(line, "PartyC") != NULL)
            (*partyCCount)++;
    }

    fclose(file); // Close the file

    //printf("Vote count:\n");
    //printf("PartyA: %d\n", *partyACount);
    //printf("PartyB: %d\n", *partyBCount);
    //printf("PartyC: %d\n", *partyCCount);

    // Create an array of pointers to party counts
    int** partyCounts = (int**)malloc(3 * sizeof(int*));
    partyCounts[0] = partyACount;
    partyCounts[1] = partyBCount;
    partyCounts[2] = partyCCount;

    // Sort the partyCounts array in descending order using bubble sort
    int* temp;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (*partyCounts[j] < *partyCounts[j + 1])
            {
                temp = partyCounts[j];
                partyCounts[j] = partyCounts[j + 1];
                partyCounts[j + 1] = temp;
            }
        }
    }

    printf("Election leading party:\n");
    for (int i = 0; i < 3; i++)
    {
        if (partyCounts[i] == partyACount)
            printf("%d. PartyA: %d\n", i + 1, *partyCounts[i]);
        else if (partyCounts[i] == partyBCount)
            printf("%d. PartyB: %d\n", i + 1, *partyCounts[i]);
        else if (partyCounts[i] == partyCCount)
            printf("%d. PartyC: %d\n", i + 1, *partyCounts[i]);
    }

    // Free allocated memory
    free(partyCounts);
    free(partyACount);
    free(partyBCount);
    free(partyCCount);
}

int options()
{
    int option;
    printf("Available options are:\n1. Cast your vote\n2. Find leading Candidate\n3. Exit\n");
    printf("Please choose your option (1-3): ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("You selected the option to Cast your vote.\n");
            cast(voter);
            break;
        case 2:
            printf("You selected the option to Find the leading Candidate.\n");
            findleading();
            break;
        case 3:
            printf("You selected the option to Exit.\n");
            break;
        default:
            printf("Invalid Option.\n");
            break;
    }

    return option;
}
