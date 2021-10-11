#include <bits/stdc++.h>
using namespace std;

long long minimumCost(vector<int> stones, int k)
{
    int n = stones.size();

    vector<long long> dp(n, 0);
    for(int i=1; i<n; i++) dp[i] = INT_MAX;

    for (int i = 0; i < n; i++) 
    { 
        for (int j = i + 1; j <= i + k; j++) 
        { 
            if (j < n) 
                dp[j] = min(dp[j], dp[i] + abs(stones[j] - stones[i]));
        }
    }

    return dp[n-1];
}
