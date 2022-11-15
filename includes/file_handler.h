#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int file_exist()
{

    FILE *fp = fopen("files\\config.txt", "r");
    int status = 0;
    if (!fp)
    {
        fclose(fp);
        status = 1;
    }
    return status;
}

int config_file()
{
    int status = 1;
    if (file_exist())
    {
        FILE *fp = fopen("files\\config.txt", "a");
        fprintf(fp, "register: 1");
        fclose(fp);
        status = 1;
    }
    else
    {
        FILE *fp = fopen("files\\config.txt", "r");
        char c;
        while ((c = getc(fp)) != EOF)
        {
            if (c == '1')
            {
                status = 1;
            }
            else if (c == '0')
            {
                status = 0;
            }
        }
    }
    return status;
}

void check_register_status()
{
    FILE *fp = fopen("files\\config.txt", "r");
    char c;
    while ((c = getc(fp)) != EOF)
    {
        if (c == '1')
        {
            fclose(fp);
            FILE *fp = fopen("files\\config.txt", "w+");
            fprintf(fp, "register: 0");
            puts("Desativado!");
            fclose(fp);
        }
        else if (c == '0')
        {
            fclose(fp);
            FILE *fp = fopen("files\\config.txt", "w+");
            fprintf(fp, "register: 1");
            puts("Ativado!");
            fclose(fp);
        }
    }
    getch();
    system("cls");
}

int create_file(char filename[25], char content[256])
{
    int status = 0;
    FILE *fp = fopen(filename, "a");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        fprintf(fp, "%s\n", content);
        status = 1;
    }
    fclose(fp);

    return status;
}

int read_file(char filename[25], char content[256])
{
    int status = 0;
    FILE *fp = fopen(filename, "r");
    char c[100];
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
        exit(1);
    }
    else
    {
        while (fgets(c, sizeof(c), fp))
        {
            if (strstr(c, content))
            {
                status = 1;
                break;
            }
        }
    }

    fclose(fp);

    return status;
}

void query_c_files(char filename[25])
{
    char name[256];
    int age;
    char cpf[60];
    int active;
    int counter = 1;

    FILE *fp = fopen(filename, "r");
    char c;
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    bool password = false;

    while (fscanf(fp, "%s %d %s %d", name, &age, cpf, &active) == 4)
    {

        printf("Consulta: %d\n\n", counter);
        printf("Nome: %s\n", name);
        printf("Idade: %d anos\n", age);
        printf("CPF: %s\n", cpf);
        (active == 1) ? printf("Ativo? Sim\n") : printf("Ativo? Nao\n");
        puts("-----------------------------------------------------------");

        counter++;
    }
    fclose(fp);
}

void query_w_files(char filename[25])
{
    char name[256];
    char role[256];
    float payment;
    int counter = 1;

    FILE *fp = fopen(filename, "r");
    char c;
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    bool password = false;

    while (fscanf(fp, "%s %s %f", name, role, &payment) == 3)
    {

        printf("Consulta: %d\n\n", counter);
        printf("Nome: %s\n", name);
        printf("Cargo: %s\n", role);
        printf("Salario: %0.2f\n", payment);
        puts("-----------------------------------------------------------");

        counter++;
    }
    fclose(fp);
}

void query_users_files(char filename[25])
{
    FILE *fp = fopen(filename, "r");
    char name[256];
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    while (fscanf(fp, "%s %*s", name) == 1)
    {
        {
            printf("Usuario: %s\n", name);
        }
    }

    fclose(fp);
}