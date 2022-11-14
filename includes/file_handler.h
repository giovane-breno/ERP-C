#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int config_file()
{
    int first_init = 0;
    char c[100];
    FILE *fp = fopen("files\\config.txt", "a");
    while (fgets(c, sizeof(c), fp))
    {
        if (strstr(c, "build"))
        {
            first_init = 1;
            break;
        }
    }

    if (first_init != 1)
    {
        time_t timestamp = time(NULL);
        fprintf(fp, "file build: %s;\n", ctime(&timestamp));
        fprintf(fp, "register: 1;");
    }
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

    while (fscanf(fp, "%s %d %s %d", name, &age, decrypt(cpf), &active) == 4)
    {
        {
            printf("Consulta: %d\n\n", counter);
            printf("Nome: %s\n", name);
            printf("Idade: %d anos\n", age);
            printf("CPF: %s\n", cpf);
            (active == 1) ? printf("Ativo? Sim\n") : printf("Ativo? Nao\n");
            puts("-----------------------------------------------------------");
        }
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