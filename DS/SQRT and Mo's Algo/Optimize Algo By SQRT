//https://atcoder.jp/contests/abc335/tasks/abc335_f

// There is a row of N squares labeled 1, 2, ... , N and a sequence A = (A1, A2, ... , AN) of length N.
// Initially, square 1 is painted black, the other N - 1 squares are painted white, and a piece is placed on square 1.

// You may repeat the following operation any number of times, possibly zero:

// . When the piece is on square i, choose a positive integer and move the piece to square i + Ai X x.
// o Here, you cannot make a move with i + Ai X x > N.
// . Then, paint the square i + Ai X x black.

// Find the number of possible sets of squares that can be painted black at the end of the operations, modulo 998244353.


#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) { cin >> a[i]; }

	int x = (int)sqrt(n);

	vector<int> dp(n, 1);
	vector<vector<int>> s(x + 1, vector<int>(x + 1));
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > x) {
			for (int j = i + a[i]; j < n; j += a[i]) {
				dp[i] += dp[j];
				dp[i] %= MOD;
			}
		} else {
			dp[i] += s[a[i]][i % a[i]];
			dp[i] %= MOD;
		}
		for (int j = 1; j <= x; j++) {
			s[j][i % j] += dp[i];
			s[j][i % j] %= MOD;
		}
	}

	cout << dp[0] << endl;
}
