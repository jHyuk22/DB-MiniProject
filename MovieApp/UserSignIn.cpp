// UserSignIn.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "UserSignIn.h"
#include "ODBC.h"

// UserSignIn 대화 상자

IMPLEMENT_DYNAMIC(UserSignIn, CDialogEx)

UserSignIn::UserSignIn(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT_SIGNIN, pParent)
{

}

UserSignIn::~UserSignIn()
{
}

void UserSignIn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, userID);
	DDX_Control(pDX, IDC_EDIT2, userName);
	DDX_Control(pDX, IDC_EDIT3, userPhone);
	DDX_Control(pDX, IDC_EDIT4, userEmail);
	DDX_Control(pDX, IDC_EDIT5, userRecommender);
}


BEGIN_MESSAGE_MAP(UserSignIn, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &UserSignIn::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &UserSignIn::OnBnClickedSignIn)
END_MESSAGE_MAP()


// UserSignIn 메시지 처리기


void UserSignIn::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void UserSignIn::OnBnClickedSignIn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString id, name, phone, email, recommender;
	userID.GetWindowTextA(id);
	userName.GetWindowTextA(name);
	userPhone.GetWindowTextA(phone);
	userEmail.GetWindowTextA(email);
	userRecommender.GetWindowTextA(recommender);

	ODBC obj;
	
	if (obj.db_connect())
	{
		printf("Connected to %s!\n\n", obj.dataSourceName);

		SQLHSTMT hStmt;	// Statement Handle
		SQLCHAR query[101];

		if (SQLAllocHandle(SQL_HANDLE_STMT, obj.hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 101, "INSERT INTO MEMBER VALUES(%s, %s, '%s', '%s', '%s');", id, recommender, name, phone, email);
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
			}

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
			MessageBox("Success!");
		}

		obj.db_disconnect();
	}
}
