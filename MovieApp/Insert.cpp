// Insert.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "Insert.h"
#include "UserSignIn.h"
#include "WriteReview.h"


// Insert 대화 상자

IMPLEMENT_DYNAMIC(Insert, CDialogEx)

Insert::Insert(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT_MAIN, pParent)
{

}

Insert::~Insert()
{
}

void Insert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Insert, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Insert::OnBnClickedSignIn)
	ON_BN_CLICKED(IDC_BUTTON2, &Insert::OnBnClickedWriteReview)
END_MESSAGE_MAP()


// Insert 메시지 처리기


void Insert::OnBnClickedSignIn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UserSignIn obj;

	obj.DoModal();
}


void Insert::OnBnClickedWriteReview()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	WriteReview obj;
	obj.DoModal();
}
