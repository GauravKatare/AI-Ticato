#include<bits/stdc++.h>
using namespace std;

int  print(char arr[][6])
{
	int i,j;
	printf("\n");
	for(i=1;i<=2;i++)
	{
		printf("%c|%c|%c",arr[i][1],arr[i][2],arr[i][3]);
		printf("\n_____\n");
	}
	printf("%c|%c|%c",arr[3][1],arr[3][2],arr[3][3]);
	printf("\n\n");
	return 0;
}

int check(char arr[][6])//To check wheather game is finish or not
{
	int vis[4][4];
	int c=-1,i,j;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=3;i++)
	{
		if(arr[i][1]=='X'&&arr[i][2]=='X'&&arr[i][3]=='X')
			return -10;
		if(arr[i][1]=='O'&&arr[i][2]=='O'&&arr[i][3]=='O')
			return 10;
	}
	for(i=1;i<=3;i++)
	{
		if(arr[1][i]=='X'&&arr[2][i]=='X'&&arr[3][i]=='X')
			return -10;
		if(arr[1][i]=='O'&&arr[2][i]=='O'&&arr[3][i]=='O')
			return 10;
	}
	if(arr[1][1]=='X'&&arr[2][2]=='X'&&arr[3][3]=='X')
		return -10;
	if(arr[1][1]=='O'&&arr[2][2]=='O'&&arr[3][3]=='O')
		return 10;
	if(arr[1][3]=='O'&&arr[2][2]=='O'&&arr[3][1]=='O')
		return 10;
	if(arr[1][3]=='X'&&arr[2][2]=='X'&&arr[3][1]=='X')
		return -10;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(arr[i][j]==' ')
				return 0;
		}
	}
	return -1;	
}
/*
void Player1(char arr[][],int a,int b)
{
	int  i,j;
	for(i=a;i<=3;i++)
	{
		for(j=b;j<=3;j++)
		{
			arr[i][j]='X';
			s=check(arr);
			if(s==10)
				return 10;
			else if(s==-10)
				return -10;
			else if(s==0)
				return 0;
			else
			{
				if(j!=3)
					Player2(arr,i,j+1);
			}	
		}
		Player2(arr,i+1,0);
	}			
}
void Player2(char arr[][],int a,int b)
{
	int  i,j;
	for(i=a;i<=3;i++)
	{
		for(j=b;j<=3;j++)
		{
			arr[i][j]='O';
			if(j!=3)
				Player1(arr,i,j+1);
		}
		Player1(arr,i+1,0);
	}
}*/

int main()
{
	int i,j,a,b,s=0;
	char arr[6][6];
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
			arr[i][j]=' ';
	}
	i=0;
	while(s==0)
	{
		printf("ENTER POSITION WHERE YOU WANT INSERT \n");
		scanf("%d%d",&a,&b);
		if(arr[a][b]!=' ')
		{
			printf("Wrong Choice\n");
			break;
		}
		if(i%2==0)
			arr[a][b]='X';
		else
			arr[a][b]='O';	
		print(arr);
		s=check(arr);
		printf("\n");
		i++;
	}
	if(s==-10)
		printf("X Won\n");
	else if(s==10)
		printf("O Won\n");
	else if(s==-1)
		printf("Draw\n");
	return 0;
}
