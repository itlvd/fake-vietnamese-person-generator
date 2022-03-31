
#include"ult.h"


int Random::roll(int number) {
	return rand() % number;
}

int Random::roll(int min,int max) {
	return rand() % (max - min + 1) + min;
}

Random::Random(){
	
}

FullName::FullName(){
	ifstream fileIn;
	fileIn.open("./data/ho.txt",ios::in);
	string temp;
	while(!fileIn.eof()){
		fileIn >> temp;
		_lFirstName.push_back(temp);
	}
	fileIn.close();
	fileIn.open("./data/dem.txt", ios::in);
	while(!fileIn.eof()){
		fileIn >> temp;
		_lMiddleName.push_back(temp);
	}
	fileIn.close();
	fileIn.open("./data/ten.txt", ios::in);
	while(!fileIn.eof()){
		fileIn >> temp;
		_lLastName.push_back(temp);
	}

	_firstName = "";
	_middleName = "";
	_lastName = "";

	fileIn.close();
}

void FullName::randomFirstName(){
	Random rng;
	if(_lFirstName.size() <=0){
		return;
	}
	_firstName = _lFirstName[rng.roll(_lFirstName.size())];
}

void FullName::randomMiddleName(){
	Random rng;
	if(_lMiddleName.size() <=0){
		return;
	}
	_middleName = _lMiddleName[rng.roll(_lMiddleName.size())];
}

void FullName::randomLastName(){
	Random rng;
	if(_lLastName.size() <=0){
		return;
	}
	_lastName = _lLastName[rng.roll(_lLastName.size())];
}

string FullName::getFullName(){
	stringstream writer;
	if(_middleName == ""){
		writer << _firstName << " " << _lastName;
	}
	else{
		writer << _firstName << " " << _middleName << " " << _lastName;
	}
	return writer.str();
}

Email::Email(){
	_username = "";
	_domain = "";
	ifstream fileIn;
	fileIn.open("./data/email.txt", ios::in);
	string temp;
	while(!fileIn.eof()){
		fileIn >> temp;
		_lDomain.push_back(temp);
	}
	fileIn.close();
}

string Email::getUserName(){
    stringstream writer;
	string lname = getLastName();
	lname[0] = lname[0] + 32;
	string fname = getFirstName();
	fname = fname[0] + 32;
	string mname = getMiddleName();
	mname = mname[0] + 32;
	writer << fname << mname << lname;
	return writer.str();
}

void Email::randomUserName(){
	randomFirstName();
	randomMiddleName();
	randomLastName();

	_username = getUserName();

}

void Email::randomDomain(){
	Random rng;
	_domain = _lDomain[rng.roll(_lDomain.size())];
}

string Email::getEmail(){
	stringstream writer;
	writer << getUserName() << _domain;
	return writer.str();
}

Birthday::Birthday(){
	Random rng;
    _day =0, _month=0, _year=0, _age=rng.roll(18,40);
}

void Birthday::next(){
    Random rng;
    time_t info = time(NULL);
    tm* now = localtime(&info);
    setYear(now -> tm_year + 1900 - _age);
    int month = rng.roll(1,12); // random tu thang 1 -> 12
    setMonth(month);
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        setDay(rng.roll(1,31));
    }
    else if(month == 2){
        if(isLeapYear(getYear())){// kiem tra nam co phai nam nhuan hay khong
            setDay(rng.roll(1,29));
        }
        else {
            setDay(rng.roll(1,28));
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        setDay(rng.roll(1,30));
    }
}

string Birthday::getBirthday(){
    stringstream writer;
    writer << getDay() << "-" << getMonth() << "-" << getYear();
    return writer.str();
}


bool isLeapYear(int year){
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}

FakeTel::FakeTel(){
    _prefix = "";
    _number = "";
    _mobileOperator = "";

}

string FakeTel::getLocal(string value) {
	stringstream writer;
	writer << "./data/Tel/" << value << ".txt";
	return writer.str();
}

