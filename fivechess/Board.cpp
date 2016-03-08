#include "stdafx.h"
#include "Board.h"
#include "fivechess.h"

//œ˚œ¢”≥…‰±Ì
BEGIN_MESSAGE_MAP(CBoard, CWnd)
//{{AFX_MSG_MAP(CBoard)
ON_WM_PAINT()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CBoard::CBoard()
{
	m_iml.Create(24, 24, ILC_COLOR24 | ILC_MASK, 0, 2);
	CBitmap bmpBlack, bmpWhite;
	bmpBlack.LoadBitmap(IDB_BITMAP_BLACK);
	m_iml.Add(&bmpBlack, 0xff00ff);
	bmpWhite.LoadBitmap(IDB_BITMAP_WHITE);
	m_iml.Add(&bmpWhite, 0xff00ff);
}


CBoard::~CBoard()
{
}

void CBoard::OnPaint()
{
	CPaintDC dc(this);
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	CBitmap bmp;
	CPen pen;
	bmp.LoadBitmap(IDB_BITMAP_QP);
	pen.CreatePen(PS_SOLID, 1, 0xFF);
	MemDC.SelectObject(&bmp);
	MemDC.SelectObject(&pen);
	MemDC.SetROP2(R2_NOTXORPEN);
	
	int x, y;
	POINT pt;
	for (y = 0; y < 15; ++y)
	{
		for (x = 0; x < 15; ++x)
		{
			if (-1 != m_data[x][y])
			{
				pt.x = 12 + 25 * x;
				pt.y = 84 + 25 * y;
				m_iml.Draw(&MemDC, m_data[x][y], pt, ILD_TRANSPARENT);
			}
		}
	}
	dc.BitBlt(0, 0, 395, 472, &MemDC, 0, 0, SRCCOPY);
}

void CBoard::Clear(BOOL bWait)
{
	int x, y;
	for (x = 0; x < 15; ++x)
	{
		for (y = 0; y < 15; ++y)
		{
			m_data[x][y] = -1;
		}
	}
	m_bWait = bWait;
	Invalidate();
}

void CBoard::SetColor(int color)
{
	m_color = color;
}

int CBoard::GetColor()
{
	return m_color;
}

int SetData(int x, int y, int color)
{
	m_data[x][y] = color;
}

int CBoard::Draw(int x, int y, int color)
{
	POINT pt;
	pt.x = 12 + 25 * x;
	pt.y = 84 + 25 * y;
	CDC *pDC = GetDC();
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, 0xff);
	pDC->SelectObject(&pen);
	pDC->SetROP2(R2_NOTXORPEN);
	m_iml.Draw(pDC, color, pt, ILD_TRANSPARENT);
	ReleaseDC(pDC);
}