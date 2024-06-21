#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

int mode_choice(WINDOW *choice_win);
void file_input(WINDOW *choice_win, char file_name[30]);
int count_file_lines(FILE *file_ptr);
void read_file(FILE *file_ptr, WINDOW *text_pad, int x_max, int y_max, char file_name[30]);

int main()
{
	int x_max, y_max;
	char buffer[60];
	char input[20];

	initscr();
	cbreak();
	refresh();
	curs_set(0);

	getmaxyx(stdscr, y_max, x_max);

	//------------ CHOOSE THE MODE AND OPEN A FILE -------------------------------------------------------------

	WINDOW *choice_win = newwin(y_max, x_max, 0, 0);
	box(choice_win, 0, 0);
	mvwprintw(choice_win, 0, 3, "[ TEXT EDITOR ]");
	keypad(choice_win, true);
	refresh();
	wrefresh(choice_win);

	int mode = mode_choice(choice_win);

	char *modes[3] = {"r", "r+", "w+"};
	// mvwprintw(choice_win, 10, 3, "%s", modes[mode]);
	wrefresh(choice_win);
	char file_name[30];
	char ch;

	file_input(choice_win, file_name);
	FILE *file_ptr = fopen(file_name, modes[mode]);

	while (1)
	{
		if (file_ptr == NULL)
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
	fclose(file_ptr);

	delwin(choice_win);

	//----------- DISPLAY AND OR EDIT FILE --------------------------------------------------------------------------------------

	box(stdscr, 0, 0);
	mvprintw(0, 3, "[ %s ]", file_name);
	refresh();

	int lines = count_file_lines(file_ptr);

	WINDOW *text_pad = newpad(500, x_max - 4);
	keypad(text_pad, true);
	// box(text_pad, 0, 0);
	prefresh(text_pad, 0, 0, 2, 2, y_max - 3, x_max - 4);

	switch (mode)
	{
	case 0:
		read_file(file_ptr, text_pad, x_max, y_max, file_name);
		break;

		// case 1:
		// 	// edit_file();
		// 	read_file(file_ptr, text_pad, x_max, y_max);
		// 	break;

		// case 2 :
		// 	new_file();
		// 	break;

	default:
		break;
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
	curs_set(1);
	wgetnstr(choice_win, file_name, 29);
	curs_set(0);
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

			mvwprintw(choice_win, (i * 2) + 2, 3, "%s", modes[i]);
			wattroff(choice_win, A_REVERSE);
		}

		mode = wgetch(choice_win);

		switch (mode)
		{
		case KEY_UP:
			highlight--;

			if (highlight < 0)
				highlight = 0;

			break;

		case KEY_DOWN:
			highlight++;

			if (highlight > 2)
				highlight = 2;

			break;

		default:
			break;
		}

		if (mode == 10)
		{
			break;
		}
	}

	return highlight;
}

int count_file_lines(FILE *file_ptr)
{
	char ch;
	int lines = 0;

	while (ch != EOF)
	{
		ch = fgetc(file_ptr);
		if (ch == '\n' || ch == EOF)
		{
			lines++;
		}
	}

	return lines;
}

void read_file(FILE *file_ptr, WINDOW *text_pad, int x_max, int y_max, char file_name[30])
{
	// NOTE : MAJOR ISSUE WAS THAT I HAD TO OPEN THE FILE IN THIS FUNCTION ONCE AGAIN !!!!!
	// file_ptr = fopen(file_name, "r");

	char buffer[1024];
	char temp_buffer[x_max - 9]; // 200 = 199 + null
	prefresh(text_pad, 0, 0, 2, 2, y_max - 3, x_max - 4);

	int ch;
	int highlight_line = 0;
	int start_line = 0;
	int end_line = y_max - 5;

	do
	{

		int index = 1;
		int line = 0; // Used when printing content to the screen

		file_ptr = fopen(file_name, "r");

		while (fgets(buffer, sizeof(buffer) - 1, file_ptr) != NULL)
		{
			int len = strlen(buffer);

			if (len > (x_max - 10))
			{
				int printed = 0;
				while (len >= (x_max - 10))
				{
					strncpy(temp_buffer, buffer + printed, (x_max - 10));
					temp_buffer[(x_max - 9)] = '\0';

					if (printed == 0)
					{
						if (line == highlight_line)
						{
							wattron(text_pad, A_STANDOUT);
						}
						mvwprintw(text_pad, line, 0, "%3d. %s", index, temp_buffer);
						wattroff(text_pad, A_STANDOUT);
					}
					else
					{
						if (line == highlight_line)
						{
							wattron(text_pad, A_STANDOUT);
						}
						mvwprintw(text_pad, line, 0, "     %s", temp_buffer);
						wattroff(text_pad, A_STANDOUT);
					}

					printed += (x_max - 10);
					len -= (x_max - 10);
					line++;
				}
				if (len > 0)
				{
					strcpy(temp_buffer, buffer + printed);
					temp_buffer[strlen(temp_buffer) - 1] = '\0';

					if (line == highlight_line)
					{
						wattron(text_pad, A_STANDOUT);
					}
					mvwprintw(text_pad, line, 0, "     %s", temp_buffer);
					wattroff(text_pad, A_STANDOUT);
					line++;
				}
				index++;
			}
			else
			{
				if (len > 0 && buffer[len - 1] == '\n')
				{
					buffer[len - 1] = '\0';
				}

				if (line == highlight_line)
				{
					wattron(text_pad, A_STANDOUT);
				}

				mvwprintw(text_pad, line, 0, "%3d. %s", index, buffer);
				wattroff(text_pad, A_STANDOUT);
				index++;
				line++;
			}
		}
		fclose(file_ptr);
		prefresh(text_pad, start_line, 0, 2, 2, y_max - 3, x_max - 4);

		mvprintw(y_max - 1, (x_max - 60), "[ line : %3d / Total lines : %3d ]", highlight_line + 1, line);
		wrefresh(stdscr);

		noecho();
		ch = wgetch(text_pad);
		echo();

		switch (ch)
		{
		case KEY_UP:
			highlight_line--;

			if (highlight_line < 0)
				highlight_line = 0;

			if (highlight_line < start_line)
			{
				start_line--;
			}

			break;

		case KEY_DOWN:
			highlight_line++;

			if (highlight_line >= line)
				highlight_line = line - 1;

			if (highlight_line > (y_max - 5) && highlight_line < line)
			{
				start_line++;
			}

			if (start_line > line - (y_max - 5))
			{
				start_line = line - (y_max - 5);
			}
			break;

		default:
			break;
		}

	} while (ch != 27);
}
