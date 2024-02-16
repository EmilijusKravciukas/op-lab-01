#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <random>

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
void atvaizd(Studentas*& studentai, int skaiciavimas);
string stringIvestis();
int intIvestis();
int randGen();

int main(){
    srand(time(nullptr));
    int skaiciavimas = 0; //0 - vid, 1 - med

    Studentas* studentai = nullptr;

    ivestis(studentai);

    return 0;
}

void ivestis(Studentas*& studentai){
    bool loop = true;
    char cInput = ' ';
    int m = 0;
    int n = 0;
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
                n = 0;
                Studentas* studentaiTemp = new Studentas[m];
                for(int i = 0; i < m; i++){
                    studentaiTemp[i] = studentai[i];
                }
                delete[] studentai;
                Studentas* studentai = new Studentas[m + 1];
                for(int i = 0; i < m; i++){
                    studentai[i] = studentaiTemp[i];
                }
                delete[] studentaiTemp;

                bool ndLoop = true;

                cout << "Įveskite studento vardą: ";
                studentai[m].vardas = stringIvestis();
                cout << "Įveskite studento pavardę: ";
                studentai[m].pavarde = stringIvestis();
                cout << "Įveskite studento namų darbų pažymius (0 - pereiti prie egzamino pažymio įvesties): ";

                int* ndFin = new int[n];
                
                while(ndLoop){
                    int* ndTemp = new int[n];
                    for(int i = 0; i < n; i++){
                        ndTemp[i] = ndFin[i];
                    }
                    delete[] ndFin;
                    int* ndFin = new int[n];
                    for(int i; i < n; i++){
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
                        studentai[m].n = n;
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

                        if(n )

                        ndLoop = false;
                    }
                }
            } else if(cInput = '2'){
                n = 0;
                Studentas* studentaiTemp = new Studentas[m];
                for(int i = 0; i < m; i++){
                    studentaiTemp[i] = studentai[i];
                }
                delete[] studentai;
                Studentas* studentai = new Studentas[m + 1];
                for(int i = 0; i < m; i++){
                    studentai[i] = studentaiTemp[i];
                }
                delete[] studentaiTemp;

                cout << "Įveskite studento vardą: ";
                studentai[m].vardas = stringIvestis();
                cout << "Įveskite studento pavardę: ";
                studentai[m].pavarde = stringIvestis();

                n = randGen(1, 10);
                for(int i = 0; i < n; i++){
                    studentai[m].nd[i] = randGen(1, 10);
                }
                studentai[m].egz = randGen(1, 10);
            } else if(cInput == '3'){
                n = 0;
                Studentas* studentaiTemp = new Studentas[m];
                for(int i = 0; i < m; i++){
                    studentaiTemp[i] = studentai[i];
                }
                delete[] studentai;
                Studentas* studentai = new Studentas[m + 1];
                for(int i = 0; i < m; i++){
                    studentai[i] = studentaiTemp[i];
                }
                delete[] studentaiTemp;

                string vardai[7] = {"Rokas", "Karolis", "Nojus", "Edgaras", "Martynas", "Gytis", "Justas"};
                string pavardes[7] = {"Kazlauskas", "Stankevičius", "Petrauskas", "Jankauskas", "Žukauskas", "Butkus", "Balčiūnas"};

                studentai[m].vardas = vardai[randGen(0, 6)];
                studentai[m].pavarde = pavardes[randGen(0, 6)];
            } else if(cInput == '4'){
                cout << "Pasirinkite skaičiavimo būdą: " << endl
                    << "(1) Pagal pažymių vidurkį" << endl
                    << "(2) Pagal pažymių medianą" << endl;

                cin >> cInput;

                if(cInput == '1'){
                    atvaizd(studentai, 0);
                } else if(cInput == '2'){
                    atvaizd(studentai, 1);
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

int randGen(int sRange, int eRange){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(sRange, eRange);

    return distr(gen);
}

void atvaizd(Studentas*& studentai, int skaiciavimas, int m){
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
