#include <stdio.h>
#include <stdlib.h>

int construct_candidates(int *a, int *c, int k, int tamanhoA, int*vetorCandidatos, int nCandidatos, int N)
{
    int i;
    nCandidatos = 0;
    int chave;
    int *vetorBool;

    vetorBool = (int*)malloc((N+1)*sizeof(int));

    for(i=0; i<N; i++)
        vetorBool[i] = 0;

    for(i=1; i<=tamanhoA; i++){
        chave = a[i];
        if(chave != 0){
            vetorBool[chave] = 1;
        }
    }

    for(i=0; i<k; i++){
        chave = c[i];
        if(chave != 0){
            vetorBool[chave] = 0;
        }
    }

    for(i=1; i<=N; i++){
        if(vetorBool[i] == 1){
            vetorCandidatos[nCandidatos] = i;
            nCandidatos++;
        }
    }
    return nCandidatos;
}
void permuta(int *a, int* c, int tamanhoA, int N, int*vetorCoordenadas, int k){
    int i;
    int *vetorCandidatos;
    vetorCandidatos = (int*)malloc(tamanhoA*sizeof(int));

    int nCandidatos;

    if(k==tamanhoA){
        int j = 0;
        for(i = 1; i<=N; i++){
            if(vetorCoordenadas[i]!=0)
                printf("%i ", vetorCoordenadas[i]);
            else{
                printf("%i ", c[j]);
                j++;
            }
        }
        printf("\n");
    }
    else{
        nCandidatos = construct_candidates(a, c, k, tamanhoA, vetorCandidatos, nCandidatos, N);
        for(i=0; i<nCandidatos; i++){
            c[k] = vetorCandidatos[i];
            permuta(a, c,tamanhoA, N, vetorCoordenadas, ++k);
            k--;
        }
    }
}


int main(){
    int i, coordenadaX, coordenadaY, N, M;
    int *vetorCoordenadas;
    int *vAux;
    int chave;
    int tamanhoA = 0;

    scanf("%i %i", &N, &M);

    vetorCoordenadas = (int*)malloc((N+1)*sizeof(int));
    vAux = (int*)malloc((N+1)*sizeof(int));

    for(i=1; i<=N; i++){
        vetorCoordenadas[i] = 0;
        vAux[i] = 0;
    }

    for(i=1; i<=M; i++){
        scanf("%i %i", &coordenadaX, &coordenadaY);
        vetorCoordenadas[coordenadaY] = coordenadaX;
    }

    for(i=1; i<=N; i++){
        chave = vetorCoordenadas[i];
        if(chave == 0)
            tamanhoA++;
        vAux[chave] = 1;

    }
    int j = 1;
    int *a;
    a = (int*)malloc(tamanhoA*sizeof(int));

    for(i=1; i<=N; i++){
        if(vAux[i] == 0){
            a[j] = i;
            j++;
        }
    }

    int *c;
    c = (int*)malloc(tamanhoA*sizeof(int));
    
    permuta(a, c, tamanhoA, N, vetorCoordenadas, 0);
    return 0;
}
