#include<bits/stdc++.h>
using namespace std;

int sum(vector<int> v, int i, int j)
{
    int res = 0;
    for (int k = i; k < j; k++) res += v[k];
    return res;
}

int calc(vector<int> v, int s, int e, int k)
{
    if (e - s + 1 < 0)
    {
        return 0;
    }

    int res = INT_MIN;
    for (int i = 0; i <= k; i++)
    {
        int ans = sum(v, s, s + i) + sum(v, e - k + i + 1, e + 1);
        int op = INT_MAX;
        for (int j = 0; j <= k; j++)
        {
            op = min(op, calc(v, s + i + j, e - k + i - k + j, k));
        }
        res = max(res, ans + op);
    }

    return res;
}
int MaxValue(int n, vector<int> v, int k){
    int res=calc(v,0,n-1,k);
    return res;
}
