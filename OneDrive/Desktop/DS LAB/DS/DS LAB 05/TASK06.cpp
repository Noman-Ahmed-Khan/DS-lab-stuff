
# include <iostream>

using namespace std;

bool isSafe(int** grid, int i, int j, int gridSize){
    if(i<0 || j<0 || i>=gridSize || j>=gridSize || grid[i][j]==1) return false;
        
    for(int k=0 ; k<gridSize ; k++){
        if(i+k<gridSize && j+k<gridSize && grid[i+k][j+k]==1) return false;
        if(i+k<gridSize && j-k>-1 && grid[i+k][j-k]==1) return false;
        if(j+k<gridSize && i-k>-1 && grid[i-k][j+k]==1) return false;
        if(j-k>-1 && i-k>-1 && grid[i-k][j-k]==1) return false;
        if(grid[i][k]==1) return false;
        if(grid[k][j]==1) return false;
    }

    return true;
}


bool placeFlag(int** grid, int gridSize, int &flagPlaced, int row=0, int column=0) {
    
    if (row>=gridSize) return true; 
    if (column>=gridSize) return false;

    if (isSafe(grid, row, column, gridSize)) {
        grid[row][column]=1;
        if (placeFlag(grid, gridSize, flagPlaced, row+1, 0)){
            flagPlaced++;
            return true;
        } 
        grid[row][column]=0;
    }

    return placeFlag(grid, gridSize, flagPlaced, row, column+1);
}

void display(int** matrix,int size){
    for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<size ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int gridSize=4;
    int** grid=new int*[gridSize];
    for(int i=0; i<gridSize; i++) {
        grid[i]=new int[gridSize];
    }


    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridSize; j++) {
            grid[i][j]=0;
        }
    }
    int flagPlaced=0;
    if(placeFlag(grid,gridSize,flagPlaced)){
        cout<<"Flag PLACED: "<<flagPlaced<<endl;
        display(grid,gridSize);
    } else{
        cout<<"Flags were not placed";
    }


    for (int i=0; i<gridSize; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}
