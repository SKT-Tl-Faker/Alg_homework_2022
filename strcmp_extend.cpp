#include<iostream>
#include <string>
using namespace std;

const int N = 2000;

int main(void)
{	
	int f[2][N];
	string a, b;
	int k;
	cin >> a >> b;
	cin >> k;
	int len_a=a.length();
	int len_b=b.length();
	for (int i = 0; i < N; ++i){//����һ������i�����ַ���A���ַ�λ�ã�j����B��
		f[0][i] = k * i;
	}
	f[1][0]=k;
	//cout<<len_a<<' '<<len_b<<endl;
	for (int i = 1; i <= len_a ; ++i){
		for (int j = 1; j <= len_b; ++j){
			f[1][j] = min(min(f[0][j], f[1][j - 1]) + k, f[0][j-1] + abs(a[i - 1] - b[j - 1]));
		} 
		for(int m=0;m<N;m++){//ÿ�μ���ֻ��Ҫ2�У���ʡ�ռ䡣ÿһ��֮��ѵڶ����Ƶ���һ��
			f[0][m]=f[1][m];
		}
		f[1][0]=k*(i+1);
	}
	cout << f[0][len_b] << endl;

	return 0;
}