#include "fileGen.h"

void generateFile(){
    cout << "Iveskite failo pavadinima: ";
    string fileName = stringIvestis();

    cout << "Iveskite studentu kieki: ";
    unsigned int stNum = intIvestis(0, INT32_MAX);

    cout << "Iveskite pazymiu kieki: ";
    unsigned int pazNum = intIvestis(0, INT32_MAX);

    ofstream OF(fileName);

    OF << left << setw(25) << "Vardas" << left << setw(25) << "Pavarde";
    for(int i = 0; i < pazNum; i++){
        OF << left << setw(10) << "ND" + to_string(i + 1);
    }
    OF << left << setw(10) << "Egz." << endl;
    for(int i = 0; i < stNum; i++){
        OF << left << setw(25) << "Vardas" + to_string(i + 1) << left << setw(25) << "Pavarde" + to_string(i + 1);
        for(int j = 0; j <= pazNum; j++){
            OF << left << setw(10) << randGen(1, 10);
        }
        OF << endl;
    }

    OF.close();
}
