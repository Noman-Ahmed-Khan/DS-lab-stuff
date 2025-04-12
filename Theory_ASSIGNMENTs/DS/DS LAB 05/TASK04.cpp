
# include <iostream>

using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim){
    if (dim<1) return 0;
    int i=0, sum=0;
    sum+=recursiveArraySum(arr, sizes, dim-1);
    for(i=0 ; i<sizes[dim-1] ; i++) sum+=arr[dim-1][i];
    return sum;
}



int main() {
    int* jaggedArray[4];

    int row0[] = {1, 2, 3, 4};
    int row1[] = {1, 2, 3};
    int row2[] = {1, 2, 3, 4, 5, 6, 7};
    int row3[] = {1, 2};

    jaggedArray[0] = row0;
    jaggedArray[1] = row1;
    jaggedArray[2] = row2;
    jaggedArray[3] = row3;

    int sizes[]={4,3,7,2};
    int dim=4;
    cout<<"Sum: "<<recursiveArraySum(jaggedArray,sizes,dim);
    return 0;
}