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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, x;
	cin >> n >> x;
	vector<ll>a(n + 1, 0);
	vector<ll>pr(n + 1, 0);
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		pr[i] = pr[i - 1] + a[i];
	}
	vector<ll>d(x + 1, LLONG_MAX);
	// d[i]: answer at sum i
	d[0] = -1;
	for (ll i = 1; i <= x; i++)
	{
		ll t = LLONG_MAX;
		ll k = (i - pr[n]) / a[n];
		if (k > 0 && d[i - pr[n] - k * a[n]] != LLONG_MAX)
			t = d[i - pr[n] - k * a[n]] + n + k + 1;
		for (ll j = 1; j <= n; j++)
			if (i - pr[j] >= 0 && d[i - pr[j]] != LLONG_MAX)
				t = min(t, d[i - pr[j]] + j + 1);
		d[i] = min(t, d[i]);
	}

	if (d[x] == LLONG_MAX || d[x] == -1)
		cout << -1;
	else
		cout << d[x];

	return 0;
}