#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int verified = 0;
void passCheck(char *pass, char *cmd) {
    char actualpass[50];
    char command[1000];
    char password[50];
    strcpy(actualpass,"myPass"); // could be encrypted
    strcpy(command, cmd);
    strcpy(password, pass);
    if (strcmp(password, actualpass) == 0) {
        printf("Login successful!");
        verified = 1;
    } else {
        printf("Login failed!");
    }
    printf("\n\nServer side logs:\n");
    printf("Login attempt at ");
    fflush(stdout);
    system(command);
}

int userCheck(char *user) {
    int userFound = 0;
    char actualuser[50];
    char username[50];
    strcpy(actualuser,"admin");
    strcpy(username, user);
    if (strcmp(username, actualuser) == 0) {
        userFound = 1;
    }
    else{
        printf("User not found! Try again ");
        printf(username);
    }
    return userFound;
}


int main(int argc, char *argv[]){
    char username[200];
    char password[200];
    printf("Username: ");
    scanf("%s", username);
    int userfound = userCheck(username);
    if (userfound == 1){
        printf("Password: ");
        scanf("%s", password);
        passCheck(password, "date");
    }
    if(verified ==1){
        // Allow access to the user
    }
    printf("\n");
    return 0;
}
