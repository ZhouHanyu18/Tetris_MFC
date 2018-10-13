
// 俄罗斯方块-MFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "俄罗斯方块-MFC.h"
#include "俄罗斯方块-MFCDlg.h"
#include "afxdialogex.h"
#include <time.h>
#include <thread>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define ROW 16
#define COLUMN 16
#define SPACE 20
#define SPEED 500

using namespace std;
int CuPosX = 0, CuPosY = 6;
//void CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime);

struct SMAP
{
	COLORREF rgb=RGB(255,255,255);
};
SMAP map[ROW][COLUMN];
SMAP smap[4][4];
SMAP contral[4][4];
int n_code;

struct SHARP
{
	SMAP map[4][4];
}sharp[16];

void C俄罗斯方块MFCDlg::PaintMap()
{
	
		CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
		CDC* pDC = GetDC();
		pDC->SelectObject(&pen);

		//pDC->MoveTo(0, 0);
		//pDC->LineTo(300, 300);

		//CBrush brushMap(RGB(255, 255, 255));
		//brushMap.CreateSolidBrush(RGB(255, 255, 0));
		//pDC->SelectObject(&brushMap);
		//pDC->Rectangle(CRect(0, 0, 360, 800));//初始化背景

		//ReleaseDC(pDC);


		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COLUMN; ++j)
			{
				CBrush brushMap;
				brushMap.CreateSolidBrush(map[i][j].rgb);
				pDC->SelectObject(&brushMap);
				pDC->Rectangle(CRect(SPACE*j, SPACE*i, SPACE*(j+1), SPACE*(i+1)));
			}
		}
		ReleaseDC(pDC);
}

void C俄罗斯方块MFCDlg::PaintSMap()
{
	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
	CDC* pDC = GetDC();
	pDC->SelectObject(&pen);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			CBrush brushMap;
			brushMap.CreateSolidBrush(smap[i][j].rgb);
			pDC->SelectObject(&brushMap);
			pDC->Rectangle(CRect(400+SPACE*j, 60+SPACE*i, 400+SPACE*(j+1), 60+SPACE*(i + 1)));
		}
	}
	
	pDC->SetTextColor(RGB(255,0,0));
	pDC->TextOut(380, 20, L"下一个方块：");
	pDC->TextOut(380, 200, L"得分：");
	pDC->TextOut(350, 245, L"下落速度：");
	ReleaseDC(pDC);
}

