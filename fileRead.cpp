#include "fileRead.h"

void duomSkait(vector<Studentas>& studentai){
    system("dir *.txt");
    cout<<"Pasirinkite duomenų failą: ";

    string duomPav;

    cin >> duomPav;

    ifstream DF(duomPav);

    string tempString;
    int tempInt;
    unsigned int m = 0;

    do{
        DF >> tempString;
    }while(tempString != "Egz.");

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

    cout<<"Pasirinkite rikiavimo būdą: " << endl
        <<"(1) Pagal studento vardą" << endl
        <<"(2) Pagal studento pavarde" << endl
        <<"(3) Pagal studento galutinį pažymį" << endl;

    atvaizd(studentai, m, intIvestis(1, 3));
}