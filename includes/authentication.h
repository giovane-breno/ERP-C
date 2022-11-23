#include "file_handler.h"
#include "secure.h"

/**
 * Concatena o email e senha.
 *
 * @param email deve ser uma string.
 * @param password deve ser uma string.
 * 
 * @return Chama a função de criação de arquivo com a variavel concatenada.
 */
bool register_account(char email[256], char password[256])
{
    char user_account[256] = "";
    sprintf(user_account, "%s %s", email, encrypt(password));
    fflush(stdin);
    create_file("files\\logins.txt", user_account, "a");

    return true;
}

/**
 * Concatena o email e senha.
 *
 * @param email deve ser uma string.
 * @param password deve ser uma string.
 * 
 * @return Chama a função de leitura de arquivo com a variavel concatenada.
 */
int login_account(char email[256], char password[256]){
    char user_account[256] = "";
    sprintf(user_account, "%s %s", email, encrypt(password));
    fflush(stdin);
    return read_file("files\\logins.txt", user_account);
}