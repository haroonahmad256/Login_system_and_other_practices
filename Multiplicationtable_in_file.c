#include <stdio.h>
int main(){
    FILE* fptr;
    fptr= fopen("file.txt", "w");
    int n=5;

    for (int i = 0; i < 10; i++)
    {
        fprintf(fptr, "%d x %d = %d \n",n, i+1, n*(i+1) );
    }

    if(fptr==NULL){
        printf("File could not be created or opened");
    }
    else
    {
        printf("File is written successfully");
    }
    
}