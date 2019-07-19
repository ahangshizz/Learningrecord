#include <iostream>
#include <vector>
using namespace std;

class Date {
public:
	Date(int year, int moth, int day) {
		this->year = year;
		this->moth = moth;
		this->day = day;
	}
	int iConverDateToDay() {
		int count = 0;
		vector<int> v{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsRunYear()) {
			v[1] = 29;
			for (int i = 0; i < moth - 1; ++i) {
				count += v[i];
			}
			count += day;
			cout << count << endl;
			return 0;
		}
		else {
			for (int i = 0; i < moth - 1; ++i) {
				count += v[i];
			}
			count += day;
			cout << count << endl;
			return 0;
		}
		return 0;
	}
	bool IsRunYear() {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
			return true;
		}
		else {
			return false;
		}
	}
private:
	int year;
	int moth;
	int day;
};
int main() {
	int year, moth, day;
	while (cin >> year >> moth >> day) {
		Date d(year, moth, day);
		d.iConverDateToDay();
	}
	system("pause");
	return 0;
}