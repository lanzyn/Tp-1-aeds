#include "../headers/tad_dicionario.h"

#define UPPER_A 65
#define UPPER_Z 90

#define LOWER_A 97
#define LOWER_Z 122

void inicializa_dicionario(tipo_dicionario *dicionario) {
    int i;
    for (i = 0; i < 26; i++) {
        dicionario -> alfabeto[i].identificador_upper = 'A' + i;
        dicionario -> alfabeto[i].identificador_lower = 'a' + i;
        inicializa_lista_palavras(&dicionario -> alfabeto[i].lista_palavras);
    }
}

void constroi_dicionario(tipo_dicionario *dicionario, char *nome_arquivo) {
    inicializa_dicionario(dicionario);
    tipo_palavra *palavra = NULL;

    char palavra_texto[100];
    char caractere_texto;
    int linha; linha = 1;
    int cont_caracteres; cont_caracteres = 0;

    FILE *arquivo = NULL;
    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo de texto!\n");
        return;
    }

    do {
        caractere_texto = fgetc(arquivo);
        switch (caractere_texto) {
            case EOF :
                break;
            case ' ' :
                palavra = inicializa_palavra_vazia();
                preenche_cadeia_caracteres(palavra, palavra_texto, linha);
                insere_dicionario(dicionario, *palavra);
                free(palavra);
                cont_caracteres = 0;
                memset(palavra_texto, 0, strlen(palavra_texto));
                break;
            case '\n' :
                palavra = inicializa_palavra_vazia();
                preenche_cadeia_caracteres(palavra, palavra_texto, linha);
                insere_dicionario(dicionario, *palavra);
                free(palavra);
                linha++;
                cont_caracteres = 0;
                memset(palavra_texto, 0, strlen(palavra_texto));
                break;
            default:
                palavra_texto[cont_caracteres] = caractere_texto;
                cont_caracteres++;
        }

    } while (caractere_texto != EOF);
}

int insere_dicionario(tipo_dicionario *dicionario, tipo_palavra palavra) {
    int i;
    if (palavra.cadeia_caracteres == NULL) {
        return 0;
    }
    for (i = 0; i < 26; i++) {
        if (((palavra.cadeia_caracteres[0] == dicionario -> alfabeto[i].identificador_upper) || (palavra.cadeia_caracteres[0] == dicionario -> alfabeto[i].identificador_lower)) && verifica_palavra(&palavra)) {
            insere_nova_palavra(&dicionario -> alfabeto[i].lista_palavras, palavra);
            return 1;
        }
    }
    return 0;
}

void imprime_dicionario_letra(tipo_dicionario *dicionario, char letra_alfabeto) {
    int aux; aux = 0;
    if (letra_alfabeto >= LOWER_A && letra_alfabeto <= LOWER_Z) {
        aux = letra_alfabeto - LOWER_A;
    }
    else if (letra_alfabeto >= UPPER_A && letra_alfabeto <= UPPER_Z) {
        aux = letra_alfabeto - UPPER_A;
    }
    else {
        printf("O caractere informado não existe!\n");
        return;
    }
    printf("Letra |%c| :\n", letra_alfabeto);
    printf("\n");
    if (retorna_numero_palavras(&dicionario -> alfabeto[aux].lista_palavras) > 0) {
        imprime_lista_palavras(&dicionario -> alfabeto[aux].lista_palavras);
        return;
    }
    else {
        printf("Não existem palavras com a letra informada!\n");
        return;
    }
}

void imprime_dicionario_completo(tipo_dicionario *dicionario) {
    int i;
    for (i = 0; i < 26; i++) {
        printf("\n------------------------------------------------------------\n");
        printf("Letra |%c| :\n", dicionario -> alfabeto[i].identificador_upper);
        printf("\n");
        imprime_lista_palavras(&dicionario -> alfabeto[i].lista_palavras);
        printf("------------------------------------------------------------\n");
        printf("\n\n");
    }
}