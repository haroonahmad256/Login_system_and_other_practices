#include <stdio.h>
int main(){
    FILE * fptr;
    fptr= fopen("sampel.txt", "w");

    char name[100], program[50], status[50];
    int roll_number;

    printf("Student name: ");
    scanf("%s", &name);
    fprintf(fptr, "Name of student: %s\n", name);

    printf("Student roll number: ");
    scanf("%d", &roll_number);
    fprintf(fptr, "Student Roll number: %d", roll_number);
    
    printf("Student program: ");
    scanf("%s", &program);
    fprintf(fptr, "Program of student: %s\n", program);

    printf("Student status: ");
    scanf("%s", &status);
    fprintf(fptr, "Status of student: %s\n", status);
  

    fclose(fptr);
}