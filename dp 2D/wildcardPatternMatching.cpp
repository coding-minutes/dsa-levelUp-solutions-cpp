#include<bits/stdc++.h>
using namespace std;

int match(string s, int n, string p, int m, int dp[500][500])
{
	if (n == 0 && m == 0)
		return 1;
	if (m == 0)
		return 0;

	if (n == 0)
	{
		while (m > 0)
		{
			if (p[m - 1] != '*')
				return 0;
			m--;
		}
		return 1;
	}

	if (dp[n][m] != -1)
		return dp[n][m];

	if (p[m - 1] == '*')
		return dp[n][m] = match(s, n - 1, p, m, dp) || match(s, n, p, m - 1, dp);

	else if (p[m - 1] == '?')
		return dp[n][m] = match(s, n - 1, p, m - 1, dp);

	else if (s[n - 1] == p[m - 1])
		return dp[n][m] = match(s, n - 1, p, m - 1, dp);

	else
		return dp[n][m] = 0;

}

bool patternMatching(string s, string p)
{
	int dp[500][500];
	memset(dp, -1, sizeof dp);

	int n = s.size();
	int m = p.size();

	int ans = match(s, n, p, m, dp);

	if (ans == 1)
		return true;
	else
		return false;
}
