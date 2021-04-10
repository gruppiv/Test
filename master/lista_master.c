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
#include "lista_master.h"

/* Retorna um nó com o dado da entrada */
no *cria(item dado) {
      no *x = malloc(sizeof(no));
      
      x->dado = dado; //(*x).dado = dado;
      x->prox = NULL; //(*x).prox = NULL; todo nó novo apontará para NULL 

      return x;
}

/* Libera a memória utilizada pelo nó de entrada*/
void exclui(no *x) {
      free(x);
}

/* Imprime a lista ligada de entrada */
void imprime_lista(no *cabeca) {
      for(no *tmp = cabeca; tmp != NULL; tmp = tmp->prox)
            imprime(tmp->dado);
      
      /*
      no *tmp = cabeca;
      
      while (tmp != NULL) {
            imprime(tmp->dado);
            tmp = tmp->prox;
      }
      */
      printf("\n");
}

/* Busca um nó na lista ligada de entrada que possua o dado de entrada 
   e retorna o nó encontrado*/
no *busca(no *cabeca, item dado) {
      for(no *tmp = cabeca; tmp != NULL; tmp = tmp->prox)
            if (tmp->dado == dado)
                  return tmp;
      return NULL;
}

/* Busca um nó na lista ligada de entrada que possua o dado de entrada 
   de maneira recursiva e retorna o nó encontrado*/
no *busca_rec(no *cabeca, item dado) {
      if (cabeca == NULL) return NULL;

      if (cabeca->dado != dado){
            return busca_rec(cabeca->prox, dado);
      }
      return cabeca;
}

/* Retorna o nó que se encontra no final da lista ligada de entrada */
no *final(no *cabeca) {
      if (cabeca == NULL) return NULL;
      no *tmp = cabeca;
      //sempre que temos uma flecha temos que ter a garantia de que o valor
      //       (*tmp).prox  que parte não é NULL ou impróprio!!
      for(tmp; tmp->prox != NULL; tmp = tmp->prox);

      return tmp;
}

/* Retorna uma lista ligada copiada da entrada */
no * copia_lista (no * cabeca){
      if (cabeca == NULL) return NULL;
      no * tmp1 = cabeca; 
      no * nova_cabeca = cria(cabeca->dado);
      no * tmp2 = nova_cabeca;

      while (tmp1 != NULL){
            tmp1 = tmp1->prox;
            if (tmp1 == NULL) return nova_cabeca;
            tmp2->prox = cria(tmp1->dado);
            tmp2 = tmp2->prox;
      }

      no * nova_cabeca = cria(cabeca->dado);
      nova_cabeca->prox = copia_lista(cabeca->prox);
      return nova_cabeca;
}

/* Remove o nó seguinte a x da entrada e retorna o valor removido */
no * remove_apos (no *x){
      if (x->prox == NULL) return NULL;
      no * tmp = x->prox;
      x->prox = tmp->prox;
      return tmp; 
}

/* Insere um nó x da entrada no início da lista ligada da entrada */
void insere_inicio    (no **p_cabeca, no *x){
     x->prox = *p_cabeca;
     *p_cabeca = x;
}

/* Insere um nó x da entrada no final da lista ligada da entrada */
void insere_final     (no **p_cabeca, no *x){
      x->prox = NULL;
      if (*p_cabeca == NULL) *p_cabeca = x;
      else{
            no * f = final(*p_cabeca);
            f->prox = x;
      }
}

/* Remove o primeiro nó da lista ligada da entrada */
no * remove_inicio    (no **p_cabeca){
      if (*p_cabeca == NULL) return NULL;
      no * tmp = *p_cabeca;
      *p_cabeca= tmp->prox;
      return tmp; 
}

/* Remove o último nó da lista ligada da entrada */
no * remove_final     (no **p_cabeca){
      if(*p_cabeca == NULL) return NULL;
      
      no * ant = *p_cabeca;
      if (ant->prox == NULL){
            *p_cabeca = NULL;
            return ant;
      }

      no * act = ant->prox;

      while(act->prox != NULL){
            ant = act;
            act = act->prox;
      }

      ant->prox = NULL;
      return act;
}

/* A lista do segundo argumento será adicionado ao final da lista
   do primeiro argumento */
void junta_listas (no **p_cabeca, no *segunda){
      if (*p_cabeca == NULL){ 
            *p_cabeca = segunda;
            return;
      }

      no * f = final(*p_cabeca);
      f->prox = segunda;
}

/*  */
no * maximo (no * cabeca){
      if (cabeca == NULL) return NULL;
      
      if (cabeca->prox == NULL) return cabeca;

      no *max = cabeca;
      no *tmp = max->prox;

      do{
            if(tmp->dado > max->dado){
                  max = tmp;
                  tmp = tmp->prox;
            }
      } while(tmp != NULL);
      
      return max;
}

/*  */
void insere_na_ordem (no **p_cabeca, no *x){
      if (*p_cabeca == NULL) *p_cabeca = x;

      if ( (*p_cabeca)->prox == NULL) insere_final(p_cabeca, x);

      no * ant = *p_cabeca;
      no * dps = ant->prox;

      if (x->dado <= ant->dado && x->dado <= dps->dado){ 
            insere_inicio(p_cabeca, x);
            return;
      }

      do{
            if (x->dado >= ant->dado && x->dado <= dps->dado){
                  ant->prox = x;
                  x->prox = dps;
                  return;
            }
            ant = ant->prox;
            dps = dps->prox;
      } while(dps != NULL);

      insere_final(p_cabeca, x);
}

 
/* Remove todos os nós da lista ligada da entrada
   que possuem o respectivo dado da entrada */
void remove_todos     (no **p_cabeca, item dado);

/* remove_todos só que recursivo */
void remove_todos_rec (no **p_cabeca, item dado);


void inverte          (no **p_cabeca);
void inverte_rec      (no **p_cabeca);