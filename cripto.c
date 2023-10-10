#include "cripto.h"
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista * criptografa(char *msg, Lista *baralho)
{
    do
    {
        //printf("Baralho original: ");
        //printa_lista(baralho);

        empurra_elem(baralho, 53, 1);
        empurra_elem(baralho, 54, 2);
            
        //printf("Baralho empurrado: ");
        //printa_lista(baralho);

        baralho = corte_triplo(baralho, 53, 54); 
        //printf("Corte triplo: ");
        //printa_lista(baralho);

        baralho = corte_contado(baralho);
        //printf("Corte contado: ");
        //printa_lista(baralho);

        //printf("Chave: ");
        //printf("%d\n", pegar_chave(baralho));
    }while(pegar_chave(baralho) == 53 || pegar_chave(baralho) == 54 );   
    return baralho;
}

Lista* cria_baralho()
{
    Lista* l = cria_lista(1);
    for (int i = 2; i <= 54; i++)
    {
        insere_elem(l, i);
    }
    return l;
}

int pega_num_carta(int index)
{
    if(index == 53 || index == 54)
    {
        return 53;
    }
    return index;
}

int pegar_chave(Lista* baralho)
{
    int cartas_puladas = pega_num_carta(baralho->info);//olha o valor da primeira carta

    Lista* carta_selecionada = lista_at(baralho, cartas_puladas);//pega a carta chave
    return carta_selecionada->info;
} 

Lista* corte_contado(Lista* baralho)
{
    Lista* carta_a = lista_at(baralho, 53);//pega o valor da última carta

    // achar as extremidades da parte cortada
    Lista* inicio_p = baralho;
    Lista* fim_p = lista_at(baralho, pega_num_carta(carta_a->info)-1);
    
    // achar as extremidades do baralho
    Lista* fim_b = lista_at(baralho, 52);
    Lista* inicio_b = fim_p->prox;

    // arrumar referencias
    fim_b->prox = inicio_p;
    fim_p->prox = carta_a;
    return inicio_b;
}

Lista* corte_triplo(Lista *baralho, int c1, int c2)
{
    // achar qual e o primeiro
    int idx_c1 = index_elem(baralho, c1);
    int idx_c2 = index_elem(baralho, c2);
    if(idx_c1 < idx_c2)
    {
        int aux = idx_c1;
        idx_c1 = idx_c2;
        idx_c2 = aux;
    }
    Lista* c1_ptr = lista_at(baralho, idx_c1);
    Lista* c2_ptr = lista_at(baralho, idx_c2);
    // separar montes
    Lista *inicio_p1 = c1_ptr->prox;
    Lista *inicio_p2 = baralho;

    // remover o final do p2
    Lista *aux = inicio_p2;
    if(aux != NULL)
    {
        while (aux->prox != c2_ptr)
        {
            aux = aux->prox;
        }
        aux->prox = NULL;
    }
    // mover p2
    c1_ptr->prox = inicio_p2;
  
    // mover p1
    Lista* ultimo_p1 = inicio_p1;
    if(ultimo_p1 != NULL)
    {
        while(ultimo_p1->prox != NULL)
        {
            ultimo_p1 = ultimo_p1->prox;
        }
        ultimo_p1->prox = c2_ptr;
    }
    if(inicio_p1 != NULL)
    {
        return inicio_p1;
    }
    else
    {
        return c2_ptr;
    }
}
   
