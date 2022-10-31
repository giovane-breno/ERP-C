#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#include "authentication.h"
#include "text_handler.h"
#include "others.h"

void register_form()
{
    char email[256];
    char senha[20];
    char csenha[20];

    authentication_text(2);

    printf("\nEmail: ");
    scanf("%s", email);
    while (1)
    {
        printf("Senha: ");
        scanf("%s", senha);
        printf("Confirmar senha: ");
        scanf("%s", csenha);

        /* Funcao para comparar as strings! */
        if (strcmp(senha, csenha) == 0)
        {
            register_account(email, senha) ? puts("\nCadastro feito com sucesso!") : puts("\nHouve um erro no cadastro!");
            puts("Pressione qualquer tecla para continuar...");
            getch();
            break;
        }
        else
        {
            printf("\n Senha incorreta!");
            system("cls");
            authentication_text(2);
            printf("* CONFIRMACAO INCORRETA, DIGITE A SENHA NOVAMENTE.\n\n");
        }
    }
}

int login_form()
{
    char email[256];
    char senha[20];
    int status = 0;

    authentication_text(3);

    printf("Email: ");
    scanf("%s", email);
    printf("Senha: ");
    scanf("%s", senha);

    status = login_account(email, senha) ? 1 : 0;

    return status;
}

void query_users(char filename[128])
{
    printf("USUARIO | SENHA\n\n");
    query_users_files(filename);
    wait_for_input("\nLista de usuarios impressa com sucesso!\n");
    system("cls");
    main_menu_text(3); /* RETORNA AO MENU APÓS CLIQUE */
}