#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void signup_function(char firstname[], char lastname[], char email[], char username[], char phonenumber[], char password[])
{

    FILE *fptr;
    fptr = fopen("users.txt", "a");
    fprintf(fptr, "%s %s %s %s %s %s\n", firstname, lastname, email, username, phonenumber, password);
    fclose(fptr);
}

void signin_function()
{
    int choice;
    printf("1. Enter information to login\n");
    printf("2. Reset Password\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        FILE *fptr;
        fptr = fopen("users.txt", "r");

        if (fptr == NULL)
        {
            printf("Error opening file");
        }
        char enter_username[50];
        char enter_password[20];
        printf("Enter your username: ");
        scanf("%s", enter_username);
        printf("Enter your password: ");
        scanf("%s", enter_password);

        int i = 1;
        do
        {
            int on = 0;
            char username[20];
            char password[20];
            char firstname[20], lastname[20], email_address[100], phonenumber[20];
            char new_password[20];

            while (fscanf(fptr, "%s %s %s %s %s %s", firstname, lastname, email_address, username, phonenumber, password) == 6)
            {
                // fscanf(fptr,"%s %d",username, &password );
                if (strcmp(username, enter_username) == 0 && strcmp(password, enter_password) == 0)
                {
                    on = 1;
                }
            }

            if (on)
            {
                printf("Login successful\n");
                i = 0;
            }

            else
            {
                printf("Invaid username or password\n");
                break;
            }
            fclose(fptr);

        } while (i);
        
        break;
    
    case 2:
        rewind(fptr);
        FILE *fptr2;
        fptr = fopen("users.txt", "r");
        fptr2 = fopen("user_temp.txt", "w");
        char username[20];
        char password[20];
        char firstname[20], lastname[20], email_address[100], phonenumber[20];
        char new_password[20];
        char input_email[100];
        char fpassword[1];
        printf("Forgot password(y/n): ");
        scanf("%s", fpassword);
        int inside = 0;

        if (fpassword[0] == 'y' || fpassword[0] == 'Y')
        {
            printf("Enter your email address to verify: ");
            scanf("%s", input_email);

            while (fscanf(fptr, "%s %s %s %s %s %s", firstname, lastname, email_address, username, phonenumber, password) == 6)
            {

                if (strcmp(email_address, input_email) == 0)
                {
                    printf("Enter new password: ");
                    scanf("%s", new_password);
                    fprintf(fptr2, "%s %s %s %s %s %s\n", firstname, lastname, email_address, username, phonenumber, new_password);
                    inside = 1;
                }
                else
                {

                    fprintf(fptr2, "%s %s %s %s %s %s\n", firstname, lastname, email_address, username, phonenumber, password);
                }
            }

            fclose(fptr2);
            fclose(fptr);

            if (inside)
            {
                remove("users.txt");
                rename("user_temp.txt", "users.txt");
                printf("Your password has been changed successfully");
            }

            else
            {
                printf("Pssword could not changed");
            }
        }
        break;
    default:
        break;
    }
}

void delete_account()
{
    FILE *fptr;
    FILE *fptr2;
    fptr = fopen("users.txt", "r");
    fptr2 = fopen("user_temp.txt", "w");
    char username[20];
    char password[20];
    char firstname[20], lastname[20], email_address[100], phonenumber[20];
    char new_password[20];
    char input_email[100];
    char del_account[1];
    printf("Do you want to delete your account(y/n): ");
    scanf("%s", del_account);
    int inside = 0;

    if (del_account[0] == 'y' || del_account[0] == 'Y')
    {
        printf("Enter your email address to verify: ");
        scanf("%s", input_email);

        while (fscanf(fptr, "%s %s %s %s %s %s", firstname, lastname, email_address, username, phonenumber, password) == 6)
        {
            if (strcmp(email_address, input_email) == 0)
            {
                inside = 1;
                continue;
            }
            else
            {
            
                fprintf(fptr2, "%s %s %s %s %s %s\n", firstname, lastname, email_address, username, phonenumber, password);
            }
        }

        fclose(fptr2);
        fclose(fptr);

        if (inside)
        {
            remove("users.txt");
            rename("user_temp.txt", "users.txt");
            printf("You account has been deleted successfully\n");
        }
        else
        {
            remove("user_temp.txt");
            printf("Account couldn't be deleted\n");
        }
    }
}

