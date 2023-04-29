//https://leetcode.com/problems/similar-string-groups/https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/submissions/
#include <bits/stdc++.h>
using namespace std;


// union find
/*vector<bool> distanceLimistedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    vector<int> pt(n);
    iota(begin(pt), end(pt), 0);

    function<int(int)> find = [&](int x) {
        return pt[x] == x ? x : pt[x] = find(pt[x]);
    };

    const int m = queries.size();
    const int b = edgeList.size();
    for (int i = 0; i < m; ++i) queries[i].push_back(i);
    sort(begin(edgeList), end(edgeList), [](const auto& a, const auto& b) { return a[2] < b[2]; });
    sort(begin(queries), end(queries), [](const auto& a, const auto& b) { return a[2] < b[2]; });

    vector<bool> ans(m);

    int i = 0;

    for (const auto& q : queries) {
        while (i < b && edgeList[i][2] < q[2])
        {
            pt[find(edgeList[i++][0])] = find(edgeList[i][1]);
        }
        ans[q[3]] = find(q[0]) == find(q[1]);
    }
    return ans;
}*/



int dsu(vector<int>& parent,int x){
    if(parent[x] == x){
        return x;
    }
    else{
        return parent[x] = dsu(parent,parent[x]);
    }
}
vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    ios_base::sync_with_stdio(0);
    vector<int>parent(n,-1); vector<bool>ans(queries.size(),false);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < edgeList.size(); i++){
        swap(edgeList[i][0],edgeList[i][2]);
    }
    sort(edgeList.begin(),edgeList.end());
    vector<pair<int,int>>Q;
    for(int i = 0; i < queries.size(); i++){
        Q.push_back({queries[i][2],i});
    }
    sort(Q.begin(),Q.end());
    int j = 0;
    for(int i = 0; i < Q.size(); i++){
        while(j < edgeList.size() && edgeList[j][0] < Q[i].first){
            int u = edgeList[j][1],v = edgeList[j][2];
            int pu = dsu(parent,u),pv = dsu(parent,v);
            if(pu != pv){
                parent[pu] = pv;
            }
            j++;
        }
        int x = queries[Q[i].second][0],y = queries[Q[i].second][1];
        int px = dsu(parent,x),py = dsu(parent,y);
        if(px == py){
            ans[Q[i].second] = true;
        }
    }
    return ans;
}


int main() {
    int n = 3;
    vector<vector<int>> edgeList ={{0,1,2},{1,2,4},{2,0,8},{1,0,16}}, queries = {{0,1,2},{0,2,5}};
    for (auto s: distanceLimitedPathsExist(n,edgeList,queries)) {
        cout << s << " ";
    }


}


/*
 * vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        vector<pair<int, int> > sortedQueries = sortQueries(queries);
        vector<pair<int, int> > sortedEdges = sortQueries(edgeList);
        vector<int> parent(n);
        vector<int> rank(n);
        initParent(parent, rank);
        vector<bool> result(queries.size());

        for(int i = 0, j = 0; i < sortedQueries.size(); i++) {
            while( j < sortedEdges.size() && sortedEdges[j].first < sortedQueries[i].first){
                addEdge(edgeList[sortedEdges[j].second][0], edgeList[sortedEdges[j].second][1], parent, rank);
                j++;
            }
            result[sortedQueries[i].second] = (find(queries[sortedQueries[i].second][0], parent) == find(queries[sortedQueries[i].second][1], parent));
        }
        return result;
    }

    vector<pair<int, int> > sortQueries(vector<vector<int>>& queries) {
        vector<pair<int, int> > result(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            result[i] = {queries[i][2], i};
        }
        sort(result.begin(), result.end());
        return result;
    }

    void initParent(vector<int> &component, vector<int> &rank) {
        for(int i = 0; i < component.size(); i++) {
            component[i] = i;
            rank[i] = 1;
        }
    }

    void addEdge(int a, int b, vector<int> &parent, vector<int> &rank) {
        int pa = find(a, parent);
        int pb = find(b, parent);

        if(pa == pb) return;

        if(rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else {
            parent[pb] = pa;
            if(rank[pa] == rank[pb]) {
                rank[pa]++;
            }
        }
    }

    int find(int a, vector<int> &parent) {
        if(a == parent[a]) return a;
        parent[a] = find(parent[a], parent);
        return parent[a];
    }
 */
/*
 *
 *  static vector<int> total;
  static void initial(int n) {
    total.clear();
    total.resize(n, -1);
  }
  static int ancient(int k) {
    if(total[k] != -1) {
      total[k] = ancient(total[k]);
      return total[k];
    }
    return k;
  }
  static int connect(int x, int y) {
    int anx = ancient(x);
    int any = ancient(y);
    if (anx != any) {
      total[any] = anx;
    }
    return anx;
  }
  static bool find(int x, int y) {
    return ancient(x) == ancient(y);
  }
};
vector<int> Union::total;
class Solution {
 public:
  Solution() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  long mod = 1e9 + 7;
  vector<bool> distanceLimitedPathsExist(int n,
                                         vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    Union::initial(n);
    int len = edgeList.size();
    vector<bool> ret(queries.size(), false);
    int j = 0;
    for (auto&v :queries) {
      v.push_back(j++);
    }

    sort(edgeList.begin(), edgeList.end(),
         [](auto& lhs, auto& rhs) { return lhs.back() < rhs.back(); });
    sort(queries.begin(), queries.end(),
         [](auto& lhs, auto& rhs) { return lhs[2] < rhs[2]; });

    int i = 0;
    for (auto& v : queries) {
      while (i < len && edgeList[i].back() < v[2]) {
        Union::connect(edgeList[i][0], edgeList[i][1]);
        ++i;
      }

      ret[v[3]] = Union::find(v[0], v[1]);
    }
    return ret;
  }
 */

/*
 * class Solution {
public:

    /*

    Took help from the discuss section to realise the method , implement by self
    V V V imp and nice way of solving

    here the thing is , we will only take edges that have less weight using sorted queries according to distance

    In this way , we made sure that till now every node that is connected has distance that satisfies our need

    */

