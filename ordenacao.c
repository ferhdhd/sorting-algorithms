#include "ordenacao.h"
#include <string.h>
#include <stdlib.h>

void getNome(char nome[]){
	strncpy(nome, "Fernando Gbur dos Santos", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR(){
	return 20211761;
}

void preencheVetor(int vet[], int tamVet, int valorMax){  //função que automatiza o preenchimento dos vetores

	int i;
	for(i = 0; i < tamVet; i++)
		vet[i] = rand()%valorMax;

}

int buscaSequencialFer(int x, int vet[], int a, int b, int* comp){

	if(a > b)
		return -1;
	if(vet[b] == x){
		
		return b;
	} else {
	*comp+=1;
	}
	return buscaSequencialFer(x, vet, a, b-1, comp);
}

int buscaSequencialFer2(int x, int vet[], int a, int b, int *comp){

	if(a > b)
		return -1;
	if(vet[b] <= x){
		*comp+=1;
		return b;
	}else {
	*comp+=1;
	}
	return buscaSequencialFer2(x, vet, a, b-1, comp);
}

int buscaBinariaFer(int x, int vetor[], int a, int b, int *comp){

	int m;
	
	if(a > b)
		return -1;
	
	m =((a+b)/2);

	if(x == vetor[m]){
		*comp+=1;
		return m;
	}else{
	*comp+=1;
	}
	if(x < vetor[m]){
		*comp += 1;
		return buscaBinariaFer(x, vetor, a, m-1, comp);
	}else{
	*comp+=1;
	}
	return buscaBinariaFer(x, vetor,m+1,b, comp);

}

void troca(int vetor[], int a, int b){

	int aux; 
	aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;

}

void insere(int vetor[], int a, int b, int *comp){

	int p; int i;
	p = buscaSequencialFer2(vetor[b], vetor, a, b-1, comp);
	i = b;
	while (i > p+1){

		troca(vetor, i, i-1);
		i = i-1;

	}
	return;

}

int minimo(int vetor[], int a, int b,int *comp){

	int m = a; int j = a;
	while(j < b){

		j = j + 1;
		if(vetor[j] < vetor[m])
			m = j;
		*comp+=1;
	}
	return m;
}

int copiar(int vetor[], int a, int b, int u[]){

	int i = a;
	while(i <= b){
		vetor[i] = u[i];
		i++;
	}
	return 0;
}

int merge(int vetor[], int a, int m, int b, int u[], int *comp){

	int k = a; int j = m + 1; int i = a; int p;

	while(k <= b){

		if(j > b || (i <= m && vetor[i] <= vetor[j])){
			p = i;
			i++;
			*comp+=1;
		} else{
			p = j;
			j++;
			*comp+=1;
		}
		u[k] = vetor[p];
		k++;
	}
	
	return copiar(vetor,a,b,u);

}

int particionar(int vetor[], int a, int b, int *comp){

	int x; int m;
	x = vetor[b];
	m = a;
	for(int i = a; i < b; i++){

		if(vetor[i] <= x){
			troca(vetor, m, i);
			m++;
		}
		*comp+=1;
	}
	troca(vetor, m, b);
	return m;
}

int insertionSortFer(int vetor[], int a, int b, int *comp){

	if(a >= b)
		return 0;
	insertionSortFer(vetor,a,b-1, comp);
	insere(vetor,a,b, comp);
	return 0;

}

int selectionSortFer(int vetor[], int a, int b, int *comp){

	if(a >= b)
	  return 0;
	troca(vetor, a, minimo(vetor, a, b,comp));
	return selectionSortFer(vetor, a+1,b,comp);  

}

int mergeSortFer(int vetor[], int a, int b, int u[], int *comp){

	int m;
	if(a >= b)
		return 0;
	m = ((a+b)/2);

	mergeSortFer(vetor, a, m, u, comp);
	mergeSortFer(vetor, m+1, b, u, comp);
	merge(vetor, a, m, b, u, comp);
	return 0;

}

int quickSortFer(int vetor[], int a, int b, int *comp){

	int m;
	if(a >= b)
	  return 0;
	m = particionar(vetor, a, b, comp);
	quickSortFer(vetor, a, m-1, comp);
	quickSortFer(vetor, m+1, b, comp);
	return 0;

}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	
	return buscaSequencialFer(valor, vetor, 0, tam, numComparacoes);  // wrapper

}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	
	return buscaBinariaFer(valor, vetor, 0, tam, numComparacoes);  // wrapper

}

int insertionSort(int vetor[], int tam){	
		                            
	int comp = 0;							 // varíavel contadora
	insertionSortFer(vetor, 0, tam, &comp);  // wrapper
	return comp;

}

int selectionSort(int vetor[], int tam){
	
	int comp = 0;                            // varíavel contadora
	selectionSortFer(vetor, 0, tam, &comp);  // wrapper
	return comp;

}

int mergeSort(int vetor[], int tam){
	
	int *u = malloc(tam * sizeof(int));      // alocação dinâmica para o vetor auxiliar
	int comp = 0;							 // varíavel contadora
	mergeSortFer(vetor, 0, tam-1, u, &comp); // wrapper
	free(u);
	return comp;

}

int quickSort(int vetor[], int tam){
	
	int comp = 0;                            // varíavel contadora
	quickSortFer(vetor, 0, tam, &comp);		 // wrapper
	return comp;
}

