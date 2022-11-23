/* *******************************************************************
 * Universidade Paulista (UNIP)
 * Análise e Desevolvimento de Sistemas - Data de Entrega:
 *
 * Autores do Projeto: Giovane Breno Pereira Barbosa [N8713B-5]
 *                     Levi Custódio Kodaria Leão
 *                     Matheus Felix Barbosa
 *                     Allan Pereira Lopes
 *                     Giovana Chiquinni Primon
 * Turma: DS2R48
 * PROJETO INTEGRADO MULTIDISCIPLINAR
 * Observação: <colocar se houver>
 *
 * PIM.c
 * ******************************************************************/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    login();
    return 0;
}

#include "includes/forms.h"

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

void register_screen() /* [2] CADASTROS */
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
        case 1: /* ESTOQUE */
            storage_screen();
            system("cls");
            break;
        case 2: /* INFRAESTRUTURA */
            infra_screen();
            system("cls");
            break;
        case 3: /* RECURSOS HUMANOS */
            human_register_screen();
            system("cls");
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

void infra_screen()
{
    int option = 0;
    int end_loop = 0;

    system("cls");
    register_options_text(1);
    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* CADASTRAR INFORMACOES */
            system("cls");
            register_infra_form();
            break;
        case 2:                /* VOLTAR */
            register_screen(); /* RETORNA AO MENU PRINCIPAL */
            break;
        default:
            system("cls");
            main_menu_text(2);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void human_register_screen() /* [2] RECURSOS HUMANOS */
{
    int option = 0;
    int end_loop = 0;

    system("cls");
    register_options_text(2);
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
            system("cls");
            register_profile_form();
            break;
        case 4:
            register_screen(); /* RETORNA AO MENU PRINCIPAL */
            break;
        default:
            system("cls");
            main_menu_text(2);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void storage_screen() /* [1] ESTOQUE */
{
    int option = 0;
    int end_loop = 0;

    system("cls");
    register_options_text(3);
    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* CADASTRAR CATEGORIA */
            system("cls");
            register_category_form();
            break;
        case 2: /* CADASTRAR ITEM*/
            system("cls");
            register_item_form();
            break;
        case 3:
            register_screen(); /* RETORNA AO MENU PRINCIPAL */
            break;
        default:
            system("cls");
            main_menu_text(2);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void query_screen() /* [2] CONSULTAR */
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
        case 1: /* ESTOQUE */
            query_storage_screen();
            system("cls");
            break;
        case 2: /* INFRAESTRUTURA */
            query_infra_screen();
            system("cls");

            break;
        case 3: /* RECURSOS HUMANOS */
            query_human_screen();
            system("cls");

            break;
        case 4:          /* VOLTAR */
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

void query_storage_screen()
{
    system("cls");
    query_human_text(3);

    int option = 0;
    int end_loop = 0;

    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* VISUALIZAR INFRAESTRUTURA */
            show_storage_form();
            system("cls");
            break;
        case 2: /* VOLTAR */
            query_screen();
            system("cls");
            break;
        default:
            system("cls");
            query_human_text(3);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void query_infra_screen()
{
    system("cls");
    query_human_text(2);

    int option = 0;
    int end_loop = 0;

    while (!end_loop)
    {
        scanf("%i", &option);
        switch (option)
        {
        case 1: /* VISUALIZAR INFRAESTRUTURA */
            system("cls");
            show_infra_form();
            break;
        case 2: /* VOLTAR */
            query_screen();
            system("cls");
            break;
        default:
            system("cls");
            query_human_text(2);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void query_human_screen() /* [2] CONSULTAR */
{
    system("cls");
    query_human_text(1);

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
            system("cls");
            query_workers("files\\workers.txt");
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
            query_human_text(1);
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

void admin_config_screen() /* CONFIGURAÇÕES ADMINISTRATIVAS */
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