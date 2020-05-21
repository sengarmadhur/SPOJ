#include<bits/stdc++.h>
using namespace std;
#define fast                         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int                          long long int
#define double                       long double
#define ff                           first
#define ss                           second
#define pb                           push_back
#define eb                           emplace_back
#define all(x)                       (x).begin(), (x).end()
#define sz(x)                        ((int)(x).size())
#define len(x)                       ((int)(x).length())
#define pii                          pair<int,int>
#define vi                            vector<int>
#define vd                           vector<double>
#define vs                            vector<string>
#define mp                          map<int,int>

#define ump                         unordered_map<int,int>

#define lb                            lower_bound
#define ub                            upper_bound
#define nx                            cout<<"\n";
#define inf                           9223372036854775807
#define PI                            3.14159265

const int MOD = 5000000;

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
inline int add(int a, int b) {    return ((a % MOD) + (b % MOD)) % MOD;}

inline int multi(int a, int b) {   return ((a % MOD) * (b % MOD)) % MOD;}

inline int sub(int a, int b) {       a %= MOD; b %= MOD; a -= b; if (a < 0) a += MOD; return a;}

inline int power(int a, int b) {       a %= MOD; int res = 1; while (b > 0) {if (b & 1) {res = multi(res, a);} a = multi(a, a); b >>= 1;}  return res;}

bool isPrime(int  x) {      if (x <= 4 || x % 2 == 0 || x % 3 == 0) {return x == 2 || x == 3;} for (int i = 5; i * i <= x; i += 6) {if (x % i == 0 || x % (i + 2) == 0) { return 0;}} return 1;}

void compress(vi &v1, int n)
{

//	for (int i = 1; i <= n; i++)cout << v1[i] << " ";
//	nx
	mp var;
	for (int i = 1; i <= n; i++) {
		var[v1[i]] = 1;
	}
	int ct = 1;
	for (auto &it : var)
	{
		it.ss = ct++;

	}

	for (int i = 1; i <= n; i++)
	{
		v1[i] = var[v1[i]];
	}
	//for (int i = 1; i <= n; i++)cout << v1[i] << " ";
}

//-------------BIT------------
#define maxn 10005
int n, k;
int BIT[52][maxn + 5];
int dp[52][maxn + 5];
int sum(int *A1, int i) {
	int sum = 0;
	while (i > 0) {
		sum += A1[i], i -= (i & (-i));
		//if (sum >= MOD)sum -= MOD;
		sum %= MOD;
	}
	return sum;
}
void add(int *A1, int i, int k) {
	while (i < maxn) {
		A1[i] += k;
		i += (i & (-i));
		//if (A1[i] >= MOD)A1[i] -= MOD;
		A1[i] %= MOD;
	}
}
//-------------END-BIT--------
int32_t main()
{
	fast ;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> k;
	vi a(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	compress(a, n);


	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= k; j++)
		{
			int qr =  ((j > 1 ? sum(BIT[j - 1], a[i] - 1) : 1) - dp[j][a[i]] + MOD) % MOD;
			add(BIT[j], a[i], qr);
			dp[j][a[i]] = (dp[j][a[i]] + qr) % MOD;
		}
	}
	cout << sum(BIT[k], 10002);


}


