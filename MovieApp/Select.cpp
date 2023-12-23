// Select.cpp: 구현 파일
//

#include "pch.h"
#include "MovieApp.h"
#include "afxdialogex.h"
#include "Select.h"
#include "ActorReview.h"
#include "Favorite.h"
#include "Trending.h"


// Select 대화 상자

IMPLEMENT_DYNAMIC(Select, CDialogEx)

Select::Select(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_MAIN, pParent)
{

}

Select::~Select()
{
}

void Select::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Select, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Select::OnBnClickedActorReview)
	ON_BN_CLICKED(IDC_BUTTON3, &Select::OnBnClickedFavorite)
	ON_BN_CLICKED(IDC_BUTTON2, &Select::OnBnClickedTrending)
END_MESSAGE_MAP()


// Select 메시지 처리기


void Select::OnBnClickedActorReview()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ActorReview obj;
	obj.DoModal();
}


void Select::OnBnClickedFavorite()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Favorite obj;
	obj.DoModal();
}


void Select::OnBnClickedTrending()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Trending obj;
	obj.DoModal();
}
