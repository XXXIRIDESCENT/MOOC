#include<iostream>
using namespace std;
int sum = 0, upperlim, n;
void test(int row, int ld, int rd)//row��ld��rd�ֱ��ʾ�����к������Խ��߷����������������һ�е���Щ�ط����ܷ�
{
       if (row != upperlim)
       {
              int pos = upperlim & ~(row | ld | rd);//�����������������õ��������еĽ�λ
              while (pos)
              {
                      int p = pos & (~pos + 1);    //ȡ��pos�����ұߵ�1
                      pos -= p;
                      test(row + p, (ld + p) << 1, (rd + p) >> 1);
              }
       }
       else   sum++;
}
int main()
{
       cin >> n;
       upperlim = (1 << n) - 1;//n��1��ɵĶ�������
       test(0, 0, 0);
       cout << sum;
}
