#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tad_palavra_linha.h"

// Declarando o tipo palavra, que contém uma cadeia de caracteres e
// uma lista encadeada de linhas, em que os elementos são inteiros que indicam
// as linhas em que a palavra apareceu
typedef struct {
    tipo_lista_linha *lista_linha;
    char *cadeia_caracteres;
} tipo_palavra;

// Função para inicizalizar uma palavra
tipo_palavra *inicializa_palavra_vazia();

// Função para preencher a cadeia de caracteres a partir de palavras
// que serão retiradas do texto (SET)
void preenche_cadeia_caracteres(tipo_palavra *palavra, char *palavra_texto, int linha);

// Função para verificar se uma palavra é válida
int verifica_palavra(tipo_palavra *palavra);

// Função para retornar a cadeia de caracteres (GET)
char *retorna_cadeia_caracteres(tipo_palavra *palavra);

// Função para imprimir a cadeia de caracteres
void imprime_cadeia_caracteres(tipo_palavra *palavra);

// Função para imprimir palavra, ou seja a cadeia de caracteres e
// as linhas em que a palavra apareceu
void imprime_palavra(tipo_palavra *palavra);