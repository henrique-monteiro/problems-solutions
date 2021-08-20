#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont;
typedef struct{
    char nome[15];
}nomes;

int partition(nomes *n, int p, int r){

    nomes pivo = n[r], aux;
    int topo, i, j;

    i = p-1;

    for (j=p; j<r; j++){
        if (strcmp(n[j].nome,pivo.nome)<=0){ // coloca qndo é
            i++;
            aux = n[i];
            n[i] = n[j];
            n[j] = aux;
        }
    }
    aux = n[i+1];
    n[i+1] = n[r];
    n[r] = aux;

    cont++;

    return i+1;

}

void quicksort(nomes *n, int p, int r){
    int q;
    if (p<r){
        q = partition(n, p, r);
        quicksort(n, p, q-1);
        quicksort(n, q+1, r);
    }

}

int main(){
    nomes n[100000];
    int n_nomes, i, j, p, m;

    scanf("%d", &n_nomes);

    for(i=0; i<n_nomes; i++){
        scanf("%s",n[i].nome);
    }
    scanf("%d", &p);
    scanf("%d", &m);

    for(j=0; j<n_nomes; j++){ // para deixar tudo minusculo
        for(i=0; i<strlen(n[j].nome); i++){
            if (n[j].nome[i]>='A'&&n[j].nome[i]<='Z')
                n[j].nome[i]=(n[j].nome[i]-'A')+'a';
        }
    }

    cont = 0;
    quicksort (n, 0, n_nomes-1);

    printf("%d\n", cont);

    for (i=p-1; i<p+m-1; i++)
        puts(n[i].nome);
    return 0;
}
