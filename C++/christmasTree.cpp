#include <iostream>
using namespace std;

int main()
{
	for(int i = 1; i <= 5; i++)
	{
        int stars=(i*2)-1;
        int space=6-i;
        for(int j=0; j<space; j++){
            cout <<" ";
        }
        for(int j=0; j<stars; j++){
            cout<<"*";
        }
       cout << endl;
	}
}