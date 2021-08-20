#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[15];
    int tam_nome;
}nomes;

void counting(nomes *A, nomes *B, int col, int n_nomes){
    int C[27];
    int i;

    for(i=0; i<27; i++)
        C[i]=0;

    for (i=0; i<n_nomes; i++)
        C[(A[i].nome[col]-96)]++;

    for (i=1; i<27; i++)
        C[i] = C[i]+C[i-1];

    for (i=0; i<27;i++)
        printf("%d ", C[i]);

    for (i=n_nomes-1; i>=0; i--){
        B[C[A[i].nome[col]-96]-1] = A[i];
        C[A[i].nome[col]-96]--;
    }

    for(i=0; i<n_nomes; i++)
        A[i]=B[i];
}

void radix(nomes *A, int d, int n_nomes){
    int i;
    nomes *B;
    B=malloc(n_nomes*sizeof(nomes));
    for(i=d-1; i>=0; i--){
        counting(A, B, i, n_nomes);
        printf("\n");
    }

}

int main(){
    nomes *n;

    int n_nomes, i, j, maior_string, P, M;

    scanf("%d", &n_nomes);

    n=(nomes*)malloc(n_nomes*sizeof(nomes));

    for(i=0; i<n_nomes; i++){
        scanf("%s",n[i].nome);
    }


    for (i=0; i<n_nomes; i++)
        n[i].tam_nome = strlen(n[i].nome);


    for(j=0; j<n_nomes; j++){ // para deixar tudo minusculo
        for(i=0; i<strlen(n[j].nome); i++){
            if (n[j].nome[i]>='A'&&n[j].nome[i]<='Z')
                n[j].nome[i]=(n[j].nome[i]-'A')+'a';
        }
    }

    maior_string = strlen(n[0].nome);           //maior string
    for(i=1; i<n_nomes; i++){
        if (strlen(n[i].nome)>maior_string)
            maior_string = strlen(n[i].nome);
    }

    for (i=0; i<n_nomes; i++){
        if((n[i].tam_nome)<maior_string){
            for(j=n[i].tam_nome; j<=maior_string; j++)
                n[i].nome[j]='`';
        }
    }

    scanf("%d", &P);
    scanf("%d", &M);

    radix(n, maior_string,n_nomes);

    for(i=0; i<n_nomes; i++)
        n[i].nome[n[i].tam_nome] = '\0';

    for(i=P-1; i<P+M-1;i++)
        puts(n[i].nome);

    return 0;
}
