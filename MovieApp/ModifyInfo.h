#pragma once
#include "afxdialogex.h"


// ModifyInfo 대화 상자

class ModifyInfo : public CDialogEx
{
	DECLARE_DYNAMIC(ModifyInfo)

public:
	ModifyInfo(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ModifyInfo();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPDATE_MODIFYINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editID;
	CEdit m_editName;
	CEdit m_editPhone;
	CEdit m_editEmail;
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedShowInfo();
	CEdit m_editRecommender;
};
