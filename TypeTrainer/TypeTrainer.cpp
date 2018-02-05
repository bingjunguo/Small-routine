#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
ifstream fin;
bool f;
char sentence[100000000],input[100000000];
string finsentence,fininput;
double ac;
int len;
int main(){  
	fin.open("TEXT.TYPETRAINER"); 
	cout<<"请选择文本来源："<<endl<<"1.文件"<<endl<<"0.随机"<<endl; 
	cin>>f;
	for(len=ac=100;;len+=100,ac=100.0){
	    system("cls");
	    cout<<len<<"字符文本"<<endl; 
		if(f){
	    	getline(fin,finsentence);
			for(int i=0;i<len;i++)
				cout<<finsentence[i];
	    }
	    if(!f){
			srand(time(0)); 
			for(int i=0;i<len;i++){
				sentence[i]=char(65+rand()%(65-122+1));
				cout<<sentence[i];
			}
		}
		Sleep(3000);
		cout<<endl<<"计时开始！"<<endl;
		double start,stop,durationTime;
		start = clock();
		if(f) getline(cin,fininput);
		if(!f)
		for(int i=0;i<len;i++)
			 cin>>input[i];
		for(int i=0;i<len;i++)
			if(sentence[i]!=input[i]&&!f||finsentence[i]!=fininput[i]&&f) ac-=100/double(len);
		stop = clock();
	    durationTime = ((double)(stop-start))/CLK_TCK;
	    cout<<"计时结束！"<<endl; 
	    system("cls");
	    cout<<"您一共花费："<<durationTime<<" 秒完成"<<len<<"个字符的打字测试！"<<endl;
	    cout<<"正确率："<<ac<<"%"<<endl; 
	    cout<<"您的打字速度："<<len/(durationTime/60)<<"字符/分钟"<<endl; 
	    cout<<"您的正确打字速度："<<len/(durationTime/60)*(ac*0.01)<<"字符/分钟"<<endl; 
	    cout<<"加油！"<<endl; 
	    Sleep(1000);
	    system("pause");
	}
}
