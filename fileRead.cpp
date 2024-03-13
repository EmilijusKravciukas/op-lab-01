#include "fileRead.h"

void duomSkait(vector<Studentas>& studentai){

    try{
        string command = "dir *.txt 2>" "NUL";

        int directoryCheck = system(command.c_str());

        if(directoryCheck != 0){
            throw runtime_error("Nerasta duomenu failu");
        }

        //system("dir *.txt");
        cout<<"Pasirinkite duomenų failą: ";

    } catch(const runtime_error& e){
        cerr << e.what() << endl;
    }

    string duomPav;

    cin >> duomPav;

    try{
        auto tStart = chrono::steady_clock::now();

        ifstream DF(duomPav);

        if(!DF.is_open()){
            throw runtime_error("Nepavyko atidaryti failo");
        }

        string tempString;
         int tempInt;
        unsigned int m = 0;

        do{
            DF >> tempString;
        }while(tempString != "Egz.");

        if(DF.fail()){
            throw runtime_error("Nepavyko nuskaityti duomenis");
        }

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

        auto tEnd = chrono::steady_clock::now();
        auto tDuration = chrono::duration_cast<std::chrono::milliseconds>(tEnd - tStart);

        cout << "Failo skaitymas uztruko : " << tDuration.count() << " milisekundziu" << std::endl;

        cout<<"Pasirinkite rikiavimo būdą: " << endl
        <<"(1) Pagal studento vardą" << endl
        <<"(2) Pagal studento pavarde" << endl
        <<"(3) Pagal studento galutinį pažymį" << endl;

        atvaizd(studentai, m, intIvestis(1, 3));
    } catch(const runtime_error& e){
        cerr << e.what() << endl;
    }
}
