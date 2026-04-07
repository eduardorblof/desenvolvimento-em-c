#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
    int tamanho;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
    p->tamanho = 0;
}

int estaVazia(Pilha* p) { return p->topo == NULL; }

void push(Pilha* p, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memória insuficiente!\n");
        return;
    }
    novo->dado = valor;
    novo->proximo = p->topo;
    p->topo = novo;
    p->tamanho++;
    printf("Push: %d\n", valor);
}

int pop(Pilha* p) {
    if (estaVazia(p)) {
        printf("Erro: pilha vazia!\n");
        return -1;
    }
    No* temp = p->topo;
    int valor = temp->dado;
    p->topo = temp->proximo;
    free(temp);
    p->tamanho--;
    printf("Pop: %d\n", valor);
    return valor;
}

int peek(Pilha* p) {
    if (estaVazia(p)) {
        printf("Erro: pilha vazia!\n");
        return -1;
    }
    return p->topo->dado;
}

int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int *answer;
    answer = (int *) malloc (sizeof(int)*pricesSize);

    register int i = 0;
    int idx;

    
    Pilha p;
    inicializar(&p);

    for(i = 0; i < pricesSize; i++){
        answer[i] = prices[i];

         while(!estaVazia(&p) && prices[peek(&p)] >= prices[i]){
        idx = pop(&p);
        answer[idx] = prices[idx] - prices[i];
    }
    push(&p, i);

    }

    *returnSize = pricesSize;
    return answer;
}