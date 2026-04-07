#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Nodo {
    int dado;
    struct Nodo *prox;
} Nodo;

typedef struct {
    Nodo *topo;
    int tamanho;
} Pilha;


void criar(Pilha *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

int isEmpty(Pilha *p) {
    return p->topo == NULL;
}

int push(Pilha *p, int x) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (!novo) return 0;        
    novo->dado = x;
    novo->prox = p->topo;       
    p->topo = novo;             
    p->tamanho++;
    return 1;
}

int pop(Pilha *p, int *x) {
    if (isEmpty(p)) return 0;  
    Nodo *tmp = p->topo;
    *x = tmp->dado;
    p->topo = tmp->prox;        
    free(tmp);
    p->tamanho--;
    return 1;
}

bool eh_operador(char* s){
    return !strcmp(s, "+") || !strcmp(s, "-") || !strcmp(s, "*") || !strcmp(s, "/");
}

int opera(Pilha *p, char *s){
    int a, b;
    pop(p, &a);
    pop(p, &b);
    if (!strcmp(s, "+"))
        return a + b;
    else if (!strcmp(s, "-"))
        return b - a;
    else if (!strcmp(s, "*"))
        return a * b;
    else
        return b / a;
}

int evalRPN(char** tokens, int tokensSize) {
    int ans;
    ans = 0;
    Pilha op;
    criar(&op);

    for(int i = 0; i < tokensSize; i++){

        if (!eh_operador(tokens[i])){
            push(&op, atoi(tokens[i]));
        } else {
            ans = opera(&op, tokens[i]);
            push(&op, ans);
        }
    }

    pop(&op, &ans);
    return ans;
     

   

}