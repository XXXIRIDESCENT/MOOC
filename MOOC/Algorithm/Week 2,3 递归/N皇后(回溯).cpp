#include<iostream>
#include<cmath>
using namespace std;
int main()
{    
    int n,a[9],c=0,i,k=1;
    cin>>n;
    a[k]=1;
    while(k>0)
        if(k<=n&&a[k]<=n)
        {
            for(i=1;i<k;i++)
                if(a[i]==a[k]||abs(a[i]-a[k])==k-i)    break;
            if(i==k)
            {
                k++;        //��K�е�λ���Ѿ�ȷ���ˣ�����Ѱ�ҵ�k+1�лʺ��λ��
                a[k]=1;     //�ӵ�һ�п�ʼ����
            }    
            else    a[k]++; //����̽�⵱ǰ�е���һ�У�a[k]+1  
        }
        else
        {
            if(k>n)    c++;
            k--;      //����λ�ò�����Ҫ�����˻�ǰһ��
            a[k]++;   //������̽��һ��λ��
        }
    cout<<c;
}
