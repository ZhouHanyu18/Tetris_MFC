
// ����˹����-MFCDlg.h : ͷ�ļ�
//

#pragma once


// C����˹����MFCDlg �Ի���
class C����˹����MFCDlg : public CDialogEx
{
// ����
public:
	C����˹����MFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	// �ٶ�Ϊ500���
	int Speed;
};
