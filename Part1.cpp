#include<vector>
#include<iostream>
using namespace std;

int main(){
	
	string board[3][3];
    string input;
    cin>>input;
    int index = 0 ;
    
    
    //Put the string in a 3x3 matrix
    for(int i= 0 ; i < 3 ; i++){
    	for(int j = 0 ; j < 3 ; j++){
    		board[i][j] = input[index];
    		index++;
		}
	}
	
	for (int i = 0 ; i < 3 ; i++){
		for ( int j = 0 ; j < 3 ; j++){
			if(j != 2){
				cout<<board[i][j]+" ";
			}else{
				cout<<board[i][j];
			}		
		}
		if(i != 2){
			cout<<"\n";
		}		
	}
    
	return 0;
}
