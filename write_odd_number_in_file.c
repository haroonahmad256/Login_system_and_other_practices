#include <stdio.h>
int main(){
    FILE* fptr;
    fptr= fopen("Odd.txt", "w");
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i%2!=0)
        {
            printf("%d\n", i);
            fprintf(fptr, "Odd number: %d\n", i);
        }
    }  
}