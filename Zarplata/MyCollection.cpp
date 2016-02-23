#include "StdAfx.h"
#include "MyCollection.h"
IMPLEMENT_SERIAL(MyCollection, CObject, VERSION_NUMBER)
MyCollection::MyCollection()
{
	idPerson = new IdPerson();
	surPerson = new SurPerson();
	salPerson = new SalPerson();
	hourPerson = new HourPerson();
}
MyCollection::~MyCollection(void)
{
	for(surIter = surPerson->begin(); surIter != surPerson->end(); surIter++)
		delete(surIter->second);
	surPerson->clear();
	delete(surPerson);
	idPerson->clear();
	delete(idPerson);
	salPerson->clear();
	delete(salPerson);
	hourPerson->clear();
	delete(hourPerson);
}
bool MyCollection::Insert(Person *p)
{
	//idIter = idPerson->find(p->getId());
	//idIter = idPerson->end();
	if(idPerson->find(p->getId()) == idPerson->end()) //перед вставкой проверить содержится ли элемент с таким Id
	{
		(*idPerson)[p->getId()] = p;
		salPerson->insert(std::make_pair(p->getSalary(), p));
		surPerson->insert(std::make_pair(p->getInitial(), p));
		hourPerson->insert(std::make_pair(p->getSumHours(), p));
		length++;
		sumSalary += p->getSalary();
		return true;
	}
	return false;
}
Person* MyCollection::getPerson()
{
	if(startPos)
	{
		if(!isReverse)
		{
			if(curMap == MyCollection::SALARY)	{salIter = salPerson->begin(); icurMap = 1;}
			if(curMap == MyCollection::ID)		{idIter = idPerson->begin(); icurMap = 2;}
			if(curMap == MyCollection::INITIAL) {surIter = surPerson->begin(); icurMap = 3;}
			if(curMap == MyCollection::HOURS)	{hourIter = hourPerson->begin(); icurMap = 4;}
		}
		else
		{
			if(curMap == MyCollection::SALARY)	{rsalIter = salPerson->rbegin(); icurMap = 5;}
			if(curMap == MyCollection::ID)		{ridIter = idPerson->rbegin(); icurMap = 6;}
			if(curMap == MyCollection::INITIAL) {rsurIter = surPerson->rbegin(); icurMap = 7;}
			if(curMap == MyCollection::HOURS)	{rhourIter = hourPerson->rbegin(); icurMap = 8;}
		}
		startPos = false;
	}
	if(icurMap == 1)
	{
		while(true)
		{
			if(salIter == salPerson->end())		return NULL;
			if(validSort(salIter->second))		return salIter++->second;
			++salIter;
		}
	}
	if(icurMap == 2)
	{
		while(true)
		{
			if(idIter == idPerson->end())		return NULL;
			if(validSort(idIter->second))		return idIter++->second;
			++idIter;
		}
	}
	if(icurMap == 3)
	{
		while(true)
		{
			if(surIter == surPerson->end())		return NULL;
			if(validSort(surIter->second))		return surIter++->second;
			++surIter;
		}
	}
	if(icurMap == 4)
	{
		while(true)
		{
			if(hourIter == hourPerson->end())	return NULL;
			if(validSort(hourIter->second))		return hourIter++->second;
			++hourIter;
		}
	}if(icurMap == 5)
	{
		while(true)
		{
			if(rsalIter == salPerson->rend())	return NULL;
			if(validSort(rsalIter->second))		return rsalIter++->second;
			++rsalIter;
		}
	}
	if(icurMap == 6)
	{
		while(true)
		{
			if(ridIter == idPerson->rend())		return NULL;
			if(validSort(ridIter->second))		return ridIter++->second;
			++ridIter;
		}
	}
	if(icurMap == 7)
	{
		while(true)
		{
			if(rsurIter == surPerson->rend())	return NULL;
			if(validSort(rsurIter->second))		return rsurIter++->second;
			++rsurIter;
		}
	}
	if(icurMap == 8)
	{
		while(true)
		{
			if(rhourIter == hourPerson->rend()) return NULL;
			if(validSort(rhourIter->second))	return rhourIter++->second;
			++rhourIter;
		}
	}
}
int MyCollection::GetLength()const
{
	return length;
}
Person* MyCollection::getOnIndex(TypeMap tMap, int index)
{
	int i = 1;
	if(!isReverse)
	{
		if(tMap == MyCollection::SALARY) for(auto iter = salPerson->begin(); iter != salPerson->end(); iter++) {if(validSort(iter->second)) if(i++ == index) return iter->second;}

		if(tMap == MyCollection::ID) for(auto iter = idPerson->begin(); iter != idPerson->end(); iter++) {if(validSort(iter->second)) if(i++ == index) return iter->second;}
		if(tMap == MyCollection::INITIAL) for(auto iter = surPerson->begin(); iter != surPerson->end(); iter++) {if(validSort(iter->second)) if(i++ == index) return iter->second;}
	if(tMap == MyCollection::HOURS) for(auto iter = hourPerson->begin(); iter != hourPerson->end(); iter++) {if(validSort(iter->second)) if(i++ == index) return iter->second;}
	}
	else
	{
		if(tMap == MyCollection::SALARY) for(auto iter = salPerson->rbegin(); iter != salPerson->rend(); iter++) {if(validSort(iter->second)) if(i++ == index) return iter->second;}
		if(tMap == MyCollection::ID) for(auto iter = idPerson->rbegin(); iter != idPerson->rend(); iter++) {if(validSort(iter->second)) if(i++ == index) return iter->second;}
		if(tMap == MyCollection::INITIAL) for(auto iter = surPerson->rbegin(); iter != surPerson->rend(); iter++) {if(validSort(iter->second)) if(i++ == index) return iter->second;}
		if(tMap == MyCollection::HOURS) for(auto iter = hourPerson->rbegin(); iter != hourPerson->rend(); iter++) {if(validSort(iter->second)) if(i++ == index) return iter->second;}
	}
	return NULL;
}
void MyCollection::Deleted(Person* p)
{
	float salary = p->getSalary();
	unsigned int id = p->getId();
	unsigned int hour = p->getSumHours();
	CString initial = p->getInitial();
	salPerson->erase(salary);
	idPerson->erase(id);
	surPerson->erase(initial);
	hourPerson->erase(hour);
	sumSalary -= p->getSalary();
	delete(p);
	length--;
	if (length == 0) sumSalary = 0;
}

