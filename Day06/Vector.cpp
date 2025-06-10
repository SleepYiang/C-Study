// ### 3.2 vector����
// #### 3.2.1 vector��������
// **���ܣ�**
// vector���ݽṹ��**����ǳ�����**��Ҳ��Ϊ**��������**
// vector����ͨ��������:
// ��֮ͬ�����������Ǿ�̬�ռ䣬��vector����**��̬��չ**


// #### 3.2.2 vector���캯��
// **����������**
// * ����vector����
// **����ԭ�ͣ�**
// * `vector<T> v; `               		     //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
// * `vector(v.begin(), v.end());   `       //��v[begin(), end())�����е�Ԫ�ؿ���������
// * `vector(n, elem);`                            //���캯����n��elem����������
// * `vector(const vector &vec);`         //�������캯����

#include <vector>
void printVector(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int> v1; //�޲ι���
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);
    vector<int> v3(10, 100);
    printVector(v3);
    vector<int> v4(v3);
    printVector(v4);
}
int main() {
    test01();
    system("pause");
    return 0;
}
// **�ܽ᣺**vector�Ķ��ֹ��췽ʽû�пɱ��ԣ����ʹ�ü���



// #### 3.2.3 vector��ֵ����
// **����������**
// * ��vector�������и�ֵ
// **����ԭ�ͣ�**
// * `vector& operator=(const vector &vec);`//���صȺŲ�����
// * `assign(beg, end);`       //��[beg, end)�����е����ݿ�����ֵ������
// * `assign(n, elem);`        //��n��elem������ֵ������
#include <vector>

void printVector(vector<int>& v) {

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//��ֵ����
void test01()
{
    vector<int> v1; //�޲ι���
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int>v2;
    v2 = v1;
    printVector(v2);

    vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    vector<int>v4;
    v4.assign(10, 100);
    printVector(v4);
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺ vector��ֵ��ʽ�Ƚϼ򵥣�ʹ��operator=������assign������




// #### 3.2.4  vector�����ʹ�С
// **����������**
// * ��vector�����������ʹ�С����
// **����ԭ�ͣ�**
// * `empty(); `                            //�ж������Ƿ�Ϊ��
// * `capacity();`                      //����������
// * `size();`                              //����������Ԫ�صĸ���
// * `resize(int num);`             //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
// * `resize(int num, elem);`  //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
#include <vector>
void printVector(vector<int>& v) {

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    if (v1.empty())
    {
        cout << "v1Ϊ��" << endl;
    }
    else
    {
        cout << "v1��Ϊ��" << endl;
        cout << "v1������ = " << v1.capacity() << endl;
        cout << "v1�Ĵ�С = " << v1.size() << endl;
    }
    //resize ����ָ����С ����ָ���ĸ���Ĭ����0�����λ�ã������������ذ汾�滻Ĭ�����
    v1.resize(15,10);
    printVector(v1);
    //resize ����ָ����С ����ָ���ĸ�С����������Ԫ�ر�ɾ��
    v1.resize(5);
    printVector(v1);
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ж��Ƿ�Ϊ��  --- empty
// ����Ԫ�ظ���  --- size
// ������������  --- capacity
// ����ָ����С  ---  resize



// #### 3.2.5 vector�����ɾ��
// **����������**
// * ��vector�������в��롢ɾ������
// **����ԭ�ͣ�**
// * `push_back(ele);`                                         //β������Ԫ��ele
// * `pop_back();`                                                //ɾ�����һ��Ԫ��
// * `insert(const_iterator pos, ele);`        //������ָ��λ��pos����Ԫ��ele
// * `insert(const_iterator pos, int count,ele);`//������ָ��λ��pos����count��Ԫ��ele
// * `erase(const_iterator pos);`                     //ɾ��������ָ���Ԫ��
// * `erase(const_iterator start, const_iterator end);`//ɾ����������start��end֮���Ԫ��
// * `clear();`                                                        //ɾ������������Ԫ��
#include <vector>

void printVector(vector<int>& v) {

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//�����ɾ��
void test01()
{
    vector<int> v1;
    //β��
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);
    //βɾ
    v1.pop_back();
    printVector(v1);
    //����
    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    //ɾ��
    v1.erase(v1.begin());
    printVector(v1);

    //���
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);
}
int main() {
    test01();
    system("pause");
    return 0;
}
// * β��  --- push_back
// * βɾ  --- pop_back
// * ����  --- insert    (λ�õ�����)
// * ɾ��  --- erase  ��λ�õ�������
// * ���  ---  clear




// #### 3.2.6 vector���ݴ�ȡ
// **����������**
// * ��vector�е����ݵĴ�ȡ����
// **����ԭ�ͣ�**
// * `at(int idx); `     //��������idx��ָ������
// * `operator[]; `       //��������idx��ָ������
// * `front(); `            //���������е�һ������Ԫ��
// * `back();`              //�������������һ������Ԫ��
#include <vector>
void test01()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;
    cout << "v1�ĵ�һ��Ԫ��Ϊ�� " << v1.front() << endl;
    cout << "v1�����һ��Ԫ��Ϊ�� " << v1.back() << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
// * �����õ�������ȡvector������Ԫ�أ�[ ]��atҲ����
// * front����������һ��Ԫ��
// * back�����������һ��Ԫ��


// #### 3.2.7 vector��������
// **����������**
// * ʵ������������Ԫ�ؽ��л���
// **����ԭ�ͣ�**
// * `swap(vec);`  // ��vec�뱾���Ԫ�ػ���
#include <vector>
void printVector(vector<int>& v) {

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int>v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);
    //��������
    cout << "������" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
void test02()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }
    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ��" << v.size() << endl;
    v.resize(3);
    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ��" << v.size() << endl;
    //�����ڴ�
    vector<int>(v).swap(v); //��������
    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ��" << v.size() << endl;
}
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
// �ܽ᣺swap����ʹ�����������������Դﵽʵ�õ������ڴ�Ч��


// #### 3.2.8 vectorԤ���ռ�
// **����������**
// * ����vector�ڶ�̬��չ����ʱ����չ����
// **����ԭ�ͣ�**
// * `reserve(int len);`//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
#include <vector>
void test01()
{
    vector<int> v;
    //Ԥ���ռ�
    v.reserve(100000);
    int num = 0;
    int* p = NULL;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }
    cout << "num:" << num << endl;
}
int main() {
    test01();
    system("pause");
    return 0;
}
// �ܽ᣺����������ϴ󣬿���һ��ʼ����reserveԤ���ռ�
