#include <stdio.h>
int main(){
    int n= 998;
    int sum=0;
    for (int i = 0; i<3; i++)  //n will continue until all numbers are added up
    {
        int last_digit= n%10;
        sum= last_digit+ sum;
        n= n/10;
    }
    int sum2=0;
    for (int i = 0; i<2; i++)
    {
        int second_last= sum%10;
        sum2= second_last+sum2;
        sum= sum/10;
    }

    printf("%d", sum2);
    
}