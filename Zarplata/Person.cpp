#include "StdAfx.h"
#include "Person.h"
IMPLEMENT_SERIAL(Person, CObject, VERSION_NUMBER) // указываем что в этом классе реализуется сериализация
Person::Person()
{
}
Person::Person(CString surname, CString name, CString secondname, unsigned int Id)
{
	this->surname		= surname;
	this->name			= name;
	this->secondname	= secondname;
	normHours			= 0;
	overHours			= 0;
	sumHours			= 0;
	dependents			= 0;
	minPayment			= 0;
	sumPayment			= 0;
	this->ID = Id;
	setHashCode();
	setInitial();
}
Person::~Person(void)
{
}
CString Person::getSurname()const
{
	return surname;
}
CString Person::getName()const
{
	return name;
}
CString Person::getSecondname()const
{
	return secondname;
}
void Person::setHashCode()
{
	hashCode = 0;
	for(unsigned int i = 0; i < surname.GetLength(); i++)
	{
		hashCode = hashCode * 3 + static_cast<int>(surname[i]) * 3;
	}
	for(unsigned int i = 0; i < name.GetLength(); i++)
	{
		hashCode = hashCode * 3 + static_cast<int>(name[i]) * 3;
	}
	for(unsigned int i = 0; i < secondname.GetLength(); i++)
	{
		hashCode = hashCode * 3 + static_cast<int>(secondname[i]) * 3;
	}
}
unsigned int Person::getHashCode() const
{
	return hashCode;
}
void Person::setInitial()
{
	initials = surname;
	CString space = static_cast<CString>(" ");
	CString dot = static_cast<CString>(".");
	initials.Insert(initials.GetLength(), space);
	initials.Insert(initials.GetLength(), name[0]);
	initials.Insert(initials.GetLength(), dot);
	initials.Insert(initials.GetLength(), space);
	initials.Insert(initials.GetLength(), secondname[0]);
	initials.Insert(initials.GetLength(), dot);
}
CString Person::getInitial()const
{
	return initials;
}
float Person::computSalary(unsigned short normHours, unsigned short overHours, unsigned short dependents,
							float minPayment, float hourPayment, float koef)
{
	this->koef = koef;
	this->normHours = normHours;
	this->overHours = overHours;
	this->dependents = dependents;
	this->minPayment = minPayment;
	this->hourPayment = hourPayment;
	this->sumHours = normHours + overHours;
	if(hourPayment < 0 || sumHours > 500 || minPayment < 0) return 0;
	float salary = normHours * hourPayment + overHours * hourPayment * koef;
	float fund	= salary * 0.01f;
	float tax = (salary - minPayment * (dependents + 1)) * 0.12f;
	if(tax < 0) tax = 0;
	return this->sumPayment = salary - fund - tax;
}
float Person::getSalary()const
{
	return sumPayment;
}
bool Person::operator<(const Person& p)const
{
	return (this->surname < p.getSurname());
}
unsigned int Person::getId()const
{
	return ID;
}

CString Person::ToCString(float value)const
{
	int val = value * 100;
	int c, i = 0; 
	CString current;
	CString str;
	while(val > 0)
	{
		i++;
		c = val % 10;
		val/= 10;
		c += 48;
		current = static_cast<char>(c);
		str = current + str;
		if(i == 2)
			str = '.' + str;
	}	
	if(str.GetLength() == 3)
		str = '0' + str;
	return str;
}
unsigned int Person::getSumHours()const
{
	return sumHours;
}
float Person::getTarif()const
{
	return hourPayment;
}
CString Person::ToCString(unsigned int value)const
{
	int c, i = 0; 
	CString current;
	CString str;
	while(value > 0)
	{
		i++;
		c = value % 10;
		value/= 10;
		c += 48;
		current = static_cast<char>(c);
		str = current + str;
	}	
	return str;
}
float Person::getKoef()const
{
	return koef;
}
float Person::getMinPayment()const
{
	return minPayment;
}
		
unsigned int Person::getDependents()const
{
	return dependents;
}
unsigned int Person::getOverHours()const
{
	return overHours;
}
void Person::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if(ar.IsStoring())
	{
		ar<<name;
		ar<<surname;
		ar<<secondname;
		ar<<initials;
		ar<<hashCode;
		ar<<ID;
		ar<<normHours;
		ar<<overHours;
		ar<<sumHours;
		ar<<dependents;
		ar<<minPayment;
		ar<<sumPayment;
		ar<<hourPayment;
		ar<<koef;
	}
	else
	{
		ar>>name;
		ar>>surname;
		ar>>secondname;
		ar>>initials;
		ar>>hashCode;
		ar>>ID;
		ar>>normHours;
		ar>>overHours;
		ar>>sumHours;
		ar>>dependents;
		ar>>minPayment;
		ar>>sumPayment;
		ar>>hourPayment;
		ar>>koef;
	}
}
