#include <iostream>
#include <random>
#include "PUF.h"

using namespace std;
static std::random_device rd;
static std::mt19937 rng{rd()};

void PUF::Init() {
    static std::uniform_int_distribution<int> uid(0, 1); // random dice
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            S[i][j] = uid(rng);
}

void PUF::Fight(int A, int B) {
    for (int i = 0; i < N; i++) {
        if (P[A][i] > P[B][i]) {
            S[B][N - i - 1] = S[A][N - i - 1];
        } else {
            S[A][N - i - 1] = S[B][N - i - 1];
        }
    }
}

void PUF::Auth(int Challenge[][2], int ChSize) {
    for (int i = 0; i < ChSize; i++) {
        Fight(Challenge[i][0], Challenge[i][1]);
    }
}

void PUF::Print() {
    for (int i = 0; i < M; i++)
        cout << S[i] << endl;
    cout << endl;
}