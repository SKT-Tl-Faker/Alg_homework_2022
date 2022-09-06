#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

void main(){
	int n;
	cin>>n;
	priority_queue <int,vector<int>,greater<int> > leaves;
	priority_queue <int,vector<int>,greater<int> > leaves_2;
	priority_queue<int,vector<int>,greater<int> > nodes;//���Ҷ�ڵ�Ȩ��
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		leaves.push(a);
		leaves_2.push(a);
	}
	for(int i=0;i<n-1;i++){
		int temp=leaves.top();
		leaves.pop();
		temp+=leaves.top();
		leaves.pop();
		leaves.push(temp);//Ҷ�ӽڵ��ں�����С��
		nodes.push(temp);//nodes���������Ҷ�ڵ�
	}
	int sum1=0,sum2=0;//Ҷ��/��ҶȨ�غ�
	for(int i=0;i<n;i++){
		sum1+=leaves_2.top();
		leaves_2.pop();
	}
	for(int i=0;i<n-1;i++){
		sum2+=nodes.top();
		nodes.pop();
	}
	cout.setf(ios::fixed);
	//���ù��ɣ�ƽ�����볤��=��ҶȨ�غ�/Ҷ��Ȩ�غ�
	cout<<setprecision(2)<<(float)sum2/sum1;
}
