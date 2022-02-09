#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

int main() {
    string a ;
    cout << "Masukan huruf/angka yang ingin di konversi : " ;
    cin >> a ;
    ll x = a.length() ;
    for (ll i = 0 ; i < x ; i++) {
        ll p = a[i] ;
        cout << p << " " ;
    }
}
