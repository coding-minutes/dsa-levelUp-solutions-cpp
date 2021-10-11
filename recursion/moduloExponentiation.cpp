#include <bits/stdc++.h>
using namespace std;

long long int solve(int A, int B, long C)
{
	if (A==0) return 0;
	if (B==0) return 1;

	long long int y;
	if (B&1)
    {
        y = A % C;
		y = (y * solve(A, B - 1, C) % C) % C;
	}

	else
    {
		y = solve(A, B / 2, C);
		y = (y * y) % C;
	}

	return (long long int)((y + C) % C);
}
long long int powerModulo(int a, int b)
{
    long mod = 1e9+7;
    return solve(a, b, mod);
}
