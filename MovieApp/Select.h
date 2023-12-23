#pragma once
#include "afxdialogex.h"


// Select 대화 상자

class Select : public CDialogEx
{
	DECLARE_DYNAMIC(Select)

public:
	Select(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Select();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedActorReview();
	afx_msg void OnBnClickedFavorite();
	afx_msg void OnBnClickedTrending();
};
