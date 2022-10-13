#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void es()
{
    char c;
    char text[20];
    char email[20];
    printf("Digite seu email: ");
    scanf("%s", email);
    FILE *arq = fopen("LOGINS.txt", "a");
    while ((c = fgetc(arq)) != EOF)
    {
        printf("1");
        strncat(text, &c, 1);
        if (strcmp(text, email) == 0)
        {
            printf("achou!");
            break;
        }
    }
}

void call_pont(char filename[25], char content[25], int skip_line)
{
    FILE *pont_arq = fopen(filename, "a+");
    ;
    if (pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        if (skip_line == 1)
        {
            fprintf(pont_arq, "%s;\n", content);
            fclose(pont_arq);
        }
        else
        {
            fprintf(pont_arq, "%s;", content);
            fclose(pont_arq);
        }
    }
}

void Registro()
{

    char email[20];
    char senha[20];
    char csenha[20];
    printf("|-----------------------------------------------------------|\n");
    printf("|                        (CADASTRO)                         |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("OBS:\n* SENHA DEVE TER NO M�XIMO 20 CARACT�RES. \n");
    printf("Email: ");
    scanf("%s", &email);
    system("cls");
    printf("|-----------------------------------------------------------|\n");
    printf("|                        (CADASTRO)                         |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("OBS:\n* SENHA DEVE TER NO M�XIMO 20 CARACT�RES.\n");
    printf("Email: %s\n", email);
    printf("Senha: ");
    scanf("%s", &senha);
    printf("\nConfirma senha: ");
    scanf("%s", &csenha);
    // Fun��o para comparar as strings!
    if (strcmp(senha, csenha) == 0)
    {
        call_pont("LOGINS.txt", email, 0);
        call_pont("LOGINS.txt", senha, 1);
        printf("Cadastro feito!");
    }
    else
    {
        printf("Senha incorreta!");
    }
}
void Login()
{

    char email[20];
    char senha[20];
    printf("|-----------------------------------------------------------|\n");
    printf("|                        (LOGIN)                            |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("Email: ");
    scanf("%s", &email);
    system("cls");
    printf("|-----------------------------------------------------------|\n");
    printf("|                        (LOGIN)                            |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("Email: %s\n", email);
    printf("Senha: ");
    scanf("%s", &senha);
}

main()
{
    /*
     * INICIALIZA��O DO PONTEIRO / ARQUIVO
     */

    setlocale(LC_ALL, "");
    int login = 0, x = 0;
    while (x == 0)
    {
        printf("|-----------------------------------------------------------|\n");
        printf("|                        (LOGIN)                            |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("|                                                           |\n");
        printf("|                (1) - Login                                |\n");
        printf("|                (2) - Cadastrar                            |\n");
        printf("|                (3) - Esqueci a senha                      |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        scanf("%i", &login);
        system("cls");

        switch (login)
        {
        case 1:
            Login();
            system("cls");
            x = 1;
            break;
        case 2:
            Registro();
            system("cls");
            break;
        case 3:
            es();
            x = 1;
            // system("cls");
            break;
        default:
            printf("N�o h� essa op��o!");
            break;
        }
    }
    return 0;
}
