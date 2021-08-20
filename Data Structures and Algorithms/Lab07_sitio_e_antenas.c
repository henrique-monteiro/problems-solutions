#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}

int sitioAntenas(int *rua, int *residencias, int *tabela, int C, int N, int t1, int t2, int indice, int j)
{
    //condição de parada da recursão
    if(indice >= residencias[N-1])
        return 0;

    int i=j;
    while(residencias[i]<=indice)
        i++;

    indice = residencias[i];

    if(tabela[indice] != 0)
        return tabela[indice];

    tabela[indice] = min(t1+sitioAntenas(rua, residencias, tabela, C, N,t1, t2, indice+t1, i),
                    t2+sitioAntenas(rua, residencias, tabela, C, N, t1, t2, indice+t2, i));

    return tabela[indice];
}

int main()
{
    int i;
    int N, C, t1, t2;
    /*
        N = número de antenas
        C = tamanho da rua
        t1 = alcance da antena 1
        t2 = alcance da antena 2
    */
    scanf("%i %i %i %i", &N, &C, &t1, &t2);

    int *rua;
    rua = (int*)malloc((C+1)*sizeof(int));

    int *residencias;
    residencias = (int*)malloc(N*sizeof(int));

    //entrando com as localizações das residencias
    for(i=0; i<N; i++)
        scanf("%i", &residencias[i]);

    //zerando vetor rua
    for(i=0; i<=C; i++)
        rua[i] = 0;

    int *tabela;
    tabela = (int*)malloc((C)*sizeof(int));

    for(i=0; i<C; i++)
        tabela[i] = 0;

    printf("%i", sitioAntenas(rua, residencias, tabela, C, N, t1, t2, 0, 0));

    return 0;
}
