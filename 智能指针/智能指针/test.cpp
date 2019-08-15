
#include <iostream>
using namespace std;


#if 0
namespace bite
{
	template<class T>
	class auto_ptr
	{
	public:
		// RAII
		auto_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)
			: _ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		// ap1 = ap2;
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}

		// 具有类似指针的行为
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}

struct A
{
	int a;
	int b;
	int c;
};

void TestAuto1()
{
	bite::auto_ptr<int> ap1(new int);
	*ap1 = 10;

	int a = 10;
	int* pa = &a;

	A aa;
	A* paa = &aa;
	paa->a = 10;

	bite::auto_ptr<A> ap2(new A);
	(*ap2).a = 10;

	ap2->b = 10;
}

void TestAuto2() {
	int a = 10;
	int* pa1 = &a;
	int* pa2(pa1);
	*pa1 = 30;
	*pa2 = 20;

	bite::auto_ptr<int> ap1(new int);
	bite::auto_ptr<int> ap2(ap1);
	*ap1 = 10;
	*ap2 = 20;

	bite::auto_ptr<int> ap3;
	ap3 = ap2;
}

int main() {

	//TestAuto1();
	TestAuto2();
	return 0;
}

#endif

#if 0
namespace bite{
	template<class T>
	class auto_ptr {
	public:
		auto_ptr(T* ptr = nullptr) :_ptr(ptr), _owner(false) {
			if (_ptr) {
				_owner = true;
			}
		}
		~auto_ptr()
		{
			if (_ptr&&_owner) {
				delete _ptr;
				_owner = false;
				_ptr = nullptr;
			}
		}
		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}
		T* get() {
			return _ptr;
		}
		auto_ptr<T>& operator=(const auto_ptr<T>& ap) {
			if (this != &ap) {
				if (_ptr&&_owner) {
					delete _ptr;
				}
				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}

	private:
		T* _ptr;
		mutable bool _owner;
	};
}

void TestAutoPtr() {
	bite::auto_ptr<int> ap1(new int);
	bite::auto_ptr<int> ap2(ap1);
	*ap1 = 10;
	*ap2 = 20;
	bite::auto_ptr<int> ap3;
	ap3 = ap2;
	if (true) {
		bite::auto_ptr<int> ap4(ap3);
	}
	*ap3 = 10;
}

int main() {
	TestAutoPtr();
	return 0;
}
#endif


#if 0
namespace bite {
	template<class T>
	class unique_ptr {
	public:
		unique_ptr(T* ptr=nullptr):_ptr(ptr){}
		~unique_ptr() {
			if (_ptr) {
				delete _ptr;
				_ptr = nullptr;
			}
		}
		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}
		// 防止被拷贝
// C++98
//private:
//	unique_ptr(const unique_ptr<T>&);
//	unique_ptr<T>& operator=(const unique_ptr<T>& ap);

// C++11 delete:禁止默认成员函数的生成
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;
	private:
		T* _ptr;
	};
}

class A {
public:
	A(int a):_a(a) {

	}
	A() = default;
private:
	int _a;
};

void TestUniquePtr() {
	bite::unique_ptr<int> up1(new int);
	//bite::unique_ptr<int> up2(up1);


	bite::unique_ptr<int> up3;
	//up3 = up1;
}
#endif

//shared_ptr

#if 0
namespace bite {
	template<class T>
	class shared_ptr {
	public:
		shared_ptr(T* ptr) :_ptr(ptr) {
			if (_ptr) {
				_count = 1;
			}
		}
		shared_ptr(shared_ptr<T>& sp) :_ptr(sp._ptr) {
			_count++;
		}
		~shared_ptr()
		{
			if (_ptr&&--_count == 0) {
				delete _ptr;
				_ptr = nullptr;
			}
		}
	private:
		T* _ptr;
		static int _count;
	};
	template<class T>
	int shared_ptr<T>::_count = 0;
}

void TestSharedPtr() {
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(sp1);
	bite::shared_ptr<int> sp3(new int);
}
int main() {
	TestSharedPtr();
	return 0;
}

#endif



#if 0
//只能管理new出来的资源
namespace bite {
	template<class T>
	class shared_ptr {
	public:
		shared_ptr(T* ptr = nullptr) :_ptr(ptr), _pcount(nullptr) {
			if (_ptr) {
				_pcount = new int(1);
			}
		}
		shared_ptr(const shared_ptr<T>& sp) :_ptr(sp._ptr), _pcount(sp._pcount) {
			if (_ptr) {
				++(*_pcount);
			}
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
			if (this != &sp) {
				release();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				if (_ptr)
					++(*_pcount);
			}
			return *this;
		}
		~shared_ptr() {
			release();
		}
		int use_count() {
			return *_pcount;
		}
	private:
		void release() {
			if (_ptr && 0 == --(*_pcount)) {
				delete _ptr;
				_ptr = nullptr;

				delete _pcount;
				_pcount = nullptr;
			}
		}
	private:
		T* _ptr;
		int* _pcount;
	};
}
void TestSharedPtr1() {
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;
	bite::shared_ptr<int> sp3(new int);
	cout << sp3.use_count() << endl;
}

void TestSharedPtr2() {
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(new int);
	bite::shared_ptr<int> sp3(sp2);
	sp2 = sp1;
}

int main() {
	//TestSharedPtr1();
	TestSharedPtr2();
	return 0;
}
#endif


//使用伪函数定制删除器

template<class T>
class DFDel {
public:
	void operator()(T*& p) {
		if (p) {
			delete p;
			p = nullptr;
		}
	}
};

//malloc的资源
template<class T>
class Free {
public:
	void operator()(T*& p) {
		if (p) {
			free(p);
			p = nullptr;
		}
	}
};

class Fclose {
public:
	void operator()(FILE*& p) {
		if (p) {
			fclose(p);
			p = nullptr;
		}
	}
};

namespace bite {
	template<class T,class DF=DFDel<T>>
	class shared_ptr {
	public:
		shared_ptr(T* ptr = nullptr) :_ptr(ptr), _pcount(nullptr) {
			if (_ptr) {
				_pcount = new int(1);
			}
		}
		shared_ptr(const shared_ptr<T>& sp):_ptr(sp._ptr),_pcount(sp._pCount) {
			if (_ptr) {
				++(*_pcount);
			}
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
			if (this != &sp) {
				release();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				if (_ptr) {
					++(*_pcount);
				}
			}
			return *this;
		}
		~shared_ptr() {
			release();
		}
	private:
		void release() {
			if (_ptr&&--(*_pcount)==0) {
				DF()(_ptr);
				_ptr = nullptr;

				delete _pcount;
				_pcount = nullptr;
			}
		}
	private:
		T* _ptr;
		int* _pcount;
	};

}

void TestSharedPtr() {
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int, Free<int>> sp2((int*)malloc(sizeof(int)));
	bite::shared_ptr<FILE, Fclose> sp3(fopen("1.text", "w"));
}

int main() {
	TestSharedPtr();
	return 0;
}

