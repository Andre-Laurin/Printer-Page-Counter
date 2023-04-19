// Printer Page CounterDlg.h : header file
//

#if !defined(AFX_PRINTERPAGECOUNTERDLG_H__BBDF0202_84D2_4AB5_BE36_3ADAD0883A9F__INCLUDED_)
#define AFX_PRINTERPAGECOUNTERDLG_H__BBDF0202_84D2_4AB5_BE36_3ADAD0883A9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrinterPageCounterDlg dialog

class CPrinterPageCounterDlg : public CDialog
{
// Construction
public:
	CPrinterPageCounterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrinterPageCounterDlg)
	enum { IDD = IDD_PRINTERPAGECOUNTER_DIALOG };
	int		m_nBW;
	int		m_nBWT;
	int		m_nColor;
	int		m_nColorT;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrinterPageCounterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrinterPageCounterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnSubtract();
	afx_msg void OnAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTERPAGECOUNTERDLG_H__BBDF0202_84D2_4AB5_BE36_3ADAD0883A9F__INCLUDED_)
