#include "matrices.hpp"
#include <cstdio>
#include <vector>
#include <tuple>

using namespace std;

namespace matrices {

	// Calculates the product of two matrices using brute force looping
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

	// Calculates the product of two matrices using recursive divide-and-conquer
	matrix_2d multiply_square_dnc(matrix_2d A, matrix_2d B) {
		// assume square
		int n_in = A.size();
		int n_out = 1;

		// determine next highest power of 2 for n_out
		while (n_in > n_out) {
			n_out *= 2;
		}

		submatrix_def sub_matrix = make_tuple(0, 0, n_out - 1, n_out - 1);

		// add buffer if input matrices are not a power of two
		if (n_in == n_out) {
			return multiply_square_dnc_internal(A, B, sub_matrix, sub_matrix);
		} else {
			
			// create matrices with buffer columns/rows (full of zeros)
			matrix_2d A_buffered = vector<vector<int>>(n_out);
			matrix_2d B_buffered = vector<vector<int>>(n_out);
			for (int i = 0; i < n_out; i++) {
				A_buffered[i] = vector<int>(n_out);
				B_buffered[i] = vector<int>(n_out);
			}

			// copy over data from input matrices
			for (int i = 0; i < n_in; i++) {
				for (int j = 0; j < n_in; j++) {
					A_buffered[i][j] = A[i][j];
					B_buffered[i][j] = B[i][j];
				}
			}

			// get output; will include buffered columns/rows
			matrix_2d C_buffered = multiply_square_dnc_internal(A_buffered, B_buffered, sub_matrix, sub_matrix);

			// copy over relevant data for output	
			matrix_2d C = vector<vector<int>>(n_in);
			for (int i = 0; i < n_in; i++) {
				C[i] = vector<int>(n_in);
				for (int j = 0; j < n_in; j++) {
					C[i][j] = C_buffered[i][j];
				}
			}
			return C;
		}

	}

	matrix_2d operator+(matrix_2d const& A, matrix_2d const& B) {
		// assume matrices are same size
		int rows = A.size();
		if (rows == 0) {
			return vector<vector<int>>();
		}

		int cols = A[0].size();
		matrix_2d C = vector<vector<int>>(rows);

		for (int i = 0; i < rows; i++) {
			C[i] = vector<int>(cols);
			for (int j = 0; j < cols; j++) {
				C[i][j] = A[i][j] + B[i][j];
			}
		}
		return C;
	}

	matrix_2d multiply_square_dnc_internal(matrix_2d A, matrix_2d B, submatrix_def sub_matrix_A, submatrix_def sub_matrix_B) {
		int start_row_A, start_col_A, end_row_A, end_col_A;
		int start_row_B, start_col_B, end_row_B, end_col_B;
		std::tie(start_row_A, start_col_A, end_row_A, end_col_A) = sub_matrix_A;
		std::tie(start_row_B, start_col_B, end_row_B, end_col_B) = sub_matrix_B;
	
		int n = end_row_A - start_row_A + 1;

		matrix_2d C = vector<vector<int>>(n);
		for (int i = 0; i < n; i++) {
			C[i] = vector<int>(n);
		}
		
		if (n == 1) {
			C[0][0] = A[start_row_A][start_col_A] * B[start_row_B][start_col_B];
			return C;
		}
	
		int n_half = n / 2;
	
		submatrix_def def_A11 = std::make_tuple(start_row_A,          start_col_A,          start_row_A + n_half - 1, start_col_A + n_half - 1);
		submatrix_def def_A12 = std::make_tuple(start_row_A,          start_col_A + n_half, start_row_A + n_half - 1, end_col_A);
		submatrix_def def_A21 = std::make_tuple(start_row_A + n_half, start_col_A,          end_row_A,                start_col_A + n_half - 1);
		submatrix_def def_A22 = std::make_tuple(start_row_A + n_half, start_col_A + n_half, end_row_A,                end_col_A);
		submatrix_def def_B11 = std::make_tuple(start_row_B,          start_col_B,          start_row_B + n_half - 1, start_col_B + n_half - 1);
		submatrix_def def_B12 = std::make_tuple(start_row_B,          start_col_B + n_half, start_row_B + n_half - 1, end_col_B);
		submatrix_def def_B21 = std::make_tuple(start_row_B + n_half, start_col_B,          end_row_B,                start_col_B + n_half - 1);
		submatrix_def def_B22 = std::make_tuple(start_row_B + n_half, start_col_B + n_half, end_row_B,                end_col_B);

		matrix_2d C_11 = multiply_square_dnc_internal(A, B, def_A11, def_B11) + multiply_square_dnc_internal(A, B, def_A12, def_B21);
		matrix_2d C_12 = multiply_square_dnc_internal(A, B, def_A11, def_B12) + multiply_square_dnc_internal(A, B, def_A12, def_B22);
		matrix_2d C_21 = multiply_square_dnc_internal(A, B, def_A21, def_B11) + multiply_square_dnc_internal(A, B, def_A22, def_B21);
		matrix_2d C_22 = multiply_square_dnc_internal(A, B, def_A21, def_B12) + multiply_square_dnc_internal(A, B, def_A22, def_B22);
	
		for (int i = 0; i < n_half; i++) {
			for (int j = 0; j < n_half; j++) {
				C[i][j] = C_11[i][j];
				C[i][j + n_half] = C_12[i][j];
				C[i + n_half][j] = C_21[i][j];
				C[i + n_half][j + n_half] = C_22[i][j];
			}
		}
	
		return C;
	}

	void print_matrix(matrix_2d A) {
		int rows = A.size();
		int cols = A[0].size();

		printf("{\n");
		for (int i = 0; i < rows; i++) {
			printf("    { ");
			for (int j = 0; j < cols; j++) {
				printf("%d, ", A[i][j]);
			}
			printf("},\n");
		}
	}

}
