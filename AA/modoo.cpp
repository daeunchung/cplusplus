#include <iostream>
class Date{
public:
	int year_;
	int month_;
	int day_;
	Date() = default;
}; 
int main(){
	Date day1;
	Date day2 = Date();
	printf("%d", day1.year_);
	printf("%d", day2.year_);
	return 0;
}
