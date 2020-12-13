#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, ToBeRemoved, start, end; 
    cin>>N;     
    vector<int> intVector(N) ; 

    for (int i = 0; i<N; i++)
    {
        cin>>intVector[i]; 
    }
    cin>>ToBeRemoved; 
    cin>>start ; 
    cin>>end; 
    
    vector<int>::iterator itr = intVector.begin() + ToBeRemoved -1 ;
    if (itr != intVector.end())
    {
        intVector.erase(itr); 
    }
    
    intVector.erase(intVector.begin()+start-1, intVector.begin()+end-1); 
    
    cout<<intVector.size()<<endl;
    for (vector<int>::iterator i = intVector.begin(); i != intVector.end(); i++)
    {
        cout<<*i<<' '; 
    }
    return 0;
}
