#include <iostream.h>

namespace spazio_matrici
{
	const int dim = 2;

	class Matrix;

	struct MperM
	{
		const Matrix& M1;
		const Matrix& M2;
		MperM(const Matrix& m1, const Matrix& m2) : M1(m1), M2(m2) { }
		operator Matrix(); // casting - tralasciamo l'implementazione
	};

	inline MperM operator*(const Matrix& m1, const Matrix& m2)
	{
		return MperM(m1,m2);
	}

	struct MperMpiuM
	{
		const Matrix& M1;
		const Matrix& M2;
		const Matrix& M3;
		MperMpiuM(const MperM& mm, const Matrix& m3) : 
			M1(mm.M1), M2(mm.M2), M3(m3) { }
		operator Matrix(); // casting - tralasciamo l'implementazione
	};

	inline MperMpiuM operator+(const MperM& mm, const Matrix& m3)
	{
		return MperMpiuM(mm,m3);
	}

	class Matrix
	{
		float m[dim][dim];
		void optimize(const Matrix&, const Matrix&, const Matrix&);
	public:
		explicit Matrix(bool=true);
		Matrix& operator=(const MperMpiuM&);
		operator float();
		friend class Matrice;
		static int nog;  // numero oggetti
		static int nop;  // numero operazioni
	};

	class Matrice
	{
		float m[dim][dim];
	public:
		Matrice();
		Matrice(const Matrix&);
		Matrice(const Matrice&);
		Matrice& operator=(const Matrice& mat);
		operator float();
		friend Matrice operator*(const Matrice&, const Matrice&);
		friend Matrice operator+(const Matrice&, const Matrice&);
		static int def; // numero oggetti creati di default
		static int cmx; // numero oggetti creati per copia da Matrix
		static int cop; // numero oggetti creati per copia
		static int ass; // numero di assegnazioni
		static int mul; // numero di moltiplicazioni
		static int sum; // numero di addizioni
	};
}