void Init_sharp()
{
	srand(time(NULL));
	COLORREF temp;
	int x = rand() / 255;
	int y = rand() / 255;
	int z = rand() / 255;
	temp=RGB(x, y, z);
	sharp[0].map[0][1].rgb = temp;
	sharp[0].map[1][1].rgb = temp;
	sharp[0].map[2][1].rgb = temp;
	sharp[0].map[3][1].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[1].map[2][0].rgb = temp;
	sharp[1].map[2][1].rgb = temp;
	sharp[1].map[2][2].rgb = temp;
	sharp[1].map[2][3].rgb = temp;
	
	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[2].map[0][1].rgb = temp;
	sharp[2].map[1][1].rgb = temp;
	sharp[2].map[1][2].rgb = temp;
	sharp[2].map[2][2].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[3].map[1][0].rgb = temp;
	sharp[3].map[1][1].rgb = temp;
	sharp[3].map[1][2].rgb = temp;
	sharp[3].map[1][3].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[4].map[0][1].rgb = temp;
	sharp[4].map[1][1].rgb = temp;
	sharp[4].map[2][1].rgb = temp;
	sharp[4].map[2][2].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[5].map[2][0].rgb = temp;
	sharp[5].map[2][1].rgb = temp;
	sharp[5].map[2][2].rgb = temp;
	sharp[5].map[1][2].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[6].map[1][2].rgb = temp;
	sharp[6].map[1][1].rgb = temp;
	sharp[6].map[2][1].rgb = temp;
	sharp[6].map[3][1].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[7].map[1][1].rgb = temp;
	sharp[7].map[2][1].rgb = temp;
	sharp[7].map[1][2].rgb = temp;
	sharp[7].map[1][3].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[8].map[0][1].rgb = temp;
	sharp[8].map[1][1].rgb = temp;
	sharp[8].map[2][1].rgb = temp;
	sharp[8].map[2][0].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[9].map[2][0].rgb = temp;
	sharp[9].map[2][1].rgb = temp;
	sharp[9].map[2][2].rgb = temp;
	sharp[9].map[1][2].rgb = temp;
	sharp[9].map[2][3].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[10].map[1][1].rgb = temp;
	sharp[10].map[1][2].rgb = temp;
	sharp[10].map[2][2].rgb = temp;
	sharp[10].map[3][2].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[11].map[1][1].rgb = temp;
	sharp[11].map[1][2].rgb = temp;
	sharp[11].map[1][3].rgb = temp;
	sharp[11].map[2][2].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[12].map[1][1].rgb = temp;
	sharp[12].map[1][2].rgb = temp;
	sharp[12].map[2][1].rgb = temp;
	sharp[12].map[2][2].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[13].map[1][1].rgb = temp;
	sharp[13].map[1][2].rgb = temp;
	sharp[13].map[2][1].rgb = temp;
	sharp[13].map[2][2].rgb = temp;
	sharp[13].map[0][1].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[14].map[0][1].rgb = temp;
	sharp[14].map[1][1].rgb = temp;
	sharp[14].map[2][1].rgb = temp;
	sharp[14].map[3][1].rgb = temp;
	sharp[14].map[0][0].rgb = temp;

	 x = rand() / 255;
	 y = rand() / 255;
	 z = rand() / 255;
	temp = RGB(x, y, z);
	sharp[15].map[0][0].rgb = temp;
	sharp[15].map[0][1].rgb = temp;
	sharp[15].map[1][1].rgb = temp;
	sharp[15].map[1][2].rgb = temp;
	sharp[15].map[2][2].rgb = temp;
	sharp[15].map[2][3].rgb = temp;
}

void ChangeSmap(const SHARP &sp)
{
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
	{
		smap[i][j].rgb = sp.map[i][j].rgb;
	}
}

void GetSharp()
{
	int rad = rand() % 16;
	ChangeSmap(sharp[rad]);
}

void GiveToContral()
{
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
	{
		contral[i][j].rgb = smap[i][j].rgb;
	}
}

void ShowSharp()
{
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
	{
		if (map[CuPosX + i][CuPosY + j].rgb == RGB(255, 255, 255))
			map[CuPosX + i][CuPosY + j].rgb = contral[i][j].rgb;
	}
}

void GetNextSharp()
{
	GetSharp();
}

bool GetFail()
{
	for (int i = 0; i < 4;++i)
	for (int j = 0; j < 4; ++j)
	{
		if (contral[i][j].rgb != RGB(255, 255, 255) && map[i][j+6].rgb != RGB(255, 255, 255))
			return TRUE;
	}
	return FALSE;
}










// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C俄罗斯方块MFCDlg 对话框



C俄罗斯方块MFCDlg::C俄罗斯方块MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C俄罗斯方块MFCDlg::IDD, pParent)
	, Speed(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C俄罗斯方块MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Speed);
}

BEGIN_MESSAGE_MAP(C俄罗斯方块MFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &C俄罗斯方块MFCDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &C俄罗斯方块MFCDlg::OnBnClickedCancel)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT1, &C俄罗斯方块MFCDlg::OnEnChangeEdit1)

	ON_MESSAGE(WM_MYMSG, OnMyMsgHandler)
END_MESSAGE_MAP()


// C俄罗斯方块MFCDlg 消息处理程序

BOOL C俄罗斯方块MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	
	Speed = 500;
	UpdateData(FALSE);

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C俄罗斯方块MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C俄罗斯方块MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
		CDC* pDC = GetDC();
		pDC->SelectObject(&pen);

		//pDC->MoveTo(0, 0);
		//pDC->LineTo(300, 300);

		CBrush brushMap(RGB(255, 255, 255));
		//brushMap.CreateSolidBrush(RGB(255, 255, 0));
		pDC->SelectObject(&brushMap);
		pDC->Rectangle(CRect(0, 0, 800, 800));//初始化背景

		PaintMap();
		PaintSMap();
	
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C俄罗斯方块MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




