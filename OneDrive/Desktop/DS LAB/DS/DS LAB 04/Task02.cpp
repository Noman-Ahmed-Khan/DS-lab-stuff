#include <iostream>
#include <string>

using namespace std;



void swap(int &num01, int &num02){
    int temp=num01;
    num01=num02;
    num02=temp;
}

template<size_t size>
void display(int (&array)[size]){
    cout<<endl<<"[ ";
    for(int num : array){
        cout<<num<<", ";
    }
    cout<<"]"<<endl;
}

int join_date(int year,int month,int date){
    return ((year*10000)+(month*100))+date;
}

int string_to_int(string str_num){
    int int_num=0;
    for (char character : str_num) {
        int_num=int_num*10+(character-'0');
    }
    return int_num;
}
class date{
    private:
        string year;
        string month;
        string day;
        int joined_date;
    public:
        date():year(""),month(""),day(""),joined_date(0){};
        date(string _year, string _month, string _day):year(_year),month(_month),day(_day),joined_date(join_date(string_to_int(_year),string_to_int(_month),string_to_int(_day))){};
        date(string _year, string _month, string _day,int _joined_date):year(_year),month(_month),day(_day),joined_date(_joined_date){};

        void set_year(string year){
            this->year=year;
        }

        void set_month(string month){
            this->month=month;
        }

        void set_day(string day){
            this->day=day;
        }
        
        void set_joined_date(void){
            this->joined_date=join_date(string_to_int(year),string_to_int(month),string_to_int(day));
        }

        string get_year(void){
            return year;
        }

        string get_month(void){
            return month;
        }

        string get_day(void){
            return day;
        }
        
        int get_joined_date(void){
            return joined_date;
        }


        void get_user_intput(void){
            cout<<"Input Year: ";
            cin>>year;
            
            cout<<"Input Month: ";
            cin>>month;            
            
            cout<<"Input day: ";
            cin>>day;
        }

        string get_date(void){
            string comb_date=day+"/"+month+"/"+year;
            return comb_date;
        }

        date& operator = (date obj){
            this->year=obj.year;
            this->month=obj.month;
            this->day=obj.day;
            this->joined_date=obj.joined_date;

            return *this;
        }        
        
};

void swap_date(date &date01, date &date02){
    date temp=date01;
    date01=date02;
    date02=temp;
}


template<size_t size>
void selection_sort(int (&array)[size]){
    for(size_t i=0 ; i<size-1 ; i++){
        int min=i;
        for(size_t j=i+1 ; j<size ; j++){
            if(array[min]>array[j]){
                min=j;
            }
        }
        swap(array[i],array[min]);
    }
}

template<size_t size>
void selection_sort_dates(date (&dates)[size]){
    
    for(size_t i=0 ; i<size-1 ; i++){
        int min=i;
        for(size_t j=i+1 ; j<size ; j++){
            if(dates[min].get_joined_date()>dates[j].get_joined_date()){
                min=j;
            }
        }
        swap_date(dates[i],dates[min]);
    }
}


int main(){
    
    date dates[5];
    int i=0;
    for(date& date : dates){
        system("cls");
        i++;
        cout<<"Input date Date "<<i<<" :"<<endl;
        date.get_user_intput();
        date.set_joined_date();
    }
    system("cls");
    for(date& date : dates){
        cout<<date.get_date()<<endl;
    }
    selection_sort_dates(dates);   
    cout<<endl;
    for(date& date : dates){
        cout<<date.get_date()<<endl;
    }


    return 0;
}