#include<vector>
#include<iostream>
using namespace std;

int main(){
	
	string board[3][3];
    string input;
    string action;
    cin>>input;
	int positionSpace =  input.find('#');
        	
	positionSpace =  input.find('#');
	if(positionSpace- 3 >= 0){
		//up
		cout<<"UP\n";
	}
	if(positionSpace+3 < 9){
	 		//down
		cout<<"DOWN\n";
	}
	if(positionSpace%3 > 0){
			//left
		cout<<"LEFT\n";			
	}
	if(positionSpace%3<2){
	 	//right	
		cout<<"RIGHT\n";	
	}
	
	return 0;
}
