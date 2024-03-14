#include "studSort.h"

// bool rikiavimasPaz(Studentas& s1, Studentas& s2){
//     return (s1.vid * 0.4 + s1.egz * 0.6) > (s2.vid * 0.4 + s2.egz * 0.6);
// }

void studSort(vector<Studentas>& studentai, unsigned int m){
    sort(studentai.begin(), studentai.end(), rikiavimasPaz);

    vector<Studentas> studentaiTemp;

    for(int i = 0; i < m; i++){
        if((studentai[i].vid * 0.4 + studentai[i].egz * 0.6) < 5){
            for(int j = i; j < m; j++){
                studentaiTemp.push_back(studentai[j]);
                studentai.erase(studentai.begin() + j);
            }
        }
    }

    ofstream LF("lopai.txt");

    LF << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis paz." << endl;

    for (Studentas studentas : studentai){
        LF << left << setw(20) << studentas.vardas << left << setw(20) << studentas.pavarde << left << setw(20) << studentas.vid * 0.4 + studentas.egz * 0.6 << endl;
        cout << left << setw(20) << studentas.vardas << left << setw(20) << studentas.pavarde << left << setw(20) << studentas.vid * 0.4 + studentas.egz * 0.6 << endl;
    }

    LF.close();


    ofstream MF("malaciai.txt");

    MF << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis paz." << endl;

    for (Studentas studentas : studentaiTemp){
        LF << left << setw(20) << studentas.vardas << left << setw(20) << studentas.pavarde << left << setw(20) << studentas.vid * 0.4 + studentas.egz * 0.6 << endl;
    }

    MF.close();
}