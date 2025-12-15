#include <stdio.h>
int main(){
    FILE* fptr;
    fptr= fopen("count_characters.csv", "r");
    int count;
    int number=0;
    while (fscanf(fptr, "%d", &count)==1)
    {
        number++;
    }
    printf("%d", number);
        
}
