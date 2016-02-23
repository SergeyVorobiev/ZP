#pragma once
#include<afx.h>

class Person: public CObject
{
	DECLARE_SERIAL(Person)														// ���������� ����������� ��� ������������
public:
	static const UINT VERSION_NUMBER = 1;										//������ ������� ��� ������������
	Person(CString surname, CString name, CString secondname, unsigned int ID); //��������� ��� ������� �������� � ID
	~Person(void);
	CString getSurname()const;
	unsigned int getHashCode()const;
	CString getInitial()const;													//�������� ������ ������� � ����������
	unsigned int getId()const;
	float computSalary(unsigned short normHours, unsigned short overHours, 
	unsigned short dependents, float minPayment, float hourPayment, float koef);//��������� ��������
	float getSalary()const;
	bool operator <(const Person& p)const;										//�� �������
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
	void Serialize(CArchive& ar);											//������� ������������
protected:
	Person(void);
private:
	CString name;															//���
	CString surname;														//�������
	CString secondname;														//��������
	CString initials;														//���� �.�.	
	unsigned int hashCode;													//����������������� �����
	unsigned int ID;
	unsigned short normHours;												//������������ ���������� ����	
	unsigned short overHours;												//�������������� ����
	unsigned short sumHours;												//����� �����
	unsigned short dependents;												//���������
	float minPayment;														//����������� ������� �����
	float sumPayment;														//����� � ������
	float hourPayment;														//�������� � ���
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
