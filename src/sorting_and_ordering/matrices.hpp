#ifndef MATRICES_HEADER_HPP
#define MATRICES_HEADER_HPP

#include <vector>
#include <tuple>

namespace matrices {

	typedef std::vector<std::vector<int>> matrix_2d;
	typedef std::tuple<int, int, int, int> submatrix_def;

	matrix_2d multiply_square_bruteforce(matrix_2d A, matrix_2d B);

	matrix_2d multiply_square_dnc(matrix_2d A, matrix_2d B);

	matrix_2d multiply_square_dnc_internal(matrix_2d A, matrix_2d B, submatrix_def sub_matrix_A, submatrix_def sub_matrix_B);

	void print_matrix(matrix_2d A);

	matrix_2d operator+(matrix_2d const& A, matrix_2d const& B);
}

#endif // MATRICES_HEADER_HPP
