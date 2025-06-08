// ## 5 �ļ�����
// ��������ʱ���������ݶ�������ʱ���ݣ�����һ�����н������ᱻ�ͷ�
// ͨ��**�ļ����Խ����ݳ־û�**
// C++�ж��ļ�������Ҫ����ͷ�ļ� ==&lt; fstream &gt;=
// �ļ����ͷ�Ϊ���֣�
// 1. **�ı��ļ�**     -  �ļ����ı���**ASCII��**��ʽ�洢�ڼ������
// 2. **�������ļ�** -  �ļ����ı���**������**��ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������
// �����ļ���������:
// 1. ofstream��д����
// 2. ifstream�� ������
// 3. fstream �� ��д����
// ### 5.1�ı��ļ�
// #### 5.1.1д�ļ�
//    д�ļ��������£�
// 1. ����ͷ�ļ�
//    \#include <fstream\>
// 2. ����������
//    ofstream ofs;
// 3. ���ļ�
//    ofs.open("�ļ�·��",�򿪷�ʽ);
// 4. д����
//    ofs << "д�������";
// 5. �ر��ļ�
//    ofs.close();
//�򿪷�ʽ
// | �򿪷�ʽ    | ����                       |
// | ----------- | -------------------------- |
// | ios::in     | Ϊ���ļ������ļ�         |
// | ios::out    | Ϊд�ļ������ļ�         |
// | ios::ate    | ��ʼλ�ã��ļ�β           |
// | ios::app    | ׷�ӷ�ʽд�ļ�             |
// | ios::trunc  | ����ļ�������ɾ�����ٴ��� |
// | ios::binary | �����Ʒ�ʽ                 |
// **ע�⣺** �ļ��򿪷�ʽ�������ʹ�ã�����|������
// **���磺**�ö����Ʒ�ʽд�ļ� `ios::binary |  ios:: out`
#include <fstream>
void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs << "����������" << endl;
    ofs << "�Ա���" << endl;
    ofs << "���䣺18" << endl;
    ofs.close();
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺
// * �ļ������������ͷ�ļ� fstream
// * ���ļ��������� ofstream  ������fstream��
// * ���ļ�ʱ����Ҫָ�������ļ���·�����Լ��򿪷�ʽ
// * ����<<�������ļ���д����
// * ������ϣ�Ҫ�ر��ļ�


// #### 5.1.2���ļ�
// ���ļ���д�ļ��������ƣ����Ƕ�ȡ��ʽ����ڱȽ϶�
// ���ļ��������£�
// 1. ����ͷ�ļ�
//    \#include <fstream\>
// 2. ����������
//    ifstream ifs;
// 3. ���ļ����ж��ļ��Ƿ�򿪳ɹ�
//    ifs.open("�ļ�·��",�򿪷�ʽ);
// 4. ������
//    ���ַ�ʽ��ȡ
// 5. �ر��ļ�
//    ifs.close();
#include <fstream>
#include <string>
void test01()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //��һ�ַ�ʽ
    //char buf[1024] = { 0 };
    //while (ifs >> buf)
    //{
    //	cout << buf << endl;
    //}
    //�ڶ���
    //char buf[1024] = { 0 };
    //while (ifs.getline(buf,sizeof(buf)))
    //{
    //	cout << buf << endl;
    //}
    //������
    //string buf;
    //while (getline(ifs, buf))
    //{
    //	cout << buf << endl;
    //}
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }
    ifs.close();
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺
// - ���ļ��������� ifstream  ������fstream��
// - ����is_open���������ж��ļ��Ƿ�򿪳ɹ�
// - close �ر��ļ�



// ### 5.2 �������ļ�
// �Զ����Ƶķ�ʽ���ļ����ж�д����
// �򿪷�ʽҪָ��Ϊ ==ios::binary==
// #### 5.2.1 д�ļ�
// �����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
// ����ԭ�� ��`ostream& write(const char * buffer,int len);`
// �������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���
#include <fstream>
#include <string>
class Person
{
public:
    char m_Name[64];
    int m_Age;
};
//�������ļ�  д�ļ�
void test01()
{
    //1������ͷ�ļ�
    //2���������������
    ofstream ofs("person.txt", ios::out | ios::binary);
    //3�����ļ�
    //ofs.open("person.txt", ios::out | ios::binary);
    Person p = {"����"  , 18};
    //4��д�ļ�
    ofs.write((const char *)&p, sizeof(p));
    //5���ر��ļ�
    ofs.close();
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺ �ļ���������� ����ͨ��write�������Զ����Ʒ�ʽд����


// #### 5.2.2 ���ļ�
// �����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
// ����ԭ�ͣ�`istream& read(char *buffer,int len);`
// �������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���
// ʾ����
#include <fstream>
#include <string>
class Person
{
public:
    char m_Name[64];
    int m_Age;
};
void test01()
{
    ifstream ifs("person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
    }
    Person p;
    ifs.read((char *)&p, sizeof(p));
    cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ļ����������� ����ͨ��read�������Զ����Ʒ�ʽ������