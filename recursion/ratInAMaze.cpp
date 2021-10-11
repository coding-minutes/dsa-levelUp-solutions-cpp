#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool calc(int n, vector<vector<char>> c, vector<int> &v, int i = 0, int j = 0)
{
    if(i==n && j==n) return true;
    if(i==n+1 || j==n+1) return false;

    if(j != n && c[i][j+1] != 'X')
    {
        if(calc(n, c, v, i, j+1))
        {
            v.push_back( (i)*(n+1) + j+2 );
            return true;
        }
    }

    if(i != n && c[i+1][j] != 'X')
    {
        if(calc(n, c, v, i+1, j))
        {
            v.push_back( (i+1)*(n+1) + j+1 );
            return true;
        }
    }

    return false;
}

vector<int> findPath(int n, vector<vector<char>> c)
{
    vector<int> v;
    calc(n-1,c,v);
    v.push_back(1);
    reverse(v.begin(), v.end());
    return v;
}