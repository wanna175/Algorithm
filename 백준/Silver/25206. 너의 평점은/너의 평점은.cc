#include <bits/stdc++.h>

using namespace std;
string subject,n,score;
int total;
double sum,avg;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	for(int i=0;i<20;++i){
		cin>>subject>>n>>score;
		int num = n[0]-'0';
		if(score == "A+") sum+=num*4.5;
		else if(score == "A0") sum+=num*4.0;
		else if(score == "B+") sum+=num*3.5;
		else if(score == "B0") sum+=num*3.0;
		else if(score == "C+") sum+=num*2.5;
		else if(score == "C0") sum+=num*2.0;
		else if(score == "D+") sum+=num*1.5;
		else if(score == "D0") sum+=num*1.0;
		else if(score == "P") continue;
		total+=num;
	}
	avg = sum/total;
	cout << avg << '\n';
	return 0;
}