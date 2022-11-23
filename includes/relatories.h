#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

float sum_payment()
{
    float result = 0;
    float payment;
    FILE *fp = fopen("files\\workers.txt", "r");

    while (fscanf(fp, "%*s %*s %f", &payment) == 1)
    {
        result += payment;
    }
    fclose(fp);
    return result;
}

float sum_services()
{
    float result = 0;
    float services;
    int count = 0;
    FILE *fp = fopen("files\\infrastructure.txt", "r");

    while (fscanf(fp, "%*s %f", &services) == 1)
    {
        if (count != 0)
        {

            if (count > 4)
                break;
            result += services;
        }
        count++;
    }
    fclose(fp);
    return result;
}

float *rent_and_tax()
{
    FILE *fp = fopen("files\\infrastructure.txt", "r");

    float rent;
    float tax;
    static float result[2];

    fscanf(fp, "%*s %f\n%*s %*f\n%*s %*f\n%*s %*f\n%*s %*f\n%f\n%*f", &rent, &tax);
    fclose(fp);
    result[0] = rent;
    result[1] = tax;
    return result;
}

float sum_opex()
{
    struct Storage item;
    float result = 0;

    FILE *fp = fopen("files\\items.txt", "r");
    while (fscanf(fp, "%*d %*s %*s %*s %d %f", &item.amount, &item.price) == 2)
    {
        result += (item.amount * item.price);
    }
    fclose(fp);
    return result;
}

float sum_capex()
{
    float result;
    FILE *fp = fopen("files\\infrastructure.txt", "r");

    fscanf(fp, "%*s %*f\n%*s %*f\n%*s %*f\n%*s %*f\n%*s %*f\n%*f\n%f", &result);
    fclose(fp);
    return result;
}