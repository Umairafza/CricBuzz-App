#include <iostream>
#include <fstream>
#include <string>
#include "CricBuzz.h"
#include <Windows.h>
void Player::addPlayer()
{
	cout << "Enter team Name of player: ";
	cin >> teamName;
	cout << "Enter name of player: ";
	cin >> playerName;
	cout << "Enter Date of birth in the format of (dd mm yyyy): ";
	cin >> dateOfbirth.day >> dateOfbirth.month >> dateOfbirth.year;
	cout << "Enter Shirt number: ";
	cin >> shirtNo;
	cout << "Enter Average: ";
	cin >> average;
	cout << "Enter Total runs: ";
	cin >> totalRuns;
	fstream addfile;
	addfile.open("Added and Updated Players.txt", ios::app);
	addfile << teamName << "\t" << playerName << "\t" << dateOfbirth.day << "-" << dateOfbirth.month << "-" << dateOfbirth.year << "\t" << shirtNo << "\t" << average << "\t" << totalRuns << endl;
}

bool Player::removePlayer()
{
	string temp;
	bool playerFound = false;
	cout << "Enter first name of player: ";
	cin >> playerName;
	ifstream read;
	read.open("players.txt");
	while (!read.eof() && !playerFound) {
		read >> temp;
		if (playerName == temp) {
			cout << "Player found!\n";
			temp = "";
			cout << "Data deleted\n";
			playerFound = true;
		}
	}
	if (!playerFound) {
		cout << "Player not found\n";
	}
	return false;
}

bool Player::searchPlayer()
{
	string temp;
	bool playerFound = false;
	cout << "Enter first name of player: ";
	cin >> playerName;
	ifstream read;
	read.open("players.txt");
	while (!read.eof() && !playerFound) {
		read >> temp;
		if (playerName == temp) {
			cout << "Player found\n";
			getline(read, temp);
			cout << "last name\tDate of Birth\t\tShirt No\tAverage\t\tTotal Runs\n";
			cout << temp << endl;
			playerFound = true;
			return true;
		}
	}
	if (!playerFound) {
		cout << "Player not found!\n";
		return false;
	}
	
}

bool Player::updatePlayer()
{
	string temp;
	bool playerFound = false;
	cout << "Enter first name of player: ";
	cin >> playerName;
	ifstream read;
	read.open("players.txt");
	while (!read.eof() && !playerFound) {
		read >> temp;
		if (playerName == temp) {
			cout << "Player found\n";
			playerFound = true;
			cout << "Enter data to update his previous data: ";
			addPlayer();
			return true;
		}
	}
	if (!playerFound) {
		cout << "Player not found!\n";
		return false;
	}
}


void Team::displayMatches()
{
	ifstream read;
	read.open("matches.txt");
	string str;
	while (!read.eof()) {
		getline(read, str);
		cout << str << endl;
	}
}

void Team::updateCaptain()
{
	string temp;
	bool captFound = false;
	cout << "Enter first name of captain: ";
	cin >> teamCaptain;
	ifstream read;
	read.open("players.txt");
	while (!read.eof() && !captFound) {
		read >> temp;
		if (teamCaptain == temp) {
			cout << "Captain found\n";
			captFound = true;
			cout << "Enter the name to update: ";
			cin >> teamCaptain;
			cout << "Captain's name updated: ";
		}
	}
	if (!captFound) {
		cout << "Captain not found!\n";
	}

}

void Team::updateCoach()
{
	string temp;
	bool coachFound = false;
	cout << "Enter first name of coach: ";
	cin >> teamCoach;
	ifstream read;
	read.open("players.txt");
	while (!read.eof() && !coachFound) {
		read >> temp;
		if (teamCaptain == temp) {
			cout << "Coach found\n";
			coachFound = true;
			cout << "Enter the name to update: ";
			cin >> teamCoach;
			cout << "Coach's name updated: ";
		}
	}
	if (!coachFound) {
		cout << "Coach not found!\n";
	}
}

void Team::displayTeam()
{
	string temp;
	bool teamFound = false;
	cout << "Enter name of team: ";
	cin >> teamName;
	ifstream read;
	read.open("team.txt");
	while (!read.eof() && !teamFound) {
		read >> temp;
		if (teamName == temp) {
			getline(read,temp); 
			cout << "\tMatches Won\tMatches lost\tODI WC Won\tCaptain\t\t\tCoach\n";
			cout << temp << endl;
			teamFound = true;
		}
	}
	read.close();
	if (!teamFound) {
		cout << "Team not found!\n";
	}
}

void Match::conductMatch()
{
	fstream file;
	file.open("Matches.txt", ios::app);
	//file<<
	cout << "Enter Team 1: ";
	getline(cin, team1);
	cout << "Enter Team 2: ";
	getline(cin, team2);
	cout << "Enter Date (dd mm yyyy): ";
	cin >> date.day >> date.month >> date.year;
	cout << "Enter venue: ";
	getline(cin, venue);
	cout << "Enter match type(t20, ODI, test): ";
	cin >> matchType;
	cout << "Enter tournament name: ";
	cin >> tournamentName;
	cout << "Enter number of commentators: ";
	cin >> noOfCommentators;
	cout << "Enter number of Umpires: ";
	cin >> noOfUmpires;
	int st;
	cout << "Enter match status: \nupcoming\tPress 1\nrecent\tPress 2\n:";
	cin >> st;
	switch (st)
	{
	case 1: 
		matchStatus = upcoming;
		break;
	case 2: 
		matchStatus = recent;
		break;
	default:
		cout << "Invalid Entry!\n";
		break;
	}
	cout << "Audience status: \nnotAllowed\tPress 1\nallowed\tPress 2\n: ";
	cin >> st;
	switch (st)
	{
	case 1:
		audienceStatus = notAllowed;
		break;
	case 2:
		audienceStatus = allowed;
		break;
	default:
		cout << "Invalid Entry!\n";
		break;
	}
	file << team1 << "  vs  " << team2 << "\t" << date.day << date.month << date.year << venue << matchType << tournamentName << noOfCommentators << noOfUmpires << matchStatus; 
}

