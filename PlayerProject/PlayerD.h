#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Player {

	int jersyNo;
	char name[20];
	int runs,wickets,matches;
	char country[20];
	float strikeRate;
	int balls;

} Player;

void storeDetails(Player*);
void displayDetails(Player* );
void searchPlayer(Player*);
int searchByJersyNo(Player* );
int searchByName(Player*);
int searchByOneName(Player* );
void deletePlayer(Player*,int );
void updatePlayer(Player* );
void updateRuns(Player*,int);
void updateWickets(Player*,int );
void updateMatches(Player*,int );
void strikeRateCal(Player*);
void displayOneRecord(Player* ,int );
void demoDetails(Player*);
Player* resizeArray(Player* ,int ,int );
void sortPlayer(Player* );
void sortByRuns(Player* );
void sortByMaxMinRuns(Player* );
void sortByMinMaxRuns(Player* );
void sortByWickets(Player* );
void sortByMaxMinWickets(Player* );
void sortByMinMaxWickets(Player* );
void sortByMatches(Player* );
void sortByMaxMinMatches(Player* );
void sortByMinMaxMatches(Player* );
void topPlayer(Player* );
void topRuns(Player* );
void topWickets(Player* );
void topMatches(Player* );
void topStrikeRates(Player* );