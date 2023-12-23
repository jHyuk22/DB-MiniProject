// WriteReview.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "WriteReview.h"
#include "ODBC.h"


// WriteReview 대화 상자

IMPLEMENT_DYNAMIC(WriteReview, CDialogEx)

WriteReview::WriteReview(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT_WRITEREVIEW, pParent)
{

}

WriteReview::~WriteReview()
{
}

void WriteReview::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editName);
	DDX_Control(pDX, IDC_EDIT2, m_editContent);
	DDX_Control(pDX, IDC_COMBO1, m_cBoxTitle);
	DDX_Control(pDX, IDC_COMBO2, m_cBoxRating);
	DDX_Control(pDX, IDC_BUTTON1, m_Submit);
	DDX_Control(pDX, IDC_BUTTON2, m_findMovie);
}

BOOL WriteReview::OnInitDialog()
{
    CDialog::OnInitDialog();

    //TODO : Add extra initialization here
    m_cBoxRating.AddString(_T("5"));
    m_cBoxRating.AddString(_T("4"));
    m_cBoxRating.AddString(_T("3"));
    m_cBoxRating.AddString(_T("2"));
    m_cBoxRating.AddString(_T("1"));

    m_cBoxRating.SetCurSel(4);
    return TRUE;
}


BEGIN_MESSAGE_MAP(WriteReview, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &WriteReview::OnBnClickedFindMovie)
    ON_BN_CLICKED(IDC_BUTTON1, &WriteReview::OnBnClickedSubmit)
END_MESSAGE_MAP()


// WriteReview 메시지 처리기


void WriteReview::OnBnClickedFindMovie()
{
    int count = m_cBoxTitle.GetCount();
    for (int i = count - 1; i >= 0; i--)
    {
        m_cBoxTitle.DeleteString(i);
    }

    CString str;
    m_editName.GetWindowTextA(str);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    ODBC obj;
    if (obj.db_connect())
    {
        printf("Connected to %s!\n\n", obj.dataSourceName);

        SQLHSTMT hStmt;   // Statement Handle
        SQLCHAR query[501];

        SQLSMALLINT colCount = -1;   // number of columns
        SQLCHAR data[50][100];      // 2d array for results
        SQLINTEGER nullData[50];   // array for null results

        if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS)
        {
            sprintf_s((char*)query, 500, "SELECT DISTINCT m.TITLE"
                " FROM MEMBER mem"
                " JOIN TICKET t ON mem.MEM_ID = t.MEM_ID"
                " JOIN MOVIE m ON t.MOVIE_ID = m.MOVIE_ID"
                " WHERE mem.NAME = '%s'; ", str);
            SQLExecDirect(hStmt, query, SQL_NTS);

            SQLNumResultCols(hStmt, &colCount);
            for (int i = 0; i < colCount; ++i)
            {
                SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), (SQLLEN*)&nullData[i]);
            }
            int index = 0;
            while (SQLFetch(hStmt) != SQL_NO_DATA)
            {
                m_cBoxTitle.AddString(_T((LPCSTR)data[index]));
            }
            m_cBoxTitle.SetCurSel(0);

            SQLCloseCursor(hStmt);
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        }

        obj.db_disconnect();
    }
}


void WriteReview::OnBnClickedSubmit()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    CString name, title, content, rating;
    m_editName.GetWindowTextA(name);
    m_editContent.GetWindowTextA(content);
    m_cBoxTitle.GetLBText(m_cBoxTitle.GetCurSel(), title);
    m_cBoxRating.GetLBText(m_cBoxRating.GetCurSel(), rating);

    ODBC obj;

    if (obj.db_connect())
    {
        printf("Connected to %s!\n\n", obj.dataSourceName);

        SQLHSTMT hStmt;	// Statement Handle
        SQLCHAR query[501];

        if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS)
        {
            sprintf_s((char*)query, 500, "INSERT INTO REVIEW (MOVIE_ID, MEM_ID, CONTENT, RATING)"
                "SELECT mov.MOVIE_ID, m.MEM_ID, '%s', %s"
                "FROM MEMBER m"
                "JOIN MOVIE mov ON m.NAME = '%s' AND mov.TITLE = '%s'; ", content, rating, name, title);
            if (SQLExecDirect(hStmt, query, SQL_NTS) == SQL_ERROR)
            {
                SQLCHAR buffer[SQL_MAX_MESSAGE_LENGTH + 1];
                SQLCHAR sqlstate[SQL_SQLSTATE_SIZE + 1];
                SQLINTEGER sqlcode;
                SQLSMALLINT length;
                SQLError(obj.hEnv, obj.hDbc, hStmt, sqlstate, &sqlcode, buffer, SQL_MAX_MESSAGE_LENGTH + 1, &length);
                printf("SQLSTATE %s\n", sqlstate);
                printf("Native error code:%ld\n", sqlcode);
                printf("%s\n\n", buffer);
                MessageBox("You've already wrote a review about this movie!");
            }
            else {
                MessageBox("Success!");
            }

            SQLCloseCursor(hStmt);
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
            
        }

        obj.db_disconnect();
    }
}
