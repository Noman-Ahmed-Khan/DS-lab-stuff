#include <iostream>

using namespace std;

void swap_desk(int &desk01, int &desk02){
    int temp=desk01;
    desk01=desk02;
    desk02=temp;
}

template<size_t size>
void display(int (&desks)[size]){
    cout<<endl;
    string designations[6] = {"CEO(Chief Executive Officer)","CTO(Chief Technology Officer)","CFO(Chief Financial Officer)","VP(Vice President)","MGR(Manager)","EMP(Employee)"};
    for(int desk : desks){
        cout<<designations[desk]<<endl;        
    }
    cout<<endl;
}

template<size_t size>
void insertion_sort(int (&desks)[size]){
    for(size_t j=1 ; j<size ; j++){
        int key=desks[j];
        int i=j-1;
        while(i>-1 && desks[i]>key){
            desks[i+1]=desks[i];
            i--;
        }
        desks[i+1]=key;
    }
}




int main(){
    
    int desks[]= {EMP,CFO,MGR,EMP,VP,CTO,MGR,CEO};

    display(desks);
    insertion_sort(desks);
    cout<<"Desks from left to right:";
    display(desks);


    return 0;
}