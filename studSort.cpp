#include "studSort.h"

#define OPENING_ERROR "Nepavyko atidaryti failo"
#define WRITING_ERROR "Nepavyko irasyti duomenu i faila"

void studSort(vector<Studentas>& studentai, unsigned int m, int rikiavimas){
    sort(studentai.begin(), studentai.end(), rikiavimasPaz);

    vector<Studentas> studentaiTemp;

    const double epsilon = 1e-9;

    for(int i = 0; i < m; i++){
        if((studentai[i].vid * 0.4 + double(studentai[i].egz) * 0.6) < 5.0 - epsilon){
            for(int j = i; j < m; j++){
                studentaiTemp.push_back(studentai[j]);
            }
            studentai.erase(studentai.begin() + i, studentai.end());
            break;
        }
    }

    if(rikiavimas == 1){
        sort(studentai.begin(), studentai.end(), rikiavimasVardu);
        sort(studentaiTemp.begin(), studentaiTemp.end(), rikiavimasVardu);
    } else if(rikiavimas == 2){
        sort(studentai.begin(), studentai.end(), rikiavimasPavarde);
        sort(studentaiTemp.begin(), studentaiTemp.end(), rikiavimasPavarde);
    }

    try{
        ofstream LF("lopai.txt");

        if(!LF.is_open()){
            throw runtime_error(OPENING_ERROR);
        }

        if(!(LF << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis paz.")){
            throw runtime_error(WRITING_ERROR);
        }

        for (Studentas studentas : studentaiTemp){
            if(!(LF << endl << left << setw(20) << studentas.vardas << left << setw(20) << studentas.pavarde << fixed << setprecision(2) << left << setw(20) << (studentas.vid * 0.4 + double(studentas.egz) * 0.6))){
                throw runtime_error(WRITING_ERROR);
            }
        }
    } catch(runtime_error& e){
        cout << e.what() << endl;
    }

    try{
        ofstream MF("malaciai.txt");

        if(!MF.is_open()){
            throw runtime_error(OPENING_ERROR);
        }

        if(!(MF << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis paz.")){
            throw runtime_error(WRITING_ERROR);
        }
        
        for (Studentas studentas : studentai){
            if(!(MF << endl << left << setw(20) << studentas.vardas << left << setw(20) << studentas.pavarde << fixed << setprecision(2) << left << setw(20) << (studentas.vid * 0.4 + double(studentas.egz) * 0.6))){
                throw runtime_error(WRITING_ERROR);
            }
        }

        MF.close();
    } catch(runtime_error& e){
        cout << e.what() << endl;
    }
}
