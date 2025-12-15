#include <stdio.h>
#include <string.h>
int main(){
    FILE* fptr;
    fptr= fopen("username_and_password.csv", "r");
    if (fptr==NULL)
    {
        printf("Error opening file");
    }
    
    char enter_username[50];
    int enter_password;
    printf("Enter your username: ");
    scanf("%s", enter_username);
    printf("Enter your password: ");
    scanf("%d", &enter_password);

    int on=0, i=0;
    char username[50];
    int password;
    for (int i = 0; i < 3; i++)
    {
        while (fscanf(fptr, "%s %d", username, &password )==2)
    {
        // fscanf(fptr,"%s %d",username, &password );
        if (strcmp(username, enter_username)==0 && password== enter_password)
        {
            on=1;
        }
        i++;
    }

        if (on)
        {
            printf("Login successful\n");
        }
        
        else
        {
            printf("Invaid username or password\n");
        }  
    
    }
    
    
    fclose(fptr);

}