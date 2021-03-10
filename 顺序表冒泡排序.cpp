#include <iostream>
using namespace std;

#define maxsize 100
#define ok 1
#define error 0
#define overflow -2

typedef int Elemtype;
typedef int Status;
//定义顺序表 
typedef struct list
{
	Elemtype *elem;
	int length;
}sqlist;
//初始化顺序表 
Status initList(sqlist &L)
{
	L.elem=new Elemtype[maxsize];
	if(!L.elem)
	exit(overflow);
	L.length=0;
	return ok;
}
//创建顺序表 
Status Creatlist(sqlist &L,Elemtype a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	L.elem[i]=a[i];
	L.length=n;
	return ok;
}
//冒泡排序
Status Bubblesort(sqlist &L)
{
	int i,j,t,q;
	for(i=1;i<L.length;i++)
	{
		for(j=0;j<L.length-1;j++)
		
		{
			if(L.elem[j]>L.elem[j+1])
			{
				t=L.elem[j+1];
				L.elem[j+1]=L.elem[j];
				L.elem[j]=t;
			}
		}
	}
	cout<<"排序后结果为：";
	for(q=0;q<L.length;q++)
	cout<<L.elem[q]<<' ';
	return ok;
} 
//清空程顺序表 
Status Displist(sqlist &L)
{
	delete []L.elem;
	L.length=0;
	return ok;
}

int main()
{
	sqlist L;
	initList(L);
	int n,i;
	cout<<"输入元素的个数为：";
	cin>>n;
	Elemtype a[maxsize];
	cout<<"请输入元素:";
	for(i=0;i<n;i++)
		cin>>a[i];
	Creatlist(L,a,n);
	//冒泡排序 
	Bubblesort(L);
	
	Displist(L);
	
    return 0;
} 
