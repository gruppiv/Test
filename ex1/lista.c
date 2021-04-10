/* 
############################################################################
###                                                                      ###
###                                                                      ###
###    ATENÇÃO:                                                          ###
###                                                                      ###
###    Não mudar nada desse arquivo, exceto onde estiver indicado com    ###
###                                                                      ### 
###    // ... seu código aqui.                                           ###
###                                                                      ###
###                                                                      ###
############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "lista.h"

no *cria(item dado) {
      no *x = malloc(sizeof(no));
      
      x->dado = dado; //(*x).dado = dado;
      x->prox = NULL; //(*x).prox = NULL; todo nó novo apontará para NULL 

      return x;
}
  
void exclui(no *x) {
      free(x);  
}

void imprime_lista(no *cabeca) {
  no *tmp = cabeca;
  
  while (tmp != NULL) {
    imprime(tmp->dado);
    tmp = tmp->prox;
  }

  printf("\n");
}

no *busca(no *cabeca, item dado) {
      for(no *tmp = cabeca; tmp != NULL; tmp = tmp->prox)
            if (tmp->dado == dado)
                  return tmp;
      return NULL;
}

no *busca_rec(no *cabeca, item dado) {
      if (cabeca == NULL) return NULL;

      if (cabeca->dado != dado){
            return busca_rec(cabeca->prox, dado);
      }
      return cabeca;
}

no *final(no *cabeca) {
      if (cabeca == NULL) return NULL;
      no *tmp = cabeca;
      
      for(tmp; tmp->prox != NULL; tmp = tmp->prox);

      return tmp;
}
