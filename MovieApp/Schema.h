#pragma once
#include "afxdialogex.h"


// Schema 대화 상자

class Schema : public CDialogEx
{
	DECLARE_DYNAMIC(Schema)

public:
	Schema(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Schema();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_cBox;
	CListCtrl m_list;
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
};
