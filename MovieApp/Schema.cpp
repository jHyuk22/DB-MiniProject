// Schema.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "Schema.h"
#include "ODBC.h"


// Schema 대화 상자

IMPLEMENT_DYNAMIC(Schema, CDialogEx)

Schema::Schema(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCHEMA_MAIN, pParent)
{

}

Schema::~Schema()
{
}

BOOL Schema::OnInitDialog()
{
	CDialog::OnInitDialog();

	//TODO : Add extra initialization here
	m_cBox.AddString(_T("MOVIE"));
	m_cBox.AddString(_T("CINEMA"));
	m_cBox.AddString(_T("TICKET"));
	m_cBox.AddString(_T("REVIEW"));
	m_cBox.AddString(_T("MEMBER"));
	m_cBox.AddString(_T("SEAT"));
	m_cBox.SetCurSel(0);

	m_list.InsertColumn(0, _T("COLUMN_NAME"), LVCFMT_CENTER, 90);
	m_list.InsertColumn(1, _T("DATA_TYPE"), LVCFMT_CENTER, 90);
	m_list.InsertColumn(2, _T("CHAR_MAX_LEN"), LVCFMT_CENTER, 100);
	m_list.InsertColumn(3, _T("NUMERIC_PRECISION"), LVCFMT_CENTER, 120);
	m_list.InsertColumn(4, _T("DATA_NULLABLE"), LVCFMT_CENTER, 100);

	return TRUE;
}

void Schema::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_cBox);
	DDX_Control(pDX, IDC_LIST2, m_list);
}


BEGIN_MESSAGE_MAP(Schema, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Schema::OnCbnSelchangeCombo1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &Schema::OnLvnItemchangedList2)
END_MESSAGE_MAP()


// Schema 메시지 처리기

void Schema::OnCbnSelchangeCombo1()
{
    CString str; // 내용이 저장될 변수

    m_cBox.GetLBText(m_cBox.GetCurSel(), str); // 값 가져오기

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
            sprintf_s((char*)query, 500, "SELECT COLUMN_NAME, DATA_TYPE, CHARACTER_MAXIMUM_LENGTH, NUMERIC_PRECISION, IS_NULLABLE FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '%s';", str);
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

void Schema::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	*pResult = 0;
}
