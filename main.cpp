#include <iostream>
#include <fstream>

using namespace std;

int main(){
    struct Studentas{
        string vardas;
        string pavarde;
        int n;
        double nd;
        int egz;
    };

    ifstream DF("data.txt");

    int N;
    DF>>N;
    cout<<N;

    Studentas studentai[N];

    for(int i = 0; i < N; i++){
        DF>>studentai[i].vardas;
        DF>>studentai[i].pavarde;
        DF>>studentai[i].n;
        int temp = 0;
        for(int j = 0; j < studentai[i].n; j++){
            DF>>temp;
            studentai[i].nd += temp;
        }
        studentai[i].nd /= studentai[i].n;
        DF>>studentai[i].egz;
    }
    

    DF.close();
  
    return 0;
}
