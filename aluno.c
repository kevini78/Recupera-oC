#include "aluno.h"

void trocaAlunos(struct Aluno *a, struct Aluno *b) {
    struct Aluno temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Aluno *X, int low, int high) {
    char pivot[100];
    strcpy(pivot, X[high].nome);
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(X[j].nome, pivot) < 0) {
            i++;
            trocaAlunos(&X[i], &X[j]);
        }
    }
    trocaAlunos(&X[i + 1], &X[high]);
    return (i + 1);
}

void quicksort(struct Aluno *X, int low, int high) {
    if (low < high) {
        int pi = partition(X, low, high);
        quicksort(X, low, pi - 1);
        quicksort(X, pi + 1, high);
    }
}

void ordenar(struct Aluno *X, int N) {
    quicksort(X, 0, N - 1);
}

float mediaFinal(struct Aluno *X, int N) {
    float somaNotas = 0.0;
    for (int i = 0; i < N; i++) {
        somaNotas += (X[i].nota1 + X[i].nota2) / 2;
    }
    return somaNotas / N;
}

int contarLinhas(FILE *arquivo) {
    int quantidade = 0;
    char linha[MAX]; // Declaração de MAX não está visível aqui, mas deve ser definido globalmente ou em aluno.h
    while (fgets(linha, MAX, arquivo) != NULL) { // Uso da constante MAX para controlar o tamanho máximo da linha
        quantidade++;
    }
    rewind(arquivo);
    return quantidade;
}

void lerArquivo(FILE *arquivo, struct Aluno *X, int *i) {
    for ((*i) = 0; fscanf(arquivo, "%[^,],%[^,],%[^,],%f,%f\n", X[*i].nome, X[*i].telefone, X[*i].curso, &X[*i].nota1, &X[*i].nota2) != EOF; (*i)++);
    // Uso de fscanf para ler corretamente os dados de cada aluno do arquivo
}

void escreveArquivo(FILE *arquivo, struct Aluno *X, int *i) {
    for (int j = 0; j < (*i); j++) {
        fprintf(arquivo, "%s, %.2f, ", X[j].nome, ((X[j].nota1 + X[j].nota2) / 2));
        if ((X[j].nota1 + X[j].nota2) / 2 >= 7.0) {
            fprintf(arquivo, "APROVADO\n");
        } else {
            fprintf(arquivo, "REPROVADO\n");
        }
    }
    // Uso de fprintf para escrever corretamente os dados de cada aluno no arquivo de saída
}
