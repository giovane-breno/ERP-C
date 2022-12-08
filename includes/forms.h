#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

/* DEFININDO O TAMANHO MAXIMO DAS VARIAVEIS TIPO CHAR */
#define MAX_EMAIL_LENGHT 80
#define MAX_PASSWORD_LENGHT 20

#define MAX_PROFILE_REASON 256

#define MAX_WORKER_ROLE 60
#define MAX_WORKER_NAME 80

#define MAX_INFRASTRUCTURE_RENT 256
#define MAX_INFRASTRUCTURE_WATER 256
#define MAX_INFRASTRUCTURE_ENERGY 256
#define MAX_INFRASTRUCTURE_CLEANING 256
#define MAX_INFRASTRUCTURE_NET 256

#define MAX_CUSTOMER_NAME 80
#define MAX_CUSTOMER_CPF 12
#define MAX_CUSTOMER_CEP 9

#define MAX_STORAGE_BRAND 256
#define MAX_STORAGE_MODEL 256
#define MAX_STORAGE_SUPPLIER 256

#define MAX_CATEGORY_NAME 80
/* DEFININDO O TAMANHO MAXIMO DAS VARIAVEIS TIPO CHAR */

struct Users
{
    char *email;
    char *password;
};

struct Workers
{
    char *name;
    char *role;
    float payment;
};

struct Customers
{
    short int gender; /* M = 1 | F = 2*/
    short int age;
    char *name;
    char *cpf;
    char *cep;
};

struct Profiles
{
    long int customer_id;             /* ID DO CLIENTE */
    short int domestic_or_commercial; /* PARA USO DOMÉSTICO[1] OU COMERCIAL[2] */
    short int pickup_or_delivery;     /* PARA RETIRAR NA LOJA[1] OU ENTREGA[2] */
    short int active;                 /* USUARIO ATIVO OU NAO */
    char *reason_of_buying;           /* MOTIVO DE COMPRA */
};

struct Infrastructure
{
    char *rent_adress;
    float rent_price;

    char *water_sender;
    float water_value;

    char *energy_sender;
    float energy_value;

    char *cleaning_sender;
    float cleaning_value;

    char *net_sender;
    float net_value;

    float tax;
    float total_value;
};

struct Storage
{
    short int category;
    int amount;
    float price;
    char *brand;
    char *model;
    char *supplier;
};

#include "others.h"
#include "relatories.h"
#include "authentication.h"
#include "text_handler.h"

/**
 * Formulário de cadastro de perfil, utilizando um cliente cadastrado.
 *
 * @return Impressão no console e criação de arquivo profiles.txt.
 */
