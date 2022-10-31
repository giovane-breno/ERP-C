void authentication_text(int type)
{
    switch (type)
    {
    case 1:
        printf("|-----------------------------------------------------------|\n");
        printf("|                    [AUTENTICACAO]                         |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("|                                                           |\n");
        printf("|                [1] - Login                                |\n");
        printf("|                [2] - Cadastrar                            |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        break;

    case 2:
        printf("|-----------------------------------------------------------|\n");
        printf("|                        [CADASTRO]                         |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("OBS:\n* SENHA DEVE TER NO MAXIMO 20 CARACTERES. \n");
        break;
    case 3:
        printf("|-----------------------------------------------------------|\n");
        printf("|                        [LOGIN]                            |\n");
        printf("|-----------------------------------------------------------|\n");
        break;
    default:
        break;
    }
}

void main_menu_text(int type)
{
    switch (type)
    {
    case 1:
        printf("|-----------------------------------------------------------|\n");
        printf("|                  [MENU PRINCIPAL]                         |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("|                                                           |\n");
        printf("|                [1] - Cadastros                            |\n");
        printf("|                [2] - Consultas                            |\n");
        printf("|                [3] - Gerenciamento                        |\n");
        printf("|                [4] - Sair                                 |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        break;
    case 2:
        printf("|-----------------------------------------------------------|\n");
        printf("|                     [CADASTROS]                           |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("|                                                           |\n");
        printf("|                [1] - Cadastrar Cliente                    |\n");
        printf("|                [2] - Cadastrar Funcionario                |\n");
        printf("|                [3] - Cadastrar Perfil                     |\n");
        printf("|                [4] - Voltar                               |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        break;
    case 3:
        printf("|-----------------------------------------------------------|\n");
        printf("|                     [CONSULTAS]                           |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("|                                                           |\n");
        printf("|                [1] - Consultar Clientes                   |\n");
        printf("|                [2] - Cadastrar Funcionarios               |\n");
        printf("|                [3] - Consultar Perfis                     |\n");
        printf("|                [4] - Consultar Usuarios                   |\n");
        printf("|                [5] - Voltar                               |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        break;
    default:
        break;
    }
}

