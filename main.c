#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void corpo_informacoes_html();
//void ordenacao_500_posicoes();
//void ordenacao_5000_posicoes();
//void ordenacao_100000_posicoes();
//void bubbleSort(int vet[], int TAM);
//void insertionSort(int vet[], int TAM);
//void selectionSort(int vet[], int TAM);
//void shellSort(int vet[], int TAM);
//void quickSort(int vetor[], int tam, int inicio, int fim);
//void heapSort(int vetor[], int TAM);

main()
{
    FILE *html_arq;

    html_arq = fopen("index.html", "w");

    fprintf(html_arq, "<!DOCTYPE html><html lang=\"pt-br\"><head><title>Tempo de Ordenação</title><meta charset=\"UTF-8\">");
    fprintf(html_arq, "<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css\"rel=\"stylesheet\" integrity=\"sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3\" crossorigin=\"anonymous\">");
    fprintf(html_arq, "<link rel=\"stylesheet\" href=\"index.css\">");
    fprintf(html_arq, "</head><body	>");
    // nav
    fprintf(html_arq, "<nav class=\"collapse navbar navbar-collapse d-flex justify-content-center\"><div class=\"navbar-nav\"><h3 class=\"navbar-text mb-2 \">Tempo de execução</h3></div></nav>");
    fprintf(html_arq, "<div class=\" d-flex justify-content-center mt-5\"><h3>Algoritmos de Ordenação</h3></div>");
    // table
    fprintf(html_arq, "<div class=\"container mt-3 col-12 \" >");
    fprintf(html_arq, "<table class=\"table table-borderless\"><thead></tr><tr ><th scope=\"col\">Posições</th><th scope=\"col\" ><a href = \"https://blog.betrybe.com/tecnologia/bubble-sort-tudo-sobre/\">Bubble Sort</a></th><th scope=\"col\">Selection Sort</th><th scope=\"col\">Insertion Sort</th><th scope=\"col\">Shell Sort</th><th scope=\"col\">Quick Sort</th><th scope=\"col\">Heap Sort</th></thead>");
    fprintf(html_arq, " ", ordenacao_500_posicoes());
    fprintf(html_arq, " ", ordenacao_5000_posicoes());
    fprintf(html_arq, " ", ordenacao_100000_posicoes());
    fprintf(html_arq, " ", corpo_informacoes_html());
    fclose(html_arq);

}

void corpo_informacoes_html(void){
    FILE *html_arq;
    
    html_arq = fopen("index.html", "a");

    fprintf(html_arq, "<div class=\"container mt-5\"><div class=\"card border-0 \"><h5 class=\"card-header\">SOBRE</h5><div class=\"card-body border-0\">");
    fprintf(html_arq, "<p class=\"card-text\">Esse HTML foi gerado em C, o programa está realizando a leitura de um arquivo de números inteiros e alocando-os em um vetor, para que seja realizada a ordenação com os métodos supracitados. Após isso, foi gerado este arquivo HTML para impressão do tempo de execução de cada método.</p></div></div></div>");
	fprintf(html_arq, "<div class=\"container mt-5\"><div class=\"card border-0 \"><h5 class=\"card-header\">CRIADORA</h5><div class=\"card-body border-0\">");
	fprintf(html_arq, "<div class=\"col-12 d-flex justify-content-center\"><img src=\"beatrizPicture.jpg\" alt=\"Beatriz Siqueira\" class=\"rounded-circle w-25\"></div>");
	fprintf(html_arq, "<div class=\"col-12 py-2 mt-3 text-left\"><p>Olá, me chamo Beatriz Siqueira! Estou no 3º Período do curso de Sistemas de Informação. Atualmente trabalho com suporte e desenvolvimento em banco de dados Oracle</p><p>Atualmente aprendendo: PHP, JavaScript, HTML, CSS e Bootstrap!</p></div>");
	fprintf(html_arq, "<div class=\"col-12 py-2 mt-3 text-left\"><p>Contato: <ul> <li><a href=\"https://github.com/beatrizsiq\" class=\"git\">Github</a></li> <li><a href=\"beatrizsiqueiracosta2001@gmail.com\" class=\"gmail\">G-mail</a></li> <li><a href=\"https://instagram.com/beasiqueiras_\" class=\"insta\">Instagram</a></li></ul></p>");
	fprintf(html_arq, "</div></div></div></div>");
	fprintf(html_arq, "</body></html>");

}

