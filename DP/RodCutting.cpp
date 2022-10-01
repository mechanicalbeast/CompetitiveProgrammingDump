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

int cutRodUtil(vector<int> &price, int ind, int N, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        return N * price[0];
    }

    if (dp[ind][N] != -1)
        return dp[ind][N];

    int notTaken = 0 + cutRodUtil(price, ind - 1, N, dp);

    int taken = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
        taken = price[ind] + cutRodUtil(price, ind, N - rodLength, dp);

    return dp[ind][N] = max(notTaken, taken);
}

int cutRod(vector<int> &price, int N)
{

    vector<vector<int>> dp(N, vector<int>(N + 1, -1));
    return cutRodUtil(price, N - 1, N, dp);
}

int main()
{
    io;
    vector<int> price = {2, 5, 7, 8, 10};

    int n = price.size();

    cout << "The Maximum price generated is " << cutRod(price, n);
}

// Made with ❤️ by Abhinav Jha