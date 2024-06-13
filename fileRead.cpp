#include "fileRead.h"

void duomSkait(){
    vector<Studentas> studentai;

    try{
        string command = "dir *.txt 2>" "NUL";

        int directoryCheck = system(command.c_str());

        if(directoryCheck != 0){
            throw runtime_error("Nerasta duomenu failu");
        }

        cout<<"Pasirinkite duomenų failą: ";

    } catch(const runtime_error& e){
        cerr << e.what() << endl;
    }

    string duomPav = fileIvestis();

    try{
        auto tStart = chrono::steady_clock::now();

        ifstream DF(duomPav);
        string line;

        if(!DF.is_open()){
            throw runtime_error("Nepavyko atidaryti failo");
        }

        string tempString;
        unsigned int m = 0;

        getline(DF, line);

        if(DF.fail()){
            throw runtime_error("Nepavyko nuskaityti duomenis");
        }

        while(getline(DF, line)){
            stringstream ss(line);
            Studentas studentasTemp;
            ss >> studentasTemp.vardas >> studentasTemp.pavarde;

            studentai.push_back(studentasTemp);

            int n = 0;

            int num;

            while(ss >> num){
                n++;
                studentai[m].nd.push_back(num);
            }

            studentai[m].egz = studentai[m].nd[n-1];
            studentai[m].nd.pop_back();
            studentai[m].n = n;
            studentai[m].vid = rastiVid(studentai, m);
            studentai[m].mediana = rastiMed(studentai, m);

            m++;
        }

        // while(DF.peek() != EOF){
        //     Studentas studentasTemp;
        //     DF >> studentasTemp.vardas;
        //     DF >> studentasTemp.pavarde;

        //     studentai.push_back(studentasTemp);

        //     int n = 0;

        //     while(DF.peek() != '\n' && DF.peek() != EOF){
        //         DF >> tempInt;
        //         n++;
        //         studentai[m].nd.push_back(tempInt);
        //     }

        //     studentai[m].egz = studentai[m].nd[n-1];
        //     studentai[m].nd.pop_back();
        //     studentai[m].n = n;
        //     studentai[m].vid = rastiVid(studentai, m);
        //     studentai[m].mediana = rastiMed(studentai, m);

        //     m++;
        // }

        auto tEnd = chrono::steady_clock::now();
        auto tDuration = chrono::duration_cast<chrono::milliseconds>(tEnd - tStart);

        cout << "Failo skaitymas uztruko: " << double(tDuration.count())/1000 << " sekundziu" << endl;

        cout<<"Pasirinkite rikiavimo būdą: " << endl
            <<"(1) Pagal studento vardą" << endl
            <<"(2) Pagal studento pavarde" << endl
            <<"(3) Pagal studento galutinį pažymį" << endl;

        int rikiavimoBudas = intIvestis(1, 3);

        cout<<"Pasirinkite atvaizdavimo buda: " << endl
            <<"(1) Komandineje eiluteje" << endl
            <<"(2) Issaugoti i du failus (rikiavimas pagal pasiekimus)" << endl;

        int cInput = intIvestis(1, 2);

        if(cInput == 1){
            atvaizd(studentai, m, rikiavimoBudas);
        } else {
            studSort(studentai, m, rikiavimoBudas);
        }
    } catch(const runtime_error& e){
        cerr << e.what() << endl;
    }
}