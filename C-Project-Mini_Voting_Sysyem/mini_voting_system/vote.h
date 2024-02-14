#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct voterdetails
{
    int age;
    char name[50];
    int id;
    char votedFor[10];
}voter;

int checkVoterID();
int checkVoterStatus(int voterID);
void list();
void cast();
void findleading();
int options();
