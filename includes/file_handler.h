#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int file_exist()
{

    FILE *fp = fopen("files\\config.txt", "r");
    int status = 0;
    if (!fp)
    {
        fclose(fp);
        status = 1;
    }
    return status;
}

int config_file()
{
    int status = 1;
    if (file_exist())
    {
        FILE *fp = fopen("files\\config.txt", "a");
        fprintf(fp, "register: 1");
        fclose(fp);
        status = 1;
    }
    else
    {
        FILE *fp = fopen("files\\config.txt", "r");
        char c;
        while ((c = getc(fp)) != EOF)
        {
            if (c == '1')
            {
                status = 1;
            }
            else if (c == '0')
            {
                status = 0;
            }
        }
    }
    return status;
}

void check_register_status()
{
    FILE *fp = fopen("files\\config.txt", "r");
    char c;
    while ((c = getc(fp)) != EOF)
    {
        if (c == '1')
        {
            fclose(fp);
            FILE *fp = fopen("files\\config.txt", "w+");
            fprintf(fp, "register: 0");
            puts("Desativado!");
            fclose(fp);
        }
        else if (c == '0')
        {
            fclose(fp);
            FILE *fp = fopen("files\\config.txt", "w+");
            fprintf(fp, "register: 1");
            puts("Ativado!");
            fclose(fp);
        }
    }
    getch();
    system("cls");
}

int create_file(char filename[25], char content[256])
{
    int status = 0;
    FILE *fp = fopen(filename, "a");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        fprintf(fp, "%s\n", content);
        status = 1;
    }
    fclose(fp);

    return status;
}

int read_file(char filename[25], char content[256])
{
    int status = 0;
    FILE *fp = fopen(filename, "r");
    char c[100];
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
        exit(1);
    }
    else
    {
        while (fgets(c, sizeof(c), fp))
        {
            if (strstr(c, content))
            {
                status = 1;
                break;
            }
        }
    }

    fclose(fp);

    return status;
}

void query_c_files(char filename[25])
{
    char name[256];
    int age;
    char cpf[60];
    int active;
    int counter = 1;

    FILE *fp = fopen(filename, "r");
    char c;
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    bool password = false;

    while (fscanf(fp, "%s %d %s %d", name, &age, cpf, &active) == 4)
    {

        printf("Consulta: %d\n\n", counter);
        printf("Nome: %s\n", name);
        printf("Idade: %d anos\n", age);
        printf("CPF: %s\n", cpf);
        (active == 1) ? printf("Ativo? Sim\n") : printf("Ativo? Nao\n");
        puts("-----------------------------------------------------------");

        counter++;
    }
    fclose(fp);
}

void query_w_files(char filename[25])
{
    char name[256];
    char role[256];
    float payment;
    int counter = 1;

    FILE *fp = fopen(filename, "r");
    char c;
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    bool password = false;

    while (fscanf(fp, "%s %s %f", name, role, &payment) == 3)
    {

        printf("Consulta: %d\n\n", counter);
        printf("Nome: %s\n", name);
        printf("Cargo: %s\n", role);
        printf("Salario: %0.2f\n", payment);
        puts("-----------------------------------------------------------");

        counter++;
    }
    fclose(fp);
}

void query_users_files(char filename[25])
{
    FILE *fp = fopen(filename, "r");
    char name[256];
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    while (fscanf(fp, "%s %*s", name) == 1)
    {
        {
            printf("Usuario: %s\n", name);
        }
    }

    fclose(fp);
}

