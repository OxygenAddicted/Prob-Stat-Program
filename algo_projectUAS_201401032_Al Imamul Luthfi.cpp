#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;


string coin(){

    int res;
    string jenis;
    //memberi hasil random yang diambil dari ruang sampel
    res = ((rand()%2) + 1);

    if (res == 1){
        jenis = "Angka";
        return jenis;
    }
    else{
        jenis = "Gambar";
        return jenis;
    }
}

int dice(){

    int res;
    //memberi hasil random yang diambil dari ruang sampel
    res = ((rand()%6) + 1);
    return res;
}

int fakt_n(int n){

        if (n == 1){
            return n;
        }
		else{
            return n * fakt_n(n-1);
		}
}

int fakt_nr(int nr){

        if (nr == 1){
            return nr;
        }
		else{
            return nr * fakt_nr(nr-1);
		}
}

int fakt_r(int r){

        if (r == 1){
            return r;
        }
		else{
            return r * fakt_r(r-1);
		}
}

int permutasi(int n, int nr){

    int resn = fakt_n(n);
    int resnr = fakt_nr(nr);

    return resn / resnr;
}

int kombinasi(int n, int r, int nr){

    int resn = fakt_n(n);
    int resr = fakt_r(r);
    int resnr = fakt_nr(nr);

    return resn / (resr *  resnr);
}

void urut(float bil[], int n){

    //mengurutkan bilangan dari yang terkecil
    for(int i = n - 1; i >= 0; i--){
        if(bil[i] < bil[i - 1]){
            int temp;
            temp = bil[i];
            bil[i] = bil[i - 1];
            bil[i - 1] = temp;
        }
    }


    //menampilkan hasil urutan
    for (int i = 0; i < n; i++){
        if (i == n - 1){
            cout<< bil[i];
        }
        else{
            cout<< bil[i];
            cout<< ", ";
        }
    }
    cout<<endl;
}

float mean(float bil[], int n){

    int i;
    float mean = 0;
    for (i = 0; i < n; i++){
        mean += bil[i];
    }
    return mean /= n;
}

float median(float bil[], int n){

    float med;
    if (n % 2 == 1){
        med = bil[(n / 2) + 1 / 2] ;
        return med;
    }
    else{
        med = (bil[n / 2 - 1] + bil[n / 2]) / 2;
        return med;
    }
}

void modus(float bil[], int n, float mod[]){

    //k untuk frekuensi, v untuk modus
    int total[100], i, j, k = 1, v = 0, w = 0, z = 0;
    //menghitung frekuensi muncul tiap angka
    for(int i = 0; i < n; i++){
        total[i] = 0;
        for(int j = 0; j < n; j++){
            if(bil[i] == bil[j]){
                total[i]++;
            }
        }
    }

    //menentukan modus
    for(int i = 0; i < n; i++){
        if(total[i] > k){
            k = total[i];
        }
    }

    //cek apakah modus lebih dari satu
    for(int i = 0; i < n; i++){
        if(v == 0){
            mod[v]=0;
        }
        else{
            mod[v] = mod[v-1];
        }

        if(total[i] == k){
            if(bil[i] != mod[v]){
                mod[v] = bil[i];
                v++;
            }
        }
    }

    //cek apakah semua data sama banyaknya
    for(int i = 0; i < n; i++){
        if(total[i] == k){
            z++;
        }
    }
    //jika ya, maka tidak ada modus
    if(z == n){
        v = 0;
    }

    if (v == 0){
        //cek apakah semua data isinya sama
        for(int i = n - 1; i >= 0; i--){
            if(bil[i] == bil[i-1]){
                w++;
            }
        }
        //jika ya, maka akan ke label skip
        if (w == n - 1){
            goto skip;
        }
        cout<<"Modus: (tidak ada)";
        goto endd;
    }
    else{
        cout<<"Modus: ";
        for(int i = 0; i < v; i++){
            cout<< mod[i] <<" ";
        }
        goto endd;
    }

    skip:
        cout<<"Modus: "<< bil[1];
    endd:
        cout<<endl;
}

