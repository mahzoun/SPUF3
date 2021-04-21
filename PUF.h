#ifndef SPUF3_PUF_H
#define SPUF3_PUF_H

#include <iostream>
#include <random>
#include <bitset>

#define N 6 //columns
#define M 6 //rows
using namespace std;

class PUF {
public:
    bitset<N> S[M];
    int P[M][N] = {{3, 1, 1, 6, 1, 6},
                   {1, 6, 4, 2, 3, 5},
                   {5, 5, 5, 1, 5, 1},
                   {2, 2, 2, 4, 6, 2},
                   {4, 4, 6, 5, 2, 4},
                   {6, 3, 3, 3, 4, 3}};

    void Init();

    void Fight(int, int);

    void Auth(int[][2], int);

    void Print();
};


#endif //SPUF3_PUF_H
