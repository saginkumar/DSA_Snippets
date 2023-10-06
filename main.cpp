
#include <bits/stdc++.h>
using namespace std;
class info{
public:
  int open, close, full;
public:
  info(int _open, int _close, int _full){
    open = _open;
    close = _close;
    full = _full;
  }
  info(){
    open = 0;
    close = 0;
    full = 0;
  }
};
info merge(info left, info right){
  info ans = info(0, 0, 0);
  ans.full = left.full + right.full + min(left.open, right.close);
  ans.open = left.open + right.open - min(left.open, right.close);
  ans.close = left.close + right.close - min(left.open, right.close);
  return ans;
}
void build(int index, int low, int high, string &s, info seg[]){
  if(low == high){
    seg[index].open = s[low] == '(';
    seg[index].close = s[low] == ')';
    seg[index].full = 0;
    return;
  }
  int mid = (low + high) >> 1;
  build(2*index+1, low, mid, s, seg);
  build(2*index+2, mid+1, high, s, seg);
  seg[index] = merge(seg[2*index+1], seg[2*index+2]);
}
info query(int index, int low, int high, int l, int r, info seg[]){
  if(low >= l && high <= r){
    return seg[index];
  }
  if(low > r || high < l) return info(0, 0, 0);
  int mid = (low + high) >> 1;
  info left = query(2*index+1, low, mid, l, r, seg);
  info right = query(2*index+2, mid+1, high, l, r, seg);
  return merge(left, right);
}
signed main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  #endif
  string s = "";
  cin >> s;
  int n = s.size();
  info seg[4*n];
  build(0, 0, n-1, s, seg);
  int q;
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;
    l--; r--;
    info ans = query(0, 0, n-1, l, r, seg);
    cout << ans.full * 2 << endl;
  }
	return 0;
}