#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50


void getNome(char nome[]);


unsigned int getGRR();

void preencheVetor(int vet[], int tamVet, int valorMax);

int buscaSequencialFer(int x, int vet[], int a, int b, int* comp);

int buscaSequencialFer2(int x, int vet[], int a, int b, int *comp);

int buscaBinariaFer(int x, int vetor[], int a, int b, int *comp);

void troca(int vetor[], int a, int b);

void insere(int vetor[], int a, int b, int *comp);

int minimo(int vetor[], int a, int b,int *comp);

int merge(int vetor[], int a, int m, int b, int u[], int *comp);

int particionar(int vetor[], int a, int b, int *comp);

int selectionSortFer(int vetor[], int a, int b, int *comp);

int mergeSortFer(int vetor[], int a, int b, int u[], int *comp);

int quickSortFer(int vetor[], int a, int b, int *comp);

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes);


int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes);


int insertionSort(int vetor[], int tam);

int selectionSort(int vetor[], int tam);

int mergeSort(int vetor[], int tam);

int quickSort(int vetor[], int tam);

#endif // ORDENACAO_H_
