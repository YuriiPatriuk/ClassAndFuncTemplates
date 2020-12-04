#pragma once
#include <iostream>
using namespace std;
template<typename T=double>
class Matrix
{
public:
	Matrix(const size_t& rows = 2, const size_t& cols = 2);
	Matrix(const Matrix& other);
	void print() const;
	~Matrix();
	T& operator()(const size_t& r,const size_t& c);//operator func call ніби індексування
	Matrix<T>& operator=(const Matrix<T>& other);//operator func call ніби індексування
	static size_t getCount();
private:
	static size_t count; //static fill
	T** matrix = nullptr;
	size_t rows, cols;
	bool isValidIndex(const size_t& r, const size_t& c) const
	{
		return r < rows && c < cols;
	}
	template <typename T>
	friend ostream& operator << (ostream& out, const Matrix<T>& m);
};

template<typename T>
size_t Matrix<T>::count = 0;

template<typename T>
inline Matrix<T>::Matrix(const size_t& rows, const size_t& cols)
{
	this->rows = rows > 0 ? rows : 1;
	this->cols = cols > 0 ? cols: 1;
	matrix = new T * [this->rows];
	for (size_t i = 0; i < this->rows; i++)
	{
		matrix[i] = new T[this->cols]{}; //default for type T
	}
	++count;
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix& other)
{
	*this = other;
}

template<typename T>
inline void Matrix<T>::print() const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	cout << "~~~~~~~~DTOR~~~~~~~\n";
	cols = 0;
	rows = 0;
	if (matrix != nullptr)
	{
		for (size_t i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = nullptr;
	}

}

template<typename T>
inline T& Matrix<T>::operator()(const size_t& r, const size_t& c)
{
	static T error;
	if (isValidIndex(r, c))
		return matrix[r][c];
	else error;
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
	this->cols = other.cols;
	this->rows = other.rows;
	for (size_t i = 0; i < this->rows; i++)
		this->matrix[i] = new T[this->cols]{}; //default for type T
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			this->matrix[i][j] = other.matrix[i][j];
	}
	return *this;
}

template<typename T>
inline size_t Matrix<T>::getCount()
{
	return count;
}

template<typename T>
inline ostream& operator<<(ostream& out, const Matrix<T>& m)
{
	for (size_t i = 0; i < m.rows; i++)
	{
		for (size_t j = 0; j < m.cols; j++) 
		{
			out << m.matrix[i][j] << "," << "\t";
		}
		out << endl;
	}
	return out;
}
