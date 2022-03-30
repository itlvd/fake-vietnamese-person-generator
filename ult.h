#include<iostream>
#include<sstream>
#include<string>
#include<ctime>
#include<vector>
#include<fstream>
#define MAXDISTRICT 24
using namespace std;


class Random {
    public:
	Random();
	int roll(int number);
    int roll(int min, int max);
};

class FullName{
    private:
        string _firstName;
        string _middleName;
        string _lastName;
        vector<string> _lFirstName;
        vector<string> _lMiddleName;
        vector<string> _lLastName;
    public:
        FullName();
        string getFirstName(){return _firstName;}
        void setFirstName(string x) {_firstName = x;}
        string getMiddleName() {return _middleName;}
        void setMiddleName(string x) {_middleName = x;}
        string getLastName() {return _lastName;}
        void setLastName(string x) {_lastName = x;}

        void randomFirstName();
        void randomMiddleName();
        void randomLastName();

        string getFullName();
};

class Email:public FullName{
    private:
        string _username;
        string _domain;
        vector<string> _lDomain;
    public:
        Email();
        
        string getUserName();
        void setUserName(string x){_username = x;}
        string getDomain(){return _domain;}
        void setDomain(string x){_domain = x;}

        void randomDomain();
        void randomUserName();

        string getEmail();
};

class Birthday{
private:
    int _day, _month, _year, _age;

public:
    Birthday();
    void setDay(int d){ _day = d;}
    void setMonth(int m){_month = m;}
    void setYear(int y) {_year = y;}
    int getDay() {return _day;}
    int getMonth() {return _month;}
    int getYear() {return _year;}
    void setAge(int x) {_age = x;}
    int getAge() {return _age;}
    void next();
    string getBirthday();
};
bool isLeapYear(int year);


class FakeTel
{
	string _prefix;
	string _number;
	string _mobileOperator;
public:
    FakeTel();
	void randomPrefix();
	void randomNum();
	string getPhoneNumber();
private:
	string getLocal(string value);
	
};

class FakeHouseAddress {
	string _district;
	string _ward;
	string _street;
	string _number;
    int _DistrictIndex;
    string getLocalWard(int index);
public:
	FakeHouseAddress();
	string getDistrict() { return _district; }
	string getWard() { return _ward; }
	string getStreet() { return _street; }
	void setDistrict(string quan) { _district = quan; };
	void setWard(string phuong) { _ward = phuong; }
	void setStreet(string duong) { _street = duong; }

	void randomDistrict();
	void randomWard();
	void randomStreet();
	void randomNumber();
	string getAddress();

};

class Person : public Email, public Birthday, public FakeTel, public FakeHouseAddress{
    public:
        Person();
        void next();
        //void setAge(int x){setAge(x);}
        string getInfoPerson();
};