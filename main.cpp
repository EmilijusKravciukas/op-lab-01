#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Studentas{
        string vardas;
        string pavarde;
        int n;
        double nd;
        int egz;
        double mediana;
};

int m;

void duomSkait(Studentas*& studentai);
void atvaizd(Studentas*& studentai, int skaiciavimas);

int main(){
    int skaiciavimas = 0; //0 - vid, 1 - med

    ifstream DF("data.txt");
    DF >> m;
    DF.close();

    Studentas* studentai{new Studentas[m]{}};


    duomSkait(studentai);
    atvaizd(studentai, skaiciavimas);


    return 0;
}


void duomSkait(Studentas*& studentai){
    ifstream DF("data.txt");

    DF >> m;

    for(int i = 0; i < m; i++){
        DF >> studentai[i].vardas;
        DF >> studentai[i].pavarde;
        DF >> studentai[i].n;
        int temp = 0;
        int* medianaMas{new int[studentai[i].n]{}};
        for(int j = 0; j < studentai[i].n; j++){
            DF>>temp;
            studentai[i].nd += temp;
            medianaMas[j] = temp;
        }
        studentai[i].nd /= studentai[i].n;
        for(int j = 0; j < studentai[i].n-1; j++){
            for(int z = j+1; z < studentai[i].n; z++){
                if(medianaMas[j] < medianaMas[z]){
                    temp = medianaMas[j];
                    medianaMas[j] = medianaMas[z];
                    medianaMas[z] = temp;
                }
            }
        }
        if(studentai[i].n % 2 == 0){
            studentai[i].mediana = (medianaMas[studentai[i].n/2] + medianaMas[studentai[i].n/2 + 1]) / 2;
        } else {
            studentai[i].mediana = medianaMas[studentai[i].n/2 + 1];
        }
        DF>>studentai[i].egz;
    }

    DF.close();
}

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
