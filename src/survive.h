#include <Eigen/Dense>

using namespace Eigen;


class Survive {

    public:
        MatrixXi data;

    public:
        Survive(int width, int height);
        ~Survive(){}

        void setAliveCell(int i, int j);
        int calculatorOneCell(int i, int j);
        void calculatorNextStep();
};
