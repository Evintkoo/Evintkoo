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
    ll a ;
    cout << "Masukan angka : " ;
    cin >> a ;
    if (a <= 664579) {
        cout << "Bilangan prima pertama hingga ke-" << a << " adalah \n" ;
        for (ll i = 0 ; i < a ; i++) {
            cout << deret_prima[i] << " " ;
        }
    } else cout << "Mohon maaf deret prima tidak dapat di sajikan" ;
    cout << endl ;
}
