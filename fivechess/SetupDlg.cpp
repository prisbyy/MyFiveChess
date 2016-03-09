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
	, m_net_port(0), m_is_HOST(FALSE)
{

}

CSetupDlg::~CSetupDlg()
{
}

void CSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IP_ADDRESS_EDIT, m_addr_ip);
	DDX_Text(pDX, IDC_PORT_EDIT, m_net_port);
	DDV_MinMaxUInt(pDX, m_net_port, 1, 65530);
}


BEGIN_MESSAGE_MAP(CSetupDlg, CDialog)
	ON_BN_CLICKED(IDCANCEL, &CSetupDlg::OnCancel)
	ON_BN_CLICKED(IDOK, &CSetupDlg::OnOk)
	ON_COMMAND(IDC_HOST_OPTION, &CSetupDlg::OnHostOption)
	ON_COMMAND(IDC_CLIENT_OPTION, &CSetupDlg::OnClientOption)
END_MESSAGE_MAP()


// CSetupDlg 消息处理程序


void CSetupDlg::OnCancel()
{
	CDialog::OnCancel();
}


void CSetupDlg::OnOk()
{
	CString strIP;
	CString strPort;
	UpdateData(TRUE);
	m_addr_ip.GetWindowText(strIP);
	strPort.Format("%d", m_net_port);
	if (m_is_HOST)
	{
		WritePrivateProfileString("HOST", "PORT", strPort, ".\\config.ini");
	}
	else
	{
		WritePrivateProfileString("CLIENT", "IP", strIP, ".\\config.ini");
		WritePrivateProfileString("CLIENT", "PORT", strPort, ".\\config.ini");
	}
	CDialog::OnOK();
}


void CSetupDlg::OnHostOption()
{
	char str[128] = {0};
	m_is_HOST = TRUE;
	GetPrivateProfileString("HOST", "IP", "", str, 127, ".\\config.ini");
	memset(str, 0, 128);
	GetPrivateProfileString("HOST", "PORT", "", str, 127, ".\\config.ini");
	m_net_port = atoi(str);
	UpdateData(FALSE);
}


void CSetupDlg::OnClientOption()
{
	char str[128] = { 0 };
	m_addr_ip.EnableWindow(TRUE);
	GetPrivateProfileString("CLIENT", "IP", "", str, 127, ".\\config.ini");
	m_addr_ip.SetWindowText(str);
	memset(str, 0, 128);
	GetPrivateProfileString("CLIENT", "PORT", "", str, 127, ".\\config.ini");
	m_net_port = atoi(str);
	m_is_HOST = FALSE;
	UpdateData(FALSE);
}

BOOL CSetupDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	((CButton*)GetDlgItem(IDC_HOST_OPTION))->SetCheck(1);
	OnHostOption();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
