#include <stdio.h>
#include <stdlib.h>

int bubble(int *v, int n){
    int i, aux, j, r=0;
    for (i=n-1; i>0; i--){
        for (j=0; j<i; j++){
            if (v[j]>v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                r++;
            }
        }
    }
    return r;
}

int main()
{
    int n, *v, i, resul;
    scanf("%d", &n);
    v = (int)malloc(n*sizeof(int));
    for (i=0; i<n; i++)
        scanf("%d",&v[i]);

    resul = bubble(v,n);

    if (resul%2==0)
        printf("Carlos");
    else
        printf("Marcelo");

    return 0;
}
