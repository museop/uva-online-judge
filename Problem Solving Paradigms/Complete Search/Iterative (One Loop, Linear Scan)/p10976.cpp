#include <stdio.h>
#include <vector>
using namespace std;


int ans[10000][2];

int main() {
    freopen("input.txt", "r", stdin);
    int k;
    while (scanf("%d", &k) != EOF) {
        int cnt = 0;
        int ymax = k * 2;
        for (int y = k + 1; y <= ymax; y++) {
            int t1 = k * y;
            int t2 = y - k;
            if (t1 % t2 == 0) {
                ans[cnt][0] = t1 / t2;
                ans[cnt][1] = y;
                cnt++;
            }
        }
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; i++) {
            printf("1/%d = 1/%d + 1/%d\n", k, ans[i][0], ans[i][1]);
        }
    }
}