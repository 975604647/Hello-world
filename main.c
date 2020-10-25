#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LISTSIZE 5
typedef struct{
	int num;//±àºÅ
	int password;//ÃÜÂë
	int flag;//É¾³ý±êÖ¾
}ElemType;
typedef  struct {
	ElemType  elem[LISTSIZE];
     int     length;
}SqList,*List;
void Init(SqList *L)
{
	srand(time(NULL));
	L=(List)malloc(sizeof(SqList));
    L->length =LISTSIZE;
    int i=0;
	for( i=0;i<LISTSIZE;i++)
	{
		(L->elem[i]).num=i;
		(L->elem[i]).password= rand()%LISTSIZE-LISTSIZE/2;
		(L->elem[i]).flag=0;
	}
}
void display(List L)
{
	printf(" N-- P\n ");
	int i =0; 
	for(i=0;i<LISTSIZE;i++)
	{
		printf("%d-- %d\n ",i,(L->elem[i]).password);
	}
}
int notover(List L)
{
	int i,j=0;
	for(i=0;i<LISTSIZE;i++)
	{
	if ((L->elem[i]).flag==0) j=1;
	}
	return j;
}
void Joseph(List L,int m)
{
	int i,j=0,f=1;
	while(f)
	{
			for(i=0;j<abs(m);i=(i+1)%LISTSIZE)  {if((L->elem[i]).flag==0) j++;}
		    m=(L->elem[i]).password;
			(L->elem[i]).flag=1;
			j=0;
			printf("%d  ",i);
			f=notover(L);
	}
}
void main()
{
	List L;
	Init(L);
	display(L);
	Joseph(L,1);
}

