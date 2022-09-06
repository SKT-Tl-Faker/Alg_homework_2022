#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

struct node{
	double x;
	double y;
};
double get_distance(node a,node b){
	return (a.y-b.y)*(a.y-b.y)+(a.x-b.x)*(a.x-b.x);
}
bool cmp_y(node a,node b){//y����
	return a.y<b.y;
}
bool cmp_x(node a,node b){//x����
	return a.x<b.x;
}
double min_dis=10000.0;//��С���룬��ʼ��Ϊ�ϴ����

double calcu(node *n,int start,int end){//nodes[i][0] is x��[i][1] is y;�±���s��e�ķ�Χ�ڣ�������
	int length = end-start + 1;
	if(length<=3){//�ܳ���С��=3ֱ��Ѱ��
		switch(length){
		case 3:{
				double min1=min(get_distance(n[start], n[start+1]),get_distance(n[start], n[end]));
				double min2=min(min1,get_distance(n[start+1], n[end]));
				return  min2;
			   }
		case 2:
			return get_distance(n[start],n[end]);
		}
	}
	int mid=(start+end)/2;
    min_dis = min(calcu(n,start,mid), calcu(n,mid + 1,end));
        
    //�鲢���ж����ҵĵ��Ƿ���̵ľ���
    //ֻ��x-mid.x<min_dis�ĵ���п��ܸ�������gap
    node* gap = new node[length];
    int possibleNum = 0;
    for(int i = start; i <= end; i++) {
        if(abs(n[i].x - n[mid].x) < min_dis) {
            gap[possibleNum] = n[i];
            ++possibleNum;
        }
    }
    // ������������������Լ��ٱȽϴ���
    sort(gap, gap + possibleNum, cmp_y);
    // �����Ƚ�gap�ľ���
    for(int i = 0; i < possibleNum - 1; ++i) {
        for(int j = i + 1; j < possibleNum; ++j) {
            // ���j�����������i���������Ĳ���Ѿ�����Ŀǰ����̾��룬��ʣ�µĵ�Ͳ��ñȽ���
            if(gap[j].y - gap[i].y > min_dis) {
                break;
            }else {
                min_dis = min(min_dis, get_distance(gap[i], gap[j]));
            }
        }
    }     
    // �ͷ���Դ
    delete [] gap;

	return min_dis;
}

int main(){
	int n;
	cin>>n;
	node *px=new node [n];
	for(int i=0;i<n;i++){
		cin>>px[i].x>>px[i].y;
	}
	sort(px,px+n,cmp_x);
	float result=calcu(px,0,n-1);
	printf("%.2f",result);
	
	delete []px;
}