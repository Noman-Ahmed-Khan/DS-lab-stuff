#include <iostream>

using namespace std;

int main(){
    int num_of_rows,seats;

    cout<<"Enter Number Of Row: ";
    cin>>num_of_rows;

    system("cls");
    string** conference_hall = new string*[num_of_rows];
    int num_of_seats[num_of_rows];
    for(int i=0 ; i<num_of_rows ; i++){
        cout<<"For Row "<<i+1<<", Input Number Of Seats:";
        cin>>seats;
        conference_hall[i]=new string[seats];
        num_of_seats[i]=seats;
    }
    for(int i=0 ; i<num_of_rows ; i++){
        system("cls");
        cout<<"Input Attendee's Name:"<<endl<<endl;        
        for(int j=0 ; j<num_of_seats[i] ; j++){
            cout<<"Row: "<<i+1<<", Seat: "<<j+1<<endl<<"Input Name: ";
            cin>>conference_hall[i][j];
        }
    }

    system("cls");
    cout<<"Attendee's Name:"<<endl<<endl;    
    for(int i=0 ; i<num_of_rows ; i++){
        for(int j=0 ; j<num_of_seats[i] ; j++){
            cout<<"Row: "<<i+1<<", Seat: "<<j+1<<", Name: "<<conference_hall[i][j]<<endl;
        }
        cout<<endl;
    }

    

    return 0;
}
