#ifndef LISTA_H
#define LISTA_H

typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

Lista *cria_lista(int inicial);

int lista_vazia(Lista *l);

void insere_elem(Lista *l, int elem);

void empurra_elem(Lista *lista, int elem, int n);

int index_elem(Lista* lista, int elem);

Lista *lista_at(Lista *lista, int index);

void printa_lista(Lista *l);

#endif // LISTA_H
