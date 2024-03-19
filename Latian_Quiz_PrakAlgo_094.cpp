#include <iostream>
#include <string>
using namespace std;

class dataMahasiswa
{
public:
    string namaMHS;
    string nimMHS;
    float nilaiUTS;
    float nilaiUAS;
    float nilaiHarian;
    float countNilaiAkhir(float persenHarian, float persenUTS, float persenUAS)
    {
        float nilaiAkhir;
        persenHarian = 0.3 * nilaiHarian;
        persenUTS = 0.3 * nilaiUTS;
        persenUAS = 0.4 * nilaiUAS;

        return nilaiAkhir = persenHarian + persenUAS + persenUTS;
    }
};

int getNavigation();

int main()
{
    bool onLoop = true;
    bool isFound = false;
    string setLoop, searchName;
    int navigation, dataSize;
    int index = 0;
    dataMahasiswa data[99];

    while (onLoop)
    {
        system("cls");
        cout << "===================\n";
        cout << "| ATHALLA ZACHARI |\n";
        cout << "| 123210094       |\n";
        cout << "===================\n\n";
        cout << "MAIN MENU\n1. Input Data Mahasiswa\n2. Show Data Mahasiswa\n3. Cari Data Mahasiswa\n4. Exit\n";
        navigation = getNavigation(); // Input pilihan disini

        switch (navigation)
        {
        case 1:
            system("cls");
            cout << "=====================\n";
            cout << "| DATA INPUT        |\n";
            cout << "| Input Data ke - " << index + 1 << " |\n";
            cout << "=====================\n\n";
            cout << "Nama Mahasiswa \t= ";
            cin.ignore();
            getline(cin, data[index].namaMHS);
            cout << "NIM Mahasiswa \t= ";
            getline(cin, data[index].nimMHS);
            cout << "Nilai UTS \t= ";
            cin >> data[index].nilaiUTS;
            cout << "Nilai UAS \t= ";
            cin >> data[index].nilaiUAS;
            cout << "Nilai Harian \t= ";
            cin >> data[index].nilaiHarian;

            index++;
            break;

        case 2:
            system("cls");
            index == 0 ? cout << " Data kosong, silahkan input terlebih dahulu!\n" : cout << " SHOWING ALL DATA\n";
            cout << " Data tercatat - " << index << endl;

            for (int i = 0; i < index; i++)
            {
                cout << "\nNama Mahasiswa \t= " << data[i].namaMHS << endl;
                cout << "Nilai UTS \t= " << data[i].nilaiUTS << endl;
                cout << "Nilai UAS \t= " << data[i].nilaiUAS << endl;
                cout << "Nilai Harian \t= " << data[i].nilaiHarian << endl;
                cout << "Nilai Akhir \t= " << data[i].countNilaiAkhir(data[i].nilaiUTS, data[i].nilaiUAS, data[i].nilaiHarian) << endl;
            }
            break;

        case 3:
            system("cls");
            index == 0 ? cout << " Data kosong, silahkan input terlebih dahulu!\n" : cout << "SEARCH ALL DATA\n";
            cout << "Masukkan nama yang ingin dicari = ";
            cin.ignore();
            getline(cin, searchName);

            for (int i=0; i < index; i++)
            {
                if (data[i].namaMHS == searchName)
                {
                    isFound = true;
                    cout << "Data Found!!\n";
                    cout << "\nNama Mahasiswa \t= " << data[i].namaMHS << endl;
                    cout << "Nilai UTS \t= " << data[i].nilaiUTS << endl;
                    cout << "Nilai UAS \t= " << data[i].nilaiUAS << endl;
                    cout << "Nilai Harian \t= " << data[i].nilaiHarian << endl;
                    cout << "Nilai Akhir \t= " << data[i].countNilaiAkhir(data[i].nilaiUTS, data[i].nilaiUAS, data[i].nilaiHarian) << endl;
                }
                if (!isFound)
                {   
                    cout<<"-----------------------------------\n";
                    cout << "Data yang dicari tidak ditemukan!\n";
                    cout << "Pastikan input benar dan data sudah dimasukkan!\n\n";
                }
            }

            break;

        default:
            break;
        }

        cout << "Kembali ke menu utama?(Y/N)";
        cin >> setLoop;
        setLoop == "Y" || setLoop == "y" ? onLoop = true : onLoop = false;
    }

    return 0;
}


int getNavigation()
{
    int selectedNav;

    cout << "Pilih : ";
    cin >> selectedNav;

    if (selectedNav < 1 || selectedNav > 4)
    {
        cout << "Input salah, silahkan masukkan input yang benar!!\n";
        return getNavigation();
    }
    return selectedNav;
}