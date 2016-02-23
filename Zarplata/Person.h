#pragma once
#include<afx.h>

class Person: public CObject
{
	DECLARE_SERIAL(Person)														// декларация необходимая для сериализации
public:
	static const UINT VERSION_NUMBER = 1;										//версия объекта для сериализации
	Person(CString surname, CString name, CString secondname, unsigned int ID); //принимает имя фамилию отчество и ID
	~Person(void);
	CString getSurname()const;
	unsigned int getHashCode()const;
	CString getInitial()const;													//получить строку фамилии с инициалами
	unsigned int getId()const;
	float computSalary(unsigned short normHours, unsigned short overHours, 
	unsigned short dependents, float minPayment, float hourPayment, float koef);//посчитать зарплату
	float getSalary()const;
	bool operator <(const Person& p)const;										//по фамилии
	CString getName()const;
	CString getSecondname()const;
	CString ToCString(float value)const;
	CString ToCString(unsigned int value)const;
	unsigned int getSumHours()const;
	float getTarif()const;
	float getKoef()const;
	float getMinPayment()const;
	unsigned int getDependents()const;
	unsigned int getOverHours()const;
	void Serialize(CArchive& ar);											//функция сериализации
protected:
	Person(void);
private:
	CString name;															//имя
	CString surname;														//фамилия
	CString secondname;														//отчество
	CString initials;														//Вася П.П.	
	unsigned int hashCode;													//идентификационный номер
	unsigned int ID;
	unsigned short normHours;												//отработанные нормальные часы	
	unsigned short overHours;												//переработанные часы
	unsigned short sumHours;												//всего часов
	unsigned short dependents;												//иждивенцы
	float minPayment;														//минимальная опалата труда
	float sumPayment;														//всего к оплате
	float hourPayment;														//зарплата в час
	unsigned int koef;
	void setHashCode();
	void setInitial();
};
class NameCmp
{
public:
	bool operator() (const Person* p1, const Person* p2)const
	{
		return (p1->getName() < p2->getName());
	}
};
class SurnameCmp
{
public:
	bool operator() (const Person* p1, const Person* p2)const
	{
		return (p1->getSurname() < p2->getSurname() || p1->getName() < p2->getName() || p1->getSecondname() < p2->getSecondname());
	}
};
class SecondnameCmp
{
public:
	bool operator() (const Person* p1, const Person* p2)const
	{
		return (p1->getSecondname() < p2->getSecondname());
	}
};
class HashCmp
{
public:
	bool operator() (const Person* p1, const Person* p2)const
	{
		return (p1->getHashCode() < p2->getHashCode());
	}
};
class IDCmp
{
public:
	bool operator() (const Person* p1, const Person* p2)const
	{
		return (p1->getId() < p2->getId());
	}
};
class SalaryCmp
{
public:
	bool operator() (const Person* p1, const Person* p2)const
	{
		return (p1->getSalary() < p2->getSalary());
	}
};
class IntCmp
{
public:
	bool operator() (int p1, int p2)const
	{
		return (p1 < p2);
	}
};
class FloatCmp
{
public:
	bool operator() (float p1, float p2)const
	{
		return (p1 < p2);
	}
};
class StringCmp
{
public:
	bool operator() (const CString& p1, const CString& p2)const
	{
		return (p1 < p2);
	}
};
