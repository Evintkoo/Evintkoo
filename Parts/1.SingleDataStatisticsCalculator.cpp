#include <bits/stdc++.h>
typedef long long ll ;
typedef bool bl ;
#define pb push_back
#define fi first
#define se second
using namespace std;
vector<float> arr ;
float sum, avg, ma = -1000, mi = INT_MAX;
ll n;
ll pe ;
ll batas = 10000001 ;
ll deret_faktorial[26], deret_prima[1000000] ;
ll deret_fibo[100] ;
bl x[10000001] ;
float median(ll a) {
    if (n%2) {
        if (a == 2) return arr[n/2] ;
        else {
            if((n+1)%4 == 0) {
                if (a == 1) return arr[n/4] ;
                if (a == 3) return arr[3*n/4] ;
            } else {
                if (a == 1) return (arr[(n-1)/4-1] + arr[(n-1)/4])/2 ;
                if (a == 3) return (arr[n-(n-1)/4] + arr[n-1-(n-1)/4])/2 ;
            }
        }
    } else {
        if (a == 2) return (arr[(n-1)/2]+arr[((n-1)/2)+1])/2 ;
        else {
            if (n%4 == 0) {
                if (a == 1) return arr[(n-1)/4] ;
                if (a == 3) return arr[n-1-((n-1)/4)] ;
            } else {
                if (a == 1) return (arr[(n-1)/4]+arr[(n-1)/4-1])/2 ;
                if (a == 3) return (arr[n-(n-1)/4]+arr[n-1-(n-1)/4])/2 ;
            }
        }
    }
}
float varians() {
    float ans = 0 ;
    //O(n)
    for (ll i = 0 ; i < n ; i++) {
        ans += pow((arr[i]-avg),2) ;
    }
    ans /= n ;
    return ans ;
}
float simpangan() {
    float ans = 0 ;
    //O(n)
    for (ll i = 0 ; i < n ; i++) {
        ans += abs(arr[i]-avg) ;
    }
    ans /= n ;
    return ans ;
}

int main() {
    cout << "PROGRAM STATISTIK DATA TUNGGAL\n" ;
    cout << "===============================================\n\n" ;
    cout << "Masukan jumlah data : " ;
    cin >> n ;
    cout << "Masukan data, dengan pemisahan tiap data berupa spasi atau enter : \n" ;
    sum = 0 ;
    ma = -1000001 ;
    mi = INT_MAX ;
    arr.clear() ;
    //O(n)
    for (ll i = 1 ; i <= n ; i++) {
        float a;
        cin >> a;
        arr.pb(a) ; //menggunakan vektor sebagai tempat penyimpanan
        sum += a ; //menentukan jumlah array bersamaan dengan masukan dari user
        if (mi > a) mi = a ; // menentukan nilai minimal dari vektor arr bersamaan dengan masukan dari user
        if (ma < a) ma = a ; //menentukan nilai maksimal dari vektor arr bersamaan dengan masukan user
    }
    sort(arr.begin(),arr.end()) ; //mengurutkan vektor secara acending, kompleksitas O(nlogn)
    avg = sum / n ; //menentukan nilai rata-rata dari array
    float var = varians() ; //memanggil fungsi varians() yang disimpan di dalam variabel "var"

    //output kepada user (hasil program)
    cout << endl << "HASIL PERHITUNGAN STATISTIK" << endl ;
    cout << "====================================\n\n" ;
    cout << "Data tunggal terurut sebagai berikut \n" ;
    //mengeluarkan data secara terurut
    for (ll i = 0 ; i < n ; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl << endl;
    cout << "Jumlah data :" << n << endl ; //mengeluarkan jumlah data yang dimasukan
    cout << "Nilai minimum : " << setprecision(2) << fixed << mi << endl ; //mengeluarkan nilai minimum dari vektor
    cout << "Nilai maksimum : " << setprecision(2) << fixed << ma << endl ; //mengeluarkan nilai maksimum dari vektor
    cout << "Rata-rata : " << setprecision(2) << fixed << avg << endl; //mengeluarkan rata-rata vektor
    cout << "Jumlah : " << setprecision(2) << fixed << sum << endl ; //mengeluarkan jumlah vektor
    cout << "Kuartil bawah : " << setprecision(2) << fixed << median(1) << endl ; //mengeluarkan kuartil bawah vektor
    cout << "Median : " << setprecision(2) << fixed << median(2) << endl ; //mengeluarkan median vektor
    cout << "Kuartil atas : " << setprecision(2) << fixed << median(3) << endl ; //mengeluarkan kuartil atas vektor
    cout << "Varians : " << setprecision(2)<< fixed << var << endl ; //mengeluarkan varians vektor
    cout << "Simpangan baku : " << setprecision(2) << fixed << sqrt(var) << endl ; //mengeluarkan nilai dari simpangan baku
    cout << "Simpangan rata-rata : "<< setprecision(2) << fixed<< simpangan() << endl ; //mengeluarkan nilai dari simpangan rata-rata
}
