#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct Users
{
    char email[256];
    char password[20];
};

struct Workers
{
    char name[256];
    char role[256];
    float payment;
};

struct Customers
{
    char name[256];
    char cpf[22];
    char cep[16];
    int gender; /* M = 1 | F = 2*/
    int age;
};

struct Profiles
{
    int customer_id;              /* ID DO CLIENTE */
    int domestic_or_commercial;   /* PARA USO DOMÉSTICO[1] OU COMERCIAL[2] */
    int pickup_or_delivery;       /* PARA RETIRAR NA LOJA[1] OU ENTREGA[2] */
    char reason_of_buying[256];   /* MOTIVO DE COMPRA */
    char point_of_relevancy[256]; /* PONTO DE RELEVANCIA PARA ENCOMENDA, CARACTERISCAS PARA COMPRAR*/
    int active;                   /* USUARIO ATIVO OU NAO */
};

struct Infrastructure
{
    char rent_adress[256];
    float rent_price;

    char water_sender[256];
    float water_value;

    char energy_sender[256];
    float energy_value;

    char cleaning_sender[256];
    float cleaning_value;

    char net_sender[256];
    float net_value;

    float tax;
    float total_value;
};

struct Storage
{
    int category;
    char brand[256];
    char model[256];
    char supplier[256];

    int amount;
    float price;
};

#include "relatories.h"
#include "authentication.h"
#include "text_handler.h"
#include "others.h"

void register_profile_form()
{
    struct Profiles profile;
    char profile_data[468];
    int answer;
    int status = 0;
    int correct_data;

    while (true)
    {

        system("cls");
        fflush(stdin);
        register_profile_text(1);
        puts("\nImprimir lista de clientes?\n [1] - Sim | [2] - Nao");
        scanf("%d", &answer);

        if (answer == 1)
        {
            system("cls");
            query_c_files("files\\customers.txt", 1);

            wait_for_input("\nLista de clientes impressa com sucesso!\n");
        }

        system("cls");
        fflush(stdin);
        register_profile_text(1);
        printf("\nID do Cliente: ");
        scanf("%d", &profile.customer_id);

        do
        {
            system("cls");
            fflush(stdin);
            register_profile_text(1);
            puts("\nO Cliente faz encomendas para uso particular ou comercial?\n[1] - PARTICULAR | [2] - COMERCIAL");
            scanf("%d", &profile.domestic_or_commercial);
            if (profile.domestic_or_commercial == 1 || profile.domestic_or_commercial == 2)
                break;
        } while (true);

        do
        {
            system("cls");
            fflush(stdin);
            register_profile_text(1);
            puts("\nO Cliente faz encomendas para entregar ou retirar no local?\n[1] - ENTREGAR | [2] - RETIRAR NO LOCAL");
            scanf("%d", &profile.pickup_or_delivery);
            if (profile.pickup_or_delivery == 1 || profile.pickup_or_delivery == 2)
                break;
        } while (true);

        system("cls");
        fflush(stdin);
        register_profile_text(1);
        puts("\nO Cliente tem algum motivo especifico para comprar na empresa?");
        gets(profile.reason_of_buying);
        remove_whitespace(profile.reason_of_buying);

        do
        {
            system("cls");
            fflush(stdin);
            register_profile_text(1);
            puts("\nO Cliente ainda frequenta?\n[1] - ATIVO | [2] - INATIVO");
            scanf("%d", &profile.active);
            if (profile.active == 1 || profile.active == 2)
                break;
        } while (true);

        do
        {
            system("cls");
            register_profile_text(1);
            puts("\nConfirme se os dados abaixo estao corretos:");
            printf("\nID do Cliente: %d", profile.customer_id);
            printf("\nTipo de Encomenda: ");
            (profile.domestic_or_commercial == 1) ? printf("Particular") : printf("Comercial");
            printf("\nMetodo de Entrega: ");
            (profile.pickup_or_delivery == 1) ? printf("Entregar") : printf("Retirar no Local");
            printf("\nMotivo de Compra: %s", profile.reason_of_buying);
            printf("\nCliente Ativo? ");
            (profile.active == 1) ? printf("Sim") : printf("Nao");
            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao");
            scanf("%d", &correct_data);

            if (correct_data == 1 || correct_data == 2)
                break;
        } while (true);

        if (correct_data == 1)
            break;
    }

    sprintf(profile_data, "%d %d %d %s %d", profile.customer_id, profile.domestic_or_commercial, profile.pickup_or_delivery, profile.reason_of_buying, profile.active);
    system("cls");
    status = create_file("files\\profiles.txt", profile_data, 'a');

    if (status)
    {
        wait_for_input("\nPerfil de Cliente cadastrado com sucesso!\n");
    }
    else
    {
        wait_for_input("\n");
    }

    register_screen();
}

