
#include <bits/stdc++.h>
using namespace std;
class Disjoint{
  vector<int>parent, rank;
  public:
  Disjoint(int n){
    parent.resize(n+1, 0);
    rank.resize(n+1);
    for(int i=0; i<=n; i++){
      parent[i] = i;
    }
  }
  int findPar(int node){
    if(node == parent[node]){
      return node;
    }
    else{
      return parent[node] = findPar(parent[node]);
    }
  }
  void unionByRank(int u, int v){
    int tp_v = parent[v];
    int tp_u = parent[u];
    if(tp_v == tp_u) return;
    else if(rank[tp_v] > rank[tp_u]){
      parent[tp_u] = tp_v;
    }
    else if(rank[tp_u] > rank[tp_v]){
      parent[tp_v] = tp_u;
    }
    else{
      parent[tp_v] = tp_u;
      rank[tp_u]++;
    }
  }
};
signed main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  #endif
  Disjoint ds(7);
  ds.unoinByRank(1,2);
  ds.unoinByRank(2,3);
  ds.unoinByRank(4,5);
  ds.unoinByRank(6,7);
  ds.unoinByRank(3,4);
  ds.unoinByRank(4, 7);
  cout << ds.findPar(2) << " "<< ds.findPar(7);
	return 0;
}
