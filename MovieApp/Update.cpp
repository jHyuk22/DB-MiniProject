// Update.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "Update.h"
#include "MoveOut.h"
#include "ModifyInfo.h"


// Update 대화 상자

IMPLEMENT_DYNAMIC(Update, CDialogEx)

Update::Update(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPDATE_MAIN, pParent)
{

}

Update::~Update()
{
}

void Update::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Update, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Update::OnBnClickedMoveOut)
	ON_BN_CLICKED(IDC_BUTTON2, &Update::OnBnClickedModifyInfo)
END_MESSAGE_MAP()


// Update 메시지 처리기


void Update::OnBnClickedMoveOut()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MoveOut obj;
	obj.DoModal();
}


void Update::OnBnClickedModifyInfo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ModifyInfo obj;
	obj.DoModal();
}
