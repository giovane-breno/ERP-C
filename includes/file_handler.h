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

void query_users(char filename[25])
{
    FILE *fp = fopen(filename, "r");
    char c;
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    bool password = false;
    bool first = true;

    while ((c = getc(fp)) != EOF)
    {
        if (first)
        {
            printf("\n\nUSUARIO: ");
            first = false;
        }

        if ((c == 124) || (c == 59)) /* |  e ; */
        {
            if (c != 59) /* ; */
            {
                printf("\nSENHA: ");
                password = true;
            }
            else if (c == 59) /* ; */
            {
                printf("\nUSUARIO: ");
                password = false;
            }
        }

        if (c != 59 && c != 10 && c != 124)
            (password == false) ? printf("%c", c) : printf("%c", c);
    }

    fclose(fp);
}