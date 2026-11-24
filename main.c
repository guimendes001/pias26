/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define qp 6

char cabecalho[qp][20] = {"Código     ", "Produto    ", "Valor Unit.", "Qntd.      ", "Valor Total"};
char pzs[qp][20] = {"Marguerita     ", "Calabresa      ", "Frango         ", "Peperoni       ", "4 Queijos      ", "Milho com bacon"};
char pzd[qp][20] = {"Sensação       ", "Dois Amores    ", "Prestigio      ", "Banoffe        ", "Ferrero Roche  ", "Romeu e Julieta"};
char bbs[qp][20] = {"Coca-Cola    ","Sprite       ", "Guaraná      ", "Fanta Laranja", "Fanta Uva    ", "Tubaina      "};        
float nota = 0;
float pagarbbs;    
float pagarps;
float pagarpd;
float precops[qp] = {75.90, 75.90, 75.90, 75.90, 75.90, 75.90};
float precopd[qp] = {75.90, 75.90, 75.90, 75.90, 75.90, 75.90};
float precobbs[qp] = {14.90, 13.90, 13.90, 13.90, 13.90, 13.90}; 
int estoqueps[qp] = {30, 30, 30, 30, 30, 30};
int estoquepd[qp] = {30, 30, 30, 30, 30, 30};
int estoquebd[qp] = {30, 30, 30, 30, 30, 30};
int qntdps[qp] = {0, 0, 0, 0, 0, 0};
int qntdpd[qp] = {0, 0, 0, 0, 0, 0};
int qntdbbs[qp] = {0, 0, 0, 0, 0, 0};
int codps[qp] = {101, 102, 103, 104, 105, 106};
int codpd[qp] = {107, 108, 109, 110, 111, 112};
int codbbs[qp] = {113, 114, 115, 116, 117, 118};

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void mostra_pizzadoce(){
    for(int i = 0; i<qp; i++){
        printf("%d- %s -- %.2f\n", i, pzd[i], precopd[i]);
    }
}

void escolha_pizzadoce(){ 
    int produtodoce;
    int quantpd;
    scanf("%d", &produtodoce);
    printf("\nEscolha a quantidade: ");
    scanf("%d", &quantpd);
    qntdpd[produtodoce] = quantpd;
    estoquepd[produtodoce] = estoquepd[produtodoce] - quantpd;
}

void mostra_pizzasalgada(){
    for(int i = 0; i<qp; i++){
        printf("%d- %s -- %.2f\n", i, pzs[i], precops[i]);
    }
}

void escolha_pizzasalgada(){ 
    int produtosalgada;
    int quantps;
    scanf("%d", &produtosalgada);
    printf("\nEscolha a quantidade: ");
    scanf("%d", &quantps);
    qntdps[produtosalgada] = quantps;
    estoqueps[produtosalgada] = estoqueps[produtosalgada] - quantps;
}

void mostra_bebidas(){
    for(int i = 0; i<qp; i++){
        printf("%d- %s -- %.2f\n", i, bbs[i], precobbs[i]);
    }
}
void escolha_bebidas(){ 
    int produtobebidas;
    int quantbd;
    scanf("%d", &produtobebidas);
    printf("\nEscolha a quantidade: "); 
    scanf("%d", &quantbd);
    qntdbbs[produtobebidas] = quantbd;
    estoquebd[produtobebidas] = estoquebd[produtobebidas] - quantbd;
}

void mostra_cabecalho(){
    printf("\n %s\t%s\t%s\t%s\t%s", cabecalho[0], cabecalho[1], cabecalho[2], cabecalho[3], cabecalho[4]);
}

void mostra_compraps(){
    for(int i = 0; i<qp; i++){
        if(qntdps[i] != 0){
            pagarps = qntdps[i]*precops[i];
            printf("\n %d\t\t%s\t%.2f\t\t%d\t\t%.2f", codps[i], pzs[i], precops[i], qntdps[i], pagarps);
        }
    }
}
void mostra_comprapd(){
    for(int i = 0; i<qp; i++){
        if(qntdpd[i] != 0){
            pagarpd = qntdpd[i]*precopd[i];
            printf("\n %d\t\t%s\t%.2f\t\t%d\t\t%.2f", codpd[i], pzd[i], precopd[i], qntdpd[i], pagarpd);
        }
    }
}
void mostra_comprabbs(){
    for(int i = 0; i<qp; i++){
        if(qntdbbs[i] != 0){
            pagarbbs = qntdbbs[i]*precobbs[i];
            printf("\n %d\t\t%s\t%.2f\t\t%d\t\t%.2f", codbbs[i], bbs[i], precobbs[i], qntdbbs[i], pagarbbs);
        } 
    }
}
void notafiscal(){
    float valortotal;
    if(pagarbbs > 0 || pagarpd > 0 || pagarps > 0){
        valortotal = pagarps + pagarpd + pagarbbs;
        printf("\n  TOTAL:     R$%.2f", valortotal);
    }
}
void menu(){

    int card = 0;

    do{
        printf("================= BELLA PIZZA =================\n\n");
        printf("1 - Bebidas\n");
        printf("2 - Pizza salgada\n");
        printf("3 - Pizza doce\n");
        printf("0 - para finalizar o pedido\n\n");
        printf("===============================================\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &card);
        
        limpar_tela();
        switch(card){

            case 1:
                mostra_bebidas();
                escolha_bebidas();
                limpar_tela();

                break;
            case 2:
                mostra_pizzasalgada();
                escolha_pizzasalgada();
                limpar_tela();

                break;
            case 3:
                mostra_pizzadoce();
                escolha_pizzadoce();
                limpar_tela();
                break;

        }       

    }while(card != 0);

}

int main(){

    menu();
    printf("========================= NOTA FISCAL =========================");
    //printf("\n\nCódigo\t\tProduto\t\tValor Unit.\t\tQntd.\t\tValor Total ");
    mostra_cabecalho();
    mostra_compraps();
    mostra_comprapd();
    mostra_comprabbs();
    printf("\n\n----------------------------------------------------------------");
    notafiscal();
return 0;
    
}
