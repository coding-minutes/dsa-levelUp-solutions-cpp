#include<bits/stdc++.h>
using namespace std;

long long mixtures(vector<int> v, int i, int j, long long dp[500][500])
{
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	long long res = INT_MAX;

	for (int k = i; k < j; k++)
	{
		long long ans = mixtures(v, i, k, dp) + mixtures(v, k + 1, j, dp);
		ans += ( ( (v[k] - (i > 0 ? v[i - 1] : 0) ) % 100 ) * ((v[j] - v[k]) % 100) );
		res = min(res, ans);
	}

	return dp[i][j] = res;
}

long long minimumSmoke(vector<int> v)
{
	long long dp[500][500];
	memset(dp, -1, sizeof dp);

	int n = v.size();
	for (int i = 1; i < n; i++)
	{
		v[i] += v[i - 1]; //cumulative sum
	}

	long long ans = mixtures(v, 0, n - 1, dp);
	return ans;
}
