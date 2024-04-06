#include "matrices.hpp"
#include <vector>

using namespace std;

namespace matrices {

	matrix_2d multiply_square_bruteforce(matrix_2d A, matrix_2d B) {
		// we assume A and B are square
		int n = A.size();
		
		// populate matrix to be returned
		matrix_2d C = vector<vector<int>>(n);
		for (int i = 0; i < n; i++) {
			C[i] = vector<int>(n);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}

		return C;
	}

	matrix_2d multiply_square_dnc(matrix_2d A, matrix_2d B) {
		matrix_2d value = vector<vector<int>>();
		return value;
	}

	matrix_2d multiply_square_strassen(matrix_2d A, matrix_2d B) {
		matrix_2d value = vector<vector<int>>();
		return value;
	}
}