Person* MyCollection::getOnId(unsigned id)const
{
	IdPerson::iterator iter = idPerson->find(id);
	if(iter == idPerson->end())
		return NULL;
	return iter->second;
}
float MyCollection::getSumSalary()const
{
	return sumSalary;
}
bool MyCollection::validSort(Person* p)const
{
	if(moreHours && sortHours > 0)
	{
		if(p->getSumHours() <= sortHours)
			return false;
	}
	else if(!moreHours && sortHours > 0)
	{
		if(p->getSumHours() >= sortHours)
			return false;
	}
	return true;
}
void MyCollection::subFromSumSalary(Person* p)
{
	sumSalary -= p->getSalary();
	if(sumSalary < 0) sumSalary = 0;
}
void MyCollection::addToSumSalary(float salary)
{
	sumSalary += salary;
	if(sumSalary < 0) sumSalary = 0;
}
void MyCollection::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if(ar.IsStoring())
	{
		ar<<static_cast<int>(curMap);
		ar<<length;
		ar<<sumSalary;
		ar<<icurMap;
		ar<<isReverse;
		ar<<sortHours;
		ar<<moreHours;
		for(auto iter = idPerson->begin(); iter != idPerson->end(); iter++)
			ar<<iter->second;
	}
	else
	{
		int tempElem(0);
		ar>>tempElem;
		curMap = static_cast<TypeMap>(tempElem);
		ar>>length;
		ar>>sumSalary;
		ar>>icurMap;
		ar>>isReverse;
		ar>>sortHours;
		ar>>moreHours;
		Person* p;
		for(int i = 0; i < length; i++)
		{
			ar>>p;
			(*idPerson)[p->getId()] = p;
			salPerson->insert(std::make_pair(p->getSalary(), p));
			surPerson->insert(std::make_pair(p->getInitial(), p));
			hourPerson->insert(std::make_pair(p->getSumHours(), p));
		}
	}
}
	