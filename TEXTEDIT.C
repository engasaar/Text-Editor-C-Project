#include <stdio.h>
#include <conio.h>
#include <string.h>
#define LEFT 75
#define RIGHT 77
#define HOME 71
#define END 79
#define ESC 27
#define ENTER 13
void main()
{
int n;
char ch;
char* ptr=NULL;
char* pcurrent=NULL;
clrscr();
printf("enter no of your text characters: ");
scanf("%d",&n);
clrscr();
ptr=(char* )malloc(sizeof(char)*n+1);
	if (ptr!=NULL)
	{
	 pcurrent=ptr;
	 memset(ptr,0,n+1);
		while(ch!=ESC)
		{
		ch=getch();
			if(ch!=0)
				{
					if(isprint(ch))
					{
						if((pcurrent-ptr)<n)
						{
						printf("%c",ch);
						*pcurrent=ch;
						pcurrent ++;
						}
						else
						{
						printf("\a");
						}
					}
					else
					{
						switch (ch)
						{
						case ENTER:
						gotoxy(1,15);
						printf("you text is:%s",ptr);
						break;
						}
					 }
				}
				else
				{
				ch=getch();
					switch (ch)
					{
					case HOME:
					pcurrent=ptr;
					gotoxy(pcurrent-ptr+1,1);
					break;
					case END:
					pcurrent=ptr+strlen(ptr);
					gotoxy(pcurrent-ptr+1,1);
					break;
					case RIGHT:
						if((pcurrent-ptr)<strlen(ptr))
						{
						pcurrent++;
						gotoxy(pcurrent-ptr+1,1);
						 }
					break;
					case LEFT:
						if((pcurrent-ptr)>0)
						{
						pcurrent --;
						gotoxy(pcurrent-ptr+1,1);
						}
					break;
					}
				}
		}
	}
getch();
}