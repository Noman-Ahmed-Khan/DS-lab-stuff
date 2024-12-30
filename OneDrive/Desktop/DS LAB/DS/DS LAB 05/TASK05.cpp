# include <iostream>

using namespace std;

bool isSafe(int** maze, int i, int j, int mazeSize){
    return (i>-1 && j>-1 && i<mazeSize && j<mazeSize && maze[i][j]==1);
}


bool findPath(int** maze,int** path, int mazeSize,int i=0,int j=0){
    
    if(i==mazeSize-1 && j==mazeSize-1){
        path[i][j]=1;
        return true;
    }

    if(isSafe(maze, i, j, mazeSize)){
        path[i][j]=1;

        //Forward Direction
        if(findPath(maze,path,mazeSize,i,j+1)) return true;
        //Downward Direction
        if(findPath(maze,path,mazeSize,i+1,j)) return true;
        //Backward Direction
        if(findPath(maze,path,mazeSize,i,j-1)) return true;
        //Upward Direction
        if(findPath(maze,path,mazeSize,i-1,j)) return true;

        path[i][j]=0;
        return false;
    }
    return false;
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

    int mazeSize=5;
    int** maze=new int*[mazeSize];
    int** path=new int*[mazeSize];
    for(int i=0; i<mazeSize; i++) {
        maze[i]=new int[mazeSize];
        path[i]=new int[mazeSize];
    }

    int initialMaze[5][5]={{1, 0, 1, 0, 1},
                           {1, 1, 1, 1, 1},
                           {0, 1, 0, 1, 1},
                           {1, 0, 0, 1, 1},
                           {1, 1, 1, 0, 1}};

    for (int i=0; i<mazeSize; i++) {
        for (int j=0; j<mazeSize; j++) {
            maze[i][j]=initialMaze[i][j];
            path[i][j]=0;
        }
    }


    if(findPath(maze,path,mazeSize)){
        cout<<"THE PATH THE LION NAVIGATED TO REACH THE MEAT:"<<endl;
        display(path,mazeSize);
    } else {
        cout<<"NO PATH FOUND";
    }


    for (int i=0; i<mazeSize; i++) {
        delete[] maze[i];
        delete[] path[i];
    }
    delete[] maze;
    delete[] path;

    return 0;
}