void show_data(){
    FILE *fptr;
    fptr = fopen("users.txt", "r");
    
    char username[20];
    char password[20];
    char firstname[20], lastname[20], email_address[100], phonenumber[20];
    char new_password[20];
    char input_email[100];
    char del_account[1];
    printf("Do you want to see your saved data(y/n): ");
    scanf("%s", del_account);
    int inside = 0;

    if (del_account[0] == 'y' || del_account[0] == 'Y')
    {
        printf("Enter your email address to verify: ");
        scanf("%s", input_email);

        while (fscanf(fptr, "%s %s %s %s %s %s", firstname, lastname, email_address, username, phonenumber, password) == 6)
        {
            if (strcmp(email_address, input_email) == 0)
            {
                printf("Name: %s %s\n", firstname, lastname);
                printf("Email Address: %s\n", email_address);
                printf("Username: %s\n", username);
                printf("Phone number: %s\n", phonenumber);
                printf("Password: %s\n", password);
                inside= 1;
            }
            
        }

        if (inside)
        {
            printf("Rewiew your data\n");
        }
        else
        {
            printf("Couldn't perform the operation!\n");
        }
        
        fclose(fptr);

    }

}

int main()
{
    int i = 1;
    while (i)
    {
        int choice;
        printf("1. Signup\n");
        printf("2. Login / Reset Password\n");
        printf("3. Delete Account\n");
        printf("4. Show Data\n");
        printf("Enter your choice(0 to exit): ");
        scanf("%d", &choice);
        printf("Enter any key to continue.....................");
        char cont;
        scanf(" %c", &cont);
        if (cont)
        {
            system("cls");
        }

        switch (choice)
        {

        case 1:

            FILE *fptr;
            fptr = fopen("users.txt", "r");

            if (fptr == NULL)
            {
                printf("Error opening file");
            }

            char email_address[100], username[20], firstname[20], lastname[20], password[20], phonenumber[20];

            char input_email_address[100], input_username[20], input_firstname[20], input_lastname[20], input_password[20], input_phone_number[20];

            printf("Enter your first name: ");
            scanf("%s", input_firstname);
            printf("Last name: ");
            scanf("%s", input_lastname);
            printf("Enter your email address: ");
            scanf("%s", input_email_address);
            int is_continue = 0;
            int is_exist = 0;

            while (fscanf(fptr, "%s %s %s %s %s %s", firstname, lastname, email_address, username, phonenumber, password) == 6)
            {

                if (strcmp(email_address, input_email_address) == 0)
                {
                    is_continue = 1;
                }

                if (strcmp(username, input_username) == 0)
                {
                    is_exist = 1;
                }
            }

            if (is_continue)
            {

                printf("Email has already been registered\n");
                printf("Enter any key to continue.....................");
                
                scanf(" %c", &cont);
                if (cont)
                {
                    system("cls");
                }
            }

            rewind(fptr);
            printf("Enter your username: ");
            scanf("%s", input_username);

            while (fscanf(fptr, "%s %s %s %s %s %s", firstname, lastname, email_address, username, phonenumber, password) == 6)
            {

                if (strcmp(username, input_username) == 0)
                {
                    is_exist = 1;
                }
            }

            if (is_exist)
            {
                printf("Username has already been taken\n");
                printf("Enter any key to continue.....................");
                
                scanf(" %c", &cont);
                if (cont)
                {
                    system("cls");
                }
                break;
            }

            printf("Enter your phone number: ");
            scanf("%s", input_phone_number);
            printf("Set a strong password: ");
            scanf("%s", input_password);
            signup_function(input_firstname, input_lastname, input_email_address, input_username, input_phone_number, input_password);

            printf("Enter any key to continue.....................");
            
            scanf(" %c", &cont);
            if (cont)
            {
                system("cls");
            }
            break;

        case 2:
            signin_function();
            printf("Enter any key to continue.....................");
            scanf(" %c", &cont);
            if (cont)
            {
                system("cls");
            }

            break;

        case 3:
            delete_account();
            printf("Enter any key to continue.....................");
            scanf(" %c", &cont);
            if (cont)
            {
                system("cls");
            }
            
            break;
        
        case 4:
            show_data();
            printf("Enter any key to continue.....................");
            scanf(" %c", &cont);
            if (cont)
            {
                system("cls");
            }
            break;

        case 0:
            i = 0;
            break;

        default:
            printf("Invalid input\n");
            break;
        }
    }
}
