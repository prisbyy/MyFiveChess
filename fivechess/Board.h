#pragma once
#include "afxwin.h"
class CBoard :
	public CWnd
{
public:
	CBoard();
	~CBoard();

	CImageList m_iml;

	void Clear(BOOL bWait);
	void SetColor(int color);
	int GetColor();
	int SetWait(BOOL bWait);
	int SetData(int x, int y, int color);
	int Draw(int x, int y, int color);
private:
	BOOL m_bWait;
	int m_color;
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP();
};

