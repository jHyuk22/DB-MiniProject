// BeSued.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "BeSued.h"
#include "ODBC.h"


// BeSued 대화 상자

IMPLEMENT_DYNAMIC(BeSued, CDialogEx)

BeSued::BeSued(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE_BESUED, pParent)
{

}

BeSued::~BeSued()
{
}

void BeSued::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(BeSued, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &BeSued::OnBnClickedCleanIt)
END_MESSAGE_MAP()


// BeSued 메시지 처리기


void BeSued::OnBnClickedCleanIt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_edit.GetWindowTextA(str);

	ODBC obj;
	if (obj.db_connect())
	{
		SQLHSTMT hStmt;	// Statement Handle
		SQLCHAR query[501];

		if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 500, "DELETE FROM REVIEW WHERE MOVIE_ID IN( SELECT MOVIE_ID FROM MOVIE WHERE MAIN_ACTOR = '%s' ); ", str);
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
			MessageBox("Success!");
		}

		obj.db_disconnect();
	}
}