bool Check(int x1,int y1)
{
	for (int j = 0; j < 4; ++j)
	for (int i = 0; i < 4; ++i)
	{
		if (contral[3 - i][3 - j].rgb != RGB(255, 255, 255))
		{
			if (x1 + 3 - i + 1 >= 16)
				return TRUE;
			if (map[x1 + 3 - i + 1][y1 + 3 - j].rgb != RGB(255, 255, 255))
				return TRUE;
			else
				break;
		}
	}
	return FALSE;
}

void Down1(int x1,int y1)
{
	for (int j = 0; j < 4; ++j)
	{
		int flag = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (contral[i][j].rgb != RGB(255, 255, 255)&&flag==0)
			{
				flag = 1;
				map[x1 + i][y1 + j].rgb = RGB(255,255,255);
				map[x1 + i + 1][y1 + j].rgb = contral[i][j].rgb;
			}
			if (contral[i][j].rgb != RGB(255, 255, 255))
			{
				map[x1 + i + 1][y1 + j].rgb = contral[i][j].rgb;
			}
		}
	}
}  

void ChangeSharp()
{
	SMAP temp[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			temp[i][j] = contral[i][j];
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			contral[j][3 - i] = temp[i][j];
		}
	}
}

LRESULT C俄罗斯方块MFCDlg::OnMyMsgHandler(WPARAM, LPARAM)
{
	return 0;
}

void C俄罗斯方块MFCDlg::Clear()
{
	for (int i = 0; i < ROW; ++i)
	{
		int j;
		for (j = 0; j < COLUMN; ++j)
		{
			if (map[i][j].rgb == RGB(255, 255, 255))
				break;
		}
		if (j == COLUMN)
		{
			for (int k = i; k >= 0; --k)
			{
				for (j = 0; j < COLUMN; ++j)
				{
					if (k == 0)
					{
						map[k][j].rgb = RGB(255, 255, 255);
					}
					else
					{
						map[k][j].rgb = map[k - 1][j].rgb;
					}
				}
			}
			CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
			CDC* pDC = GetDC();
			pDC->SelectObject(&pen);
			pDC->SetTextColor(RGB(255, 0, 0));

			CString code;
			n_code++;
			code.Format(L"%d", n_code);
			pDC->TextOut(440, 200, code);
		}
	}
}