void FakeTel::randomPrefix() {
	short index = rand() % 4 + 1;
	string value;
	switch (index) {
	case 1: {
		value = "Viettel"; 
		break;
	}
	case 2:
	{
		value = "Mobiphone";
		break;
	}
	case 3:
	{
		value = "Vinaphone";
		break;
	}
	case 4:
	{
		value = "Vietnammobile";
		break;
	}
	}
	_mobileOperator = value;
	string localFile = getLocal(value);
	ifstream fileIn;
	fileIn.open(localFile,ios::in);
	int count = 0;
	string temp;
	while (!fileIn.eof()) {
		count++;
		getline(fileIn, temp);
	}
	index = rand() % count + 1;
	for (int i = 1; i <= index; i++) {
		getline(fileIn, temp);
	}

	_prefix = temp;

	fileIn.close();

}

void FakeTel::randomNum() {
	stringstream writer;
	for (int i = 1; i <= 7; i++) {
		writer << rand() % 9 + 1;
	}
	_number = writer.str();
}

string FakeTel::getPhoneNumber() {
	stringstream writer;
	writer << _prefix << _number << "   " << _mobileOperator;
	return writer.str();
}

FakeHouseAddress::FakeHouseAddress(){
    _district ="";
	_ward ="";
	_street="";
	_number="";
    _DistrictIndex=1;
}

string FakeHouseAddress::getLocalWard(int index) {// Chuyen index thanh duong dan ten file
	stringstream writer;
	writer << "./data/Address/Phuong/" << index << ".txt";
	return writer.str();
}
void FakeHouseAddress::randomDistrict(){
	int index = rand() % MAXDISTRICT + 1;//Bien index random thu tu trong file Quan
	ifstream fileIn;//ten bien doc file
	fileIn.open("./data/Address/Quan.txt", ios::in);
	string temp;//Quan da random
	for (int i = 1; i <= index; i++) {
		getline(fileIn, temp);
	}
	_district = temp;
    _DistrictIndex = index;
	fileIn.close();
	
}
void FakeHouseAddress::randomWard() {
    vector<string> lWard;
	string local = getLocalWard(_DistrictIndex);
	ifstream fileIn;//ten bien doc file Phuong
	fileIn.open(local, ios::in);
	string temp;//Phuong da random
	int maxWard = 0;
	while (!fileIn.eof()) {
		maxWard++;
		getline(fileIn, temp);
        lWard.push_back(temp);
	}
	int index = rand() % maxWard + 1;
	_ward = lWard[index];
	fileIn.close();
	
}

void FakeHouseAddress::randomStreet() {
	int index = rand() % 185 + 1;
	ifstream fileIn;
	string temp;
	fileIn.open("./data/Address/duong.txt",ios::in);
	for (int i = 1; i <= 185; i++) {
		getline(fileIn, temp);
		if (i == index) {
			break;
		}
	}
    _street = temp;
	fileIn.close();
}

void FakeHouseAddress::randomNumber() {
	int numberAdd1 = rand() % 999 + 1;
	int numberAdd2 = rand() % 99 + 1;
	int choose = rand() % 2 + 1;
	stringstream writer;
	if (choose == 1) {
		writer << numberAdd1;
		_number= writer.str();
	}
	else {
		writer << numberAdd1 << "/" << numberAdd2;
		_number =  writer.str();
	}
}

string FakeHouseAddress::getAddress() {

	FakeHouseAddress::randomDistrict();
	FakeHouseAddress::randomWard();
	FakeHouseAddress::randomStreet();
	FakeHouseAddress::randomNumber();
	stringstream writer;
	writer << _number << ", Duong " << _street << ", " << _ward << ", " << _district << ", Thanh pho Ho Chi Minh, Viet Nam" ;
	return writer.str();
}

Person::Person(){
    randomUserName();
    randomDomain();

    Birthday::next();

    randomPrefix();
    randomNum();

    randomDistrict();
    randomWard();
    randomStreet();
    randomNumber();

}

void Person::next(){
    randomUserName();
    randomDomain();

    Birthday::next();

    randomPrefix();
    randomNum();

    randomDistrict();
    randomWard();
    randomStreet();
    randomNumber();

}

string Person::getInfoPerson(){
    stringstream writer;
    writer << "Name: " << getFullName() << "\nAge: " << getAge() <<"\nBirthday: " <<getBirthday()
            << "\nPhone: " <<getPhoneNumber() << "\nEmail: " << getEmail() << "\nAddress: " <<getAddress();
    return writer.str();
}
