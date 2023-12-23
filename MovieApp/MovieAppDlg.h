
// MovieAppDlg.h: 헤더 파일
//

#pragma once


// CMovieAppDlg 대화 상자
class CMovieAppDlg : public CDialogEx
{
// 생성입니다.
public:
	CMovieAppDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOVIEAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInsert();
	afx_msg void OnBnClickedSchemaCheck();
	afx_msg void OnBnClickedSelect();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedUpdate();
};
