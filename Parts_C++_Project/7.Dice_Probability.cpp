#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

ll pe ;

void solve1(ll x, ll a, ll b, ll c) {
    if (c <= b){
        if (x == a && c == b) {
            pe++ ;
        }
        else{
            for (ll i = 1 ; i <= 6 ; i++) {
                solve1(x+i,a,b,c+1) ;
            }
        }
    }
}

int main() {
    ll b, a;
    pe = 0;
    cout << "Masukan jumlah dadu : " ;
    cin >> b ;
    cout << "Masukan angka yang diinginkan : " ;
    cin >> a ;
    if (a <= b*6 && b <= 10 && a >= b) {
        if (a!=b && a!= b*6) solve1(0,a,b,0) ;
        else pe = 1 ;
        ll total_sample = pow(6,b) ;
        ll kemungkinan = pe ;
        ll ans = __gcd(kemungkinan,total_sample) ;
        cout << "Peluang jumlah mata dadu sebanyak " << a << " dengan jumlah dadu " << b << " adalah " << kemungkinan/ans << "/" << total_sample/ans ;
    } else if (a < b || a > b){
        cout << "tidak memungkinkan" ;
    } else cout << "Mohon maaf, peluang tidak dapat di hitung karena melebihi batas" ;
    cout << endl ;
}
