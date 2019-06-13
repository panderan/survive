#ifndef SURVIVE_H_
#define SURVIVE_H_

#include <Eigen/Dense>

using namespace Eigen;


class Survive {

    public:
        MatrixXi data;

    public:
        Survive(int width = 0, int height = 0);
        ~Survive(){}

        void setAliveCell(int i, int j);
        void setSize(int width, int height);
        int calculatorOneCell(int i, int j);
        void calculatorNextTime();

        int getStatus(int i, int j);
        int getWidth();
        int getHeight();
        bool isDeadWorld();
};

extern Survive gSur;

#endif

