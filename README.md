#**C Login & Account Management System**#

A console-based user authentication system written in C language that allows users to sign up, sign in, reset forgotten passwords, and delete accounts using file handling.

This project demonstrates core C concepts such as:

File handling (fopen, fscanf, fprintf)

String manipulation

**Conditional logic**

Temporary file usage for safe updates

**Features**

User Signup

User Login (Username + Password)

Forgot Password (Email Verification)

Reset Password

Delete Account

Persistent storage using text files

**Technologies Used**

Language: C

Compiler: GCC / MinGW

Platform: Windows (uses system("cls"))

Data Storage Format

User data is stored in users.txt in space-separated format:

FirstName LastName Email Username PhoneNumber Password
**
Example:**

Ali Khan ali@gmail.com ali123 03001234567 pass123


Note: Although the file is named .txt, it is not a real CSV.

How to Compile and Run

**Compile**

gcc main.c -o login_system

Run

./login_system

In vscode if you have installed and configured c/c++ compiler then press ctrl+alt+n to run

Program Menu

1. Signup
   
2. Login
   
3. Forgot Password
 
4. Delete Account
 
0. Exit

Password Reset Logic (Important)

User enters registered email

Email is verified by scanning the file

Password is updated using a temporary file

Old file is replaced with the updated file

This approach ensures safe file modification.
