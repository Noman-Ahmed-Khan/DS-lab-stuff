/*You are tasked with developing a program to manage and display the Grade Point Average (GPA) for the
core courses offered in the first semester of four departments: Software Engineering (SE), Artificial Intelligence
(AI), Computer Science (CS), and Data Science (DS). Each department offers a distinct number of core courses
for this semester: SE has 3 core courses, AI has 4 core courses, CS has 2 core courses, and DS has 1 core course.
To efficiently store and present this data, which type of array structure would you employ? implement a solution
using the chosen array structure to display the GPAs of the core courses for each department.*/


    //  we will deploy jagged array structure to save the gpa in a single unit.

#include <iostream>

#define total_departments 4
#define SE 3
#define AI 4
#define CS 2
#define DS 1



using namespace std;

int main() {
    
    int departments_courses[total_departments]={SE,AI,CS,DS};
    string departments_name[total_departments]={"SE","AI","CS","DS"};
    float** GPA_dataSet = new float*[total_departments];
    
    for(int i=0 ; i<total_departments ; i++){
        GPA_dataSet[i]=new float[departments_courses[i]];
    }

    float avg_gpa=0.00;

    for(int i=0 ; i<total_departments ; i++){
        system("cls");
        cout<<endl<<"FOR "<<departments_name[i]<<" Course Input Core Results:"<<endl;
        for(int j=0 ; j<departments_courses[i] ; j++){
            cout<<"For Core No. "<<j+1<<" : ";
            cin>>GPA_dataSet[i][j];
        }
    }
    // assuming core courses are worth of 3 credits hours like in fast
    float total=0;
    int total_credts=0;
    for(int i=0 ; i<total_departments ; i++){
        cout<<endl<<"FOR "<<departments_name[i]<<" Course Score:"<<endl;
        total_credts+=departments_courses[i]*3;
        for(int j=0 ; j<departments_courses[i] ; j++){
            cout<<"For Core No. "<<j+1<<" : "<<GPA_dataSet[i][j]<<endl;
            total+=GPA_dataSet[i][j]*3;
        }
    }
    cout<<endl<<endl<<"Total Score: "<<total<<endl;
    cout<<"Total Credits: "<<total_credts<<endl;
    avg_gpa=total/total_credts;
    cout<<"Overal GPA: "<<avg_gpa<<endl;
    return 0;
}
