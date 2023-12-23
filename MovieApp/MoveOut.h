#pragma once
#include "afxdialogex.h"


// MoveOut 대화 상자

class MoveOut : public CDialogEx
{
	DECLARE_DYNAMIC(MoveOut)

public:
	MoveOut(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MoveOut();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPDATE_MOVEOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editCineName;
	CEdit m_editAddress;
	CButton m_udpate;
	afx_msg void OnBnClickedUpdate();
};
