#pragma once
#include "MyCollection.h"

// DialogPicture dialog

class DialogPicture : public CDialogEx
{
	DECLARE_DYNAMIC(DialogPicture)

public:
	DialogPicture(CWnd* pParent = NULL);   // standard constructor
	virtual ~DialogPicture();
	MyCollection* coll;
	int curPerson;
// Dialog Data
	enum { IDD = IDD_DIALOG13 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
