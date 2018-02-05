#include <windows.h>
#include <iostream>
#include <string> 
#include <conio.h>
#include <map>
#include <set> 
using namespace std;
struct person{
	string name;
	int vote;
};
person z;
struct cmp{
	bool operator()(const person&x,const person&y)const{
		if(x.vote<y.vote) return 0;
		if(x.vote>y.vote) return 1;
		if(x.name<y.name) return 1;
		return 0;
	}
};
map<string,int> info;
map<string,int>::iterator it;
set<person,cmp> output;
set<person,cmp>::iterator outputit;
string name;
int main(){
	info.clear(); output.clear();
	system("cls");
	system("title 投票系统");
	system("color f0");
	cout<<"请输入投票信息（人名之间用空格隔开，输入Ctrl+Z停止）：";
	while(cin>>name) info[name]++;
	cout<<"输入结束！"<<endl;
	cin.clear(); cin.sync();
	Sleep(1000);
	system("cls");
	cout<<"正在统计信息......"<<endl;
	for(it=info.begin();it!=info.end();it++){
		z.name=it->first; z.vote=it->second;
		output.insert(z);
	}
	Sleep(1000); 
	system("cls");
	cout<<"以下为投票信息："<<endl; 
	for(outputit=output.begin();outputit!=output.end();outputit++){
		cout<<outputit->name;
		for(int i=15;i>=outputit->name.length();i--) cout<<" ";
		cout<<"票数："<<outputit->vote<<endl;
	}
	cout<<endl<<"是否重新开始？（Y/N）"<<endl;
	name[0]=getch();
	if(name[0]=='Y'||name[0]=='y') main();
	return 0;
}
