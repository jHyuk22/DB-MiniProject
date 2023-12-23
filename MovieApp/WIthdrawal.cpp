// WIthdrawal.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "WIthdrawal.h"
#include "ODBC.h"


// WIthdrawal 대화 상자

IMPLEMENT_DYNAMIC(Withdrawal, CDialogEx)

Withdrawal::Withdrawal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE_WITHDRAWAL, pParent)
{

}

Withdrawal::~Withdrawal()
{
}

void Withdrawal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}


BEGIN_MESSAGE_MAP(Withdrawal, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Withdrawal::OnBnClickedBye)
END_MESSAGE_MAP()


// WIthdrawal 메시지 처리기


void Withdrawal::OnBnClickedBye()
{
	CString id;
	m_Edit.GetWindowTextA(id);

	ODBC obj;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (obj.db_connect())
	{
		SQLHSTMT hStmt;	// Statement Handle
		SQLCHAR query[501];

		if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 500, "DECLARE @MemberIdToDelete INT;"
				"SET @MemberIdToDelete = %s;"
				"BEGIN TRANSACTION;"
				"UPDATE MEMBER"
				"SET RECOMMENDER = NULL"
				"WHERE RECOMMENDER = @MemberIdToDelete;"
				"DELETE FROM REVIEW"
				"WHERE MEM_ID = @MemberIdToDelete;"
				"DELETE FROM TICKET"
				"WHERE MEM_ID = @MemberIdToDelete;"
				"DELETE FROM MEMBER"
				"WHERE MEM_ID = @MemberIdToDelete;"
				"COMMIT;", id);
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
			MessageBox("Success!");
		}

		obj.db_disconnect();
	}
}
