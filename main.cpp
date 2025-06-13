#include <SFML/Graphics.hpp>
#include<SFML\Audio.hpp>
#include <iostream>
#include <fstream>
#include "CricBuzz.h"
#include <Windows.h>
#include <string>
using namespace std;
using namespace sf;
int main() {
	bool invalid = false, enter = false, stop = false;
	int choice;
	char chr;
	int c2, c3;
	fstream writeFile;
	ifstream readFile;
	string email, password, temp;
	bool logged = false;
	Team teamObj;
	Player playerObj;
	Match matchObj;
	News newsObj;
	ifstream read;
	ifstream readTeamRankings;
	RenderWindow window(VideoMode(650, 900), "Cric Buzz");
	Font font;
	if (!font.loadFromFile("OpenSans-Bold.ttf"))
	{
		cout << "file not found!\n";
	}
	Music sound;
	if (!sound.openFromFile("Y2Mate.ogg"))
	{
		cout << "file not found!\n";
	}
	RectangleShape sound_Button(Vector2f(650.0f, 900.0f));
	sound_Button.setPosition(0.0, 0.0);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("Login.png");
	sound_Button.setTexture(&sound_ButtonTexture);
	RectangleShape starter(Vector2f(650.0f, 900.0f));
	starter.setPosition(0.0, 0.0);
	Texture starter_texture;
	starter_texture.loadFromFile("starter.png");
	starter.setTexture(&starter_texture);
	RectangleShape pic3(Vector2f(650.0f, 900.0f));
	pic3.setPosition(0.0, 0.0);
	Texture pic3_texture;
	pic3_texture.loadFromFile("Signup.png");
	pic3.setTexture(&pic3_texture);
	RectangleShape classMenu(Vector2f(650.0f, 900.0f));
	classMenu.setPosition(0.0, 0.0);
	Texture classMenu_texture;
	classMenu_texture.loadFromFile("Class Menu.png");
	classMenu.setTexture(&classMenu_texture);
	RectangleShape teamMenu(Vector2f(650.0f, 900.0f));
	teamMenu.setPosition(0.0, 0.0);
	Texture teamMenu_texture;
	teamMenu_texture.loadFromFile("team menu2.png");
	teamMenu.setTexture(&teamMenu_texture);
	RectangleShape teamPk(Vector2f(650.0f, 900.0f));
	teamPk.setPosition(0.0, 0.0);
	Texture teamPk_texture;
	teamPk_texture.loadFromFile("Pakistan.png");
	teamPk.setTexture(&teamPk_texture);
	RectangleShape teamInd(Vector2f(650.0f, 900.0f));
	teamInd.setPosition(0.0, 0.0);
	Texture teamInd_texture;
	teamInd_texture.loadFromFile("India.png");
	teamInd.setTexture(&teamInd_texture);
	RectangleShape teamEng(Vector2f(650.0f, 900.0f));
	teamEng.setPosition(0.0, 0.0);
	Texture teamEng_texture;
	teamEng_texture.loadFromFile("England.png");
	teamEng.setTexture(&teamEng_texture); 
	RectangleShape teamNz(Vector2f(650.0f, 900.0f));
	teamNz.setPosition(0.0, 0.0);
	Texture teamNz_texture;
	teamNz_texture.loadFromFile("New Zealand.png");
	teamNz.setTexture(&teamNz_texture); 
	RectangleShape teamBan(Vector2f(650.0f, 900.0f));
	teamBan.setPosition(0.0, 0.0);
	Texture teamBan_texture;
	teamBan_texture.loadFromFile("Bangladesh.png");
	teamBan.setTexture(&teamBan_texture);
	RectangleShape teamRankings(Vector2f(650.0f, 900.0f));
	teamRankings.setPosition(0.0, 0.0);
	Texture teamRankings_texture;
	teamRankings_texture.loadFromFile("team rankings.png");
	teamRankings.setTexture(&teamRankings_texture);
	RectangleShape recNews(Vector2f(650.0f, 900.0f));
	recNews.setPosition(0.0, 0.0);
	Texture recNews_texture;
	recNews_texture.loadFromFile("recNews.png");
	recNews.setTexture(&recNews_texture);
	RectangleShape UpNews(Vector2f(650.0f, 900.0f));
	UpNews.setPosition(0.0, 0.0);
	Texture UpNews_texture;
	UpNews_texture.loadFromFile("UpNews.png");
	UpNews.setTexture(&UpNews_texture);
	RectangleShape playerNews(Vector2f(650.0f, 900.0f));
	playerNews.setPosition(0.0, 0.0);
	Texture playerNews_texture;
	playerNews_texture.loadFromFile("playerNews.png");
	playerNews.setTexture(&playerNews_texture);
	RectangleShape RankingsNews(Vector2f(650.0f, 900.0f));
	RankingsNews.setPosition(0.0, 0.0);
	Texture RankingsNews_texture;
	RankingsNews_texture.loadFromFile("RankingsNews.png");
	RankingsNews.setTexture(&RankingsNews_texture);
	RectangleShape f2Menu(Vector2f(650.0f, 900.0f));
	f2Menu.setPosition(0.0, 0.0);
	Texture f2Menu_texture;
	f2Menu_texture.loadFromFile("F2 menu.png");
	f2Menu.setTexture(&f2Menu_texture);
	RectangleShape newsMenu(Vector2f(650.0f, 900.0f));
	newsMenu.setPosition(0.0, 0.0);
	Texture newsMenu_texture;
	newsMenu_texture.loadFromFile("News Menu.png");
	newsMenu.setTexture(&newsMenu_texture);
	RectangleShape liveMatch(Vector2f(650.0f, 900.0f));
	liveMatch.setPosition(0.0, 0.0);
	Texture liveMatch_texture;
	liveMatch_texture.loadFromFile("Live Match.png");
	liveMatch.setTexture(&liveMatch_texture);
	printf("\033[1;32m");
	cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_* C R I C\tB U Z Z *_*_*_*_*_*_*_*_*_*_*_*_*_*\n"; //
	cout << "Login\tPress 1\nSignUp\tPress 2\n:";
	cin >> choice;
	cout << endl;
	printf("\033[0m");
	try
	{
		switch (choice)
		{
		case 1:
			printf("\033[1;31m");
			cout << "Enter your email: ";
			cin >> email;
			cout << "Enter password: ";
			cin >> password;
			printf("\033[1;33m");
			loading();
			readFile.open("Emails and Passwords.txt");
			while (!readFile.eof() && !logged) {
				readFile >> temp;
				if (email == temp) {
					readFile >> temp;
					if (password == temp) {
						cout << "Logged in!\n";
						logged = true;
						enter = true;
					}
				}
			}
			if (!logged)
				cout << "Incorrect email or password\n";
			break;
		case 2:
			writeFile.open("Emails and Passwords.txt", ios::app);
			cout << "Enter your email: ";
			cin >> email;
			cout << "Enter your password: ";
			cin >> password;
			writeFile << email << endl << password << endl;
			cout << "Your account has been signed up!\n";
			enter = true;
			writeFile.close();
			break;
		default:
			cout << "Invalid Entry!\n";
			invalid = true;
			throw 'a';
			break;
		}//
		if (enter) {
			while (enter)
			{
				printf("\033[1;34m");
				cout << "On which class do you want to work?\nTeam\tPress 1\nPlayer\tPress 2\nMatches\tPress 3\nNews\tPress 4\n: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					printf("\033[1;35m");
					cout << "Update Captain\tPress 1\nUpdate Coach\tPress 2\nDisplay Matches\tPress 3\nDisplay Team\tPress 4\n: ";
					cin >> c2;
					switch (c2)
					{
					case 1:
						teamObj.updateCaptain();
						break;
					case 2:
						teamObj.updateCoach();
						break;
					case 3:
						teamObj.displayMatches();
						break;
					case 4:
						teamObj.displayTeam();
						break;
					default:
						cout << "Invalid Entry\n";
						throw 'a';
						break;
					}
					break;
				case 2:
					printf("\033[1;36m");
					cout << "Add Player\tPress 1\nRemove Player\tPress 2\nUpdate Player\tPress 3\n: ";
					cin >> c2;
					switch (c2)
					{
					case 1:
						playerObj.addPlayer();
						break;
					case 2:
						playerObj.removePlayer();
						break;
					case 3:
						playerObj.updatePlayer();
						break;
					default:
						cout << "Invalid Entry\n";
						throw 'a';
						break;
					}
					break;
				case 3:
					printf("\033[1;37m");
					cout << "Conduct Matches\tPress 1\nSchedule Matches\tPress 2\nUpdate WorldRecord\tPress 3\nUpdate TeamRankings\tPress 4\nUpdate PlayerRankings\tPress 5\nDisplay UpcomingMatches\tPress 6\nDisplay Recentmatches\tPress 7\n: ";
					cin >> c2;
					switch (c2)
					{
					case 1:
						matchObj.conductMatch();
						break;
					case 2:
						matchObj.scheduleMatch();
						break;
					case 3:
						matchObj.updateWorldRecords();
						break;
					case 4:
						matchObj.updateTeamRanking();
						break;
					case 5:
						matchObj.updatePlayerRanking();
						break;
					case 6:
						matchObj.displayUpcomingMatches();
						break;
					case 7:
						matchObj.displayRecentMatches();
						break;
					default:
						cout << "Invalid Entry\n";
						throw 'a';
						break;
					}
					break;
				case 4:
					printf("\033[1;31m");
					cout << "What kind of news do you want to see?\nNews about Previous Match\tPress 1\nNews about Upcoming Match\tPress 2\nNews about Team Rankings\tPress 3\nNews about Players Rankings\tPress 4\n: ";
					cin >> c2;
					switch (c2)
					{
					case 1:
						newsObj.newsOfprevMatch();
						break;
					case 2:
						newsObj.newsOfUpcomMatch();
						break;
					case 3:
						newsObj.teamRankings();
						break;
					case 4:
						newsObj.playerRankings();
						break;
					default:
						throw 'a';
						cout << "Invalid Entry\n";
						break;
					}
					break;
				default:
					cout << "Invalid Entry\n";
					throw 'a';
					break;
				}
				printf("\033[1;32m");
				cout << "Press 's' to quit the program, else enter any character!\n";
				cin >> chr;
				system("cls");
				if (chr == 's') {
					enter = false;
				}
			}
		}
	}
	catch (char chr) {
		cout << "Exception can also be handled if you enter character or string!\n";
	}
	if (!invalid) {
		printf("\033[1;33m");
		cout << "Time to view this app Graphically!\nPlease Enter Right Shift to start the app: ";
		Sleep(1000);
		read.open("teams and players.txt");
		string str[8][15];
		for (int i = 0; !read.eof() && i < 8; i++) {
			for (int j = 0; j < 15; j++) {
				getline(read, str[i][j]);
			}
		}
		read.close();
		Text players[8][15];
		int y;
		for (int i = 0; i < 8; i++) {
			y = 150;
			for (int j = 0; j < 15; j++) {
				players[i][j].setFont(font);
				players[i][j].setCharacterSize(18);
				players[i][j].setFillColor(Color::White);
				players[i][j].setOutlineThickness(1);
				players[i][j].setOutlineColor(Color::Black);
				players[i][j].setPosition(2, y);
				players[i][j].setString(str[i][j]);
				y = y + 40;
			}
		}
		readTeamRankings.open("Ranking.txt");
		string str2[30];
		int index = 0;
		while (!readTeamRankings.eof())
		{
			getline(readTeamRankings, str2[index]);
			index++;
		}
		Text teamRank[30];
		y = 180;
		for (int i = 0; i < 30; i++) {
			teamRank[i].setFont(font);
			teamRank[i].setCharacterSize(25);
			teamRank[i].setFillColor(Color::White);
			teamRank[i].setOutlineThickness(2);
			teamRank[i].setOutlineColor(Color::Black);
			teamRank[i].setPosition(80, y);
			teamRank[i].setString(str2[i]);
			y = y + 40;
		}
		readTeamRankings.close();
		ifstream readWR;
		readWR.open("world records.txt");
		string str3[30];
		index = 0;
		while (!readWR.eof())
		{
			getline(readWR, str3[index]);
			index++;
		}
		Text worldRec[30];
		y = 180;
		for (int i = 0; i < 30; i++) {
			worldRec[i].setFont(font);
			worldRec[i].setCharacterSize(25);
			worldRec[i].setFillColor(Color::White);
			worldRec[i].setOutlineThickness(2);
			worldRec[i].setOutlineColor(Color::Black);
			worldRec[i].setPosition(80, y);
			worldRec[i].setString(str3[i]);
			y = y + 40;
		}
		readWR.close();
		ifstream readplayerRec;
		readplayerRec.open("player Rankings.txt");
		string str4[30];
		index = 0;
		while (!readplayerRec.eof())
		{
			getline(readplayerRec, str4[index]);
			index++;
		}
		Text playerRec[30];
		y = 180;
		for (int i = 0; i < 30; i++) {
			playerRec[i].setFont(font);
			playerRec[i].setCharacterSize(25);
			playerRec[i].setFillColor(Color::White);
			playerRec[i].setOutlineThickness(1);
			playerRec[i].setOutlineColor(Color::Black);
			playerRec[i].setPosition(80, y);
			playerRec[i].setString(str4[i]);
			y = y + 40;
		}
		readplayerRec.close();
		ifstream readUpcom;
		readUpcom.open("upcom.txt");
		string str5[30];
		index = 0;
		while (!readUpcom.eof())
		{
			getline(readUpcom, str5[index]);
			index++;
		}
		Text upcom[30];
		y = 180;
		for (int i = 0; i < 30; i++) {
			upcom[i].setFont(font);
			upcom[i].setCharacterSize(25);
			upcom[i].setFillColor(Color::White);
			upcom[i].setOutlineThickness(1);
			upcom[i].setOutlineColor(Color::Black);
			upcom[i].setPosition(15, y);
			upcom[i].setString(str5[i]);
			y = y + 40;
		}
		readUpcom.close();
		ifstream readRecent;
		readRecent.open("rec.txt");
		string str6[30];
		index = 0;
		while (!readRecent.eof())
		{
			getline(readRecent, str6[index]);
			index++;
		}
		Text rec[30];
		y = 180;
		for (int i = 0; i < 30; i++) {
			rec[i].setFont(font);
			rec[i].setCharacterSize(25);
			rec[i].setFillColor(Color::White);
			rec[i].setOutlineThickness(1);
			rec[i].setOutlineColor(Color::Black);
			rec[i].setPosition(15, y);
			rec[i].setString(str6[i]);
			y = y + 40;
		}
		readRecent.close();
		Text startUp;
		startUp.setFont(font);
		startUp.setCharacterSize(25);
		startUp.setFillColor(Color::White);
		startUp.setOutlineThickness(2);
		startUp.setOutlineColor(Color::Black);
		startUp.setPosition(80, 80);
		startUp.setString("Press Right Shift!");
		while (window.isOpen())
		{
			if (Keyboard::isKeyPressed(Keyboard::RShift)) {
				window.draw(starter);
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter)) {
				window.draw(sound_Button);
			}
			if (Keyboard::isKeyPressed(Keyboard::Num2)) {
				window.draw(pic3);
			}
			if (Keyboard::isKeyPressed(Keyboard::Num3)) {
				window.draw(classMenu);
			}
			if (Keyboard::isKeyPressed(Keyboard::Num1)) {
				window.draw(classMenu);
			}
			if (Keyboard::isKeyPressed(Keyboard::F1))
			{
				window.draw(teamMenu);
			}
			if (Keyboard::isKeyPressed(Keyboard::M))
			{
				window.draw(liveMatch);
			}
			if (Keyboard::isKeyPressed(Keyboard::F2))
			{
				window.draw(f2Menu);
			}
			if (Keyboard::isKeyPressed(Keyboard::F3))
			{
				window.draw(newsMenu);
			}
			if (Keyboard::isKeyPressed(Keyboard::P)) {
				window.draw(teamPk);
				for (int i = 0, j = 1; j < 15; j++) {
					window.draw(players[i][j]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::I)) {
				window.draw(teamInd);
				for (int i = 2, j = 1; j < 15; j++) {
					window.draw(players[i][j]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				window.draw(teamEng);
				for (int i = 1, j = 1; j < 15; j++) {
					window.draw(players[i][j]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::N)) {
				window.draw(teamNz);
				for (int i = 5, j = 1; j < 15; j++) {
					window.draw(players[i][j]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::B)) {
				window.draw(teamBan);
				for (int i = 4, j = 1; j < 15; j++) {
					window.draw(players[i][j]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::R)) {
				window.draw(teamRankings);
				for (int i = 0; i < 30; i++) {
					window.draw(teamRank[i]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Z)) {
				window.draw(RankingsNews);
				for (int i = 0; i < 30; i++) {
					window.draw(teamRank[i]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				window.draw(teamRankings);
				for (int i = 0; i < 30; i++) {
					window.draw(worldRec[i]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::X)) {
				window.draw(playerNews);
				for (int i = 0; i < 30; i++) {
					window.draw(playerRec[i]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::L)) {
				window.draw(teamRankings);
				for (int i = 0; i < 30; i++) {
					window.draw(playerRec[i]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::C)) {
				window.draw(UpNews);
				for (int i = 0; i < 30; i++) {
					window.draw(upcom[i]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Q)) {
				window.draw(teamRankings);
				for (int i = 0; i < 30; i++) {
					window.draw(upcom[i]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::O)) {
				window.draw(teamRankings);
				for (int i = 0; i < 30; i++) {
					window.draw(rec[i]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::V)) {
				window.draw(recNews);
				for (int i = 0; i < 30; i++) {
					window.draw(rec[i]);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				sound.play();
			}
			if (Keyboard::isKeyPressed(Keyboard::Num0)) {
				sound.pause();
			}
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			window.display();
		}
	}
	return 0;
}