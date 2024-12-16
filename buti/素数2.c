#include<stdio.h>
#include<stdlib.h>
#define N 31623
int isprime[N+1];
int primes[N];
void f()
{
	int i, j;
	isprime[1]=1;
	for(i=2; i*i<=N; i++){
		if(isprime[i]==0){
			for(j=i*i; j<=N; j+=i){
				isprime[j]=1;
			}
		}
	}
	
	j=0;
	for(i=2; i<=N; i++){
		if(isprime[i]==0) primes[j++]=i;
	}
 } 
int main()
{
	f();
	int T;
	scanf("%d", &T);
	while(T--){
		long long L, R, count=0;
		scanf("%lld %lld", &L, &R);
		int *a=(int*)calloc(R-L+1, sizeof(int));
		
		long long i, j, k, t;
		for(i=0; primes[i]!=0 && primes[i]*primes[i]<=R; i++){
			t=primes[i];
			// 从>L开始 
			if(t<L){
				if(L%t==0) k=L; 
				else k=L/t*t+t;
			}
			else if(t==L) k=t+t;
			else k=t*t;
			// L~R之内的合数 
			for(j=k; j<=R; j+=t){
				a[j-L]=1;
			}
		}
		if(L==1) count--;
		// if(R==1) count-=2;
		for(i=0; i<=R-L; i++){
			if(a[i]==0) count++;
		}
		printf("%lld\n", count);
		free(a);
	}
	
	return 0;
}
