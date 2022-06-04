#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int vetor[], int TAM)
{
    int i, j, aux;

    for (i = 0; i < TAM - 1; i++)
    {
        for (j = i + 1; j < TAM; j++)
        {
            if (vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void insertionSort(int vetor[], int TAM)
{
    int i, j, chave;

    for (i = 1; i < TAM; i++)
    {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void selectionSort(int vetor[], int TAM)
{
    int i, j, min, aux;

    for (i = 0; i < (TAM - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < TAM; j++)
        {
            if (vetor[j] < vetor[min])
                min = j;
        }
        if (i != min)
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}

void shellSort(int vetor[], int TAM)
{

    int h = 1, valor, j, i;

    do
    {
        h = (3 * h) + 1;
    } while (h < TAM);
    do
    {
        h /= 3;
        for (i = h; i < TAM; i++)
        {
            valor = vetor[i];
            j = i - h;
            while ((j >= 0) && (valor < vetor[j]))
            {
                vetor[j + h] = vetor[j];
                j -= h;
            }
            vetor[j + h] = valor;
        }
    } while (h > 1);
}

void quickSort(int vetor[], int TAM, int inicio, int fim)
{
    vetor[TAM];
    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;
    meio = (i + j) / 2;
    pivo = vetor[meio];
    do
    {
        while (vetor[i] < pivo)
            i = i + 1;
        while (vetor[j] > pivo)
            j = j - 1;
        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);

    if (inicio < j)
    {
        quickSort(vetor, TAM, inicio, j);
    }
    if (i < fim)
    {
        quickSort(vetor, TAM, i, fim);
    }
}

void heapSort(int vetor[], int TAM)
{
    int i, pai, filho, aux, n;

    i = TAM / 2;
    n = TAM;
    while (1)
    {
        if (i > 0)
        {
            i--;
            aux = vetor[i];
        }
        else
        {
            n--;
            if (n == 0)
                break;
            aux = vetor[n];
            vetor[n] = vetor[0];
        }
        pai = i;
        filho = (i * 2) + 1;
        while (filho < n)
        {
            if ((filho + 1 < n) && (vetor[filho + 1] > vetor[filho]))
                filho++;
            if (vetor[filho] > aux)
            {
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = (pai * 2) + 1;
            }
            else
                break;
        }
        vetor[pai] = aux;
    }
}
