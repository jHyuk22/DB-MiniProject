// MoveOut.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "MoveOut.h"
#include "ODBC.h"


// MoveOut 대화 상자

IMPLEMENT_DYNAMIC(MoveOut, CDialogEx)

MoveOut::MoveOut(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPDATE_MOVEOUT, pParent)
{

}

MoveOut::~MoveOut()
{
}

void MoveOut::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editCineName);
	DDX_Control(pDX, IDC_EDIT2, m_editAddress);
	DDX_Control(pDX, IDC_BUTTON1, m_udpate);
}


BEGIN_MESSAGE_MAP(MoveOut, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MoveOut::OnBnClickedUpdate)
END_MESSAGE_MAP()


// MoveOut 메시지 처리기


void MoveOut::OnBnClickedUpdate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cineName, address;

	m_editAddress.GetWindowTextA(cineName);
	m_editCineName.GetWindowTextA(address);

	ODBC obj;

	if (obj.db_connect())
	{
		printf("Connected to %s!\n\n", obj.dataSourceName);

		SQLHSTMT hStmt;	// Statement Handle
		SQLCHAR query[101];

		if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 101, "UPDATE CINEMA SET ADDRESS = '%s' WHERE NAME = '%s'; ", address, cineName);
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}
		MessageBox("Success!");
		obj.db_disconnect();
	}
}
