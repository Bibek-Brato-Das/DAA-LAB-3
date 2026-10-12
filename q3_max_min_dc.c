#include <stdio.h>
#include <stdlib.h>
int mx, mn, c;
void mm(int a[], int l, int r){
    int n = r-l+1, m, mx1, mn1;
    if(n == 1){ mx = mn = a[l]; return; }
    if(n == 2){
        c++;
        if(a[l] > a[r]){ mx = a[l]; mn = a[r]; }
        else{ mx = a[r]; mn = a[l]; }
        return;
    }
    m = l + 2*((n+2)/4) - 1;      // left part gets an even size
    mm(a, l, m);
    mx1 = mx; mn1 = mn;           // save the left answer
    mm(a, m+1, r);               // mx, mn now hold the right answer
    c += 2;
    if(mx1 > mx) mx = mx1;
    if(mn1 < mn) mn = mn1;
}
int main(){
    int s[6] = {8, 10, 64, 100, 512, 1000}, k, n, i, a[1000];
    printf("n\tmax\tmin\tcomparisons\t3n/2\n");
    for(k=0; k<6; k++){
        n = s[k];
        for(i=0; i<n; i++) a[i] = rand() % 10000;
        c = 0;
        mm(a, 0, n-1);
        printf("%d\t%d\t%d\t%d\t\t%d\n", n, mx, mn, c, 3*n/2);
    }
    return 0;
}
