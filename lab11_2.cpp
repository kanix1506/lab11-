#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	
    int x = rand()%13+1;
    
    return x ;
}

int calScore(int x,int y,int z){
	
	int sum ;
	
	if(x > 10) x=10;
	else if (y > 10) y=10;
	else if (z > 10) z=10;
	
	sum =x+y+z;
	return sum%10;
	
}

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1; 
	else{int m = rand()%100+1;
	if(m > 69) return 2;
	else return 1;
	    
	}
    
}
void checkWinner(int p, int y){
	cout << "\n---------------------------------\n";
	if(p == y)
	cout <<   "|             Draw!!!           |"; 
	if(p > y)
	cout <<   "|         Player wins!!!        |"; 
	if(p < y)
	cout <<   "|          Yugi wins!!!         |"; 
	
	cout << "\n---------------------------------\n";
	
}
int main(){	
    srand(time(0)); 

	int playerScore, YugiScore, playerAction, YugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int YugiCards[3] = {drawCard(), drawCard(), 0}; 
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction!=1 && playerAction!=2); 
	if(playerAction == 1){
	    
		playerCards[2] = drawCard();
        playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[playerCards[2]] <<"\n";
		cout << "Your new score: " << playerScore <<"\n";
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[YugiCards[0]] <<" "<< cardNames[YugiCards[1]] << "\n";
	YugiScore = calScore(YugiCards[0],YugiCards[1],YugiCards[2]);
	cout << "Yugi's score: " << YugiScore << "\n";
	YugiAction = findYugiAction(YugiScore);
	if(YugiAction == 1){
	    
	    YugiCards[2]= drawCard();
        YugiScore = calScore(YugiCards[0],YugiCards[1],YugiCards[2]) ;
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " << cardNames[YugiCards[2]] <<"\n";
		cout << "Yugi's new score: " << YugiScore <<"\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,YugiScore);
}