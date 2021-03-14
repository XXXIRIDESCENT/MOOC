#include<iostream>
#include<cstring>
using namespace std;
void flip(char& a,int j)
{
	a ^= (1 << j);
}
int main()
{
	char a[5] = { 0 }, b[5];
	int n;
	cin >> n;
	for (int x = 1;x <= n;x++) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 6; j++)
			{
				int t;
				cin >> t;
				if (t) a[i] |= (1 << j);
				else a[i] &= ~(1 << j);
			}
		for (int i = 0;i < 64;i++)
		{
			b[0] = i;
			char l = a[0]; //l��ʾ���е�״̬
			for (int j = 0;j < 5;j++)
			{
				for (int k = 0; k < 6; k++)
				{
					if ((b[j] >> k) & 1) //��b[j]�ĵ�kλΪ1����ת���������Ƶ�״̬
					{
						if (k > 0) flip(l, k - 1);
						flip(l, k);
						if (k < 5) flip(l, k + 1);
					}
				}
				if (j < 4) {
					b[j+1] = l; //l��ʾ���еƾ����غ�ʣ������ƣ�����һ�ж�Ӧ�����
					l = a[j + 1] ^ b[j]; //l��ʾ���е�״̬
				}
					
			}
			if (l == 0) break;
		}
		cout << "PUZZLE #" << x << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 6; j++) {
				cout << ((b[i] >> j) & 1);
				if (i < 5) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
