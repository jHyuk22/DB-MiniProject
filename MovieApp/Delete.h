#pragma once
#include "afxdialogex.h"


// Delete 대화 상자

class Delete : public CDialogEx
{
	DECLARE_DYNAMIC(Delete)

public:
	Delete(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Delete();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedWithdrawal();
	afx_msg void OnBnClickedBeSued();
};
