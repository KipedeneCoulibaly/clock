#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "controller.h"

int main(int* argc, char* argv[]) {
	int choix = 0, hours = 0, minutes = 0, second = 0, session = 0;
	printMenu();
	while (1) {
		scanf("%d", &choix);
		switch (choix) {
			case 1:
				printf("===============  stopwatch  ============\n");
				printFormat();
				scanf("%d%d%d", &hours, &minutes, &second);
				while (1) {
					if (second == 0) {
						if (minutes == 0) {
							hours--;
							minutes = 60;
						}
						minutes--;
						second = 60;
					}
					second--;
					printf("Timer start :\n");
					printf("%02d:%02d:%02d", hours, minutes, second);
					Sleep(1000);
					system("cls");
					if (hours == 0 & minutes == 0 & second == 0) {
						MessageBeep(MB_OK);
						break;
					}
				}
				redirection();
				printMenu();
				break;
			case 2:
				printf("===============  timer  ================\n");
				printFormat();
				scanf("%d%d%d", &hours, &minutes, &second);
				if (hours > 24 || minutes > 60 || second > 60) {
					printf("Error : wrong declaration\n");
					exit(0);
				}
				// Stop timer after 30 seconds for testing purposes
				// and control the closing of the program.
				while (session != 30) { 
					second++;
					if (second == 60) {
						minutes++;
						second = 0;
					}
					if (minutes == 60) {
						hours++;
						minutes = 0;
					}
					if (hours > 24) {
						hours = 1;
					}
					printf("Timer start :\n");
					printf("%02d:%02d:%02d", hours, minutes, second);
					Sleep(1000);
					system("cls");
					session++;
				}
				redirection();
				printMenu();
				break;
			case 3:
				printf("===============  sliptime  =============\n");
				scanf("%d%d", &hours, &minutes);
				splitTime(&hours, &minutes);
				printf("%d hours %d minutes\n", hours, minutes);
				break;
			case 4:
				printMenu();
				break;
			case 5:
				quitProgram();
				exit(0);
			default:
				printf("Wrong selection\nTry again !!!\n");
				break;
		}
	}
	return 0;
}
