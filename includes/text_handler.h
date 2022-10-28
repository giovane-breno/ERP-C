void return_text(int type)
{
    switch (type)
    {
    case 1:
        printf("|-----------------------------------------------------------|\n");
        printf("|                  (MENU PRINCIPAL)                         |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("|                                                           |\n");
        printf("|                (1) - Login                                |\n");
        printf("|                (2) - Cadastrar                            |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        break;

    case 2:
        printf("|-----------------------------------------------------------|\n");
        printf("|                        (CADASTRO)                         |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("OBS:\n* SENHA DEVE TER NO MAXIMO 20 CARACTERES. \n");
        break;
    case 3:
        printf("|-----------------------------------------------------------|\n");
        printf("|                        (LOGIN)                            |\n");
        printf("|-----------------------------------------------------------|\n");
        break;
    default:
        break;
    }
}