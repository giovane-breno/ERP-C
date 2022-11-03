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
        fprintf(fp, "%s;\n", content);
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

void query_users_files(char filename[25])
{
    FILE *fp = fopen(filename, "r");
    char c;
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    bool password = false;

    while ((c = getc(fp)) != EOF)
    {

        if ((c == '|') || (c == ';')) /* |  e ; */
        {
            if (c != ';') /* ; */
            {
                printf(" | ");
                password = true;
            }
            else if (c == ';') /* ; */
            {
                password = false;
            }
        }

        if (c != ';' && c != '|')
            (password == false) ? printf("%c", c) : printf("*");
    }

    fclose(fp);
}