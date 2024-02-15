// program using structure pointer

//syntax for structure pointer is->  struct structure_name *pointer_name or variable

//Initialization of structure pointer-> struct structure_name *pointer_variable = &structure_variable;

#include <stdio.h>
#include <string.h>

// create the Structure of student to store multiples items
struct student
{
    char name[ 30];
    int roll_no;
    char state[100];
    int age;
};
struct student s1; // declare s1 variable of student structure

int main()
{
    // records of the student s1
    strcpy (s1.name, "Saishitha");
    s1.roll_no = 5;
    strcpy (s1.state, "AP");
    s1.age = 21;
   // struct student *p;
   struct student *p = &s1; 
    // print the details of the student s1;
    printf (" Name of the student s1 is: %s\t ", (*p).name);
    printf (" \n Roll No. of the student s1 is: %d\t ", (*p).roll_no);
    printf (" \n The state of the student s1 is: %s\t ", (*p).state);
    printf (" \n Age of the student s1 is: %d\n ",(*p).age);
}
