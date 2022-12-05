#include "../headers/tad_palavra_linha.h"

void inicializa_lista_linha(tipo_lista_linha *lista_linha) {
    lista_linha -> primeiro_linha = (tipo_celula_linha*) malloc(sizeof(tipo_celula_linha));
    lista_linha -> ultimo_linha = lista_linha -> primeiro_linha;
    lista_linha -> primeiro_linha -> p_prox_linha = NULL;
}

int verifica_lista_linha(tipo_lista_linha *lista_linha) {
    return (lista_linha -> primeiro_linha == lista_linha -> ultimo_linha);
}

int insere_linha(tipo_lista_linha *lista_linha, int linha) {
    lista_linha -> ultimo_linha -> p_prox_linha = (apontador_linha) malloc(sizeof(tipo_celula_linha));
    lista_linha -> ultimo_linha = lista_linha -> ultimo_linha -> p_prox_linha;
    lista_linha -> ultimo_linha -> num_linha = linha;
    lista_linha -> ultimo_linha -> p_prox_linha = NULL;
    return 1;
}

void imprime_linha(tipo_lista_linha *lista_linha) {
    apontador_linha aux_linha;
    aux_linha = lista_linha -> primeiro_linha -> p_prox_linha;
    printf("Linhas: ");
    while (aux_linha != NULL) {
        printf("|%d|", aux_linha -> num_linha);
        aux_linha = aux_linha -> p_prox_linha;
    }
    printf("\n");
}