#pragma once
#include "afxdialogex.h"


// BeSued 대화 상자

class BeSued : public CDialogEx
{
	DECLARE_DYNAMIC(BeSued)

public:
	BeSued(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~BeSued();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE_BESUED };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCleanIt();
	CEdit m_edit;
};
