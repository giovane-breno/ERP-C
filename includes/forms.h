#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "authentication.h"
#include "text_handler.h"

void register_form()
{
    char email[20];
    char senha[20];
    char csenha[20];

    return_text(2);

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
            return_text(2);
            printf("* CONFIRMACAO INCORRETA, DIGITE A SENHA NOVAMENTE.\n\n");
        }
    }
}

void login_form()
{
    char email[20];
    char senha[20];

    printf("Email: ");
    scanf("%s", email);
    printf("\nSenha: ");
    scanf("%s", senha);
}