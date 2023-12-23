#pragma once
#include "afxdialogex.h"


// Insert 대화 상자

class Insert : public CDialogEx
{
	DECLARE_DYNAMIC(Insert)

public:
	Insert(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Insert();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERT_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSignIn();
	afx_msg void OnBnClickedWriteReview();
};
