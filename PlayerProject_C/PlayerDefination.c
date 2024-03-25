#include "PlayerD.h"

int cnt=0;

void storeDetails(Player* plr) {


			printf("\n\n\n1.Enter the Player Details!!!\n");
			printf("----------------------------------------------------------------------------------------------------------------------");

			printf("\nEnter the Player Jersy No : ");
			scanf("%d",&plr[cnt].jersyNo);

			int j;
			for(j=0; j<cnt; j++) {
				if(plr[cnt].jersyNo==plr[j].jersyNo) {

					printf("\n%d Jersy No is Already Present!!! Please Enter Different Jersy No!!!",plr[cnt].jersyNo);
					return;
				}
			}

			printf("\nEnter the Player Name : ");
			fflush(stdin);
			gets(plr[cnt].name);
			printf("\nEnter the Player Runs : ");
			scanf("%d",&plr[cnt].runs);
			printf("\nEnter the Player Wickets : ");
			scanf("%d",&plr[cnt].wickets);
			printf("\nEnter the Player Matches : ");
			scanf("%d",&plr[cnt].matches);
			fflush(stdin);
			printf("\nEnter the Player Country : ");
			gets(plr[cnt].country);
			printf("\nEnter the balls played by the player :");
			scanf("%d",&plr[cnt].balls);
			printf("----------------------------------------------------------------------------------------------------------------------");
			cnt++;
//

}

//***********************************************************************************************************************************************************************

void displayDetails(Player* plr) {

	int i;
	printf("\n\n\n                                                 DASHBOARD");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n   Jersy No   |     Name     |     Runs     |     Wickets     |     Matches     |     Country     |   Strike Rate   ");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	strikeRateCal(plr);

	for(i=0; i<cnt; i++) {

		printf("\n     %-10d %-17s %-17d %-16d %-17d %-16s %.2f ",plr[i].jersyNo,plr[i].name,plr[i].runs,plr[i].wickets,plr[i].matches,plr[i].country,plr[i].strikeRate);
		printf("\n--------------------------------------------------------------------------------------------------------------------");

	}
	printf("\n");
	printf("\nTotal Player : %d",cnt);

}

//**********************************************************************************************************************************************************************************

Player* resizeArray(Player* plr,int size,int n) {

	plr=(Player*)realloc(plr,sizeof(Player)*size+n);

	return plr;

}


//*************************************************************************************************************************************************************************

void searchPlayer(Player* plr) {

	int ch;
	printf("\n\n");
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\n1.Search By Jersy No\n2.Search By Name\n");
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\n\nEnter the Choice : ");
	scanf("%d",&ch);
	printf("----------------------------------------------------------------------------------------------------------------------");

	switch(ch) {

		case 1 : {

			int index=searchByJersyNo(plr);
			if(index==-1) {

				printf("\nPlayer Details Not Found!!!");
			} else {
//
				displayOneRecord(plr,index);
			}
			break;
		}

		case 2 : {

			int index=searchByName(plr);
			if(index==-1) {

				printf("\nPlayer Details Not Found!!!");
			}

			break;
		}

	}
}

//*************************************************************************************************************************************************************************

int searchByJersyNo(Player* plr) {

	int jn; //Jersy No
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the Jersy No : ");
	scanf("%d",&jn);
	printf("----------------------------------------------------------------------------------------------------------------------");

	int i;
	for(i=0; i<cnt; i++) {

		if(plr[i].jersyNo==jn) {

			return i;
		}
	}

	return -1;
}

//**************************************************************************************************************************************************************************

