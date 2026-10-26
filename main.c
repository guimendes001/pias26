#include <stdio.h>
#define qp 6

int escolha = 0;
char pzs[qp][20] = {"marguerita", "calabresa", "frango", "peperoni", "4 queijos", "milho com bacon"};
char pzd[qp][20] = {"sensacao", "dois amores", "prestigio", "banoffe", "ferrero roche", "romeu e julieta"};
char bbs[qp][20] = {"coca-cola", "sprite", "guarana", "fanta laranja", "fanta uva", "tubaina"};        
float precops[qp] = {75.90, 75.90, 75.90, 75.90, 75.90, 75.90};
float precopd[qp] = {75.90, 75.90, 75.90, 75.90, 75.90, 75.90};
float precobd[qp] = {14.90, 13.90, 13.90, 13.90, 13.90, 13.90}; 
int estoqueps[qp] = {10, 10, 10, 10, 10, 10};
int estoquepd[qp] = {10, 10, 10, 10, 10, 10};
int estoquebd[qp] = {10, 10, 10, 10, 10, 10};
int compraps[qp] = {0, 0, 0, 0, 0, 0};
int comprapd[qp] = {0, 0, 0, 0, 0, 0};
int comprabd[qp] = {0, 0, 0, 0, 0, 0};

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
    comprapd[produtodoce] = quantpd;
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
    compraps[produtosalgada] = quantps;
    estoqueps[produtosalgada] = estoqueps[produtosalgada] - quantps;
}

void mostra_bebidas(){
    for(int i = 0; i<qp; i++){
        printf("%d- %s -- %.2f\n", i, bbs[i], precobd[i]);
    }
}
void escolha_bebidas(){ 
    int produtobebidas;
    int quantbd;
    scanf("%d", &produtobebidas);
    printf("\nEscolha a quantidade: "); 
    scanf("%d", &quantbd);
    comprabd[produtobebidas] = quantbd;
    estoquebd[produtobebidas] = estoquebd[produtobebidas] - quantbd;
}

void menu(){


    
    do{
    printf("1 - Bebidas\n");
    printf("2 - Pizza doce\n");
    printf("3 - Pizza salgada\n");
    printf("0 - para sair\n");
    scanf("%d", &escolha);
    
    switch(escolha){
        case 1:
            mostra_bebidas();
            escolha_bebidas();
        }       
    }while(escolha=!0);
}


int main(){

    menu();
    while(1){
        if(escolha==1){
            mostra_bebidas();
            escolha_bebidas();
        }
        if(escolha==2){
                mostra_pizzadoce();
                escolha_pizzadoce();    
        }
        if(escolha==3){
                mostra_bebidas();
                escolha_bebidas();    
        }
        if(escolha==0){
            break;
        }
    }
    return 0;
}