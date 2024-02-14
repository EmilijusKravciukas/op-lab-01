#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Studentas{
        string vardas;
        string pavarde;
        int n;
        int* nd = nullptr;
        int egz;
        double mediana;
};

int m;

void duomSkait(Studentas*& studentai);
void ivestis(Studentas*&);
void atvaizd(Studentas*& studentai, int skaiciavimas);

int main(){
    int skaiciavimas = 0; //0 - vid, 1 - med

    Studentas* studentai = nullptr;



    //duomSkait(studentai);
    atvaizd(studentai, skaiciavimas);


    return 0;
}

void ivestis(Studentas*& studentai){
    bool loop = true;
    char cInput = ' ';
    int mTemp = 0;
    int nTemp = 0;
    while(loop){
        cout << "Pridėti naują studentą? (T/N): ";
        cin >> cInput;
        if(cInput == 'T'){
            cout << "Pasirinkite įvedimo būdą:" << endl
            << "(1) Duomenų įvedimas ranka" << endl
            << "(2) Generuoti pažymius" << endl
            << "(3) Generuoti vardą, pavardę ir pažymius" << endl
            << "(4) Baigti darbą" << endl;

            cin >> cInput;

            if(cInput == '1'){
                Studentas* studentaiTemp = new Studentas[mTemp];
                bool ndLoop = true;

                cout << "Įveskite studento vardą: ";
                studentai[mTemp].vardas = stringIvestis();
                cout << "Įveskite studento pavardę: ";
                studentai[mTemp].pavarde = stringIvestis();
                
                while(ndLoop){
                    cout << "Įveskite studento namų darbų pažymius (0 - pereiti prie egzamino pažymio įvesties): ";
                    int temp = intIvestis();
                    if(temp != 0){
                        studentai[mTemp].nd[nTemp] = temp;
                        nTemp++;
                    } else {
                        cout << "Įveskite studento egzamino pažymį: ";
                        studentai[mTemp].egz = intIvestis();
                        ndLoop = false;
                    }
                }
            }
        }
    }
}

string stringIvestis(){
    string cInput;
    bool loop = false;

    do{
        loop = false;
        cin >> cInput;
        for(char a : cInput){
            if(isblank(a) || isdigit(a) || cInput.length() > 16){
                cout << "Klaida. Bandykite dar kartą: ";
                loop = true;
            }
        }
    }while(loop);

    return cInput;
}

int intIvestis(){
    int cInput;
    bool loop = false;

    do{
        loop = false;
        cin >> cInput;
        for(char a : to_string(cInput)){
            if(isblank(a) || !(isdigit(a)) || a < 0 || a > 10){
                cout << "Klaida. Bandykite dar kartą: ";
                loop = true;
            }
        }
    }while(loop);

    return cInput;
}

// void duomSkait(Studentas*& studentai){
//     ifstream DF("data.txt");

//     DF >> m;

//     for(int i = 0; i < m; i++){
//         DF >> studentai[i].vardas;
//         DF >> studentai[i].pavarde;
//         DF >> studentai[i].n;
//         int temp = 0;
//         int* medianaMas{new int[studentai[i].n]{}};
//         for(int j = 0; j < studentai[i].n; j++){
//             DF>>temp;
//             studentai[i].nd += temp;
//             medianaMas[j] = temp;
//         }
//         studentai[i].nd /= studentai[i].n;
//         for(int j = 0; j < studentai[i].n-1; j++){
//             for(int z = 0; z < studentai[i].n; z++){
//                 if(medianaMas[j] < medianaMas[z]){
//                     temp = medianaMas[j];
//                     medianaMas[j] = medianaMas[z];
//                     medianaMas[z] = temp;
//                 }
//             }
//         }
//         if(studentai[i].n % 2 == 0){
//             studentai[i].mediana = (medianaMas[studentai[i].n/2] + medianaMas[studentai[i].n/2 + 1]) / 2;
//         } else {
//             studentai[i].mediana = medianaMas[studentai[i].n/2 + 1];
//         }
//         DF>>studentai[i].egz;
//     }

//     DF.close();
// }

void atvaizd(Studentas*& studentai, int skaiciavimas){
    if(skaiciavimas == 0) {
        cout << left << setw(16) << "Pavardė" << left << setw(16) << "Vardas" << left << setw(16) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------------" << endl;
        for(int i = 0; i < m; i++){
            cout << left << setw(15) << studentai[i].vardas
                << left << setw(16) << studentai[i].pavarde
                << setprecision(2) << fixed << left << setw(16) << studentai[i].nd * 0.4 + double(studentai[i].egz) * 0.6 << endl;
        }
    } else {
        cout << left << setw(16) << "Pavardė" << left << setw(16) << "Vardas" << left << setw(16) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------------" << endl;
        for(int i = 0; i < m; i++){
            cout << left << setw(15) << studentai[i].vardas
                << left << setw(16) << studentai[i].pavarde
                << setprecision(2) << fixed << left << setw(16) << double(studentai[i].mediana) * 0.4 + double(studentai[i].egz) * 0.6 << endl;
        }
    }
}
