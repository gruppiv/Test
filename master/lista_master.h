#ifndef LISTA
#define LISTA

#include "item.h"

typedef struct s_no no;

struct s_no {
  item dado;
  no * prox;
};

no * cria             (item dado);
void exclui           (no *x);
void imprime_lista    (no *cabeca);
no * busca            (no *cabeca, item dado);
no * busca_rec        (no *cabeca, item dado);
no * final            (no *cabeca);
no * copia_lista      (no * cabeca);
no * remove_apos      (no *x);

void insere_inicio    (no **p_cabeca, no *x);
void insere_final     (no **p_cabeca, no *x);
no * remove_inicio    (no **p_cabeca);
no * remove_final     (no **p_cabeca);

void junta_listas     (no **p_cabeca, no *segunda);
no * maximo           (no * cabeca);
void insere_na_ordem  (no **p_cabeca, no *x);

void remove_todos     (no **p_cabeca, item dado);
void remove_todos_rec (no **p_cabeca, item dado);
void inverte          (no **p_cabeca);
void inverte_rec      (no **p_cabeca);

#endif
