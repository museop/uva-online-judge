#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    while (true) {
        int totalV, V0;
        scanf("%d %d", &totalV, &V0);
        if (totalV == 0 && V0 == 0) break;
        double maxValue = 0;
        int ret = 0;
        int retCnt = 0;
        for (int i = 1; i <= 60000; i++) {
            double V = totalV / (double)i; 
            if (V <= V0) break;
            double value = i * sqrt(V - V0);
            if (abs(maxValue - value) < 1e-9) {
                retCnt++;
            } else if (maxValue < value) {
                maxValue = value;
                retCnt = 0;
                ret = i;
            }
        }
        printf("%d\n", retCnt == 0 ? ret : 0);
    }
}
// NOTE: 실수 비교 연산의 오차를 잘 처리할 수 있는지가 중요