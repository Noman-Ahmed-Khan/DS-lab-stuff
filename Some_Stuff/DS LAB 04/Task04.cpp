#include <iostream>

using namespace std;


class Employee {
private:
    string name;
    string designation;
    int age;
    float weight;

public:
    Employee() : name(""), designation(""), age(0), weight(0.0) {}

    Employee(string _name,string _designation, int _age, float _weight)
        : name(_name), designation(_designation), age(_age), weight(_weight) {}

    string get_name(){
        return name;
    }

    void set_name(string name){
        this->name=name;
    }

    string get_designation(){
        return designation;
    }

    void set_designation(string designation){
        this->designation=designation;
    }

    int get_age(){
        return age;
    }

    void set_age(int age) {
        this->age=age;
    }

    float get_weight(){
        return weight;
    }

    void set_weight(float weight) {
        this->weight=weight;
    }

    void display() const {
        cout<<"Name: "<<name<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Weight: "<<weight<<" kg"<<endl;
    }

    Employee& operator = (Employee obj){
        
        this->name=obj.name;
        this->age=obj.age;
        this->designation=obj.designation;
        this->weight=obj.weight;

        return *this;
    }
};

void swap(int &num01, int &num02){
    int temp=num01;
    num01=num02;
    num02=temp;
}


void reverse(int* &arr,int size){
    for(int i=0 ; i<size/2 ; i++){
        swap(arr[i],arr[size-1-i]);
    }
}

int* input_value(int* array, int& size, int value) {
    int* temp=new int[size+1];
    
    for (int i=0; i<size; ++i) {
        temp[i]=array[i];
    }
    
    temp[size]=value;
    size++;

    delete[] array;
    return temp;
}



template<size_t size>
void shell_sort(Employee (&employees)[size]){
    
    int k=1, gap_count=0, gap=1;   
    int* gaps=new int[0];

    while(gap<size){
        gap=(1<<k)-1; 
        if(gap<size) gaps=input_value(gaps,gap_count,gap);
        k++;
    }

    reverse(gaps,gap_count);
    
    for (int i=0; i<gap_count; i++) {
        int gap=gaps[i];
        for (int j=gap; j<size; j++) {
            Employee key=employees[j];
            int res=j;
            while (res>=gap && employees[res-gap].get_weight()>key.get_weight()){
                employees[res]=employees[res-gap];
                res-=gap;
            }
            employees[res]=key;
        }
    }


    delete[] gaps;
}




int main(){

    Employee employees[10] = {
        Employee("Alice", "Manager", 34, 72.0),
        Employee("Bob", "Developer", 29, 65.5),
        Employee("Charlie", "Designer", 31, 68.0),
        Employee("Diana", "Analyst", 27, 70.5),
        Employee("Edward", "Tester", 40, 78.2),
        Employee("Fiona", "Developer", 33, 60.1),
        Employee("George", "Manager", 45, 80.4),
        Employee("Hannah", "Designer", 26, 62.5),
        Employee("Ian", "Analyst", 39, 76.0),
        Employee("Jenna", "Tester", 24, 55.8),
    };

    cout<<"Unsorted Employees"<<endl;
    for(int i=0; i<10; ++i) {
        cout << "Employee " << (i + 1) << ":" << endl;
        employees[i].display();
        cout << endl;
        // cout<<employees[i].get_weight()<<" ";
    }
    cout<<endl<<endl;
    shell_sort(employees);

    cout<<endl<<endl<<"Sorted Employees"<<endl;
    for(int i=0; i<10; ++i) {
        cout << "Employee " << (i + 1) << ":" << endl;
        employees[i].display();
        cout << endl;
        // cout<<employees[i].get_weight()<<" ";
    }


    return 0;
}