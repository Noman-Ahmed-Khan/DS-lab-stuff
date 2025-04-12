#include <iostream>

// assuming exam records of 8 subjects is to be managed
#define numberOfSubs 8
using namespace std;

class Exam{
    private:
        string studentName;
        string* examDate;
        float examScore;
        // not asked in question but there should be a exam's subject name 
        string* examName;

    public:
    // Default construcor
    Exam(){
        studentName="Null";
        examDate=new string("Null");
        examName=new string("Null");
        examScore=0.0;
    };
    
    // Parameterized construcor
    Exam(string _studentName,string _examDate,
         string _examName,float _examScore) : studentName(_studentName), examScore(_examScore){
            examDate=new string(_examDate);
            examName=new string(_examName);                                    
        };
    

    // getters/setters
    void setStudentName(string _studentName){
        this->studentName=_studentName;
    }
    string getStudentName(void){
        return studentName;
    }
    
    void setExamDate(string _examDate){
        *examDate=_examDate;
    }
    string getExamDate(void){
        return *examDate;
    }

    void setExamName(string _examName){
        *examName=_examName;
    }
    string getExamName(void){
        return *examName;
    }

    void setExamScore(float examScore){
        this->examScore=examScore;
    }
    float getExamScore(void){
        return examScore;
    }

    // display function
    void displayExamDetails(void){
        cout<<endl<<"Student Name: "<<studentName<<endl;
        cout<<"Exam Date: "<<*examDate<<endl;
        cout<<"Exam Name: "<<*examName<<endl;
        cout<<"Exam Score: "<<examScore<<endl;
    }

    // destructor
    ~Exam(){
        delete examDate;
        delete examName;
    }    
};


int main(){
    // for student 01 
    Exam student01("Ahmed Khan","1-12-24","Mathematics",100);
    Exam student02(student01);
    
    cout<<endl<<"BEFORE ANY MANIPULATION:"<<endl;
    student01.displayExamDetails();
    student02.displayExamDetails();
    
    student01.setExamDate("25-01-25");
    student01.setExamName("English");
    student01.setExamScore(80.5);
    
    
    cout<<endl<<endl<<"AFTER ANY MANIPULATION:"<<endl;
    student01.displayExamDetails();
    student02.displayExamDetails();

    // We can Obsereve that not creating a user define copy constructor for shallow copy creates logical error and on changing the first obj. 
    //Chnages the values of second obj which is the copy of the first obj as both point to the same memory 
    return 0;
}