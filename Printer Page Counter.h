// Printer Page Counter.h : main header file for the PRINTER PAGE COUNTER application
//

#if !defined(AFX_PRINTERPAGECOUNTER_H__E80F612E_76D6_40A6_BD80_240AF9F552FF__INCLUDED_)
#define AFX_PRINTERPAGECOUNTER_H__E80F612E_76D6_40A6_BD80_240AF9F552FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrinterPageCounterApp:
// See Printer Page Counter.cpp for the implementation of this class
//

class CPrinterPageCounterApp : public CWinApp
{
public:
	CPrinterPageCounterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrinterPageCounterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrinterPageCounterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTERPAGECOUNTER_H__E80F612E_76D6_40A6_BD80_240AF9F552FF__INCLUDED_)
