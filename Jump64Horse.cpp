#include <iostream>
#include <string>
#include <sys/time.h>
#include <stdlib.h>
#include "table.hpp"

using namespace std;


int main () {
    struct timeval start, stop;
    double secs = 0;

    gettimeofday(&start, NULL);    
    
    Table table;
    //table_print(table, "Početak");
    table.jump(2, 2, 1);
    table.print("++:Kraj:++*", 3);

    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    cout << "Time taken: " << secs << endl;

    return 0;
}

