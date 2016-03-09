#pragma once
#define _WIN 0x00
#define _LOST 0x01
#define _OTHER 0x02

class CRule
{
public:
	CRule();
	virtual ~CRule();
	
	int Win(int color, int x, int y);
	BOOL Ban(int x, int y);
private:
	BOOL forbid2(int x, int y);
	BOOL forbid1(int x, int y);
};