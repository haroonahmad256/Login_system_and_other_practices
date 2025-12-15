#include <stdio.h>
#include <string.h>
int main(){
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    int length= strlen(sentence);
    for (int i = 0; i<length ; i++)
    {
        if (sentence[i]==' ')
        {
            sentence[i]= '_';
        }
        
    }
    printf("%s", &sentence);
}