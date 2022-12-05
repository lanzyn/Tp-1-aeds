#include "../headers/tad_lista_palavra.h"

void inicializa_lista_palavras(tipo_lista_palavras *lista_palavras) {
    lista_palavras -> primeiro_lista = (tipo_celula_lista_palavras*) malloc(sizeof(tipo_celula_lista_palavras));
    lista_palavras -> ultimo_lista = lista_palavras -> primeiro_lista;
    lista_palavras -> ultimo_lista -> p_prox_lista = NULL;
}

int verifica_lista_palavras(tipo_lista_palavras *lista_palavras) {
    return (lista_palavras -> primeiro_lista == lista_palavras -> ultimo_lista);
}

int insere_nova_palavra(tipo_lista_palavras *lista_palavras, tipo_palavra palavra) {
    if (verifica_pertencimento_lista_palavras(lista_palavras, palavra.cadeia_caracteres)) {
        int existe_linha; existe_linha = 0;
        apontador_lista_palavras p_aux; p_aux = lista_palavras -> primeiro_lista -> p_prox_lista;
        while (p_aux != NULL && strcmp(p_aux -> item_palavra.cadeia_caracteres, palavra.cadeia_caracteres) != 0) {
            p_aux = p_aux -> p_prox_lista;
        }
        apontador_linha p_aux_linha_1; p_aux_linha_1 = palavra.lista_linha -> primeiro_linha -> p_prox_linha;
        while (p_aux_linha_1 != NULL) {
            apontador_linha p_aux_linha_2; p_aux_linha_2 = p_aux -> item_palavra.lista_linha -> primeiro_linha -> p_prox_linha;
            while (p_aux_linha_2 != NULL) {
                if (p_aux_linha_2 -> num_linha == p_aux_linha_1 -> num_linha) {
                    existe_linha = 1;
                    break;
                }
                p_aux_linha_2 = p_aux_linha_2 -> p_prox_linha;
            }
            if (!existe_linha) {
                insere_linha(p_aux -> item_palavra.lista_linha, p_aux_linha_1 -> num_linha);
            }
            existe_linha = 0;
            p_aux_linha_1 = p_aux_linha_1 -> p_prox_linha;
        }
        return 2;
    }
    lista_palavras -> ultimo_lista -> p_prox_lista = (tipo_celula_lista_palavras*) malloc(sizeof(tipo_celula_lista_palavras));
    lista_palavras -> ultimo_lista = lista_palavras -> ultimo_lista -> p_prox_lista;
    lista_palavras -> ultimo_lista -> item_palavra = palavra;
    lista_palavras -> ultimo_lista -> p_prox_lista = NULL;
    return 1;
}

int remove_palavra_informada(tipo_lista_palavras *lista_palavras, char *char_palavra) {
    apontador_lista_palavras p_ultimo; p_ultimo = lista_palavras -> primeiro_lista -> p_prox_lista;
    apontador_lista_palavras p_novo_ultimo; p_novo_ultimo = lista_palavras -> primeiro_lista;
    while (p_ultimo != NULL && strcmp(p_ultimo -> item_palavra.cadeia_caracteres, char_palavra) != 0) {
        p_novo_ultimo = p_novo_ultimo -> p_prox_lista;
        p_ultimo = p_ultimo -> p_prox_lista;
    }
    if (p_ultimo == NULL) {
        return 0;
    }
    p_novo_ultimo -> p_prox_lista = p_ultimo -> p_prox_lista;
    free(p_ultimo);
    return 1;
}

int remove_palavra_final(tipo_lista_palavras *lista_palavras) {
    apontador_lista_palavras aux_remove; aux_remove = lista_palavras -> primeiro_lista -> p_prox_lista;
    while (aux_remove -> p_prox_lista != NULL) {
        aux_remove = aux_remove -> p_prox_lista;
    }
    free(aux_remove -> p_prox_lista);
    aux_remove -> p_prox_lista = NULL;
    return 1;
}

int retorna_numero_palavras(tipo_lista_palavras *lista_palavras) {
    int numero_palavras; numero_palavras = 0;
    apontador_lista_palavras aux_percorre; aux_percorre = lista_palavras -> primeiro_lista -> p_prox_lista;
    while (aux_percorre != NULL) {
        numero_palavras++;
        aux_percorre = aux_percorre -> p_prox_lista;
    }
    return numero_palavras;
}

int verifica_pertencimento_lista_palavras(tipo_lista_palavras *lista_palavras, char *char_palavra) {
    apontador_lista_palavras aux_verifica; aux_verifica = lista_palavras -> primeiro_lista -> p_prox_lista;
    while (aux_verifica != NULL) {
        if (strcmp(char_palavra, aux_verifica -> item_palavra.cadeia_caracteres) == 0) {
            return 1;
        }
        aux_verifica = aux_verifica -> p_prox_lista;
    }
    return 0;
}

void imprime_lista_palavras(tipo_lista_palavras *lista_palavras) {
    apontador_lista_palavras aux_palavra_imprime; aux_palavra_imprime = lista_palavras -> primeiro_lista -> p_prox_lista;
    while (aux_palavra_imprime != NULL) {
        imprime_palavra(&aux_palavra_imprime -> item_palavra);
        printf("\n");
        aux_palavra_imprime = aux_palavra_imprime -> p_prox_lista;
    }
}