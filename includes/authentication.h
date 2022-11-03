#include "file_handler.h"

int register_account(char email[256], char password[256])
{
    char user_account[256] = "";
    sprintf(user_account, "%s|%s", email, password);
    fflush(stdin);
    create_file("files\\logins.txt", user_account);

    return 1;
}

int login_account(char email[256], char password[256]){
    char user_account[256] = "";
    sprintf(user_account, "%s|%s", email, password);
    fflush(stdin);
    return read_file("files\\logins.txt", user_account);
}