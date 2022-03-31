# Fake Vietnamese Person Generator
This is a tool that generated information about Vietnamese. Address correctly to Ward.

This is a project of OOP class - 2019.

## Demo

https://replit.com/@itlvd/fake-vietnamese-person-generator

## Data

- Phone number: accurate to the mobile operator level.
- Name: exactly according to Wikipedia and many source. - [First Name](https://vi.wikipedia.org/wiki/H%E1%BB%8D_ng%C6%B0%E1%BB%9Di_Vi%E1%BB%87t_Nam), [Middle Name, Last Name](https://vi.wikipedia.org/wiki/T%C3%AAn_ng%C6%B0%E1%BB%9Di_Vi%E1%BB%87t_Nam),..
- Address: exact to the ward level.

## Class FullName

You can generate a new name or change the name you want.

| Function           | Description                                             |
|--------------------|---------------------------------------------------------|
| getFirstName()     | get the first name of person.                           |
| setFirstName(x)    | set the x as the first name                             |
| getMiddleName()    | get the middle name of person.                          |
| setMiddleName(x)   | set the x as the middle name                            |
| getLastName()      | get the last name of person.                            |
| setLastName(x)     | set the x as the last name                              |
| randomFirstName()  | random new first name.                                  |
| randomMiddleName() | random new middle name.                                 |
| randomLastName()   | random new last name.                                   |
| getFullName()      | return a string of first name + middle name + last name |


## Class Email

Class Email inherits class FullName

| Function              | Description                           |
|-----------------------|---------------------------------------|
| getUserName()         | return string of username.            |
| setUserName(string x) | set x as username.                    |
| getDomain()           | return string of domain of email.     |
| setDomain(string x)   | set x as domain of email.             |
| randomDomain()        | random new domain of email.           |
| randomUserName()      | random new FullName and new username. |
| getEmail()            | return string of email.               |

## Class Birthday

Generate new birthday or set new day, month, year birthday.

| Function        | Description                         |
|-----------------|-------------------------------------|
| setDay(int d)   | set new day.                        |
| setMonth(int m) | set new month.                      |
| setYear(int y)  | set new year.                       |
| getDay()        | get day of birth.                   |
| getMonth()      | get month of birth.                 |
| getYear()       | get year of birth.                  |
| setAge(int x)   | set age to generate the birth.      |
| getAge()        | get age.                            |
| next()          | generate new birthday.              |
| getBirthday()   | return string of birth (DD/MM/YYYY) |

## Class FakeTel

Generate new phone number.

| Function         | Description                    |
|------------------|--------------------------------|
| randomPrefix()   | random new prefix number.      |
| randomNum()      | random new number.             |
| getPhoneNumber() | return string of phone number. |

## Class FakeHouseAddress

Generate new Address.

| Function                 | Description                  |
|--------------------------|------------------------------|
| getDistrict()            | get the district.            |
| getWard()                | get the ward.                |
| getStreet()              | get the street.              |
| setDistrict(string quan) | set quan as district.        |
| setWard(string phuong)   | set phuong as ward.          |
| setStreet(string duong)  | set duong as street.         |
| randomDistrict()         | generate new district.       |
| randomWard()             | generate new ward.           |
| randomStreet()           | generate new street name.    |
| randomNumber()           | generate new number address. |
| getAddress()             | return string of address.    |

## Class Personal

This class inherits all class above. 

Generate the information of one person. Change information or generate the new information.

| Function        | Description                                     |
|-----------------|-------------------------------------------------|
| Constructor     | generate random information. Set static age.    |
| next();         | generate infomation based on age of the person. |
| getInfoPerson() | return the string, full information of person.  |
