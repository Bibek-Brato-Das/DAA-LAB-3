#include <stdio.h>
int sel(int a[], int n){
    int i, j, min, t, c = 0;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            c++;
            if(a[j] < a[min]) min = j;
        }
        t = a[i]; a[i] = a[min]; a[min] = t;
    }
    return c;                       // number of comparisons
}
int main(){
    int n, i, c1, c2, a[100], b[100];
    printf("n\tsorted\treverse\tn(n-1)/2\n");
    for(n=10; n<=50; n+=10){
        for(i=0; i<n; i++){ a[i] = i; b[i] = n-i; }
        c1 = sel(a, n);             // best case input
        c2 = sel(b, n);             // worst case input
        for(i=1; i<n; i++)
            if(b[i] < b[i-1]) printf("not sorted\n");
        printf("%d\t%d\t%d\t%d\n", n, c1, c2, n*(n-1)/2);
    }
    return 0;
}
