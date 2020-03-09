#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}


int nbrBase(int size)
{
  int i = 1;
  int base = 7;
  int n = 6;
  
  while(i < size)
    {
      base = base + n;
      if((i % 2) != 0)
	{	 
	  n = n + 2;
	}
      i++;      
    }
  return (base);
}



void print_stage(int size, int nbrSpace, int nbrStar)
{
  int i;
  int j;
  int nbrLine = size + 3;
  
  while(nbrLine > 0)
    {
      i = nbrStar;
      j = nbrSpace;
      while(nbrSpace > 0)
	{
	  my_putchar(32);
	  nbrSpace--;
	}
      while(nbrStar > 0)
	{
	  my_putchar('*');
	  nbrStar--;
	}
      my_putchar('\n');
      nbrSpace = j - 1;
      nbrStar = i + 2;
      nbrLine--;
    }
}



void print_log(int size, int SpaceLog)
{
  int i;
  int j;
  int nbrLog;
  int nbrLogTmp;
  int nbrLogLine = size;

  if (size % 2 == 1)
    {
      nbrLog = size;
    }
  else
    {
      nbrLog = size + 1;
    }  
  while(nbrLogLine > 0)
    {
      i = SpaceLog;
      j = nbrLog;
      nbrLogTmp = nbrLog;
      while(SpaceLog > 0)
	{
	  my_putchar(32);
	  SpaceLog--;
	}
      while(nbrLog > 0)
	{
	  my_putchar('|');
	  nbrLog--;
	}
      SpaceLog = i;
      nbrLog = j;
      my_putchar('\n');
      nbrLogLine--;
    }
}


void tree(int size)
{
  int i = 1;
  int j;
  int start = nbrBase(size) / 2;
  
  while(i <= size)
    {
      j = (i + 2) * 2;
      print_stage(i, ((nbrBase(size) - (nbrBase(i) - j)) / 2), nbrBase(i) - j);
      i++;
    }
  i = 1;
  j = (size + 2) * 2;
  print_log(size, (nbrBase(size) - ((nbrBase(size) + size + 1)) / 2));

}



int main()
{
  tree(3);
}
