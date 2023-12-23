// Trending.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "Trending.h"
#include "ODBC.h"


// Trending 대화 상자

IMPLEMENT_DYNAMIC(Trending, CDialogEx)

Trending::Trending(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_TRENDING, pParent)
{

}

Trending::~Trending()
{
}

BOOL Trending::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_list.InsertColumn(0, _T("TITLE"), LVCFMT_CENTER, 90);
	m_list.InsertColumn(1, _T("BOOKINGS"), LVCFMT_CENTER, 90);
	m_list.InsertColumn(2, _T("RATIINGS"), LVCFMT_CENTER, 90);

	return TRUE;
}

void Trending::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_BUTTON1, m_show);
}


BEGIN_MESSAGE_MAP(Trending, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Trending::OnBnClickedShowMe)
END_MESSAGE_MAP()


// Trending 메시지 처리기


void Trending::OnBnClickedShowMe()
{
    ODBC obj;
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    if (obj.db_connect())
    {
        printf("Connected to %s!\n\n", obj.dataSourceName);

        SQLHSTMT hStmt;   // Statement Handle
        SQLCHAR query[501];

        SQLSMALLINT colCount = -1;   // number of columns
        SQLCHAR data[50][1000];      // 2d array for results
        SQLINTEGER nullData[50];   // array for null results

        if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS)
        {
            sprintf_s((char*)query, 500, "SELECT TOP 3 TITLE, BOOKINGS, RATING　FROM (SELECT m.TITLE, t.BOOKINGS, m.RATING,ROW_NUMBER() OVER (ORDER BY t.BOOKINGS DESC) AS RＮ　FROM MOVIE m　INNER JOIN (SELECT MOVIE_ID, COUNT(*) AS BOOKINGS　FROM TICKET　GROUP BY MOVIE_ID) t ON m.MOVIE_ID = t.MOVIE_ID) AS sub　WHERE RN <= 3　ORDER BY BOOKINGS DESC;");
            SQLExecDirect(hStmt, query, SQL_NTS);

            SQLNumResultCols(hStmt, &colCount);
            for (int i = 0; i < colCount; ++i)
            {
                SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), (SQLLEN*)&nullData[i]);
            }

            int index = 0;
            m_list.DeleteAllItems();

            while (SQLFetch(hStmt) != SQL_NO_DATA)
            {
                m_list.InsertItem(index, _T("index"));
                for (int i = 0; i < colCount; ++i)
                {
                    if (nullData[i] == SQL_NULL_DATA) m_list.SetItem(index, i, LVIF_TEXT, TEXT("NULL"), NULL, NULL, NULL, NULL);
                    else m_list.SetItem(index, i, LVIF_TEXT, TEXT((const char*)data[i]), NULL, NULL, NULL, NULL);
                }
                index++;
            }

            SQLCloseCursor(hStmt);
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        }

        obj.db_disconnect();
    }
}
