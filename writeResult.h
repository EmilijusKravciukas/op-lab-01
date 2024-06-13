#pragma once

#include <vector>
#include <iostream>
#include "studentas.h"
#include <iomanip>
#include <algorithm>

using namespace std;

void atvaizd(vector<Studentas>& studentai, int m, int rikiavimas);
bool rikiavimasPaz(Studentas& s1, Studentas& s2);
bool rikiavimasPavarde(Studentas& s1, Studentas& s2);
bool rikiavimasVardu(Studentas& s1, Studentas& s2);