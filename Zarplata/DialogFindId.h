#pragma once
#include "MyCollection.h"

// DialogFindId dialog

class DialogFindId : public CDialogEx
{
	DECLARE_DYNAMIC(DialogFindId)

public:
	DialogFindId(CWnd* pParent = NULL);   // standard constructor
	virtual ~DialogFindId();
	bool isOk;
	MyCollection* myColl;
	Person* p;
// Dialog Data
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel10();
};
