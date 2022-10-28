#include "file_handler.h"

int register_account(char email[256], char password[256])
{
    char user_account[256] = "";
    strcat(email, "|");
    strcat(email, password);
    strcat(user_account, email);
    fflush(stdin);
    create_file("LOGINS.txt", user_account);

    return 1;
}

int login_account(char email[256], char password[256]){
    char user_account[256] = "";
    strcat(email, "|");
    strcat(email, password);
    strcat(email, ";");
    strcat(user_account, email);
    fflush(stdin);
    read_file("LOGINS.txt", user_account);
    
    return 1;
}