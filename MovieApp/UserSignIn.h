#pragma once
#include "afxdialogex.h"


// UserSignIn 대화 상자

class UserSignIn : public CDialogEx
{
	DECLARE_DYNAMIC(UserSignIn)

public:
	UserSignIn(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~UserSignIn();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int id, recommender;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedSignIn();
	CEdit userID;
	CEdit userName;
	CEdit userPhone;
	CEdit userEmail;
	CEdit userRecommender;
};
