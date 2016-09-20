#include<cstdio>
int n, k, dp[201] = { 1 };
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= k; i++){
    for (int j = 1; j <= n; j++){
      dp[j] += (dp[j - 1] * k) % (int)(1e9);

    }
  }
  printf("%d", dp[n]);


  if() 
    {
    }
  return 0;
}
