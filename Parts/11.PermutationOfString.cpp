#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

int main (){
    cout << "Masukan kata : " ;
    string a ;
    cin >> a ;
    sort(a.begin(),a.end()) ;
    ll ans = 0 ;
    do {
        ans++ ;
        //cout << a << endl;
    } while (next_permutation(a.begin(),a.end())) ;
    cout << "Didapat " << ans << " kata yang dapat disusun\n" ;
}
