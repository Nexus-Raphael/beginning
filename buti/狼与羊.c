#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long ll;
#define MOD 1000000007
ll dp[1002][2004];
void solve(int n,int k){
	for(int i = 1;i <= n;i++){
		dp[i][1] = 1;
		dp[i][i] = 1;
	}

	for(int i = 2;i <= n;i++){
		for(int j = 2;j <= k;j++){
			dp[i][j] = (j*dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
		}
	}
	return;
}
int main(){
	int t;
	scanf("%d",&t);
	solve(1000,2000);
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		ll ans = 0;
		for(int i = 1;i <= k - 1;i++){
			ll te1 = dp[n][i] % MOD;
			ll te2 = dp[m][k - i] % MOD;
			ans = (ans % MOD + (te1 * te2) % MOD) % MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
