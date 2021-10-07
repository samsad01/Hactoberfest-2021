/*
*
*	AUTHOR :- @soham01
*
*/
#include "bits/stdc++.h"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> //find_by_order(), order_of_key()
#define pb push_back
#define mp make_pair 
#define vi vector<long long int >
#define vb vector<bool>
#define vs vector<string>
#define vd vector<double>
#define vvi vector<vector<long long int> >
#define vp vector<pair<long long int , long long int > >
#define seti set<long long int >
#define setc set<char>
#define setd set<double>
#define mod 1000000009
#define endl '\n'
typedef long long int lli;

// ITS MY REQUEST TO PLEASE PLEASE DO LOOK AT THE CONSTRAINS GIVEN CAREFULLY
// DO CHECK FOR CORNER CASES

//to create a DSU of size n do DSU d(n)
//for union d._union(u,v)
//to find s.find(i)
class DSU {
public:
    vector<lli> parent, rank;
    set<lli> cycle;
 
    DSU (lli n) {
        rank.assign(n + 1, 1);
        parent.assign(n + 1, 0);
        for (lli i = 0; i <= n; ++i) parent[i] = i;
    }
 
    lli find(lli x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
 
    void _union(lli a, lli b) {
        lli s1 = find(a), s2 = find(b);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        } else {
            lli x = find(s1);
            if (cycle.count(x)) cycle.erase(x);
            else cycle.insert(x);
        }
    }
 
};
void solve()
{
	lli n,m,i,j,c=0,s=0;
    cin >> n >> m;
    DSU d(n);
    for(i=0;i<m;i++)
    {
        lli u,v;
        cin >> u >> v;
        d._union(u,v);
    }
    set <lli> st;
    for(i=1;i<=n;i++)
    {
       
        st.insert(d.find(i));
    }
    cout << st.size() << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
		solve();
	return 0;
}
