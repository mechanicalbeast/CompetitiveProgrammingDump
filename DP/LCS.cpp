#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef vector<int> vll;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define mkp make_pair
#define omap tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int lcsUtil(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
{

    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);

    else
        return dp[ind1][ind2] = 0 + max(lcsUtil(s1, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
}

int lcs(string s1, string s2)
{

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcsUtil(s1, s2, n - 1, m - 1, dp);
}

int main()
{
    io;
    string s1 = "acd";
    string s2 = "ced";

    cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2);
}

// Made with ❤️ by Abhinav Jha