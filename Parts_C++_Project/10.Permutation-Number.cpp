#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

int main() {
    ll n ;
    cout << "Masukan jumlah angka yang akan di acak : " ;
    cin >> n ;
    vector<ll> x ;
    for (ll i = 1 ; i <= n ; i++) {
        ll a ;
        cin >> a ;
        x.pb(a) ;
    }
    sort(x.begin(),x.end()) ;
    // << "Berikut urutan permutasi dari angka-angka diatas : \n" ;
    ll ans = 0 ;
    do {
        ans++ ;
        /*for (ll i = 0 ; i < x.size() ; i++) {
            cout << x[i] << " " ;
        }
        cout << endl ;*/
    } while(next_permutation(x.begin(),x.end())) ;
    cout << "Didapat " << ans << " urutan berbeda yang dapat disusun\n" ;
}
