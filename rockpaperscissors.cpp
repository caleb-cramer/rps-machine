#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


void whoWon(string x, string y, int &wins, int &ties, int &losses){
	if (x==y){
		cout<<"It's a tie\n";
		ties+=1;
	}
	else if (x == "r" && y == "p"){
		cout<<"You lost!\n";
		losses+=1;
	}
	else if (x == "r" && y == "s"){
		cout<<"You won!\n";
		wins++;
	}
	else if (x == "p" && y == "s"){
		cout<<"You won!\n";
		wins++;
	}
	else if (x == "p" && y == "r"){
		cout<<"You lost!\n";
		losses+=1;
	}
	else if (x == "s" && y == "p"){
		cout<<"You won!\n";
		wins++;
	}
	else if (x == "s" && y == "r"){
		cout<<"You lost!\n";
		losses+=1;
	}
	else
		cout<<"something went wrong...\n";
}

string machineChoice(string lastchoice, int flag){
	string choices[3] = {"r","p","s"};
	if(flag==1) {

		for (int i = 4; i < 7; i++)
		{
			if (lastchoice==choices[i%4]){
				cout<<"made1";
				return choices[i%3];
			}
		}
	}
	return choices[rand()%3];
}
//checks to see for two same throws in a row
int twoinaRow(string prevch, string userch){
	if (prevch==userch){
		return 1;
	}
	else{
		return 0;
	}
}

int main()
{
	cout<< "This is a simple rock paper scissors machine. It is inspired by a book called Rock Breaks Scissors.\nAll you have to do to play is enter r for rock, p for paper, or s for scissors.\
	Easy as that. There is no cheating, the machine picks its guess before asking for your's.\nLet's play 15 games and see how we do. "; 
	string machchoice = "p";
	srand(time(0));
	string userchoice;
	int numwins=0;
	int numties=0;
	int numlosses=0;
	int twoinarowFlag=0;
	string lastChoice="";
	string doublelastChoice="";
	int n = 14;
	while (n>=0){
		cout<<"Rock Paper Scissors Shoot... ";
		cin>>userchoice;
		cout<<"You chose " <<userchoice << " and the machine chose " <<machchoice<<endl;
		whoWon(userchoice,machchoice, numwins,numties,numlosses);
		machchoice=machineChoice(lastChoice,twoinaRow(lastChoice,doublelastChoice));
		n-=1;

		
		doublelastChoice=lastChoice;
		lastChoice=userchoice;
	}

	cout<<"You lost "<<numlosses<<" times, tied "<<numties<<" times, and won "<<numwins<<endl;
	double percentwon=(double)numwins/(15-numties)*100;
	cout<<"You won "<<numwins<<" games which is "<<percentwon<<"% of the games."<<endl;

	return 0;
}