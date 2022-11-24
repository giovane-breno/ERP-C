#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/**
 * Verifica se o arquivo config.txt existe.
 *
 * @returns True / False
 */
bool file_exist()
{
    bool status = false;
    FILE *fp = fopen("files\\config.txt", "r");
    if (!fp)
    {
        fclose(fp);
        status = true;
    }

    return status;
}

/**
 * Verifica o valor de register, dentro do arquivo config.txt.
 *
 * @returns True / False
 */
bool config_file()
{
    bool status = false;
    if (file_exist() == true)
    {
        FILE *fp = fopen("files\\config.txt", "a");
        fprintf(fp, "register: 1");
        fclose(fp);
        status = true;
    }
    else
    {
        FILE *fp = fopen("files\\config.txt", "r");
        char c;
        while ((c = getc(fp)) != EOF)
        {
            if (c == '1')
            {
                status = true;
            }
            else if (c == '0')
            {
                status = false;
            }
        }
    }
    return status;
}

/**
 * Altera o arquivo de configurações, de 0 para 1.
 */
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

    wait_for_input("");
}

/**
 * Cria um arquivo, de acordo com os parametros.
 *
 * @param filename deve ser um diretorio.
 * @param content deve ser um array de caracteres.
 * @param method deve ser um metodo de manipulação de arquivo.
 * @returns True / False
 */
bool create_file(char filename[25], char content[256], char method[2])
{
    bool status = false;
    FILE *fp = fopen(filename, method);
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        fprintf(fp, "%s\n", content);
        status = true;
    }
    fclose(fp);

    return status;
}

/**
 * Le um arquivo, de acordo com os parametros.
 *
 * @param filename deve ser um diretorio.
 * @param content deve ser um array de caracteres.
 * @returns True / False
 */
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

/**
 * Função para recuperar a categoria de um item.
 *
 * @param id deve ser um int
 * @returns {Array}
 */
char *getCategory(int id)
{
    int counter = 1;
    char *category = malloc(256);
    FILE *fp = fopen("files\\categories.txt", "r");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        while (fscanf(fp, "%s", category) != EOF)
        {
            if (counter == id)
            {
                fclose(fp);
                return category;
            }
            counter++;
        }
    }
    fclose(fp);
    return "Categoria nao encontrada!";
}

/**
 * Função para recuperar a o nome de um cliente cadastrado.
 *
 * @param id deve ser um int
 * @returns {Array}
 */
char *getName(int id)
{
    int counter = 1;
    char *name = malloc(256);
    FILE *fp = fopen("files\\customers.txt", "r");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        while (fscanf(fp, "%s %*d %*d %*s %*s", name) != EOF)
        {

            if (counter == id)
            {
                fclose(fp);
                return name;
            }
            counter++;
        }
    }
    fclose(fp);
    return "Cliente nao encontrado!";
}

/**
 * Pesquisar os usuarios cadastrados.
 *
 * @param filename deve ser um diretorio.
 */
void query_users_file(char filename[25])
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

/**
 * Imprime os dados da infraestrutura da empresa, previamente cadastrados no arquivo.
 *
 * @param filename deve ser um diretorio.
 */
void query_infra_files(char filename[25])
{
    struct Infrastructure infrastructure;

    FILE *fp = fopen(filename, "r");
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

/**
 * Imprime os dados da infraestrutura da empresa, previamente cadastrados no arquivo.
 *
 * @param filename deve ser um diretorio.
 */
void query_storage_files(char filename[25], int minimalist)
{

    struct Storage item;
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        if (minimalist == 0)
        {
            while (fscanf(fp, "%d %s %s %s %d %f", &item.category, item.supplier, item.brand, item.model, &item.amount, &item.price) == 6)
            {

                add_whitespace(item.supplier);
                add_whitespace(item.brand);
                add_whitespace(item.model);

                printf("* %s\n", getCategory(item.category));
                printf("Fornecedor: %s\n", item.supplier);
                printf("Marca: %s\n", item.brand);
                printf("Modelo: %s\n", item.model);
                printf("Quantidade: %d\n", item.amount);
                printf("Valor Unitario: R$ %0.2f\n", item.price);
                printf("Valor Total: R$ %0.2f\n", (item.amount * item.price));
                printf("------------------------------------------------------\n");
            }
        }
        else
        {
            float total = 0;
            while (fscanf(fp, "%d %*s %*s %*s %d %f", &item.category, &item.amount, &item.price) == 3)
            {
                printf("* %s\n", getCategory(item.category));
                printf("R$ %0.2f\n\n", (item.amount * item.price));

                total += (item.amount * item.price);
            }

            printf("TOTAL CAPEX -> R$ %0.2f\n\n", total);
        }
    }
    fclose(fp);
}

