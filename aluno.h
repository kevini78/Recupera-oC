#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[100];
    char telefone[100];
    char curso[20];
    float nota1;
    float nota2;
};

#define ERRO 1
#define MAX 1024

int contarLinhas(FILE *arquivo);
void lerArquivo(FILE *arquivo, struct Aluno *X, int *i);
void escreveArquivo(FILE *arquivo, struct Aluno *X, int *i);

void ordenar(struct Aluno *X, int N);  // Ordena o vetor de struct Aluno indicada por X com tamanho N
float mediaFinal(struct Aluno *X, int N); // Determina a nota média final de todos os alunos

#endif
