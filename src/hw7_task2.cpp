#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

//2. По условию предыдущей задачи создайте два умных указателя date1 и date2. 
// Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой 
// (сравнение происходит по датам). Функция должна вернуть более позднюю дату.
// Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.


class Date {
    int day;
    int month;
    int year;
    public:
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
	Date(Date * d) : day{d->day}, month{d->month}, year{d->year} {}
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
        bool operator>(Date & d) {
	 if(this->year > d.year)
             return true;
         else if (this->year < d.year)
             return false;
         else if (this->month > d.month)
             return true;
         else if (this->month < d.month)
             return false;
	 else if (this->day > d.day)
	     return true;
	 else
             return false;
	} 
	Date & operator=(const Date & d) = default;
	std::string to_string() const {
	  return std::to_string(day)+"."+std::to_string(month)+"."+std::to_string(year);
	}
};


ostream & operator<<(ostream & os, Date & d) {
    os << d.day << "." << d.month << "." << d.year ;
    return os;
}

unique_ptr<Date> compare(const unique_ptr<Date>& d1, const unique_ptr<Date>& d2) {
 if (*d1>*d2)
   return make_unique<Date>(d1.get());
 else
   return make_unique<Date>(d2.get());
};

// Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
void swap_uniq(unique_ptr<Date>& d1, unique_ptr<Date>& d2) {
 std::swap(d1,d2);
}

int main(int argc, char ** argv) {

    unique_ptr<Date> date1 = make_unique<Date>(15,9,2021);
    cout << *date1 << "\n"; 
    unique_ptr<Date> date2 = make_unique<Date>(15,9,2020);
    cout << *date2 << "\n"; 
    cout << "newer date:" << *compare(date1,date2) << "\n";
    swap_uniq(date1,date2);
    cout << *date1 << "\n"; 
    cout << *date2 << "\n"; 
    return 0;	
}
