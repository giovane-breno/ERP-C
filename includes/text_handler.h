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
        printf("|                [2] - Consultar Funcionarios               |\n");
        printf("|                [3] - Consultar Perfis                     |\n");
        printf("|                [4] - Consultar Usuarios                   |\n");
        printf("|                [5] - Voltar                               |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        break;
    case 4:
        printf("|-----------------------------------------------------------|\n");
        printf("|                     [GERENCIAMENTO]                       |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("|                                                           |\n");
        printf("|                [1] - Gerenciar Dados                      |\n");
        printf("|                [2] - Visualizar Relatorios                |\n");
        printf("|                [3] - Config. Administrativas              |\n");
        printf("|                [4] - Outros                               |\n");
        printf("|                [5] - Voltar                               |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        break;
    default:
        break;
    }
}

void register_work_text(int type)
{
    switch (type)
    {
    case 1:
        printf("|-----------------------------------------------------------|\n");
        printf("|                [CADASTRO DE FUNCIONARIO]                  |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("OBS:\n* DADOS REFERENTES A 01 FUNCIONARIO! \n");
        break;

    default:
        break;
    }
}

void register_customer_text(int type)
{
    switch (type)
    {
    case 1:
        printf("|-----------------------------------------------------------|\n");
        printf("|                  [CADASTRO DE CLIENTE]                    |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("OBS:\n* DADOS REFERENTES A 01 CLIENTE! \n");
        break;

    default:
        break;
    }
}

void edit_data_text(int type)
{
    switch (type)
    {
    case 1:
        printf("|-----------------------------------------------------------|\n");
        printf("|                      [EDITAR DADOS]                       |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("|                                                           |\n");
        printf("|                [1] - Funcionarios                         |\n");
        printf("|                [2] - Clientes                             |\n");
        printf("|                [3] - Perfis de Usuarios                   |\n");
        printf("|                [4] - Voltar                               |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        break;

    default:
        break;
    }
}

void admin_config_text(int type)
{
    switch (type)
    {
    case 1:
        printf("|-----------------------------------------------------------|\n");
        printf("|              [CONFIGURACOES ADMINISTRATIVAS]              |\n");
        printf("|-----------------------------------------------------------|\n");
        printf("|                                                           |\n");
        printf("|                [1] - Ativar/Desativar Registros           |\n");
        printf("|                [4] - Voltar                               |\n");
        printf("|                                                           |\n");
        printf("|-----------------------------------------------------------|\n");
        break;

    default:
        break;
    }
}

void relatories_text(int type)
{
    switch (type)
    {
    case 1:
        printf("|------------------------------------------------------|\n");
        printf("|                     [RELATORIOS]                     |\n");
        printf("|------------------------------------------------------|\n");
        printf("|                                                      |\n");
        printf("|             [1] - Relatorio CAPEX                    |\n");
        printf("|             [2] - Relatorio OPEX                     |\n");
        printf("|             [3] - Relatorio CAPEX & OPEX             |\n");
        printf("|             [4] - Voltar                             |\n");
        printf("|                                                      |\n");
        printf("|------------------------------------------------------|\n");
        break;
    case 2:
        printf("|------------------------------------------------------|\n");
        printf("|                  RELATORIO CAPEX                     |\n");
        printf("|------------------------------------------------------|\n\n");
        break;
    case 3:
        printf("|------------------------------------------------------|\n");
        printf("|                  RELATORIO OPEX                      |\n");
        printf("|------------------------------------------------------|\n\n");
        break;
    case 4:
        printf("|------------------------------------------------------|\n");
        printf("|              RELATORIO CAPEX & OPEX                  |\n");
        printf("|------------------------------------------------------|\n\n");
        break;
    default:
        break;
    }
}