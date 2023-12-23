#pragma once
#include "afxdialogex.h"


// WriteReview 대화 상자

class WriteReview : public CDialogEx
{
	DECLARE_DYNAMIC(WriteReview)

public:
	WriteReview(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~WriteReview();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERT_WRITEREVIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editName;
	CEdit m_editContent;
	CComboBox m_cBoxTitle;
	CComboBox m_cBoxRating;
	CButton m_Submit;
	CButton m_findMovie;
	afx_msg void OnBnClickedFindMovie();
	afx_msg void OnBnClickedSubmit();
};
