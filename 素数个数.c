#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000000

// 计算小于等于n的所有素数，使用埃拉托斯特尼筛法
void sieve_of_eratosthenes(int n, bool prime[]) {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; i++) {
        prime[i] = true;
    }
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}
// 获取所有小于等于sqrt(R)的素数
void get_primes_up_to_sqrt_r(int limit, int primes[], int *prime_count) {
    bool prime[limit + 1];
    sieve_of_eratosthenes(limit, prime);
    *prime_count = 0;
    for (int i = 2; i <= limit; i++) {
        if (prime[i]) {
            primes[*prime_count] = i;
            (*prime_count)++;
        }
    }
}
// 区间筛法，统计区间[L, R]中的素数
int count_primes_in_range(int L, int R, int primes[], int prime_count) {
    bool *is_prime = (bool *)malloc((R - L + 1) * sizeof(bool));
    // 初始化区间的标记数组，假设每个数都是素数
    for (int i = 0; i <= R - L; i++) {
        is_prime[i] = true;
    }

    // 处理L = 1的情况
    if (L == 1) {
        is_prime[0] = false;
    }

    // 用小素数筛掉区间[L, R]中的合数
    for (int i = 0; i < prime_count; i++) {
        int p = primes[i];
        
        // 找到p的第一个倍数在[L, R]区间的起始位置
        int start = (L / p) * p;
        if (start < L) {
            start += p;
        }

        // 从start开始标记所有p的倍数为合数
        for (int j = start; j <= R; j += p) {
            if (j != p) {  // 排除p本身
                is_prime[j - L] = false;
            }
        }
    }

    // 统计素数个数
    int count = 0;
    for (int i = 0; i <= R - L; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    free(is_prime);
    return count;
}

int main() {
    int T;
    scanf("%d", &T);  // 输入查询次数

    // 查询数组
    int queries[T][2];
    int max_r = 0;

    // 输入所有查询，并记录最大R值
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &queries[i][0], &queries[i][1]);
        if (queries[i][1] > max_r) {
            max_r = queries[i][1];
        }
    }

    // 获取所有小于等于sqrt(max_r)的素数
    int limit = (int) sqrt(max_r) + 1;
    int primes[MAX], prime_count = 0;
    get_primes_up_to_sqrt_r(limit, primes, &prime_count);

    // 对每个查询区间，计算素数个数
    for (int i = 0; i < T; i++) {
        int L = queries[i][0];
        int R = queries[i][1];
        int prime_count_in_range = count_primes_in_range(L, R, primes, prime_count);
        printf("%d\n", prime_count_in_range);
    }

    return 0;
}