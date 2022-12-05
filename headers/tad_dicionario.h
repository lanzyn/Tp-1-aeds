#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tad_lista_palavra.h"

// Declarando célula para o dicionário
typedef struct {
    char identificador_upper;
    char identificador_lower;
    tipo_lista_palavras lista_palavras;
} tipo_celula_dicionario;

// Declarando o dicionário
typedef struct {
    tipo_celula_dicionario alfabeto[26];
} tipo_dicionario;

// Função para inicializar o dicionário vazio
void inicializa_dicionario(tipo_dicionario *dicionario);

// Função para construir o dicionário recebendo um texto como parâmetro
void constroi_dicionario(tipo_dicionario *dicionario, char *nome_arquivo);

// Função para inserir a lista encadeade de palavras de cada letra
int insere_dicionario(tipo_dicionario *dicionario, tipo_palavra palavra);

// Função para imprimir a lista de palavras de uma determinada letra do alfabeto
void imprime_dicionario_letra(tipo_dicionario *dicionario, char letra_alfabeto);

// Fução para imprimir o dicionário completo com a a lista de palavras de cada letra do alfabeto
void imprime_dicionario_completo(tipo_dicionario *dicionario);