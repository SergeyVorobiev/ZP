#pragma once
#include<map>
#include "Person.h"
#include <iomanip>

typedef std::multimap<CString, Person*, StringCmp> SurPerson;
typedef std::map<unsigned int, Person*, IntCmp> IdPerson;
typedef std::multimap<float, Person*, FloatCmp> SalPerson;
typedef std::multimap<unsigned int, Person*, IntCmp> HourPerson; 
class MyCollection: public CObject
{
	DECLARE_SERIAL(MyCollection)
public:
	static const UINT VERSION_NUMBER = 1;
	typedef enum{INITIAL, ID, SALARY, HOURS} TypeMap;	
	TypeMap curMap;
	MyCollection(TypeMap current)
	{
		curMap = current;
		idPerson = new IdPerson();
		surPerson = new SurPerson();
		salPerson = new SalPerson();
		hourPerson = new HourPerson();
		isReverse = false;
		length = 0;
		sumSalary = 0;
		sortHours = 0;
		moreHours = true;
		startPos = true;
	};
	bool Insert(Person* p);
	Person* getPerson();
	int GetLength()const;
	~MyCollection(void);
	Person* getOnIndex(TypeMap tMap, int index);
	void Deleted(Person* p);
	Person* getOnId(unsigned id)const;
	bool isReverse;
	float getSumSalary()const;
	int sortHours;
	bool moreHours;
	bool startPos;
	void subFromSumSalary(Person* p);
	void addToSumSalary(float salary);
	void Serialize(CArchive& ar);
protected:
	MyCollection();
private:
	int length;
	float sumSalary;
	SurPerson* surPerson;
	SalPerson* salPerson;
	IdPerson* idPerson;
	HourPerson* hourPerson;
	SalPerson::iterator salIter;
	SurPerson::iterator surIter;
	IdPerson::iterator idIter;
	HourPerson::iterator hourIter;
	SalPerson::reverse_iterator rsalIter;
	SurPerson::reverse_iterator rsurIter;
	IdPerson::reverse_iterator ridIter;
	HourPerson::reverse_iterator rhourIter;
	bool validSort(Person* p)const;
	int icurMap;
};


