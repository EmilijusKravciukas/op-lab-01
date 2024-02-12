#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    struct Studentas{
        string vardas;
        string pavarde;
        int n;
        int egz;
        int nd[];
    };

    ifstream DF("data.txt");

    int mInput;
    char medianaUI = '0'; // 0 - rodo vidurki, 1 - rodo mediana
    // cout << "Pasirinkite, rodyti pažymio vidurkį(0) ar mediana(1):";
    // cin >> medianaUI;
    DF >> mInput;
    
    const int m = mInput;

    Studentas studentai[m];

    for(int i = 0; i < m; i++){
        DF >> studentai[i].vardas;
        DF >> studentai[i].pavarde;
        DF >> studentai[i].n;
        int temp = 0;
        for(int j = 0; j < studentai[i].n; j++){
            DF>>temp;
            studentai[i].nd[j] = temp;
        }
        DF>>studentai[i].egz;
    }

    if(medianaUI == '0'){
        cout << left << setw(16) << "Pavardė" << left << setw(16) << "Vardas" << left << setw(16) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------------" << endl;
        for(int i = 0; i < m; i++){
            double vid = 0;
            for(int j = 0; j < studentai[i].n; j++){
                vid += studentai[i].nd[j];
            }
            vid /= studentai[i].n;
            
            cout << left << setw(15) << studentai[i].vardas
                << left << setw(16) << studentai[i].pavarde
                << setprecision(2) << fixed << left << setw(16) << vid * 0.4 + double(studentai[i].egz) * 0.6 << endl;
        }
    } else {
        cout << left << setw(16) << "Pavardė" << left << setw(16) << "Vardas" << left << setw(16) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------------" << endl;
        for(int i = 0; i < m; i++){
            double med = 0;
            int temp = 0;
            for(int j = 0; j < studentai[i].n-1; j++){
                for(int z = j+1; z < studentai[i].n; z++){
                    if(studentai[i].nd[j] < studentai[i].nd[z]){
                        temp = studentai[i].nd[j];
                        studentai[i].nd[j] = studentai[i].nd[z];
                        studentai[i].nd[z] = temp;
                    }
                }
            }
            
            if(m % 2 == 0){
                cout << left << setw(15) << studentai[i].vardas
                << left << setw(16) << studentai[i].pavarde
                << setprecision(2) << fixed << left << setw(16) << (studentai[i].nd[m/2] + studentai[i].nd[m/2 + 1]) / 2 * 0.4 + double(studentai[i].egz) * 0.6 << endl;
            } else {
                cout << left << setw(15) << studentai[i].vardas
                << left << setw(16) << studentai[i].pavarde
                << setprecision(2) << fixed << left << setw(16) << studentai[i].nd[m/2 + 1] * 0.4 + double(studentai[i].egz) * 0.6 << endl;
            }
        }
    }
    

    DF.close();
  
    return 0;
}
