#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#include "authentication.h"
#include "text_handler.h"
#include "others.h"

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
    char cpf[256];
    int age;
    int active;
};

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
    main_menu_text(3); /* RETORNA AO MENU APÓS CLIQUE */
}

void query_customers(char filename[128])
{
    query_c_files(filename);
    wait_for_input("\nLista de usuarios impressa com sucesso!\n");
    system("cls");
    main_menu_text(3); /* RETORNA AO MENU APÓS CLIQUE */
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
    status = create_file("files\\workers.txt", worker_data);

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

        system("cls");
        fflush(stdin);
        register_customer_text(1);
        printf("\nIdade: ");
        scanf("%d", &customer.age);

        system("cls");
        fflush(stdin);
        register_customer_text(1);
        printf("\nCPF (APENAS NUMEROS): ");
        gets(customer.cpf);
        encrypt(customer.cpf);

        system("cls");
        fflush(stdin);
        register_customer_text(1);
        puts("\nCliente Ativo? ");
        puts("[1] - Sim\n[2] - Nao");
        scanf("%d", &customer.active);
        fflush(stdin);

        system("cls");
        register_work_text(1);
        puts("\nConfirme se os dados abaixo estao corretos:");
        printf("\nNome: %s", customer.name);
        printf("\nIdade: %d", customer.age);
        printf("\nCPF: %s", customer.cpf);
        (customer.active == 1) ? printf("\nAtivo: Sim") : printf("\nAtivo: Nao");

        puts("\n\nCorretos?\n[1] - Sim\n[2] - Nao\n");
        scanf("%d", &correct_data);

        if (correct_data == 1)
            break;
    }

    sprintf(customer_data, "%s %d %s %d", customer.name, customer.age, customer.cpf, customer.active);
    system("cls");
    status = create_file("files\\customers.txt", customer_data);

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