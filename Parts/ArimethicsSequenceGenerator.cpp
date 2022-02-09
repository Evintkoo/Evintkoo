#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

int main () {
    float a, b;
    ll n;
    cout << "Masukan nilai a : " ;
    cin >> a ;
    cout << "Masukkan nilai b : " ;
    cin >> b ;
    cout << "Masukkan banyak suku : " ;
    cin >> n ;
    cout << "Deret aritmatika : \n" ;
    for (ll i = 0 ; i < n ; i++) {
        cout << a+b*i << " ";
    }
    cout << endl ;
    float sum = n*(2*a+(n-1)*b)/2 ;
    cout << "Jumlah deret : " << setprecision(2) << fixed << sum << endl ;
}
