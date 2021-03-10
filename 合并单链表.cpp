#include<iostream>
using	namespace	std;

#define	OK	1
#define	ERROR	0
#define	MAXSIZE	100
#define	OVERFLOW	-2

typedef	int	Elemtype;
typedef	int	Status;
typedef	struct
{
	Elemtype	*elem;
	int	length;
}Sqlist;

Status	Initlist(Sqlist	&L);
Status	creatlist(Sqlist	&L,int	a[],int	n);
void	Mergelist(Sqlist	La,Sqlist	Lb,Sqlist	&Lc);
Status	Listinsert(Sqlist	&L,Elemtype	x);

int	main()
{
	Sqlist	La,Lb,Lc;
	int	z;
	Elemtype	a[MAXSIZE],b[MAXSIZE];
	int	n,i,m;
	Initlist(La);
	Initlist(Lb);
	cout<<"请输入La中的元素个数：";
	cin>>n;
	cout<<"请输入元素:";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	creatlist(La,a,n);
	cout<<"请输入Lb中的元素个数：";
	cin>>m;
	cout<<"请输入元素:";
	for(i=0;i<m;i++){
		cin>>b[i];
	}
	creatlist(Lb,b,m);
	cout<<"调整后La为:";
	for(i=0;i<La.length;i++)
	{
		cout<<La.elem[i]<<' ';
	}
	cout<<endl;
	cout<<"调整后Lb为:";
	for(i=0;i<Lb.length;i++)
	{
		cout<<Lb.elem[i]<<' ';
	}
	cout<<endl;
	Mergelist(La,Lb,Lc);
	cout<<"合并之后结果为:";
	for(i=0;i<Lc.length;i++)
	{
		cout<<Lc.elem[i]<<' ';
	}
}
Status	Initlist(Sqlist	&L)
{
	L.elem=new	Elemtype[MAXSIZE];
	if(!L.elem)	return	OVERFLOW;
	L.length=0;
	return	OK;
}
Status	creatlist(Sqlist	&L,int	a[],int	n)
{
	int	i,j;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			L.elem[i]=a[i];
			L.length++;
		}
		else
		{
			for(j=0;j<L.length;j++)
			if(a[i]<=L.elem[j])
			break;
			Listinsert(L,a[i]);
		}
	}
}
Status	Listinsert(Sqlist	&L,Elemtype	x)
{
	int i;
	if(L.length+1>MAXSIZE) 
		return ERROR;
	for(i=L.length-1;L.elem[i]>x && i>=0;i--)
		L.elem[i+1]=L.elem[i];
	L.elem[i+1]=x;
	L.length++;
	return OK;
}
void	Mergelist(Sqlist	La,Sqlist	Lb,Sqlist	&Lc)
{
	Elemtype *pa,*pb,*pc,*pa1,*pb1; 
	pa=La.elem; pb=Lb.elem;
	Lc.length=Lc.length=La.length+Lb.length;
	pc=Lc.elem=new Elemtype[Lc.length];
	pa1=La.elem+La.length-1;
	pb1=Lb.elem+Lb.length-1;
	while(pa<=pa1 && pb<=pb1)
	{
		if(*pa<=*pb)
			*pc++=*pa++;
		else
			*pc++=*pb++; 
	 } 
	 while(pa<=pa1)
	 	*pc++=*pa++;
	 while(pb<=pb1)
	 	*pc++=*pb++;
}
