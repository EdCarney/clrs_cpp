#ifndef MATRICES_HEADER_HPP
#define MATRICES_HEADER_HPP

#include <vector>

namespace matrices {

	typedef std::vector<std::vector<int>> matrix_2d;

	matrix_2d multiply_square_bruteforce(matrix_2d A, matrix_2d B);

	matrix_2d multiply_square_dnc(matrix_2d A, matrix_2d B);

	matrix_2d multiply_square_strassen(matrix_2d A, matrix_2d B);
}

#endif // MATRICES_HEADER_HPP
