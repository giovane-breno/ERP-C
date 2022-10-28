#include <stdio.h>
#include <stdlib.h>

void create_file(char filename[25], char content[25])
{
     /*
     * INICIALIZAÇÃ DO PONTEIRO / ARQUIVO
     */
    FILE *pont_arq = fopen(filename, "a+");
    if (pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        fprintf(pont_arq, "%s;\n", content);
        fclose(pont_arq);
    }
}

void verify_file(char filename[25], char content[256]){
    
}