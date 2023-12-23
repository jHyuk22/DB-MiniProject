#pragma once
#include "afxdialogex.h"


// ActorReview 대화 상자

class ActorReview : public CDialogEx
{
	DECLARE_DYNAMIC(ActorReview)

public:
	ActorReview(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ActorReview();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT_ACTORREVIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cBox;
	CListCtrl m_list;
	CEdit m_edit1;
	afx_msg void OnBnClickedSearch();
};
