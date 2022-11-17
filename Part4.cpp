#include<vector>
#include<typeinfo>
#include<algorithm>
#include<list>
#include<iostream>
using namespace std;

// a class for an instance of a  board
class board{
	public:
        string config;
        board *childUp;
        board *childDown;
        board *childLeft;
        board *childRight;
        
        board *parent;
        
        board(string config ){
        	this->config =  config;
		}    

};
    
		
	// check if the current board is the correct configuration(goal)
	bool is_goal(string config, string goal){
         return (config==goal);		
	}
	
	void search(){
		
	}
	


int main(){
	string puzzle, temp ; 
	board *currentNode , *node;
	bool *valid_moves;
	int positionSpace;
	list<board*> frontier;
	vector<string> visited;
				
	board *parent =new board("1857#3462");          //initialize root
	parent->parent = NULL;
	string goal = "78651432#";                   // destination                 // destination

	frontier.push_back(parent);
	if(!is_goal(parent->config , goal)){
		while(!frontier.empty()){
			
			currentNode = frontier.front();
			puzzle = currentNode->config;
			visited.push_back(puzzle);
			frontier.pop_front();
					
	
			positionSpace =  puzzle.find('#');
			if(positionSpace- 3 >= 0){
					//up
				temp = puzzle;
				temp[positionSpace] = temp[positionSpace-3];
				temp[positionSpace-3] = '#';	
				if(is_goal(temp , goal) ){
					cout<<"goal found\n";
					break;
				}			
				if(!(find(visited.begin(), visited.end(), temp) != visited.end())){
					frontier.push_back(currentNode->childUp = new board(temp));
	                currentNode->childUp->parent = currentNode;
				}
	
				
			}
			if(positionSpace+3 < 9){
			 		//down
				temp = puzzle;
				temp[positionSpace] = temp[positionSpace+3];
				temp[positionSpace+3] = '#';		
				if(is_goal(temp , goal) ){
					cout<<"goal found\n";
					break;
				}			
				if(!(find(visited.begin(), visited.end(), temp) != visited.end())){
					frontier.push_back(currentNode->childDown = new board(temp));
	                currentNode->childDown->parent = currentNode;			
				}
	
			}
			if(positionSpace%3 > 0){
					//left
				temp = puzzle;
				temp[positionSpace] = temp[positionSpace-1];
				temp[positionSpace-1] = '#';			
				if(is_goal(temp , goal) ){
					cout<<"goal found\n";
					break;
				}			
				if(!(find(visited.begin(), visited.end(), temp) != visited.end())){
					frontier.push_back(currentNode->childLeft = new board(temp));
	                currentNode->childLeft->parent = currentNode;						
				}			
			}
			if(positionSpace%3<2){
			 	//right
				temp = puzzle;
				temp[positionSpace] = temp[positionSpace+1];
				temp[positionSpace+1] = '#';
					
				if(is_goal(temp , goal) ){
					cout<<"goal found\n";
					break;
				}			
				if(!(find(visited.begin(), visited.end(), temp) != visited.end())){			
					frontier.push_back(currentNode->childRight = new board(temp));
	                currentNode->childRight->parent = currentNode;
								
				}		
			}
		
		}		
	}	

	int count = 1;
    while(currentNode->parent != NULL){
    	
 		count++;
		currentNode = currentNode->parent;   	
	}
 	cout<<"Cost :"+to_string(count)+"\n";		
			
			

	
	

    delete parent , valid_moves;
    
	return 0;
}


