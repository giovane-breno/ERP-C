#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_file(char filename[25], char content[25])
{
    FILE *fp = fopen(filename, "a");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    fprintf(fp, "%s;\n", content);
    fclose(fp);
}

int read_file(char filename[25], char content[256])
{
    int status = 0;
    FILE *fp = fopen(filename, "r");
    char c[100];
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    while (fgets(c, sizeof(c), fp))
    {
        if (strstr(c, content))
        {
            status = 1;
            break;
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