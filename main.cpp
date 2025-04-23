//hang person game

#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{ 
  initscr();	
  noecho();
  //cbreak();

  const char* wordlist[3];
  wordlist[0] = "Start";
  wordlist[1] = "Quit";
  wordlist[2] = "Word list";
  int choice = 0;
  int highlight = 0;
  int wordlistsize = sizeof(wordlist);
  int elementsize = sizeof(wordlist[0]);
  int listsizemax = wordlistsize / elementsize;
  
  //scren size
  int y, x = 0;
  getmaxyx(stdscr, y, x);

  //window test
  WINDOW* renderwindow = newwin(20, 50, 0, 0);
  box(renderwindow, 0, 0);
  refresh();
  wrefresh(renderwindow);

  //create menu window
  WINDOW* inputwin = newwin(6, 50, y-8, 0);
  box(inputwin, 0, 0);
  refresh();
  wrefresh(inputwin);
  keypad(inputwin, true);
  curs_set(0);

  while(1)
  {
    for(int i = 0; i < 3; i++)
    {
      if(i == highlight)
      {
        wattron(inputwin, A_REVERSE);
      }
      mvwprintw(inputwin, i+1, 1, wordlist[i]);
      wattroff(inputwin, A_REVERSE);
    }

    choice = wgetch(inputwin);

    switch(choice)
    {
      case KEY_UP:
        if(highlight - 1 < 0)
        {
          break;
        }
        highlight--;
        break;
      case KEY_DOWN:
        if(highlight + 1 > (listsizemax - 1))
        {
          break;
        }
        highlight++;
        break;
      defeault:
        break;
    }

    if(choice == 10)
    {
      break;
    }
  }


  getch();
  endwin();

  return 0;
}                                         