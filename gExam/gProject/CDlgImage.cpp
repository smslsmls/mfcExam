// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "gProject.h"
#include "afxdialogex.h"
#include "CDlgImage.h"
#include <iostream>

// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (m_image)
	{
		m_image.Draw(dc, 0, 0);
	}

	drawData(&dc);
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	MoveWindow(0, 0, 640, 480);

	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgImage::InitImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8)
	{
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
		{
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);
}


void CDlgImage::drawData(CDC* pDC)
{
	CRect rect;
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, COLOR_RED);
	CPen* pOldPen = pDC->SelectObject(&pen);
	if (m_ptCentor.x >= 0 && m_ptCentor.y >= 0)
	{
		ChangePen(pDC, &pen, COLOR_YELLOW);
		rect.SetRect(m_ptCentor, m_ptCentor);
		rect.InflateRect(10, 10);
		pDC->Ellipse(rect);
		ChangePen(pDC, &pen, COLOR_RED);
		pDC->MoveTo(m_ptCentor.x - 6, m_ptCentor.y);
		pDC->LineTo(m_ptCentor.x + 5, m_ptCentor.y);
		pDC->MoveTo(m_ptCentor.x, m_ptCentor.y - 6);
		pDC->LineTo(m_ptCentor.x, m_ptCentor.y + 5);
	}
	for (int i = 0; i < m_nDataCount; i++)
	{
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(5, 5);
		pDC->Ellipse(rect);
	}
	pDC->SelectObject(pOldPen);
}

void CDlgImage::ChangePen(CDC* pDC, CPen* pPen, COLORREF crColor)
{
	pPen->DeleteObject();
	pPen->CreatePen(PS_SOLID, 2, crColor);
	pDC->SelectObject(pPen);
}