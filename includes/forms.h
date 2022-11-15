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

void relatory_capex()
{
    int resposta;
    // Variáveis globais (Capex)
    float valor_pc = 30000;
    float valor_monitores = 3493.90;
    float valor_mesas = 2500.00;
    float valor_cadeiras = 2500.00;
    float valor_outros = 2500.00;
    float total_CAPEX = valor_pc + valor_monitores + valor_mesas + valor_cadeiras + valor_outros;

    relatories_text(2);

    printf("|Computadores\n");
    printf("|R$ %2.0f \n\n", valor_pc);
    printf("|Monitores\n");
    printf("|R$ %0.2f \n\n", valor_monitores);
    printf("|Mesas\n");
    printf("|R$ %2.0f \n\n", valor_mesas);
    printf("|Cadeiras\n");
    printf("|R$ %2.0f \n\n", valor_cadeiras);
    printf("|Outros\n");
    printf("|R$ %2.0f \n\n", valor_outros);

    printf("|TOTAL CAPEX -> R$ %0.2f|\n\n", total_CAPEX);
    printf("Deseja exportar o relatorio com mais informacoes? \n");
    // printf("Digite 1 para Sim, ou 2 para Nï¿½o <1/2> \n");

    printf("[1] - SIM\n");
    printf("[2] - NAO\n\n");

    scanf("%d", &resposta);

    if (resposta == 1)
    {
        system("cls");
        file_capex(valor_pc, valor_monitores, valor_mesas, valor_cadeiras, valor_outros, total_CAPEX);
    }

    relatories_screen();
}

void relatory_opex(){
    int resposta = 0;
//Variáveis
    float aluguel = 1400.63;
    float agua = 230.02;
    float energia = 674.98;
    float limpeza = 337.45;
    float internet = 545.01;
    float total_servicos =  agua + energia + limpeza + internet;
    float impostos = 753.00;
    float salario_adm = 9984.60;
    float salario_com = 8619.69;
    float salario_ope = 11294.71;
    float total_salarios = salario_adm + salario_com + salario_ope;
    float total_OPEX = aluguel + total_servicos + total_salarios + impostos;

    relatories_text(3);

    printf("|Salários\n");
	printf("|R$ %2.0f \n\n", total_salarios);
	
	//impostos
	printf("|Impostos\n");
	printf("|R$ %2.0f \n\n", impostos);
	
	//serviços terceirizados
	printf("|Serviços\n");
	printf("|R$ %2.0f \n\n", total_servicos);
	
	//Aluguel
	printf("|Aluguel\n");
	printf("|R$ %2.0f \n\n", aluguel);
	
	//total OPEX
	printf("|TOTAL OPEX -> R$ %0.2f|\n\n", total_OPEX);

    printf("Deseja exportar o relatorio com mais informacoes? \n");
    // printf("Digite 1 para Sim, ou 2 para Nï¿½o <1/2> \n");

    printf("[1] - SIM\n");
    printf("[2] - NAO\n\n");

    scanf("%d", &resposta);

    if (resposta == 1)
    {
        system("cls");
        file_opex(aluguel ,agua ,energia ,limpeza ,internet ,total_servicos,impostos,salario_adm, salario_com,salario_ope, total_salarios, total_OPEX);
    }
    relatories_screen();
}

void relatory_capex_opex(){
//capex
    float valor_pc = 30000;
    float valor_monitores = 3493.90;
    float valor_mesas = 2500.00;
    float valor_cadeiras = 2500.00;
    float valor_outros = 2500.00;
    float total_CAPEX = valor_pc + valor_monitores + valor_mesas + valor_cadeiras + valor_outros;

//Opex
    float aluguel = 1400.63;
    float agua = 230.02;
    float energia = 674.98;
    float limpeza = 337.45;
    float internet = 545.01;
    float total_servicos =  agua + energia + limpeza + internet;
    float impostos = 753.00;
    float salario_adm = 9984.60;
    float salario_com = 8619.69;
    float salario_ope = 11294.71;
    float total_salarios = salario_adm + salario_com + salario_ope;
    float total_OPEX = aluguel + total_servicos + total_salarios + impostos;

    relatories_text(4);

    printf("|CAPEX \n");
	printf("|TOTAL CAPEX -> R$ %0.2f\n\n", total_CAPEX);

	printf("|OPEX  \n");
	printf("|TOTAL OPEX -> R$ %0.2f\n\n", total_OPEX);
	wait_for_input("");

    relatories_screen();

}


 