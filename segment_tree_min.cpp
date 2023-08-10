
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100], seg[4 * 100];
void build(int low, int high, int index){
  if(low == high){
    seg[index] = a[low];
    return;
  }
  int mid = (low + high)/2;
  build(low, mid, 2*index+1);
  build(mid+1, high, 2*index+2);
  seg[index] = max(seg[2*index+1], seg[2*index+2]);
}
int query(int index, int low, int high, int l, int r){
  if(low >= l && high <= r){
    return seg[index];
  }
  if(high < l || low > r) return INT_MIN;
  int mid = (low + high)/2;
  int left = query(2*index+1, low, mid, l, r);
  int right = query(2*index+2, mid+1, high, l, r);
  return max(left, right);
}
signed main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  #endif
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  build(0, n-1, 0);
  int q;
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;
    cout << query(0, 0, n-1, l, r) << " ";
  }
	return 0;
}
