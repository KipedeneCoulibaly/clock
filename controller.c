
void printMenu(void) {
	printf("_________________ MENU _________________\n");
	printf("|    I  .  Stopwatch                   |\n");
	printf("|    II .  Timer                       |\n");
	printf("|    III.  Sliptime                    |\n");
	printf("|    IV .  Menu                        |\n");
	printf("|    V  .  Close program               |\n");
	printf("|______________________________________|\n");
}

int splitTime(int* hours, int* minutes) {
	*hours = *hours + (*minutes / 60);
	*minutes = *minutes % 60;
}

void redirection(void) {
	printf("End of timer\n");
	printf("You we be redirecting to the menu in :\n");
	Sleep(1000);
	for (int i = 0; i < 6; i++) {
		printf("%02d seconds", i);
		i++;
		Sleep(3000);
		system("cls");
	}
}

void quitProgram(void) {
	printf("The program will be closed in 5 seconds\n");
	Sleep(5000);
	printf("_________________ END __________________\n");
}

void printFormat(void) {
	printf("\n...Set time in format H:M:S.\n");
	printf("...Each element by command line.\n");
}