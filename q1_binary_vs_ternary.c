#include <stdio.h>
int c1, c2;
int bs(int a[], int n, int x){
    int lo = 0, hi = n-1, mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        c1++; if(a[mid] == x) return mid;
        c1++; if(a[mid] < x) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}
int ts(int a[], int n, int x){
    int lo = 0, hi = n-1, m1, m2;
    while(lo <= hi){
        m1 = lo + (hi-lo)/3;
        m2 = hi - (hi-lo)/3;
        c2++; if(a[m1] == x) return m1;
        c2++; if(a[m2] == x) return m2;
        c2++;
        if(x < a[m1]) hi = m1-1;
        else{
            c2++;
            if(x > a[m2]) lo = m2+1;
            else{ lo = m1+1; hi = m2-1; }   // middle part
        }
    }
    return -1;
}
int main(){
    int n, i, x, a[1000];
    printf("n\tbinary\tternary\n");
    for(n=100; n<=1000; n+=100){
        for(i=0; i<n; i++) a[i] = i;
        for(x=0; x<n; x++)                  // correctness check
            if(bs(a,n,x) != x || ts(a,n,x) != x) printf("wrong at %d\n", x);
        c1 = 0; c2 = 0;
        bs(a, n, n); ts(a, n, n);           // n is larger than all elements
        printf("%d\t%d\t%d\n", n, c1, c2);
    }
    return 0;
}