void Match::scheduleMatch()
{
	ifstream read;
	char chr;
	read.open("matches.txt");
	string str,temp="";
	for (int i = 1; !read.eof() && temp != "Recent";i++) {
		if(temp!="Recent"){
			getline(read, str);
		cout << temp <<" " <<str << endl ;
		}
		read >> temp;
	}
	cout << "Want to schedule a match?\tPress 'Y', else enter any character: ";
	cin >> chr;
	if (chr == 'y' || chr == 'Y') {
		conductMatch();
	}
}

void Match::updateWorldRecords()
{
	ofstream write;
	string recordTitle, name;
	int odi, t20, test;
	write.open("world records.txt", ios::app);
	cout << "Enter record title: ";
	getline(cin, recordTitle);
	cout << "Enter record holder: ";
	getline(cin, name);
	write << recordTitle << ":\t" << name << endl;
	write.close();
}

void Match::updateTeamRanking()
{
	ofstream write;
	string name;
	int odi, t20, test;
	write.open("Ranking.txt", ios::app);
	cout << "Enter name of team: ";
	getline(cin, name);
	cout << "Enter ODI, T20 and Test rankings: ";
	cin >> odi >> t20 >> test;
	write << name << "\t|\t" << odi << "\t|\t" << t20 << "\t|\t" << test << endl;
	write.close();
}

void Match::updatePlayerRanking()
{
	ofstream write;
	string name;
	write.open("players Rankings.txt", ios::app);
	cout << "Enter name of player: ";
	getline(cin, name);
	write << name << endl;
	write.close();
}

void Match::displayUpcomingMatches()
{
	ifstream read;
	bool stop = false;
	read.open("Upcoming.txt");
	string str;
	while (!read.eof() && !stop) {
		getline(read, str);
		cout << str << endl;

	}
}

void Match::displayRecentMatches()
{
	ifstream read;
	bool stop = false;
	read.open("Recent.txt");
	string str;
	while (!read.eof() && !stop) {
		getline(read, str);
		cout << str << endl;

	}
}

void News::newsOfprevMatch()
{
	cout << "Enter team 1: ";
	cin >> team1;
	cout << "Enter team 2: ";
	cin >> team2;
	string temp;
	bool prevMatchFound = false, enter = false;
	ifstream read;
	read.open("matches.txt");
	while (!read.eof() && !prevMatchFound) {
		read >> temp;
		if (temp == "Recent" || enter) {
			enter = true;
			if (team1 == temp) {
				read >> temp;
				if (team2 == temp) {
					getline(read, temp);
					cout << "That was a fantastic match! The information of match is: \n";
					cout << "\tDate\t\tVenue\tMatch Type\tTournament Name\tCommentators\tUmpires\t\tAudience Status\n";
					cout << temp << endl;
					prevMatchFound = true;
				}
			}
		}
	}
	if (!prevMatchFound) {
		cout << "No news found about given match!\n";
	}
}

void News::newsOfUpcomMatch()
{
	cout << "Enter team 1: ";
	cin >> team1;
	cout << "Enter team 2: ";
	cin >> team2;
	string temp;
	bool upMatch = false, enter = false;
	ifstream read;
	read.open("matches.txt");
	while (!read.eof() && !upMatch && temp!="Recent") {
		read >> temp;
		if (team1 == temp) {
			read >> temp;
			if (team2 == temp) {
				cout << "Yes, the wait is about to over, the news about most awaited match is: \n";
				getline(read, temp);
				cout << "\tDate\t\tVenue\tMatch Type\tTournament Name\tCommentators\tUmpires\t\tAudience Status\n";
				cout << temp << endl;
				upMatch = true;
			}
		}
		
	}
	if (!upMatch) {
		cout << "No news found about given match!\n";
	}
}

void News::teamRankings()
{
	ifstream read;
	bool stop = false;
	read.open("Ranking.txt");
	string str;
	cout << "Here is the ICC rankings of a few teams!\n";
	while (!read.eof() && !stop) {
		getline(read, str);
		cout << str << endl;
	}
}

void News::playerRankings()
{
	ifstream read;
	bool stop = false;
	read.open("player Rankings.txt");
	string str;
	cout << "Breaking News!!!!\nBabar Azam has crossed Virat Kohli and taken the 1st Place\n";
	while (!read.eof() && !stop) {
		getline(read, str);
		cout << str << endl;
	}
}

void loading()
{
	cout << "\t\t";
	for (int i = 0; i < 4; i++) {
		cout << ".";
		Sleep(1000);
	}
	cout << endl;
}
