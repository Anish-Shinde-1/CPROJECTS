#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

int mode_choice(WINDOW *choice_win);
void file_input(WINDOW *choice_win, char file_name[30]);
void read_file(FILE *file_ptr);


int main()
{
	int x_max, y_max;
	char buffer[60];
	char input[20];

	initscr();
	cbreak();
	refresh();

	getmaxyx(stdscr, y_max, x_max);

//------------ CHOOSE THE MODE AND OPEN A FILE -------------------------------------------------------------

	WINDOW *choice_win = newwin(y_max, x_max, 0 , 0);
	box(choice_win, 0, 0);
	mvwprintw(choice_win, 0, 3, "[ TEXT EDITOR ]");
	keypad(choice_win, true);
	refresh();
	wrefresh(choice_win);

	int mode = mode_choice(choice_win);
	char *modes[3] = {"r", "r+", "w+"};
	char file_name[30];
	char ch;


	FILE *file_ptr;

	file_input(choice_win, file_name);
	file_ptr = fopen(file_name, modes[mode]);

	while (1)
	{
		if(file_ptr == NULL)
		{
			mvwprintw(choice_win, 4, 3, "ERROR OPENING FILE !");
			wrefresh(choice_win);
			getchar();
			file_input(choice_win, file_name);
			file_ptr = fopen(file_name, modes[mode]);
		}
		else
			break;
	}

	delwin(choice_win);

//----------- DISPLAY AND OR EDIT FILE --------------------------------------------------------------------------------------

	box(stdscr, 0, 0);
	mvprintw(0, 3, "[ %s ]", file_name);
	refresh();

	switch(mode)
	{
		case 0 : 
			read_file();
			break;

		case 1 : 
			edit_file();
			break;

		case 2 : 
			new_file();
			break;

		default : 
			break
	}



	getchar();
	endwin();
}

void file_input(WINDOW *choice_win, char file_name[30])
{
	wclear(choice_win);
	box(choice_win, 0, 0);
	mvwprintw(choice_win, 0, 3, "[ TEXT EDITOR ]");
	mvwprintw(choice_win, 2, 3, "[+] FILE NAME : ");
	wrefresh(choice_win);
	wgetnstr(choice_win, file_name, 29);
}


int mode_choice(WINDOW *choice_win)
{
	char modes[3][20] = {"[+] READ A FILE", "[+] EDIT A FILE", "[+] NEW FILE"};
	int mode;
	int highlight = 0;

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == highlight)
				wattron(choice_win, A_REVERSE);
			
			mvwprintw(choice_win, (i*2)+2, 3, "%s",modes[i]);
			wattroff(choice_win, A_REVERSE);
		}
		
		mode = wgetch(choice_win);

		switch(mode)
		{
			case KEY_UP :
				highlight--;

				if (highlight < 0) 
					highlight = 0;

				break;
			
			case KEY_DOWN :
				highlight++;

				if (highlight > 2) 
					highlight = 2;

				break;
			
			default : 
				break;
		}

		if(mode == 10)
		{
			break;
		}
	}

	return highlight;
}

void read_file(FILE *file_ptr)
{
	char buffer[256];

	while (fgets())
}