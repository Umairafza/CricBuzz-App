#pragma once
#include<iostream>
using namespace std;
struct IccRankings
{
	int odi;
	int t20;
	int testMatches;
};

struct Date {
	int day;
	int month;
	int year;
};

enum MatchStatus {
	upcoming,
	recent
};

enum AudienceStatus {
	notAllowed,
	allowed
};
class Team {
protected:
	string teamName;
	IccRankings rankings;
	int noOfPlayers;
	int totalWon;
	int totalLost;
	int odiWorldCupWon;
	int t20WorldCupWon;
	string teamCaptain;
	string teamCoach;
	string adminUsername;
	string adminPassword;
public:
	void displayMatches();
	void updateCaptain();
	void updateCoach();
	void displayTeam();
};

class Player:public Team {
protected:
	string playerName;
	Date dateOfbirth;
	int shirtNo;
	int average;
	IccRankings rankings;
	int totalRuns;
	int MatchesPlayed; //*
	int totalWickets;
	string battingStyle; 
	string bowlingStyle;
	string Role; //*
public:
	void addPlayer();
	bool removePlayer();
	bool searchPlayer();
	bool updatePlayer();
};

class Match {
protected:
	string team1;
	string team2;
	Date date;
	string venue;
	string matchType;
	string tournamentName;
	int noOfCommentators;
	int noOfUmpires;
	MatchStatus matchStatus;
	AudienceStatus audienceStatus;
public:
	void conductMatch();
	void scheduleMatch(); 
	void updateWorldRecords();
	void updateTeamRanking();
	void updatePlayerRanking(); //
	void displayUpcomingMatches();	
	void displayRecentMatches();
};

class News : public Player, public Match {
public:
	void newsOfprevMatch();
	void newsOfUpcomMatch();
	void teamRankings();
	void playerRankings();
};
void loading();