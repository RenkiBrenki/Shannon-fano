//
// Created by jauso on 5/18/2024.
//

#include <iostream>
#include <fstream>
using namespace std;

class BinReader {
public:
    int k;
    ifstream f;
    char x;

    BinReader(const char *p) : k(0) {
        f.open(p, ios::binary);
    }

    char readByte() {
        f.read((char*)&x, 1);
        return x;
    }

    bool readBit() {
        if (k == 8) {
            readByte();
            k = 0;
        }
        bool b = (x >> k) & 1;
        k++;
        return b;
    }

    int readInt() {
        f.read((char*)&x, 4);
        return x;
    }

    float readFloat() {
        f.read((char*)&x, 32);
        return x;
    }
};