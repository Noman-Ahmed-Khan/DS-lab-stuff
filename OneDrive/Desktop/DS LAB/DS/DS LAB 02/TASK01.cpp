#include <iostream>

using namespace std;

#define initial_col_size 5
#define second_col_size 10

int main() {

    int row_size;

    cout<<"Input Row Size: ";
    cin>>row_size;


    int **jagged_array=new int*[row_size]; 

    for(int i=0; i<row_size; i++) {
        jagged_array[i]=new int[initial_col_size]; 
        system("cls");
        cout<<"For Row "<<i+1<<" :"<<endl<<endl;
        
        for(int j=0; j<initial_col_size; j++) {
            cout<<"Input Value For Element "<<j+1<<" : ";
            cin>>jagged_array[i][j];
        }
    }

    for(int i=0 ; i<row_size ; i++) {
        int *temp_array=new int[second_col_size];
        for(int j=0; j<second_col_size; j++) {
            temp_array[j]=jagged_array[i][j]; 
        }

        delete[] jagged_array[i]; 
        jagged_array[i]=temp_array;
    }

    for(int i=0; i<row_size; i++) {
        system("cls");
        cout<<"For Row "<<i+1<<" Enter New Element Values: "<<endl<<endl;
        for(int j=initial_col_size; j<second_col_size; j++) { 
            cout<<"Input Value For Element "<<j+1<<" : ";
            cin>>jagged_array[i][j];
        }
    }

    cout<<"Before:"<<endl;
    for(int i=0; i<row_size; i++) {
        for(int j = 0; j<initial_col_size; j++) {
            cout<<jagged_array[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"After:"<<endl;
    for(int i=0; i<row_size; i++) {
        for(int j = 0; j<second_col_size; j++) {
            cout<<jagged_array[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<row_size; i++) {
        delete[] jagged_array[i];
    }
    delete[] jagged_array;
    return 0;
}
