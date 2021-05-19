#include <iostream>
using namespace std;

const int MAXN = 1e5;
const int NINF = -1e9;

int n;
int s[MAXN], maxs[MAXN], mins[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        maxs[0] = s[0];
        for (int i = 1; i < n; i++) {
            maxs[i] = max(s[i], maxs[i-1]);
        }
        mins[n-1] = s[n-1];
        for (int i = n-2; i >= 0; i--) {
            mins[i] = min(s[i], mins[i+1]);
        }
        int ret = NINF;
        for (int i = 0; i < n - 1; i++) {
            ret = max(ret, maxs[i] - mins[i+1]);
        }
        printf("%d\n", ret);
    }
}