/**
 * Imprime os dados do relatorio capex, é feito um loop dentro do arquivo de itens para recuperar os dados.
 *
 * @param filename deve ser um diretorio.
 */
void file_capex(char filename[25])
{
    struct Storage item;
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        float total_capex = 0;
        ;
        FILE *fp1 = fopen("relatories\\RelatorioCapex.txt", "w+");
        fprintf(fp1, "|------------------------------------------------------|\n");
        fprintf(fp1, "|                 RELATÓRIO CAPEX                      |\n");
        fprintf(fp1, "|------------------------------------------------------|\n\n");

        while (fscanf(fp, "%d %s %s %s %d %f", &item.category, item.supplier, item.brand, item.model, &item.amount, &item.price) == 6)
        {

            add_whitespace(item.supplier);
            add_whitespace(item.brand);
            add_whitespace(item.model);

            fprintf(fp1, "* %s\n", getCategory(item.category));
            fprintf(fp1, "  Fornecedor: %s\n", item.supplier);
            fprintf(fp1, "  Marca: %s\n", item.brand);
            fprintf(fp1, "  Modelo: %s\n", item.model);
            fprintf(fp1, "  Quantidade: %d\n", item.amount);
            fprintf(fp1, "  Valor Unitario: R$ %0.2f\n", item.price);
            fprintf(fp1, "  Valor Total: R$ %0.2f\n\n", (item.amount * item.price));

            total_capex += (item.amount * item.price);
        }

        fprintf(fp1, "* TOTAL CAPEX:\n");
        fprintf(fp1, "  R$ %0.02f \n\n", total_capex);

        fclose(fp);
        fclose(fp1);
    }

    wait_for_input("O arquivo foi criado com sucesso!\n");
}

/**
 * Imprime os dados do relatorio opex, eles são recuperados por meio de um unico comando.
 *
 * @param filename deve ser um diretorio.
 */
void file_opex(char filename[25])
{
    struct Infrastructure infrastructure;
    float payment = sum_payment();
    float services = sum_services();

    FILE *fp = fopen(filename, "r");
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

/**
 * Função para recuperar os dados do usuario e organizar do arquivo de armazenamento.
 *
 * @param filename deve ser um diretorio.
 * @param minimized deve ser true ou false.
 */

void query_customers_file(char filename[25], bool minimized)
{
    char name[256];
    int age;
    char cpf[60];
    char cep[60];

    int gender;

    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        if (minimized == false)
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
            int counter = 1;
            printf("* LISTA DE CLIENTES *\n");
            while (fscanf(fp, "%s %*d %*d %*s %*s", name) == 1)
            {
                add_whitespace(name);
                printf("ID: %d | %s\n", counter, name);
                counter++;
            }
        }
    }

    fclose(fp);
}

/**
 * Função para recuperar os dados do perfil de usuario do arquivo de armazenamento.
 *
 * @param filename deve ser um diretorio.
 * @param id deve ser o id de um usuario.
 */
void query_p_files(char filename[25], int id)
{
    struct Profiles profile;
    bool found = false;
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }
    else
    {
        while (fscanf(fp, "%d %d %d %s %d", &profile.customer_id, &profile.domestic_or_commercial, &profile.pickup_or_delivery, profile.reason_of_buying, &profile.active) == 5)
        {
            if (profile.customer_id == id)
            {
                add_whitespace(profile.reason_of_buying);

                printf("\nID: %d | %s\n", id, getName(profile.customer_id));
                printf("\nTipo de Encomenda: ");
                (profile.domestic_or_commercial == 1) ? printf("Particular") : printf("Comercial");
                printf("\nMetodo de Entrega: ");
                (profile.pickup_or_delivery == 1) ? printf("Entregar") : printf("Retirar no Local");
                printf("\nMotivo de Compra: %s", profile.reason_of_buying);
                printf("\nCliente Ativo? ");
                (profile.active == 1) ? printf("Sim\n") : printf("Nao\n");
                found = true;
            }
        }

        if (found == false)
        {
            printf("\nPerfil de cliente nao encontrado!\n");
        }
    }
    fclose(fp);
}

/**
 * Função para recuperar os dados dos funcionarios e organizar.
 *
 * @param filename deve ser um diretorio.
 */
void query_workers_file(char filename[25])
{
    char name[256];
    char role[256];
    float payment;
    int counter = 1;

    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

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

/**
 * Função para recuperar as categorias dos itens do arquivo de armazenamento.
 *
 * @param filename deve ser um diretorio.
 * @param minimized deve ser true ou false.
 */
void query_cat_files(char filename[20], bool minimized)
{
    char category[256];

    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Erro na abertura do arquivo!");
    }

    if (minimized == false)
    {
        int counter = 1;

        while (fscanf(fp, "%s", category) == 1)
        {

            printf("ID: %d | %s\n", counter, category);

            counter++;
        }
    }

    fclose(fp);
}

