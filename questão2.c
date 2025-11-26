#include <stdio.h>
#include <string.h>

#define QTD_PRODUTOS 5
#define QTD_MOVS 100

typedef struct {
    int codigoProduto;
    char descricaoProduto[50];
    int estoque;
} Produto;

typedef struct {
    int id;
    int codigoProduto;
    int quantidade;
    char descricao[80];
} MovEstoque;

/*· Um número identificador único.
· Uma descrição para identificar o tipo da movimentação realizada*/

Produto estoque[QTD_PRODUTOS] = {
    {101, "Caneta Azul", 150},
    {102, "Caderno Universitário", 75},
    {103, "Borracha Branca", 200},
    {104, "Lápis Preto HB", 320},
    {105, "Marcador de Texto Amarelo", 90}
};

int main() {
    MovEstoque movimentos[QTD_MOVS];
    int movs_realizadas = 0;
    int opcao;

    while(1){
        printf("\n 1 - Movimentar Estoque\n 2 - Mostrar Estoque Atual\n 0 - Sair\n Sua opção: ");
        scanf("%d", &opcao);

        if(opcao == 0)
        break;

        if(opcao == 2){
            printf("\n Estoque Atual: \n");
            for (int i = 0; i< QTD_PRODUTOS; i++)
                printf("%d - %s | Qtde: %d\n", estoque[i].codigoProduto, estoque[i].descricaoProduto, estoque[i].estoque);
            continue;

        }

        int cod, qtd, tipo;
        char desc[80];

        printf("\n Informe o código do produto: ");
        scanf("%d", &cod);
        int idx = -1;
        for (int i = 0; i < QTD_PRODUTOS; i++)
            if(estoque[i].codigoProduto == cod) idx = i;
        if (idx == -1){
            printf("Produto não existe.\n");
            continue;
        }

        printf("1 - Entrada\n 2 - Saída\n Tipo: ");
        scanf("%d", &tipo);

        printf("Quantidade: ");
        scanf("%d", &qtd);
        if (tipo == 2 && estoque[idx].estoque < qtd){
            printf("Estoque insuficiente! \n");
            continue;
        }

        printf("Descriçao da movimentação: ");
        getchar();
        fgets(desc, 80, stdin);
        desc[strcspn(desc, "\n")] = 0;

        movimentos[movs_realizadas].id = movs_realizadas + 1;
        movimentos[movs_realizadas].codigoProduto = cod;
        movimentos[movs_realizadas].quantidade = (tipo == 2 ? -qtd : qtd);
        strcpy(movimentos[movs_realizadas].descricao, desc);

        estoque[idx].estoque += movimentos[movs_realizadas].quantidade;
        printf("Movimentação registrada (ID: %d)\n", movimentos[movs_realizadas].id);
        printf("Qtde final de '%s' : %d \n", estoque[idx].descricaoProduto, estoque[idx].estoque);

        movs_realizadas++;   
    }
    return 0;
}