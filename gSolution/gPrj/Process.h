﻿#pragma once

// CProcess 명령 대상

class CProcess : public CObject
{
public:
	CProcess();
	virtual ~CProcess();

	int getStarInfo(CImage* image, int nTh=100);
	int getStarInfo(CImage* image, int nTh, CRect rect);
};


