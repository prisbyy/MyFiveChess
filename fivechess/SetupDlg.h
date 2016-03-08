#pragma once
#include "afxcmn.h"


// CSetupDlg 对话框

class CSetupDlg : public CDialog
{
	DECLARE_DYNAMIC(CSetupDlg)

public:
	CSetupDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetupDlg();

public:
	BOOL m_is_HOST;
// 对话框数据
	enum { IDD = IDD_SETUP_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CIPAddressCtrl m_addr_ip;
	UINT m_net_port;
	afx_msg void OnCancel();
	afx_msg void OnOk();
	afx_msg void OnHostOption();
	afx_msg void OnClientOption();
	virtual BOOL OnInitDialog();
};
