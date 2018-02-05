#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
string str,passwd,o;
ofstream fout;
ifstream fin;
int main(){
	cout<<"加载中......"<<endl;
	Sleep(1000); 
	while(1){
		cin.clear();
		cin.sync();
		system("cls");
		system("title 文本加密解密器");
		system("color f0");
		cout<<"文本加密解密器"<<endl<<"1.加密"<<endl<<"2.解密"<<endl<<"请输入命令："; 
		o[0]=getch();
		if(o[0]=='1'){
		 	system("cls");
			cout<<"请输入一行文本：";
			getline(cin,str);
			system("cls");
			cout<<"正在分析文本，请稍后......"<<endl;
			Sleep(1000);
			system("cls"); 
			cout<<"请输入密码：";
			getline(cin,passwd);
			system("cls");
			cout<<"正在分析密码，请稍后......"<<endl;
			Sleep(1000);
			system("cls");
			cout<<"加密中......"<<endl; 
			Sleep(1000);
			for(int i=0;i<str.length();i++)
				for(int j=0;j<passwd.length();j++)
					str[i]=str[i]+passwd[j];
		 	fout.open("密文.txt"); 
		 	fout<<str<<endl;
		 	fout.close(); 
		 	system("cls");
		 	cout<<"完成！"<<endl;
		 	system("pause");
		}
		if(o[0]=='2'){
			system("cls");
			cout<<"请输入密码：";
			getline(cin,passwd);
			system("cls");
			cout<<"正在分析密码，请稍后......"<<endl;
			Sleep(1000);
			system("cls");
			cout<<"解密中......"<<endl; 
			Sleep(1000);
			fin.open("密文.txt");
			getline(fin,str);
			for(int i=0;i<str.length();i++)
				for(int j=0;j<passwd.length();j++)
					str[i]=str[i]-passwd[j];
			fin.close();
			system("cls");
			cout<<"这是用"<<passwd<<"密钥解密的文本："<<endl;
			cout<<str<<endl;
		 	system("pause");
		}
	}
	return 0;
}
