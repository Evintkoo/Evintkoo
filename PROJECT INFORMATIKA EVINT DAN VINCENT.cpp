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


//fungsi median() bertipe data float dengan parameter long long a dengan nilai 1 (Kuartil 1), 2 (kuartil 2), 3 (kuartil 3) sebagai penentu kuartil. Memiliki kompleksitas O(1)
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

//fungsi varians() bertipe data float untuk menentukan nilai varians dari array yang dimasukan user, memiliki kompleksitas waktu O(n)
float varians() {
    float ans = 0 ;
    //O(n)
    for (ll i = 0 ; i < n ; i++) {
        ans += pow((arr[i]-avg),2) ;
    }
    ans /= n ;
    return ans ;
}

//fungsi simpangan() bertipe data float untuk menentukan nilai simpangan baku pada array masukan. memiliki kompleksitas waktu O(n)
float simpangan() {
    float ans = 0 ;
    //O(n)
    for (ll i = 0 ; i < n ; i++) {
        ans += abs(arr[i]-avg) ;
    }
    ans /= n ;
    return ans ;
}

//fungsi statistika() merupakan subprogram dari fitur bernomor 1 tanpa adanya pengembalian, memiliki kompleksitas O(nlogn)
void statistika() {
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
//fungsi faktorial() memprecompute nilai faktorial pada array deret_faktorial[], kompleksitas waktu O(n)
void faktorial() {
    deret_faktorial[0] = 1 ;
    for (ll i = 1 ; i <= 25 ; i++) {
        deret_faktorial[i] = i*deret_faktorial[i-1] ;
    }
}

//menggunakan algoritma sieve of eratosthenes untuk membuat deret prima, kompleksitas O(nlogn)
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

//precumpute deret fibonaci, kompleksitas waktu O(n)
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

//memanggil fungsi untuk precompute nilai faktorial, deret prima, dan deret fibonaci
void build() {
    faktorial() ;
    prima() ;
    fibo() ;
}

//fungsi fibonaci() pada fitur 4
void fibonaci() {
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

void call_prima() {
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

void callfaktorial() {
    cout << "Masukan angka : " ;
    ll a ;
    cin >> a;
    if (a < 26) cout << "Nilai dari " << a << "! adalah " << deret_faktorial[a] ;
    else cout << "Mohon maaf nilai faktorial tidak dapat di hitung" << endl ;
}

//O(1)
void kuadrat() {
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

//O(nlogn)
void faktorisasi() {
    cout << "Masukan angka : " ;
    ll a ;
    cin >> a;
    ll b = a ;
    cout << "faktorisasi prima dari " << a << " adalah : \n" ;
    for (ll i = 0 ; i*i <= a && a > 1; i++) {
        ll faktor = deret_prima[i] ;
        ll pangkat = 0 ;
        if (a%faktor == 0) {
            while (a%faktor == 0) {
                pangkat++ ;
                a /= faktor ;
            }
            if (pangkat == 1) cout << faktor;
            else cout << faktor << "^" << pangkat  ;
            if (a != 1) cout << " x " ;
        }
    }
    cout << endl << "Pemfaktoran dari bilangan " << b << " adalah : \n" ;
    vector<ll> x ;
    for (ll i = 1 ; i*i <= b ; i++) {
        if (b%i == 0) {
            x.pb(i) ;
            if (i*i != b) x.pb(b/i) ;
        }
    }
    sort(x.begin(), x.end()) ;
    for (ll i = 0 ; i < x.size() ; i++) {
        cout << x[i] << " " ;
    }
    cout << endl ;
}

//O(6^n)
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

void peluang() {
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

//O(n)
void aritmatik () {
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

//O(n*k)
void geometrik() {
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

void game_tebak() {
    cout << "SELAMAT DATANG DI GAME TEBAK ANGKA!" << endl ;
    cout << "======================================\n" ;
    cout << "Anda diberikan kesempatan sebanyak 10 kali untuk menebak angka dari 1 hingga 1000\n" ;
    ll p = rand()%1000 ;
    srand(time(0)) ;
    for (ll i = 1 ; i <= 11 ; i++) {
        if (i != 11) {
            cout << "Kesempatan anda tersisa " << 10-i+1 << endl ;
        } else {
            cout << "Kesempatan Terakhir!" << endl ;
        }
        cout << "masukan tebakan anda : " ;
        ll a ;
        cin >> a ;
        if (a == p) {
            cout << "Selamat jawaban anda benar! \n\n" ;
            cout << "PERMAINAN BERAKHIR" ;
            break ;
        } else {
            if (a > p) cout << "Tebakan anda terlalu besar" << endl ;
            else cout << "Tebakan anda terlalu kecil" << endl ;
        }
    }
}
ll arr2[11] ;
bl used[11], ans, used2[11] ;
void solve2(ll i, ll sum, ll k) {
    if (sum > k) {
        return ;
    } else if (sum == k) {
        cout << sum << " " ;
        for (ll i = 1 ; i <= 10 ; i++) {
            used2[i] = used[i] ;
            //cout << used[i] << " " << used2[i] << endl ;
        }
        cout << endl ;
        ans = true ;
        return ;
    } else if (i > 10){
        return ;
    } else if (!ans) {
        used[i] = true ;
        solve2(i+1,sum+arr2[i], k) ;
        used[i] = false ;
        solve2(i+1,sum,k) ;
    }
}

void game_deret() {
    ans = false ;
    memset(used,0,sizeof(used)) ;
    memset(used2,0,sizeof(used2)) ;
    cout << "GAME JUMLAH ANGKA\n" ;
    cout << "====================\n" ;
    cout << "Terdapat angka sebagai berikut : \n" ;
    srand(time(0)) ;
    ll ma = 0 ;
    for (ll i = 1 ; i <= 10 ; i++) {
        ll x = rand()%50 ;
        cout << x << " " ;
        arr2[i] = x ;
        ma += x ;
    }
    cout << endl ;
    ll k = rand()%ma+1;
    cout << "Dapatkah kita menjumlahkan angka-angka tersebut sehingga menghasilkan " << k << "? (Y/N)" ;
    char p ;
    cin >> p ;
    solve2(1,0,k) ;
    if (ans && (p == 'Y' || p == 'y')) {
        cout << "Jawaban anda benar!\n" ;
    } else cout << "Jawaban anda salah!\n" ;
    if (ans) {
        cout << "Angka dapat disusun dengan : " ;
        for (ll i = 1 ; i <= 10 ; i++) {
            if (used2[i]) cout << arr2[i] << " " ;
        }
    }
}

void permutasi_angka() {
    ll n ;
    cout << "Masukan jumlah angka yang akan di acak : " ;
    cin >> n ;
    vector<ll> x ;
    for (ll i = 1 ; i <= n ; i++) {
        ll a ;
        cin >> a ;
        x.pb(a) ;
    }
    sort(x.begin(),x.end()) ;
    // << "Berikut urutan permutasi dari angka-angka diatas : \n" ;
    ll ans = 0 ;
    do {
        ans++ ;
        /*for (ll i = 0 ; i < x.size() ; i++) {
            cout << x[i] << " " ;
        }
        cout << endl ;*/
    } while(next_permutation(x.begin(),x.end())) ;
    cout << "Didapat " << ans << " urutan berbeda yang dapat disusun\n" ;
}

void permutasi_kata(){
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

void permutasi() {
    ll a ;
    cout << "1. Permutasi angka\n" ;
    cout << "2. Permutasi kata\n" ;
    cout << endl << "Masukan pilihan anda : " ;
    cin >> a ;
    system("cls") ;
    if (a == 1) {
        permutasi_angka() ;
    } else if (a == 2) {
        permutasi_kata() ;
    }
}

void randomizer() {
    vector<string> murid{
    "Anastasia Bernice Agusovna Santoso",//1
    "Anindya Utami Nitipadma",//2
    "Anthony Alvin Nathaniel",//3
    "Elisabeth Chandra Rucita",//4
    "Evint Leovonzko",//5
    "Gianella Belva Marsianus",//6
    "Glenn Navero Sitera",//7
    "Immanuelya Hatikvah Stya Persada",//8
    "Ivan Tjandra",//9
    "Joshua Austin Widjaja",//10
    "Julio Vincent Sugiarto",//11
    "Keisha Devana Sugiyanto ",//12
    "Laurencia Edelyne Sanjaya",//13
    "Liuz Lysander Sunarko",//14
    "Mallery Ellen Evania Tombeng",//15
    "Meime Setiawan",//16
    "Muhammad Rafi Danendra",//17
    "Natalie Hartono",//18
    "Nathanael Esmond",//19
    "Nathanael Valentino Kristianto",//20
    "Nathania Sakiara Chrismanto",//21
    "Nyimas Alexandra Callista",//22
    "Richard Angelico Pudjohartono",//23
    "Wisely Suryoyuwono",//24
    "Yeshi Visakha Tan"//25
    } ;
    srand(time(0)) ;
    ret :
    cout << "Terdapat " << murid.size() << " murid yang dapat diambil" << endl ;
    cout << "Masukan jumlah murid yang akan di ambil : " ;
    ll a;
    cin >> a ;
    cout << "Masukan jenis kegiatan : " ;
    string r ;
    cin >> r ;
    ll b = a ;
    if (a <= murid.size() && a > 0) {
        cout << "Berikut murid yang akan di ambil kegiatan " << r << " :" << endl ;
        while (a--) {
            ll x = murid.size() ;
            ll p = rand()%x;
            cout << b-a << ". " << murid[p] << endl ;
            murid.erase(murid.begin()+p) ;
        }
        cout << "Apa ingin melakukan pengambilan lagi? (Y/N)\n" ;
        char ans ; cin >> ans ;
        if (ans == 'Y' || ans == 'y') {
            goto ret ;
        }
    } else cout << "Tidak dapat dilakukan pengambilan\n" ;
}

void trading() {
    ll a = 1000000;
    ll limit = a*1.5 ;
    ll b = a/2 ;
    srand(time(0)) ;
    ll harga  = rand()%1000+50 ;
    back :
    while (a > b && a < limit) {
        cout << "Saldo anda tersisa Rp" << a << endl ;
        cout << "Harga saham ABCD saat ini berada di Rp" << harga << endl;
        ll harga_awal = harga ;
        ll penentu = rand()%2 ;
        if (!penentu) penentu-- ;
        ll b ;
        cout << "Masukan jumlah lot yang ingin anda beli : " ;
        cin >> b ;
        b = b*harga*100 ;
        ll c = b ;
        if (b <= a) {
        	cout << "anda membeli saham ABCD dengan jumlah Rp" << b << endl ;
        	a -= b ;
        }
        else {
            cout << "Maaf, melebihi limit\n" ;
            goto back ;
        }
        ll x = rand() ;
        if (penentu == 1) {
	        if (harga <= 200) {
	            x %= 35 ;
	        } else if (harga <= 5000) {
	            x %= 25 ;
	        } else {
	            x %= 20 ;
        	}
        } else {
        	x %= 7 ;
        }
        float profit = (x*penentu) ;
        harga = harga*(profit+100)/100 ;
        if (harga < 50) harga = 50 ;
        cout << "Harga saham ABCD saat ini menjadi Rp" << harga << endl ;
        //cout << profit << endl ;
        b = b*(profit+100)/100;
        if (profit >= 0) cout << "selamat, anda mendapat keuntungan sebesar " ;
        else cout << "anda kurang beruntung, anda mengalami kerugian sebesar " ;
        cout << "Rp" << abs(c-b) << endl;
        a += b ;
        cout << endl ;
    }
    cout << "Saldo akhir anda adalah " << a << endl;
    if (a >= limit) cout << "Anda memenangkan permainan\n" ;
    else cout << "Anda belum memenangkan permainan \n" ;
}

int main()
{
    build() ;
    restart :
    system("cls") ;
    ll a ;
    cout << "PROJECT INFORMATIKA EVINT LEOVONZKO DAN JULIO VINCENT SUGIARTO XII MIPA SMA BUDI UTAMA\n" ;
    cout << "======================================================================================\n\n" ;
    cout << "fitur pada program : \n" ;
    cout << "1. Perhitungan data statistika\n" ;
    cout << "2. Nilai faktorial\n" ;
    cout << "3. Deret prima\n" ;
    cout << "4. Deret fibonaci\n" ;
    cout << "5. Pemfaktoran dan faktorisasi prima angka\n" ;
    cout << "6. Akar fungsi kuadrat\n" ;
    cout << "7. Peluang dadu\n" ;
    cout << "8. Deret aritmatika\n" ;
    cout << "9. Deret geometrik\n" ;
    cout << "10. Game tebak angka\n" ;
    cout << "11. Game jumlah deret\n" ;
    cout << "12. Permutasi angka dan huruf\n" ;
    cout << "13. Randomizer kelas XII MIPA\n" ;
    cout << "14. Kunci jawaban generator\n";
    cout << "15. Konversi ASCII\n" ;
    cout << "16. Konversi angka ke biner\n" ;
    cout << "17. Game trading\n" ;

    cout << endl << "Masukan pilihan anda : " ;
    cin >> a ;
    system("cls") ;
    if (a == 1) {
        statistika() ;
    } else if (a == 2) {
        callfaktorial() ;
    } else if (a == 3) {
        call_prima() ;
    } else if (a == 4) {
        fibonaci() ;
    } else if (a == 5) {
        faktorisasi() ;
    } else if (a == 6) {
        kuadrat() ;
    } else if (a == 7) {
        peluang() ;
    } else if (a == 8) {
        aritmatik() ;
    } else if (a == 9) {
        geometrik() ;
    } else if (a == 10) {
        game_tebak() ;
    } else if (a == 11) {
        game_deret() ;
    } else if (a == 12) {
        permutasi() ;
    } else if (a == 13) {
        randomizer() ;
    } else if (a == 14) {
        cout << "Masukan jumlah soal : " ;
        ll a ; cin >> a ;
        srand(time(0)) ;
        for(ll i =1 ; i <= a ; i++) {
            char x = rand()%5+'a' ;
            cout << i << ". " << x << endl;
        }
    } else if (a==15) {
        string a ;
        cout << "Masukan huruf/angka yang ingin di konversi : " ;
        cin >> a ;
        ll x = a.length() ;
        for (ll i = 0 ; i < x ; i++) {
            ll p = a[i] ;
            cout << p << " " ;
        }
    } else if (a == 16) {
        ll a;
        cout << "Masukan angka yang akan di konversikan ke biner : " ;
        cin >> a ;
        vector<bl> ans ;
        ans.clear() ;
        while (a > 0) {
            ans.pb(a%2) ;
            a /=2 ;
        }
        for (ll i = ans.size()-1 ; i >= 0 ; i--) cout << ans[i] ;
    } else if (a == 17) {
        trading() ;
    }

    cout << endl << "Apakah ingin di lanjut? (Y/N)\n" ;
    char ans ;
    cin >> ans ;
    if (ans == 'Y' || ans == 'y') {
        goto restart ;
    } else cout << endl << "Program selesai, terimakasih telah menggunakan program kami" ;
    return 0;
}
