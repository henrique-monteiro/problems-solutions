#include <stdio.h>
#include <stdlib.h>

int partition(int *saldo, int p, int r){
    int aux, x, i, j;
    x = saldo[r];
    i = p-1;
    for (j=p; j<r; j++){
        if (saldo[j]<=x){
            i++;
            aux = saldo[i];
            saldo[i] = saldo[j];
            saldo[j] = aux;
        }
    }
    aux = saldo[i+1];
    saldo[i+1] = saldo[r];
    saldo[r] = aux;
    return i+1;
}

void quicksort(int *saldo, int p, int r){
    int q;
    if (p<r){
        q = partition(saldo, p, r);
        quicksort(saldo, p, q-1);
        quicksort(saldo, q+1, r);
    }
}

int main(){
    int N, G, favor, contra, i, n_pontos=0;
    int *saldo;

    scanf("%d", &N);
    scanf("%d", &G);

    saldo = (int*)malloc(N*sizeof(int));

    for (i=0; i<N; i++){
        scanf("%d", &favor);
        scanf("%d", &contra);
        saldo[i] = favor-contra;
    }

    quicksort(saldo, 0, N-1);


    for (i=N-1; i>=0; i--){
        if (saldo[i]>=1){
            n_pontos = n_pontos+3;
        }
        else if (saldo[i]==0 && G>=1){
            n_pontos = n_pontos+3;
            G--;
        }
        else if (saldo[i]==0 && G==0){
            n_pontos++;
        }
        else if (saldo[i]<0){
            if (saldo[i]+G>0){
                n_pontos = n_pontos+3;
                G = G+saldo[i]-1;
            }
            else if (saldo[i]+G==0){
                n_pontos++;
                G = G+saldo[i];
            }
        }
    }

    printf("%d", n_pontos);

    return 0;
}