void register_form()
{
    struct Users user;
    char cpass[256]; /* CONFIRM PASSWORD */

    authentication_text(2);

    printf("\nEmail: ");
    scanf("%s", user.email);
    while (1)
    {
        printf("Senha: ");
        scanf("%s", user.password);
        printf("Confirmar senha: ");
        scanf("%s", cpass);

        /* Funcao para comparar as strings! */
        if (strcmp(cpass, user.password) == 0)
        {
            register_account(user.email, user.password) ? puts("\nCadastro feito com sucesso!") : puts("\nHouve um erro no cadastro!");
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
    struct Users user;
    int status = 0;

    authentication_text(3);

    printf("Email: ");
    scanf("%s", user.email);
    printf("Senha: ");
    scanf("%s", user.password);

    status = login_account(user.email, user.password) ? 1 : 0;

    return status;
}

void query_users(char filename[128])
{
    query_users_files(filename);
    wait_for_input("\nLista de usuarios impressa com sucesso!\n");
    system("cls");
    main_menu_text(2); /* RETORNA AO MENU APÓS CLIQUE */
}

void query_customers(char filename[128])
{
    query_c_files(filename, 0);
    wait_for_input("\nLista de clientes impressa com sucesso!\n");
    system("cls");
    main_menu_text(2); /* RETORNA AO MENU APÓS CLIQUE */
}

void query_workers(char filename[128])
{
    query_w_files(filename);
    wait_for_input("\nLista de funcionarios impressa com sucesso!\n");
    system("cls");
    main_menu_text(2); /* RETORNA AO MENU APÓS CLIQUE */
}

void register_work_form()
{
    struct Workers worker;
    char worker_data[256];

    int correct_data;
    int status;

    while (true)
    {
        system("cls");
        fflush(stdin);
        register_work_text(1);
        printf("\nNome: ");
        gets(worker.name);
        remove_whitespace(worker.name);

        system("cls");
        register_work_text(1);
        printf("\nCargo: ");
        gets(worker.role);
        remove_whitespace(worker.role);

        system("cls");
        register_work_text(1);
        printf("\nSalario: ");
        scanf("%f", &worker.payment);

        fflush(stdin);

        system("cls");
        register_work_text(1);
        puts("\nConfirme se os dados abaixo estao corretos:");
        printf("\nNome: %s", worker.name);
        printf("\nCargo: %s", worker.role);
        printf("\nSalario: R$%.2f", worker.payment);
        puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
        scanf("%d", &correct_data);

        if (correct_data == 1)
            break;
    }

    sprintf(worker_data, "%s %s %.2f", worker.name, worker.role, worker.payment);
    system("cls");
    status = create_file("files\\workers.txt", worker_data, 'a');

    if (status)
    {
        wait_for_input("\nFuncionario cadastrado com sucesso!\n");
    }
    else
    {
        wait_for_input("\n");
    }

    register_screen();
}

void register_infra_form()
{
    struct Infrastructure infrastructure;
    char infra_data[256];

    int status = 0;
    int correct_data;

    while (true)
    {
        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* ALUGUEL ");
        printf("Endereco: ");
        gets(infrastructure.rent_adress);
        remove_whitespace(infrastructure.rent_adress);
        printf("Valor: R$ ");
        scanf("%f", &infrastructure.rent_price);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* AGUA E SANEAMENTO ");
        printf("Distribuidora: ");
        gets(infrastructure.water_sender);
        remove_whitespace(infrastructure.water_sender);
        printf("Valor: R$ ");
        scanf("%f", &infrastructure.water_value);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* DISTRIBUICAO DE ENERGIA ");
        printf("Distribuidora: ");
        gets(infrastructure.energy_sender);
        remove_whitespace(infrastructure.energy_sender);
        printf("Valor: R$ ");
        scanf("%f", &infrastructure.energy_value);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* SERVICO DE LIMPEZA ");
        printf("Distribuidora: ");
        gets(infrastructure.cleaning_sender);
        remove_whitespace(infrastructure.cleaning_sender);
        printf("Valor: R$ ");
        scanf("%f", &infrastructure.cleaning_value);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* SERVICO DE INTERNET ");
        printf("Distribuidora: ");
        gets(infrastructure.net_sender);
        remove_whitespace(infrastructure.net_sender);
        printf("Valor: R$ ");
        scanf("%f", &infrastructure.net_value);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* TAXAS ");
        printf("Imposto: ");
        scanf("%f", &infrastructure.tax);

        infrastructure.total_value = infrastructure.rent_price + infrastructure.water_value + infrastructure.energy_value + infrastructure.cleaning_value + infrastructure.net_value + infrastructure.tax;
        add_whitespace(infrastructure.rent_adress);
        add_whitespace(infrastructure.water_sender);
        add_whitespace(infrastructure.energy_sender);
        add_whitespace(infrastructure.cleaning_sender);
        add_whitespace(infrastructure.net_sender);

        do
        {
            system("cls");
            infra_text(1);
            puts("\nConfirme se os dados abaixo estao corretos:");
            puts("\n* ALUGUEL");
            printf("Endereco: %s", infrastructure.rent_adress);
            printf("\nValor: R$%0.2f", infrastructure.rent_price);

            puts("\n\n* AGUA E SANEAMENTO");
            printf("Distribuidora: %s", infrastructure.water_sender);
            printf("\nValor: R$%0.2f", infrastructure.water_value);

            puts("\n\n* DISTRIBUICAO DE ENERGIA");
            printf("Distribuidora: %s", infrastructure.energy_sender);
            printf("\nValor: R$%0.2f", infrastructure.energy_value);

            puts("\n\n* SERVICO DE LIMPEZA");
            printf("Distribuidora: %s", infrastructure.cleaning_sender);
            printf("\nValor: R$%0.2f", infrastructure.cleaning_value);

            puts("\n\n* SERVICO DE INTERNET");
            printf("Distribuidora: %s", infrastructure.net_sender);
            printf("\nValor: R$%0.2f", infrastructure.net_value);

            puts("\n\n* TAXAS");
            printf("Imposto: %0.2f\n", infrastructure.tax);
            printf("Valor Total: %0.2f", infrastructure.total_value);

            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
            scanf("%d", &correct_data);

            if (correct_data == 1 || correct_data == 2)
                break;
        } while (true);

        if (correct_data == 1)
            break;
    }

    remove_whitespace(infrastructure.rent_adress);
    remove_whitespace(infrastructure.water_sender);
    remove_whitespace(infrastructure.energy_sender);
    remove_whitespace(infrastructure.cleaning_sender);
    remove_whitespace(infrastructure.net_sender);

    sprintf(infra_data, "%s %0.2f\n%s %0.2f\n%s %0.2f\n%s %0.2f\n%s %0.2f\n%0.2f\n%0.2f", infrastructure.rent_adress, infrastructure.rent_price, infrastructure.water_sender, infrastructure.water_value, infrastructure.energy_sender, infrastructure.energy_value, infrastructure.cleaning_sender, infrastructure.cleaning_value, infrastructure.net_sender, infrastructure.net_value, infrastructure.tax, infrastructure.total_value);
    system("cls");
    status = create_file("files\\infrastructure.txt", infra_data, "w+");

    if (status)
    {
        wait_for_input("\nInfraestrutura cadastrada com sucesso!\n");
    }
    else
    {
        wait_for_input("\n");
    }

    infra_screen();
}

void show_infra_form()
{

    infra_text(2);
    query_infra_files("files\\infrastructure.txt");

    wait_for_input("\nDados de Infraestrutura impressos com sucesso!\n");
    query_infra_screen();
}

void register_customer_form()
{
    struct Customers customer;
    char customer_data[256];

    int status = 0;
    int correct_data;

    while (true)
    {
        system("cls");
        fflush(stdin);
        register_customer_text(1);
        printf("\nNome: ");
        gets(customer.name);
        remove_whitespace(customer.name);

        do
        {

            system("cls");
            fflush(stdin);
            register_customer_text(1);
            printf("\nIdade: ");
            scanf("%d", &customer.age);
            if (customer.age >= 0)
                break;

        } while (true);

        do
        {
            system("cls");
            fflush(stdin);
            register_customer_text(1);
            printf("\n[1] - MASCULINO | [2] - FEMININO\nSEXO: ");
            scanf("%d", &customer.gender);

            if (customer.gender == 1 || customer.gender == 2)
                break;

        } while (true);

        system("cls");
        fflush(stdin);
        register_customer_text(1);
        printf("\nCPF (APENAS NUMEROS): ");
        gets(customer.cpf);

        system("cls");
        fflush(stdin);
        register_customer_text(1);
        printf("\nCEP (APENAS NUMEROS): ");
        gets(customer.cep);
        do
        {
            system("cls");
            register_customer_text(1);
            puts("\nConfirme se os dados abaixo estao corretos:");
            printf("\nNome: %s", customer.name);
            printf("\nIdade: %d", customer.age);
            printf("\nSexo: ");
            (customer.gender == 1) ? printf("Masculino") : printf("Feminino");
            printf("\nCPF: %.11s", customer.cpf);
            printf("\nCEP: %.8s", customer.cep);

            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
            scanf("%d", &correct_data);

            if (correct_data == 1 || correct_data == 2)
                break;
        } while (true);

        if (correct_data == 1)
            break;
    }

    sprintf(customer_data, "%s %d %d %s %s", customer.name, customer.age, customer.gender, customer.cpf, customer.cep);
    system("cls");
    status = create_file("files\\customers.txt", customer_data, "a");

    if (status)
    {
        wait_for_input("\nCliente cadastrado com sucesso!\n");
    }
    else
    {
        wait_for_input("\n");
    }

    register_screen();
}

void register_category_form()
{
    char category[256];
    int correct_data = 0;
    int status = 0;
    while (true)
    {
        system("cls");
        fflush(stdin);
        category_text(1);
        printf("\nCategoria: ");
        gets(category);
        remove_whitespace(category);

        do
        {
            system("cls");
            category_text(1);
            puts("\nConfirme se os dados abaixo estao corretos:");
            printf("\nCategoria: %s", category);

            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
            scanf("%d", &correct_data);

            if (correct_data == 1 || correct_data == 2)
                break;
        } while (true);

        if (correct_data == 1)
            break;
    }
    system("cls");
    status = create_file("files\\categories.txt", category, "a");

    if (status)
    {
        wait_for_input("\nCategoria cadastrada com sucesso!\n");
    }
    else
    {
        wait_for_input("\n");
    }

    storage_screen();
}

void register_item_form()
{
    struct Storage item;

    char item_data[256];
    int correct_data = 0;
    int status = 0;
    int answer = 0;

    system("cls");
    fflush(stdin);
    register_profile_text(1);
    puts("\nImprimir lista de categorias?\n [1] - Sim | [2] - Nao");
    scanf("%d", &answer);

    if (answer == 1)
    {
        system("cls");
        query_cat_files("files\\categories.txt", 0);

        wait_for_input("\nCategorias impressa com sucesso!\n");
    }

    while (true)
    {
        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nID da Categoria: ");
        scanf("%d", &item.category);

        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nFornecedor: ");
        gets(item.supplier);
        remove_whitespace(item.supplier);

        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nMarca: ");
        gets(item.brand);
        remove_whitespace(item.brand);

        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nModelo: ");
        gets(item.model);
        remove_whitespace(item.model);

        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nQuantidade: ");
        scanf("%d", &item.amount);

        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nValor Unitario: ");
        scanf("%f", &item.price);

        do
        {
            system("cls");
            category_text(2);
            puts("\nConfirme se os dados abaixo estao corretos:");
            printf("\nCategoria: %s", getCategory(item.category));
            printf("\nFornecedor: %s", item.supplier);
            printf("\nMarca:  %s", item.brand);
            printf("\nModelo:  %s", item.model);
            printf("\nQuantidade:  %d", item.amount);
            printf("\nValor Unitario: R$ %0.2f", item.price);

            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
            scanf("%d", &correct_data);

            if (correct_data == 1 || correct_data == 2)
                break;
        } while (true);

        if (correct_data == 1)
            break;
    }
    system("cls");

    sprintf(item_data, "%d %s %s %s %d %0.2f", item.category, item.supplier, item.brand, item.model, item.amount, item.price);

    status = create_file("files\\items.txt", item_data, "a");
    if (status)
    {
        wait_for_input("\nCategoria cadastrada com sucesso!\n");
    }
    else
    {
        wait_for_input("\n");
    }

    storage_screen();
}

void show_storage_form()
{
    system("cls");
    category_text(3);
    query_storage_files("files\\items.txt", 0);

    wait_for_input("\nDados de Estoque impressos com sucesso!\n");
    query_storage_screen();
}

void relatory_capex()
{
    int resposta;

    relatories_text(2);

    query_storage_files("files\\items.txt", 1);

    printf("Deseja exportar o relatorio com mais informacoes? \n");
    // printf("Digite 1 para Sim, ou 2 para Nï¿½o <1/2> \n");

    printf("[1] - SIM\n");
    printf("[2] - NAO\n\n");

    scanf("%d", &resposta);

    if (resposta == 1)
    {
        system("cls");
        file_capex();
    }

    relatories_screen();
}

void relatory_opex()
{
    float payment = sum_payment();
    float services = sum_services();
    float *rent = rent_and_tax();
    int resposta = 0;
    relatories_text(3);

    printf("* SALARIOS\n");
    printf("  R$ %0.2f \n\n", payment);

    // impostos
    printf("* IMPOSTOS\n");
    printf("  R$ %0.2f \n\n", rent[1]);

    // serviços terceirizados
    printf("* SERVICOS\n");
    printf("  R$ %0.2f \n\n", services);

    // Aluguel
    printf("* ALUGUEL\n");
    printf("  R$ %0.2f \n\n", rent[0]);

    // Total OPEX
    printf("TOTAL OPEX -> R$ %0.2f\n\n", payment + rent[1] + services);

    printf("Deseja exportar o relatorio com mais informacoes? \n");

    printf("[1] - SIM\n");
    printf("[2] - NAO\n\n");

    scanf("%d", &resposta);

    if (resposta == 1)
    {
        system("cls");
        file_opex();
    }
    relatories_screen();
}

void relatory_capex_opex()
{
    float total_CAPEX = sum_capex();
    float total_OPEX = sum_opex();
    relatories_text(4);

    printf("* CAPEX \n");
    printf("  TOTAL CAPEX -> R$ %0.2f\n\n", total_CAPEX);

    printf("* OPEX  \n");
    printf("  TOTAL OPEX -> R$ %0.2f\n\n", total_OPEX);
    wait_for_input("");

    relatories_screen();
}
