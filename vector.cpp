#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <random>
#include <locale.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Studentas{
        wstring vardas;
        wstring pavarde;
        int n;
        vector<int> nd;
        int egz;
        double vid = 0;
        double mediana;
};

void duomSkait(vector<Studentas>& studentai);
void ivestis(vector<Studentas>& studentai);
void atvaizd(vector<Studentas>& studentai, int m, int rikiavimas);
wstring stringIvestis();
int intIvestis(int sRange, int eRange);
int randGen(int sRange, int eRange);
double rastiVid(Studentas studentasTemp);
double rastiMed(Studentas studentasTemp);

double rastiVid(vector<Studentas>& studentai, int m);
double rastiMed(vector<Studentas>& studentai, int m);

int main(){
    locale::global(locale("en_US"));

    srand(time(0));
    system("chcp 65001  > nul");

    cout<<"Pasirinkite įvedimo būdą: " << endl
        << "(1) Rankinis įvedimo būdas" << endl
        << "(2) Skaitymas iš failo" << endl;

    int cInput = intIvestis(1, 2);

    vector<Studentas> studentai;

    if(cInput == 1){
        ivestis(studentai);
    } else if(cInput == 2){
        duomSkait(studentai);
    }

    return 0;
}

void duomSkait(vector<Studentas>& studentai){
    system("dir *.txt");
    cout<<"Pasirinkite duomenų failą: ";

    string duomPav;

    cin >> duomPav;

    wifstream DF(duomPav);

    wstring tempString;
    int tempInt;
    unsigned int m = 0;

    do{
        DF >> tempString;
    }while(tempString != L"Egz.");

    while(DF.peek() != EOF){
        studentai.resize(m+1);
        DF >> studentai[m].vardas;
        DF >> studentai[m].pavarde;

        int n = 0;

        while(DF.peek() != '\n' && DF.peek() != EOF){
            DF >> tempInt;
            n++;
            studentai[m].nd.push_back(tempInt);
        }

        studentai[m].egz = studentai[m].nd[n-1];
        studentai[m].nd.pop_back();
        studentai[m].n = n;
        studentai[m].vid = rastiVid(studentai, m);
        studentai[m].mediana = rastiMed(studentai, m);

        m++;
    }

    cout<<"Pasirinkite rikiavimo būdą: " << endl
        <<"(1) Pagal studento vardą" << endl
        <<"(2) Pagal studento pavarde" << endl
        <<"(3) Pagal studento galutinį pažymį" << endl;

    atvaizd(studentai, m, intIvestis(1, 3));
}

void ivestis(vector<Studentas>& studentai){
    bool loop = true;
    unsigned int m = 0;
    unsigned int n = 0;
    while(loop){
        cout << "Pasirinkite įvedimo būdą:" << endl
        << "(1) Duomenų įvedimas ranka" << endl
        << "(2) Generuoti pažymius" << endl
        << "(3) Generuoti vardą, pavardę ir pažymius" << endl
        << "(4) Baigti darbą" << endl;

        int cInput = intIvestis(0, 10);

        if(cInput == 1){
            n = 0;

            Studentas studentasTemp;

            bool ndLoop = true;

            cout << "Įveskite studento vardą: ";
            studentasTemp.vardas = stringIvestis();
            cout << "Įveskite studento pavardę: ";
            studentasTemp.pavarde = stringIvestis();
            cout << "Įveskite studento namų darbų pažymius (0 - pereiti prie egzamino pažymio įvesties): ";
            while(ndLoop){
                int temp = intIvestis(0, 10);
                if(temp != 0){
                    studentasTemp.nd.push_back(temp);
                    n++;
                } else {
                    cout << "Įveskite studento egzamino pažymį: ";
                    studentasTemp.egz = intIvestis(1, 10);
                    studentasTemp.n = n;
                    studentasTemp.vid = rastiVid(studentasTemp);
                    studentasTemp.mediana = rastiMed(studentasTemp);

                    ndLoop = false;
                }
            }
            
            studentai.push_back(studentasTemp);

            m++;
        } else if(cInput == 2){
            n = 0;

            Studentas studentasTemp;

            cout << "Įveskite studento vardą: ";
            studentai[m].vardas = stringIvestis();
            cout << "Įveskite studento pavardę: ";
            studentai[m].pavarde = stringIvestis();

            n = randGen(1, 10);
            studentasTemp.n = n;
            for(int i = 0; i < n; i++){
                studentasTemp.nd.push_back(randGen(1, 10));
            }

            studentasTemp.egz = randGen(1, 10);
            studentasTemp.n = n;
            studentasTemp.vid = rastiVid(studentasTemp);
            studentasTemp.mediana = rastiMed(studentasTemp);

            studentai.push_back(studentasTemp);

            m++;
        } else if(cInput == 3){
            n = 0;
            
            Studentas studentasTemp;

            vector<wstring> vardai = {L"Rokas", L"Karolis", L"Nojus", L"Edgaras", L"Martynas", L"Gytis", L"Justas"};
            vector<wstring> pavardes = {L"Kazlauskas", L"Stankevičius", L"Petrauskas", L"Jankauskas", L"Žukauskas", L"Butkus", L"Balčiūnas"};

            studentasTemp.vardas = vardai[randGen(0, 6)];
            studentasTemp.pavarde = pavardes[randGen(0, 6)];

            n = randGen(1, 10);
            studentasTemp.n = n;
            for(int i = 0; i < n; i++){
                studentasTemp.nd.push_back(randGen(1, 10));
            }

            studentasTemp.egz = randGen(1, 10);
            studentasTemp.n = n;
            studentasTemp.vid = rastiVid(studentasTemp);
            studentasTemp.mediana = rastiMed(studentasTemp);

            studentai.push_back(studentasTemp);

            m++;
        } else if(cInput == 4){
            cout<<"Pasirinkite rikiavimo būdą: " << endl
                <<"(1) Pagal studento vardą" << endl
                <<"(2) Pagal studento pavarde" << endl
                <<"(3) Pagal studento galutinį pažymį" << endl;

                atvaizd(studentai, m, intIvestis(1, 3));
        }
    }
}

