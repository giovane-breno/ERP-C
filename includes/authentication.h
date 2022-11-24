#include "file_handler.h"
#include "secure.h"

/**
 * Concatena o email e senha.
 *
 * @param email deve ser uma string.
 * @param password deve ser uma string.
 *
 * @return Adiciona o registro no final do arquivo logins.txt
 */
bool register_account(char *email, char *password)
{
    bool status = false;
    FILE *fp = fopen("files\\logins.txt", "a");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        remove_whitespace(email);
        remove_whitespace(password);

        fprintf(fp, "%s %s\n", email, encrypt(password));
        status = true;
    }
    fclose(fp);

    return status;
}

/**
 * Compara o email e senha digitada por um usuario com os do arquivo de dados criptografados.
 *
 * @param email deve ser uma string.
 * @param password deve ser uma string.
 *
 * @return Faz a leitura do arquivo e compara os dados enviados..
 */
bool login_account(char *email, char *password)
{
    char *temp_email = malloc(sizeof(char) * MAX_EMAIL_LENGHT);
    char *temp_password = malloc(sizeof(char) * MAX_PASSWORD_LENGHT);

    FILE *fp = fopen("files\\logins.txt", "r");

    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {

        while (fscanf(fp, "%s %s", temp_email, temp_password) == 2)
        {
            if ((strcmp(temp_email, email) == 0) && (strcmp(temp_password, password) == 0))
            {
                free(temp_email);
                free(temp_password);
                return true;
            }
        }
    }

    free(temp_email);
    free(temp_password);
    return false;
}