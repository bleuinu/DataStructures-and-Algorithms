// Manber-Myers Algorithm
// O(n log^2(n))

#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define ios cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'

bool cmp(int, int);
void getSA(string);

const int MAX_N(1001);
int t, n, g[MAX_N], tg[MAX_N], SA[MAX_N];

int main()
{
	ios;
	string s;

	cin >> s;
	getSA(s);
	const int N = s.size();
	for (int i=0; i<N; ++i) 
	{
		cout << s.c_str() + SA[i] << endl;
	}

	return 0;
}

/*
 * sort SA based on the group number
 * */
bool cmp(int x, int y)
{
	// same group number
	if (g[x] == g[y])
		return g[x + t] < g[y + t];

	// if different
	return g[x] < g[y];
}

void getSA(string str)
{
	t = 1;
	n = str.size(); 

	// assign groups based on the first character
	for(int i=0; i<n; ++i) 
	{
		SA[i] = i;
		g[i] = str[i] - 'a'; // assign the group number
	}

	// t = 1,2,4,8,.... 
	while (t <= n) 
	{
		g[n] = -1;
		sort(SA, SA + n, cmp);
		tg[SA[0]] = 0;

		// assign the next group
		for (int i=0; i<n; ++i)
		{
			// if group is different, assign the next group number
			if (cmp(SA[i-1], SA[i]))
				tg[SA[i]] = tg[SA[i-1]] + 1;
			// if they're the same group, assign the same number
			else
				tg[SA[i]] = tg[SA[i-1]];
		}

		// assign the new group
		for (int i=0; i<n; ++i)
		{
			g[i] = tg[i];
		}

		t <<= 1;
	}

	return;
}