wstring stringIvestis(){
    wstring cInput;
    bool loop = false;

    do{
        loop = false;
        wcin >> cInput;
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

int intIvestis(int sRange, int eRange){
    int cInput;
    bool loop = false;

    do{
        loop = false;
        cin >> cInput;
        if(cInput < sRange || cInput > eRange || !cin){
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

double rastiVid(Studentas studentasTemp){
    for(int i = 0; i < studentasTemp.n; i++){
        studentasTemp.vid += studentasTemp.nd[i];
    }
    studentasTemp.vid /= studentasTemp.n;

    return studentasTemp.vid;
}

double rastiVid(vector<Studentas>& studentai, int m){
    for(int i = 0; i < studentai[m].n; i++){
        studentai[m].vid += studentai[m].nd[i];
    }
    studentai[m].vid /= studentai[m].n;

    return studentai[m].vid;
}

double rastiMed(Studentas studentasTemp){
    for(int i = 0; i < studentasTemp.n; i++){
        for(int j = i+1; j < studentasTemp.n; j++){
            if(studentasTemp.nd[i] < studentasTemp.nd[j]){
                int temp = studentasTemp.nd[i];
                studentasTemp.nd[i] = studentasTemp.nd[j];
                studentasTemp.nd[j] = temp;
            }
        }
    }

    if(studentasTemp.n % 2 == 0){
        studentasTemp.mediana = double(studentasTemp.nd[studentasTemp.n/2 - 1] + studentasTemp.nd[studentasTemp.n/2]) / 2;
    } else {
        studentasTemp.mediana = studentasTemp.nd[studentasTemp.n/2];
    }

    return studentasTemp.mediana;
}

double rastiMed(vector<Studentas>& studentai, int m){
    for(int i = 0; i < studentai[m].n; i++){
        for(int j = i+1; j < studentai[m].n; j++){
            if(studentai[m].nd[i] < studentai[m].nd[j]){
                int temp = studentai[m].nd[i];
                studentai[m].nd[i] = studentai[m].nd[j];
                studentai[m].nd[j] = temp;
            }
        }
    }

    if(studentai[m].n % 2 == 0){
        studentai[m].mediana = (studentai[m].nd[studentai[m].n/2] + studentai[m].nd[studentai[m].n/2 + 1]) / 2;
    } else {
        studentai[m].mediana = studentai[m].nd[studentai[m].n/2 + 1];
    }

    return studentai[m].mediana;
}

bool rikiavimasVardu(Studentas& s1, Studentas& s2){
    return s1.vardas < s2.vardas;
}

bool rikiavimasPavarde(Studentas& s1, Studentas& s2){
    return s1.pavarde < s2.pavarde;
}

bool rikiavimasPaz(Studentas& s1, Studentas& s2){
    return (s1.vid * 0.4 + s1.egz * 0.6) > (s2.vid * 0.4 + s2.egz * 0.6);
}

void atvaizd(vector<Studentas>& studentai, int m, int rikiavimas){
    if(rikiavimas == 1){
        sort(studentai.begin(), studentai.end(), rikiavimasVardu);
    } else if(rikiavimas == 2){
        sort(studentai.begin(), studentai.end(), rikiavimasPavarde);
    } else if(rikiavimas == 3){
        sort(studentai.begin(), studentai.end(), rikiavimasPaz);
    }

    cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė" << left << setw(20) << "Galutinis (Vid.)" << left << setw(20) << "Galutinis (Med.)" << endl;
    cout << "---------------------------------------------------------------------------" << m << endl;
    cout << setprecision(2) << fixed;
    for(int i = 0; i < m; i++){
        wcout << left << setw(20) << studentai[i].vardas
            << left << setw(20) << studentai[i].pavarde
            << left << setw(20) << studentai[i].vid * 0.4 + double(studentai[i].egz) * 0.6
            << left << setw(20) << studentai[i].mediana * 0.4 + double(studentai[i].egz) * 0.6 << " ";
            for(int j= 0; j < studentai[i].n; j++) {
                cout << studentai[i].nd[j] << " ";
            }
            cout<<"| "<<studentai[i].egz<<endl;
    }
}
