#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

bl x[10000001] ;
ll deret_prima[1000000] ;
ll batas = 10000001 ;

void prima() {
    memset(x,1,sizeof(x)) ;
    for (ll i = 2 ; i <= batas ; i++) {
        for (ll j = i+i ; j <= batas ; j += i) {
            x[j] = false;
        }
    }
    ll p = 0 ;
    for (ll i = 2 ; i <= batas ; i++) {
        if (x[i]) {
            deret_prima[p] = i ;
            p++ ;
        }
    }
    //cout << p << endl ;
}

int main() {
    prima() ;
    cout << "Masukan angka : " ;
    ll a ;
    cin >> a;
    ll b = a ;
    cout << "faktorisasi prima dari " << a << " adalah : \n" ;
    for (ll i = 0 ; i*i <= a && a > 1; i++) {
        ll faktor = deret_prima[i] ;
        ll pangkat = 0 ;
        if (a%faktor == 0) {
            while (a%faktor == 0) {
                pangkat++ ;
                a /= faktor ;
            }
            if (pangkat == 1) cout << faktor;
            else cout << faktor << "^" << pangkat  ;
            if (a != 1) cout << " x " ;
        }
    }
    cout << endl << "Pemfaktoran dari bilangan " << b << " adalah : \n" ;
    vector<ll> x ;
    for (ll i = 1 ; i*i <= b ; i++) {
        if (b%i == 0) {
            x.pb(i) ;
            if (i*i != b) x.pb(b/i) ;
        }
    }
    sort(x.begin(), x.end()) ;
    for (ll i = 0 ; i < x.size() ; i++) {
        cout << x[i] << " " ;
    }
    cout << endl ;
}
