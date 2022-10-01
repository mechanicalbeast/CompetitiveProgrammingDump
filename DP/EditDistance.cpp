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

int editDistanceUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
{

    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i] == S2[j])
        return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);

    // Minimum of three choices
    else
        return dp[i][j] = 1 + min(editDistanceUtil(S1, S2, i - 1, j - 1, dp),
                                  min(editDistanceUtil(S1, S2, i - 1, j, dp), editDistanceUtil(S1, S2, i, j - 1, dp)));
}

int editDistance(string &S1, string &S2)
{

    int n = S1.size();
    int m = S2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return editDistanceUtil(S1, S2, n - 1, m - 1, dp);
}

int main()
{
    io;
    string s1 = "horse";
    string s2 = "ros";

    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
}

// Made with ❤️ by Abhinav Jha