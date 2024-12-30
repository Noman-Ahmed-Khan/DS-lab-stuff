#include <iostream>

#define table_size 5


void insert_value(int* &array,int &size, int value){
    int* temp = new int[size+1];
    for(int i=0 ; i<size ; i++){
        temp[i]=array[i];
    }
    temp[size]=value;
    delete[] array;
    array=temp;
    size++;
}

int join_num(int val_01,int val_02){
    return (val_01*10)+val_02;
}
int break_num(int &val){
    int last_num=val%10;
    val/=10;
    return last_num;
}



using namespace std;

int main(){

    bool friend_table[5][5]={{0,1,0,1,1},
                             {1,0,1,0,1},
                             {0,1,0,0,0},
                             {1,0,0,0,1},
                             {1,1,0,1,0}};

    int common_friend_size=0, no_common_friend_size=0, i=0, j=0, k=0;
    int* common_friend = new int[common_friend_size];
    int* no_common_friend = new int[no_common_friend_size];

    for(i=0 ; i<table_size ; i++){
        
        for(j=i+1 ; j<table_size ; j++){
            bool has_common_friend=false;
            
            for(k=0 ; k<table_size ; k++){
                if(friend_table[i][k] && friend_table[j][k]){
                    insert_value(common_friend,common_friend_size,join_num(join_num(i,j),k));
                    has_common_friend=true;
                }
            }
            
            if(!has_common_friend){
                insert_value(no_common_friend,no_common_friend_size,join_num(i,j));        
            }
        }
        
    }
    cout<<endl;
    for(i=0 ; i<common_friend_size ; i++){
        int value=common_friend[i];
        cout<<"Common friend of "<<break_num(value)<<" and "<<break_num(value)<<" is "<<break_num(value)<<endl;
    }
    cout<<endl;
    for(i=0 ; i<no_common_friend_size ; i++){
        int value=no_common_friend[i];
        cout<<break_num(value)<<" and "<<break_num(value)<<" have no common friends "<<endl;
    }
    
    delete[] common_friend;
    delete[] no_common_friend;

    return 0;
}
