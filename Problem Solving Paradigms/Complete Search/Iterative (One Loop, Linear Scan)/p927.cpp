#include <stdio.h>

int c[10001];

long long mpow(int a, int b) {
    long long ret = 1;
    for (int i = 0; i < b; i++) {
        ret *= a;
    }
    return ret;
}


int main() {
    freopen("input.txt", "r", stdin);
    int C;
    scanf("%d", &C);
    while (C--) {
        int n, d, k;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            scanf("%d", &c[i]);
        }
        scanf("%d%d", &d, &k);
        int j = 1;
        while (k > d * (j * (j+1)) / 2) j++;
        long long aj = 0;
        for (int i = 0; i <= n; i++) {
            aj = aj + c[i] * mpow(j, i);
        }
        printf("%lld\n", aj);
    }
}