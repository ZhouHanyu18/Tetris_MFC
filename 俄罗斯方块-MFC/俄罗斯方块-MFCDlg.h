
// 俄罗斯方块-MFCDlg.h : 头文件
//

#pragma once


// C俄罗斯方块MFCDlg 对话框
class C俄罗斯方块MFCDlg : public CDialogEx
{
// 构造
public:
	C俄罗斯方块MFCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRecvData(...);
	
	
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	void PaintMap();
	void PaintSMap();
	void Clear();
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
	
	afx_msg LRESULT OnMyMsgHandler(WPARAM, LPARAM);
	//friend CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnEnChangeEdit1();
	// 速度为500最佳
	int Speed;
};
