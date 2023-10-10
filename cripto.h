#ifndef CRIPTO_H
#define CRIPTO_H

#include "lista.h"


Lista* criptografa(char *texto, Lista *baralho);

// retorna o novo inicio
Lista* corte_triplo(Lista *baralho, int c1, int c2);

// retorna o inicio do baralho
Lista* cria_baralho();

Lista* corte_contado(Lista* baralho);

int pega_num_carta(int index);

int pegar_chave(Lista* baralho);

#endif // CRIPTO_H