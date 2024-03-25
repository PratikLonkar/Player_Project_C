#include "PlayerDefination.c"

void main() {
	printf("\n----------------------------------------------Player Management System--------------------------------------------------\n");

	int size=5;

	Player* plr=(Player*)malloc(sizeof(Player)*size);
	int ch;


	demoDetails(plr);  //337
Menu:
	do {

		printf("\n\n");
		printf("\n----------------------------------------------------*****Menu*****----------------------------------------------------");
		printf("\n\n1)Add Player Details\n2)Show Player Details\n3)Search Player Details\n4)Delete Player Details\n5)Update Player Details\n6)Sort Player Details\n7)Top 3 Players\n0)Exit\n\n");
		printf("----------------------------------------------------------------------------------------------------------------------");
		printf("\nEnter the choice : ");
		scanf("%d",&ch);
		printf("----------------------------------------------------------------------------------------------------------------------");


		switch(ch) {

			case 1 : {

				if(cnt==size) {

					printf("\nPlayers Table is  Full!!!");
					char ch;
					printf("\nYou Want to increase table size (Y/N) :");
					fflush(stdin);
					scanf("%c",&ch);

					if(ch=='Y' || ch=='y') {

						int n;
						printf("\nEnter the size you want to increase :");
						scanf("%d",&n);

						plr=resizeArray(plr,size,n);  //67


					} else if(ch=='N' || ch=='n') {

						printf("\nPlayers Table is not sufficient to store more data!!! ");

						goto Menu;
					}

				}

				storeDetails(plr); 
				break;
			}

			case 2 : {

				displayDetails(plr);
				break;
			}

			case 3 : {

				searchPlayer(plr);
				break;
			}

			case 4 : {

				int index=searchByOneName(plr);
				if(index==-1) {

					printf("\nPlayer Details Not Found!!!");
				} else {

					deletePlayer(plr,index);
					printf("\nPlayer Deleted Successfully!!!");
				}

				break;
			}

			case 5 : {

				updatePlayer(plr);

				break;
			}

			case 6 : {

				sortPlayer(plr);
				break;
			}

			case 7 : {

				topPlayer(plr);
				break;
			}

			case 0 : {

				printf("\nThank You....");
			}

		}

	} while(ch>0 && ch<8);

	if(!(ch>=0 && ch<8)) {

		printf("\nPlease Enter Valid Option!!!");
		goto Menu;
	}

}
