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
    MatrixXi datac;
    
    datac=data.block<3,3>(1,1);
    MatrixXi model(3,3);
    model << 1,1,1,
            1,0,1,
            1,1,1;
    cout << datac  << endl << endl << model << endl << endl;
    cout << datac * model <<endl;
    return (datac*model).trace();
}

void Survive::calculatorNextStep()
{

}