int searchByName(Player* plr) {

	char nm[20]; //Name
	int i,flag=0;
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the Player Name : ");
	fflush(stdin);
	gets(nm);
	int n=strlen(nm);
	printf("----------------------------------------------------------------------------------------------------------------------");

	printf("\n\n\n                                                 DASHBOARD");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n   Jersy No   |     Name     |     Runs     |     Wickets     |     Matches     |     Country     |   Strike Rate   ");
	printf("\n--------------------------------------------------------------------------------------------------------------------");

	strikeRateCal(plr);

	for(i=0; i<cnt; i++) {

		if(strncasecmp(plr[i].name,nm,n)==0) {

			printf("\n     %-10d %-17s %-17d %-16d %-17d %-16s %.2f ",plr[i].jersyNo,plr[i].name,plr[i].runs,plr[i].wickets,plr[i].matches,plr[i].country,plr[i].strikeRate);
			printf("\n--------------------------------------------------------------------------------------------------------------------");
			flag=1;		

		}
	}
	
	//return i;

	if(flag==0) {

		return -1;
	}
}

//********************************************************************************************************************************************************************************

int searchByOneName(Player* plr) {

	char nm[20]; //Name
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the Name : ");
	fflush(stdin);
	gets(nm);
	printf("----------------------------------------------------------------------------------------------------------------------");

	int i;
	for(i=0; i<cnt; i++) {

		if(strcasecmp(plr[i].name,nm)==0) {

			return i;
		}
	}

	return -1;
}

//**************************************************************************************************************************************************************************

void displayOneRecord(Player* plr,int index) {

	strikeRateCal(plr);

	printf("\n\n\n                                               DASHBOARD");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n   Jersy No   |     Name     |     Runs     |     Wickets     |     Matches     |     Country     |   Strike Rate   ");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n     %-10d %-17s %-17d %-16d %-17d %-16s %.2f ",plr[index].jersyNo,plr[index].name,plr[index].runs,plr[index].wickets,plr[index].matches,plr[index].country,plr[index].strikeRate);
	printf("\n--------------------------------------------------------------------------------------------------------------------");
}

//***************************************************************************************************************************************************************************

void deletePlayer(Player* plr,int index) {

	for(index; index<cnt; index++) {
		plr[index]=plr[index+1];
	}

	cnt--;
}

//***************************************************************************************************************************************************************************

void updatePlayer(Player* plr) {

	int ch;
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\n1.Update Runs\n2.Update Wickets\n3.Update Matches\n");
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\n\nEnter the Choice : ");
	scanf("%d",&ch);
	printf("----------------------------------------------------------------------------------------------------------------------");

	switch(ch) {

		case 1 : {

			int index=searchByOneName(plr);
			if(index==-1) {

				printf("\nPlayer Details Not Found!!!");
			} else {

				updateRuns(plr,index);
				printf("\nPlayer Runs Updated Successfully!!!");
				displayOneRecord(plr,index);


			}
			break;
		}

		case 2 : {
			int index=searchByOneName(plr);
			if(index==-1) {

				printf("\nPlayer Details Not Found!!!");
			} else {

				updateWickets(plr,index);
				printf("\nPlayer Wickets Updated Successfully!!!");
				displayOneRecord(plr,index);
			}

			break;
		}

		case 3 : {
			int index=searchByOneName(plr);
			if(index==-1) {

				printf("\nPlayer Details Not Found!!!");
			} else {

				updateMatches(plr,index);
				printf("\nPlayer Matches Updated Successfully!!!");
				displayOneRecord(plr,index);
			}

			break;
		}
	}
}

//****************************************************************************************************************************************************************************

void updateRuns(Player* plr,int index) {

	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the Runs : ");
	scanf("%d",&plr[index].runs);
	printf("----------------------------------------------------------------------------------------------------------------------");

}

//******************************************************************************************************************************************************************************

void updateWickets(Player* plr,int index) {

	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the Wickets : ");
	scanf("%d",&plr[index].wickets);
	printf("----------------------------------------------------------------------------------------------------------------------");

}

//******************************************************************************************************************************************************************************

void updateMatches(Player* plr,int index) {

	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the Matches : ");
	scanf("%d",&plr[index].matches);
	printf("----------------------------------------------------------------------------------------------------------------------");

}

//*******************************************************************************************************************************************************************************

void strikeRateCal(Player* plr) {

	int i;
	for(i=0; i<cnt; i++) {

		plr[i].strikeRate=(plr[i].runs*100)/plr[i].balls;
	}
}


//*********************************************************************************************************************************************************************************

