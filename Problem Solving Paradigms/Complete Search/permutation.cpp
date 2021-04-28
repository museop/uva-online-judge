#include <iostream>
using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/***
 * 순열 알고리즘
 * a[idx]를 정해가면서 모든 순열을 출력하는 재귀함수
 * 순열의 순서가 사전순은 아님
 * 중복된 원소가 있는 경우, 중복된 순열이 출력됨
 */
void permutation(int a[], int idx, int n) {
    if (idx == n) {
        printArray(a, n);
        return;
    }
    for (int i = idx; i < n; i++) {
        swap(a[idx], a[i]);
        permutation(a, idx + 1, n);
        swap(a[idx], a[i]);
    }
}

void rightRotate(int a[], int l, int r) {
    int last = a[r];
    for (int i = r; i > l; i--) {
        a[i] = a[i - 1];
    }
    a[l] = last;
}

void leftRotate(int a[], int l, int r) {
    int first = a[l];
    for (int i = l; i < r; i++) {
        a[i] = a[i + 1];
    }
    a[r] = first;
}


/***
 * 순열 알고리즘
 * a[idx]를 정해가면서 모든 순열을 출력하는 재귀함수
 * 첫 순열이 사전순일 경우, 출력되는 순열의 순서는 사전순은 아님
 * 중복된 원소가 있는 경우, 중복된 순열이 출력됨
 */
void permutationDict(int a[], int idx, int n) {
    if (idx == n) {
        printArray(a, n);
        return;
    }
    for (int i = idx; i < n; i++) {
        rightRotate(a, idx, i);
        permutationDict(a, idx + 1, n);
        leftRotate(a, idx, i);
    }
}

/***
 * 순열 알고리즘(k개의 원소로 이루어진)
 * a[idx]를 정해가면서 모든 순열을 출력하는 재귀함수
 * 순열의 순서가 사전순은 아님
 * 중복된 원소가 있는 경우, 중복된 순열이 출력됨
 */
void permutationK(int a[], int idx, int n, int k) {
    if (idx == k) {
        printArray(a, k);
        return;
    }
    for (int i = idx; i < n; i++) {
        swap(a[idx], a[i]);
        permutationK(a, idx + 1, n, k);
        swap(a[idx], a[i]);
    }
}


//https://en.wikipedia.org/wiki/Heap%27s_algorithm
void heapPermutation(int a[], int size, int n) {
    if (size == 1) {
        printArray(a, n);
        return;
    }
    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1, n);
        if (i < size - 1) {
            if (size % 2 == 1)
                swap(a[0], a[size - 1]);
            else
                swap(a[i], a[size - 1]);
        }
    }
}

/***
 * 사전순으로 다음 순열 생성하는 함수
 * 수열을 사전순으로 나열해보고, 이전 순열에서 다음 순열로 어떻게 변화하는지 관찰해보면 알고리즘이 도출됨
 * 1. i=n-1에서부터 a[i-1] < a[i]가 되는 i를 찾는다. (역순이 아닌 곳 찾기)
 * 2. j=n-1에서부터 a[i-1] < a[j]가 되는 j를 찾아 a[i-1]와 a[j]를 swap한다.
 * 3. a[i..n-1]을 뒤집는다.
 */
bool nextPermutation(int a[], int n) {
    int i = n - 1;
    while (i > 0 && a[i-1] >= a[i]) i--;
    if (i <= 0) return false;
    int j = n - 1;
    while (a[i-1] >= a[j]) j--;
    swap(a[i-1], a[j]);
    j = n - 1;
    while (i < j) {
        swap(a[i++], a[j--]);
    }
    return true;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    // permutation(a, 0, 5);
    permutationDict(a, 0, 5);
    // permutationK(a, 0, 5, 2);
    // heapPermutation(a, 5, 5);
    // do {
    //     printArray(a, 5);
    // } while (nextPermutation(a, 5));

    return 0;
}