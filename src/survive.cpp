#include <iostream>
#include "survive.h"

using namespace std;

Survive::Survive(int width, int height)
{
    data = MatrixXi::Zero(width+2, height+2);
}

void Survive::setAliveCell(int i, int j)
{
    data(i,j) = 1;
}

int Survive::calculatorOneCell(int i, int j)
{
    MatrixXi datac;
    
    datac=data.block<3,3>(i,j);
    MatrixXi model(3,3);
    model << 1,1,1,
            1,0,1,
            1,1,1;

    return (datac*model).trace();
}

void Survive::calculatorNextStep()
{

}