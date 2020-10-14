#include<iostream>
#include<string.h>
using	namespace	std;

#define	OK	1
#define	ERROR	0
#define	MAXSIZE	255
#define	OVERFLOW	-2

typedef	int		Status;
typedef	char	HElemType;

typedef	struct{
	char	*ch;
	int	length;
}HString;

Status	InitString(HString	&S);
Status	GetSon(HString	S,int	e,int	f);
Status	Delete(HString	&S,int	h,int	i);
Status	StrAssign(HString	&S,char	*chars);
Status	Change(HString	&S1,HString	S2,int	a,int	b); 
Status	BF(HString	S,HString	T,int	pos);

int	main()
{
	HString	S;
	InitString(S); 
	int	z;
	do{
		cout<<endl;
		cout<<"字符串操作："<<endl;
		cout<<"1-比较 2-连接 3-取字串 4-删除 5-替换 6-BF模式匹配 7-退出"<<endl;
		cout<<"请选择功能：";
		cin>>z;
		switch(z){
			case	1:
				HString	S5,S6;
				char	a[100],b[200]; 
				cout<<"请输入第一个字符串："<<endl;
				scanf("%s",a);
				StrAssign(S5,a);
				cout<<"请输入第二个字符串："<<endl;
				scanf("%s",b);
				StrAssign(S6,b);
				if(strcmp(S5.ch,S6.ch)==0)
					cout<<S5.ch<<"和"<<S6.ch<<"是相等的！"<<endl;
				else	cout<<S5.ch<<"和"<<S6.ch<<"不是相等的！"<<endl;
				break;
			case	2:
				HString	S7,S8;
				char	c[100],d[200]; 
				cout<<"请输入第一个字符串："<<endl;
				scanf("%s",c);
				StrAssign(S7,c);
				cout<<"请输入第二个字符串："<<endl;
				scanf("%s",d);
				StrAssign(S8,d);
				cout<<S7.ch<<"和"<<S8.ch<<"连接后的结果为：";
				strcat(S7.ch,S8.ch);
				cout<<S7.ch<<endl;
				break;
			case	3:
				HString	S1;
				char	e[100];
				cout<<"请输入主串"<<endl;
				scanf("%s",e);
				StrAssign(S1,e);
				cout<<"请输入要取子串的起始位置号:"<<endl;
				int	g,f;
				cin>>g;
				cout<<"请输入要取子串的长度："<<endl;
				cin>>f;
				GetSon(S1,g,f);
				break;
			case	4:
				HString	S2;
				char	p[100];
				cout<<"请输入主串"<<endl;
				scanf("%s",p);
				StrAssign(S2,p);
				cout<<"请输入要删除子串的起始位置号:"<<endl;
				int	h,i;
				cin>>h;
				cout<<"请输入要删除子串的长度："<<endl;
				cin>>i;
				cout<<"删掉"<<S2.ch<<"的第"<<h<<"个字符开始长度为"<<i<<"的子串后结果为：";
				Delete(S2,h,i);
				cout<<S2.ch;
				break;
			case	5:
				HString	S3,S4;
				char	q[100];
				int	v,zx;
				cout<<"请输入主串"<<endl;
				scanf("%s",q);
				StrAssign(S3,q);
				cout<<"请输入替换串："<<endl;
				char	t[100];
				scanf("%s",t);
				StrAssign(S4,t);
				cout<<"请输入要替换的子串的起始位置号：";
				cin>>v;
				cout<<"请输入要替换的子串的长度：";
				cin>>zx;
				cout<<"将"<<S3.ch<<"的第"<<v<<"个字符开始长度为"<<zx<<"的子串用"<<S4.ch<<"替换后的结果为："; 
				Change(S3,S4,v,zx);
				cout<<S3.ch;
				cout<<endl;
				break;
			case	6:
				HString	SS,RR;
				int	wz;
				char	QQ[100],rr[100];
				cout<<"请输入主串"<<endl;
				scanf("%s",QQ);
				StrAssign(SS,QQ);
				cout<<"请输入模式串:"<<endl;
				scanf("%s",rr);
				StrAssign(RR,rr);
				cout<<"请输入主串中起始匹配位置号："<<endl;
				cin>>wz;
				int	gg=BF(SS,RR,wz);
				if(gg!=0)	cout<<RR.ch<<"从"<<SS.ch<<"的第"<<gg<<"个字符处匹配成功"<<endl;
				else	cout<<"匹配不成功"<<endl;
				break;
			
		}
	}while(z!=7);
	return	0;
}
Status	InitString(HString	&S){
	S.ch=new	HElemType[MAXSIZE];
	if(!S.ch)	return	OVERFLOW;
	S.length=0;
	return	OK;
}
Status	GetSon(HString	S,int	e,int	f){
	HString	Q;
	Q.ch=new	char[f];
	int	j=0;
	for(int	i=e-1;i<e-1+f;i++){
		Q.ch[j++]=S.ch[i];
	}
	Q.ch[j]='\0';
	cout<<"从"<<S.ch<<"的第"<<e<<"个字符开始长度为"<<f<<"的子串后结果为"<<Q.ch<<endl;
	return	OK;
}
Status	Delete(HString	&S,int	h,int	i){
	int	j;
	int	k=h-1;
	for(j=0;j<i;j++)
	{
		S.ch[k]=S.ch[k+i];
		S.length--;
		k++;
	}
	S.ch[S.length+1]='\0';
	return	OK;
	
}
Status	StrAssign(HString	&S,char	*chars)
{
	int	len,j;
	len=strlen(chars);
	if(!len){
		S.ch=NULL;
		S.length=0;
	}
	else{
		S.ch=new	char[len+1];
		if(!S.ch)	return	OVERFLOW;
		for(j=0;j<len;j++)
			S.ch[j]=chars[j];
			S.length=len;
			S.ch[len]='\0';
	}
	return	OK;
}
Status	Change(HString	&S1,HString	S2,int	a,int	b){
	--b;
	int	i=0,j=b;
	for(;S1.ch[j]!='\0';++j)
	{
		if(S2.ch[i]!='\0')
		{
			S1.ch[j]=S2.ch[i];
			++i;
		}
		else
		{
			break;
		}
	}
	return	OK;
}
Status	BF(HString	S,HString	T,int	pos)
{
	int	i=pos-1,j=0;
	while(i<S.length&&j<T.length){
		if(S.ch[i]==T.ch[j]){
			++i;
			++j;
		}
		else	{
			i=i-j+1;
			j=0;
		}
	}
	if(j==T.length)	return	i-T.length+1;
	else	return	0;
}
