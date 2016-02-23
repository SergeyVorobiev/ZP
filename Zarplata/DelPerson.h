#pragma once


// DelPerson dialog

class DelPerson : public CDialogEx
{
	DECLARE_DYNAMIC(DelPerson)

public:
	DelPerson(CWnd* pParent = NULL);   // standard constructor
	virtual ~DelPerson();
	bool isDeleted;
// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
