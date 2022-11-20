 #include <iostream>
#include <string>

#include <stdlib.h>
#include "table.hpp"
#include "helpers.hpp"
using namespace std;

Table::Table() {
    //Table *table = (Table *)malloc(sizeof(Table));
    
    for(int i = 0; i < TABLE_SIZE + 4; i++) {
        for (int j = 0; j < TABLE_SIZE + 4; j++) {
            table[i][j] = -1;
        }
    }
   for(int i = 2; i < TABLE_SIZE + 2; i++) {
        for (int j = 2; j < TABLE_SIZE + 2; j++) {
            table[i][j] = 0;
        }
    }
    table[2][2] = 1;
}

void Table::print(string descr, int severity) {
    if(severity <= LOG_LEVEL || descr[0] == '*') {
        cout << endl << descr << endl;
        if(severity <= LOG_LEVEL) {
            printf("   x | y      ");
            for(int i = 0; i < TABLE_SIZE; i++) {
                printf("%*d", 4, i + 1);
            }
            
            cout << endl << "-----+-----------";
            for(int i = 0; i < TABLE_SIZE; i++) {
                cout << "----";
            }
            cout << "------+" << endl;

            for(int i = 0; i < TABLE_SIZE + 4; i++) {
                if(i > 1 && i < TABLE_SIZE + 2) {
                    printf("%*d |", 4, i - 1);
                } else {
                    cout << "     |";
                }
                for (int j = 0; j < TABLE_SIZE + 4; j++) {
                    printf("%*d",4, table[i][j]);
                }
                cout << " |" << endl;
            }
            cout << "-----+-----------";
            for(int i = 0; i < TABLE_SIZE; i++) {
                cout << "----";
            }
            cout << "------+" << endl;
        }
    }

}

void Table::print(string descr) {
    print(descr, 5);
}


int Table::canMove(int x, int y, int direction) {
    return !table[x + moves[direction][0]][y + moves[direction][1]];
}

void Table::setMove(int x, int y, int direction, int value) {
    table[x + moves[direction][0]][y + moves[direction][1]] = value;
}

int Table::jump(int x, int y, int move) {
    int lastMove = -1;
    //string text, number;
    //strcpy(text, "Potez: ");
    //sprintf(text << number "%s %d","Potez: ", move);
    //strcat(text, number);
    print("Potez: " +  to_string(move), 7);
    if(move >= MOVES) {
        return 1;
    }

    for(int i = 0; i < 8; i++) {
        if(canMove(x, y, i)) {
            setMove(x, y, i, move + 1);
            if(lastMove > -1) {
                setMove(x, y, lastMove, 0);
                //sprintf(text, "%s %d %s %d, %s %d", "Brisanje:", move, "Direction:", i, "Last move,", lastMove);
                print("Brisanje: " + to_string(move) + " Direction: " + to_string(i) + " Last move: " + to_string(lastMove), 6);
                //printf(" ");
            }
            lastMove = i;
            if(jump(x + moves[i][0], y + moves[i][1], move + 1)) {
                print("Kraj:");
                return 1;
            }
            
        }
    }
    if(lastMove > -1) {
        setMove(x, y, lastMove, 0);
        //sprintf(text, "%s %d", "Kraj poteza:", move);
        print("Kraj poteza: " + move, 6);
    }
    return 0;
}
