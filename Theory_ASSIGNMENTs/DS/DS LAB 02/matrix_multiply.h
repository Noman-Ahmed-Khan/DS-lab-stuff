#ifndef MATRIX_MULTIPY_H
#define MATRIX_MULTIPY_H

namespace N{
    class matrix_multiply{
        public:

        int** multiply(int** matrix_01,int row_01,int col_01,int** matrix_02,int row_02,int col_02);
        void display(int** matrix,int row,int col);
        int** create_matrix(int row,int col);

    };
}
#endif 