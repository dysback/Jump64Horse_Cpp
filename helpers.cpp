#include <iostream>
#include "helpers.hpp"
using namespace std;

void logStr(char *value, int severity) {
    if(severity >= LOG_LEVEL) {
        cout << "-" << value << "------" << endl;
    }

}

void logInt(int value, int severity) {
    if(severity >= LOG_LEVEL) {
        cout << "-" << value << "------" << endl;
    }

}