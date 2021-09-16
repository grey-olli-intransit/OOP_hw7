#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

// 1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. 
// Перегрузите оператор вывода для данного класса. 
// Создайте два "умных" указателя today и date. 
// Первому присвойте значение сегодняшней даты. 
// Для него вызовите по отдельности методы доступа к полям класса Date, 
// а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода. 
// Затем переместите ресурс, которым владеет указатель today в указатель date. 
// Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.

class Date {
    int day;
    int month;
    int year;
    public:
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
	int getDay()  const {return day;}
	int getMonth() const {return month;}
	int getYear() const {return year;}
	int setDay(int d) {
	    if ( d > 0 && d <= 31)
	       day = d;
	    else
	       throw "day out of range";
	}
	int setMonth(int m) {
	    if ( m > 0 && m <= 12)
	       month = m;
	    else
	       throw "month out of range";
	}
	int setYear(int y) {
	    if ( y > 0)
	       year = y;
	    else
	       throw "year out of range";
	}
        friend ostream & operator<<(ostream & os, Date & d);
	Date & operator=(const Date & d) = default;
};

ostream & operator<<(ostream & os, Date & d) {
    os << d.day << "." << d.month << "." << d.year ;
    return os;
}

int main(int argc, char ** argv) {

    Date d(7,11,1976);
    std::cout << d << "\n";
    unique_ptr<Date> date;
    if (date == nullptr)
        std::cout << "date is nullptr\n";
    else
        std::cout << "date is NOT null.\n";

    unique_ptr<Date> today = make_unique<Date>(15,9,2021);
    cout << today->getDay() << ".";
    cout << today->getMonth() <<  ".";
    cout << today->getYear() << endl;
    cout << *today << endl;
    today.swap(date);
    cout << "After swap:\n";
    if (date == nullptr)
        cout << "date is nullptr\n";
    else
        cout << "date is NOT null (expected).\n";

    if (today == nullptr)
        cout << "today is null\n";
    else
        cout << "today is NOT null.\n";

    return 0;	
}
