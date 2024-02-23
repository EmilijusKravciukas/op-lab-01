#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <random>
#include <locale>
#include <time.h>
#include <vector>

using namespace std;

struct Studentas{
        string vardas;
        string pavarde;
        int n;
        vector<int> nd;
        int egz;
        double vid = 0;
        double mediana;
};

void duomSkait(vector<Studentas>& studentai);
void ivestis(vector<Studentas>& studentai);
void atvaizd(vector<Studentas>& studentai, int m);
string stringIvestis();
int intIvestis(int sRange, int eRange);
int randGen(int sRange, int eRange);
double rastiVid(vector<Studentas>& studentai, int m);
double rastiMed(vector<Studentas>& studentai, int m);

int main(){
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

    ifstream DF(duomPav);

    string tempString;
    int tempInt;
    unsigned int m = 0;

    do{
        DF >> tempString;
    }while(tempString != "Egz.");

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

    atvaizd(studentai, m);
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
            studentai.resize(m+1);
            bool ndLoop = true;

            cout << "Įveskite studento vardą: ";
            studentai[m].vardas = stringIvestis();
            cout<<studentai[m].vardas;
            cout << "Įveskite studento pavardę: ";
            studentai[m].pavarde = stringIvestis();
            cout << "Įveskite studento namų darbų pažymius (0 - pereiti prie egzamino pažymio įvesties): ";
            while(ndLoop){
                int temp = intIvestis(0, 10);
                if(temp != 0){
                    studentai[m].nd.push_back(temp);
                    n++;
                } else {
                    cout << "Įveskite studento egzamino pažymį: ";
                    studentai[m].egz = intIvestis(0, 10);
                    studentai[m].n = n+1;
                    studentai[m].vid = rastiVid(studentai, m);
                    studentai[m].mediana = rastiMed(studentai, m);

                    ndLoop = false;
                }
            }
            m++;
        } else if(cInput == 2){
            n = 0;
            studentai.resize(m+1);


            cout << "Įveskite studento vardą: ";
            studentai[m].vardas = stringIvestis();
            cout << "Įveskite studento pavardę: ";
            studentai[m].pavarde = stringIvestis();

            n = randGen(1, 10);
            studentai[m].n = n;
            for(int i = 0; i < n; i++){
                studentai[m].nd.push_back(randGen(1, 10));
            }

            studentai[m].egz = randGen(1, 10);
            studentai[m].n = n;
            studentai[m].vid = rastiVid(studentai, m);
            studentai[m].mediana = rastiMed(studentai, m);

            m++;
        } else if(cInput == 3){
            n = 0;
            studentai.resize(m+1);

            vector<string> vardai = {"Rokas", "Karolis", "Nojus", "Edgaras", "Martynas", "Gytis", "Justas"};
            vector<string> pavardes = {"Kazlauskas", "Stankevičius", "Petrauskas", "Jankauskas", "Žukauskas", "Butkus", "Balčiūnas"};

            studentai[m].vardas = vardai[randGen(0, 6)];
            studentai[m].pavarde = pavardes[randGen(0, 6)];

            n = randGen(1, 10);
            studentai[m].n = n;
            for(int i = 0; i < n; i++){
                studentai[m].nd.push_back(randGen(1, 10));
            }

            studentai[m].egz = randGen(1, 10);
            studentai[m].n = n;
            studentai[m].vid = rastiVid(studentai, m);
            studentai[m].mediana = rastiMed(studentai, m);

            m++;
        } else if(cInput == 4){
            atvaizd(studentai, m);
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

double rastiVid(vector<Studentas>& studentai, int m){
    for(int i = 0; i < studentai[m].n; i++){
        studentai[m].vid += studentai[m].nd[i];
    }
    studentai[m].vid /= studentai[m].n;

    return studentai[m].vid;
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

void atvaizd(vector<Studentas>& studentai, int m){
    cout << left << setw(16) << "Vardas" << left << setw(16) << "Pavardė" << left << setw(16) << "Galutinis (Vid.)" << endl;
    cout << "---------------------------------------------------------------------------" << m << endl;
    for(int i = 0; i < m; i++){
        cout << left << setw(15) << studentai[i].vardas
            << left << setw(16) << studentai[i].pavarde
            << setprecision(2) << fixed << left << setw(16) << studentai[i].vid * 0.4 + double(studentai[i].egz) * 0.6
            << setprecision(2) << fixed << left << setw(16) << studentai[i].mediana * 0.4 + double(studentai[i].egz) * 0.6 << endl;
    }
}
