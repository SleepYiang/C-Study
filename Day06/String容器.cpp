// ### 3.1 string����
// #### 3.1.1 string��������
// **���ʣ�**
// * string��C++�����ַ�������string��������һ����
// **string��char * ����**
// * char * ��һ��ָ��
// * string��һ���࣬���ڲ���װ��char\*����������ַ�������һ��char*�͵�������
// **�ص㣺**
// string ���ڲ���װ�˺ܶ��Ա����
// ���磺����find������copy��ɾ��delete �滻replace������insert
// string����char*��������ڴ棬���õ��ĸ���Խ���ȡֵԽ��ȣ������ڲ����и���


// #### 3.1.2 string���캯��
// ���캯��ԭ��
// `string();`          				//����һ���յ��ַ��� ����: string str;
// `string(const char* s);`	           //ʹ���ַ���s��ʼ��
// `string(const string& str);`       //ʹ��һ��string�����ʼ����һ��string����
// `string(int n, char c);`          //ʹ��n���ַ�c��ʼ��
#include <string>
//string����
void test01()
{
    string s1; //�������ַ����������޲ι��캯��
    cout << "str1 = " << s1 << endl;
    const char* str = "hello world";
    string s2(str); //��c_stringת������string
    cout << "str2 = " << s2 << endl;
    string s3(s2); //���ÿ������캯��
    cout << "str3 = " << s3 << endl;
    string s4(10, 'a');
    cout << "str3 = " << s3 << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺string�Ķ��ֹ��췽ʽû�пɱ��ԣ����ʹ�ü���



// #### 3.1.3 string��ֵ����
// ����������
// * ��string�ַ������и�ֵ
// ��ֵ�ĺ���ԭ�ͣ�
// * `string& operator=(const char* s);`             //char*�����ַ��� ��ֵ����ǰ���ַ���
// * `string& operator=(const string &s);`         //���ַ���s������ǰ���ַ���
// * `string& operator=(char c);`                          //�ַ���ֵ����ǰ���ַ���
// * `string& assign(const char *s);`                  //���ַ���s������ǰ���ַ���
// * `string& assign(const char *s, int n);`     //���ַ���s��ǰn���ַ�������ǰ���ַ���
// * `string& assign(const string &s);`              //���ַ���s������ǰ�ַ���
// * `string& assign(int n, char c);`                  //��n���ַ�c������ǰ�ַ���
//��ֵ
void test01()
{
    string str1;
    str1 = "hello world";
    cout << "str1 = " << str1 << endl;
    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;
    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;
    string str4;
    str4.assign("hello c++");
    cout << "str4 = " << str4 << endl;
    string str5;
    str5.assign("hello c++",5);
    cout << "str5 = " << str5 << endl;
    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;
    string str7;
    str7.assign(5, 'x');
    cout << "str7 = " << str7 << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺ string�ĸ�ֵ��ʽ�ܶ࣬`operator=`  ���ַ�ʽ�ǱȽ�ʵ�õ�



// #### 3.1.4 string�ַ���ƴ��
// **����������**
// * ʵ�����ַ���ĩβƴ���ַ���
// **����ԭ�ͣ�**
// * `string& operator+=(const char* str);`                   //����+=������
// * `string& operator+=(const char c);`                         //����+=������
// * `string& operator+=(const string& str);`                //����+=������
// * `string& append(const char *s); `                               //���ַ���s���ӵ���ǰ�ַ�����β
// * `string& append(const char *s, int n);`                 //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
// * `string& append(const string &s);`                           //ͬoperator+=(const string& str)
// * `string& append(const string &s, int pos, int n);`//�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
//�ַ���ƴ��
void test01()
{
    string str1 = "��";
    str1 += "������Ϸ";
    cout << "str1 = " << str1 << endl;
    str1 += ':';
    cout << "str1 = " << str1 << endl;
    string str2 = "LOL DNF";
    str1 += str2;
    cout << "str1 = " << str1 << endl;
    string str3 = "I";
    str3.append(" love ");
    str3.append("game abcde", 4);
    //str3.append(str2);
    str3.append(str2, 4, 3); // ���±�4λ�ÿ�ʼ ����ȡ3���ַ���ƴ�ӵ��ַ���ĩβ
    cout << "str3 = " << str3 << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺�ַ���ƴ�ӵ����ذ汾�ܶ࣬��ѧ�׶μ�ס���ּ���


// #### 3.1.5 string���Һ��滻
// **����������**
// * ���ң�����ָ���ַ����Ƿ����
// * �滻����ָ����λ���滻�ַ���
// **����ԭ�ͣ�**
// * `int find(const string& str, int pos = 0) const;`              //����str��һ�γ���λ��,��pos��ʼ����
// * `int find(const char* s, int pos = 0) const; `                     //����s��һ�γ���λ��,��pos��ʼ����
// * `int find(const char* s, int pos, int n) const; `               //��posλ�ò���s��ǰn���ַ���һ��λ��
// * `int find(const char c, int pos = 0) const; `                       //�����ַ�c��һ�γ���λ��
// * `int rfind(const string& str, int pos = npos) const;`      //����str���һ��λ��,��pos��ʼ����
// * `int rfind(const char* s, int pos = npos) const;`              //����s���һ�γ���λ��,��pos��ʼ����
// * `int rfind(const char* s, int pos, int n) const;`              //��pos����s��ǰn���ַ����һ��λ��
// * `int rfind(const char c, int pos = 0) const;  `                      //�����ַ�c���һ�γ���λ��
// * `string& replace(int pos, int n, const string& str); `       //�滻��pos��ʼn���ַ�Ϊ�ַ���str
// * `string& replace(int pos, int n,const char* s); `                 //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
//���Һ��滻
void test01()
{
    //����
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    if (pos == -1)
    {
        cout << "δ�ҵ�" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;
}
void test02()
{
    //�滻
    string str1 = "abcdefgde";
    str1.replace(1, 3, "1111");
    cout << "str1 = " << str1 << endl;
}
int main() {
    //test01();
    //test02();
    system("pause");
    return 0;
}
// �ܽ᣺
// * find�����Ǵ�������rfind��������
// * find�ҵ��ַ����󷵻ز��ҵĵ�һ���ַ�λ�ã��Ҳ�������-1
// * replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ���


// ####    3.1.6 string�ַ����Ƚ�
// **����������**
// * �ַ���֮��ıȽ�
// **�ȽϷ�ʽ��**
// * �ַ����Ƚ��ǰ��ַ���ASCII����жԱ�
// = ����   0
// \> ����   1
// < ����  -1
// **����ԭ�ͣ�**
// * `int compare(const string &s) const; `  //���ַ���s�Ƚ�
// * `int compare(const char *s) const;`      //���ַ���s�Ƚ�
//�ַ����Ƚ�
void test01()
{
    string s1 = "hello";
    string s2 = "aello";
    int ret = s1.compare(s2);
    if (ret == 0) {
        cout << "s1 ���� s2" << endl;
    }
    else if (ret > 0)
    {
        cout << "s1 ���� s2" << endl;
    }
    else
    {
        cout << "s1 С�� s2" << endl;
    }

}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺�ַ����Ա���Ҫ�����ڱȽ������ַ����Ƿ���ȣ��ж�˭��˭С�����岢���Ǻܴ�



// #### 3.1.7 string�ַ���ȡ
// string�е����ַ���ȡ��ʽ������
// * `char& operator[](int n); `     //ͨ��[]��ʽȡ�ַ�
// * `char& at(int n);   `                    //ͨ��at������ȡ�ַ�
void test01()
{
    string str = "hello world";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;
    //�ַ��޸�
    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;

}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺string�ַ����е����ַ���ȡ�����ַ�ʽ������ [ ] �� at



// #### 3.1.8 string�����ɾ��
// **����������**
// * ��string�ַ������в����ɾ���ַ�����
// **����ԭ�ͣ�**
// * `string& insert(int pos, const char* s);  `                //�����ַ���
// * `string& insert(int pos, const string& str); `        //�����ַ���
// * `string& insert(int pos, int n, char c);`                //��ָ��λ�ò���n���ַ�c
// * `string& erase(int pos, int n = npos);`                    //ɾ����Pos��ʼ��n���ַ�
//�ַ��������ɾ��
void test01()
{
    string str = "hello";
    str.insert(1, "111");
    cout << str << endl;
    str.erase(1, 3);  //��1��λ�ÿ�ʼ3���ַ�
    cout << str << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
// **�ܽ᣺**�����ɾ������ʼ�±궼�Ǵ�0��ʼ


// #### 3.1.9 string�Ӵ�
// **����������**
// * ���ַ����л�ȡ��Ҫ���Ӵ�
// **����ԭ�ͣ�**
// * `string substr(int pos = 0, int n = npos) const;`   //������pos��ʼ��n���ַ���ɵ��ַ���
//�Ӵ�
void test01()
{
    string str = "abcdefg";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;
    string email = "hello@sina.com";
    int pos = email.find("@");
    string username = email.substr(0, pos);
    cout << "username: " << username << endl;

}
int main() {
    test01();
    system("pause");
    return 0;
}
// **�ܽ᣺**�����������Ӵ����ܣ�������ʵ�ʿ����л�ȡ��Ч����Ϣ