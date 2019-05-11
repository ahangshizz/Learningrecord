#include <iostream>
using namespace std;


class MyArray {
public:
	MyArray(int len);
	~MyArray();
public:
	int & operator[](int id);
	int Get_len();
	//实现这个异常抛出类
	class Msize {
	public:
		Msize(int size) {
			this->size = size;
		}
		virtual void PrintErr() {
			cout << "size:" << size << endl;
		}
	protected:
		int size;
	};
	class eNegative :public Msize {
	public:
		eNegative(int size) :Msize(size) {};
		virtual void PrintErr() {
			cout << "eNegative类型size:" << size << endl;
		}
	};
	class eZero :public Msize {
	public:
		eZero(int size) :Msize(size) {};
		virtual void PrintErr() {
			cout << "eZero类型size:" << size << endl;
		}
	};
	class eTooBig :public Msize {
	public:
		eTooBig(int size) :Msize(size) {};
		virtual void PrintErr() {
			cout << "eTooBig类型size:" << size << endl;
		}
	};
	class eTooSmall :public Msize {
	public:
		eTooSmall(int size) :Msize(size) {};
		virtual void PrintErr() {
			cout << "eTooSmall类型size:" << size << endl;
		}
	};
private:
	int* m_space;
	int m_len;
};
//综合知识应用
//把函数写在类的外面
MyArray::MyArray(int len) {
	//抛出错误类型
	if (len < 0) {
		//错误类型在类中定义,实现多态
		throw eNegative(len);
	}
	if (len == 0) {
		throw eZero(len);
	}
	if (len > 1000) {
		throw eTooBig(len);
	}
	if (len < 3) {
		throw eTooSmall(len);
	}
	this->m_len = len;
	this->m_space = new int[len];
}
//析构函数写在类的外面
MyArray::~MyArray() {
	if (this->m_space != NULL) {
		delete[] this->m_space;
		this->m_len = 0;
	}
}
//操作符重载
int & MyArray::operator[](int id) {
	return m_space[id];
}
//因为len定义在private中外部无法访问提供一个获取长度的函数
int MyArray::Get_len() {
	return m_len;
}
int main() {

	try
	{
		MyArray arr(-4);
		for (int i = 0; i < arr.Get_len(); ++i) {
			arr[i] = i + 1;
			printf("%d ", arr[i]);
		}
	}
	catch (MyArray::Msize &e) //父类指针指向子类对象
	{
		e.PrintErr();
	}
	catch (...)
	{
		cout << "其他类型的异常" << endl;
	}
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}