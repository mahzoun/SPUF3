#include <iostream>
#include "PUF.h"

using namespace std;
PUF puf;

int main() {
    puf.Init();
    puf.Print();
    int C[2][2] = {{0, 1},
                   {1, 2}};
    puf.Auth(C, 2);
    puf.Print();
    return 0;
}
