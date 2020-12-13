#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box {
// The class should have the following functions : 
// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);
    public:
        Box(){this->l = 0; this->b = 0 ; this->h = 0 ; };
        Box(int al, int ab, int ah){this->l = al; this->b = ab ; this->h = ah ;}; 
        Box(Box &RefBox) // copy ctor .. 
        {
            this->l = RefBox.l; 
            this->b = RefBox.b; 
            this->h = RefBox.h; 
        };
// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box    
        int getLength(){
            return this->l; 
        }; 
        int getBreadth(){
            return this->b; 
        }; 
        int getHeight(){
            return this->h; 
        }; 
        long long CalculateVolume(){
            long long l_temp (this->l * this->b);
            l_temp *= this->h; 
            return l_temp;
        };
//Overload operator < as specified
//bool operator<(Box& b)        
    bool operator <(const Box  &RefBox){
            bool l_ret = false; 
            if((this->l < RefBox.l)||
                ((this->b < RefBox.b) && (this->l == RefBox.l))||
                ((this->h < RefBox.h) &&(this->b == RefBox.b)&&(this->l == RefBox.l)))
                {
                    l_ret = true; 
                }
            return l_ret; 
        }
    friend ostream& operator<<(ostream& out, Box& B){
        out<<B.l<<" "<<B.b<<" "<<B.h; 
        return out;
    }; 
    private:
        int l ; 
        int b ; 
        int h ; 
//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}