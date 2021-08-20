#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
} Elem;

typedef struct fila{
    Elem *inicio;
    Elem *fim;
} Fila;

Fila* cria_Fila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if(f!=NULL){
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

void insere_Fila(Fila* f, int valor){
    Elem *no = (Elem*) malloc(sizeof(Elem));
    no->valor = valor;
    no->prox = NULL;

    if(f->fim == NULL) //se fila vazia
        f->inicio = no;
    else
        f->fim->prox = no;
    f->fim = no;
}

int remove_Fila(Fila* f){
    if (f->inicio==f->fim && f->fim!=NULL){
        f->fim = NULL;
        f->inicio = NULL;
        return -1;
    }
    else if (f->inicio!=NULL){
        f->inicio = f->inicio->prox;
        return f->inicio->valor;
    }
}

int consulta_Fila(Fila* f){
    if(f == NULL)
        return 0;
    if(f->inicio == NULL)
        return 0;
    return f->inicio->valor;
}

void build_min_heap(Fila** A, int tam){
    int i;
    for (i=tam/2; i>=0; i--){
        min_heap(A, i, tam);
    }
}


void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *)malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1]<V[p2])//combinar ordenado
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];

                if(p1>meio)//vetor acabou?
                    fim1=1;
                if(p2>fim)
                    fim2=1;
            }
            else{
                if(!fim1)//copia o que sobrar
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)//copiar do auxiliar para o original
            V[k]=temp[j];
    }
    free(temp);

}

void mergesort(int *V, int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio = ((inicio+fim)/2);
        mergesort(V, inicio, meio);
        mergesort(V, meio+1, fim);
        merge(V, inicio, meio, fim); // combina as duas metades de forma ordenada
    }
}


void min_heap(Fila **A, int i, int tam){
    int left = 2*i;
    int right = (2*i+1);

    int min;

    if ((left < tam) && (consulta_Fila(A[left]) < consulta_Fila(A[i])))
        min=left;

    else min=i;

    if ((right < tam) && (consulta_Fila(A[right]) < consulta_Fila(A[min])))
        min=right;

    if (min!=i){
        Fila *aux;
        aux=A[i];
        A[i]=A[min];
        A[min]=aux;

        min_heap(A, min, tam);
    }
}

int main(){
    int k, I; // k é a qtde de vetores

    scanf("%i %i", &k, &I);

    int tamanho_vetor, valor;
    int i, j;

    Fila *kvetores[k];

    i=0;
    while(i<k){
        kvetores[i] = cria_Fila(); //cada elemento da Fila aponta para um kvetor
        scanf("%i", &tamanho_vetor);

        if (tamanho_vetor!=0){

            j=0;
            while(j<tamanho_vetor){
                scanf("%i", &valor);
                insere_Fila(kvetores[i], valor);
                j++;
            }
        }
        else{
            i--;
            k--;
        }

        i++;
    }

    build_min_heap(kvetores, k);

    i=0;
    while(i<I-1){
        if (remove_Fila(kvetores[0])==-1){
            kvetores[0]=kvetores[k-1];
            k--;
        }
        min_heap(kvetores, 0, k);
        i++;
    }

    int resultado[k];

    for (i=0; i<k; i++){
        if (kvetores[i]!=NULL)
            resultado[i]=consulta_Fila(kvetores[i]);
        else{
            i--;
            k--;
        }
    }

    mergesort(resultado,0,k-1);

    for (i=0; i<k; i++)
        printf("%i ", resultado[i]);


}
