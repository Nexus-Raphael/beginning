#include<stdio.h>
#define M 31623
#define N 1000000
int B[N + 1];
int A[M + 1] = {0, 0};
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}
int main() {
    int T;
    long long le, ri, i, j, j0, cnt;
    for (i = 2; i <= M; i++) A[i] = 1;
    for (i = 2; i * i <= M; i++)
        if (A[i]) for (j = i * i; j <= M; j += i) A[j] = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &le, &ri);
        for (i = le; i <= ri; i++) B[i - le] = 1;
        if (le == 1) B[0] = 0;
        for (i = 2; i <= M; i++) {
            if (A[i]) {
                j0 = max((le + i - 1) / i * i, i * i);
                for (j = j0; j <= ri; j += i) {
                    B[j - le] = 0;
                }
            }
        }
        cnt = 0;
        for (i = le; i <= ri; i++) {
            cnt += B[i - le];
        }
        printf("%d\n", cnt);
    }
}
