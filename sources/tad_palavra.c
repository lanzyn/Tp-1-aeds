#include "../headers/tad_palavra.h"

#define UPPER_A 65
#define UPPER_Z 90

#define LOWER_A 97
#define LOWER_Z 122

tipo_palavra *inicializa_palavra_vazia() {
    tipo_palavra *palavra = (tipo_palavra*) malloc(sizeof(tipo_palavra));
    palavra -> lista_linha = (tipo_lista_linha*) malloc(sizeof(tipo_lista_linha));
    inicializa_lista_linha(palavra -> lista_linha);
    return palavra;
}

void preenche_cadeia_caracteres(tipo_palavra *palavra, char *palavra_texto, int linha) {
    palavra -> cadeia_caracteres = (char*) malloc(sizeof(char) * (strlen(palavra_texto) + 1));
    insere_linha(palavra -> lista_linha, linha);
    strcpy(palavra -> cadeia_caracteres, palavra_texto);
}

int verifica_palavra(tipo_palavra *palavra) {
    int i; i = 0;
    int tamanho_cadeia; tamanho_cadeia = strlen(palavra -> cadeia_caracteres);
    int valida; valida = 1;
    while (valida && i < tamanho_cadeia) {
        if (palavra -> cadeia_caracteres[i] >= UPPER_A && palavra -> cadeia_caracteres[i] <= UPPER_Z) {
            valida = 1;
        }            
        else if (palavra -> cadeia_caracteres[i] >= LOWER_A && palavra -> cadeia_caracteres[i] <= LOWER_Z) {
            valida = 1;
        }
        else {
            valida = 0;
        }
        i++;
    }
    return valida;
}

char *retorna_cadeia_caracteres(tipo_palavra *palavra) {
    return palavra -> cadeia_caracteres;
}

void imprime_cadeia_caracteres(tipo_palavra *palavra) {
    printf("Palavra: %s\n", retorna_cadeia_caracteres(palavra));
}

void imprime_palavra(tipo_palavra *palavra) {
    imprime_cadeia_caracteres(palavra);
    imprime_linha(palavra -> lista_linha);
}