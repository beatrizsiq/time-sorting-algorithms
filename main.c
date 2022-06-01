#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
    printf("Ordenacao 500 posicoes:\n\n\n");
    ordenacao_500_posicoes();
    printf("\n\n\nOrdencao 5000 posicoes:\n\n\n");    
    ordencao_5000_posicoes();
}

void ordenacao_500_posicoes(){
    FILE *arquivo;
    
    clock_t inicio_qsort, fim_qsort;
    double tempo_qsort; 
    
    int tam = 500;
    int vetor[tam];
    int i = 1;

    arquivo = fopen("numeros.txt", "r");

    if (!arquivo){
        printf("Problema ao abrir o arquivo!\n");
        return;
    }

    while (i<=tam){
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }

    fclose(arquivo);

    heapSort(vetor, tam);
    
    inicio_qsort = clock();
    quickSort(vetor,tam, 1, tam);
    fim_qsort= clock();
    tempo_qsort = (double)(fim_qsort - inicio_qsort) / CLOCKS_PER_SEC;
	printf("\nTempo de execucao Quick Sort: %lf", tempo_qsort);
	
	shellSort(vetor, tam);
    selectionSort(vetor, tam);
	insertionSort(vetor, tam);
	bubbleSort(vetor, tam);

}

void ordencao_5000_posicoes(){
	FILE *arquivo;
    
    clock_t inicio_qsort, fim_qsort;
    double tempo_qsort; 
    
    int tam = 5000;
    int vetor[tam];
    int i = 1;

    arquivo = fopen("numeros.txt", "r");

    if (!arquivo){
        printf("Problema ao abrir o arquivo!\n");
        return;
    }

    while (i<=tam){
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }

    fclose(arquivo);

    heapSort(vetor, tam);
    
    inicio_qsort = clock();
    quickSort(vetor,tam, 1, tam);
    fim_qsort= clock();
    tempo_qsort = (double)(fim_qsort - inicio_qsort) / CLOCKS_PER_SEC;

	printf("\nTempo de execucao Quick Sort: %lf", tempo_qsort);
	
	shellSort(vetor, tam);
	selectionSort(vetor, tam);
	insertionSort(vetor, tam);
	bubbleSort(vetor, tam);
}

// Métodos de Ordenação:

void bubbleSort(int vet[], int TAM){
    int i, j, aux;
    clock_t inicio, fim;
    double tempo; 

    inicio = clock();
    for (i = 0; i < TAM - 1; i++){
        for (j = i + 1; j < TAM; j++){
            if (vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de Execucao Bubble Sort: %lf", tempo);
}

void insertionSort(int vet[], int TAM){
    int i, j, chave;
    clock_t inicio, fim;
    double tempo; 

    inicio = clock();
    for (i = 1; i < TAM; i++){
        chave = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > chave){
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = chave;
    }
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de Execucao Insertion Sort: %lf", tempo);
}

void selectionSort(int vet[], int TAM){
    int i, j, min, aux;
    clock_t inicio, fim;
    double tempo; 

    inicio = clock();
    for (i = 0; i < (TAM - 1); i++){
        min = i;
        for (j = (i + 1); j < TAM; j++){
            if (vet[j] < vet[min])
                min = j;
        }
        if (i != min){
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de Execucao Selection Sort: %lf", tempo);
}

void shellSort(int vet[], int TAM){
	
	int h = 1, valor, j, i;
    clock_t inicio, fim;
    double tempo; 

    inicio = clock();
    do{
        h = (3 * h) + 1;
    }while (h < TAM);
    do{
        h /= 3;
        for (i = h; i < TAM; i++){
            valor = vet[i];
            j = i - h;
            while ((j >= 0) && (valor < vet[j])){
                vet[j + h] = vet[j];
                j -= h;
            }
            vet[j + h] = valor;
        }
     } while (h > 1);
     
	fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de Execucao ShellSort: %lf", tempo);
 }

void quickSort(int vetor[], int tam, int inicio, int fim){
    vetor[tam];
    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;
    meio = (i+j) / 2;
    pivo = vetor[meio];
    do {
        while(vetor[i] < pivo)
            i = i + 1;
        while(vetor[j] > pivo)
            j = j - 1;
        if (i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i);

    if(inicio < j) {
        quickSort(vetor, tam, inicio, j);
    }
    if(i < fim) {
        quickSort(vetor, tam, i, fim);
    }
    
}

void heapSort(int vetor[], int TAM){
    int i, pai, filho, aux, n;
    clock_t inicio, fim;
    double tempo; 

    inicio = clock();
    i = TAM/2;
    n = TAM;
    while(1) {
        if (i > 0) {
            i--;
            aux = vetor[i];
        } else {
            n--;
            if (n == 0)
                break;
            aux = vetor[n];
            vetor[n] = vetor[0];
        }
        pai = i;
        filho = (i*2) + 1;
        while (filho < n) {
            if ((filho + 1 < n) && (vetor[filho + 1] > vetor[filho]))
                filho++;
            if (vetor[filho] > aux) {
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = (pai*2) + 1;
            } else
                break;
        }
        vetor[pai] = aux;
    }  
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de Execucao HeapSort: %lf", tempo);
}
