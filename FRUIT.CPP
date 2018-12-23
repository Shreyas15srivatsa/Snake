#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iomanip.h>
#include <iostream.h>
#include <dos.h>

int exitgame , score;
const int width = 40;
const int height = 20;
int  fruitx, fruity,snakex,snakey;
int tailx[50], taily[50];
int ntail;
char ch1;
void setup()    //function to initialise variables
{
	exitgame=0;

	snakex=width/2;
	snakey=height/2;
	fruitx = rand() % width+1;
	fruity = rand() % height+1;
   	score=0;
}

void draw()   // function to draw the map
{  clrscr();
   int i,j;
   for (i=0; i<width+2; i++)
	   cout<<"*";
	 cout<<endl;
	 for(i=0; i<height; i++)
	 {
	   for(j=0; j<width; j++)
	   {
	 if(j==0)
	   cout<<"*";
	 if(i==snakey && j==snakex)
	   cout<<"S";

	 else if(i==fruity && j==fruitx)
	   cout<<"F";
	 else
	 { int print=0;
	   for(int k=0;k<ntail;k++)
		 {
		   if(tailx[k]==j && taily[k]==i)
		   {  cout<<"s";
		  print=1;
		   }

		 }
		   if(!print)
		   cout<<" ";


	 }


	 if(j==width-1)
	   cout<<"*";
	   }
	   cout<<endl;
	 }
	 for (i=0; i<width+2; i++)
	   cout<<"*";
	 cout<<endl;
	 cout<<"score:"<<score;
}



void input() // function for movement of snake
{ int prevx=tailx[0];
  int prevy=taily[0];
  int prev2x,prev2y;
  tailx[0]=snakex;
  taily[0]=snakey;
  for(int l=1;l<ntail;l++)
  {
	 prev2x=tailx[l];
	 prev2y=taily[l];
	 tailx[l]=prevx;
	 taily[l]=prevy;
	 prevx=prev2x;
	 prevy=prev2y;
  }
  if(kbhit()){
	 ch1=getch();
		if(ch1=='a')
		{ snakex--;
		}
		else if(ch1=='s')
		{ snakey++;
		}
		else if(ch1=='d')
		{ snakex++;
		}
		else if(ch1=='w')
		{ snakey--;
		}
		else if(ch1=='o')
		{ exitgame = 1;
		}
	 }
	 else{
		int x = 150 - (score);
		if(x<=10){
			x = 10;
		}
		delay(x);
		if(ch1=='a')
		{ snakex--;
		}
		else if(ch1=='s')
		{ snakey++;
		}
		else if(ch1=='d')
		{ snakex++;
		}
		else if(ch1=='w')
		{ snakey--;
		}
		else if(ch1=='o')
		{ exitgame = 1;
		}

	 }
 /*  if(snakex>width || snakex<0 || snakey>height || snakey<0)
	{ exitgame=1;
	  cout<<endl;
	  cout<<"  game over";
	  getch();
	}*/
	if(snakex>=width) snakex=0; else if(snakex<0) snakex=width-1;
	if(snakey>=height) snakey=0; else if(snakey<0) snakey=height-1;
	for(int i=0;i<ntail;i++)
	{ if (tailx[i]==snakex && taily[i]==snakey)
	  { exitgame=1;
	cout<<endl<<endl;
	clrscr();

	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<'\t'<<'\t'<<'\t'<<'\t'<<"GAME OVER!";
	getch();
	  }
	}
	if( snakex==fruitx && snakey==fruity)
	{  score+=10;
	  fruitx = rand() % width;
	  fruity = rand() % height;
	  ntail++;
	}

  }



int main(void)
{
   int i,j;// variables for the for loop

  clrscr();

  cout<<"Snake Game"<<endl;
  cout<<"A C++ project by Sameer and Shreyas"<<endl;
  cout<<"Press any key to continue"<<endl;
  getch();
  clrscr();


   setup();  // calling function setup()
   while(!exitgame) // while exitgame is not equal to 1
   { draw();  // calling draw()
	 input(); // calling input()


   }
   getch();
   return 0;
}