void demoDetails(Player* plr) {

	plr[cnt].jersyNo=18;
	strcpy(plr[cnt].name,"Virat Kohli");
	plr[cnt].runs=50000;
	plr[cnt].wickets=50;
	strcpy(plr[cnt].country,"India");
	plr[cnt].matches=1212;
	plr[cnt].balls=12000;
	//plr[cnt].strikeRate=416;
	cnt++;

	plr[cnt].jersyNo=12;
	strcpy(plr[cnt].name,"Rahul Dravid");
	plr[cnt].runs=25000;
	plr[cnt].wickets=20;
	strcpy(plr[cnt].country,"India");
	plr[cnt].matches=1200;
	plr[cnt].balls=20000;
	//plr[cnt].strikeRate=125;
	cnt++;

	plr[cnt].jersyNo=14;
	strcpy(plr[cnt].name,"Suresh Raina");
	plr[cnt].runs=60000;
	plr[cnt].wickets=60;
	strcpy(plr[cnt].country,"India");
	plr[cnt].matches=1000;
	plr[cnt].balls=15000;
	//plr[cnt].strikeRate=400;
	cnt++;

	plr[cnt].jersyNo=45;
	strcpy(plr[cnt].name,"Rohit Sharma");
	plr[cnt].runs=15000;
	plr[cnt].wickets=30;
	strcpy(plr[cnt].country,"India");
	plr[cnt].matches=1200;
	plr[cnt].balls=13000;
	//plr[cnt].strikeRate=400;
	cnt++;
}

//***********************************************************************************************************************************************************************************

void sortPlayer(Player* plr) {

	int ch;
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\n1.Sort By Runs\n2.Sort By Wickets\n3.Sort By Matches\n");
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the Choice : ");
	scanf("%d",&ch);
	printf("----------------------------------------------------------------------------------------------------------------------");

	switch(ch) {

		case 1 : {
			sortByRuns(plr);
			break;
		}

		case 2 : {
			sortByWickets(plr);
			break;
		}

		case 3 : {
			sortByMatches(plr);
			break;
		}
	}
}

//***********************************************************************************************************************************************************************************

void sortByRuns(Player* plr) {

	int ch;
	printf("\n1.Sort By Max-Min\n2.Sort By Min-Max\n");
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the choice : ");
	scanf("%d",&ch);
	printf("----------------------------------------------------------------------------------------------------------------------");

	switch(ch) {

		case 1 : {
			sortByMaxMinRuns(plr);
			break;
		}

		case 2 : {
			sortByMinMaxRuns(plr);
			break;
		}
	}

}


void sortByMaxMinRuns(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].runs<plr[j].runs) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	displayDetails(plr);
}

void sortByMinMaxRuns(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].runs>plr[j].runs) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	displayDetails(plr);
}

//***********************************************************************************************************************************************************************************

void sortByWickets(Player* plr) {

	int ch;
	printf("\n1.Sort By Max-Min\n2.Sort By Min-Max\n");
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the choice : ");
	scanf("%d",&ch);
	printf("----------------------------------------------------------------------------------------------------------------------");

	switch(ch) {

		case 1 : {
			sortByMaxMinWickets(plr);
			break;
		}

		case 2 : {
			sortByMinMaxWickets(plr);
			break;
		}
	}

}

void sortByMaxMinWickets(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].wickets<plr[j].wickets) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	displayDetails(plr);
}

void sortByMinMaxWickets(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].wickets>plr[j].wickets) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	displayDetails(plr);
}

//**************************************************************************************************************************************************************************************

void sortByMatches(Player* plr) {

	int ch;
	printf("\n1.Sort By Max-Min\n2.Sort By Min-Max\n");
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the choice : ");
	scanf("%d",&ch);
	printf("----------------------------------------------------------------------------------------------------------------------");


	switch(ch) {

		case 1 : {
			sortByMaxMinMatches(plr);
			break;
		}

		case 2 : {
			sortByMinMaxMatches(plr);
			break;
		}
	}

}

