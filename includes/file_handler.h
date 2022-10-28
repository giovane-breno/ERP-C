#include <stdio.h>
#include <stdlib.h>

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