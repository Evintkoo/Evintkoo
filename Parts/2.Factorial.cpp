#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

ll deret_faktorial[26];

void faktorial() {
    deret_faktorial[0] = 1 ;
    for (ll i = 1 ; i <= 25 ; i++) {
        deret_faktorial[i] = i*deret_faktorial[i-1] ;
    }
}

int main() {
    faktorial() ;
    cout << "Masukan angka : " ;
    ll a ;
    cin >> a;
    if (a < 26) cout << "Nilai dari " << a << "! adalah " << deret_faktorial[a] ;
    else cout << "Mohon maaf nilai faktorial tidak dapat di hitung" << endl ;
}
