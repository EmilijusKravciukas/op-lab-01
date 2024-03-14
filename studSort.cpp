#include "studSort.h"

#define OPENING_ERROR "Nepavyko atidaryti failo"
#define WRITING_ERROR "Nepavyko irasyti duomenu i faila"

void studSort(vector<Studentas>& studentai, unsigned int m){
    sort(studentai.begin(), studentai.end(), rikiavimasPaz);

    for(Studentas studentas : studentai){
        cout<<studentas.vardas<<" "<<studentas.pavarde<<" "<<(studentas.vid*0.4 + double(studentas.egz*0.6))<<endl;
    }

    vector<Studentas> studentaiTemp;

    // for(int i = 0; i < m; i++){
    //     if((studentai[i].vid * 0.4 + double(studentai[i].egz * 0.6)) < 5){
    //         for(int j = i; j < m; j++){
    //             studentaiTemp.push_back(studentai[j]);
    //             studentai.erase(studentai.begin() + j);
    //             cout << studentaiTemp[i].vardas << " " << studentaiTemp[i].pavarde << endl;
    //         }
    //     }
    // }

    // ofstream LF("lopai.txt");

    // LF << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis paz." << endl;

    // for (Studentas studentas : studentai){
    //     LF << left << setw(20) << studentas.vardas << left << setw(20) << studentas.pavarde << left << setw(20) << studentas.vid * 0.4 + studentas.egz * 0.6 << endl;
    //     //cout << left << setw(20) << studentas.vardas << left << setw(20) << studentas.pavarde << left << setw(20) << studentas.vid * 0.4 + studentas.egz * 0.6 << endl;
    // }

    // LF.close();

    try{
        ofstream LF("lopai.txt");

        if(!LF.is_open()){
            throw runtime_error(OPENING_ERROR);
        }

        if(!(LF << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis paz." << endl)){
            throw runtime_error(WRITING_ERROR);
        }

        for (Studentas studentas : studentai){
            if(!(LF << left << setw(20) << studentas.vardas << left << setw(20) << studentas.pavarde << left << setw(20) << (studentas.vid * 0.4 + studentas.egz * 0.6) << endl)){
                throw runtime_error(WRITING_ERROR);
            }
        }
    } catch(runtime_error& e){
        cout << e.what() << endl;
    }


    ofstream MF("malaciai.txt");

    MF << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis paz." << endl;

    for (Studentas studentas : studentaiTemp){
        MF << left << setw(20) << studentas.vardas << left << setw(20) << studentas.pavarde << left << setw(20) << (studentas.vid * 0.4 + studentas.egz * 0.6) << endl;
    }

    MF.close();
}
