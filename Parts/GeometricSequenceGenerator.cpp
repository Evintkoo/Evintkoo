#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std ;

int main() {
    float a, r, sum = 0;
    ll n;
    cout << "Masukan nilai a : " ;
    cin >> a ;
    cout << "Masukan nilai r (format pecahan x/y): " ;
    string s ;
    cin >> s ;
    if (s.find("/") != -1) {
        float x = s[0]-'0', y = s[2]-'0' ;
        r  = x/y ;
    } else {
        for (ll i = s.length()-1 ; i >= 0 ; i--) {
            ll p = s[i]-'0' ;
            r *= 10 ;
            r += p ;
        }
        //cout << r << " " ;
    }
    cout << "Masukan nilai n : " ;
    cin >> n ;
    for (ll i = 0 ; i < n ; i++) {
        cout << setprecision(8) << a*pow(r,i) << " " ;
        sum += a*pow(r,i) ;
    }
    cout << endl ;
    cout << "Jumlah deret adalah " << setprecision(2) << sum << endl ;
    if (r < 1) {
        cout << "Jumlah deret tak hingga : " ;
        cout << setprecision(2) << a/(1-r) << endl ;
    }
}
