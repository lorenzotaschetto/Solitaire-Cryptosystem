#include "lista.h"
#include "cripto.h"
#include <stdio.h>
#include <stdlib.h>

Lista* cria_lista(int inicial)
{
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->info = inicial;
    l->prox = NULL;
    return l;
}

int lista_vazia(Lista *l)
{
    return (l == NULL);
}

void insere_elem(Lista *l, int elem)
{
    Lista *novo = cria_lista(elem);

    while(l->prox != NULL)
        l = l->prox;
    l->prox = novo;
}

void printa_lista(Lista *l)
{
    while(l != NULL)
    {
        printf("%d ", l->info);
        l = l->prox;
    }
    printf("\n");
}


void empurra_elem(Lista *lista, int elem, int n)
{
    Lista *inicio = lista;
    Lista *aux = lista; // aux eh o ponteiro da carta a ser movida

    //achar a carta
    while (aux->info != elem)
    {
        aux = aux->prox;
    }
    // remover a carta da lista
    if(aux != lista) 
    {
        while (lista->prox != aux)
        {
            lista = lista->prox;
        }
        lista->prox = aux->prox;

        // mover
        for (int i = 0; i < n; i++) 
        {
            //if final da lista voltar pro inicio
            if (lista->prox == NULL)
            {
                lista = inicio;
                continue;
            }

            //se nao for o ultimo elemento
            lista = lista->prox;

        }

        // recoloco a carta
        aux->prox = lista->prox;
        lista->prox = aux;
    }
    else
    { //se a carta do topo é a que está sendo procurada, deve-se só mexer ela
        for (int i = 0; i <n; i++) 
        {
            int auxiliar = lista->info;
            lista->info = lista->prox->info;
            lista->prox->info = auxiliar;
            lista = lista->prox;
        }

    }
}

//pega a posição da carta na lista
int index_elem(Lista* lista, int elem)
{
    int cont = 0;
    while (lista->info != elem)
    {
        lista = lista->prox;
        cont++;
    }
    return cont;
}

//a partir de uma posição da lista, acha a carta que ali está
Lista* lista_at(Lista* lista, int n)
{
    for (int i = 0; i < n; i++)
    {
        lista = lista->prox;
    }
    return lista;
}