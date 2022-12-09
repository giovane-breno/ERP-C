/* *******************************************************************
 * Universidade Paulista (UNIP)
 * Análise e Desenvolvimento de Sistemas - Data de Entrega: 09/12/2022
 *
 * Autores do Projeto: Allan Pereira Lopes [N843330]
 *                     Giovane Breno Pereira Barbosa [N8713B-5]
 *                     Giovana Chiquinni Primon [N9716G2]
 *                     Levi Custódio Kodaria Leão [N870230]
 *                     Matheus Felix Barbosa [G505115]
 *                     
 *                     
 * Turma: DS2R48
 * PROJETO INTEGRADO MULTIDISCIPLINAR
 * Observação:
 *
 * SOFTWARE-ERP.c
 * ******************************************************************/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "includes/forms.h"

/* DECLARAÇÃO PRÉVIA DAS FUNÇÕES VOID PARA EVITAR ERROS */
void login();
void main_menu();
void register_screen();
void query_screen();
void management_screen();
void storage_screen();
void infra_screen();
void human_register_screen();
void query_storage_screen();
void query_infra_screen();
void query_human_screen();
void query_storage_screen();
void query_infra_screen();
void query_human_screen();
void manage_data_screen();
void human_delete_data_screen();
void items_delete_data_screen();
void relatories_screen();
void admin_config_screen();

/* DECLARAÇÃO PRÉVIA DAS FUNÇÕES VOID PARA EVITAR ERROS */

int main()
{
    setlocale(LC_ALL, "Portuguese");
    login();
    return 0;
}

