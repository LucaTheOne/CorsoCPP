#include <stdlib.h>
#include "matr.h"

namespace spazio_matrici
{
	const float conv = 10.0f/RAND_MAX;

	int Matrix::nog;
	int Matrix::nop;

	Matrix::Matrix(bool init)
	{
		nog++;
		if (init) for(int i=0; i < dim; i++) for(int j=0; j < dim; j++)
				m[i][j] = conv*rand();
	}

	Matrix& Matrix::operator=(const MperMpiuM& mmm)
	{
		optimize(mmm.M1,mmm.M2,mmm.M3);
		return *this;
	}

	Matrix::operator float()
	{
		float s = 0.0;
		for(int i=0; i < dim; i++) for(int j=0; j < dim; j++)
			s += m[i][j];
		return s/(dim*dim);
	}

	void Matrix::optimize(const Matrix& M1, const Matrix& M2, 
		const Matrix& M3)
	{
		nop++;
		float val;
		for(int i=0; i < dim; i++) for(int j=0; j < dim; j++)
		{
			val = M3.m[i][j];
			for (int k=0; k < dim; k++)
				val += M1.m[i][k] * M2.m[k][j];
			m[i][j] = val;
		}
	}

	int Matrice::def;
	int Matrice::cmx;
	int Matrice::cop;
	int Matrice::ass;
	int Matrice::mul;
	int Matrice::sum;

	Matrice::Matrice()
	{
		def++;
	}

	Matrice::Matrice(const Matrix& mat)
	{
		cmx++;
		for(int i=0; i < dim; i++) for(int j=0; j < dim; j++)
			m[i][j] = mat.m[i][j];
	}

	Matrice::Matrice(const Matrice& mat)
	{
		cop++;
		for(int i=0; i < dim; i++) for(int j=0; j < dim; j++)
			m[i][j] = mat.m[i][j];
	}

	Matrice& Matrice::operator=(const Matrice& mat)
	{
		ass++;
		for(int i=0; i < dim; i++) for(int j=0; j < dim; j++)
			m[i][j] = mat.m[i][j];
		return *this;
	}

	Matrice::operator float()
	{
		float s = 0.0;
		for(int i=0; i < dim; i++) for(int j=0; j < dim; j++)
			s += m[i][j];
		return s/(dim*dim);
	}

	Matrice operator*(const Matrice& M1, const Matrice& M2)	
	{
		Matrice::mul++;
		Matrice temp;
		float val;
		for(int i=0; i < dim; i++) for(int j=0; j < dim; j++)
		{
			val = 0.0;
			for (int k=0; k < dim; k++)
				val += M1.m[i][k] * M2.m[k][j];
			temp.m[i][j] = val;
		}
		return temp;
	}

	Matrice operator+(const Matrice& M1, const Matrice& M2)	
	{
		Matrice::sum++;
		Matrice temp;
		for(int i=0; i < dim; i++) for(int j=0; j < dim; j++)
			temp.m[i][j] = M1.m[i][j] + M2.m[i][j];
		return temp;
	}
}


