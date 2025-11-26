#include <stdio.h>
#include <string.h>

#define QTD_VENDAS 36
#define MAX_VENDEDORES 10

typedef struct{
    char vendedor[50];
    double valor; 
} Venda;

typedef struct{
    char vendedor[50];
    double total_comissao;
} ComissaoVendedor;

/*· Vendas abaixo de R$100,00 não gera comissão

· Vendas abaixo de R$500,00 gera 1% de comissão

· A partir de R$500,00 gera 5% de comissão */

Venda vendas[QTD_VENDAS] = { 
    {"João Silva", 1200.50 }, {"João Silva", 950.75 }, {"João Silva", 1800.00 }, {"João Silva", 1400.30 }, {"João Silva", 1100.90 },
    {"João Silva", 1550.00 }, {"João Silva", 1700.80 }, {"João Silva", 250.30 }, {"João Silva", 480.75 }, {"João Silva", 320.40 },

    {"Maria Souza", 2100.40}, {"Maria Souza", 1350.60}, {"Maria Souza", 950.20}, {"Maria Souza", 1600.75}, {"Maria Souza", 1750.00}, {"Maria Souza", 1450.90},
    {"Maria Souza", 400.50}, {"Maria Souza", 180.20}, {"Maria Souza", 90.75},

    {"Carlos Oliveira", 800.50}, {"Carlos Oliveira", 1200.00}, {"Carlos Oliveira", 1950.30}, {"Carlos Oliveira", 1750.80}, {"Carlos Oliveira", 1300.60}, {"Carlos Oliveira", 300.40},
    {"Carlos Oliveira", 500.00}, {"Carlos Oliveira", 125.75},

    {"Ana Lima", 1000.00}, {"Ana Lima", 1100.50}, {"Ana Lima", 1250.75},  {"Ana Lima", 1400.20}, {"Ana Lima", 1550.90}, {"Ana Lima", 1650.00},
    {"Ana Lima", 75.30}, {"Ana Lima", 420.90}, {"Ana Lima", 315.40}

};

double calcula_comissao(double valor){
    /*Vendas abaixo de R$100,00 não gera comissão*/
    if (valor < 100.0)
        return 0.0;
    /*Vendas abaixo de R$500,00 gera 1% de comissão*/
    else if(valor < 500.0)
        return valor * 0.01;
    /*A partir de R$500,00 gera 5% de comissão*/
    else
        return valor * 0.05;
};
int main() {
    ComissaoVendedor vendedores[MAX_VENDEDORES];
    int n_vendedores = 0;

    for (int i = 0; i< QTD_VENDAS; i++){
        int encontrado = 0, idx = -1;
        
        for (int j = 0; j < n_vendedores; j++) {
            if (strcmp(vendas[i].vendedor, vendedores[j].vendedor) == 0){
                encontrado = 1;
                idx = j;
                break;
            }

        }
        double comissao = calcula_comissao(vendas[i].valor);
        if (!encontrado){
            strcpy(vendedores[n_vendedores].vendedor, vendas[i].vendedor);
            vendedores[n_vendedores].total_comissao = comissao;
            n_vendedores++;

        } else {
            vendedores[idx].total_comissao += comissao;
        }
    }
    printf("Comissão Total Por Vendedor: \n");
    for (int i = 0; i < n_vendedores; i++){
        printf("%d: R$ %.2f\n", vendedores[i].vendedor, vendedores[i].total_comissao);
    }
    return 0;
}