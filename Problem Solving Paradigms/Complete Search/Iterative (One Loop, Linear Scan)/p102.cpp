#include <stdio.h>

const char *bins[] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
int c2d[128];
int c[3][3];

int main() {
    freopen("input.txt", "r", stdin);
    c2d['B'] = 0;
    c2d['C'] = 1;
    c2d['G'] = 2;
    while (scanf("%d %d %d %d %d %d %d %d %d", &c[0][0], &c[0][2], &c[0][1], &c[1][0], &c[1][2], &c[1][1], &c[2][0], &c[2][2], &c[2][1]) != EOF) {
        long long value = 1LL << 32;
        int idx = 0;
        for (int i = 0; i < 6; i++) {
            const char* bin = bins[i];
            long long cand = 0;
            for (int j = 0; j < 3; j++) {
                int d = c2d[bin[j]];
                for (int k = 0; k < 3; k++) {
                    if (d != k) {
                        cand += c[j][k];
                    }
                }
            }
            if (value > cand) {
                value = cand;
                idx = i;
            }
        }
        printf("%s %lld\n", bins[idx], value);
    }
    
    return 0;
}