/*
int pr[100001];
int sz[100001];


void make_set(int a)
{
    pr[a] = a;
    sz[a] = 1;
}

int find_set(int a)
{
    if(a == pr[a])
        return a;

    return pr[a] = find_set(pr[a]);
}

void union_set(int a , int b)
{
    a = find_set(a);
    b = find_set(b);

    if(a == b)
        return ;

    if(sz[a] < sz[b])
        swap(a , b);

    pr[b] = a;
    sz[a] += sz[b];

}

bool static comp(vector<int>& a , vector<int>& b)
{
    return a[2] < b[2];
}


vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q)     {

    for(int i = 0 ; i < n ; i++)
        make_set(i);

    sort(e.begin() , e.end() , comp);

    int m = q.size();
    vector<bool> ans(m);

    vector<pair<int , int>> v;

    for(int i = 0 ; i < m ; i++)
        v.push_back({q[i][2] , i});

    sort(v.begin() , v.end());
    int i = 0;

    for(auto x : v)
    {
        int t = x.first;
        for(i ; i < e.size() && e[i][2] < t; i++)
        {
            int a = e[i][0];
            int b = e[i][1];

            union_set(a , b);
        }

        int a = q[x.second][0];
        int b = q[x.second][1];

        a = find_set(a);
        b = find_set(b);

        if(a == b)
            ans[x.second] = true;

        else
            ans[x.second] = false;
    }

    return ans;

}
};
 */
 /*
  * class Solution {
public:
    int dsu(vector<int>& parent,int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = dsu(parent,parent[x]);
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0);
        vector<int>parent(n,-1); vector<bool>ans(queries.size(),false);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < edgeList.size(); i++){
            swap(edgeList[i][0],edgeList[i][2]);
        }
        sort(edgeList.begin(),edgeList.end());
        vector<pair<int,int>>Q;
        for(int i = 0; i < queries.size(); i++){
            Q.push_back({queries[i][2],i});
        }
        sort(Q.begin(),Q.end());
        int j = 0;
        for(int i = 0; i < Q.size(); i++){
            while(j < edgeList.size() && edgeList[j][0] < Q[i].first){
                int u = edgeList[j][1],v = edgeList[j][2];
                int pu = dsu(parent,u),pv = dsu(parent,v);
                if(pu != pv){
                    parent[pu] = pv;
                }
                j++;
            }
            int x = queries[Q[i].second][0],y = queries[Q[i].second][1];
            int px = dsu(parent,x),py = dsu(parent,y);
            if(px == py){
                ans[Q[i].second] = true;
            }
        }
        return ans;
    }
};
  */

 /*
  * struct DSU {
    vector<int> data;
    DSU(int n): data(n) {
        while (n--) data[n] = n;
    }
    void merge(int a, int b) {
        data[find(a)] = find(b);
    }
    int find(int a) {
        return a == data[a] ? a : data[a] = find(data[a]);
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<array<int,4>> qq;
        for (int i = 0; i < queries.size(); ++i) {
            auto &q = queries[i];
            qq.push_back({q[2], i, q[0], q[1]});
        }
        sort(qq.begin(), qq.end());

        vector<array<int,3>> edges;
        for (auto &v: edgeList) {
            edges.push_back({v[2], v[0], v[1]});
        }
        sort(edges.begin(), edges.end());

        DSU dsu(n);
        vector<bool> result(queries.size());
        const int k = edges.size();
        int j = 0;
        for (auto [limit, i, a, b]: qq) {
            while (j < k && edges[j][0] < limit) {
                dsu.merge(edges[j][1], edges[j][2]);
                ++j;
            }
            result[i] = dsu.find(a) == dsu.find(b);
        }
        return result;
    }
};
  */
 /*
  * #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
// use less_equal to make it multiset
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef vector<pair<p64, ll>> vpp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef multiset<ll> ms64;
typedef multiset<p64> msp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef unordered_map<ll, v64> uv64;
typedef unordered_map<ll, ll> u64;
typedef unordered_map<p64, ll> up64;
typedef unordered_map<ll, vp64> uvp64;
typedef priority_queue<ll> pq64;
typedef priority_queue<ll, v64, greater<ll>> pqs64;
const int MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(p64 x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ splitmix64(x.second + FIXED_RANDOM);
    }
    size_t operator()(ll x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef gp_hash_table<ll, ll, custom_hash> fm64;
typedef gp_hash_table<p64, ll, custom_hash> fmp64;

#define ln "\n"
#define mp make_pair
#define ie insert
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())
#define dbg(a) cout << a << endl;
#define dbg2(a) cout << a << ' ';

struct DSU
{
    v64 e, sz;
    DSU(ll n)
    {
        e.assign(n + 1, -1);
        sz.assign(n + 1, 1);
    }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll size(ll x) { return sz[find(x)]; }
    ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    void join(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
            {
                swap(a, b);
            }
            e[b] = a;
            sz[a] += sz[b];
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<pair<ll,p64>> edge;
        vector<pair<p64,p64>> query;
        for(auto t:edgeList)
        {
            edge.push_back({t[2],{t[0],t[1]}});
        }
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0];
            int v=queries[i][1];
            int val=queries[i][2];
            query.push_back({{val,i},{u,v}});
        }
        sort(all(edge));
        sort(all(query));
        int j=0;
        int m=edge.size();
        DSU d(n);
        vector<bool> ans(query.size(),false);
        for(auto t:query)
        {
            while(j<m && edge[j].first<t.first.first)
            {
                d.join(edge[j].second.first,edge[j].second.second);
                j++;
            }
            ans[t.first.second]=d.same(t.second.first,t.second.second);
        }
        return ans;
    }
};
  */

 /*
  * class DSU{


    vector<int> par;
    vector<int> sz;
    public :
    DSU(int size) {
     par = vector<int> (size+1);
     sz = vector<int> (size+1);
     for(int i =0; i <= size; ++i) par[i] = i;
     for(int i =0; i <= size; ++i) sz[i] = 1;

    }

    int findPar(int x) {
        if(x == par[x]) return x;
        return par[x] = findPar(par[x]);
    }

    bool join(int u, int v) {

        int paru = findPar(u);
        int parv = findPar(v);
        if(paru == parv) return true;

        if(sz[parv] > sz[paru]) {
            swap(u,v);
            swap(paru,parv);
        }

        par[parv] = paru;
        sz[paru] += sz[parv];
        return false;
    }


};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        vector<tuple<int,int,int,int>> input;
        int idx = 0;
        for(auto x: queries) {
            int u = x[0]; int v = x[1]; int wt = x[2];
            input.push_back({wt,u,v,idx});
            ++idx;
        }

        sort(input.begin(),input.end());
        int sz = queries.size();
        vector<tuple<int,int,int>> newAdj;

        for(auto curr: edgeList) {
            int u = curr[0]; int v = curr[1]; int wt = curr[2];
            newAdj.push_back({wt,u,v});
        }
        vector<bool> ans(sz);
        sort(newAdj.begin(),newAdj.end());
        DSU s(n);
        int j = 0;
        for(int i =0; i < sz; ++i) {
            auto [qlimit, qu, qv ,qidx ] = input[i];

            while(j < (int)newAdj.size() && get<0>(newAdj[j]) < qlimit) {
                auto [ewt, eu, ev] = newAdj[j];
                j++;
                s.join(eu,ev);
            }
            bool currAns = false;
            if(s.findPar(qu) == s.findPar(qv)) currAns = true;
            ans[qidx] = currAns;
        }

       return ans;


    }
};
  */

 /*
  * class Solution {
    vector<int> sz, par;
    void init(int n){
        sz = par = vector<int>(n, 1);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }
    int findPar(int u){
        if(par[u] == u)return u;
        return par[u] = findPar(par[u]);
    }
    void merge(int u, int v){
        u = findPar(u);
        v = findPar(v);
        if(u == v)return;
        if(sz[u] > sz[v])swap(u, v);
        sz[v] += sz[u];
        par[u] = v;
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<array<int,3>> edges;
        for(auto e : edgeList){
            edges.push_back({e[2], e[1], e[0]});
        }
        vector<array<int,4>> q;
        for(int i = 0; i < (int)queries.size(); i++){
            q.push_back({queries[i][2], queries[i][1], queries[i][0], i});
        }
        sort(edges.begin(), edges.end());
        sort(q.begin(), q.end());
        int m = queries.size();
        vector<bool> ans(m);
        int i = 0;
        init(n + 1);
        for(auto e : q){
            while(i < (int)edgeList.size() && edges[i][0] < e[0]){
                merge(edges[i][1], edges[i][2]);
                i++;
            }
            if(findPar(e[1]) == findPar(e[2])){
                ans[e[3]] = true;
            }
        }
        return ans;
    }
};
  */

 /*
  * class Solution {
public:
    using AIR4 = array<int, 4>;
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> p(n);
        for (int i=0; i<n; i++) {
            p[i] = i;
        }
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& l, vector<int>& r) {
            return l[2]<r[2];
        });
        vector<AIR4> ques;
        for (int i=0; i<queries.size(); i++) {
            ques.push_back({queries[i][2], queries[i][0], queries[i][1], i});
        }
        sort(ques.begin(), ques.end());
        int edgeIdx = 0;
        vector<bool> ans(queries.size(), false);
        for (auto& [limit, a, b, i]: ques) {
            while (edgeIdx<edgeList.size() && edgeList[edgeIdx][2]<limit) {
                Union(p, edgeList[edgeIdx][0], edgeList[edgeIdx][1]);
                edgeIdx++;
            }
            if (SameSet(p, a, b)) ans[i] = true;
        }
        return ans;
    }
    int Find(vector<int>& p, int x) {
        if (x != p[x]) p[x] = Find(p, p[x]);
        return p[x];
    }
    void Union(vector<int>& p, int x, int y) {
        int px = Find(p, x);
        int py = Find(p, y);
        if (px == py) return;
        p[px] = py;
    }
    bool SameSet(vector<int>& p, int x, int y) {
        int px = Find(p, x);
        int py = Find(p, y);
        return (px == py);
    }
};
  00*/
 /*
  *
  *
  class Solution {
public:



 class DSU {
 public:
     vector<int> parent;
     vector<int> sz;

     DSU(int n) {
         for (int i = 0; i < n; i++) parent.push_back(i);
         for (int i = 0; i < n; i++) sz.push_back(1);
     }

     int root(int x) {
         if (parent[x] == x) return x;
         return parent[x] = root(parent[x]);
     }

     void merge(int x, int y) {
         x = root(x);
         y = root(y);

         if (x == y) return;

         if (sz[x] < sz[y]) swap(x, y);

         parent[y] = x;
         //cout << x << " " << y << " " << sz[x] << " " << sz[y] << endl;
         sz[x] += sz[y];
     }
 }

vector<bol> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

    sort(edgeList.begin(), edgeList.end(),
         [](vector<int>& e1, vector<int>& e2) {
             return e1[2] < e2[2];
         });

    for (int i = 0; i < queries.size(); i++)
        queries[i].push_back(i);

    sort(queries.begin(), queries.end(),
         [](vector<int>& q1, vector<int>& q2) {
             return q1[2] < q2[2];
         });

    vector<bool> res(queries.size());
    int i = 0;

    DSU dsu(n);
    for (auto& v: queries) {
        while (i < edgeList.size() && edgeList[i][2] < v[2]) {
            dsu.merge(edgeList[i][0], edgeList[i][1]);
            i++;
        }

        res[v[3]] = (dsu.root(v[0]) == dsu.root(v[1]));
    }

    return res;
}
};
*/

 /*
  * // #define DEBUG 01

#pragma region programmation {
#pragma region common {  // clang-format off
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#ifndef DEBUG
#    define DEBUG 0
#endif
#if DEBUG
#    define eprintf(...) fprintf(stderr, __VA_ARGS__)
#    define trace(...) (_trace(#__VA_ARGS__, __VA_ARGS__), 0)
#    define view(...) (_view(__VA_ARGS__), trace(""), 0)
#    define debug
#else
#    ifdef __clang__
#        pragma clang attribute push (__attribute__((no_sanitize("address","undefined"))), apply_to=function)
#    endif
#    define eprintf(...) ((void)0, 0)
#    define trace(...) ((void)0, 0)
#    define view(...) ((void)0, 0)
#    define debug while (0)
#endif
#include <bits/stdc++.h>
#define __argc(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, n, ...) n
#define _argc(...) __argc(__VA_ARGS__, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _concat(x, y) __CONCAT(x, y)
#define _range4(b, e, d, i) for (remove_reference_t<decltype(e)> i = b, _e_##i = e, _d_##i = d; _d_##i > 0 ? i < _e_##i : _e_##i < i; i += _d_##i)
#define _range1(n) _range4(0, n, 1, _i)
#define _range2(n, i) _range4(0, n, 1, i)
#define _range3(b, e, i) _range4(b, e, 1, i)
#define range(...) _concat(_range, _argc(__VA_ARGS__))(__VA_ARGS__)
#define _each2(a, x) for (auto& x : a)
#define _each_(a, ...) for (auto& [__VA_ARGS__] : a)
#define _argc2(...) __argc(__VA_ARGS__, _, _, _, _, _, _, _, _, _, _, 2, 1, 0)
#define each(...) _concat(_each, _argc2(__VA_ARGS__))(__VA_ARGS__)
#define enumerate(a, i, ...) for (int i = 0; i != -1; i = -1) each(a, __VA_ARGS__)
#define selecting(x, ...) [&](auto& x) { return __VA_ARGS__; }
#define comparing(x, ...) [&](auto& _l, auto& _r) { auto _f = [&](auto& x) { return __VA_ARGS__; }; return _f(_l) < _f(_r); }
#define adding(x, ...) [&](auto _s, auto& x) { return _s + (__VA_ARGS__); }
#define rep(i, b, e) _range3(b, e, i)
#define trav(x, a) _each2(a, x)
#define all(x) begin(x), end(x)
#define sz len
#define _print_vector_impl s << "{"; string d; for (auto&& y : x) s << d << y, d = ", "; return s << "}";
#define _trace_out cout
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; using vi = vector<int>; using pii = pair<int, int>; template <typename T> int len(const T& x) { return int(x.size()); } template <typename T, size_t l> int len(const T (&)[l]) { return l; } template <typename T, typename S> bool amax(T& t, S s) { return t < s && (t = s, 1); } template <typename T, typename S> bool amin(T& t, S s) { return s < t && (t = s, 1); } int case_id; namespace std { template <typename T, size_t l> ostream& operator<<(ostream& s, const array<T, l>& x); template <typename F, typename S> ostream& operator<<(ostream& s, const pair<F, S>& x); template <typename... T> ostream& operator<<(ostream& s, const tuple<T...>& x); template <typename C, typename T = enable_if_t<!is_same<C, string>::value, typename C::value_type>> ostream& operator<<(ostream& s, const C& x) { _print_vector_impl } template <typename T, size_t l, enable_if_t<!is_same<T, char>::value, int> = 0> ostream& operator<<(ostream& s, const T (&x)[l]) { _print_vector_impl } template <typename T, size_t l> ostream& operator<<(ostream& s, const std::array<T, l>& x) { _print_vector_impl } template <typename F, typename S> ostream& operator<<(ostream& s, const pair<F, S>& x) { return s << "{" << x.first << ", " << x.second << "}"; } template <typename... T> ostream& operator<<(ostream& s, const tuple<T...>& x) { s << "{"; string d; apply([&](auto&&... y) { (..., (s << d << y, d = ", ")); }, x); return s << "}"; } } template <typename T> void _trace(const char* l, const T& x) { if (l[0] != '"') _trace_out << l + (l[0] == ' ') << ": "; _trace_out << x << "\n"; } template <typename T, typename... A> void _trace(const char* l, const T& x, const A&... a) { if (l[0] == ' ') l++; size_t s = strchr(l, ',') - l; if (l[0] != '"') _trace_out.write(l, s) << ": "; _trace_out << x << ", ", _trace(l + s + 1, a...); } template <typename T> void _view(const T& x) { _trace_out << x; } template <typename T, typename... R> void _view(const T& x, int b, int e, R... r) { b < 0 && (b += len(x)), e < 0 && (e += len(x)); b = min(max(b, 0), len(x)), e = min(max(e, b), len(x)); auto it = begin(x); advance(it, b); _trace_out << "{"; for (int i = b; i < e; it++, i++) { if (i != b) _trace_out << ", "; _view(*it, r...); } _trace_out << "}"; }
#if !DEBUG
void _init() __attribute__((constructor)); void _init() { ios::sync_with_stdio(0), cin.tie(0); }
#endif
#pragma endregion common }  // clang-format on

// Additional library code

#pragma GCC diagnostic pop
#pragma endregion programmation }

const int mxn = 100001;
int uf[mxn];
// int fin(int i) { return uf[i] < 0 ? i : uf[i] = fin(uf[i]); }
int fin(int i){return uf[i]==i?i:uf[i]=fin(uf[i]);}
void uni(int i, int j) {
    // i = fin(i), j = fin(j);
    // if (i == j) return;
    // if (uf[i] < uf[j]) swap(i, j);
    // uf[j] += uf[i], uf[i] = j;
    if(rand()&1)swap(i,j);
    uf[fin(i)]=fin(j);
}
pair<vi, int> qi[mxn];

class Solution {
  public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        // memset(uf, -1, sizeof(uf[0]) * n);
        iota(uf,uf+n,0);
        sort(all(edgeList), comparing(e, e[2]));
        range(len(queries), i) qi[i] = {move(queries[i]), i};
        sort(qi, qi + len(queries), comparing(q, q.first[2]));
        vector<bool> ans(len(queries));
        int e = 0;
        range(len(queries), i) {
            while (e < len(edgeList) && edgeList[e][2] < qi[i].first[2]) {
                uni(edgeList[e][0], edgeList[e][1]);
                e++;
            }
            ans[qi[i].second] = fin(qi[i].first[0]) == fin(qi[i].first[1]);
        }
        return ans;
    }
};

#pragma region demo {
#if LOCAL && 01
Solution $s;
int main() {
    auto $t = [&]() {
        cout << "Case #" << ++case_id << ": ";
        // cout << $s;
        cout << "\n";
    };

    $t();
}
#elif !DEBUG && defined(__clang__)
#    pragma clang attribute pop
#endif
#pragma endregion demo }
  */

 /*
  * class Solution {
public:

    int par[100005], sz[100005];

    int findParent(int node) {
        if(par[node] == node)
            return node;
        return par[node] = findParent(par[node]);
    }

    void merge(int a, int b) {
        int pa = findParent(a), pb = findParent(b);
        if(pa == pb) return;
        if(sz[a] < sz[b]) swap(pa, pb);
        par[pb] = pa;
        sz[pa] += sz[pb];
        sz[pb] = 0;
    }

    bool inSameComponent(int a, int b) {
        return (findParent(a) == findParent(b));
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        for(int i = 0; i <= n; i++) par[i] = i, sz[i] = 1;
        vector<bool> res(q.size());

        for(int i = 0; i < q.size(); i++) q[i].push_back(i);
        sort(q.begin(), q.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });

        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });

        int ind = 0;
        for(int i = 0; i < q.size(); i++) {
            while(ind < edges.size() && q[i][2] > edges[ind][2]) {
                merge(edges[ind][0], edges[ind][1]);
                ind++;
            }

            res[q[i][3]] = inSameComponent(q[i][0], q[i][1]);

        }


        return res;


    }
};
  */
 /*
  * // #define DEBUG 01

#pragma region programmation {
#pragma region common {  // clang-format off
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#ifndef DEBUG
#    define DEBUG 0
#endif
#if DEBUG
#    define eprintf(...) fprintf(stderr, __VA_ARGS__)
#    define trace(...) (_trace(#__VA_ARGS__, __VA_ARGS__), 0)
#    define view(...) (_view(__VA_ARGS__), trace(""), 0)
#    define debug
#else
#    ifdef __clang__
#        pragma clang attribute push (__attribute__((no_sanitize("address","undefined"))), apply_to=function)
#    endif
#    define eprintf(...) ((void)0, 0)
#    define trace(...) ((void)0, 0)
#    define view(...) ((void)0, 0)
#    define debug while (0)
#endif
#include <bits/stdc++.h>
#define __argc(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, n, ...) n
#define _argc(...) __argc(__VA_ARGS__, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _concat(x, y) __CONCAT(x, y)
#define _range4(b, e, d, i) for (remove_reference_t<decltype(e)> i = b, _e_##i = e, _d_##i = d; _d_##i > 0 ? i < _e_##i : _e_##i < i; i += _d_##i)
#define _range1(n) _range4(0, n, 1, _i)
#define _range2(n, i) _range4(0, n, 1, i)
#define _range3(b, e, i) _range4(b, e, 1, i)
#define range(...) _concat(_range, _argc(__VA_ARGS__))(__VA_ARGS__)
#define _each2(a, x) for (auto& x : a)
#define _each_(a, ...) for (auto& [__VA_ARGS__] : a)
#define _argc2(...) __argc(__VA_ARGS__, _, _, _, _, _, _, _, _, _, _, 2, 1, 0)
#define each(...) _concat(_each, _argc2(__VA_ARGS__))(__VA_ARGS__)
#define enumerate(a, i, ...) for (int i = 0; i != -1; i = -1) each(a, __VA_ARGS__)
#define selecting(x, ...) [&](auto& x) { return __VA_ARGS__; }
#define comparing(x, ...) [&](auto& _l, auto& _r) { auto _f = [&](auto& x) { return __VA_ARGS__; }; return _f(_l) < _f(_r); }
#define adding(x, ...) [&](auto _s, auto& x) { return _s + (__VA_ARGS__); }
#define rep(i, b, e) _range3(b, e, i)
#define trav(x, a) _each2(a, x)
#define all(x) begin(x), end(x)
#define sz len
#define _print_vector_impl s << "{"; string d; for (auto&& y : x) s << d << y, d = ", "; return s << "}";
#define _trace_out cout
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; using vi = vector<int>; using pii = pair<int, int>; template <typename T> int len(const T& x) { return int(x.size()); } template <typename T, size_t l> int len(const T (&)[l]) { return l; } template <typename T, typename S> bool amax(T& t, S s) { return t < s && (t = s, 1); } template <typename T, typename S> bool amin(T& t, S s) { return s < t && (t = s, 1); } int case_id; namespace std { template <typename T, size_t l> ostream& operator<<(ostream& s, const array<T, l>& x); template <typename F, typename S> ostream& operator<<(ostream& s, const pair<F, S>& x); template <typename... T> ostream& operator<<(ostream& s, const tuple<T...>& x); template <typename C, typename T = enable_if_t<!is_same<C, string>::value, typename C::value_type>> ostream& operator<<(ostream& s, const C& x) { _print_vector_impl } template <typename T, size_t l, enable_if_t<!is_same<T, char>::value, int> = 0> ostream& operator<<(ostream& s, const T (&x)[l]) { _print_vector_impl } template <typename T, size_t l> ostream& operator<<(ostream& s, const std::array<T, l>& x) { _print_vector_impl } template <typename F, typename S> ostream& operator<<(ostream& s, const pair<F, S>& x) { return s << "{" << x.first << ", " << x.second << "}"; } template <typename... T> ostream& operator<<(ostream& s, const tuple<T...>& x) { s << "{"; string d; apply([&](auto&&... y) { (..., (s << d << y, d = ", ")); }, x); return s << "}"; } } template <typename T> void _trace(const char* l, const T& x) { if (l[0] != '"') _trace_out << l + (l[0] == ' ') << ": "; _trace_out << x << "\n"; } template <typename T, typename... A> void _trace(const char* l, const T& x, const A&... a) { if (l[0] == ' ') l++; size_t s = strchr(l, ',') - l; if (l[0] != '"') _trace_out.write(l, s) << ": "; _trace_out << x << ", ", _trace(l + s + 1, a...); } template <typename T> void _view(const T& x) { _trace_out << x; } template <typename T, typename... R> void _view(const T& x, int b, int e, R... r) { b < 0 && (b += len(x)), e < 0 && (e += len(x)); b = min(max(b, 0), len(x)), e = min(max(e, b), len(x)); auto it = begin(x); advance(it, b); _trace_out << "{"; for (int i = b; i < e; it++, i++) { if (i != b) _trace_out << ", "; _view(*it, r...); } _trace_out << "}"; }
#if !DEBUG
void _init() __attribute__((constructor)); void _init() { ios::sync_with_stdio(0), cin.tie(0); }
#endif
#pragma endregion common }  // clang-format on

// Additional library code

#pragma GCC diagnostic pop
#pragma endregion programmation }

const int mxn = 100001;
int uf[mxn];
int fin(int i) { return uf[i] < 0 ? i : uf[i] = fin(uf[i]); }
void uni(int i, int j) {
    i = fin(i), j = fin(j);
    if (i == j) return;
    if (uf[i] < uf[j]) swap(i, j);
    uf[j] += uf[i], uf[i] = j;
}
pair<vi, int> qi[mxn];

class Solution {
  public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        memset(uf, -1, sizeof(uf[0]) * n);
        sort(all(edgeList), comparing(e, e[2]));
        range(len(queries), i) qi[i] = {move(queries[i]), i};
        sort(qi, qi + len(queries), comparing(q, q.first[2]));
        vector<bool> ans(len(queries));
        int e = 0;
        range(len(queries), i) {
            while (e < len(edgeList) && edgeList[e][2] < qi[i].first[2]) {
                uni(edgeList[e][0], edgeList[e][1]);
                e++;
            }
            ans[qi[i].second] = fin(qi[i].first[0]) == fin(qi[i].first[1]);
        }
        return ans;
    }
};

#pragma region demo {
#if LOCAL && 01
Solution $s;
int main() {
    auto $t = [&]() {
        cout << "Case #" << ++case_id << ": ";
        // cout << $s;
        cout << "\n";
    };

    $t();
}
#elif !DEBUG && defined(__clang__)
#    pragma clang attribute pop
#endif
#pragma endregion demo }
  */
 /*
  * // #define DEBUG 01

#pragma region programmation {
#pragma region common {  // clang-format off
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#ifndef DEBUG
#    define DEBUG 0
#endif
#if DEBUG
#    define eprintf(...) fprintf(stderr, __VA_ARGS__)
#    define trace(...) (_trace(#__VA_ARGS__, __VA_ARGS__), 0)
#    define view(...) (_view(__VA_ARGS__), trace(""), 0)
#    define debug
#else
#    ifdef __clang__
#        pragma clang attribute push (__attribute__((no_sanitize("address","undefined"))), apply_to=function)
#    endif
#    define eprintf(...) ((void)0, 0)
#    define trace(...) ((void)0, 0)
#    define view(...) ((void)0, 0)
#    define debug while (0)
#endif
#include <bits/stdc++.h>
#define __argc(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, n, ...) n
#define _argc(...) __argc(__VA_ARGS__, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _concat(x, y) __CONCAT(x, y)
#define _range4(b, e, d, i) for (remove_reference_t<decltype(e)> i = b, _e_##i = e, _d_##i = d; _d_##i > 0 ? i < _e_##i : _e_##i < i; i += _d_##i)
#define _range1(n) _range4(0, n, 1, _i)
#define _range2(n, i) _range4(0, n, 1, i)
#define _range3(b, e, i) _range4(b, e, 1, i)
#define range(...) _concat(_range, _argc(__VA_ARGS__))(__VA_ARGS__)
#define _each2(a, x) for (auto& x : a)
#define _each_(a, ...) for (auto& [__VA_ARGS__] : a)
#define _argc2(...) __argc(__VA_ARGS__, _, _, _, _, _, _, _, _, _, _, 2, 1, 0)
#define each(...) _concat(_each, _argc2(__VA_ARGS__))(__VA_ARGS__)
#define enumerate(a, i, ...) for (int i = 0; i != -1; i = -1) each(a, __VA_ARGS__)
#define selecting(x, ...) [&](auto& x) { return __VA_ARGS__; }
#define comparing(x, ...) [&](auto& _l, auto& _r) { auto _f = [&](auto& x) { return __VA_ARGS__; }; return _f(_l) < _f(_r); }
#define adding(x, ...) [&](auto _s, auto& x) { return _s + (__VA_ARGS__); }
#define rep(i, b, e) _range3(b, e, i)
#define trav(x, a) _each2(a, x)
#define all(x) begin(x), end(x)
#define sz len
#define _print_vector_impl s << "{"; string d; for (auto&& y : x) s << d << y, d = ", "; return s << "}";
#define _trace_out cout
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; using vi = vector<int>; using pii = pair<int, int>; template <typename T> int len(const T& x) { return int(x.size()); } template <typename T, size_t l> int len(const T (&)[l]) { return l; } template <typename T, typename S> bool amax(T& t, S s) { return t < s && (t = s, 1); } template <typename T, typename S> bool amin(T& t, S s) { return s < t && (t = s, 1); } int case_id; namespace std { template <typename T, size_t l> ostream& operator<<(ostream& s, const array<T, l>& x); template <typename F, typename S> ostream& operator<<(ostream& s, const pair<F, S>& x); template <typename... T> ostream& operator<<(ostream& s, const tuple<T...>& x); template <typename C, typename T = enable_if_t<!is_same<C, string>::value, typename C::value_type>> ostream& operator<<(ostream& s, const C& x) { _print_vector_impl } template <typename T, size_t l, enable_if_t<!is_same<T, char>::value, int> = 0> ostream& operator<<(ostream& s, const T (&x)[l]) { _print_vector_impl } template <typename T, size_t l> ostream& operator<<(ostream& s, const std::array<T, l>& x) { _print_vector_impl } template <typename F, typename S> ostream& operator<<(ostream& s, const pair<F, S>& x) { return s << "{" << x.first << ", " << x.second << "}"; } template <typename... T> ostream& operator<<(ostream& s, const tuple<T...>& x) { s << "{"; string d; apply([&](auto&&... y) { (..., (s << d << y, d = ", ")); }, x); return s << "}"; } } template <typename T> void _trace(const char* l, const T& x) { if (l[0] != '"') _trace_out << l + (l[0] == ' ') << ": "; _trace_out << x << "\n"; } template <typename T, typename... A> void _trace(const char* l, const T& x, const A&... a) { if (l[0] == ' ') l++; size_t s = strchr(l, ',') - l; if (l[0] != '"') _trace_out.write(l, s) << ": "; _trace_out << x << ", ", _trace(l + s + 1, a...); } template <typename T> void _view(const T& x) { _trace_out << x; } template <typename T, typename... R> void _view(const T& x, int b, int e, R... r) { b < 0 && (b += len(x)), e < 0 && (e += len(x)); b = min(max(b, 0), len(x)), e = min(max(e, b), len(x)); auto it = begin(x); advance(it, b); _trace_out << "{"; for (int i = b; i < e; it++, i++) { if (i != b) _trace_out << ", "; _view(*it, r...); } _trace_out << "}"; }
#if !DEBUG
void _init() __attribute__((constructor)); void _init() { ios::sync_with_stdio(0), cin.tie(0); }
#endif
#pragma endregion common }  // clang-format on

// Additional library code

#pragma GCC diagnostic pop
#pragma endregion programmation }

const int mxn = 100001;
int uf[mxn];
// int fin(int i) { return uf[i] < 0 ? i : uf[i] = fin(uf[i]); }
int fin(int i){return uf[i]==i?i:uf[i]=fin(uf[i]);}
// void uni(int i, int j) {
    // i = fin(i), j = fin(j);
    // if (i == j) return;
    // if (uf[i] < uf[j]) swap(i, j);
    // uf[j] += uf[i], uf[i] = j;
// }
void uni(int i,int j){uf[fin(i)]=fin(j);}
pair<vi, int> qi[mxn];

class Solution {
  public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        // memset(uf, -1, sizeof(uf[0]) * n);
        iota(uf,uf+n,0);
        sort(all(edgeList), comparing(e, e[2]));
        range(len(queries), i) qi[i] = {move(queries[i]), i};
        sort(qi, qi + len(queries), comparing(q, q.first[2]));
        vector<bool> ans(len(queries));
        int e = 0;
        range(len(queries), i) {
            while (e < len(edgeList) && edgeList[e][2] < qi[i].first[2]) {
                uni(edgeList[e][0], edgeList[e][1]);
                e++;
            }
            ans[qi[i].second] = fin(qi[i].first[0]) == fin(qi[i].first[1]);
        }
        return ans;
    }
};

#pragma region demo {
#if LOCAL && 01
Solution $s;
int main() {
    auto $t = [&]() {
        cout << "Case #" << ++case_id << ": ";
        // cout << $s;
        cout << "\n";
    };

    $t();
}
#elif !DEBUG && defined(__clang__)
#    pragma clang attribute pop
#endif
#pragma endregion demo }
  */
 /*
  * class UnionFind{
    public:
    vector<int> par;
    vector<int> size;
    int n;

    UnionFind(int _n)
    {
        n = _n;
        par = vector<int>(n, -1);
        size = vector<int>(n, 1);
    }

    int find(int x)
    {
        if(par[x]==-1)return x;
        par[x] = find(par[x]);
        return par[x];
    }

    void merge(int x, int y)
    {
        int parx=find(x),pary=find(y);
        if(parx!=pary)
        {
            if(size[parx]>size[pary]){par[pary]=parx;}
            else if(size[parx]<size[pary]){
                par[parx]=pary;
            }
            else{
                par[pary]=parx;
                size[parx]++;
            }
        }
    }


};

class Comp{
    public:

    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        return a[2]<b[2];
    }
};

class Query{
    public:
    int limit, p, q, ind;
    Query(int _p, int _q, int _limit, int _ind){limit = _limit; p = _p; q = _q;ind = _ind;}
    Query(){}
};

class CompareQuery{
    public:

    bool operator()(const Query& a, const Query& b)
    {
        if(a.limit==b.limit)return a.ind<b.ind;
        return a.limit<b.limit;
    }
};

class Solution {
public:


    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {

        int m = edges.size();
        sort(edges.begin(), edges.end(), Comp());
        // vector<vector<int>> queries = vector<vector<int>>(queriesList.size());

        // copy(queriesList.begin(), queriesList.end(), queries.begin());
        // sort(queries.begin())

        int q = queries.size();
        vector<bool> ans = vector<bool>(q, false);
        vector<Query> vq = vector<Query>(q);
        for(int i=0;i<queries.size();i++)
        {
            vq[i] = Query(queries[i][0], queries[i][1], queries[i][2], i);
        }

        sort(vq.begin(), vq.end(), CompareQuery());

        // for(int i=0;i<m;i++){printf("%d %d %d\n", edges[i][0], edges[i][1], edges[i][2]);}

        // for(int i=0;i<q;i++){printf("%d %d %d %d\n", vq[i].limit, vq[i].p, vq[i].q, vq[i].ind);}
        UnionFind uf = UnionFind(n);
        int curr=0;
        for(int i=0;i<q;i++)
        {
            while(curr<m and edges[curr][2]<vq[i].limit)
            {
                uf.merge(edges[curr][0], edges[curr][1]);
                curr++;
            }
            if(uf.find(vq[i].p)==uf.find(vq[i].q)){
                ans[vq[i].ind]=true;
            }
        }

        return ans;
    }
};
  */
 /*
  * struct Query {
    int idx;
    int p, q, limit;

    Query(int idx, int p, int q, int limit) : idx(idx), p(p), q(q), limit(limit) {}

    bool operator < (const Query &other) {
        return limit < other.limit;
    }
};

struct DSU {
    int n;
    vector<int> S, P;

    DSU(int n) {
        this->n = n;
        S = vector<int>(n, 1);
        for (int i = 0; i < n; ++i) {
            P.push_back(i);
        }
    }

    int parent(int u) {
        while (u != P[u]) {
            u = P[u];
        }
        return u;
    }

    bool same(int u, int v) {
        return parent(u) == parent(v);
    }

    void unite(int u, int v) {
        u = parent(u);
        v = parent(v);
        if (S[u] < S[v]) {
            swap(u, v);
        }
        P[v] = u;
        S[u] += S[v];
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<Query> Q;
        int idx = 0;
        for (auto &query : queries) {
            Q.push_back(Query(idx++, query[0], query[1], query[2]));
        }

        sort(edgeList.begin(), edgeList.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        sort(Q.begin(), Q.end());

        int curr_edge = 0;
        const int m = edgeList.size();

        DSU dsu(n);
        vector<bool> ans(Q.size());
        for (Query &q : Q) {
            while (curr_edge < m and edgeList[curr_edge][2] < q.limit) {
                int u = edgeList[curr_edge][0];
                int v = edgeList[curr_edge][1];
                if (not dsu.same(u, v)) dsu.unite(u, v);
                ++curr_edge;
            }
            ans[q.idx] = dsu.same(q.p, q.q);
        }

        return ans;
    }
};
  */
 /*
  * // #define DEBUG 01

#pragma region programmation {
#pragma region common {  // clang-format off
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#ifndef DEBUG
#    define DEBUG 0
#endif
#if DEBUG
#    define eprintf(...) fprintf(stderr, __VA_ARGS__)
#    define trace(...) (_trace(#__VA_ARGS__, __VA_ARGS__), 0)
#    define view(...) (_view(__VA_ARGS__), trace(""), 0)
#    define debug
#else
#    ifdef __clang__
#        pragma clang attribute push (__attribute__((no_sanitize("address","undefined"))), apply_to=function)
#    endif
#    define eprintf(...) ((void)0, 0)
#    define trace(...) ((void)0, 0)
#    define view(...) ((void)0, 0)
#    define debug while (0)
#endif
#include <bits/stdc++.h>
#define __argc(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, n, ...) n
#define _argc(...) __argc(__VA_ARGS__, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _concat(x, y) __CONCAT(x, y)
#define _range4(b, e, d, i) for (remove_reference_t<decltype(e)> i = b, _e_##i = e, _d_##i = d; _d_##i > 0 ? i < _e_##i : _e_##i < i; i += _d_##i)
#define _range1(n) _range4(0, n, 1, _i)
#define _range2(n, i) _range4(0, n, 1, i)
#define _range3(b, e, i) _range4(b, e, 1, i)
#define range(...) _concat(_range, _argc(__VA_ARGS__))(__VA_ARGS__)
#define _each2(a, x) for (auto& x : a)
#define _each_(a, ...) for (auto& [__VA_ARGS__] : a)
#define _argc2(...) __argc(__VA_ARGS__, _, _, _, _, _, _, _, _, _, _, 2, 1, 0)
#define each(...) _concat(_each, _argc2(__VA_ARGS__))(__VA_ARGS__)
#define enumerate(a, i, ...) for (int i = 0; i != -1; i = -1) each(a, __VA_ARGS__)
#define selecting(x, ...) [&](auto& x) { return __VA_ARGS__; }
#define comparing(x, ...) [&](auto& _l, auto& _r) { auto _f = [&](auto& x) { return __VA_ARGS__; }; return _f(_l) < _f(_r); }
#define adding(x, ...) [&](auto _s, auto& x) { return _s + (__VA_ARGS__); }
#define rep(i, b, e) _range3(b, e, i)
#define trav(x, a) _each2(a, x)
#define all(x) begin(x), end(x)
#define sz len
#define _print_vector_impl s << "{"; string d; for (auto&& y : x) s << d << y, d = ", "; return s << "}";
#define _trace_out cout
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; using vi = vector<int>; using pii = pair<int, int>; template <typename T> int len(const T& x) { return int(x.size()); } template <typename T, size_t l> int len(const T (&)[l]) { return l; } template <typename T, typename S> bool amax(T& t, S s) { return t < s && (t = s, 1); } template <typename T, typename S> bool amin(T& t, S s) { return s < t && (t = s, 1); } int case_id; namespace std { template <typename T, size_t l> ostream& operator<<(ostream& s, const array<T, l>& x); template <typename F, typename S> ostream& operator<<(ostream& s, const pair<F, S>& x); template <typename... T> ostream& operator<<(ostream& s, const tuple<T...>& x); template <typename C, typename T = enable_if_t<!is_same<C, string>::value, typename C::value_type>> ostream& operator<<(ostream& s, const C& x) { _print_vector_impl } template <typename T, size_t l, enable_if_t<!is_same<T, char>::value, int> = 0> ostream& operator<<(ostream& s, const T (&x)[l]) { _print_vector_impl } template <typename T, size_t l> ostream& operator<<(ostream& s, const std::array<T, l>& x) { _print_vector_impl } template <typename F, typename S> ostream& operator<<(ostream& s, const pair<F, S>& x) { return s << "{" << x.first << ", " << x.second << "}"; } template <typename... T> ostream& operator<<(ostream& s, const tuple<T...>& x) { s << "{"; string d; apply([&](auto&&... y) { (..., (s << d << y, d = ", ")); }, x); return s << "}"; } } template <typename T> void _trace(const char* l, const T& x) { if (l[0] != '"') _trace_out << l + (l[0] == ' ') << ": "; _trace_out << x << "\n"; } template <typename T, typename... A> void _trace(const char* l, const T& x, const A&... a) { if (l[0] == ' ') l++; size_t s = strchr(l, ',') - l; if (l[0] != '"') _trace_out.write(l, s) << ": "; _trace_out << x << ", ", _trace(l + s + 1, a...); } template <typename T> void _view(const T& x) { _trace_out << x; } template <typename T, typename... R> void _view(const T& x, int b, int e, R... r) { b < 0 && (b += len(x)), e < 0 && (e += len(x)); b = min(max(b, 0), len(x)), e = min(max(e, b), len(x)); auto it = begin(x); advance(it, b); _trace_out << "{"; for (int i = b; i < e; it++, i++) { if (i != b) _trace_out << ", "; _view(*it, r...); } _trace_out << "}"; }
#if !DEBUG
void _init() __attribute__((constructor)); void _init() { ios::sync_with_stdio(0), cin.tie(0); }
#endif
#pragma endregion common }  // clang-format on

// Additional library code

#pragma GCC diagnostic pop
#pragma endregion programmation }

const int mxn = 100001;
int uf[mxn];
int fin(int i) { return uf[i] < 0 ? i : uf[i] = fin(uf[i]); }
void uni(int i, int j) {
    i = fin(i), j = fin(j);
    if (i == j) return;
    if (uf[i] < uf[j]) swap(i, j);
    uf[j] += uf[i], uf[i] = j;
}
pair<vi, int> qi[mxn];

class Solution {
  public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        memset(uf, -1, sizeof(uf[0]) * n);
        sort(all(edgeList), comparing(e, e[2]));
        range(len(queries), i) qi[i] = {queries[i], i};
        sort(qi, qi + len(queries), comparing(q, q.first[2]));
        vector<bool> ans(len(queries));
        int e = 0;
        range(len(queries), i) {
            while (e < len(edgeList) && edgeList[e][2] < qi[i].first[2]) {
                uni(edgeList[e][0], edgeList[e][1]);
                e++;
            }
            ans[qi[i].second] = fin(qi[i].first[0]) == fin(qi[i].first[1]);
        }
        return ans;
    }
};

#pragma region demo {
#if LOCAL && 01
Solution $s;
int main() {
    auto $t = [&]() {
        cout << "Case #" << ++case_id << ": ";
        // cout << $s;
        cout << "\n";
    };

    $t();
}
#elif !DEBUG && defined(__clang__)
#    pragma clang attribute pop
#endif
#pragma endregion demo }
  */
 /*
  *
  */