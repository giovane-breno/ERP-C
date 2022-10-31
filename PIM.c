/* *******************************************************************
 * Universidade Paulista (UNIP)
 * Análise e Desevolvimento de Sistemas - Data de Entrega:
 *
 * Autores do Projeto: Giovane Breno Pereira Barbosa
 *                     Levi Custódio Kodaria Leão
 *                     Matheus
 *                     Allan
 *                     Giovana
 * Turma: DS2R48
 * PROJETO INTEGRADO INTERDISCIPLINAR
 * Observação: <colocar se houver>
 *
 * PIM.c
 * ******************************************************************/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "includes/forms.h"

int main()
{

    setlocale(LC_ALL, "Portuguese");
    login();

    return 0;
}

void login()
{
    system("cls");
    int option = 0;
    int end_loop = 0;

    authentication_text(1);

    while (!end_loop)
    {
        scanf("%i", &option);
        system("cls");

        switch (option)
        {
        case 1:

            if (login_form())
            {
                wait_for_input("\nUsuario autenticado com sucesso!\n");
                end_loop = 1;
                main_menu();
            }
            else
            {
                wait_for_input("\nUsuario nao encontrado!\n");

                system("cls");
                authentication_text(1);
            }

            break;
        case 2:
            register_form();
            system("cls");
            authentication_text(1);
            break;
        default:
            system("cls");
            authentication_text(1);
            printf("* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void main_menu()
{
    int option = 0;
    int end_loop = 0;

    system("cls");
    main_menu_text(1);
    while (!end_loop)
    {
        scanf("%i", &option);
        system("cls");
        switch (option)
        {
        case 1: /* TELA CADASTROS */
            register_screen();
            end_loop = 1;
            break;
        case 2: /* TELA CONSULTAS */
            query_screen();
            end_loop = 1;
            break;
        case 3: /* TELA GERENCIAMENTO */
            break;
        case 4: /* VOLTAR*/
            wait_for_input("Voce escolheu sair. Ate logo!\n");
            login();
        default:
            system("cls");
            main_menu_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void register_screen()
{
    int option = 0;
    int end_loop = 0;

    main_menu_text(2);
    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* CADASTRAR CLIENTE */
            break;
        case 2: /* CADASTRAR FUNCIONARIO*/
            break;
        case 3: /* CADASTRAR PERFIL */
            break;
        case 4:
            main_menu(); /* RETORNA AO MENU PRINCIPAL */
            break;
        default:
            system("cls");
            main_menu_text(2);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void query_screen()
{
    main_menu_text(3);

    int option = 0;
    int end_loop = 0;

    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* CONSULTAR CLIENTES*/
            break;
        case 2: /* CONSULTAR FUNCIONARIOS*/
            break;
        case 3: /* CONSULTAR PERFIS*/
            break;
        case 4: /* CONSULTAR USUARIOS */
            system("cls");
            query_users("LOGINS.txt");
            break;
        case 5:
            main_menu(); /* RETORNA AO MENU PRINCIPAL */
            break;
        default:
            system("cls");
            main_menu_text(2);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}