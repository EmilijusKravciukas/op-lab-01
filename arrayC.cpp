#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <random>
#include <locale>
#include <time.h>

using namespace std;

struct Studentas{
        string vardas;
        string pavarde;
        int n;
        int* nd = nullptr;
        int egz;
        double vid = 0;
        double mediana;
};

void duomSkait(Studentas*& studentai);
void ivestis(Studentas*&);
void atvaizd(Studentas*& studentai, int skaiciavimas, int m);
string stringIvestis();
int intIvestis();
int randGen(int sRange, int eRange);

int main(){
    srand(time(0));
    system("chcp 65001  > nul");
    Studentas* studentai = nullptr;

    ivestis(studentai);

    return 0;
}

void ivestis(Studentas*& studentai){
    Studentas* studentaiTemp = nullptr;
    bool loop = true;
    int m = 0;
    int n = 0;
    while(loop){
        cout << "Pasirinkite įvedimo būdą:" << endl
        << "(1) Duomenų įvedimas ranka" << endl
        << "(2) Generuoti pažymius" << endl
        << "(3) Generuoti vardą, pavardę ir pažymius" << endl
        << "(4) Baigti darbą" << endl;

        int cInput = intIvestis();

        if(cInput == 1){
            n = 0;
            
            studentaiTemp = new Studentas[m];
            for(int i = 0; i < m; i++){
                studentaiTemp[i] = studentai[i];
            }
            delete[] studentai;
            studentai = new Studentas[m + 1];
            for(int i = 0; i < m; i++){
                studentai[i] = studentaiTemp[i];
            }
            delete[] studentaiTemp;

            bool ndLoop = true;

            cout << "Įveskite studento vardą: ";
            studentai[m].vardas = stringIvestis();
            cout<<studentai[m].vardas;
            cout << "Įveskite studento pavardę: ";
            studentai[m].pavarde = stringIvestis();
            cout << "Įveskite studento namų darbų pažymius (0 - pereiti prie egzamino pažymio įvesties): ";

            int* ndTemp = nullptr;
            int* ndFin = new int[n+1];
            
            while(ndLoop){
                ndTemp = new int[n];
                for(int i = 0; i < n; i++){
                    ndTemp[i] = ndFin[i];
                    cout<<ndTemp[i]<<" ";
                }
                delete[] ndFin;
                ndFin = new int[n+1];
                for(int i = 0; i < n; i++){
                    ndFin[i] = ndTemp[i];
                }
                delete[] ndTemp;

                int temp = intIvestis();
                if(temp != 0){
                    ndFin[n] = temp;
                    n++;
                } else {
                    cout << "Įveskite studento egzamino pažymį: ";
                    studentai[m].egz = intIvestis();
                    studentai[m].n = n+1;
                    studentai[m].nd = ndFin;

                    for(int i = 0; i < n; i++){
                        studentai[m].vid += studentai[m].nd[i];
                    }
                    studentai[m].vid /= n;

                    for(int i = 0; i < n-1; i++){
                        for(int j = i+1; j < n; j++){
                            if(studentai[m].nd[i] < studentai[m].nd[j]){
                                temp = studentai[m].nd[i];
                                studentai[m].nd[i] = studentai[m].nd[j];
                                studentai[m].nd[j] = temp;
                            }
                        }
                    }

                    if(n % 2 == 0){
                        studentai[m].mediana = (studentai[m].nd[n/2] + studentai[m].nd[n/2 + 1]) / 2;
                    } else {
                        studentai[m].mediana = studentai[m].nd[n/2 + 1];
                    }

                    ndLoop = false;
                }
            }
            m++;
        } else if(cInput == 2){
            n = 0;
            studentaiTemp = new Studentas[m];
            for(int i = 0; i < m; i++){
                studentaiTemp[i] = studentai[i];
            }
            delete[] studentai;
            studentai = new Studentas[m + 1];
            for(int i = 0; i < m; i++){
                studentai[i] = studentaiTemp[i];
            }
            delete[] studentaiTemp;

            cout << "(2)Įveskite studento vardą: ";
            studentai[m].vardas = stringIvestis();
            cout << "Įveskite studento pavardę: ";
            studentai[m].pavarde = stringIvestis();

            n = randGen(1, 10);
            studentai[m].n = n;
            int* ndTemp = new int[n];
            for(int i = 0; i < n; i++){
                ndTemp[i] = randGen(1, 10);
            }
            studentai[m].nd = ndTemp;
            studentai[m].egz = randGen(1, 10);
            m++;
        } else if(cInput == 3){
            n = 0;
            studentaiTemp = new Studentas[m];
            for(int i = 0; i < m; i++){
                studentaiTemp[i] = studentai[i];
            }
            delete[] studentai;
            studentai = new Studentas[m + 1];
            for(int i = 0; i < m; i++){
                studentai[i] = studentaiTemp[i];
            }
            delete[] studentaiTemp;

            string vardai[7] = {"Rokas", "Karolis", "Nojus", "Edgaras", "Martynas", "Gytis", "Justas"};
            string pavardes[7] = {"Kazlauskas", "Stankevičius", "Petrauskas", "Jankauskas", "Žukauskas", "Butkus", "Balčiūnas"};

            studentai[m].vardas = vardai[randGen(0, 6)];
            studentai[m].pavarde = pavardes[randGen(0, 6)];

            n = randGen(1, 10);
            studentai[m].n = n;
            int* ndTemp = new int[n];
            for(int i = 0; i < n; i++){
                ndTemp[i] = randGen(1, 10);
            }
            studentai[m].nd = ndTemp;
            studentai[m].egz = randGen(1, 10);

            // for(int i = 0; i <= m; i++){
            //     cout << studentai[i].vardas << " " << studentai[i].pavarde << " (" << studentai[i].n << ") ";
            //     for(int j = 0; j < n; j++){
            //         cout<<studentai[i].nd[j] << " ";
            //     }
            //     cout<<endl;
            // }

            m++;
        } else if(cInput == 4){
            cout << "Pasirinkite skaičiavimo būdą: " << endl
                << "(1) Pagal pažymių vidurkį" << endl
                << "(2) Pagal pažymių medianą" << endl;

            cin >> cInput;

            if(cInput == 1){
                atvaizd(studentai, 0, m);
                break;
            } else if(cInput == 2){
                atvaizd(studentai, 1, m);
                break;
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
                loop = true;
            }
        }
        if(loop){
            cout << "Klaida. Bandykite dar kartą: ";
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
        if(cInput < 0 || cInput > 10 || !cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                loop = true;
        }
        for(char a : to_string(cInput)){
            if(isblank(a)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                loop = true;
            }
        }
        if(loop){
            cout << "Klaida. Bandykite dar kartą: ";
        }
    }while(loop);

    return cInput;
}

int randGen(int sRange, int eRange){
    int r = rand() % eRange + sRange;

    return r;
}

void atvaizd(Studentas*& studentai, int skaiciavimas, int m){
    if(skaiciavimas == 0) {
        cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavardė" << left << setw(16) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------------" << m << endl;
        for(int i = 0; i < m; i++){
            cout << left << setw(15) << studentai[i].vardas
                << left << setw(16) << studentai[i].pavarde
                << setprecision(2) << fixed << left << setw(16) << studentai[i].vid * 0.4 + double(studentai[i].egz) * 0.6 << endl;
        }
    } else {
        cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavardė" << left << setw(16) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------------" << endl;
        for(int i = 0; i < m; i++){
            cout << left << setw(15) << studentai[i].vardas
                << left << setw(16) << studentai[i].pavarde
                << setprecision(2) << fixed << left << setw(16) << studentai[i].mediana * 0.4 + double(studentai[i].egz) * 0.6 << endl;
        }
    }
}