void ordenacao_500_posicoes(void)
{
    FILE *arquivo;
    FILE *html_arq;

    html_arq = fopen("index.html", "a");

    clock_t i_quick, f_quick, i_bubble, f_bubble, i_selection, f_selection, i_insertion, f_insertion, i_shell, f_shell, i_heap, f_heap;
    double t_quick, t_bubble, t_heap, t_selection, t_insertion, t_shell;

    int tam = 500;
    int vetor[tam];
    int i = 1;

    arquivo = fopen("numeros.txt", "r");

    if (!arquivo)
    {
        printf("Problema ao abrir o arquivo!\n");
        return;
    }

    while (i <= tam)
    {
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }

    fclose(arquivo);

    i_quick = clock();
    quickSort(vetor, tam, 1, tam);
    f_quick = clock();
    t_quick = (double)(f_quick - i_quick) / CLOCKS_PER_SEC;

    i_bubble = clock();
    bubbleSort(vetor, tam);
    f_bubble = clock();
    t_bubble = (double)(f_bubble - i_bubble) / CLOCKS_PER_SEC;

    i_selection = clock();
    selectionSort(vetor, tam);
    f_selection = clock();
    t_selection = (double)(f_selection - i_selection) / CLOCKS_PER_SEC;

    i_insertion = clock();
    insertionSort(vetor, tam);
    f_insertion = clock();
    t_insertion = (double)(f_insertion - i_insertion) / CLOCKS_PER_SEC;

    i_shell = clock();
    shellSort(vetor, tam);
    f_shell = clock();
    t_shell = (double)(f_shell - i_shell) / CLOCKS_PER_SEC;

    i_heap = clock();
    heapSort(vetor, tam);
    f_heap = clock();
    t_heap = (double)(f_heap - i_heap) / CLOCKS_PER_SEC;

    fprintf(html_arq, "<tbody><tr><th scope=\"row\" class=\"posicoes\">500</th>");
    fprintf(html_arq, "<td>%.3lf</td>", t_bubble);
    fprintf(html_arq, "<td>%.3lf</td>", t_selection);
    fprintf(html_arq, "<td>%.3lf</td>", t_insertion);
    fprintf(html_arq, "<td>%.3lf</td>", t_shell);
    fprintf(html_arq, "<td>%.3lf</td>", t_quick);
    fprintf(html_arq, "<td>%.3lf</td>", t_heap);
    fprintf(html_arq, "</tr>");
}

void ordenacao_5000_posicoes(void)
{
    FILE *arquivo;
    FILE *html_arq;

    html_arq = fopen("index.html", "a");

    clock_t i_quick, f_quick, i_bubble, f_bubble, i_selection, f_selection, i_insertion, f_insertion, i_shell, f_shell, i_heap, f_heap;
    double t_quick, t_bubble, t_heap, t_selection, t_insertion, t_shell;

    int tam = 5000;
    int vetor[tam];
    int i = 1;

    arquivo = fopen("numeros.txt", "r");

    if (!arquivo)
    {
        printf("Problema ao abrir o arquivo!\n");
        return;
    }

    while (i <= tam)
    {
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }

    fclose(arquivo);

    i_quick = clock();
    quickSort(vetor, tam, 1, tam);
    f_quick = clock();
    t_quick = (double)(f_quick - i_quick) / CLOCKS_PER_SEC;

    i_bubble = clock();
    bubbleSort(vetor, tam);
    f_bubble = clock();
    t_bubble = (double)(f_bubble - i_bubble) / CLOCKS_PER_SEC;

    i_selection = clock();
    selectionSort(vetor, tam);
    f_selection = clock();
    t_selection = (double)(f_selection - i_selection) / CLOCKS_PER_SEC;

    i_insertion = clock();
    insertionSort(vetor, tam);
    f_insertion = clock();
    t_insertion = (double)(f_insertion - i_insertion) / CLOCKS_PER_SEC;

    i_shell = clock();
    shellSort(vetor, tam);
    f_shell = clock();
    t_shell = (double)(f_shell - i_shell) / CLOCKS_PER_SEC;

    i_heap = clock();
    heapSort(vetor, tam);
    f_heap = clock();
    t_heap = (double)(f_heap - i_heap) / CLOCKS_PER_SEC;

    fprintf(html_arq, "<tr><th scope=\"row\" class=\"posicoes\">5000</th>");
    fprintf(html_arq, "<td>%.3lf</td>", t_bubble);
    fprintf(html_arq, "<td>%.3lf</td>", t_selection);
    fprintf(html_arq, "<td>%.3lf</td>", t_insertion);
    fprintf(html_arq, "<td>%.3lf</td>", t_shell);
    fprintf(html_arq, "<td>%.3lf</td>", t_quick);
    fprintf(html_arq, "<td>%.3lf</td>", t_heap);
    fprintf(html_arq, "</tr>");
}

