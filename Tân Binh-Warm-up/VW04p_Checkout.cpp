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
	ld d, a1, a2, v, t;
	cin >> d >> a1 >> a2 >> v >> t;
	ld a = -1 / (2 * a1) - 1 / (2 * a2);
	ld b = -t;
	ld c = d;
	ld d1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	ld d2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	ld vmax = max(d1, d2);
	if (vmax < v)
		v = vmax;
	ld ans = v / (2 * a1) + v / (2 * a2) + d / v;
	cout << fixed << setprecision(12) << ans;
	return 0;
}