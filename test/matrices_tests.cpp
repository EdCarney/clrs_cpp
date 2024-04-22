#include "../src/sorting_and_ordering/matrices.hpp"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

void expect_matrices_equal(matrices::matrix_2d A, matrices::matrix_2d B) {
	EXPECT_EQ(A.size(), B.size());
	
	int n = A.size();
	for (int i = 0; i < n; i++) {
		EXPECT_EQ(A[i].size(), B[i].size());
		int m = A[i].size();
		for (int j = 0; j < m; j++) {
			EXPECT_EQ(A[i][j], B[i][j]) << "Failed for index: (" << i << ", " << j << ")";
		}
	}
}

TEST(MatrixMultiplySquareBruteForce, EmptyMatrices) {
	matrices::matrix_2d A = vector<vector<int>>();
	matrices::matrix_2d B = vector<vector<int>>();

	matrices::matrix_2d C = matrices::multiply_square_bruteforce(A, B);

	EXPECT_TRUE(C.empty());
}

TEST(MatrixMultiplySquareBruteForce, NonEmptyMatrices) {
	vector<vector<int>> A {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	vector<vector<int>> B {
		{ 9, 8, 7 },
		{ 6, 5, 4 },
		{ 3, 2, 1 }
	};
	vector<vector<int>> C_expected {
		{ 30,  24,  18 },
		{ 84,  69,  54 },
		{ 138, 114, 90 }
	};

	matrices::matrix_2d C = matrices::multiply_square_bruteforce(A, B);

	expect_matrices_equal(C, C_expected);;
}

TEST(MatrixMultiplySquareDivideAndConquer, NonEmpty2x2Matrices) {
	vector<vector<int>> A {
		{ 1, 2 },
		{ 4, 5 },
	};
	vector<vector<int>> B {
		{ 9, 8 },
		{ 6, 5 },
	};
	vector<vector<int>> C_expected {
		{ 21, 18 },
		{ 66, 57 },
	};

	matrices::matrix_2d C = matrices::multiply_square_dnc(A, B);

	expect_matrices_equal(C, C_expected);
}

TEST(MatrixMultiplySquareDivideAndConquer, NonEmpty3x3Matrices) {
	vector<vector<int>> A {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	vector<vector<int>> B {
		{ 9, 8, 7 },
		{ 6, 5, 4 },
		{ 3, 2, 1 }
	};
	vector<vector<int>> C_expected {
		{ 30,  24,  18 },
		{ 84,  69,  54 },
		{ 138, 114, 90 }
	};


	matrices::matrix_2d C = matrices::multiply_square_dnc(A, B);

	expect_matrices_equal(C, C_expected);
}

TEST(MatrixMultiplySquareDivideAndConquer, NonEmpty4x4Matrices) {
	vector<vector<int>> A {
		{ 1,  2,  3,  4 },
     		{ 5,  6,  7,  8 },
     		{ 9,  10, 11, 12 },
     		{ 13, 14, 15, 16 }
	};
	vector<vector<int>> B {
		{ 17, 18, 19, 20 },
     		{ 21, 22, 23, 24 },
     		{ 25, 26, 27, 28 },
     		{ 29, 30, 31, 32 }
	};
	vector<vector<int>> C_expected {
		{ 250,  260,  270,  280 },
 		{ 618,  644,  670,  696 },
 		{ 986,  1028, 1070, 1112 },
 		{ 1354, 1412, 1470, 1528 }
	};


	matrices::matrix_2d C = matrices::multiply_square_dnc(A, B);

	expect_matrices_equal(C, C_expected);
}
