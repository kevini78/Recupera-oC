#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

int main() {
    FILE *arquivo;
    int i;
    arquivo = fopen("DadosEntrada.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(ERRO);
    }

    int linhas = contarLinhas(arquivo);
    struct Aluno *X = malloc(linhas * sizeof(struct Aluno));

    if (X == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(ERRO);
    }

    // Pular a primeira linha do arquivo
    fscanf(arquivo, "%*[^\n]\n");

    lerArquivo(arquivo, X, &i); 
    fclose(arquivo);

    // Ordenar os alunos pelo nome
    ordenar(X, linhas);

    // Escrever arquivo de saída
    FILE *saida;
    char nomeArquivoSaida[50]; // Considerando um nome suficientemente grande para o número de matrícula
    sprintf(nomeArquivoSaida, "SituacaoFinal.csv");

    saida = fopen(nomeArquivoSaida, "w");

    if (saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        exit(ERRO);
    }

    for (int j = 0; j < linhas; j++) {
        fprintf(saida, "%s, %.2f, ", X[j].nome, ((X[j].nota1 + X[j].nota2) / 2));
        if ((X[j].nota1 + X[j].nota2) / 2 >= 7.0) {
            fprintf(saida, "APROVADO\n");
        } else {
            fprintf(saida, "REPROVADO\n");
        }
    }

    fclose(saida);

    // Calcular a média final de todos os alunos
    float media = mediaFinal(X, linhas);
    printf("A média final de todos os alunos é: %.2f\n", media);

    free(X);

    return 0; 
}
