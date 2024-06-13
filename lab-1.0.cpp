#include <iostream>
#include <string>
#include <time.h>
#include <locale.h>
#include <vector>
#include "fileRead.h"
#include "inputCheck.h"
#include "inputData.h"
#include "studentas.h"
#include "fileGen.h"

using namespace std;

int main(){
    srand(time(0));
    system("chcp 65001  > nul");

    int cInput = 0;

    while(cInput != 4){
        cout<<"Menu: " << endl
            << "(1) Rankinis įvedimo būdas" << endl
            << "(2) Skaitymas iš failo" << endl
            << "(3) Generuoti duomenu faila" << endl
            << "(4) Baigti darbą" << endl;

        cInput = intIvestis(1, 4);

        if(cInput == 1){
            ivestis();
        } else if(cInput == 2){
            duomSkait();
        } else if(cInput == 3){
            generateFile();
        }
    }
    

    return 0;
}
