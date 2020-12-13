#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    private: 
        int age; 
        string first_name; 
        string last_name; 
        int standard ; 
    public:
        void set_age(int a){
            this->age = a; 
        }
        int get_age(void){
            return this->age ;
        }
        void set_standard(int s){
            this->standard = s; 
        }
        int get_standard(void){
            return this->standard;
        }        
        void set_first_name(string s){
            this->first_name = s; 
        }; 
        string get_first_name( void){
            return this->first_name;
        };
        void set_last_name(string s){
            this->last_name = s; 
        }; 
        string get_last_name( void){
            return this->last_name;
        };
        string to_string(void){
            string s = std::to_string(this->age);
            s += ",";            
            s += this->first_name;
            s += ",";
            s += this->last_name ; 
            s += ","; 

            s += std::to_string(this->standard);
            return s ; 
        };
};
int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
