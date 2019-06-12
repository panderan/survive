#include <iostream>
#include "survive.h"

using namespace std;

Survive::Survive(int width, int height)
{
    data = MatrixXi::Zero(width, height);
}

void Survive::setAliveCell(int i, int j)
{
    data(i,j) = 1;
}

int Survive::calculatorOneCell(int i, int j)
{
    return 2;
}


