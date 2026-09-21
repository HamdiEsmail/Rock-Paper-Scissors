#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
enum enChoice { Stone = 1, Paper, Sescissors };
enum enWinner { Player1 = 1, Computer, Draw };
struct stRoundInfo {
	enChoice Player1Choice;
	enChoice ComputerChoice;
	enWinner Winner;
	string WhoWinner;
	int roundNumber;


};
struct stGameInfo {
	int PlayerWinTimes;
	int ComputerWinTimes;
	int DrawTimes;
	int AllRound;
	enWinner Winner;
	string WhoIsWinner;



};
int randNumber(int from, int to) {

	return rand() % (to - from + 1) + from;

}
enChoice UserChoice() {
	int number;
	do {
		cout << " your choice : [1]:Stone , [2]:Paper , [3]:Scissors ? ";
		cin >> number;
	} while (number <= 0 || number > 3);
	return enChoice(number);


}
enChoice ComputerChoice() {

	int copmuterChoice = randNumber(1, 3);
	return enChoice(copmuterChoice);

}
enWinner WhoTheWinner(enChoice userChoice, enChoice ComputerChoice) {
	if (userChoice == ComputerChoice) {

		return enWinner::Draw;
	}
	else {

		switch (userChoice) {


		case enChoice::Paper:
			if (ComputerChoice == enChoice::Sescissors) {

				return enWinner::Computer;
			}
			break;
		case enChoice::Stone:
			if (ComputerChoice == enChoice::Paper) {

				return enWinner::Computer;

			}
			break;
		case enChoice::Sescissors:
			if (ComputerChoice == enChoice::Stone) {
				return enWinner::Computer;
			}break;







		}


		return enWinner::Player1;


	}





}
void SetScreenColor(enWinner winnerName) {
	if (winnerName == enWinner::Computer) {
		system("color 4f");
		cout << "\a";
	}
	else if (winnerName == enWinner::Player1) {
		system("color 2f");

	}
	else {
		system("color 6f");
	}

}
string Tap(int number) {

	string t = "";
	for (int i = 0;i < number;i++) {

		t += "\t";


	}
	return t;


}
void GameOver() {

	cout << Tap(3) << "__________________________________________________________________________\n";
	cout << Tap(6) << "+++ Game Over +++" << endl;
	cout << Tap(3) << "__________________________________________________________________________\n";



}
void GameResults(stGameInfo gameInfo) {


	cout << Tap(3) << "____________________________[ Game Results ]____________________________\n";
	cout << Tap(3) << "Game Rounds : " << gameInfo.AllRound << endl;
	cout << Tap(3) << "Player Won times :" << gameInfo.PlayerWinTimes << endl;
	cout << Tap(3) << "Computer Won times :" << gameInfo.ComputerWinTimes << endl;
	cout << Tap(3) << "Draw Times : " << gameInfo.DrawTimes << endl;
	cout << Tap(3) << "Final Winner : " << gameInfo.WhoIsWinner << endl;
	cout << Tap(3) << "\n__________________________________________________________________________\n";

}
int readRound() {
	int number;
	do {

		cout << "enter number from 1 to 10 : ";
		cin >> number;


	} while (number <= 0 || number > 10);
	return number;
}
string ConvertChoice(enChoice choice) {

	string ourChoiceies[3] = { "Stone","Paper","Sescissors" };
	return ourChoiceies[choice - 1];

}
string ConvertWinner(enWinner winner) {

	string Ourwinner[3] = { "player1","computer","Draw" };
	return Ourwinner[winner - 1];

}
void StartGame() {
	char Play = 'Y';
	do {
		system("cls");
		int round = readRound();
		int Player1WinTimes = 0, ComputerWinTime = 0, DrawTimes = 0;
		for (int i = 1;i <= round;i++) {
			cout << "\nRound [" << i << "] begins : \n";
			enChoice userCh = UserChoice();
			stRoundInfo CurrRound;
			CurrRound.ComputerChoice = ComputerChoice();
			CurrRound.Player1Choice = userCh;
			CurrRound.Winner = WhoTheWinner(CurrRound.Player1Choice, CurrRound.ComputerChoice);
			CurrRound.roundNumber = i;
			CurrRound.WhoWinner = ConvertWinner(CurrRound.Winner);
			SetScreenColor(CurrRound.Winner);
			cout << "\n__________Round [" << i << "] _______________\n";
			cout << "Player1 Choice : " << ConvertChoice(CurrRound.Player1Choice) << endl;
			cout << "Computer Choice : " << ConvertChoice(CurrRound.ComputerChoice) << endl;
			cout << "Round Winner : " << "[" << CurrRound.WhoWinner << "]\n";
			if (CurrRound.Winner == enWinner::Player1) {

				Player1WinTimes++;
			}
			else if (CurrRound.Winner == enWinner::Computer) {

				ComputerWinTime++;
			}
			else { DrawTimes++; }
		}
		stGameInfo FullGame;
		FullGame.AllRound = round;
		FullGame.ComputerWinTimes = ComputerWinTime;
		FullGame.DrawTimes = DrawTimes;
		FullGame.PlayerWinTimes = Player1WinTimes;
		if (FullGame.ComputerWinTimes > FullGame.PlayerWinTimes) {

			FullGame.Winner = enWinner::Computer;
		}
		else if (FullGame.PlayerWinTimes > FullGame.ComputerWinTimes) {
			FullGame.Winner = enWinner::Player1;


		}
		else {
			FullGame.Winner = enWinner::Draw;

		}

		FullGame.WhoIsWinner = ConvertWinner(FullGame.Winner);
		GameOver();
		GameResults(FullGame);
		cout << endl;
		cout << "\nDo You want Play Again? (Y/N) ";
		cin >> Play;



	} while (Play == 'Y' || Play == 'y');


}




int main() {
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}