void register_profile_form()
{
    struct Profiles profile;
    profile.reason_of_buying = malloc(sizeof(char) * MAX_PROFILE_REASON);

    char *profile_data;
    short int answer;
    bool status = false;
    short int correct_data;

    while (true)
    {

        system("cls");
        fflush(stdin);
        register_profile_text(1);
        puts("\nImprimir lista de clientes?\n [1] - Sim | [2] - Nao");
        scanf("%hd", &answer);

        if (answer == 1)
        {
            system("cls");
            query_customers_file("files\\customers.txt", 1);

            wait_for_input("\nLista de clientes impressa com sucesso!\n");
        }

        system("cls");
        fflush(stdin);
        register_profile_text(1);
        printf("\nID do Cliente: ");
        scanf("%ld", &profile.customer_id);

        do
        {
            system("cls");
            fflush(stdin);
            register_profile_text(1);
            puts("\nO Cliente faz encomendas para uso particular ou comercial?\n[1] - PARTICULAR | [2] - COMERCIAL");
            scanf("%hd", &profile.domestic_or_commercial);
            if (profile.domestic_or_commercial == 1 || profile.domestic_or_commercial == 2)
                break;
        } while (true);

        do
        {
            system("cls");
            fflush(stdin);
            register_profile_text(1);
            puts("\nO Cliente faz encomendas para entregar ou retirar no local?\n[1] - ENTREGAR | [2] - RETIRAR NO LOCAL");
            scanf("%hd", &profile.pickup_or_delivery);
            if (profile.pickup_or_delivery == 1 || profile.pickup_or_delivery == 2)
                break;
        } while (true);

        system("cls");
        fflush(stdin);
        register_profile_text(1);
        puts("\nO Cliente tem algum motivo especifico para comprar na empresa?");
        fgets(profile.reason_of_buying, MAX_PROFILE_REASON, stdin);

        do
        {
            system("cls");
            fflush(stdin);
            register_profile_text(1);
            puts("\nO Cliente ainda frequenta?\n[1] - ATIVO | [2] - INATIVO");
            scanf("%hd", &profile.active);
            if (profile.active == 1 || profile.active == 2)
                break;
        } while (true);

        do
        {
            system("cls");
            register_profile_text(1);
            puts("\nConfirme se os dados abaixo estao corretos:");
            printf("\nID do Cliente: %ld", profile.customer_id);
            printf("\nTipo de Encomenda: ");
            (profile.domestic_or_commercial == 1) ? printf("Particular") : printf("Comercial");
            printf("\nMetodo de Entrega: ");
            (profile.pickup_or_delivery == 1) ? printf("Entregar") : printf("Retirar no Local");
            printf("\nMotivo de Compra: %s", profile.reason_of_buying);
            printf("\nCliente Ativo? ");
            (profile.active == 1) ? printf("Sim") : printf("Nao");
            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao");
            scanf("%hd", &correct_data);

            if (correct_data == 1 || correct_data == 2)
                break;
        } while (true);

        if (correct_data == 1)
            break;
    }

    remove_whitespace(profile.reason_of_buying);
    profile_data = malloc(strlen(profile.reason_of_buying) + 4 + (sizeof(long int) * (profile.customer_id)) + (sizeof(short int) * (profile.domestic_or_commercial)) + (sizeof(short int) * profile.pickup_or_delivery));

    sprintf(profile_data, "%ld %hd %hd %s %hd", profile.customer_id, profile.domestic_or_commercial, profile.pickup_or_delivery, profile.reason_of_buying, profile.active);
    system("cls");
    status = create_file("files\\profiles.txt", profile_data, "a");

    free(profile.reason_of_buying);
    free(profile_data);

    (status) ? wait_for_input("\nPerfil de Cliente cadastrado com sucesso!\n") : wait_for_input("\n");
}

/**
 * Formulário de cadastro de usuario do sistema.
 *
 * @return Impressão no console.
 */