void login()
{
    system("cls");
    short int option = 0;

    authentication_text(1);

    while (true)
    {
        scanf("%hd", &option);
        system("cls");

        switch (option)
        {
        case 1:

            if (login_form())
            {
                wait_for_input("\nUsuario autenticado com sucesso!\n");
                main_menu();
            }
            else
            {
                wait_for_input("\nUsuario nao encontrado!\n");
                system("cls");
            }
            login(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:
            (config_file()) ? register_form() : wait_for_input("O registro de novas contas foi desativado por um administrador.\n");
            system("cls");

            login(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        default:
            system("cls");
            authentication_text(1);
            printf("* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void main_menu() /* TELA INICIAL */
{
    short int option = 0;

    system("cls");
    main_menu_text(1);
    while (true)
    {
        scanf("%hd", &option);
        system("cls");
        switch (option)
        {
        case 1:
            register_screen(); /* TELA CADASTROS */

            main_menu(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:
            query_screen(); /* TELA CONSULTAS */

            main_menu(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 3:
            management_screen(); /* TELA GERENCIAMENTO */

            main_menu(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 4:
            wait_for_input("Voce escolheu sair. Ate logo!\n");
            login(); /* RETORNA AO LOGIN */
        default:
            system("cls");
            main_menu_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void storage_screen() /* TELA INICIAL - > [1] CADASTROS - > [1] ESTOQUE */
{
    short int option = 0;

    system("cls");
    register_options_text(3);
    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* CADASTRAR CATEGORIA */
            system("cls");
            register_category_form();

            storage_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:
            system("cls");
            register_item_form(); /* CADASTRAR ITEM*/

            storage_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
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

void infra_screen() /* TELA INICIAL - > [1] CADASTROS - > [2] INFRAESTRUTURA */
{
    short int option = 0;

    system("cls");
    register_options_text(1);
    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1:
            system("cls");
            register_infra_form(); /* CADASTRAR INFORMACOES */

            infra_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:
            register_screen(); /* RETORNA A TELA DE CADASTRO */
            break;
        default:
            system("cls");
            register_options_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void human_register_screen() /* TELA INICIAL - > [1] CADASTROS - >  [3] RECURSOS HUMANOS */
{
    short int option = 0;

    system("cls");
    register_options_text(2);
    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1:
            system("cls");
            register_customer_form(); /* CADASTRAR CLIENTE */

            human_register_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:                      /* CADASTRAR FUNCIONARIO*/
            system("cls");
            register_work_form();

            human_register_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 3:                      /* CADASTRAR PERFIL */
            system("cls");
            register_profile_form();

            human_register_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 4:
            register_screen(); /* RETORNA A TELA DE CADASTROS */
            break;
        default:
            system("cls");
            register_options_text(2);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void register_screen() /* TELA INICIAL - > [1] CADASTROS */
{
    short int option = 0;

    system("cls");
    main_menu_text(2);
    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* ESTOQUE */
            storage_screen();
            system("cls");

            register_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:
            infra_screen(); /* INFRAESTRUTURA */
            system("cls");

            register_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 3:
            human_register_screen(); /* RECURSOS HUMANOS */
            system("cls");

            register_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
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

void query_screen() /* TELA INICIAL - > [2] CONSULTAR */
{
    system("cls");
    main_menu_text(3);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* ESTOQUE */
            query_storage_screen();
            system("cls");

            query_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:             /* INFRAESTRUTURA */
            query_infra_screen();
            system("cls");

            query_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 3:             /* RECURSOS HUMANOS */
            query_human_screen();
            system("cls");

            query_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 4:
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

void query_storage_screen() /* TELA INICIAL - > [2] CONSULTAR - >  [1] ESTOQUE */
{
    system("cls");
    query_human_text(3);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* VISUALIZAR INFRAESTRUTURA */
            system("cls");
            show_storage_form();

            query_storage_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:
            system("cls");
            query_screen(); /* VOLTAR */
            break;
        default:
            system("cls");
            query_human_text(3);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void query_infra_screen() /* TELA INICIAL - > [2] CONSULTAR - >  [2] INFRAESTRUTURA */
{
    system("cls");
    query_human_text(2);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* VISUALIZAR INFRAESTRUTURA */
            system("cls");
            show_infra_form();

            query_infra_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:
            system("cls");
            query_screen(); /* VOLTAR */
            break;
        default:
            system("cls");
            query_human_text(2);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void query_human_screen() /* TELA INICIAL - > [2] CONSULTAR - >  [3] RECURSOS HUMANOS */
{
    system("cls");
    query_human_text(1);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* CONSULTAR CLIENTES*/
            system("cls");
            query_customers("files\\customers.txt");

            query_human_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:                   /* CONSULTAR FUNCIONARIOS*/
            system("cls");
            query_workers("files\\workers.txt");

            query_human_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 3:                   /* CONSULTAR PERFIS*/
            query_profile("files\\profiles.txt");

            query_human_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 4:                   /* CONSULTAR USUARIOS */
            system("cls");
            query_users("files\\logins.txt");

            query_human_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 5:
            query_screen(); /* RETORNA AO MENU PRINCIPAL */
            break;
        default:
            system("cls");
            query_human_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void management_screen() /* TELA INICIAL - > [3] GERENCIAMENTO */
{
    system("cls");
    main_menu_text(4);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* GERENCIAR DADOS */
            system("cls");
            manage_data_screen();

            management_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:                  /* VISUALIZAR RELATORIOS */
            system("cls");
            relatories_screen();

            management_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 3:                  /* CONFIG ADMINISTRATIVAS */
            system("cls");
            admin_config_screen();

            management_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 4:
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

void manage_data_screen() /* TELA INICIAL - > [3] GERENCIAMENTO - > [1] EDITAR DADOS */
{

    system("cls");
    edit_data_text(2);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* ITENS */
            system("cls");
            items_delete_data_screen();

            manage_data_screen();
            break;
        case 2: /* RECURSOS HUMANOS */
            system("cls");
            human_delete_data_screen();

            manage_data_screen();
        case 3:
            management_screen(); /* RETORNA A TELA DE GERENCIAMENTO */
            break;
        default:
            system("cls");
            edit_data_text(2);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void items_delete_data_screen() /* TELA INICIAL - > [3] GERENCIAMENTO - > [1] EDITAR DADOS -> [1] ITEMS */
{
    system("cls");
    edit_data_text(3);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* ITENS */
            system("cls");
            delete_items_form();

            items_delete_data_screen();
            break;
        case 2: /* CATEGORIAS */
            system("cls");
            delete_categories_form();

            items_delete_data_screen();
        case 3:
            manage_data_screen(); /* RETORNA A TELA DE GERENCIAMENTO */
            break;
        default:
            system("cls");
            edit_data_text(3);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void human_delete_data_screen() /* TELA INICIAL - > [3] GERENCIAMENTO - > [1] EDITAR DADOS -> [1] RECURSOS HUMANOS */
{

    system("cls");
    edit_data_text(1);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* FUNCIONARIOS */
            system("cls");
            delete_workers_form();

            human_delete_data_screen();
            break;
        case 2: /* CLIENTES */
            system("cls");
            delete_customer_form();

            human_delete_data_screen();
        case 3: /* PERFIS DE USUARIOS */
            system("cls");
            delete_profiles_form();

            human_delete_data_screen();
            break;
        case 4: /* USUARIOS */
            system("cls");
            delete_users_form();

            human_delete_data_screen();
        case 5:
            manage_data_screen(); /* RETORNA A TELA DE GERENCIAMENTO */
            break;
        default:
            system("cls");
            edit_data_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void relatories_screen() /* TELA INICIAL - > [3] GERENCIAMENTO - > [2] VISUALIZAR RELATÓRIOS */
{
    system("cls");
    relatories_text(1);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* Relatório CAPEX */
            system("cls");
            relatory_capex();

            relatories_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:                  /* Relatório OPEX  */
            system("cls");
            relatory_opex();

            relatories_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 3:                  /* Relatório CAPEX & OPEX */
            system("cls");
            relatory_capex_opex();

            relatories_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 4:
            management_screen(); /* Voltar */
            break;
        default:
            system("cls");
            relatories_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}

void admin_config_screen() /* TELA INICIAL - > [3] GERENCIAMENTO - > [3] CONFIGURAÇÕES ADMINISTRATIVAS */
{
    system("cls");
    admin_config_text(1);

    short int option = 0;

    while (true)
    {
        scanf("%hd", &option);
        switch (option)
        {
        case 1: /* ATIVAR / DESATIVAR REGISTRO */
            system("cls");
            check_register_status();

            admin_config_screen(); /* RECURSIVIDADE - CHAMANDO A PROPRIA FUNCAO PARA RECUPERAR O LACO DE REPETIÇÃO*/
        case 2:
            management_screen(); /* RETORNA AO MENU PRINCIPAL */
            break;
        default:
            system("cls");
            admin_config_text(1);
            printf("OBS:\n* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }
}