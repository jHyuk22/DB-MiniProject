#pragma once
#include "afxdialogex.h"


// WIthdrawal 대화 상자

class Withdrawal : public CDialogEx
{
	DECLARE_DYNAMIC(Withdrawal)

public:
	Withdrawal(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Withdrawal();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE_WITHDRAWAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit;
	afx_msg void OnBnClickedBye();
};
