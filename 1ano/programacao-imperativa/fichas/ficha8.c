#include <stdio.h>
#include <stdlib.h>


typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;


LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
return r;
}


typedef LInt Stack;

typedef struct {
    LInt inicio,fim;
} Queue;


/*
1. Apresente definicoes das funcoes habituais sobre Stacks:
• void initStack (Stack *s)
• int SisEmpty (Stack s)
• int push (Stack *s, int x)
• int pop (Stack *s, int *x)
• int top (Stack s, int *x)
*/



void initStack (Stack *s) {Stack t = malloc(sizeof(struct LInt));
    t->valor = x;
    t->prox = *s;

    return 0;
    (*s) -> valor = 0;
    (*s) -> prox = NULL;
}


int SisEmpty (Stack s) {
    return !(s);
}


int push (Stack *s, int x) {
    int r = 0;
    LInt new = newLInt(x, *s);
    if(new) *s = add;
    else r = 1;

    return r;
}

int pop (Stack *s, int *x) {
    int r = 0;

    if(SisEmpty(s)) {
        r = 1;
    } else {
        LInt first = *s;
        *x = first->valor;
        *s = (*s) ->prox;
        free(first);
    }

    return r;
}



int top (Stack s, int *x) {
    int r = 0;

    if(SisEmpty(s)) {
        r = 1;
    } else {
        while(s->prox) {
            s = s->prox;
        }

        *x = s->valor;
    }

    return r;
    
}






/*
2. Apresente definicoes das funcoes habituais sobre Queues:
• void initQueue (Queue *q)
• int QisEmpty (Queue q)
• int enqueue (Queue *q, int x)
• int dequeue (Queue *q, int *x)
• int front (Queue q, int *x)
*/

void initQueue (Queue *q) {
    
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q) {

    if(!(q.inicio && q.fim)) {
        return 1;
    } else {
        return 0;
    }
}


int enqueue (Queue *q, int x) {
    int r = 1;
    LInt new = newLInt(x, NULL);    
    
    if(new) {
        r = 0;
        if(QisEmpty(*q)) {
            q->inicio = q->fim = new;
        } else {
            q->fim = q->fim->prox = new;
        }
    }

    return r;
} 



int dequeue (Queue *q, int *x) {
    int r = 1;
    
    if(q->inicio) {
        LInt temp = q->inicio;
        r = 0;
        *x = q->inicio->valor;

        if(q->inicio == q->fim) {
            q->inicio = q->fim = NULL;
        } else {
            q->inicio = q->incio->prox;
            
        }
        free(temp);
    }
    return r;
}

int front (Queue q, int *x) {
    int r = 1;

    if(!(QisEmpty(q))) {
        r = 0;
        *x = q->inicio->valor;
    }

    return r;
}


/*
3. Apresente definicoes alternativas destas funcoes usando uma lista circular tal como referido
acima.
*/
typedef LInt QueueC;

initQueueC (QueueC *q) {
    *q = NULL;
}

int QcisEmpty (QueueC q) {
    
    return (q==NULL);
}

int enqueueC (QueueC *q, int x) {
    LInt new = newLInt(x, NULL);
    int r = 1;
    if(new) {
        r = 0;

        if(QcisEmpty(*q)) {
            (*q) -> prox = new->prox = new;
        } else {
            new->prox = (*q) -> prox;
            (*q) -> prox = new;
            *q = new;
        }
    }

    return r;
}

int dequeueC (QueueC *q, int *x) {
    int r = 1;
    
    if(q->inicio) {
        LInt first = (*q)->prox;
        r = 0;
        *x = (*q)->valor

        if(*q == (*q)->prox) {
            *q = NULL;
        } else {
            (*q) -> prox = (*q)->prox->prox;
            
        }


        free(first);
    }

    return r;

}


int frontC (QueueC *q, int *x) {

    int r = 1;

    if(*q){
        r = 0;
        *x = (*q)->valor;
    }

    return r;
}


