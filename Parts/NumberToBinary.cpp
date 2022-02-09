#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

int main(){
  ll a;
  cout << "Masukan angka yang akan di konversikan ke biner : " ;
  cin >> a ;
  vector<bl> ans ;
  ans.clear() ;
  while (a > 0) {
  ans.pb(a%2) ;
  a /=2 ;
  }
  for (ll i = ans.size()-1 ; i >= 0 ; i--) cout << ans[i] ;
}
