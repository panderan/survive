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
    
    datac=data.block<3,3>(i-1,j-1);

//    cout << "data-c :" << endl << datac << endl;
    MatrixXi model(3,3);
    model << 1,1,1,
            1,0,1,
            1,1,1;

    return (datac*model).trace();
}

void Survive::calculatorNextTime()
{
    int rows = 0, cols = 0;
    MatrixXi newdata;

    rows = data.rows();
    cols = data.cols();

    newdata = MatrixXi::Zero(rows, cols);
    
    for (int i = 1; i < rows-1; i++) {
        for (int j = 1; j < cols-1; j++) {
            int cnt = 0;
            cnt = calculatorOneCell(i,j);
            if (data(i,j) == 0) {
                if (cnt == 3) {
                    newdata(i,j) = 1;
                }
            }
            else {
                if (cnt == 2 || cnt == 3) {
                    newdata(i,j) = 1;
                }
            }
        }
    }

    data = newdata;
}

