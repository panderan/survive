#include <iostream>
#include "survive.h"

using namespace std;

Survive::Survive(int width, int height)
{
    data = MatrixXi::Zero(width, height);
}






/*
 *  int main()
 *  {
 *          Matrix4d data;
 *          data << 1, 2, 3, 4,
 *         5, 6, 7, 8,
 *             9, 10, 11, 12,
 *             13, 14, 15, 16;
 *
 *          MatrixXd t(3,3);
 *          t << 1,1,1,
 *         1,0,1,
 *             1,1,1;
 *
 *    std::cout << "a * b =\n" << a * b << std::endl;
 *    std::cout << "a - b =\n" << a - b << std::endl;
 *    std::cout << "Doing a += b;" << std::endl;
 *    a += b;
 *    std::cout << "Now a =\n" << a << std::endl;
 *    Vector3d v(1,2,3);
 *    Vector3d w(1,0,0);
 *    std::cout << "-v + w - v =\n" << -v + w - v << std::endl;
 *
 *          std::cout << data.block<3,3>(1,1) << std::endl;
 *          std::cout << ((data.block<3,3>(1,1))*t).trace() << std::endl;
 *
 *          return 0;
 *  }
 */
