#pragma once

#include <vector>
#include "studentas.h"

using namespace std;

double rastiVid(Studentas studentasTemp);
double rastiMed(Studentas studentasTemp);

double rastiVid(vector<Studentas>& studentai, int m);
double rastiMed(vector<Studentas>& studentai, int m);