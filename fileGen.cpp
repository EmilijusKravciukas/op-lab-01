#include "fileGen.h"

#define WRITING_ERROR "Nepavyko irasyti duomenu i faila"

void generateFile(){
    cout << "Iveskite failo pavadinima: ";
    string fileName = fileIvestis();

    cout << "Iveskite studentu kieki: ";
    unsigned int stNum = intIvestis(0, INT32_MAX);

    cout << "Iveskite pazymiu kieki: ";
    unsigned int pazNum = intIvestis(0, INT32_MAX);

    try{
        auto tStart = chrono::steady_clock::now();

        ofstream OF(fileName);

        if(!OF.is_open()){
            throw runtime_error("Nepavyko atidaryti failo");
        }
        if(!(OF << setw(16) << left << "Vardas" << setw(16) << right << "Pavarde")){
            throw runtime_error(WRITING_ERROR);
        }
        for(int i = 0; i < pazNum; i++){
            string output = "ND" + to_string(i + 1);
            if(i == 0){
                if(!(OF << setw(23) << right << output)){
                    throw runtime_error(WRITING_ERROR);
                }
            }else if(!(OF << setw(10) << right << output)){
                throw runtime_error(WRITING_ERROR);
            }
        }
        if(!(OF << setw(10) << right << "Egz." << endl)){
            throw runtime_error(WRITING_ERROR);
        }
        for(int i = 0; i < stNum; i++){
            string outputVardas = "Vardas" + to_string(i + 1);
            string outputPavarde = "Pavarde" + to_string(i + 1);
            if(!(OF << setw(16) << left << outputVardas << setw(16) << right << outputPavarde)){
                throw runtime_error(WRITING_ERROR);
            }
            for(int j = 0; j <= pazNum; j++){
                if(j == 0){
                    if(!(OF << setw(23) << right << randGen(1, 10))){
                        throw runtime_error(WRITING_ERROR);
                    }
                } else if(!(OF << setw(10) << right << randGen(1, 10))){
                    throw runtime_error(WRITING_ERROR);
                }
            }
            if(i != (stNum - 1)){
                OF << endl;
            }
        }

        OF.close();

        auto tEnd = chrono::steady_clock::now();
        auto tDuration = chrono::duration_cast<chrono::milliseconds>(tEnd - tStart);

        cout << "Failo kurimas uztruko: " << double(tDuration.count())/1000 << " sekundziu" << endl;
    } catch(runtime_error& e){
        cout << e.what() << right << endl;
    }
}
