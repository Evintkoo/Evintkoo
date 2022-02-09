#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;

int main() {
    cout << "Masukan nilai a : " ;
    float a, b, c;
    cin >> a;
    cout << "Masukan nilai b : " ;
    cin >> b ;
    cout << "Masukan nilai c : " ;
    cin >> c ;
    float D = pow(b,2) -4*a*c ;
    if (D >= 0) {
        //(sqrt(D)-b)/(2*a)
        float akar1 = (0-sqrt(D)-b)/(2*a) ;
        float akar2 = (sqrt(D)-b)/(2*a) ;
        cout << "Akar persamaan kuadrat dari " ;
        if (a != 0) cout << a << "x^2" ;
        if (b != 0) {
            if (b < 0) cout << " - " << abs(b) << "x" ;
            if (b > 0) cout << " + " << b << "x" ;
        }
        if (c != 0) {
            if (c > 0) cout << " + " << c ;
            else cout << " - " << abs(c) ;
        }
        cout << " : " ;
        if (akar1 != akar2) {
            cout << akar1 << " dan " << akar2 ;
        } else {
            cout << akar1 ;
        }
        cout << endl ;
    } else {
        cout << "Tidak ada akar real\n" ;
    }
}
