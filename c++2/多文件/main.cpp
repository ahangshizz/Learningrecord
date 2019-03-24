#include <iostream>
#include "circle.h"
using namespace std;
int main() {
	circle h;
	h.set_r(10);
	h.get_girth();
	h.get_acre();
	cout << h.get_girth() <<"zhouchang"<< endl;
	cout << h.get_acre() <<"banjing"<< endl;
	system("pause");
	return 0;
}