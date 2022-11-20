#ifndef HEADER_TABLE
#define HEADER_TABLE

#include <string>

#define TABLE_SIZE 8

using namespace std;

class Table {

    private:
    int moves[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    int table[TABLE_SIZE + 4][TABLE_SIZE + 4];
    
    public:
        Table();

        void print(string);
        void print(string, int);

        int canMove(int, int, int);
        void setMove(int, int, int, int); 
        int jump(int, int, int);

};

#endif