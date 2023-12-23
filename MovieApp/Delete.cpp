// Delete.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "Delete.h"
#include "Withdrawal.h"
#include "BeSued.h"


// Delete 대화 상자

IMPLEMENT_DYNAMIC(Delete, CDialogEx)

Delete::Delete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE_MAIN, pParent)
{

}

Delete::~Delete()
{
}

void Delete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Delete, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Delete::OnBnClickedWithdrawal)
	ON_BN_CLICKED(IDC_BUTTON2, &Delete::OnBnClickedBeSued)
END_MESSAGE_MAP()


// Delete 메시지 처리기


void Delete::OnBnClickedWithdrawal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Withdrawal obj;
	obj.DoModal();

}


void Delete::OnBnClickedBeSued()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BeSued obj;
	obj.DoModal();
}