void register_form()
{
    struct Users user;

    user.email = malloc(sizeof(char) * MAX_EMAIL_LENGHT);
    user.password = malloc(sizeof(char) * MAX_PASSWORD_LENGHT);
    char *cpass = malloc(sizeof(char) * MAX_PASSWORD_LENGHT); /* CONFIRM PASSWORD */

    system("cls");
    authentication_text(2);
    fflush(stdin);
    printf("\nEmail: ");
    fgets(user.email, MAX_EMAIL_LENGHT, stdin);
    while (true)
    {
        printf("Senha: ");
        fgets(user.password, MAX_PASSWORD_LENGHT, stdin);
        printf("Confirmar senha: ");
        fgets(cpass, MAX_PASSWORD_LENGHT, stdin);

        /* Funcao para comparar as strings! */
        if (strcmp(cpass, user.password) == 0)
        {
            register_account(user.email, user.password) ? puts("\nCadastro feito com sucesso!") : puts("\nHouve um erro no cadastro!");
            wait_for_input("");
            free(user.email);
            free(user.password);
            free(cpass);

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

/**
 * Formulário de login.
 *
 * @returns True / False
 */
bool login_form()
{
    struct Users user;
    bool status = false;

    user.email = malloc(sizeof(char) * MAX_EMAIL_LENGHT);
    user.password = malloc(sizeof(char) * MAX_PASSWORD_LENGHT);

    authentication_text(3);
    fflush(stdin);
    printf("Email: ");
    fgets(user.email, MAX_EMAIL_LENGHT, stdin);
    printf("Senha: ");
    fgets(user.password, MAX_PASSWORD_LENGHT, stdin);

    remove_whitespace(user.email);
    remove_whitespace(user.password);

    status = login_account(user.email, encrypt(user.password)) ? true : false;

    free(user.email);
    free(user.password);

    return status;
}

/**
 * Função para imprimir a lista de usuarios.
 * Chama a função query_users_file().
 *
 * @param filename deve ser um int
 * @return Impressão de lista de usuarios no console.
 */
void query_users(char *filename)
{
    query_users_file(filename);
    wait_for_input("\nLista de usuarios impressa com sucesso!\n");
    system("cls");
    main_menu_text(2); /* RETORNA AO MENU APÓS CLIQUE */
}

/**
 * Função para imprimir a lista de clientes.
 * Chama a função query_customers_file().
 *
 * @param filename deve ser um diretorio de arquivo.
 * @return Impressão da lista de clientes no console.
 */
void query_customers(char *filename)
{
    query_customers_file(filename, false);
    wait_for_input("\nLista de clientes impressa com sucesso!\n");
    system("cls");
    main_menu_text(2); /* RETORNA AO MENU APÓS CLIQUE */
}

/**
 * Função para imprimir a lista de funcionarios.
 * Chama a função query_workers_file().

 * @param filename deve ser um diretorio de arquivo.
 * @return Impressão da lista de clientes no console.
 */
void query_workers(char *filename)
{
    query_workers_file(filename);
    wait_for_input("\nLista de funcionarios impressa com sucesso!\n");
    system("cls");
    main_menu_text(2); /* RETORNA AO MENU APÓS CLIQUE */
}

/**
 * Função para imprimir a lista de clientes e pegar o perfil do cliente selecionado.
 *
 * @param filename deve ser um diretorio de arquivo.
 * @return Impressão da lista de perfil de um cliente selecionado.
 */
void query_profile(char *filename)
{
    long int id = 0;
    short int answer = 0;

    system("cls");
    fflush(stdin);
    register_profile_text(2);
    puts("\nImprimir lista de clientes?\n [1] - Sim | [2] - Nao");
    scanf("%hd", &answer);

    if (answer == 1)
    {
        system("cls");
        query_customers_file("files\\customers.txt", 1);

        wait_for_input("\nLista de clientes impressa com sucesso!\n");
    }

    system("cls");
    fflush(stdin);
    register_profile_text(2);
    printf("\nID do Cliente: ");
    scanf("%ld", &id);

    system("cls");
    register_profile_text(2);
    query_p_files(filename, id);

    wait_for_input("\nPerfil de cliente impresso com sucesso!\n");
    system("cls");
    query_human_text(1);
}

/**
 * Formulario para cadastrar 01 funcionario.
 *
 * @return Impressão no console e criação do arquivo workers.txt.
 */
void register_work_form()
{
    struct Workers worker;
    char *worker_data;

    worker.name = malloc(sizeof(char) * MAX_WORKER_NAME);
    worker.role = malloc(sizeof(char) * MAX_WORKER_ROLE);

    short int correct_data;
    bool status = false;

    while (true)
    {
        fflush(stdin);
        system("cls");
        register_work_text(1);
        printf("\nNome: ");
        fgets(worker.name, MAX_WORKER_NAME, stdin);

        system("cls");
        register_work_text(1);
        printf("Cargo: ");
        fgets(worker.role, MAX_WORKER_ROLE, stdin);

        system("cls");
        register_work_text(1);
        printf("Salario: ");
        scanf("%f", &worker.payment);

        fflush(stdin);

        system("cls");
        register_work_text(1);
        puts("\nConfirme se os dados abaixo estao corretos:");
        printf("\nNome: %s", worker.name);
        printf("Cargo: %s", worker.role);
        printf("Salario: R$%.2f", worker.payment);
        puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
        scanf("%hd", &correct_data);

        if (correct_data == 1)
            break;
    }

    remove_whitespace(worker.name);
    remove_whitespace(worker.role);

    worker_data = malloc(strlen(worker.name) + 1 + strlen(worker.role) + 1 + (sizeof(float) * (worker.payment)));

    sprintf(worker_data, "%s %s %.2f", worker.name, worker.role, worker.payment);
    system("cls");
    status = create_file("files\\workers.txt", worker_data, "a");

    free(worker_data);
    free(worker.name);
    free(worker.role);

    (status == true) ? wait_for_input("\nFuncionario cadastrado com sucesso!\n") : wait_for_input("\n");
}

/**
 * Formulario de registro dos dados de infraestrutura.
 *
 * @return Impressão no console e criação do arquivo infrastructure.txt.
 */
void register_infra_form()
{
    struct Infrastructure infrastructure;
    infrastructure.rent_adress = malloc(sizeof(char) * MAX_INFRASTRUCTURE_RENT);
    infrastructure.water_sender = malloc(sizeof(char) * MAX_INFRASTRUCTURE_WATER);
    infrastructure.energy_sender = malloc(sizeof(char) * MAX_INFRASTRUCTURE_ENERGY);
    infrastructure.cleaning_sender = malloc(sizeof(char) * MAX_INFRASTRUCTURE_CLEANING);
    infrastructure.net_sender = malloc(sizeof(char) * MAX_INFRASTRUCTURE_NET);

    char *infra_data;
    bool status = false;
    short int correct_data;

    while (true)
    {
        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* ALUGUEL ");
        printf("Endereco: ");
        fgets(infrastructure.rent_adress, MAX_INFRASTRUCTURE_RENT, stdin);
        printf("Valor: R$ ");
        scanf("%f", &infrastructure.rent_price);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* AGUA E SANEAMENTO ");
        printf("Distribuidora: ");
        fgets(infrastructure.water_sender, MAX_INFRASTRUCTURE_WATER, stdin);
        printf("Valor: R$ ");
        scanf("%f", &infrastructure.water_value);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* DISTRIBUICAO DE ENERGIA ");
        printf("Distribuidora: ");
        fgets(infrastructure.energy_sender, MAX_INFRASTRUCTURE_ENERGY, stdin);

        printf("Valor: R$ ");
        scanf("%f", &infrastructure.energy_value);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* SERVICO DE LIMPEZA ");
        printf("Distribuidora: ");
        fgets(infrastructure.cleaning_sender, MAX_INFRASTRUCTURE_CLEANING, stdin);
        printf("Valor: R$ ");
        scanf("%f", &infrastructure.cleaning_value);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* SERVICO DE INTERNET ");
        printf("Distribuidora: ");
        fgets(infrastructure.net_sender, MAX_INFRASTRUCTURE_NET, stdin);

        printf("Valor: R$ ");
        scanf("%f", &infrastructure.net_value);

        system("cls");
        fflush(stdin);
        infra_text(1);
        puts("\n* TAXAS ");
        printf("Imposto: ");
        scanf("%f", &infrastructure.tax);

        infrastructure.total_value = infrastructure.rent_price + infrastructure.water_value + infrastructure.energy_value + infrastructure.cleaning_value + infrastructure.net_value + infrastructure.tax;
        do
        {
            system("cls");
            infra_text(1);
            puts("\nConfirme se os dados abaixo estao corretos:");
            puts("\n* ALUGUEL");
            printf("Endereco: %s", infrastructure.rent_adress);
            printf("Valor: R$ %0.2f", infrastructure.rent_price);

            puts("\n\n* AGUA E SANEAMENTO");
            printf("Distribuidora: %s", infrastructure.water_sender);
            printf("Valor: R$ %0.2f", infrastructure.water_value);

            puts("\n\n* DISTRIBUICAO DE ENERGIA");
            printf("Distribuidora: %s", infrastructure.energy_sender);
            printf("Valor: R$ %0.2f", infrastructure.energy_value);

            puts("\n\n* SERVICO DE LIMPEZA");
            printf("Distribuidora: %s", infrastructure.cleaning_sender);
            printf("Valor: R$ %0.2f", infrastructure.cleaning_value);

            puts("\n\n* SERVICO DE INTERNET");
            printf("Distribuidora: %s", infrastructure.net_sender);
            printf("Valor: R$ %0.2f", infrastructure.net_value);

            puts("\n\n* TAXAS");
            printf("Imposto: R$ %0.2f\n", infrastructure.tax);
            printf("Valor Total: R$ %0.2f", infrastructure.total_value);

            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
            scanf("%hd", &correct_data);

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

    infra_data = malloc(strlen(infrastructure.rent_adress) + 1 + strlen(infrastructure.water_sender) + 1 + strlen(infrastructure.energy_sender) + 1 + strlen(infrastructure.cleaning_sender) + 1 + strlen(infrastructure.net_sender) + 1 + (sizeof(float) * (infrastructure.rent_price)) + (sizeof(float) * (infrastructure.water_value)) + (sizeof(float) * (infrastructure.energy_value)) + (sizeof(float) * (infrastructure.cleaning_value)) + (sizeof(float) * (infrastructure.net_value)) + (sizeof(float) * (infrastructure.tax)) + (sizeof(float) * (infrastructure.total_value)));

    sprintf(infra_data, "%s %0.2f\n%s %0.2f\n%s %0.2f\n%s %0.2f\n%s %0.2f\n%0.2f\n%0.2f", infrastructure.rent_adress, infrastructure.rent_price, infrastructure.water_sender, infrastructure.water_value, infrastructure.energy_sender, infrastructure.energy_value, infrastructure.cleaning_sender, infrastructure.cleaning_value, infrastructure.net_sender, infrastructure.net_value, infrastructure.tax, infrastructure.total_value);
    system("cls");
    status = create_file("files\\infrastructure.txt", infra_data, "w+");

    free(infra_data);
    free(infrastructure.rent_adress);
    free(infrastructure.water_sender);
    free(infrastructure.energy_sender);
    free(infrastructure.cleaning_sender);
    free(infrastructure.net_sender);

    (status == true) ? wait_for_input("\nInfraestrutura cadastrada com sucesso!\n") : wait_for_input("\n");
}

/**
 * Função para imprimir os dados da infraestrutura da empresa.
 * É usado na chamada no main.
 *
 * @return Impressão no console e criação do arquivo infrastructure.txt.

 */
void show_infra_form()
{
    infra_text(2);
    query_infra_files("files\\infrastructure.txt");
    wait_for_input("\nDados de Infraestrutura impressos com sucesso!\n");
}

/**
 * Formulário para cadastrar um cliente.
 */
void register_customer_form()
{
    struct Customers customer;
    char *customer_data;
    customer.name = malloc(sizeof(char) * MAX_CUSTOMER_NAME);
    customer.cpf = malloc(sizeof(char) * MAX_CUSTOMER_CPF);
    customer.cep = malloc(sizeof(char) * MAX_CUSTOMER_CEP);

    bool status = false;
    short int correct_data;

    while (true)
    {
        system("cls");
        fflush(stdin);
        register_customer_text(1);
        printf("\nNome: ");
        fgets(customer.name, MAX_CUSTOMER_NAME, stdin);

        do
        {

            system("cls");
            fflush(stdin);
            register_customer_text(1);
            printf("\nIdade: ");
            scanf("%hd", &customer.age);
            if (customer.age >= 0)
                break;

        } while (true);

        do
        {
            system("cls");
            fflush(stdin);
            register_customer_text(1);
            printf("\n[1] - MASCULINO | [2] - FEMININO\nSEXO: ");
            scanf("%hd", &customer.gender);

            if (customer.gender == 1 || customer.gender == 2)
                break;

        } while (true);

        system("cls");
        fflush(stdin);
        register_customer_text(1);
        printf("\nCPF (APENAS NUMEROS): ");
        fgets(customer.cpf, MAX_CUSTOMER_CPF, stdin);

        system("cls");
        fflush(stdin);
        register_customer_text(1);
        printf("\nCEP (APENAS NUMEROS): ");
        fgets(customer.cep, MAX_CUSTOMER_CEP, stdin);
        do
        {
            system("cls");
            register_customer_text(1);
            puts("\nConfirme se os dados abaixo estao corretos:");
            printf("\nNome: %s", customer.name);
            printf("Idade: %hd", customer.age);
            printf("\nSexo: ");
            (customer.gender == 1) ? printf("Masculino") : printf("Feminino");
            printf("\nCPF: %.11s", customer.cpf);
            printf("\nCEP: %.8s", customer.cep);

            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
            scanf("%hd", &correct_data);

            if (correct_data == 1 || correct_data == 2)
                break;
        } while (true);

        if (correct_data == 1)
            break;
    }

    remove_whitespace(customer.name);
    remove_whitespace(customer.cpf);
    remove_whitespace(customer.cep);

    customer_data = malloc(strlen(customer.name) + 1 + strlen(customer.cpf) + 1 + strlen(customer.cep) + 1 + (sizeof(short int) * (customer.age)) + (sizeof(short int) * (customer.gender)));

    sprintf(customer_data, "%s %hd %hd %s %s", customer.name, customer.age, customer.gender, customer.cpf, customer.cep);
    system("cls");
    status = create_file("files\\customers.txt", customer_data, "a");

    free(customer_data);
    free(customer.name);
    free(customer.cpf);
    free(customer.cep);
    (status == true) ? wait_for_input("\nCliente cadastrado com sucesso!\n") : wait_for_input("\n");
}

/**
 * Formulário para cadastrar uma categoria.
 *
 * @return Impressão no console e criação do arquivo categories.txt.

 */
void register_category_form()
{
    char *category = malloc(sizeof(char) * MAX_CATEGORY_NAME);
    short int correct_data;

    bool status = false;
    while (true)
    {
        system("cls");
        fflush(stdin);
        category_text(1);
        printf("\nCategoria: ");
        fgets(category, MAX_CATEGORY_NAME, stdin);

        do
        {
            system("cls");
            category_text(1);
            puts("\nConfirme se os dados abaixo estao corretos:");
            printf("\nCategoria: %s", category);
            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
            scanf("%hd", &correct_data);

            if (correct_data == 1 || correct_data == 2)
                break;
        } while (true);

        if (correct_data == 1)
            break;
    }
    remove_whitespace(category);

    status = create_file("files\\categories.txt", category, "a");
    system("cls");

    free(category);
    (status == true) ? wait_for_input("\nCategoria cadastrada com sucesso!\n") : wait_for_input("\n");
}

/**
 * Formulário para cadastrar um item.
 * Realiza a pesquisa das categorias e dos itens referentes a tal.
 *
 * @return Impressão no console e criação do arquivo categories.txt.
 */
void register_item_form()
{
    struct Storage item;
    item.supplier = malloc(sizeof(char) * MAX_STORAGE_SUPPLIER);
    item.brand = malloc(sizeof(char) * MAX_STORAGE_BRAND);
    item.model = malloc(sizeof(char) * MAX_STORAGE_MODEL);

    char *item_data;
    short int correct_data = 0;
    short int answer = 0;
    bool status = false;

    system("cls");
    fflush(stdin);
    register_profile_text(1);
    puts("\nImprimir lista de categorias?\n [1] - Sim | [2] - Nao");
    scanf("%hd", &answer);

    if (answer == 1)
    {
        system("cls");
        query_cat_files("files\\categories.txt", false);

        wait_for_input("\nCategorias impressa com sucesso!\n");
    }

    while (true)
    {
        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nID da Categoria: ");
        scanf("%hd", &item.category);

        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nFornecedor: ");
        fgets(item.supplier, MAX_STORAGE_SUPPLIER, stdin);

        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nMarca: ");
        fgets(item.brand, MAX_STORAGE_BRAND, stdin);

        system("cls");
        fflush(stdin);
        category_text(2);
        printf("\nModelo: ");
        fgets(item.model, MAX_STORAGE_MODEL, stdin);

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
            printf("Marca:  %s", item.brand);
            printf("Modelo:  %s", item.model);
            printf("Quantidade:  %d", item.amount);
            printf("\nValor Unitario: R$ %0.2f", item.price);

            puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
            scanf("%hd", &correct_data);

            if (correct_data == 1 || correct_data == 2)
                break;
        } while (true);

        if (correct_data == 1)
            break;
    }

    remove_whitespace(item.supplier);
    remove_whitespace(item.brand);
    remove_whitespace(item.model);

    item_data = malloc(strlen(item.supplier) + 1 + strlen(item.brand) + 1 + strlen(item.model) + 1 + (sizeof(int) * (item.amount)) + (sizeof(int) * (item.category)) + (sizeof(float) * (item.price)));

    sprintf(item_data, "%hd %s %s %s %d %0.2f", item.category, item.supplier, item.brand, item.model, item.amount, item.price);
    system("cls");
    status = create_file("files\\items.txt", item_data, "a");

    free(item_data);
    free(item.supplier);
    free(item.brand);
    free(item.model);
    (status == true) ? wait_for_input("\nItem cadastrado com sucesso!\n") : wait_for_input("\n");
}

/**
 * Função para imprimir os dados do estoque de itens cadastrados.
 * É usado na chamada no main.
 *
 * @return Impressão no console e criação do arquivo items.txt.
 */
void show_storage_form()
{
    system("cls");
    category_text(3);
    query_storage_files("files\\items.txt", false);

    wait_for_input("\nDados de Estoque impressos com sucesso!\n");
}

/**
 * Função para imprimir o relatório capex no console.
 * É usado na chamada no main.
 *
 * @return Impressão no console.
 */
void relatory_capex()
{
    short int resposta;

    relatories_text(2);

    query_storage_files("files\\items.txt", true);

    printf("Deseja exportar o relatorio com mais informacoes? \n");

    printf("[1] - SIM\n");
    printf("[2] - NAO\n\n");

    scanf("%hd", &resposta);

    if (resposta == 1)
    {
        system("cls");
        file_capex("files\\items.txt");
    }
}

/**
 * Função para imprimir o relatório opex no console.
 * É usado na chamada no main.
 *
 * @return Impressão no console e .
 */
void relatory_opex()
{
    float payment = sum_payment();
    float services = sum_services();
    float *rent = rent_and_tax();
    short int resposta;
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

    scanf("%hd", &resposta);

    if (resposta == 1)
    {
        system("cls");
        file_opex("files\\infrastructure.txt");
    }
}

/**
 * Função para imprimir o total do relatorio capex e opex no console.
 * É usado na chamada no main.
 *
 * @return Impressão no console.
 */
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
}

void delete_customer_form()
{ // EDITAR CLIENTES
    if (delete_customer() == true)
    {
        int res;
        system("cls");
        puts("Voce deseja cadastrar um novo cliente?");
        puts("[1] - Sim | [2] - Nao\n");
        scanf("%d", &res);
        if (res == 1)
        {
            register_customer_form();
        }
    }
    else
    {
        system("cls");
        wait_for_input("Ha um perfil cadastrado para esse cliente, exclua-o previamente.\n");
    }
}

void delete_users_form()
{ // EDITAR LOGINS
    if (delete_user() == true)
    {
        int res;
        system("cls");
        puts("Voce deseja cadastrar um novo usuario?");
        puts("[1] - Sim | [2] - Nao\n");
        scanf("%d", &res);
        if (res == 1)
        {
            register_form();
        }
    }
}

void delete_profiles_form()
{
    if (delete_profiles() == true)
    {
        int res;
        system("cls");
        puts("Voce deseja cadastrar um novo perfil de cliente?");
        puts("[1] - Sim | [2] - Nao\n");
        scanf("%d", &res);
        if (res == 1)
        {
            register_profile_form();
        }
    }
}

void delete_workers_form()
{
    if (delete_workers() == true)
    {
        int res;
        system("cls");
        puts("\nVoce deseja cadastrar um novo funcionario?");
        puts("[1] - Sim | [2] - Nao\n");
        scanf("%d", &res);
        if (res == 1)
        {
            register_work_form();
        }
    }
}

void delete_items_form()
{
    if (delete_item() == true)
    {
        int res;
        system("cls");
        puts("\nVoce deseja cadastrar um novo item?");
        puts("[1] - Sim | [2] - Nao\n");
        scanf("%d", &res);
        if (res == 1)
        {
            register_item_form();
        }
    }
}

void delete_categories_form()
{
    if (delete_category() == true)
    {
        int res;
        system("cls");
        puts("Voce deseja cadastrar uma nova categoria?");
        puts("[1] - Sim | [2] - Nao\n");
        scanf("%d", &res);
        if (res == 1)
        {
            register_category_form();
        }
    }
    else
    {
        system("cls");
        wait_for_input("Ha itens cadastrados nessa categoria, exclua-o previamente.\n");
    }
}