#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"


#define N 50000 // tamanho do vetor
#define K 32603 // numero utilizado nas buscas

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBuscaSeq ; int idxBuscaBin;
	int numComp; int numCompBin = 0; int numCompSeq = 0;
	clock_t start, end;
    double total;
	int tamVetor = N;
	
	
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	

	// insertion sort
	
	int* vetor = malloc(tamVetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	
	preencheVetor(vetor, N, N);
	
	start = clock();
	numComp = insertionSort(vetor, N-1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	
	/*
	for(int i=0; i < N; i++){
		printf("%d ", vetor[i]); // comentei a impressão dos vetores para não poluir a execução no terminal
	}                            // os algoritmos de busca chegando no mesmo valor (sem repetição no vetor)
	*/                           // provam que o vetor está ordenado. Se o prof quiser conferir mesmo, é só retirar o comentário.
    
	
	printf("\n");
	printf("\nNúmero de comparações do insertionSort:%d", numComp);
	printf("\n");
	printf("Tempo total de ordenação do insertionSort: %f\n", total);

	start = clock();
	idxBuscaSeq = buscaSequencial(vetor, N, K, &numCompSeq);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nNúmero de comparações e índice do vetor da buscaSequencial:%d e %d", numCompSeq, idxBuscaSeq);
	printf("\n");
	printf("Tempo total de execução do buscaSequencial:%f\n", total);
	
	
	start = clock();
	idxBuscaBin = buscaBinaria(vetor, N, K, &numCompBin);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nNúmero de comparações e índice do vetor da buscaBinaria:%d e %d", numCompBin, idxBuscaBin);
	printf("\n");
	printf("Tempo total de execução da BuscaBinaria:%f\n", total);

	free(vetor);
	numCompBin = 0; numCompSeq = 0;
	


	//selection sort

	int* vetor2 = malloc(tamVetor * sizeof(int));
	if(vetor2 == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	
	preencheVetor(vetor2, N, N);
	
	start = clock();
	numComp = selectionSort(vetor2, N-1);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
		
	/*
	for(int i=0; i < N; i++){
		printf("%d ", vetor2[i]);
	}
	*/

	printf("\n");
	printf("\nNúmero de comparações do selectionSort:%d", numComp);
	printf("\n");
	printf("Tempo total de ordenação do selectionSort: %f\n", total);

	start = clock();
	idxBuscaSeq = buscaSequencial(vetor2, N, K, &numCompSeq);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nNúmero de comparações e índice do vetor da buscaSequencial:%d e %d", numCompSeq, idxBuscaSeq);
	printf("\n");
	printf("Tempo total de execução do buscaSequencial:%f\n", total);
	
	
	start = clock();
	idxBuscaBin = buscaBinaria(vetor2, N, K, &numCompBin);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nNúmero de comparações e índice do vetor da buscaBinaria:%d e %d", numCompBin, idxBuscaBin);
	printf("\n");
	printf("Tempo total de execução da BuscaBinaria:%f\n", total);

	free(vetor2);
	numCompBin = 0; numCompSeq = 0;

	
	// merge sort
	
	int* vetor3 = malloc(tamVetor * sizeof(int));
	if(vetor3 == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	
	preencheVetor(vetor3, N, N);
	
	start = clock();
	numComp = mergeSort(vetor3, N);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
		
	/*
	for(int i=0; i < N; i++){
		printf("%d ", vetor3[i]);
	}
	//
	*/

	printf("\n");
	printf("\nNúmero de comparações do mergeSort:%d", numComp);
	printf("\n");
	printf("Tempo total de ordenação do mergeSort: %f\n", total);

	start = clock();
	idxBuscaSeq = buscaSequencial(vetor3, N, K, &numCompSeq);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nNúmero de comparações e índice do vetor da buscaSequencial:%d e %d", numCompSeq, idxBuscaSeq);
	printf("\n");
	printf("Tempo total de execução do buscaSequencial:%f\n", total);
	
	
	start = clock();
	idxBuscaBin = buscaBinaria(vetor3, N, K, &numCompBin);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nNúmero de comparações e índice do vetor da buscaBinaria:%d e %d", numCompBin, idxBuscaBin);
	printf("\n");
	printf("Tempo total de execução da BuscaBinaria:%f\n", total);

	free(vetor3);
	numCompBin = 0; numCompSeq = 0;

	
	// quick sort

	int *vetor4 = malloc(tamVetor * sizeof(int));
	if(vetor4 == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	
	preencheVetor(vetor4, N, N);
	
	start = clock();
	numComp = quickSort(vetor4, N);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	
	/*
	for(int i=0; i < N; i++){
		printf("%d ", vetor4[i]);
	}
	*/

	printf("\n");
	printf("\nNúmero de comparações do quickSort:%d", numComp);
	printf("\n");
	printf("Tempo total de ordenação do quickSort: %f\n", total);

	start = clock();
	idxBuscaSeq = buscaSequencial(vetor4, N, K, &numCompSeq);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nNúmero de comparações e índice do vetor da buscaSequencial:%d e %d", numCompSeq, idxBuscaSeq);
	printf("\n");
	printf("Tempo total de execução do buscaSequencial:%f\n", total);
	
	
	start = clock();
	idxBuscaBin = buscaBinaria(vetor4, N, K, &numCompBin);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nNúmero de comparações e índice do vetor da buscaBinaria:%d e %d", numCompBin, idxBuscaBin);
	printf("\n");
	printf("Tempo total de execução da BuscaBinaria:%f\n", total);

	free(vetor4);

	return 0;
}
