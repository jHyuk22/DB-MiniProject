// ActorReview.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "ActorReview.h"
#include "ODBC.h"


// ActorReview 대화 상자

IMPLEMENT_DYNAMIC(ActorReview, CDialogEx)

ActorReview::ActorReview(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_ACTORREVIEW, pParent)
{

}

ActorReview::~ActorReview()
{
}

BOOL ActorReview::OnInitDialog()
{
	CDialog::OnInitDialog();

	//TODO : Add extra initialization here

	m_list.InsertColumn(0, _T("MOVIE_TITLE"), LVCFMT_CENTER, 150);
	m_list.InsertColumn(1, _T("RATING"), LVCFMT_CENTER, 90);

	return TRUE;
}

void ActorReview::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
}


BEGIN_MESSAGE_MAP(ActorReview, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ActorReview::OnBnClickedSearch)
END_MESSAGE_MAP()



void ActorReview::OnBnClickedSearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_edit1.GetWindowTextA(str);

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
            sprintf_s((char*)query, 500, "SELECT m.TITLE, ROUND(AVG(m.RATING),2) AS AverageRating FROM MOVIE m WHERE m.MAIN_ACTOR = '%s' GROUP BY m.TITLE; ", str);
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
