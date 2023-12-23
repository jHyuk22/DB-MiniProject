#pragma once
#include "afxdialogex.h"


// Favorite 대화 상자

class Favorite : public CDialogEx
{
	DECLARE_DYNAMIC(Favorite)

public:
	Favorite(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Favorite();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT_FAVORITE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	afx_msg void OnBnClickedSearch();
	CEdit m_Print;
};