void sortByMaxMinMatches(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].matches<plr[j].matches) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	displayDetails(plr);
}

void sortByMinMaxMatches(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].matches>plr[j].matches) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	displayDetails(plr);
}

//*************************************************************************************************************************************************************************************

void topPlayer(Player* plr) {

	int ch;
	printf("\n1.Top 3 By Runs\n2.Top 3 By Wickets\n3.Top 3 By Matches\n4.Top 3 By Strike Rates\n");
	printf("----------------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the choice : ");
	scanf("%d",&ch);
	printf("----------------------------------------------------------------------------------------------------------------------");

	switch(ch) {

		case 1 : {
			topRuns(plr);
			break;
		}

		case 2 : {
			topWickets(plr);
			break;
		}

		case 3 : {
			topMatches(plr);
			break;
		}

		case 4 : {
			topStrikeRates(plr);
			break;
		}
	}

}


void topRuns(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].runs<plr[j].runs) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	printf("\n\n\n                                                 DASHBOARD");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n   Jersy No   |     Name     |     Runs     |     Wickets     |     Matches     |     Country     |   Strike Rate   ");
	printf("\n--------------------------------------------------------------------------------------------------------------------");

	for(i=0; i<3; i++) {

		strikeRateCal(plr);
		printf("\n     %-10d %-17s %-17d %-16d %-17d %-16s %.2f ",plr[i].jersyNo,plr[i].name,plr[i].runs,plr[i].wickets,plr[i].matches,plr[i].country,plr[i].strikeRate);
		printf("\n--------------------------------------------------------------------------------------------------------------------");

	}

}


void topWickets(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].wickets<plr[j].wickets) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	printf("\n\n\n                                                 DASHBOARD");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n   Jersy No   |     Name     |     Runs     |     Wickets     |     Matches     |     Country     |   Strike Rate   ");
	printf("\n--------------------------------------------------------------------------------------------------------------------");

	for(i=0; i<3; i++) {

		strikeRateCal(plr);
		printf("\n     %-10d %-17s %-17d %-16d %-17d %-16s %.2f ",plr[i].jersyNo,plr[i].name,plr[i].runs,plr[i].wickets,plr[i].matches,plr[i].country,plr[i].strikeRate);
		printf("\n--------------------------------------------------------------------------------------------------------------------");

	}

}


void topMatches(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].matches<plr[j].matches) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	printf("\n\n\n                                                 DASHBOARD");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n   Jersy No   |     Name     |     Runs     |     Wickets     |     Matches     |     Country     |   Strike Rate   ");
	printf("\n--------------------------------------------------------------------------------------------------------------------");

	for(i=0; i<3; i++) {

		strikeRateCal(plr);
		printf("\n     %-10d %-17s %-17d %-16d %-17d %-16s %.2f ",plr[i].jersyNo,plr[i].name,plr[i].runs,plr[i].wickets,plr[i].matches,plr[i].country,plr[i].strikeRate);
		printf("\n--------------------------------------------------------------------------------------------------------------------");

	}

}


void topStrikeRates(Player* plr) {

	int i,j;
	for(i=0; i<cnt; i++) {

		for(j=i+1; j<cnt; j++) {

			if(plr[i].strikeRate<plr[j].strikeRate) {

				Player temp=plr[i];
				plr[i]=plr[j];
				plr[j]=temp;
			}
		}
	}

	printf("\n\n\n                                                 DASHBOARD");
	printf("\n--------------------------------------------------------------------------------------------------------------------");
	printf("\n   Jersy No   |     Name     |     Runs     |     Wickets     |     Matches     |     Country     |   Strike Rate   ");
	printf("\n--------------------------------------------------------------------------------------------------------------------");

	for(i=0; i<3; i++) {

		strikeRateCal(plr);
		printf("\n     %-10d %-17s %-17d %-16d %-17d %-16s %.2f ",plr[i].jersyNo,plr[i].name,plr[i].runs,plr[i].wickets,plr[i].matches,plr[i].country,plr[i].strikeRate);
		printf("\n--------------------------------------------------------------------------------------------------------------------");

	}

}