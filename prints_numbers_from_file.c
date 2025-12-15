#include <stdio.h>
int main(){
    FILE *fptr;
    fptr= fopen("sample.txt", "r");
    int n;
    fscanf(fptr,"%d ", &n);
    printf("%d ", n);
    fscanf(fptr,"%d ", &n);
    printf("%d ", n);
    fscanf(fptr,"%d ", &n);
    printf("%d ", n);
    fscanf(fptr,"%d ", &n);
    printf("%d ", n);
    fscanf(fptr,"%d ", &n);
    printf("%d ", n);
    
    
    fclose(fptr);
}