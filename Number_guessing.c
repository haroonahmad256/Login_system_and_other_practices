#include <stdio.h>
int main(){
    int on =1;
    int n, constant= 67;
    while (on)
    {
        printf("\nGuess a number: ");
        scanf("%d", &n);
        if (n>constant)
        {
            printf("Please Enter lower number\n");
        }
        else if (n<constant)
        {
            printf("Please Enter Higher number\n");
        }
        else if (n==constant)
        {
            printf("Conguratulations! You have guessed the number..........");
            on=0;
        }
    }
    
}