BOOL C俄罗斯方块MFCDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_UP:
			for (int i = 0; i < 4; ++i)
			for (int j = 0; j<4; ++j)
			{
				if (contral[i][j].rgb != RGB(255, 255, 255))
				{
					map[CuPosX + i][CuPosY + j].rgb = RGB(255, 255, 255);
				}
			}
			ChangeSharp();
			ShowSharp();
			PaintMap();
			break;
		case VK_LEFT:
			//if (CuPosY > 0)
			{
				for (int i = 0; i < 4; ++i)
				{
					int flag = 0;
					for (int j = 0; j < 4; ++j)
					{
						if (contral[i][3-j].rgb != RGB(255, 255, 255) && flag == 0)
						{
							flag = 1;
							map[CuPosX + i][CuPosY +3- j].rgb = RGB(255, 255, 255);
							map[CuPosX + i][CuPosY +3- j - 1].rgb = contral[i][3-j].rgb;
						}
						if (contral[i][3-j].rgb != RGB(255, 255, 255))
						{
							map[CuPosX + i][CuPosY +3- j - 1].rgb = contral[i][3-j].rgb;
						}
					}
				}
				PaintMap();
			}
			--CuPosY;
			break;
		case VK_RIGHT:
			//if (CuPosY < 15)
			{
				for (int i = 0; i < 4; ++i)
				{
					int flag = 0;
					for (int j = 0; j < 4; ++j)
					{
						if (contral[i][j].rgb != RGB(255, 255, 255) && flag == 0)
						{
							flag = 1;
							map[CuPosX + i][CuPosY + j].rgb = RGB(255, 255, 255);
							map[CuPosX + i][CuPosY + j+1].rgb = contral[i][j].rgb;
						}
						if (contral[i][j].rgb != RGB(255, 255, 255))
						{
							map[CuPosX + i][CuPosY + j+1].rgb = contral[i][j].rgb;
						}
					}
				}
				PaintMap();
			}
			++CuPosY;
			break;
		case VK_DOWN:
			if (Check(CuPosX, CuPosY))
			{
				Clear();
				PaintMap();
				break;
			}
			Down1(CuPosX, CuPosY);
			++CuPosX;
			PaintMap();
			break;
		}
	}
	if (pMsg->message == WM_MYMSG)
	{
		if (Check(CuPosX, CuPosY))
		{
			Clear();
			PaintMap();
			CuPosX = 0;
			CuPosY = 6;
			GiveToContral();
			GetSharp();
			if (GetFail())
			{
				MessageBox(L"GAME OVER");
				Init_sharp();
				
				CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
				CDC* pDC = GetDC();
				pDC->SelectObject(&pen);
				pDC->SetTextColor(RGB(255, 0, 0));

				CString code;
				code.Format(L"%d", n_code);
				pDC->TextOut(440, 200, code);

				KillTimer(1);
			}
			ShowSharp();
			PaintMap();
			GetNextSharp();
			PaintSMap();
		}
		Down1(CuPosX, CuPosY);
		++CuPosX;
		PaintMap();
		
	}
	//return CDialog::PreTranslateMessage(pMsg);
	return FALSE;//截获按键信息
}

void PaintAndDown(C俄罗斯方块MFCDlg *pthis)
{
	while (TRUE)
	{
		GetSharp();
		ShowSharp();
		pthis->PaintMap();
		GetNextSharp();
		pthis->PaintSMap();
		CuPosX = 0;
		CuPosY = 6;
		for (int i = 4; i <= ROW + 1; ++i)
		{
			Sleep(SPEED);
			if (Check(CuPosX, CuPosY))
				break;
			Down1(CuPosX, CuPosY);
			++CuPosX;
			pthis->PaintMap();
		}
		GiveToContral();
		if (GetFail())
		{
			break;
		}
	}

}

void C俄罗斯方块MFCDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();

	//MessageBox(L"游戏将在3s倒计时后开始");
	//

	//for (int i = 0; i < 4; i++)
	//{
	//	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
	//	CDC* pDC = GetDC();
	//	pDC->SelectObject(&pen);

	//	CFont font;
	//	font.CreatePointFont(1600,L"System",pDC);
	//	pDC->SelectObject(&font);
	//	pDC->SetTextColor(RGB(255, 0, 0));
	//	//pDC->SetBkMode(TRANSPARENT);
	//	CString Cnum;
	//	Cnum.Format(L"%d", 3-i);
	//	pDC->TextOut(260, 100, Cnum);
	//	Sleep(1000);
	//}
	//GetDlgItem(IDD_MFC_DIALOG)->SetFocus();
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			map[i][j].rgb = RGB(255, 255, 255);
		}
	}
	PaintMap();
	//PaintSMap();
	
	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
	CDC* pDC = GetDC();
	pDC->SelectObject(&pen);
	pDC->SetTextColor(RGB(255, 0, 0));

	CString code;
	code.Format(L"%d", n_code);
	pDC->TextOut(440, 200, code);

	Init_sharp();
	GetSharp();
	GiveToContral();
	ShowSharp();
	PaintMap();
	GetNextSharp();
	PaintSMap();
	UpdateData();
	SetTimer(1, Speed, NULL);
	//thread t(PaintAndDown,this);
	//t.join();

	
	//MessageBox(L"告诉你们个好消息:\n国庆没了...没...了");

}



void C俄罗斯方块MFCDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void C俄罗斯方块MFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1)
	{
		PostMessage(WM_MYMSG);//不可用SendMessage
	}
}


void C俄罗斯方块MFCDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
