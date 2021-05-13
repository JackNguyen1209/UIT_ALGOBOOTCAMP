/*
Nguyen Duc Anh Phuc_Jacke
*/

#include <limits.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <fstream>
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;

ll dx[9] = { -1,-1,-1,0,0,0,1,1,1 };
ll dy[9] = { -1,0,1,-1,0,1,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>>a(n, vector<ll>(m));
	for (ll i = 0; i <= n - 1; i++)
		for (ll j = 0; j <= m - 1; j++)
			cin >> a[i][j];

	ll ma = LLONG_MAX;
	for (ll i = 0; i <= n - 1; i++)
		for (ll j = 0; j <= m - 1; j++)
		{
			ll c = 0;
			bool f = 1;
			for (ll t = 0; t <= 8; t++)
			{
				ll x = i + dx[t];
				ll y = j + dy[t];
				if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1)
					c += a[x][y];
				else
				{
					f = 0;
					break;
				}
			}
			if (f)
				ma = min(ma, c);
		}
	cout << ma;
	return 0;
}