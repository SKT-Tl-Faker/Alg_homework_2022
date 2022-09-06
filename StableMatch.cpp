#include <iostream>
using namespace std;

int invite(int inviter,int invited,int *list,int *invited_check){
	if(invited_check[invited]<0)//��û������,return 1
		return 1;
	if(list[inviter]<list[invited_check[invited]])//�����ߵ������ȵ�ǰ�Ķ����,return 2
		return 2;
	return 0;
}
void initial(int *a,int n,int target){//a[n]��ʼ��Ϊtarget
	for(int i=0;i<n;i++)
		a[i]=target;
}

int match(int *result,int **womanprefer,int **manprefer,int n){
	int *womans_man=new int[n];//�±��ʾ���ܵĶ���-1��ʾ��û������
	int *mans_woman=new int[n];
	int *mychance=new int[n];
	int **womanchangelist=new int*[n];//ת�ù���Ů����prefer,�±�������index��ֵΪ����
	for(int i=0;i<n;i++){
		womanchangelist[i]=new int[n];
		for(int j=0;j<n;j++)
			womanchangelist[i][womanprefer[i][j]]=j;
	}
	initial(result,n,-1);//��ʼ�����
	initial(womans_man,n,-1);//������ȷ��ƥ��ı���-1
	initial(mans_woman,n,-1);
	initial(mychance,n,n);//ÿ����������n�λ���

	for(int i=0;i<n;i++){//go inviting
		if(mans_woman[i]>=0||mychance[i]<1)//��ǰ�е��Ѿ��ж����˻���û�����ˣ�����һ���е�
			continue;
		//cout<<endl;�е�ע���ǵ����õģ����ù�
		for(int j=0;j<n;j++){//��i���������j��Ŀ�귢������,manprefer[i][j]ΪŮ�����
			//cout<<"1 ";
			mychance[i]--;//�������-1
			int end=invite(i,manprefer[i][j],womanchangelist[manprefer[i][j]],womans_man);//������
			if(end==2){//����ɹ���������ĳ��
				int kicked=womans_man[manprefer[i][j]];//���ߵ���ǰ����
				mans_woman[kicked]=-1;//��ǰ�еı�˦
				womans_man[manprefer[i][j]]=i;//��������λ
				mans_woman[i]=manprefer[i][j];//��Ů����λ
				i=kicked-1;//��ô���ߵ���������ѡ��,i��++���ʼ�һ
				break;//����ȥ���Ǹ�ʧ����������
			}
			else if(end==1){
				womans_man[manprefer[i][j]]=i;//��������λ
				mans_woman[i]=manprefer[i][j];//��Ů����λ
				break;//�������
			}
			else continue;//ʧ���ˣ���һ��Ů��
		}
	}	
	//cout<<"\nyes";
	for(int i=0;i<n;i++)//ֵ����ȥ
		result[i]=mans_woman[i];
	for(int j=0;j<n;j++){
		delete []womanchangelist[j];
	}
	delete []womanchangelist;
	delete []womans_man;
	delete []mans_woman;
	delete []mychance;
	return *result;
}

int main(){
	int n;//men and women
	cout<<"Please input n\n";
	cin>>n;
	cout<<"Now input lists\n";
	int **manprefer=new int *[n];
	int **womanprefer=new int *[n];
	for(int i=0;i<n;i++){
		manprefer[i]=new int[n];
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			manprefer[i][j]=x-1;//�����Ǵ�1��ʼ�ģ�Ҫ��0��ʼ
		}
	}
	for(int i=0;i<n;i++){
		womanprefer[i]=new int[n];
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			womanprefer[i][j]=x-1;
		}
	}
	int *result=new int[n];
	match(result,womanprefer,manprefer,n);
	for(int i=0;i<n;i++){
		cout<<result[i]+1;
		if(i!=n-1)
			cout<<' ';
		else cout<<"\n";           
	}
	for(int j=0;j<n;j++){
		delete []manprefer[j];
		delete []womanprefer[j];
	}
	delete []result;
	delete []manprefer;
	delete []womanprefer;
}