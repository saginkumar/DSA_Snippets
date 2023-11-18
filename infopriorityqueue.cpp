/*
 ____    _    ____ ___ _   _
/ ___|  / \  / ___|_ _| \ | |
\___ \ / _ \| |  _ | ||  \| |
 ___) / ___ \ |_| || || |\  |
|____/_/   \_\____|___|_| \_|
 
*/
#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
#define int long long int

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define endl '\n'
#define mod 1000000007
#define mod2 998244353
class info{
  public:
  string path = "";
  int x = 0, y = 0, len = 0;
  info(int _len, string _path, int _x, int _y){
    len = _len;
    path = _path;
    x = _x;
    y = _y;
  }
  info(){
    len = 0;
    path = "";
    x = 0;
    y = 0;
  }
  bool operator<(const info &other) const {
      return len > other.len;
  }
};
signed main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  cin >> n >> m;
  int stx = 0, sty = 0, endx = 0, endy = 0;
  vector<vector<char>>grid(n, vector<char>(m, '0'));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> grid[i][j];
      if(grid[i][j] == 'A'){
        stx = i, sty = j;
      }
      if(grid[i][j] == 'B'){
        endx = i, endy = j;
      }
    }
  }
  auto inside = [&](int i, int j){
    return (0 <= i && i <= n-1 && 0 <= j && j <= m-1);
  };
  vector<pair<pair<int,int>,char>> dir;
  dir.push_back({{1, 0}, 'D'});
  dir.push_back({{-1, 0}, 'U'});
  dir.push_back({{0, 1}, 'R'});
  dir.push_back({{0, -1}, 'L'});
  priority_queue<info>pq;
  pq.push({0, "", stx, sty});
  pq.push({-1, "", stx, sty});
  cout << pq.top().len;
  return (0);
} 
