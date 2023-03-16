
// core_rdp_clientDlg.h : 头文件
//

#pragma once
#include "mstscax1.h"
#include "CMsRdpClientAdvancedSettings8.h"

#include <string>

// Ccore_rdp_clientDlg 对话框
class Ccore_rdp_clientDlg : public CDialogEx
{
	DECLARE_DYNAMIC(Ccore_rdp_clientDlg)

	// 构造
public:
	Ccore_rdp_clientDlg(CWnd* pParent = NULL);	// 标准构造函数

												// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CORE_RDP_CLIENT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


														// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

public:
	DECLARE_EVENTSINK_MAP()
	// IMsTscAxEvents
	void OnConnecting();
	void OnConnected();
	void OnLoginComplete();
	void OnDisconnected(long discReason);
	void OnEnterFullScreenMode();
	void OnLeaveFullScreenMode();
	void OnChannelReceivedData(BSTR chanName, BSTR data);
	void OnRequestGoFullScreen();
	void OnRequestLeaveFullScreen();
	void OnFatalError(long errorCode);
	void OnWarning(long warningCode);
	void OnRemoteDesktopSizeChange(long width, long height);
	void OnIdleTimeoutNotification();
	void OnRequestContainerMinimize();
	void OnConfirmClose(VARIANT_BOOL * pfAllowClose);
	void OnReceivedTSPublicKey(BSTR publicKey, VARIANT_BOOL * pfContinueLogon);
	void OnAutoReconnecting(long disconnectReason, long attemptCount, AutoReconnectContinueState * pArcContinueStatus);
	void OnAuthenticationWarningDisplayed();
	void OnAuthenticationWarningDismissed();
	void OnRemoteProgramResult(BSTR bstrRemoteProgram, RemoteProgramResult lError, VARIANT_BOOL vbIsExecutable);
	void OnRemoteProgramDisplayed(VARIANT_BOOL vbDisplayed, unsigned long uDisplayInformation);
	void OnRemoteWindowDisplayed(VARIANT_BOOL vbDisplayed, wireHWND hwnd, RemoteWindowDisplayedAttribute windowAttribute);
	void OnLogonError(long lError);
	void OnFocusReleased(int iDirection);
	void OnUserNameAcquired(BSTR bstrUserName);
	void OnMouseInputModeChanged(VARIANT_BOOL fMouseModeRelative);
	void OnServiceMessageReceived(BSTR serviceMessage);
	void OnConnectionBarPullDown();
	void OnNetworkStatusChanged(unsigned long qualityLevel, long bandwidth, long rtt);
	void OnDevicesButtonPressed();
	void OnAutoReconnected();
	void OnAutoReconnecting2(long disconnectReason, VARIANT_BOOL networkAvailable, long attemptCount, long maxAttemptCount);

public:
	CMstscax1 m_mstscax;
	BOOL m_is_create_mstscax = FALSE;

	std::wstring m_user_name;
	std::wstring m_pass_word;
	std::wstring m_ip_address;
	std::wstring m_server_port;

	std::wstring to_wstring(std::string str);
	std::string to_string(std::wstring str);

	void initialize_parameter();

	bool connect();

	bool start_remote_program(std::string exe, std::string argvs = "");

	bool send_message(std::wstring buffer, std::wstring window_class = L"isolation_client");

	std::string get_current_time();

	bool send_name_pipe_buffer(std::string name, std::string buffer);
};
