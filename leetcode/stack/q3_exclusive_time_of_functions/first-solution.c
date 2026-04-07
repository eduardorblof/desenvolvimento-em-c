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

int retorna_pos(char* s) {
    int pos = strcspn(s, ":");
    return pos;
}

int retorna_id(char* s) {
    char id[100];
    int pos = retorna_pos(s);
    strncpy(id, s, pos);
    id[pos] = '\0';

    return atoi(id);
}
bool retorna_status(char* s) {
    char substr[100];
    char temp[100];
    int pos = retorna_pos(s);

    strncpy(substr, s + pos + 1, strlen(s));
    substr[strlen(s) - pos - 1] = '\0';

    pos = retorna_pos(substr);
    strncpy(temp, substr, pos);
    temp[pos] = '\0';

    return strcmp(temp, "start") == 0;
}
int retorna_timestamp(char* s) {
    char substr[100];
    char temp[100];
    int pos = retorna_pos(s);

    strncpy(substr, s + pos + 1, strlen(s));
    substr[strlen(s) - pos - 1] = '\0';

    pos = retorna_pos(substr);
    strncpy(temp, substr + pos + 1, strlen(substr));
    temp[strlen(substr) - pos - 1] = '\0';

    return atoi(temp);
}

int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    int id, timestamp, prev;
    prev = 0;
    timestamp = 0;
    bool status;

    Pilha p;
    inicializar(&p);

    int* exec_time = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < logsSize; i++) {
        id = retorna_id(logs[i]);
        status = retorna_status(logs[i]);
        timestamp = retorna_timestamp(logs[i]);

        if (status) {
            if(!estaVazia(&p)){
                exec_time[peek(&p)] += timestamp- prev;
            }
            push(&p, id);
            prev = timestamp;
        } else {
            exec_time[pop(&p)] += timestamp - prev + 1;
            prev = timestamp + 1;
        }

    }
    *returnSize = n;
    return exec_time;
}