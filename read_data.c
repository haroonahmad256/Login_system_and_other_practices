#include <stdio.h>
int main(){
    FILE * fptr;
    fptr= fopen("data.csv", "r");
    char storage_file[50];
    // fscanf(fptr, "%s",storage_file );
    // printf("%s", storage_file);
    while ((fscanf(fptr, "%s", storage_file))!=EOF)
    {
        printf("%s\n", storage_file);
    }
}