main(){

	cout<<"===| E-learning Probabilitas dan Statistika Semester 2 |===\n"<<endl;

	signup:
        char uname[33], pass[33];
        cout<<"+------------+"<<endl;
        cout<<"|Sign Up Page|"<<endl;
        cout<<"+------------+\n"<<endl;
        cout<<"Username: "; cin>>uname;
        cout<<"Password: "; cin>>pass;
        cout<<"\nSign up berhasil"<<endl;
        system("pause");

    signin:
        system("CLS");
        cout<<"===| E-learning Probabilitas dan Statistika Semester 2 |===\n"<<endl;

        char un[33], pw[33], yn;
        cout<<"+------------+"<<endl;
        cout<<"|Sign in Page|"<<endl;
        cout<<"+------------+\n"<<endl;
        cout<<"Belum punya akun? (Y/N): "; cin>>yn;
        if(yn == 'Y' || yn == 'y'){
            goto signup;
        }
        cout<<"\nUsername: "; cin>>un;
        cout<<"Password: "; cin>>pw;

        int x, y;
        x = strcmp(uname, un);
        y = strcmp(pass, pw);

        if (x == 0 && y == 0){
            cout<<"\nSign in berhasil."<<endl;
        }
        else{
            cout<<"\nUsername atau password salah. Silakan coba lagi."<<endl;
            goto signin;
        }
        system("pause");

    landing:
		system("CLS");
        cout<<"===| E-learning Probabilitas dan Statistika Semester 2 |===\n"<<endl;

        int input;
        cout<<"Selamat datang, "<<uname<<"."<<endl;
        cout<<"\nIngin belajar apa hari ini?"<<endl;
        cout<<"1. Probabilitas"<<endl;
        cout<<"2. Statistika"<<endl;
        cout<<"3. Sign out"<<endl;
        cout<<"\nInput: "; cin>>input;

        if (input == 1){
            goto prob;
        }
        else if (input == 2){
            goto stat;
        }
        else if (input == 3){
            goto signin;
        }
        else{
            cout<<"Maaf, Anda tidak menginput sesuai dengan list pelajaran. Silakan coba lagi.\n"<<endl;
            system("pause");
            goto landing;
        }

        prob:
            system("CLS");
            cout<<"===| E-learning Probabilitas dan Statistika Semester 2 |===\n"<<endl;

            cout<<"Probabilitas (probability) adalah suatu nilai yang digunakan untuk mengukur "<<endl;
            cout<<"tingkat terjadinya suatu kejadian yang acak.\n"<<endl;
            cout<<"Probabilitas secara umum merupakan peluang bahwa sesuatu akan terjadi.\n"<<endl;

            int imp;
            cout<<"Probabilitas dapat diimplementasikan pada: "<<endl;
            cout<<"1. Koin"<<endl;
            cout<<"2. Dadu"<<endl;
            cout<<"3. Permutasi"<<endl;
            cout<<"4. Kombinasi"<<endl;
            cout<<"5. Kembali ke menu utama"<<endl;
            cout<<"\nInput: "; cin>>imp;

            if (imp == 1){
                koin:
                system("CLS");
                cout<<"===| E-learning Probabilitas dan Statistika Semester 2 |===\n"<<endl;

                cout<<"Ruang sampel dari koin adalah dua, karena mata koin hanya ada dua ";
                cout<<"yaitu angka dan gambar.\n"<<endl;
                cout<<"contoh:\n"<<endl;
                cout<<"Andra melempar koin sebanyak satu kali.\n"<<endl;

                string res = coin();

                cout << "        ===============" << endl;
                cout << "        =    "<< res << "   = " << endl;
                cout << "        ===============\n" << endl;
                cout << "Peluang Andra mendapatkan mata koin "<< res <<" adalah 1/2."<<endl;
                cout<<"\nLempar ulang?"<<endl;
                cout<<"> Y"<<endl;
                cout<<"> N"<<endl;
                cout<<"Input: "; cin>>yn;
                if (yn == 'y' || yn == 'Y'){
                    goto koin;
                }

                goto bacc;
            }
            else if (imp == 2){
                dadu:
                    system("CLS");
                    cout<<"===| E-learning Probabilitas dan Statistika Semester 2 |===\n"<<endl;

                    cout<<"Ruang sampel dari dadu adalah enam, karena mata dadu hanya ada enam ";
                    cout<<"yaitu 1, 2, 3, 4, 5, dan 6.\n"<<endl;
                    cout<<"contoh:\n"<<endl;
                    cout<<"Avan melempar dadu sebanyak satu kali.\n"<<endl;

                    int res = dice();
                    cout << "        ===============" << endl;
                    cout << "        =      " << res << "     =" << endl;
                    cout << "        ===============\n" << endl;

                    cout << "Peluang Avan mendapatkan mata dadu " << res <<" adalah 1/6."<<endl;

                    cout<<"\nLempar ulang?"<<endl;
                    cout<<"> Y"<<endl;
                    cout<<"> N"<<endl;
                    cout<<"Input: "; cin>>yn;
                    if (yn == 'y' || yn == 'Y'){
                        goto dadu;
                    }

                goto bacc;
            }
            else if (imp == 3){
                perm:
                    system("CLS");
                    cout<<"===| E-learning Probabilitas dan Statistika Semester 2 |===\n"<<endl;

                    cout<<"Permutasi adalah penyusunan kembali suatu kumpulan objek dalam urutan ";
                    cout<<"yang berbeda dari urutan yang semula.\n"<<endl;
                    cout<<"contoh:\n"<<endl;


                    int n, r;
                    cout<<"Masukkan nominal n: "; cin>>n;
                    cout<<"Masukkan nominal r: "; cin>>r;
                    cout<<endl;

                    if (n < r){
                        cout<<"n tidak boleh lebih kecil daripada r. Silakan input ulang."<<endl;
                        system("pause");
                        goto perm;
                    }

                    cout<<"nPr = n!/(n-r)!"<<endl;
                    cout<< n <<"P"<< r <<" = "<< n <<"!/("<< n <<"-"<< r <<")!"<<endl;
                    cout<<"    = "<< permutasi(n, n - r) <<endl;

                    cout<<"\nHitung ulang?"<<endl;
                    cout<<"> Y"<<endl;
                    cout<<"> N"<<endl;
                    cout<<"Input: "; cin>>yn;
                    if (yn == 'y' || yn == 'Y'){
                        goto perm;
                    }
                    goto bacc;
            }
            else if (imp == 4){
                komb:
                    system("CLS");
                    cout<<"===| E-learning Probabilitas dan Statistika Semester 2 |===\n"<<endl;

                    cout<<"Kombinasi adalah penyusunan kembali suatu kumpulan objek tanpa memerhatikan urutan ";
                    cout<<"yang berbeda dari urutan yang semula.\n"<<endl;
                    cout<<"contoh:\n"<<endl;

                    int n, r;
                    cout<<"Masukkan nominal n: "; cin>>n;
                    cout<<"Masukkan nominal r: "; cin>>r;
                    cout<<endl;

                    if (n < r){
                        cout<<"n tidak boleh lebih kecil daripada r. Silakan input ulang.";
                        goto komb;
                    }

                    cout<<"nCr = n!/r!(n-r)!"<<endl;
                    cout<< n <<"C"<< r <<" = "<< n <<"!/"<< r <<"!("<< n <<"-"<< r <<")!"<<endl;
                    cout<<"    = "<< kombinasi(n, r, n - r) <<endl;

                    cout<<"\nHitung ulang?"<<endl;
                    cout<<"> Y"<<endl;
                    cout<<"> N"<<endl;
                    cout<<"Input: "; cin>>yn;
                    if (yn == 'y' || yn == 'Y'){
                        goto komb;
                    }

                    goto bacc;
            }
            if (imp == 5){
                goto landing;
            }
            else {
                cout<<"Maaf Anda tidak menginput menu yang tersedia. Silakan coba lagi.\n"<<endl;
                system("pause");
                goto prob;
            }

            bacc:
                cout<<"\nIngin kembali ke menu probabilitas?"<<endl;
                cout<<"> Y"<<endl;
                cout<<"> N"<<endl;
                cout<<"Input: "; cin>>yn;
                if (yn == 'y' || yn == 'Y'){
                    goto prob;
                }
                cout<<"\nIngin kembali ke menu utama?"<<endl;
                cout<<"> Y"<<endl;
                cout<<"> N"<<endl;
                cout<<"Input: "; cin>>yn;
                if (yn == 'y' || yn == 'Y'){
                    goto landing;
                }

            goto akhir;

        stat:
            system("CLS");
            cout<<"===| E-learning Probabilitas dan Statistika Semester 2 |===\n"<<endl;

            cout<<"Statistika adalah sebuah ilmu yang mempelajari bagaimana cara merencanakan, "<<endl;
            cout<<"mengumpulkan, menganalisis, lalu menginterpretasikan, dan akhirnya mempresentasikan data.\n"<<endl;
            cout<<"Singkatnya, statistika adalah ilmu yang bersangkutan dengan suatu data.\n"<<endl;
            cout<<"Di sini kita akan mempraktikkan ilmu statistika dengan mencari mean, median, dan modus.\n"<<endl;

            cout<<"contoh:\n"<<endl;

            int n, i, j;
            float bil[100], mod[100];
            cout<<"Banyak data yang akan dihitung: "; cin>>n;
            cout<<endl;

            cout<<"Input data dalam bilangan bulat!"<<endl;
            for(int i = 0; i < n; i++){
                cout<<"Data "<<(i+1)<<" : "; cin>>bil[i];
            }
            cout<<endl;

            cout<<"Susunan data sesuai urutan dari yang terkecil"<<endl;
            cout<<"----------------------------------------------\n"<<endl;
            urut(bil, n);
            cout<<endl;
            cout<<"Mean: "<< mean(bil, n)<<endl;
            cout<<"Median: "<< median(bil, n)<<endl;
            modus(bil, n, mod);
            cout<<endl;

            cout<<"\nHitung ulang?"<<endl;
            cout<<"> Y"<<endl;
            cout<<"> N"<<endl;
            cout<<"Input: "; cin>>yn;
            if (yn == 'y' || yn == 'Y'){
                goto stat;
            }

            cout<<"\nIngin kembali ke menu utama?"<<endl;
            cout<<"> Y"<<endl;
            cout<<"> N"<<endl;
            cout<<"Input: "; cin>>yn;
            if (yn == 'y' || yn == 'Y'){
                goto landing;
            }

        akhir:
            cout<<"\nApakah Anda yakin ingin keluar dari e-learning?";
            cout<<"> Y"<<endl;
            cout<<"> N"<<endl;
            cout<<"Input: "; cin>>yn;
            if (yn == 'n' || yn == 'N'){
                goto landing;
            }

            cout<<"\nAkun Anda akan otomatis sign out."<<endl;
            return 0;
}
