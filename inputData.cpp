#include "inputData.h"

void ivestis(){
    vector<Studentas> studentai;

    bool loop = true;
    unsigned int m = 0;
    unsigned int n = 0;
    while(loop){
        cout << "Pasirinkite įvedimo būdą:" << endl
        << "(1) Duomenų įvedimas ranka" << endl
        << "(2) Generuoti pažymius" << endl
        << "(3) Generuoti vardą, pavardę ir pažymius" << endl
        << "(4) Baigti darbą" << endl;

        int cInput = intIvestis(0, 10);

        if(cInput == 1){
            n = 0;

            Studentas studentasTemp;

            bool ndLoop = true;

            cout << "Įveskite studento vardą: ";
            studentasTemp.vardas = stringIvestis();
            cout << "Įveskite studento pavardę: ";
            studentasTemp.pavarde = stringIvestis();
            cout << "Įveskite studento namų darbų pažymius (0 - pereiti prie egzamino pažymio įvesties): ";
            while(ndLoop){
                int temp = intIvestis(0, 10);
                if(temp != 0){
                    studentasTemp.nd.push_back(temp);
                    n++;
                } else {
                    cout << "Įveskite studento egzamino pažymį: ";
                    studentasTemp.egz = intIvestis(1, 10);
                    studentasTemp.n = n;
                    studentasTemp.vid = rastiVid(studentasTemp);
                    studentasTemp.mediana = rastiMed(studentasTemp);

                    ndLoop = false;
                }
            }
            
            studentai.push_back(studentasTemp);

            m++;
        } else if(cInput == 2){
            n = 0;

            Studentas studentasTemp;

            cout << "Įveskite studento vardą: ";
            studentai[m].vardas = stringIvestis();
            cout << "Įveskite studento pavardę: ";
            studentai[m].pavarde = stringIvestis();

            n = randGen(1, 10);
            studentasTemp.n = n;
            for(int i = 0; i < n; i++){
                studentasTemp.nd.push_back(randGen(1, 10));
            }

            studentasTemp.egz = randGen(1, 10);
            studentasTemp.n = n;
            studentasTemp.vid = rastiVid(studentasTemp);
            studentasTemp.mediana = rastiMed(studentasTemp);

            studentai.push_back(studentasTemp);

            m++;
        } else if(cInput == 3){
            n = 0;
            
            Studentas studentasTemp;

            vector<string> vardai = {"Rokas", "Karolis", "Nojus", "Edgaras", "Martynas", "Gytis", "Justas"};
            vector<string> pavardes = {"Kazlauskas", "Stankevičius", "Petrauskas", "Jankauskas", "Žukauskas", "Butkus", "Balčiūnas"};

            studentasTemp.vardas = vardai[randGen(0, 6)];
            studentasTemp.pavarde = pavardes[randGen(0, 6)];

            n = randGen(1, 10);
            studentasTemp.n = n;
            for(int i = 0; i < n; i++){
                studentasTemp.nd.push_back(randGen(1, 10));
            }

            studentasTemp.egz = randGen(1, 10);
            studentasTemp.n = n;
            studentasTemp.vid = rastiVid(studentasTemp);
            studentasTemp.mediana = rastiMed(studentasTemp);

            studentai.push_back(studentasTemp);

            m++;
        } else if(cInput == 4){
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
                studSort(studentai, m);
            } else {
                atvaizd(studentai, m, intIvestis(1, 3));
            }
        }
    }
}
