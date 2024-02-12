#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    struct Studentas{
        string vardas;
        string pavarde;
        int n;
        double nd;
        int egz;
    };

    ifstream DF("data.txt");

    int N;
    DF >> N;

    Studentas studentai[N];

    for(int i = 0; i < N; i++){
        DF >> studentai[i].vardas;
        DF >> studentai[i].pavarde;
        DF >> studentai[i].n;
        int temp = 0;
        for(int j = 0; j < studentai[i].n; j++){
            DF>>temp;
            studentai[i].nd += temp;
        }
        studentai[i].nd /= studentai[i].n;
        DF>>studentai[i].egz;
    }

    cout << left << setw(16) << "Pavardė" << left << setw(16) << "Vardas" << left << setw(16) << "Galutinis (Vid.)" << endl;
    cout << "--------------------------------------------------------" << endl;
    for(int i = 0; i < N; i++){
        cout << left << setw(15) << studentai[i].vardas
            << left << setw(16) << studentai[i].pavarde
            << setprecision(2) << fixed << left << setw(16) << studentai[i].nd * 0.4 + double(studentai[i].egz) * 0.6 << endl;
    }

    DF.close();
  
    return 0;
}