void ordenacao_100000_posicoes(void)
{
    FILE *arquivo;
    FILE *html_arq;

    html_arq = fopen("index.html", "a");

    clock_t i_quick, f_quick, i_bubble, f_bubble, i_selection, f_selection, i_insertion, f_insertion, i_shell, f_shell, i_heap, f_heap;
    double t_quick, t_bubble, t_heap, t_selection, t_insertion, t_shell;

    int tam = 100000;
    int vetor[tam];
    int i = 1;

    arquivo = fopen("numeros.txt", "r");

    if (!arquivo)
    {
        printf("Problema ao abrir o arquivo!\n");
        return;
    }

    while (i <= tam)
    {
        fscanf(arquivo, "%d", &vetor[i]);
        i++;
    }

    fclose(arquivo);

    i_quick = clock();
    quickSort(vetor, tam, 1, tam);
    f_quick = clock();
    t_quick = (double)(f_quick - i_quick) / CLOCKS_PER_SEC;

    i_bubble = clock();
    bubbleSort(vetor, tam);
    f_bubble = clock();
    t_bubble = (double)(f_bubble - i_bubble) / CLOCKS_PER_SEC;

    i_selection = clock();
    selectionSort(vetor, tam);
    f_selection = clock();
    t_selection = (double)(f_selection - i_selection) / CLOCKS_PER_SEC;

    i_insertion = clock();
    insertionSort(vetor, tam);
    f_insertion = clock();
    t_insertion = (double)(f_insertion - i_insertion) / CLOCKS_PER_SEC;

    i_shell = clock();
    shellSort(vetor, tam);
    f_shell = clock();
    t_shell = (double)(f_shell - i_shell) / CLOCKS_PER_SEC;

    i_heap = clock();
    heapSort(vetor, tam);
    f_heap = clock();
    t_heap = (double)(f_heap - i_heap) / CLOCKS_PER_SEC;

    fprintf(html_arq, "<tr><th scope=\"row\" class=\"posicoes\">100000</th>");
    fprintf(html_arq, "<td>%.3lf</td>", t_bubble);
    fprintf(html_arq, "<td>%.3lf</td>", t_selection);
    fprintf(html_arq, "<td>%.3lf</td>", t_insertion);
    fprintf(html_arq, "<td>%.3lf</td>", t_shell);
    fprintf(html_arq, "<td>%.3lf</td>", t_quick);
    fprintf(html_arq, "<td>%.3lf</td>", t_heap);
    fprintf(html_arq, "</tr></tbody></table></div>");
}
// metodos de ordenacao

void bubbleSort(int vet[], int TAM)
{
    int i, j, aux;

    for (i = 0; i < TAM - 1; i++)
    {
        for (j = i + 1; j < TAM; j++)
        {
            if (vet[i] > vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void insertionSort(int vet[], int TAM)
{
    int i, j, chave;

    for (i = 1; i < TAM; i++)
    {
        chave = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > chave)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = chave;
    }
}

void selectionSort(int vet[], int TAM)
{
    int i, j, min, aux;

    for (i = 0; i < (TAM - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < TAM; j++)
        {
            if (vet[j] < vet[min])
                min = j;
        }
        if (i != min)
        {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
}

void shellSort(int vet[], int TAM)
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
            valor = vet[i];
            j = i - h;
            while ((j >= 0) && (valor < vet[j]))
            {
                vet[j + h] = vet[j];
                j -= h;
            }
            vet[j + h] = valor;
        }
    } while (h > 1);
}

void quickSort(int vetor[], int tam, int inicio, int fim)
{
    vetor[tam];
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
        quickSort(vetor, tam, inicio, j);
    }
    if (i < fim)
    {
        quickSort(vetor, tam, i, fim);
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