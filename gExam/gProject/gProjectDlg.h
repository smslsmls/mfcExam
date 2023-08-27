﻿
// gProjectDlg.h: 헤더 파일
//

#include "CDlgImage.h"
#pragma once


// CgProjectDlg 대화 상자
class CgProjectDlg : public CDialogEx
{
// 생성입니다.
public:
	CgProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CDlgImage* m_pDlgImage;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nNum;
	afx_msg void OnBnClickedBtnCreate();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnGetData();
};
