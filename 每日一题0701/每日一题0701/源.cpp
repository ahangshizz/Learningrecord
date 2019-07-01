#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//ÀıÈç   s1="dadwadwa"
//		 s2="ad"
//		 Êä³ö  ww
#if 0
int main() {
	string s1;
	string s2;
	while (getline(cin, s1)) {
		while (getline(cin, s2)) {
			auto it_1 = s1.begin();
			auto it_2 = s2.begin();
			for (it_2; it_2 != s2.end(); ++it_2) {
				it_1 = s1.begin();
				for (it_1; it_1 != s1.end(); ) {
					if (*(it_1) == *(it_2)) {
						s1.erase(it_1);
					}
					else {
						++it_1;
					}
				}
			}
			cout << s1 << endl;
			break;
		}
	}
	return 0;
}
#endif

class MyString {
public:
	MyString(char* p_Data = NULL) {
		this->m_pData = p_Data;
	};
	MyString(const MyString& str) {
		if (this != NULL) {
			delete [] m_pData;
		}
		this->m_pData = new char[strlen(str.m_pData) + 1];
	}
	MyString& operator=(const MyString& str) {
		/*
		if (this == &str) {
			return *this;
		}
		if (this != NULL) {
			delete[]m_pData;
		}
		this->m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(this->m_pData, str.m_pData);
		return *this;
		*/
		if (this != &str) {
			MyString strtmp(str);
			char* temp = strtmp.m_pData;
			strtmp.m_pData = this->m_pData;
			this->m_pData = temp;
		}
		return *this;
	}
private:
	char* m_pData;
};