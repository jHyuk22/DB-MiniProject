#pragma once
#include "afxdialogex.h"


// Update 대화 상자

class Update : public CDialogEx
{
	DECLARE_DYNAMIC(Update)

public:
	Update(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Update();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPDATE_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMoveOut();
	afx_msg void OnBnClickedModifyInfo();
};
