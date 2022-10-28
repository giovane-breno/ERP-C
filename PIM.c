#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "includes/forms.h"

int main()
{

    setlocale(LC_ALL, "");
    int option = 0;
    int authenticated = 0;
    return_text(1);

    while (authenticated == 0)
    {
        scanf("%i", &option);
        system("cls");

        switch (option)
        {
        case 1:
            login_form();
            system("cls");
            authenticated = 1;
            break;
        case 2:
            register_form();
            system("cls");
            return_text(1);
            break;
        default:
            system("cls");
            return_text(1);
            printf("* OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
            break;
        }
    }

    return 0;
}
