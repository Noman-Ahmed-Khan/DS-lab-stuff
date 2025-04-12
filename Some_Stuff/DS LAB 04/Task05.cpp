#include <iostream>

using namespace std;

void swap(float &num01, float &num02){
    int temp=num01;
    num01=num02;
    num02=temp;
}

template<size_t size>
void display(float (&array)[size]){
    cout<<endl<<"[ ";
    for(float num : array){
        cout<<num<<", ";
    }
    cout<<"]"<<endl;
}

template<size_t size>
void comb_sort(float (&list)[size]){
    float shrink=10;
    int gap=size;
    bool swapped=true;

    while(gap>1 || swapped){
        gap = int(gap/shrink);
        if(gap<1) gap=1;

        swapped=false;

        for(int i=0 ; i+gap<size ; i++){
            if(list[i]>list[i+gap]){
                swap(list[i],list[i+gap]);
                swapped=true;
            }
        }
    }
}



int main(){
    
    float price_list[10]= {5.2,112.3,33.53,60.9,210.33,93.4,741.,444.4,853.3,10.01};

    display(price_list);
    comb_sort(price_list);
    display(price_list);


    return 0;
}