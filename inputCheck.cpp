#include "inputCheck.h"

string stringIvestis(){
    string cInput;
    bool loop = false;

    do{
        loop = false;
        cin >> cInput;
        for(char a : cInput){
            if(isblank(a) || isdigit(a) || cInput.length() > 20){
                loop = true;
            }
        }
        if(loop){
            cout << "Klaida. Bandykite dar kartą: ";
        }
    }while(loop);

    return cInput;
}

string fileIvestis(){
    string cInput;
    bool loop = false;

    do{
        loop = false;
        cin >> cInput;
        for(char a : cInput){
            if(isblank(a) || cInput.length() > 30){
                loop = true;
            }
        }
        if(loop){
            cout << "Klaida. Bandykite dar kartą: ";
        }
    }while(loop);

    return cInput;
}

int intIvestis(int sRange, int eRange){
    int cInput;
    bool loop = false;

    do{
        loop = false;
        cin >> cInput;
        if(cInput < sRange || cInput > eRange || !cin){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                loop = true;
        }
        for(char a : to_string(cInput)){
            if(isblank(a)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                loop = true;
            }
        }
        if(loop){
            cout << "Klaida. Bandykite dar kartą: ";
        }
    }while(loop);

    return cInput;
}