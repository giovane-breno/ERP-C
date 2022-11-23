#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

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
            puts("Novos registros desativado!");
            fclose(fp);
        }
        else if (c == '0')
        {
            fclose(fp);
            FILE *fp = fopen("files\\config.txt", "w+");
            fprintf(fp, "register: 1");
            puts("Novos registros ativado!");
            fclose(fp);
        }
    }
    getch();
    system("cls");
}

int create_file(char filename[25], char content[256], char method[2])
{
    int status = 0;
    FILE *fp = fopen(filename, method);
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

void query_c_files(char filename[25], int minimized)
{
    char name[256];
    int age;
    char cpf[60];
    char cep[60];

    int gender;

    FILE *fp = fopen(filename, "r");
    char c;
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    bool password = false;

    if (minimized != 1)
    {
        int counter = 1;

        while (fscanf(fp, "%s %d %d %s %s", name, &age, &gender, cpf, cep) == 5)
        {

            printf("Consulta: %d\n\n", counter);
            printf("Nome: %s\n", name);
            printf("Idade: %d anos\n", age);
            printf("Sexo: ");
            (gender == 1) ? printf("Masculino\n") : printf("Feminino\n");
            printf("CPF: %s\n", cpf);
            printf("CEP: %s\n", cep);
            puts("-----------------------------------------------------------");

            counter++;
        }
    }
    else
    {
        int counter = 0;
        printf("* LISTA DE CLIENTES *\n");
        while (fscanf(fp, "%s %*d %*d %*s %*s", name) == 1)
        {
            printf("ID: %d | %s\n", counter, name);
            counter++;
        }
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

char *query_infra_files(char filename[25])
{
    struct Infrastructure infrastructure;

    FILE *fp = fopen(filename, "r");
    char name[256];
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        fscanf(fp, "%s %f\n%s %f\n%s %f\n%s %f\n%s %f\n%f\n%f", infrastructure.rent_adress, &infrastructure.rent_price, infrastructure.water_sender, &infrastructure.water_value, infrastructure.energy_sender, &infrastructure.energy_value, infrastructure.cleaning_sender, &infrastructure.cleaning_value, infrastructure.net_sender, &infrastructure.net_value, &infrastructure.tax, &infrastructure.total_value);

        puts("\n* ALUGUEL");
        printf("Endereco: %s", infrastructure.rent_adress);
        printf("\nValor: R$%0.2f", infrastructure.rent_price);

        puts("\n\n* AGUA E SANEAMENTO");
        printf("Distribuidora: %s", infrastructure.water_sender);
        printf("\nValor: R$%0.2f", infrastructure.water_value);

        puts("\n\n* DISTRIBUICAO DE ENERGIA");
        printf("Distribuidora: %s", infrastructure.energy_sender);
        printf("\nValor: R$%0.2f", infrastructure.energy_value);

        puts("\n\n* SERVICO DE LIMPEZA");
        printf("Distribuidora: %s", infrastructure.cleaning_sender);
        printf("\nValor: R$%0.2f", infrastructure.cleaning_value);

        puts("\n\n* SERVICO DE INTERNET");
        printf("Distribuidora: %s", infrastructure.net_sender);
        printf("\nValor: R$%0.2f", infrastructure.net_value);

        puts("\n\n* TAXAS");
        printf("Imposto: R$%0.2f", infrastructure.tax);
        printf("\nValor Total: R$%0.2f\n", infrastructure.total_value);
    }
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

void file_opex()
{
    struct Infrastructure infrastructure;
    float payment = sum_payment();
    float services = sum_services();

    FILE *fp = fopen("files\\infrastructure.txt", "r");
    char name[256];
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        fscanf(fp, "%s %f\n%s %f\n%s %f\n%s %f\n%s %f\n%f\n%f", infrastructure.rent_adress, &infrastructure.rent_price, infrastructure.water_sender, &infrastructure.water_value, infrastructure.energy_sender, &infrastructure.energy_value, infrastructure.cleaning_sender, &infrastructure.cleaning_value, infrastructure.net_sender, &infrastructure.net_value, &infrastructure.tax, &infrastructure.total_value);
        add_whitespace(infrastructure.rent_adress);
        add_whitespace(infrastructure.water_sender);
        add_whitespace(infrastructure.energy_sender);
        add_whitespace(infrastructure.cleaning_sender);
        add_whitespace(infrastructure.net_sender);
        fclose(fp);

        FILE *fp = fopen("relatories\\RelatorioOPEX.txt", "w+");
        fprintf(fp, "|------------------------------------------------------|\n");
        fprintf(fp, "|                 RELATÓRIO OPEX                       |\n");
        fprintf(fp, "|------------------------------------------------------|\n\n");

        fprintf(fp, "* ALUGUEL\n");
        fprintf(fp, "  Endereco: %s\n", infrastructure.rent_adress);
        fprintf(fp, "  Valor: R$ %0.02f \n\n", infrastructure.rent_price);

        fprintf(fp, "* AGUA E SANEAMENTO\n");
        fprintf(fp, "  Distribuidora: %s\n", infrastructure.water_sender);
        fprintf(fp, "  Valor: R$ %0.02f \n\n", infrastructure.water_value);

        fprintf(fp, "* DISTRIBUICAO DE ENERGIA\n");
        fprintf(fp, "  Distribuidora:  %s\n", infrastructure.energy_sender);
        fprintf(fp, "  Valor: R$ %0.02f \n\n", infrastructure.energy_value);

        fprintf(fp, "* SERVICO DE LIMPEZA\n");
        fprintf(fp, "  Distribuidora: %s\n", infrastructure.cleaning_sender);
        fprintf(fp, "  Valor: R$ %0.02f \n\n", infrastructure.cleaning_value);

        fprintf(fp, "* SERVICO DE INTERNET\n");
        fprintf(fp, "  Distribuidora:  %s\n", infrastructure.net_sender);
        fprintf(fp, "  Valor: R$ %0.02f \n\n", infrastructure.net_value);

        fprintf(fp, "* TOTAL DOS SERVICOS: R$ %0.02f \n\n", services);

        fprintf(fp, "* SALARIOS\n");
        fprintf(fp, "  Funcionarios: R$ %0.02f \n", payment);

        fprintf(fp, "\n* IMPOSTOS\n");
        fprintf(fp, "  Valor: R$ %0.02f| \n\n", infrastructure.tax);

        fprintf(fp, "* TOTAL OPEX:\n");
        fprintf(fp, "  R$ %0.02f \n\n", infrastructure.total_value + payment);

        fclose(fp);
        wait_for_input("O arquivo foi criado com sucesso!\n");
    }
}