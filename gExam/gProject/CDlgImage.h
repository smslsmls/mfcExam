#pragma once
#include "afxdialogex.h"

#define MAX_POINT 1000

// CDlgImage 대화 상자

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	CImage m_image;
	CWnd* m_pParent;
	int m_nDataSize = 0;
	CPoint m_ptData;
	CPoint m_ptCentor = { -1,-1 };

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDLGIMAGE1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	void InitImage();
	void drawData(CDC* pDC);
	void ChangePen(CDC* pDC, CPen* pPen, COLORREF crColor);
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
};
