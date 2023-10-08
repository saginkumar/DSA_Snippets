
#include <bits/stdc++.h>
using namespace std;
class SGTree{
  public:
    vector<int>seg, lazy;
  public:
    SGTree(int n){
      seg.resize(4*n+1, 0);
      lazy.resize(4*n+1, 0);
    }
    void build(int index, int low, int high, vector<int>&v){
      if(low == high){
        seg[index] = v[low];
        return;
      }
      int mid = (low + high) >> 1;
      build(2*index+1, low, mid, v);
      build(2*index+2, mid+1, high, v);
      seg[index] = seg[2*index+1] + seg[2*index+2];
    }
    void update(int index, int low, int high, int l, int r, int val){
      if(lazy[index] != 0){
        seg[index] += (high - low + 1) * lazy[index];
        if(low != high){
          lazy[2*index+1] += lazy[index];
          lazy[2*index+2] += lazy[index];
        }
        lazy[index] = 0;
      }
      // out of bound
      if(l > high || r < low) return;
      // l low high r
      if(l <= low && high <= r){
        seg[index] += (high - low + 1) * val;
        if(low != high){
          lazy[2*index+1] += lazy[index];
          lazy[2*index+2] += lazy[index];
        }
        return;
      }
      int mid = (low + high) >> 1;
      update(2*index+1, low, mid, l, r, val);
      update(2*index+2, mid+1, high, l, r, val);
      seg[index] = seg[2*index+1] + seg[2*index+2];
    }
    int query(int index, int low, int high, int l, int r){
      if(lazy[index] != 0){
        seg[index] += (high - low + 1) * lazy[index];
        if(low != high){
          lazy[2*index+1] += lazy[index];
          lazy[2*index+2] += lazy[index];
        }
        lazy[index] = 0;
      }
      // out of bound
      if(l > high || r < low) return 0;
      // l low high r
      if(l <= low && high <= r){
        return seg[index];
      }
      int mid = (low + high) >> 1;
      int left = query(2*index+1, low, mid, l, r);
      int right = query(2*index+2, mid+1, high, l, r);
      return (left + right);
    }
};
signed main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  #endif
  int n;
  cin >> n;
  vector<int>v(n);
  for(int &i:v) cin >> i;
  SGTree st(n);
  st.build(0, 0, n-1, v);
  // cout << st.seg[0];
  int q;
  cin >> q;
  while(q--){
    int type  = 0;
    cin >> type;
    if(type == 1){
      int l , r;
      cin >> l >> r;
      cout << st.query(0, 0, n-1, l, r) << endl;
    }
    else{
      int l, r, val;
      cin >> l >> r >> val;
      st.update(0, 0, n-1, l, r, val);
    }
  }
	return 0;
}
