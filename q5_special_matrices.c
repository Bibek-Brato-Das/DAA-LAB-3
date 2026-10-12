#include <stdio.h>
#include <stdlib.h>
int c;
void mul(int n, int a[n][n], int b[n][n], int r[n][n]){
    int h = n/2, i, j;
    if(n == 1){ r[0][0] = a[0][0]*b[0][0]; c++; return; }
    int sa[h][h], da[h][h], sb[h][h], db[h][h], s[h][h], d[h][h];
    for(i=0; i<h; i++) for(j=0; j<h; j++){
        sa[i][j] = a[i][j] + a[i][j+h];     // A1 + A2
        da[i][j] = a[i][j] - a[i][j+h];     // A1 - A2
        sb[i][j] = b[i][j] + b[i][j+h];     // B1 + B2
        db[i][j] = b[i][j] - b[i][j+h];     // B1 - B2
        c += 4;
    }
    mul(h, sa, sb, s);                       // S = P + Q
    mul(h, da, db, d);                       // D = P - Q
    for(i=0; i<h; i++) for(j=0; j<h; j++){
        r[i][j]     = (s[i][j] + d[i][j])/2;   // P
        r[i+h][j+h] = (s[i][j] + d[i][j])/2;   // P
        r[i][j+h]   = (s[i][j] - d[i][j])/2;   // Q
        r[i+h][j]   = (s[i][j] - d[i][j])/2;   // Q
        c += 4;
    }
}
int main(){
    int n, i, j, k, t, ok, f[64], g[64];
    printf("n\tops\t4n^2-3n\tcorrect\n");
    for(n=1; n<=64; n=n*2){
        int a[n][n], b[n][n], r[n][n];
        for(i=0; i<n; i++){ f[i] = rand()%10; g[i] = rand()%10; }
        for(i=0; i<n; i++) for(j=0; j<n; j++){
            a[i][j] = f[i^j];      // i^j (XOR) gives exactly the block pattern
            b[i][j] = g[i^j];
        }
        c = 0;
        mul(n, a, b, r);
        ok = 1;
        for(i=0; i<n; i++) for(j=0; j<n; j++){   // normal multiplication to check
            t = 0;
            for(k=0; k<n; k++) t += a[i][k]*b[k][j];
            if(t != r[i][j]) ok = 0;
        }
        printf("%d\t%d\t%d\t%d\n", n, c, 4*n*n-3*n, ok);
    }
    return 0;
}
