#include<stdio.h>
#include<string.h>
struct student
{
	int age;
	char name[20];
	int roll_number;
	int batch;
};
int main() {
	struct student s1;
	s1.age = 20;
	strcpy(s1.name,"Saishitha");
	s1.roll_number = 5;
	s1.batch = 1;
	printf (" Age of the student s1 is: %d\t ", s1.age);
        printf (" \n Name of the student s1 is: %s\t ", s1.name);
        printf (" \n Roll_num of the student s1 is: %d\t ", s1.roll_number);
        printf (" \n Batch of the student s1 is: %d\t ", s1.batch);
}
