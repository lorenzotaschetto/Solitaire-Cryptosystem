#include "lista.h"
#include "cripto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *normaliza_msg(char *line)
{
	int i, j;
	
	for ( i = 0, j; line[i] != '\0'; ++i) 
   {
      while (!(line[i] >= 'a' && line[i] <= 'z') && !(line[i] >= 'A' && line[i] <= 'Z') && !(line[i] == '\0')) 
      {
         for (j = i; line[j] != '\0'; ++j)
         {
            line[j] = line[j + 1];
         }
         line[j] = '\0';
      }
   }
   for(i=0; line[i] != '\0'; i++)
   	line[i]=toupper(line[i]);
   return line;
}

char cria_cifra_final(char *msg, Lista *baralho, int i)
{
   int chave, chaveFinal;
	char cifra;
	chave = pegar_chave(baralho);
   if(chave > 26)
      chave = chave - 26;
	chaveFinal = (chave + (msg[i]-'A'+1))%27;
	cifra = chaveFinal+'A'-1;
   //printf("Cifra final: %c\n", cifra);
   return cifra;
}

char descriptografa(char *msg, Lista *baralho,int i)
{
   int chave, chaveFinal;
   char cifra;
   chave = pegar_chave(baralho);
   if(chave > 26)
      chave = chave - 26;
   chaveFinal = (msg[i]-'A') - chave;
   if(chaveFinal < 0)
      chaveFinal += 27;
   cifra = chaveFinal+'A';
   //printf("Cifra final: %c\n", cifra);
   return cifra;
}

int main()
{
   char msg[256];
   printf("Digite a mensagem a ser criptografada: ");
   scanf("%s", msg);

   Lista* baralho = cria_baralho();
   normaliza_msg(msg);
   printf("Mensagem normalizada: %s\n", msg);
   for(int i=0; i<strlen(msg); i++)
   {
      baralho = criptografa(msg, baralho);
      msg[i] = cria_cifra_final(msg, baralho,i);
   }
   
   printf("Mensagem criptografada: %s\n", msg);
   
   baralho = cria_baralho();
   for(int i=0; i<strlen(msg); i++)
   {
      baralho = criptografa(msg, baralho);
      msg[i] = descriptografa(msg, baralho,i);
   }

   printf("Mensagem descriptografada: %s\n", msg);
   
   return 0;
}
