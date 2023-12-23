#pragma once
#include "afxdialogex.h"


// Trending 대화 상자

class Trending : public CDialogEx
{
	DECLARE_DYNAMIC(Trending)

public:
	Trending(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Trending();

	BOOL OnInitDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT_TRENDING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CButton m_show;
	afx_msg void OnBnClickedShowMe();
};
