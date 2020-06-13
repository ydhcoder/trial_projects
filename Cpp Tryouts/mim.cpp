#include <iostream>
using namespace std;
int main()
{
	int count=0;
	int num[100];
	for (int i=1; i<=3; i++){
		cin>>num[i];
	}
	for (int j=0; j<=3; j++){
		
		if(num[j]>50){
			cout<<num[j]<<" ";
			cout<<count;
			count++;
		}
		
	}
	return 0;
}
