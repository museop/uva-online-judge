#include <stdio.h>

const int MAXD = 10000;
char M[MAXD][25];
int L[MAXD], H[MAXD];

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int D;
        scanf("%d", &D);
        for (int i = 0; i < D; i++) {
            scanf("%s %d %d", M[i], L+i, H+i);
        }
        int Q;
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            int P;
            scanf("%d", &P);
            int idx = -1;
            int cnt = 0;
            for (int j = 0; j < D; j++) {
                if (P >= L[j] && P <= H[j]) {
                    cnt++;
                    idx = j;
                }
            }
            if (cnt == 1) {
                puts(M[idx]);
            } else {
                puts("UNDETERMINED");
            }
        }
        if (T) puts("");
    }
}
