//
// Created by jauso on 5/18/2024.
//
#include <iostream>
#include <fstream>
using namespace std;

class BinWriter {
public:
    int k;
    ofstream f;
    char x;

    BinWriter(const char *p) : k(0) {
        f.open(p, ios::binary);
    }

    ~BinWriter() {
        if (k > 0) writeByte(x);
        f.close();
    }

    void writeByte(char x) {
        f.write((char*)&x, 1);
    }

    void writeInt(int y) {
        f.write((char*)&y, 4);
    }

    void writeFloat(float y) {
        f.write((char*)&y, 32);
    }

    void writeBit(bool b) {
        if (k == 8) {
            writeByte(x);
            k = 0;
        }
        x ^= (-b ^ x) & (1 << k);
        k++;
    }
};