//�ݹ麯�������ҵ���
//eg: an=a(n-1)+3
//Ԥ֪��һ�������֪��ǰһ���ֵ

//ʹ�õݹ���ȱ�����
//��Ŀ������һ������������ȱ�����2��4��8��16��32 ...�ĵ�N���ֵ
//����һ������n
//���:һ���������ȱ����еĽ��
//�����6  ���64
#include<iostream>
using namespace std;
int faction(int n)   //����һ������ʵ��
{
    int res;  //����һ�����
    if (n==1) //������������
    {
        res=2;//����
    }
    else
    {
        res=faction(n-1)*2;//�������Ե���
    }
    return res;
}
int main0()
{
    cout<<"������һ������n:"<<endl;
    int n;
    cin >>n ;
    cout<<faction(n)<<endl;
    return 0;
}


//ʹ�õݹ�ʵ�ֺ�����׳�
//��5��=5*4*5*2*1��
//��Ŀ:����һ������n�����n�Ľ׳˽����
//����һ������n
//���:һ��������n!�Ľ��
//���룺5 �����120
int faction1(int n)
{
    int resu;
    if (n==1)
    {
        resu=1;
    }
    else
    {
        resu=faction1(n-1)*n;
    }
    return resu;
}
int main()
{
    cout<<faction1(5)<<endl;
    return 0;
}

