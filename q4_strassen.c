#include <stdio.h>
void ad(int n, int a[n][n], int b[n][n], int c[n][n], int s){   // c = a + s*b
    int i, j;
    for(i=0; i<n; i++) for(j=0; j<n; j++) c[i][j] = a[i][j] + s*b[i][j];
}
void mul(int n, int a[n][n], int b[n][n], int c[n][n]){
    int h = n/2, i, j;
    if(n == 1){ c[0][0] = a[0][0]*b[0][0]; return; }
    int a11[h][h], a12[h][h], a21[h][h], a22[h][h];
    int b11[h][h], b12[h][h], b21[h][h], b22[h][h];
    int m1[h][h], m2[h][h], m3[h][h], m4[h][h], m5[h][h], m6[h][h], m7[h][h];
    int t1[h][h], t2[h][h];
    for(i=0; i<h; i++) for(j=0; j<h; j++){
        a11[i][j] = a[i][j];   a12[i][j] = a[i][j+h];
        a21[i][j] = a[i+h][j]; a22[i][j] = a[i+h][j+h];
        b11[i][j] = b[i][j];   b12[i][j] = b[i][j+h];
        b21[i][j] = b[i+h][j]; b22[i][j] = b[i+h][j+h];
    }
    ad(h,a11,a22,t1,1);  ad(h,b11,b22,t2,1);  mul(h,t1,t2,m1);
    ad(h,a21,a22,t1,1);  mul(h,t1,b11,m2);
    ad(h,b12,b22,t2,-1); mul(h,a11,t2,m3);
    ad(h,b21,b11,t2,-1); mul(h,a22,t2,m4);
    ad(h,a11,a12,t1,1);  mul(h,t1,b22,m5);
    ad(h,a21,a11,t1,-1); ad(h,b11,b12,t2,1); mul(h,t1,t2,m6);
    ad(h,a12,a22,t1,-1); ad(h,b21,b22,t2,1); mul(h,t1,t2,m7);
    for(i=0; i<h; i++) for(j=0; j<h; j++){
        c[i][j]     = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
        c[i][j+h]   = m3[i][j] + m5[i][j];
        c[i+h][j]   = m2[i][j] + m4[i][j];
        c[i+h][j+h] = m1[i][j] - m2[i][j] + m3[i][j] + m6[i][j];
    }
}
int main(){
    int n, i, j;
    printf("n (power of 2): ");
    scanf("%d", &n);
    int a[n][n], b[n][n], c[n][n];
    printf("matrix A:\n");
    for(i=0; i<n; i++) for(j=0; j<n; j++) scanf("%d", &a[i][j]);
    printf("matrix B:\n");
    for(i=0; i<n; i++) for(j=0; j<n; j++) scanf("%d", &b[i][j]);
    mul(n, a, b, c);
    printf("A x B:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++) printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
