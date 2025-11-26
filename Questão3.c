#include <stdio.h>
#include <time.h>

int dias_em_atraso(struct tm venc, struct tm hoje){
    time_t t_venc = mktime(&venc);
    time_t t_hoje = mktime(&hoje);
    double diff = difftime(t_hoje, t_venc);
    int dias = (int) (diff / (60 * 60 * 24));
    return (dias > 0) ? dias : 0;
}

int main(){
    double valor, multa_dia = 0.025, juros = 0.0;
    int dia, mes, ano;

    printf("Digite o valor original: R$ ");
    scanf("%lf", &valor);

    printf("Digite a data de vencimento (dia/mes/ano): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    struct tm venc = {0};
    venc.tm_mday = dia;
    venc.tm_mon = mes - 1;
    venc.tm_year = ano - 1900;

    time_t agora = time(NULL);
    struct tm *hoje_tm = localtime(&agora);
    int atraso = dias_em_atraso(venc, *hoje_tm);

    if (atraso == 0){
        printf("Pagamento está ok, não tem juros.\n");
    } else {
        juros = valor * multa_dia * atraso;
        printf("Dias em atraso: %d\n", atraso);
        printf("Juros Devidos: R$ %.2f\n", juros);
        printf("Valor total atualizado: R$ %.2f\n", valor + juros);
    }
    return 0;
}