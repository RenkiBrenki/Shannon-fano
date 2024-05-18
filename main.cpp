// PRIMER za BinReader in BinWriter
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

int main() {
	BinWriter bw("test.bin");
	bw.writeBit(1);
	bw.writeBit(0);
	bw.writeBit(0);
	bw.writeBit(0);
	bw.writeBit(0);
	bw.writeBit(0);
	bw.writeBit(1);
	bw.writeBit(0); 
	bw.writeByte(bw.x);
	bw.f.close();

	BinReader br("test.bin");
	br.readByte();
	for (int i = 0; i < 8; ++i)
		std::cout << (int)br.readBit() << "\n";
	br.f.close();

	return 0;
}