bool edit_customer()
{
    struct Customers customer;
    
    FILE *fp = fopen("files\\customers.txt", "r");
    FILE *fpnew = fopen("files\\temp.txt", "w+");
    int id;
    int i = 1;
    int counter = 1;
    bool check = true;
    while (fscanf(fp, "%s %d %d %s %s", customer.name, &customer.age, &customer.gender, customer.cpf, customer.cep) == 5)
    {
        printf("ID: %d | %s\n", counter, customer.name);
        counter++;
    }
    fclose(fp);
    puts("Digite o id do user que voce quer substituir:\n");
    scanf("%d", &id);
    if (id >= counter || id <= 0){
        check = false;
    }
    fp = fopen("files\\customers.txt.txt", "r");
    while (fscanf(fp, "%s %d %d %s %s", customer.name, &customer.age, &customer.gender, customer.cpf, customer.cep) == 5)
    {
        if (i != id)
        {
            fprintf(fpnew, "%s %d %d %s %s\n", customer.name, customer.age, customer.gender, customer.cpf, customer.cep);
        }
        i++;
    }

    fclose(fp);
    fclose(fpnew);
    remove("files\\customers.txt.txt");
    rename("files\\temp.txt", "files\\customers.txt");
    return check;
}

bool edit_user(){
    struct Users user;
    
    FILE *fp = fopen("files\\logins.txt", "r");
    FILE *fpnew = fopen("files\\temp.txt", "w+");
    int id;
    int i = 1;
    int counter = 1;
    bool check = true;

    while (fscanf(fp, "%s %s", user.email, user.password) == 2)
    {
        printf("ID: %d | %s\n", counter, user.email);
        counter++;
    }
    fclose(fp);
    puts("Digite o id do user que voce quer substituir:\n");
    scanf("%d", &id);
    if (id >= counter || id <= 0){
        check = false;
    }
    fp = fopen("files\\logins.txt", "r");
    while (fscanf(fp, "%s %s", user.email, user.password) == 2)
    {
        if (i != id)
        {
            fprintf(fpnew, "%s %s\n", user.email, user.password);
        }
        i++;
    }

    fclose(fp);
    fclose(fpnew);
    remove("files\\logins.txt");
    rename("files\\temp.txt", "files\\logins.txt");
    return check;
}

bool edit_profiles(){
    struct Profiles profile;
    
    FILE *fp = fopen("files\\profiles.txt", "r");
    FILE *fpnew = fopen("files\\temp.txt", "w+");
    int id;
    int i = 1;
    int counter = 1;
    bool check = true;
    while (fscanf(fp, "%d %d %d %s %d", &profile.customer_id, &profile.domestic_or_commercial, &profile.pickup_or_delivery, profile.reason_of_buying, &profile.active) == 5)
    {
        printf("ID: %d | %s\n", counter, getName(profile.customer_id));
        counter++;
    }
    fclose(fp);
    puts("Digite o id do user que voce quer substituir:\n");
    scanf("%d", &id);
    if (id >= counter || id <= 0){
        check = false;
    }
    fp = fopen("files\\profiles.txt", "r");
    while (fscanf(fp, "%d %d %d %s %d", &profile.customer_id, &profile.domestic_or_commercial, &profile.pickup_or_delivery, profile.reason_of_buying, &profile.active) == 5)
    {
        if (i != id)
        {
            fprintf(fpnew, "%d %d %d %s %d", profile.customer_id, profile.domestic_or_commercial, profile.pickup_or_delivery, profile.reason_of_buying, profile.active);
        }
        i++;
    }
    fclose(fp);
    fclose(fpnew);
    remove("files\\profiles.txt");
    rename("files\\temp.txt", "files\\profiles.txt");
    return check;
}

bool edit_workers(){
    struct Workers worker;
    
    FILE *fp = fopen("files\\workers.txt", "r");
    FILE *fpnew = fopen("files\\temp.txt", "w+");
    int id;
    int i = 1;
    int counter = 1;
    bool check = true;

    while (fscanf(fp, "%s %s %f", worker.name, worker.role, &worker.payment) == 3)
    {
        printf("ID: %d | %s\n", counter, worker.name);
        counter++;
    }
    fclose(fp);
    puts("Digite o id do user que voce quer substituir:\n");
    scanf("%d", &id);
    if (id >= counter || id <= 0){
        check = false;
    }
    fp = fopen("files\\workers.txt", "r");
    while (fscanf(fp, "%s %s %f", worker.name, worker.role, &worker.payment) == 3)
    {
        if (i != id)
        {
            fprintf(fpnew, "%s %s %f\n", worker.name, worker.role, worker.payment);
        }
        i++;
    }

    fclose(fp);
    fclose(fpnew);
    remove("files\\workers.txt");
    rename("files\\temp.txt", "files\\workers.txt");
    return check;
}