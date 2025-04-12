
# include <iostream>
# include <cstdlib>
# include <time.h>

using namespace std;

int input_num(void){
    int num;
    cout<<endl<<"ENTER YOUR GUESS: ";
    cin>>num;
    return num;
}

void guess_the_word(int random_num){
    int num=input_num();
    if(num==random_num){
        system("cls");
        cout<<"CONGRATULATIONS CORRECT GUESS "<<num<<endl;
    } else if(num<random_num){
        system("cls");
        cout<<"WRONG GUESS "<<endl<<"THE CURRENT GUESS "<<num<<" IS TO LOW"<<endl; 
        cout<<"PASS TO THE NEXT PLAYER"<<endl;
        guess_the_word(random_num);
    } else{
        system("cls");
        cout<<"WRONG GUESS "<<endl<<"THE CURRENT GUESS "<<num<<" IS TO HIGH"<<endl; 
        cout<<"PASS TO THE NEXT PLAYER"<<endl;
        guess_the_word(random_num);
    } 

}



int main(){

    srand(time(0));
    guess_the_word(rand());


    return 0;
}