void file_capex(float valor_pc, float valor_monitores, float valor_mesas, float valor_cadeiras, float valor_outros, float total_CAPEX)
{
    FILE *fp = fopen("relatories\\RelatorioCapex.txt", "w+");
    fprintf(fp, "|------------------------------------------------------|\n");
    fprintf(fp, "|                 RELATÓRIO CAPEX                      |\n");
    fprintf(fp, "|------------------------------------------------------|\n\n");

    fprintf(fp, "|Computadores\n");
    fprintf(fp, "  -Marca: DELL\n");
    fprintf(fp, "  -Modelo: Inspiron 15 3000 i5-1135G7 \n");
    fprintf(fp, "  -Quantidade: 5\n");
    fprintf(fp, "  -Fornecedor: Dell Computadores do Brasil Ltda\n");
    fprintf(fp, "  -Valor: R$ %2.0f \n\n", valor_pc);

    fprintf(fp, "|Monitores\n");
    fprintf(fp, "  -Marca: LG\n");
    fprintf(fp, "  -Modelo: Monitor LG 19.5' LED HD \n");
    fprintf(fp, "  -Quantidade: 5\n");
    fprintf(fp, "  -Fornecedor: Amazon.com, Inc.\n");
    fprintf(fp, "  -Valor: R$ %0.2f \n\n", valor_monitores);

    fprintf(fp, "|Mesas\n");
    fprintf(fp, "  -Quantidade: 5\n");
    fprintf(fp, "  -Dimensões: 2.5m x 1.20m \n");
    fprintf(fp, "  -Fornecedor: MADEIRAMADEIRA COMERCIO ELETRONICO S/A \n");
    fprintf(fp, "  -Valor: R$ %2.0f \n\n", valor_mesas);

    fprintf(fp, "|Cadeiras\n");
    fprintf(fp, "  -Quantidade: 5\n");
    fprintf(fp, "  -Fornecedor: LOJAS AMERICANAS S.A. \n");
    fprintf(fp, "  -Valor: R$ %2.0f \n\n", valor_cadeiras);

    fprintf(fp, "|Outros\n");
    fprintf(fp, "  -Valor: R$ %2.0f \n\n", valor_outros);
    fprintf(fp, "|TOTAL CAPEX\n");
    fprintf(fp, "   R$ %0.02f \n\n", total_CAPEX);
    

    fclose(fp);
    wait_for_input("O arquivo foi criado com sucesso!\n");
}

void file_opex(float aluguel,float agua,float energia,float limpeza,float internet,float total_servicos,float impostos,float salario_adm,float salario_com,float salario_ope,float total_salarios,float total_OPEX)
{
    FILE *fp = fopen("relatories\\RelatorioOPEX.txt", "w+");
    fprintf(fp, "|------------------------------------------------------|\n");
    fprintf(fp, "|                 RELATÓRIO OPEX                       |\n");
    fprintf(fp, "|------------------------------------------------------|\n\n");

    fprintf(fp, "|Aluguel\n");
    fprintf(fp, "  Endereço: R. dos Pardais - Vila Tatetuba, São J. Campos - 12220-600\n");
    fprintf(fp, "  Valor: R$ %0.02f \n\n", aluguel);
// Serviços  
    fprintf(fp, "|Água e Saneamento\n");
    fprintf(fp, "  Distribuidora: CIA. DE SANEAMENTO BÁSICO DO ESTADO DE SÃO PAULO – SABESP\n");
    fprintf(fp, "  Valor: R$ %0.02f \n\n", agua);
// Serviço de distruibição de Energia
    fprintf(fp, "|Distribuição de Energia\n");
	fprintf(fp, "  Distribuidora:  EDP ENERGIAS DO BRASIL S.A\n");
    fprintf(fp, "  Valor: R$ %0.02f \n\n", energia);
    
//Serviço dfp, e limpeza
	fprintf(fp, "|Serviço de Limpeza\n");
	fprintf(fp, "  Distribuidora: Milclean Comércio e Serviços \n");
    fprintf(fp, "  Valor: R$ %0.02f \n\n", limpeza);

//Sefrviço dfp, e Internet
	fprintf(fp, "|Serviço de Internet\n");
	fprintf(fp, "  Distribuidora:  Telefônica Brasil S/A VIVO\n");
    fprintf(fp, "  Valor: R$ %0.02f \n\n", internet);
    fprintf(fp, "*|Total Valor de Serviços: R$ %0.02f|* \n\n",total_servicos);
    
// salarios fp, 
	fprintf(fp, "|Salários\n");
	fprintf(fp, "  Administrativo: R$ %0.02f \n",salario_adm);
    fprintf(fp, "  Comercial R$ %0.02f \n", salario_com);
    fprintf(fp, "  Operacional: R$ %0.02f \n", salario_ope);
	fprintf(fp, "|Total: R$ %0.02f| \n\n", total_salarios);
// impostos 
	fprintf(fp, "|Impostos\n");
	fprintf(fp, "  Valor: R$ %0.02f| \n\n", impostos);

	fprintf(fp, "|TOTAL OPEX\n");
 	fprintf(fp, "   R$ %0.02f \n\n", total_OPEX);

    fclose(fp);
    wait_for_input("O arquivo foi criado com sucesso!\n");
}