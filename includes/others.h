#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/**
 * Função para aguardar por clique de usuario.
 *
 * @param message deve ser uma string, pode ser vazia.
 * @return Impressão no console.
 */
void wait_for_input(char message[256])
{
    printf("%s", message);
    puts("Pressione qualquer tecla para continuar...");
    getch();
}

/**
 * Função para substituir os ' ' por '_'.
 *
 * @param var deve ser uma string.
 * @return Manipulação por meio do ponteiro da variavel formal.
 */
void remove_whitespace(char var[256]){
    char *ptr = var;
    while (*ptr)
    {
        if (*ptr == ' ')
            *ptr = '_';
        ptr++;
    }
}

/**
 * Função para substituir os '_' por ' '.
 *
 * @param var deve ser uma string.
 * @return Manipulação por meio do ponteiro da variavel formal.
 */
void add_whitespace(char var[256]){
    char *ptr = var;
    while (*ptr)
    {
        if (*ptr == '_')
            *ptr = ' ';
        ptr++;
    }
}