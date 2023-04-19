// Printer Page CounterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Printer Page Counter.h"
#include "Printer Page CounterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrinterPageCounterDlg dialog

CPrinterPageCounterDlg::CPrinterPageCounterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrinterPageCounterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrinterPageCounterDlg)
	m_nBW = 0;
	m_nBWT = 0;
	m_nColor = 0;
	m_nColorT = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		// Open file and get current print results. If file does not exist then set results to 0 
	CString strFileName, strError;
	
	strFileName = "results.dat";

	CFile fileText;
	CFileException ErrorCode;
	CFileStatus status;

	if(fileText.Open(strFileName, CFile::modeRead | CFile::typeBinary, &ErrorCode))
	{
		fileText.Read(&m_nBWT, sizeof(m_nBWT));
		fileText.Read(&m_nColorT, sizeof(m_nColorT));
		fileText.Close();
	} else {
		if(ErrorCode.m_cause != CFileException::fileNotFound)
		{
			strError.Format("File read error: %s", ErrorCode.m_cause);
			AfxMessageBox(strError);
		} else {
			m_nBWT = m_nColorT = 0;
		}
	}	
}

void CPrinterPageCounterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrinterPageCounterDlg)
	DDX_Text(pDX, IDC_BW, m_nBW);
	DDV_MinMaxInt(pDX, m_nBW, 0, 1000);
	DDX_Text(pDX, IDC_BWT, m_nBWT);
	DDX_Text(pDX, IDC_COLOR, m_nColor);
	DDV_MinMaxInt(pDX, m_nColor, 0, 1000);
	DDX_Text(pDX, IDC_COLORT, m_nColorT);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrinterPageCounterDlg, CDialog)
	//{{AFX_MSG_MAP(CPrinterPageCounterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_SUBTRACT, OnSubtract)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrinterPageCounterDlg message handlers

BOOL CPrinterPageCounterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPrinterPageCounterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPrinterPageCounterDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPrinterPageCounterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPrinterPageCounterDlg::OnAdd() 
{
	CString strFileName, strError;

	strFileName = "results.dat";

	CFile fileText;
	CFileException ErrorCode;
	CFileStatus status;

	UpdateData();

	if(m_nBW == 0 && m_nColor == 0) {
		strError.Format("There's no need to add a 0.");
		AfxMessageBox(strError);
	} else {		
		m_nBWT += m_nBW;
		m_nColorT += m_nColor;		
		if(fileText.Open(strFileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::typeBinary, &ErrorCode))
		{
			fileText.Write(&m_nBWT, sizeof(m_nBWT));
			fileText.Write(&m_nColorT, sizeof(m_nColorT));
			fileText.Close();
			m_nBW = m_nColor = 0;
			UpdateData(FALSE);
		} else {
			strError.Format("File write error: %s", ErrorCode.m_cause);
			AfxMessageBox(strError);
		}
	}
}

void CPrinterPageCounterDlg::OnSubtract() 
{
	CString strFileName, strError;

	strFileName = "results.dat";

	CFile fileText;
	CFileException ErrorCode;
	CFileStatus status;

	UpdateData();

	if(m_nBW == 0 && m_nColor == 0) {
		strError.Format("There's no need to subtract a 0.");
		AfxMessageBox(strError);
	} else {
		m_nBWT -= m_nBW;
		m_nColorT -= m_nColor;
		if(m_nBWT < 0 || m_nColorT < 0)
		{
			m_nBWT += m_nBW;
			m_nColorT += m_nColor;
			strError.Format("You can't unprint pages :)");
			AfxMessageBox(strError);
		} else {
				
			if(fileText.Open(strFileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::typeBinary, &ErrorCode))
			{
				fileText.Write(&m_nBWT, sizeof(m_nBWT));
				fileText.Write(&m_nColorT, sizeof(m_nColorT));
				fileText.Close();
				m_nBW = m_nColor = 0;
				UpdateData(FALSE);
			} else {
				strError.Format("File write error: %s", ErrorCode.m_cause);
				AfxMessageBox(strError);
			}
		}
	}
}


void CPrinterPageCounterDlg::OnAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}
