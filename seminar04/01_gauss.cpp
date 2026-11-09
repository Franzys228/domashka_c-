#include <cmath>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

bool solveGaussian(const std::vector<std::vector<double>>& matrix,
                   const std::vector<double>& rhs,
                   std::vector<double>& solution) {
    const int n = static_cast<int>(matrix.size());
    if (n == 0 || static_cast<int>(rhs.size()) != n) {
        return false;
    }

    std::vector<std::vector<double>> a = matrix;
    std::vector<double> b = rhs;
    std::vector<double> scale(n, 0);
    for (int i = 0; i < n; ++i) {
        if (static_cast<int>(a[i].size()) != n) {
            return false;
        }
        for (double value : a[i]) {
            if (!std::isfinite(value)) {
                return false;
            }
            if (std::abs(value) > scale[i]) {
                scale[i] = std::abs(value);
            }
        }
        if (!std::isfinite(b[i])) {
            return false;
        }
        if (scale[i] == 0) {
            return false;
        }
    }

    const double epsilon =
        std::numeric_limits<double>::epsilon() * n * 64;
    for (int col = 0; col < n; ++col) {
        int pivot = col;
        double best = 0;
        for (int row = col; row < n; ++row) {
            double ratio = std::abs(a[row][col]) / scale[row];
            if (ratio > best) {
                best = ratio;
                pivot = row;
            }
        }
        if (best <= epsilon) {
            return false;
        }

        std::swap(a[col], a[pivot]);
        std::swap(b[col], b[pivot]);
        std::swap(scale[col], scale[pivot]);

        for (int row = col + 1; row < n; ++row) {
            double factor = a[row][col] / a[col][col];
            a[row][col] = 0;
            for (int j = col + 1; j < n; ++j) {
                a[row][j] -= factor * a[col][j];
            }
            b[row] -= factor * b[col];
        }
    }

    solution.assign(n, 0);
    for (int row = n - 1; row >= 0; --row) {
        double value = b[row];
        for (int col = row + 1; col < n; ++col) {
            value -= a[row][col] * solution[col];
        }
        solution[row] = value / a[row][row];
        if (!std::isfinite(solution[row])) {
            solution.clear();
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc > 2) {
        return 1;
    }
    std::ifstream file;
    std::istream* input = &std::cin;
    if (argc == 2) {
        file.open(argv[1]);
        if (!file) {
            std::cerr << "Cannot open input file\n";
            return 1;
        }
        input = &file;
    }

    int n;
    if (!(*input >> n) || n <= 0) {
        std::cerr << "Invalid matrix size\n";
        return 1;
    }
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    std::vector<double> rhs(n);
    for (int i = 0; i < n; ++i) {
        for (double& value : matrix[i]) {
            if (!(*input >> value)) {
                std::cerr << "Invalid matrix data\n";
                return 1;
            }
        }
        if (!(*input >> rhs[i])) {
            std::cerr << "Invalid matrix data\n";
            return 1;
        }
    }

    std::vector<double> solution;
    if (!solveGaussian(matrix, rhs, solution)) {
        std::cout << "No unique solution\n";
        return 0;
    }
    std::cout << std::setprecision(12);
    for (double value : solution) {
        std::cout << value << '\n';
    }
}
