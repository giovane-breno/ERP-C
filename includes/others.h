#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void wait_for_input(char message[256])
{
    printf("%s", message);
    puts("Pressione qualquer tecla para continuar...");
    getch();
}

void remove_whitespace(char var[256]){
    char *ptr = var;
    while (*ptr)
    {
        if (*ptr == ' ')
            *ptr = '_';
        ptr++;
    }
}