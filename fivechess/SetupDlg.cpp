// SetupDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "fivechess.h"
#include "SetupDlg.h"
#include "afxdialogex.h"


// CSetupDlg 对话框

IMPLEMENT_DYNAMIC(CSetupDlg, CDialog)

CSetupDlg::CSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetupDlg::IDD, pParent)
{

}

CSetupDlg::~CSetupDlg()
{
}

void CSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSetupDlg, CDialog)
END_MESSAGE_MAP()


// CSetupDlg 消息处理程序
