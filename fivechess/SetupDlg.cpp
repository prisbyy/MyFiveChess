// SetupDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "fivechess.h"
#include "SetupDlg.h"
#include "afxdialogex.h"


// CSetupDlg �Ի���

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


// CSetupDlg ��Ϣ�������
