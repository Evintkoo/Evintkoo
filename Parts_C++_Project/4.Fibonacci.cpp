#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

ll deret_fibo[100] ;
ll batas = 10000001 ;

void fibo() {
    deret_fibo[1] = 1 ;
    deret_fibo[2] = 1 ;
    ll p= 2 ;
    for(ll i = 3 ; i <= batas && deret_fibo[i-1] > 0; i++) {
        deret_fibo[i] = deret_fibo[i-1] + deret_fibo[i-2] ;
        p++ ;
    }
    //cout << p ;
}

int main() {
    fibo() ;
    cout << "Masukan angka : ";
    ll a ;
    cin >> a ;
    if (a < 93) {
        cout << "Deret fibonaci pertama hingga ke-" << a << " adalah : \n" ;
        for (ll i = 1 ; i <= a ; i++) {
            cout << deret_fibo[i] << " " ;
        }
    } else {
        cout << "Mohon maaf angka tidak dapat di hitung karena melebihi batas" ;
    }
    cout << endl ;
}
