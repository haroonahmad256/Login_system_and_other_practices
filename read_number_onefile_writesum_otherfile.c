#include <stdio.h>
int main(){
    FILE* fptr;
    fptr= fopen("Sum_Of_two_numbers.txt", "r");
    int a, b;
    fscanf(fptr, "%d", &a);
    fscanf(fptr, "%d", &b);
    fptr= fopen("Sum_of_two_numbers.txt", "w");
    fprintf(fptr, "%d", a+b);
    fclose(fptr);
}