#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/tad_dicionario.h"

#define UPPER_A 65
#define UPPER_Z 90

#define LOWER_A 97
#define LOWER_Z 122

int main() {
    tipo_dicionario dicionario;

    char nome_arquivo[100]; // Variável que recebe o nome do arquivo para ser lido
    char palavra_menu[100]; // Variável que recebe palavras para serem verificadas ou removidas
    char letra_desejada;  // Variável que recebe uma letra para associar com determinada lista
    int num_letra; num_letra = 0; // Variável que recebe o número da letra
    int cont_num_palavras; cont_num_palavras = 0; // Variável que recebe o número total de palavras do texto
    int loop; loop = 1; // Variável de loop para o menu
    int option; // Variável que recebe a opção do menu

    while (loop) {
        // Operações disponíveis no menu
        printf("\n-------------------- DICIONÁRIO DE AEDS --------------------\n");
        printf("Opções do dicionário:\n");
        printf("Nome do arquivo: %s\n", nome_arquivo); // Exibe o nome do arquivo que foi aberto
        printf("1. Inserir nome do arquivo\n"); // Inserir o nome do arquivo desejado
        printf("2. Construir o dicionário do texto\n"); // Constrói o dicionário
        printf("3. Exibir lista de palavras de determinada letra\n"); // Exibe a lista de palavras de uma determinada letra
        printf("4. Exibir toda a lista de palavras do texto\n"); // Exibe toda a lista de palavras do texto
        printf("5. Verificar número de palavras do texto\n"); // Exibe o número de palavras únicas do texto de cada letra e total
        printf("6. Verificar se determinada palavra está na lista de palavras do texto\n"); // Verifica se determinada palavra está nas listas
        printf("7. Remover determinada palavra de uma lista de palavras\n"); // Remove um determina palavra de uma determina lista
        printf("8. Instruções para usar o programa\n"); // Breve explicação de como usar o programa
        printf("9. Sair do programa\n"); // Encerrta o programa
        printf("------------------------------------------------------------\n");
        printf("Opção desejada: ");
        scanf("%d", &option);
        system("cls || clear");

        // Implementação do menu de operações do programa
        switch (option) {
            case 1 :
                printf("Nome do arquivo desejado: ");
                scanf("%s", nome_arquivo);
                break;
            case 2 :
                constroi_dicionario(&dicionario, nome_arquivo);
                break;
            case 3 :
                printf("Insira uma letra: ");
                scanf("%s", &letra_desejada);
                printf("\n");
                imprime_dicionario_letra(&dicionario, letra_desejada);
                break;
            case 4 :
                imprime_dicionario_completo(&dicionario);
                break;
            case 5 :
                for (num_letra = 0; num_letra < 26; num_letra++) {
                    printf("\n------------------------------------------------------------\n");
                    printf("%d palavras únicas com a letra |%c|\n", retorna_numero_palavras(&dicionario.alfabeto[num_letra].lista_palavras), 
                    dicionario.alfabeto[num_letra].identificador_upper);
                    cont_num_palavras = cont_num_palavras + retorna_numero_palavras(&dicionario.alfabeto[num_letra].lista_palavras);
                    printf("------------------------------------------------------------\n");
                }
                printf("\n------------------------------------------------------------\n");
                printf("Número total de palavras únicas: %d\n", cont_num_palavras);
                printf("------------------------------------------------------------\n");
                cont_num_palavras = 0;
                break;
            case 6 :
                printf("Insira uma letra: ");
                scanf("%s", &letra_desejada);
                if (letra_desejada >= LOWER_A && letra_desejada <= LOWER_Z) {
                    num_letra = letra_desejada - LOWER_A;
                }
                else if (letra_desejada >= UPPER_A && letra_desejada <= UPPER_Z) {
                    num_letra = letra_desejada - UPPER_A;
                }
                else {
                    printf("O caractere informado não existe!\n");
                    break;
                }
                printf("Palavra que deseja verificar: ");
                scanf("%s", palavra_menu);
                if (verifica_pertencimento_lista_palavras(&dicionario.alfabeto[num_letra].lista_palavras, palavra_menu) == 1) {
                    printf("A palavra <%s> foi encontrada na lista de palavras de letra |%c|\n", palavra_menu, letra_desejada);
                }
                else {
                    printf("A palavra não foi encontrada!\n");
                }
                break;

                break;
            case 7 :
                printf("Insira uma letra: ");
                scanf("%s", &letra_desejada);
                if (letra_desejada >= LOWER_A && letra_desejada <= LOWER_Z) {
                    num_letra = letra_desejada - LOWER_A;
                }
                else if (letra_desejada >= UPPER_A && letra_desejada <= UPPER_Z) {
                    num_letra = letra_desejada - UPPER_A;
                }
                else {
                    printf("O caractere informado não existe!\n");
                    break;
                }
                printf("Palavra que deseja remover: ");
                scanf("%s", palavra_menu);
                if (remove_palavra_informada(&dicionario.alfabeto[num_letra].lista_palavras, palavra_menu) == 1) {
                    printf("A palavra <%s> foi removida com sucesso!\n", palavra_menu);
                }
                else {
                    printf("Não foi possível remover a palavra!\n");
                }
                break;
            case 8 :
                printf("Instruções:\n");
                printf("Passo 1 - Inserir o nome do arquivo de texto que deseja ler e receber suas informações (1)\n");
                printf("Passo 2 - Construir o dicionário com suas listas de palavras (2)\n");
                printf("Passo 3 - Utilizar as demais funções conforme sua vontade\n");
                break;
            case 9 :
                printf("Obrigado por usar nosso dicionário :)\n");
                loop = 0;
                break;
            default :
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    return 0;
}