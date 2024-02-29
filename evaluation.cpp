#include "evaluation.h"

double rastiVid(Studentas studentasTemp){
    for(int i = 0; i < studentasTemp.n; i++){
        studentasTemp.vid += studentasTemp.nd[i];
    }
    studentasTemp.vid /= studentasTemp.n;

    return studentasTemp.vid;
}

double rastiVid(vector<Studentas>& studentai, int m){
    for(int i = 0; i < studentai[m].n; i++){
        studentai[m].vid += studentai[m].nd[i];
    }
    studentai[m].vid /= studentai[m].n;

    return studentai[m].vid;
}

double rastiMed(Studentas studentasTemp){
    for(int i = 0; i < studentasTemp.n; i++){
        for(int j = i+1; j < studentasTemp.n; j++){
            if(studentasTemp.nd[i] < studentasTemp.nd[j]){
                int temp = studentasTemp.nd[i];
                studentasTemp.nd[i] = studentasTemp.nd[j];
                studentasTemp.nd[j] = temp;
            }
        }
    }

    if(studentasTemp.n % 2 == 0){
        studentasTemp.mediana = double(studentasTemp.nd[studentasTemp.n/2 - 1] + studentasTemp.nd[studentasTemp.n/2]) / 2;
    } else {
        studentasTemp.mediana = studentasTemp.nd[studentasTemp.n/2];
    }

    return studentasTemp.mediana;
}

double rastiMed(vector<Studentas>& studentai, int m){
    for(int i = 0; i < studentai[m].n; i++){
        for(int j = i+1; j < studentai[m].n; j++){
            if(studentai[m].nd[i] < studentai[m].nd[j]){
                int temp = studentai[m].nd[i];
                studentai[m].nd[i] = studentai[m].nd[j];
                studentai[m].nd[j] = temp;
            }
        }
    }

    if(studentai[m].n % 2 == 0){
        studentai[m].mediana = (studentai[m].nd[studentai[m].n/2] + studentai[m].nd[studentai[m].n/2 + 1]) / 2;
    } else {
        studentai[m].mediana = studentai[m].nd[studentai[m].n/2 + 1];
    }

    return studentai[m].mediana;
}