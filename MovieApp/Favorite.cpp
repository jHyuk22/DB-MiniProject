// Favorite.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "Favorite.h"
#include "ODBC.h"

// Favorite 대화 상자

IMPLEMENT_DYNAMIC(Favorite, CDialogEx)

Favorite::Favorite(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_FAVORITE, pParent)
{

}

Favorite::~Favorite()
{
}

void Favorite::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT1, m_edit);
    DDX_Control(pDX, IDC_EDIT2, m_Print);
}


BEGIN_MESSAGE_MAP(Favorite, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Favorite::OnBnClickedSearch)
END_MESSAGE_MAP()


// Favorite 메시지 처리기


void Favorite::OnBnClickedSearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_edit.GetWindowTextA(str);

    ODBC obj;
    if (obj.db_connect())
    {
        SQLHSTMT hStmt;   // Statement Handle
        SQLCHAR query[501];

        if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS) {
            sprintf_s((char*)query, 501, "SELECT c.NAME FROM CINEMA c INNER JOIN TICKET t ON c.CINEMA_ID = t.CINEMA_ID INNER JOIN MEMBER m ON t.MEM_ID = m.MEM_ID WHERE m.EMAIL = '%s' GROUP BY c.NAME ORDER BY COUNT(*) DESC, c.NAME;", str);
            SQLExecDirect(hStmt, query, SQL_NTS);

            SQLCHAR cineName[101] = { NULL };
            SQLBindCol(hStmt, 1, SQL_C_CHAR, cineName, 100, NULL);

            while (SQLFetch(hStmt) != SQL_NO_DATA) {
                m_Print.SetWindowTextA((LPCTSTR)cineName);
            }

            SQLCloseCursor(hStmt);
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        }

        obj.db_disconnect();
    }
}
