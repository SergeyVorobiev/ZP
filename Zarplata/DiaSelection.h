#pragma once
#include "MyCollection.h"

// DiaSelection dialog

class DiaSelection : public CDialogEx
{
	DECLARE_DYNAMIC(DiaSelection)

public:
	DiaSelection(CWnd* pParent = NULL);   // standard constructor
	virtual ~DiaSelection();
	MyCollection* coll;
	CString ToCString(unsigned int value)const;
// Dialog Data
	enum { IDD = IDD_DIASELECTION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
