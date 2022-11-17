#include<vector>
#include<iostream>
using namespace std;

	string move_up(string puzzle ,int positionSpace){
		string temp = puzzle;
		temp[positionSpace] = temp[positionSpace-3];
		temp[positionSpace-3] = '#';		
		return temp;
	}
	
	string move_down(string puzzle ,int positionSpace){
		string temp = puzzle;
		temp[positionSpace] = temp[positionSpace+3];
		temp[positionSpace+3] = '#';		
		return temp;
	}
	string move_left(string puzzle ,int positionSpace){
		string temp = puzzle;
		temp[positionSpace] = temp[positionSpace-1];
		temp[positionSpace-1] = '#';	
		return temp;
	}
	string move_right(string puzzle ,int positionSpace){
		string temp = puzzle;
		temp[positionSpace] = temp[positionSpace+1];
		temp[positionSpace+1] = '#';
		return temp;
	}
int main(){
	
	string board[3][3];
    string input;
    string action;
    cin>>input;
    cin>>action;
    

	int positionSpace =  input.find('#');
    
    string action_arr[] = {"LEFT", "RIGHT","UP", "DOWN"};                // actions available
    
    	
	if(action_arr[0] == action){
 		
		// left
		input = move_left(input , positionSpace);
	}
	else if(action_arr[1] == action){
		
		// right
		input = move_right(input , positionSpace);			
	}
	else if(action_arr[2] == action){
		
		// up
		input = move_up(input , positionSpace);				
	}
	else{
		
		//down
		input = move_down(input , positionSpace);
			
	}
	
    //Put the string in a 3x3 matrix
    int index = 0;
    for(int i= 0 ; i < 3 ; i++){
    	for(int j = 0 ; j < 3 ; j++){
    		board[i][j] = input[index];
    		index++;
		}
	}
	cout<<to_string(1)+"\n";
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
