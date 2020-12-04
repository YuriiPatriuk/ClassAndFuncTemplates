#include <iostream>
#include "Matrix.h"
int main()
{
	std::cout << "count of Matrix<int> m(2, 3): " << Matrix<int>::getCount() << std::endl;
	Matrix<int> m(2, 3),n;
	std::cout << "count of Matrix<int> m(2, 3): " << Matrix<int>::getCount() << std::endl;
	//1 - створить клас на основі шаблону класу(T = int)
	//class Matrix_123 {int ** matrix...}
	//2 - створить екземпляр класу(викликає к-тор з параметрами)
	std::cout << "---------start--------\n";
	m(0, 0) = 100;
	m(0, 1) = 200;
	m.print();
	std::cout << "\n";
	n = m;
	n.print();


	Matrix<std::string> mS(3, 3);
	//mS.print();
	mS(1, 1) = "center";
	std::cout << mS;
	std::cout << "Count of Matrix<std::string> : " <<
		Matrix<std::string> ::getCount() << std::endl;
	Matrix<> d(3, 4);
	d(1, 1) = 1.2;




}
