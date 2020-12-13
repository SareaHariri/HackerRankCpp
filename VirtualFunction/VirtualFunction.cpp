#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int NumberOfProf = 0 ; 
int NumberOfStd = 0; 
class Person{
private: 
public:
    char name[100]; 
    int age; 
    virtual void getdata(void){}
    virtual void putdata(void){}
}; 
class Professor:public Person{
private:
    int publications; 
    int ID;  
public:
    Professor(){
        NumberOfProf++; 
        ID = NumberOfProf; 
    }
    void getdata(){
        cin>>name>>age; 
        cin>>publications;
    }
    void putdata(void){
        cout<<name<<" "<<age<<" "<<publications<<" "<<ID<<endl; 
    }
};
class Student:public Person{
private:
    int marks[6];
    int ID;   
public:
    Student(){
        NumberOfStd++; 
        ID = NumberOfStd; 
    }
    void getdata(){
        cin>>name>>age; 
        for (int i =0; i<6; i++)
        {
            cin>>marks[i]; 
        }
    }
    void putdata(void){
        long int sum = 0 ; 
        cout<<name<<" "<<age<<" ";
        for (int i =0; i<6; i++)
        {
            sum  +=marks[i];  
        }
        cout<<sum<<" "; 
        cout<<ID<<endl; 
    }
};
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
