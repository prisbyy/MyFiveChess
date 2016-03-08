#pragma once


// CSetupDlg 对话框

class CSetupDlg : public CDialog
{
	DECLARE_DYNAMIC(CSetupDlg)

public:
	CSetupDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetupDlg();

// 对话框数据
	enum { IDD = IDD_SETUP_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
