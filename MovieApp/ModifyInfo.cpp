// ModifyInfo.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "ModifyInfo.h"
#include "ODBC.h"


// ModifyInfo 대화 상자

IMPLEMENT_DYNAMIC(ModifyInfo, CDialogEx)

ModifyInfo::ModifyInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPDATE_MODIFYINFO, pParent)
{

}

ModifyInfo::~ModifyInfo()
{
}

void ModifyInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editID);
	DDX_Control(pDX, IDC_EDIT2, m_editName);
	DDX_Control(pDX, IDC_EDIT3, m_editPhone);
	DDX_Control(pDX, IDC_EDIT4, m_editEmail);
	DDX_Control(pDX, IDC_EDIT5, m_editRecommender);
}


BEGIN_MESSAGE_MAP(ModifyInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ModifyInfo::OnBnClickedModify)
	ON_BN_CLICKED(IDC_BUTTON1, &ModifyInfo::OnBnClickedShowInfo)
END_MESSAGE_MAP()


// ModifyInfo 메시지 처리기

void ModifyInfo::OnBnClickedShowInfo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString id;
	m_editID.GetWindowTextA(id);
	if (id) {
		m_editID.SetReadOnly(TRUE);
	}


    ODBC obj;
    if (obj.db_connect())
    {
        SQLHSTMT hStmt;   // Statement Handle
        SQLCHAR query[501];

        SQLSMALLINT colCount = -1;   // number of columns
        SQLCHAR data[50][1000];      // 2d array for results
        SQLINTEGER nullData[50];   // array for null results

        if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS) {
            sprintf_s((char*)query, 501, "SELECT NAME, PHONE, EMAIL, RECOMMENDER FROM MEMBER WHERE MEM_ID = %s; ", id);
            SQLExecDirect(hStmt, query, SQL_NTS);

            SQLNumResultCols(hStmt, &colCount);
            for (int i = 0; i < colCount; ++i)
            {
                SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), (SQLLEN*)&nullData[i]);
            }

            while (SQLFetch(hStmt) != SQL_NO_DATA) {
                m_editName.SetWindowTextA((LPCTSTR)data[0]);
                m_editPhone.SetWindowTextA((LPCTSTR)data[1]);
                m_editEmail.SetWindowTextA((LPCTSTR)data[2]);
                m_editRecommender.SetWindowTextA((LPCTSTR)data[3]);
            }

            SQLCloseCursor(hStmt);
            SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
        }

        obj.db_disconnect();
    }
}

void ModifyInfo::OnBnClickedModify()
{
	CString id, name, phone, email;
	m_editID.GetWindowTextA(id);
	m_editName.GetWindowTextA(name);
	m_editPhone.GetWindowTextA(phone);
	m_editEmail.GetWindowTextA(email);

	ODBC obj;

	if (obj.db_connect())
	{
		printf("Connected to %s!\n\n", obj.dataSourceName);

		SQLHSTMT hStmt;	// Statement Handle
		SQLCHAR query[501];

		if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 500, "UPDATE MEMBER SET NAME = '%s', PHONE = '%s', EMAIL = '%s' WHERE MEM_ID = %s; ", name, phone, email, id);
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}
		MessageBox("Success!");
		obj.db_disconnect();
	}
	m_editID.SetReadOnly(FALSE);
	m_editID.SetWindowText(_T(""));
	m_editName.SetWindowText(_T(""));
	m_editPhone.SetWindowText(_T(""));
	m_editEmail.SetWindowText(_T(""));
	m_editRecommender.SetWindowText(_T(""));
}



