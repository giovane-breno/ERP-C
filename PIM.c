/* *******************************************************************
 * Universidade Paulista (UNIP)
 * Análise e Desevolvimento de Sistemas - Data de Entrega:
 *
 * Autores do Projeto: Giovane Breno Pereira Barbosa
 *                     Levi Custódio Kodaria Leão
 *                     Matheus Felix Barbosa
 *                     Allan Pereira Lopes
 *                     Giovana Chiquinni Primon
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
            (config_file()) ? register_form() : wait_for_input("O registro de novas contas foi desativado por um administrador.\n");
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
            management_screen();
            end_loop = 1;
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

void register_screen() /* [2] CADASTRAR */
{
    int option = 0;
    int end_loop = 0;

    system("cls");
    main_menu_text(2);
    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* CADASTRAR CLIENTE */
            system("cls");
            register_customer_form();
            break;
        case 2: /* CADASTRAR FUNCIONARIO*/
            system("cls");
            register_work_form();
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

void query_screen() /* [1] CONSULTAR */
{
    system("cls");
    main_menu_text(3);

    int option = 0;
    int end_loop = 0;

    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* CONSULTAR CLIENTES*/
            system("cls");
            query_customers("files\\customers.txt");
            break;
        case 2: /* CONSULTAR FUNCIONARIOS*/
            break;
        case 3: /* CONSULTAR PERFIS*/
            break;
        case 4: /* CONSULTAR USUARIOS */
            system("cls");
            query_users("files\\logins.txt");
            break;
        case 5:
            main_menu(); /* RETORNA AO MENU PRINCIPAL */
            break;
        default:
            system("cls");
            main_menu_text(3);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void management_screen() /* [3] GERENCIAMENTO */
{
    system("cls");
    main_menu_text(4);

    int option = 0;
    int end_loop = 0;

    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* GERENCIAR DADOS */
            system("cls");
            edit_data_screen();
            break;
        case 2: /* VISUALIZAR RELATORIOS */
            system("cls");
            relatories_screen();
            break;
        case 3: /* CONFIG ADMINISTRATIVAS */
            system("cls");
            admin_config_screen();
            break;
        case 4: /* OUTROS */
            system("cls");
            break;
        case 5:
            main_menu(); /* RETORNA AO MENU PRINCIPAL */
            break;
        default:
            system("cls");
            main_menu_text(4);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void edit_data_screen() /* [1] EDITAR DADOS */
{

    system("cls");
    edit_data_text(1);

    int option = 0;
    int end_loop = 0;

    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* FUNCIONARIOS */
            system("cls");
            break;
        case 2: /* CLIENTES */
            system("cls");

            break;
        case 3: /* PERFIS DE USUARIOS */
            system("cls");

            break;
        case 4: /* RETORNA AO MENU PRINCIPAL */
            management_screen();
            break;
        default:
            system("cls");
            edit_data_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void admin_config_screen()
{
    system("cls");
    admin_config_text(1);

    int option = 0;
    int end_loop = 0;

    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* ATIVAR / DESATIVAR REGISTRO */
            system("cls");
            check_register_status();
            admin_config_text(1);
            break;
        case 2: /* CLIENTES */
            system("cls");

            break;
        case 3: /* PERFIS DE USUARIOS */
            system("cls");

            break;
        case 4: /* RETORNA AO MENU PRINCIPAL */
            management_screen();
            break;
        default:
            system("cls");
            admin_config_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void relatories_screen()
{
    system("cls");
    relatories_text(1);

    int option = 0;
    int end_loop = 0;

    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* Relatório CAPEX */
            system("cls");
            relatory_capex();

            break;
        case 2: /* Relatório OPEX  */
            system("cls");
            relatory_opex();
            
            break;
        case 3: /* Relatório CAPEX & OPEX */
            system("cls");
            relatory_capex_opex();
        
            break;
        case 4: /* Voltar */
            management_screen();
            break;
        default:
            system("cls");
            relatories_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}