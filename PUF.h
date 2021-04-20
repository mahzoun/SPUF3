#ifndef SPUF3_PUF_H
#define SPUF3_PUF_H

#include <iostream>
#include <random>
#include <bitset>

#define N 5 //columns
#define M 3 //rows
using namespace std;

class PUF {
public:
    bitset<N> S[M];
    int P[M][N] = {{3, 2, 2, 1, 3},
                   {1, 1, 3, 2, 2},
                   {2, 3, 1, 3, 1}};

    void Init();

    void Fight(int, int);

    void Auth(int[][2], int);

    void Print();
};


#endif //SPUF3_PUF_H
