#include <iostream>
#include "matrix_multiply.h"

using namespace  N;
using namespace  std;

    int** matrix_multiply::multiply(int** matrix_01,int row_01,int col_01,int** matrix_02,int row_02,int col_02){
        
        system("cls");
        // cout<<row_01<<" "<<col_01<<" "<<row_02<<" "<<col_02;



        if(col_01!=row_02){
            throw("ERROR: Matix Can Not Be Multiplied");
        }

        int** resultant_matrix = new int*[row_01];
        for(int i=0 ; i<row_01 ; i++){
            resultant_matrix[i]=new int[col_02];
            for(int j=0; j<col_02; j++) {
                resultant_matrix[i][j]=0;
            }
        }
        
        for (int i=0; i<row_01; i++) {
            for (int j=0; j<col_02; j++) {
                for (int k=0; k<col_01; k++) {
                resultant_matrix[i][j] += (matrix_01[i][k] * matrix_02[k][j]);
            }
        }
    }

        
        return resultant_matrix;
    }


    void matrix_multiply::display(int** matrix,int row,int col){
        // system("cls");
        for(int i=0 ; i<row ; i++){
            cout<<endl;
            for(int j=0 ; j<col ; j++){
                cout<<matrix[i][j]<<" ";
            }
        }

    }


    int** matrix_multiply::create_matrix(int row,int col){

        int **matrix=new int*[row]; 

        for(int i=0; i<row; i++) {
            matrix[i]=new int[col]; 
            system("cls");
            cout<<"For Row "<<i+1<<" :"<<endl<<endl;
            
            for(int j=0; j<col; j++) {
                cout<<"Input Value For Element "<<j+1<<" : ";
                cin>>matrix[i][j];
            }
        }

        return matrix;

    }