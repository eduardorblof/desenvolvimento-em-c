#include <math.h>
#define VALOR_MAX 100001

typedef struct {
    int data[VALOR_MAX];
    int top;
} Pilha;

void init(Pilha *p)        { p->top = -1; }
int  empty(Pilha *p)       { return p->top == -1; }
int  full(Pilha *p)        { return p->top == VALOR_MAX - 1; }
void push(Pilha *p, int x) { if (!full(p))  p->data[++p->top] = x; }
int  pop(Pilha *p)         { if (!empty(p)) return p->data[p->top--]; return -1; }
int  peek(Pilha *p)        { if (!empty(p)) return p->data[p->top];   return -1; }

int largestRectangleArea(int *heights, int heightsSize) {
    int area = 0;

    Pilha p;
    init(&p);

    for (int i = 0; i <= heightsSize; i++) {
        int cur = (i == heightsSize) ? 0 : heights[i];

        while (!empty(&p) && heights[peek(&p)] > cur) {
            int idx    = pop(&p);
            int height = heights[idx];
            int left   = empty(&p) ? -1 : peek(&p);
            int right  = i;
            int a      = height * (right - left - 1);
            if (a > area) area = a;
        }

        push(&p, i);
    }

    return area;
}