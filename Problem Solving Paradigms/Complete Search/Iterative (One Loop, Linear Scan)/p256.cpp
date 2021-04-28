#include <bits/stdc++.h>

using namespace std;

const char* fmt[] = { "%02d\n", "%04d\n", "%06d\n", "%08d\n" };
vector<int> s[4];

bool check(long long num, int digits) {
    int d = 1;
    for (int i = 0; i < digits; i++) {
        d *= 10;
    }
    long long a = num / d;
    long long b = num % d;
    long long t = a + b;
    return num == t * t;
}

void precalc() {
    for (int i = 0; i <= 99; i++) {
        if (check(i, 1)) {
            s[0].push_back(i);
        }
    }
    for (int i = 0; i <= 9999; i++) {
        if (check(i, 2)) {
            s[1].push_back(i);
        }
    }
    for (int i = 0; i <= 999999; i++) {
        if (check(i, 3)) {
            s[2].push_back(i);
        }
    }
    for (int i = 0; i <= 99999999; i++) {
        if (check(i, 4)) {
            s[3].push_back(i);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    precalc();
    int n;
    while (scanf("%d", &n) != EOF) {
        int x = n/2 - 1;
        for (int i = 0; i < s[x].size(); i++) {
            printf(fmt[x], s[x][i]);
        }
    }
}
