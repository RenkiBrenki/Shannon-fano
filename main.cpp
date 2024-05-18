// PRIMER za BinReader in BinWriter
#include <iostream>
#include "BinWriter.cpp"
#include "BinReader.cpp"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool contains(string niz, char ch) {
    for (int i = 0; i < niz.size(); i++) {
        if (niz[i] == ch) {
            return true;
        }
    }
    return false;
}

template <typename T>
void print_vector(const std::vector<T>& vec) {
    for (const T& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void shannon_fano(const string niz) {
    map<char, int> stats;
    for (auto &ch : niz) {
        if (contains(niz, ch))
            stats[ch] += 1;
    }

    vector<pair<char, int>> pairs(stats.begin(), stats.end());
    sort(pairs.begin(), pairs.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });

    for (const auto& pair : pairs) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main(int argc, const char *const argv[]) {
    if (argc != 3) {
        return -1;
    }

    const string file_name = argv[2];
    const char* option = argv[1];

    if (*option == 'c') {
        shannon_fano("ABRACADABRA");
    }
    else if (*option == 'd') {

    }

    shannon_fano("ABRACADABRA");

	return 0;
}