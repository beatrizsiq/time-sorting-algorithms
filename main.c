#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "metodos_ordenacao.h"
#include <locale.h>

main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Começando a ordenar!");
    FILE *html_arq;
    int tam1=500, tam2=2500, tam3=5000;
    int vetor1[tam1], vetor2[tam2], vetor3[tam3];

    html_arq = fopen("index.html", "w");

    head_nav_table();
    ordenacao(vetor1, tam1);
    ordenacao(vetor2, tam2);
    ordenacao(vetor3, tam3);
    section_html();
    fclose(html_arq);

}

void head_nav_table(){
    FILE *html_arq;
    
    html_arq = fopen("index.html", "a");

    fprintf(html_arq, "<!DOCTYPE html><html lang=\"pt-br\"><head><title>Tempo de Ordenação</title><link rel=\"icon\" type=\"image/x-icon\" href=\"relogio.ico\"><meta charset=\"UTF-8\">");
    fprintf(html_arq, "<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css\"rel=\"stylesheet\" integrity=\"sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3\" crossorigin=\"anonymous\">");
    fprintf(html_arq, "<link rel=\"stylesheet\" href=\"index.css\">");
    fprintf(html_arq, "</head><body	>");
    // nav
    fprintf(html_arq, "<nav class=\"navbar sticky-top navbar-expand-lg  d-flex \"> <div class=\"container-fluid\"> <a class=\"navbar-brand\" href=\"index.html\">Tempo de Execução</a>");
    fprintf(html_arq, "<div class=\"collapse navbar-collapse\" id=\"navbarNavAltMarkup\"> <div class=\"navbar-nav\"> <a class=\"nav-link active\" aria-current=\"page\" href=\"#sobreSection\">Sobre</a> <a class=\"nav-link\" href=\"#criadoraSection\">Criadora</a> </div></div></div></nav>");
    fprintf(html_arq, "<div class=\" d-flex justify-content-center mt-5\"><h3>Algoritmos de Ordenação</h3></div>");
    // table
    fprintf(html_arq, "<div class=\"container mt-3 col-12 \" >");
    fprintf(html_arq, "<table class=\"table table-borderless\"><thead><tr ><th scope=\"col\">Posições</th><th scope=\"col\" ><a class=\"table-link\" href = \"https://blog.betrybe.com/tecnologia/bubble-sort-tudo-sobre/\">Bubble Sort</a></th><th scope=\"col\"><a class=\"table-link\" href = \"https://joaoarthurbm.github.io/eda/posts/selection-sort/\">Selection Sort</a></th><th scope=\"col\"><a class=\"table-link\" href = \"https://joaoarthurbm.github.io/eda/posts/insertion-sort/\">Insertion Sort</a></th><th scope=\"col\"><a class=\"table-link\" href = \" https://pt.wikipedia.org/wiki/Shell_sort\">Shell Sort</a></th><th scope=\"col\"><a class=\"table-link\" href = \" https://pt.wikipedia.org/wiki/Quick_sort\">Quick Sort</a></th><th scope=\"col\"><a class=\"table-link\" href = \" https://pt.wikipedia.org/wiki/Heap_sort\">Heap Sort</a></th></tr></thead><tbody>");
}

void section_html(void){
    FILE *html_arq;
    
    html_arq = fopen("index.html", "a");

    fprintf(html_arq, "</tbody></table></div>");
    fprintf(html_arq, " <section id=\"sobreSection\" class=\"default-sections-min-height col-12 py-5\"><div class=\"container mt-5\"><div class=\"card border-0 \"><h5 class=\"card-header\">SOBRE</h5><div class=\"card-body border-0\">");
    fprintf(html_arq, "<p class=\"card-text\">O <a class=\"link-algoritmo\"href=\"https://github.com/beatrizsiq/time-sorting-algorithms\">algoritmo</a> está realizando a leitura de outro arquivo com números inteiros e alocando-os em um vetor, para que seja realizada a ordenação com os métodos supracitados. Após isso, foi gerado este arquivo HTML para impressão do tempo de execução de cada método.</p><p>Tecnologias utilizadas: Linguagem C, HTML, CSS e Bootstrap!</p><p>Trabalho para a disciplina de Ordenação e Pesquisa.</p></div></div></div></section>");
	fprintf(html_arq, "<section id=\"criadoraSection\" class=\"default-sections-min-height col-12 py-5\"> <div class=\"container mt-5\"><div class=\"card border-0 \"><h5 class=\"card-header\">CRIADORA</h5><div class=\"card-body border-0\">");
	fprintf(html_arq, "<div class=\"col-12 d-flex justify-content-center\"><img src=\"beatrizPicture.jpg\" alt=\"Beatriz Siqueira\" class=\"rounded-circle w-25\"></div>");
	fprintf(html_arq, "<div class=\"col-12 py-2 mt-3 text-left\"><p>Olá, me chamo Beatriz Siqueira! Estou no 3º Período do curso de Sistemas de Informação. Atualmente trabalho com suporte e desenvolvimento em banco de dados Oracle</p><p>Estudando: PHP, JavaScript, HTML, CSS e Bootstrap!</p></div>");
	fprintf(html_arq, "<div class=\"col-12 py-2 mt-3 text-left\"><p>Contato: <ul> <li><a href=\"https://github.com/beatrizsiq\" class=\"git\">Github</a></li><li><a href=\"https://instagram.com/beasiqueiras_\" class=\"insta\">Instagram</a></li></ul></p>");
	fprintf(html_arq, "</div></div></div></div></section>");
	fprintf(html_arq, "</body></html>");

}

void ordenacao(int vetor[], int tam){
    printf("\nOrdenando %d posicoes...", tam);
    FILE *arquivo;
    FILE *html_arq;

    html_arq = fopen("index.html", "a");

    clock_t i_quick, f_quick, i_bubble, f_bubble, i_selection, f_selection, i_insertion, f_insertion, i_shell, f_shell, i_heap, f_heap;
    double t_quick, t_bubble, t_heap, t_selection, t_insertion, t_shell;

    int i = 1;

    arquivo = fopen("numeros.txt", "r");

    if (!arquivo){
        printf("Problema ao abrir o arquivo!\n");
        return;
    }

    while (i <= tam){
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

    fprintf(html_arq, "<tr><th scope=\"row\" class=\"posicoes\">%d</th>", tam);
    fprintf(html_arq, "<td>%.3lf</td>", t_bubble);
    fprintf(html_arq, "<td>%.3lf</td>", t_selection);
    fprintf(html_arq, "<td>%.3lf</td>", t_insertion);
    fprintf(html_arq, "<td>%.3lf</td>", t_shell);
    fprintf(html_arq, "<td>%.3lf</td>", t_quick);
    fprintf(html_arq, "<td>%.3lf</td>", t_heap);
    fprintf(html_arq, "</tr>");
}