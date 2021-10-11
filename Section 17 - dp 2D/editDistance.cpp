#include<bits/stdc++.h>
using namespace std;

int minDistance(string str1, int n1, string str2, int n2, int dp[500][500])
{
	if (n1 == 0) return n2;
	if (n2 == 0) return n1;

	if (dp[n1][n2] != -1) return dp[n1][n2];

	if (str1[n1 - 1] == str2[n2 - 1])
		return dp[n1][n2] = minDistance(str1, n1 - 1, str2, n2 - 1, dp);
	else
	{
		int op1, op2, op3;
		op1 = minDistance(str1, n1, str2, n2 - 1, dp); // insert
		op2 = minDistance(str1, n1 - 1, str2, n2, dp); // remove
		op3 = minDistance(str1, n1 - 1, str2, n2 - 1, dp); // replace

		return dp[n1][n2] = 1 + min(op1, min(op2, op3));
	}
}

int editDistance(string str1, string str2)
{
	int dp[500][500];
	memset(dp, -1, sizeof dp);

	int n1 = str1.size();
	int n2 = str2.size();

	int ans = minDistance(str1, n1, str2, n2, dp);
	return ans;
}