#include<stdio.h>
#include<math.h>
int prime[32000];
int t[1001];
int cnt;
int a[1000000];
void sieve(){
    int i,j;
    for(i=2;i<179;i++) if(!t[i]){
        for(j=i*i;j<32000;j+=i)t[j]=1;
    }
    for(i=2;i<1001;i++) if (!t[i]) prime[cnt++]=i;
}

int main(){
	int T,i,j;
	sieve();
	scanf("%d",&T);
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		//int sql=sqrt(l);
		for(i=0;prime[i]*prime[i]<=l;i++);
		for(j=i;j<32000;j++) if(!t[j]){
			for(int k=j*j;k<=r;k++) a[k-l]=1;
		}
		int count=0;
		for(i=0;i<r;i++){
			if(!a[i]){
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
