#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void board(char one,char two,char three,char four,char five,char six,char seven,char eight,char nine);

//void wincheck(char one,char two,char three,char four,char five,char six,char seven,char eight,char nine);

// int inputans(int input);

int main()
{
	int i, input;
	char player1[50], player2[50];
	char one, two, three, four, five, six, seven, eight, nine;

	one = '1'; two = '2'; three = '3'; four = '4'; five = '5'; six = '6'; seven = '7'; eight = '8'; nine = '9';

	printf("Enter first players name : ");
	scanf("%s",player1);
	printf("Enter second players name : ");
	scanf("%s",player2);

	for(i = 1; i <=9; i++)
	{
		board(one, two, three, four, five, six, seven, eight, nine);
		// inputans(input);
		printf("Which box do you want?\n");
	 	scanf("%d",&input);

	 	if(input<1 || input>9)
	 	{
	 		printf("INVALID INPUT!!\n");
	 		i--;
	 		sleep(1);
	 		continue;
	 	}

	 	if(i%2 != 0)
	 	{
			switch (input)
			{
			case 1 : one = 'X';
				break;
			case 2 : two = 'X';
				break;
			case 3 : three = 'X';
				break;
			case 4 : four = 'X';
				break;
			case 5 : five = 'X';
				break;
			case 6 : six = 'X';
				break;
			case 7 : seven = 'X';
				break;
			case 8 : eight = 'X';
				break;
			case 9 : nine = 'X';
				break;
			}
		}
		else if(i%2 == 0)
		{
			switch (input)
			{
			case 1 : one = 'O';
				break;
			case 2 : two = 'O';
				break;
			case 3 : three = 'O';
				break;
			case 4 : four = 'O';
				break;
			case 5 : five = 'O';
				break;
			case 6 : six = 'O';
				break;
			case 7 : seven = 'O';
				break;
			case 8 : eight = 'O';
				break;
			case 9 : nine = 'O';
				break;
			}
		}
		// wincheck(one, two, three, four, five, six, seven, eight, nine); // a break: used in a function is not applicable in main funtion!!
		if((one==two && two==three) || (four==five && five==six) || (seven==eight && eight==nine))
			{ break; }
		else if((one==four && four==seven) || (two==five && five==eight) || (three==six && six==nine))
			{ break; }
		else if((one==five && five==nine) || (three==five && five==seven))
			{ break; }
	}

	board(one, two, three, four, five, six, seven, eight, nine);

	if(i>9){
		printf("IT IS A DRAW!!\n");
	}
	else if(i%2!=0){
		printf("%s WINS!!\n\n",player1);
	}
	else if(i%2==0){
		printf("%s WINS!!\n\n",player2);
	}

	return 0;
}

void board(char one,char two,char three,char four,char five,char six,char seven,char eight,char nine)
{
	system("clear");
	printf("=== TIC TAC TOE ===\n\n");
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n", one, two, three);
	printf("|_____|_____|_____|\n");
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n", four, five, six);
	printf("|_____|_____|_____|\n");
	printf("|     |     |     |\n");
	printf("|  %c  |  %c  |  %c  |\n", seven, eight, nine);
	printf("|     |     |     |\n\n");
}

/* wincheck(char one,char two,char three,char four,char five,char six,char seven,char eight,char nine)
{
	if((one==two && two==three) || (four==five && five==six) || (seven==eight && eight==nine))
			{ break; }
		else if((one==four && four==seven) || (two==five && five==eight) || (three==six && six==nine))
			{ break; }
		else if((one==five && five==nine) || (three==five && five==seven))
			{ break; }
}*/

// int inputans(int input) // ANY CHANGE MADE TO INPUT IN THIS FUNCTION DOES NOT AFFECT VALUE OF INPUT IN MAIN FUNCTION!!!!!! // REQUIRES THE USE OF POINTERS
// {
// 	printf("Which box do you want?");
// 	scanf("%d",&input);

// 	return input;
// }