#include <iostream>
#include "matrix_multiply.cpp"

using namespace std;

int main(){

    matrix_multiply matrix_calculator;

    int** matrix_01=matrix_calculator.create_matrix(5,3);
    int** matrix_02=matrix_calculator.create_matrix(3,5);         
    int** resultant_matrix;
    

    
    resultant_matrix=matrix_calculator.multiply(matrix_01,5,3,matrix_02,3,5);
    

    matrix_calculator.display(resultant_matrix,3,3);


    delete[] matrix_01;
    delete[] matrix_02;
    delete[] resultant_matrix;

    return 0;
}
