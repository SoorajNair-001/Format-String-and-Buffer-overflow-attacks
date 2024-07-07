#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void passCheck(char *pass, char *cmd) {
    char actualpass[50];
    char command[1000];
    char canary[10];
    char password[50];
    strcpy(actualpass,"myPass");
    strcpy(command, cmd);
    strcpy(canary,"1234");
    strcpy(password, pass);
    
    if (strcmp(canary,"1234")==0){
        if (strcmp(password, actualpass) == 0) {
            printf("Login successful!");
        } else {
            printf("Login failed!");
        }
        printf("\n\nServer side logs:\n");
        printf("Login attempt at ");
        fflush(stdout);
        system(command);
    }else {printf("Buffer overflow detected");};
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
        printf("%s",username);
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
    printf("\n");
    return 0;
}
