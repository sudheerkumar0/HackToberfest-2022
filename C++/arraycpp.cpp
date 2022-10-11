#include<iostream>
using namespace std;
int main()
{
    string nama_012[20],asal_012[30],alamat_012[30],prodi_012[30],data_012;
    char ulangi_012= 'y',pilih_012;
    int x_012,i_012;

    cout<< "--------------------------------------------------------------------"<< endl;
    cout<< "\t\t\t SELAMAT DATANG \t\t\t"<< endl;
    cout<< "\t\t DAFTAR CALON MAHASISWA UNIVERSITAS BOYOLALI \t\t"<< endl;
    cout<< "---------------------------------------------------------------------"<< endl;
    cout<< endl;
    for(int i_012=0; i_012<5; i_012++){
    cout<< "  Masukan Nama calon mahasiswa : ";
    cin>>nama_012[i_012];
    cout<< "  Masukan Asal sekolah         : ";
    cin>>asal_012[i_012];
    cout<< "  Masukan Alamat               : ";
    cin>>alamat_012[i_012];
    cout<< "  Masukan Program Studi        : ";
    cin>>prodi_012[i_012];
    cout<<endl;
    }
     cout<< " Daftar calon mahasiswa UBY keseluruhan ";
            cout<<endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << "NO" << "\t" << " Nama" << "\t \t" << "Asal sekolah" << "\t\t\t"  << "Alamat" << "\t\t\t\t" << "Program Studi"<<" \t\t"<< endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;

            for(int i_012=0; i_012<5; i_012++){
                cout<<i_012<<" \t "<<nama_012[i_012]<<" \t \t "<<asal_012[i_012]<<" \t\t\t"<<alamat_012[i_012]<<" \t\t\t\t "<<prodi_012[i_012]<<endl;
                cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            }

     while(ulangi_012== 'y'){
            cout<<endl;
            cout <<"Daftar nomor berapa yang ingin ditampilkan(0,1,2,3,4)..?: ";
            cin>>x_012;
            cout<<"\n Nama           :"<<nama_012[x_012];
            cout<<"\n Asal sekolah   :"<<asal_012[x_012];
            cout<<"\n Alamat         :"<<alamat_012[x_012];
            cout<<"\n Program Studi  :"<<prodi_012[x_012];
            cout<<endl;
            cout<<"Mau menampilkan data yang lain? (y/t)";
            cout<< "jawab: ";
            cin>>ulangi_012;
     }
            cout<<endl;

        cout<<endl;
        cout<<"================================*******=========================\n";
        cout<<" \t  \t \t      perulangan selesai ! \n";
        cout<<"================================*******=========================\n";
        cout<<" \t \t \t \t \t \t SELESAI \n\n";



    return 0;
}

