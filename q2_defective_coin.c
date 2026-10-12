#include <stdio.h>
int w[1000], cnt;
int find(int l, int r, int known){
    int n = r-l+1, m = n/2, s1 = 0, s2 = 0, i;
    if(n == 1 && known) return l;
    for(i=0; i<m; i++){ s1 += w[l+i]; s2 += w[l+m+i]; }   // the balance
    cnt++;
    if(s1 < s2) return find(l, l+m-1, 1);        // left pan lighter
    if(s2 < s1) return find(l+m, l+2*m-1, 1);    // right pan lighter
    if(n % 2 == 0) return -1;                    // equal, no leftover coin
    if(known) return r;                          // leftover coin must be defective
    cnt++;                                       // compare leftover with a genuine coin
    if(w[r] < w[l]) return r;
    return -1;
}
int main(){
    int n, p, i, r;
    printf("n and index of lighter coin (-1 for none): ");
    scanf("%d %d", &n, &p);
    for(i=0; i<n; i++) w[i] = 10;
    if(p >= 0) w[p] = 9;
    r = find(0, n-1, 0);
    printf("defective coin: %d, weighings: %d\n", r, cnt);
    return 0;
}
