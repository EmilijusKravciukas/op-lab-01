#include <iostream>
#include <string>
#include <time.h>
#include <locale.h>
#include <vector>
#include "fileRead.h"
#include "inputCheck.h"
#include "inputData.h"
#include "studentas.h"

using namespace std;

int main(){
    srand(time(0));
    system("chcp 65001  > nul");

    cout<<"Pasirinkite įvedimo būdą: " << endl
        << "(1) Rankinis įvedimo būdas" << endl
        << "(2) Skaitymas iš failo" << endl;

    int cInput = intIvestis(1, 2);

    vector<Studentas> studentai;

    if(cInput == 1){
        ivestis(studentai);
    } else if(cInput == 2){
        duomSkait(studentai);
    }

    return 0;
}
