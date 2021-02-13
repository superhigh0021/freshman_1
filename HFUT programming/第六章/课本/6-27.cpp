#include <iostream>
#include <string.h>

using namespace std;
class Employee
{
private:
	char name[30];
	char street[30];
	char city[20];
	char zip[8];
public:
	Employee(const char *n, const char *str, const char *ct, const char *z);
	void change_name(const char *n);
	void display();
};
	Employee::Employee(const char *n, const char *str, const char *ct, const char *z)
{
	strcpy(name, n);
	strcpy(street, str);
	strcpy(city, ct);
	strcpy(zip, z);
}
void Employee::change_name(const char *n)
{
	strcpy(name, n);
}
void Employee::display()
{
	cout << name << " " << street << " ";
	cout << city << " " << zip;
}
int main(void)
{
	Employee x("海绵宝宝", "合工大翡翠湖校区", "合肥市", "0524500");
	x.display();
	cout << endl;
	x.change_name("派大星");
	x.display();
	cout << endl;
}
