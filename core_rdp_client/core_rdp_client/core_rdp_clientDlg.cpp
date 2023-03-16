
// core_rdp_clientDlg.cpp : 实现文件
//
#pragma warning(disable : 4311 4302 4267)
#include "stdafx.h"
#include "core_rdp_client.h"
#include "core_rdp_clientDlg.h"
#include "afxdialogex.h"
#include "log.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ccore_rdp_clientDlg 对话框

IMPLEMENT_DYNAMIC(Ccore_rdp_clientDlg, CDialogEx)

Ccore_rdp_clientDlg::Ccore_rdp_clientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CORE_RDP_CLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ccore_rdp_clientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	if (m_is_create_mstscax) DDX_Control(pDX, IDC_MSTSCAX1, m_mstscax);
}

BEGIN_MESSAGE_MAP(Ccore_rdp_clientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_COPYDATA()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(Ccore_rdp_clientDlg, CWnd)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 1, Ccore_rdp_clientDlg::OnConnecting, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 2, Ccore_rdp_clientDlg::OnConnected, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 3, Ccore_rdp_clientDlg::OnLoginComplete, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 4, Ccore_rdp_clientDlg::OnDisconnected, VTS_I4)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 5, Ccore_rdp_clientDlg::OnEnterFullScreenMode, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 6, Ccore_rdp_clientDlg::OnLeaveFullScreenMode, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 7, Ccore_rdp_clientDlg::OnChannelReceivedData, VTS_BSTR VTS_BSTR)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 8, Ccore_rdp_clientDlg::OnRequestGoFullScreen, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 9, Ccore_rdp_clientDlg::OnRequestLeaveFullScreen, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 10, Ccore_rdp_clientDlg::OnFatalError, VTS_I4)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 11, Ccore_rdp_clientDlg::OnWarning, VTS_I4)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 12, Ccore_rdp_clientDlg::OnRemoteDesktopSizeChange, VTS_I4 VTS_I4)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 13, Ccore_rdp_clientDlg::OnIdleTimeoutNotification, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 14, Ccore_rdp_clientDlg::OnRequestContainerMinimize, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 15, Ccore_rdp_clientDlg::OnConfirmClose, VTS_PBOOL)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 16, Ccore_rdp_clientDlg::OnReceivedTSPublicKey, VTS_BSTR VTS_PBOOL)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 17, Ccore_rdp_clientDlg::OnAutoReconnecting, VTS_I4 VTS_I4 VTS_UNKNOWN)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 18, Ccore_rdp_clientDlg::OnAuthenticationWarningDisplayed, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 19, Ccore_rdp_clientDlg::OnAuthenticationWarningDismissed, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 20, Ccore_rdp_clientDlg::OnRemoteProgramResult, VTS_BSTR VTS_I4 VTS_BOOL)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 21, Ccore_rdp_clientDlg::OnRemoteProgramDisplayed, VTS_BOOL VTS_I4)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 22, Ccore_rdp_clientDlg::OnRemoteWindowDisplayed, VTS_BOOL VTS_UNKNOWN VTS_I4)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 23, Ccore_rdp_clientDlg::OnLogonError, VTS_I4)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 24, Ccore_rdp_clientDlg::OnFocusReleased, VTS_I4)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 25, Ccore_rdp_clientDlg::OnUserNameAcquired, VTS_BSTR)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 26, Ccore_rdp_clientDlg::OnMouseInputModeChanged, VTS_BOOL)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 27, Ccore_rdp_clientDlg::OnServiceMessageReceived, VTS_BSTR)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 28, Ccore_rdp_clientDlg::OnConnectionBarPullDown, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 29, Ccore_rdp_clientDlg::OnNetworkStatusChanged, VTS_I4 VTS_I4 VTS_I4)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 30, Ccore_rdp_clientDlg::OnDevicesButtonPressed, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 31, Ccore_rdp_clientDlg::OnAutoReconnected, VTS_NONE)
	ON_EVENT(Ccore_rdp_clientDlg, IDC_MSTSCAX1, 32, Ccore_rdp_clientDlg::OnAutoReconnecting2, VTS_I4 VTS_BOOL VTS_I4 VTS_I4)
END_EVENTSINK_MAP()

// Ccore_rdp_clientDlg 消息处理程序

BOOL Ccore_rdp_clientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	initialize_parameter();

	// 创建控件
	CRect r;
	m_is_create_mstscax = m_mstscax.Create(NULL, WS_VISIBLE | WS_EX_TOPMOST, r, this, IDC_MSTSCAX1);
	if (m_is_create_mstscax) connect();

	SetWindowPos(&CWnd::wndNoTopMost, 2000, 2000, 0, 0, SWP_HIDEWINDOW);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ccore_rdp_clientDlg::OnPaint()
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
	}
}

void Ccore_rdp_clientDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (m_is_create_mstscax) GetDlgItem(IDC_MSTSCAX1)->MoveWindow(0, 0, cx, cy, 1);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ccore_rdp_clientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL Ccore_rdp_clientDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (pCopyDataStruct && pCopyDataStruct->lpData)
	{
		AfxMessageBox((const wchar_t*)pCopyDataStruct->lpData);
	}

	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
}

void Ccore_rdp_clientDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDblClk(nFlags, point);
}

// 当客户端控件开始连接到服务器以响应对IMsTscAx::Connect的调用时调用
void Ccore_rdp_clientDlg::OnConnecting()
{
	u_log::info(__FUNCTION__);
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 客户端控件在与RD会话主机服务器建立连接的过程中调用
void Ccore_rdp_clientDlg::OnConnected()
{
	u_log::info(__FUNCTION__);
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 当客户端控件成功登录到RD会话主机服务器时调用，然后显示Windows登录对话框
void Ccore_rdp_clientDlg::OnLoginComplete()
{
	u_log::info(__FUNCTION__);
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 当客户端控件已与RD会话主机服务器断开连接时调用
void Ccore_rdp_clientDlg::OnDisconnected(long discReason)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(discReason));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 当客户端进入全屏模式时调用。 例如当用户按下全屏模式快捷键组合 (Ctrl+Alt+BREAK) 时，将调用此事件
void Ccore_rdp_clientDlg::OnEnterFullScreenMode()
{
	u_log::info(__FUNCTION__);
}

// 客户端退出全屏模式时调用。 例如当用户按下全屏模式快捷键组合 (Ctrl+Alt+BREAK) 时，将调用此事件
void Ccore_rdp_clientDlg::OnLeaveFullScreenMode()
{
	u_log::info(__FUNCTION__);
}

// 客户端在可编写脚本的虚拟通道上接收数据时调用
void Ccore_rdp_clientDlg::OnChannelReceivedData(BSTR chanName, BSTR data)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +to_string(chanName) + std::string{ " " } +to_string(data));
}

// 当客户端请求切换到全屏模式和IMsTscAdvancedSettings::put_ContainerHandledFullScreen方法时调用
void Ccore_rdp_clientDlg::OnRequestGoFullScreen()
{
	u_log::info(__FUNCTION__);
}

// 当客户端请求退出全屏模式且IMsTscAdvancedSettings::put_ContainerHandledFullScreen属性已设置为非零值时调用
void Ccore_rdp_clientDlg::OnRequestLeaveFullScreen()
{
	u_log::info(__FUNCTION__);
}

// 当客户端控件遇到致命错误时调用
void Ccore_rdp_clientDlg::OnFatalError(long errorCode)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(errorCode));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 	当客户端控件遇到非致命错误条件时调用
void Ccore_rdp_clientDlg::OnWarning(long warningCode)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(warningCode));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 调用以指示远程桌面上的客户端控件的大小已更改以响应客户端控制操作
void Ccore_rdp_clientDlg::OnRemoteDesktopSizeChange(long width, long height)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(width) + std::string{ " " } +std::to_string(height));
}

// 当用户在IMsRdpClientAdvancedSettings::put_MinutesToIdleTimeout方法设置的时间期间没有鼠标或键盘输入时调用
void Ccore_rdp_clientDlg::OnIdleTimeoutNotification()
{
	u_log::info(__FUNCTION__);
}

// 当用户在全屏模式下按下连接栏上的最小化按钮时调用。 触发此事件是容器应用程序将自身最小化的请求。
void Ccore_rdp_clientDlg::OnRequestContainerMinimize()
{
	u_log::info(__FUNCTION__);
}

// 客户端调用IMsRdpClient::RequestClose方法时调用
void Ccore_rdp_clientDlg::OnConfirmClose(VARIANT_BOOL * pfAllowClose)
{
	u_log::info(__FUNCTION__);
}

// 当客户端从服务器检索公钥时，在连接序列中调用。 仅当NotifyTSPublicKey属性VARIANT_TRUE时才会调用此事件
void Ccore_rdp_clientDlg::OnReceivedTSPublicKey(BSTR publicKey, VARIANT_BOOL * pfContinueLogon)
{
	u_log::info(__FUNCTION__);
}

// 当客户端在自动与RD会话主机服务器重新连接会话的过程中调用
void Ccore_rdp_clientDlg::OnAutoReconnecting(long disconnectReason, long attemptCount, AutoReconnectContinueState * pArcContinueStatus)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(disconnectReason) + std::string{ " " } +std::to_string(attemptCount));
}

// ActiveX控件之前调用的身份验证对话框(例如证书错误对话框)
void Ccore_rdp_clientDlg::OnAuthenticationWarningDisplayed()
{
	u_log::info(__FUNCTION__);
}

// ActiveX控件后调用的身份验证对话框(例如证书错误对话框)
void Ccore_rdp_clientDlg::OnAuthenticationWarningDismissed()
{
	u_log::info(__FUNCTION__);
}

// 当RemoteApp程序将结果返回到客户端控件时调用
void Ccore_rdp_clientDlg::OnRemoteProgramResult(BSTR bstrRemoteProgram, RemoteProgramResult lError, VARIANT_BOOL vbIsExecutable)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +to_string(bstrRemoteProgram) + std::string{ " " } +std::to_string(lError));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 显示RemoteApp程序时调用
void Ccore_rdp_clientDlg::OnRemoteProgramDisplayed(VARIANT_BOOL vbDisplayed, unsigned long uDisplayInformation)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(vbDisplayed) + std::string{ " " } +std::to_string(uDisplayInformation));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 显示RemoteApp窗口时调用
void Ccore_rdp_clientDlg::OnRemoteWindowDisplayed(VARIANT_BOOL vbDisplayed, wireHWND hwnd, RemoteWindowDisplayedAttribute windowAttribute)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(vbDisplayed) + std::string{ " " } +std::to_string((unsigned long)hwnd));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 发生登录错误或其他登录事件时调用
void Ccore_rdp_clientDlg::OnLogonError(long lError)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(lError));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 按下释放焦点键组合时调用。 例如当用户按下 Ctrl+Alt+向左键或 Ctrl+Alt+向右键组合时，将调用此事件
void Ccore_rdp_clientDlg::OnFocusReleased(int iDirection)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(iDirection));
}

// 控件获取用户名时调用
void Ccore_rdp_clientDlg::OnUserNameAcquired(BSTR bstrUserName)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +to_string(bstrUserName));
}

// 鼠标输入模式发生更改时调用
void Ccore_rdp_clientDlg::OnMouseInputModeChanged(VARIANT_BOOL fMouseModeRelative)
{
	u_log::info(__FUNCTION__);
}

// 客户端收到系统消息时调用
void Ccore_rdp_clientDlg::OnServiceMessageReceived(BSTR serviceMessage)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +to_string(serviceMessage));
}

// 当用户拖到连接栏上时调用
void Ccore_rdp_clientDlg::OnConnectionBarPullDown()
{
	u_log::info(__FUNCTION__);
}

// 当网络状态发生更改时调用
void Ccore_rdp_clientDlg::OnNetworkStatusChanged(unsigned long qualityLevel, long bandwidth, long rtt)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(qualityLevel) + std::string{ " " } +std::to_string(bandwidth) + std::string{ " " } +std::to_string(rtt));
}

// 在连接栏中的设备按钮被按下时调用
void Ccore_rdp_clientDlg::OnDevicesButtonPressed()
{
	u_log::info(__FUNCTION__);
}

// 当客户端控件自动重新连接到远程会话时调用
void Ccore_rdp_clientDlg::OnAutoReconnected()
{
	u_log::info(__FUNCTION__);
}

// 当客户端在自动与RD会话主机服务器重新连接会话的过程中调用
void Ccore_rdp_clientDlg::OnAutoReconnecting2(long disconnectReason, VARIANT_BOOL networkAvailable, long attemptCount, long maxAttemptCount)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(disconnectReason) + std::string{ " " } +std::to_string(attemptCount) + std::string{ " " } +std::to_string(maxAttemptCount));
}

std::wstring Ccore_rdp_clientDlg::to_wstring(std::string str)
{
	std::wstring result;

	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	wchar_t* buffer = new wchar_t[len + 1];
	if (buffer == nullptr) return result;

	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';

	result = buffer;
	delete[] buffer;
	return result;
}

std::string Ccore_rdp_clientDlg::to_string(std::wstring str)
{
	std::string result;

	int len = WideCharToMultiByte(CP_ACP, 0, str.c_str(), str.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	if (buffer == nullptr) return result;

	WideCharToMultiByte(CP_ACP, 0, str.c_str(), str.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';

	result = buffer;
	delete[] buffer;
	return result;
}

void Ccore_rdp_clientDlg::initialize_parameter()
{
	for (int i = 1; i < __argc - 1; i++)
	{
		const std::wstring s = __wargv[i];
		if (s == L"-u") m_user_name = __wargv[i + 1];
		else if (s == L"-p") m_pass_word = __wargv[i + 1];
		else if (s == L"-i") m_ip_address = __wargv[i + 1];
		else if (s == L"-o") m_server_port = __wargv[i + 1];
	}
}

bool Ccore_rdp_clientDlg::connect()
{
	if (m_mstscax.get_Connected()) return true;

	// 4f6996d5-d7b1-412c-b0ff-063718566907
	CLSID IID_IMsRdpClientNonScriptable5 = { 0x4f6996d5, 0xd7b1, 0x412c,{ 0xb0, 0xff, 0x06, 0x37, 0x18, 0x56, 0x69, 0x07 } };
	IMsRdpClientNonScriptable5* rdp_client_non_script = 0;
	IDispatch* dispatch = (IDispatch*)m_mstscax.GetControlUnknown();
	if (SUCCEEDED(dispatch->QueryInterface(IID_IMsRdpClientNonScriptable5, (void**)&rdp_client_non_script)))
	{
		rdp_client_non_script->put_RedirectDynamicDevices(VARIANT_TRUE); // 重定向会话中枚举的动态连接的PnP驱动器
		rdp_client_non_script->put_RedirectDynamicDrives(VARIANT_TRUE); // 重定向会话中枚举的动态连接的PnP驱动器
		rdp_client_non_script->put_WarnAboutClipboardRedirection(VARIANT_FALSE); // 应显示安全警告对话框以警告用户有关剪贴板重定向的信息
		rdp_client_non_script->put_UIParentWindowHandle((wireHWND)GetSafeHwnd()); // 控件父窗口的窗口句柄
		rdp_client_non_script->put_AllowPromptingForCredentials(VARIANT_TRUE); // 可以提示用户输入凭据
		rdp_client_non_script->put_DisableRemoteAppCapsCheck(VARIANT_FALSE); // 检查服务器是否有 RemoteApp 功能
		rdp_client_non_script->put_AllowCredentialSaving(VARIANT_TRUE); // 显示用于保存凭据的复选框
		rdp_client_non_script->put_LaunchedViaClientShellInterface(VARIANT_TRUE); // 使用远程桌面 Web 访问 (RD Web Access) 接口启动客户端控件
		rdp_client_non_script->put_MarkRdpSettingsSecure(VARIANT_TRUE); // 标记为安全
		rdp_client_non_script->put_PromptForCredsOnClient(VARIANT_TRUE); // 显示提示输入凭据的对话框
		rdp_client_non_script->put_TrustedZoneSite(VARIANT_TRUE); // 用户启动连接的网站位于用户客户端计算机的受信任站点列表中
		rdp_client_non_script->put_WarnAboutPrinterRedirection(VARIANT_TRUE); // 控制重定向对话框在启动会话之前显示有关打印机重定向的消息
		rdp_client_non_script->put_ConnectionBarText(L"Connecting"); // 更新连接栏的文本
		rdp_client_non_script->put_EnableCredSspSupport(VARIANT_TRUE); // 为此连接启用了凭据安全服务提供程序 (CredSSP)
		rdp_client_non_script->put_PromptForCredentials(VARIANT_FALSE); // 为连接不启用凭据对话框的提示
		rdp_client_non_script->put_ShowRedirectionWarningDialog(VARIANT_FALSE); // 不显示重定向警告对话框
		rdp_client_non_script->put_WarnAboutSendingCredentials(VARIANT_TRUE); // 包含有关在启动会话之前向远程服务器发送凭据的警告
		rdp_client_non_script->Release();
	}

	IMsRdpClientSecuredSettings2* rdp_client_secured_settings = (IMsRdpClientSecuredSettings2*)m_mstscax.get_SecuredSettings2();
	if (rdp_client_secured_settings)
	{
		rdp_client_secured_settings->put_AudioRedirectionMode(0); // 将声音重定向到客户端
		rdp_client_secured_settings->put_KeyboardHookMode(0); // 在远程服务器上应用键组合
		rdp_client_secured_settings->Release();
	}

	ITSRemoteProgram2* remote_program = (ITSRemoteProgram2*)m_mstscax.get_RemoteProgram2();
	if (remote_program)
	{
		remote_program->put_RemoteProgramMode(VARIANT_TRUE);
		remote_program->Release();
	}

	CMsRdpClientAdvancedSettings8 rdp_client_advanced_settings(m_mstscax.get_AdvancedSettings8());
	rdp_client_advanced_settings.put_BitmapPeristence(1); // 启用位图缓存
	rdp_client_advanced_settings.put_Compress(1); // 启用压缩
	rdp_client_advanced_settings.put_DisableRdpdr(FALSE); // 启用打印机和剪贴板重定向
	rdp_client_advanced_settings.put_AcceleratorPassthrough(1); // 将键盘加速器传递
	rdp_client_advanced_settings.put_CachePersistenceActive(1); // 使用持久位图缓存
	rdp_client_advanced_settings.put_ClearTextPassword(m_pass_word.c_str()); // 登陆密码
	rdp_client_advanced_settings.put_DisableCtrlAltDel(0); // 不显示 Winlogon 中的初始说明屏幕
	rdp_client_advanced_settings.put_DisplayConnectionBar(TRUE); // 使用连接栏
	rdp_client_advanced_settings.put_DoubleClickDetect(1); // 识别服务器的双击
	rdp_client_advanced_settings.put_EnableWindowsKey(1); // 在远程会话中使用 Windows 键
	rdp_client_advanced_settings.put_GrabFocusOnConnect(TRUE); // 客户端控件在连接时应具有焦点
	rdp_client_advanced_settings.put_PerformanceFlags(0x00000001); // 服务器上设置以提高性能
	rdp_client_advanced_settings.put_RDPPort(_wtoi(m_server_port.c_str())); // 连接端口
	rdp_client_advanced_settings.put_RedirectDrives(TRUE); // 允许磁盘驱动器重定向
	rdp_client_advanced_settings.put_RedirectPorts(TRUE); // 允许重定向本地端口
	rdp_client_advanced_settings.put_RedirectPrinters(TRUE); // 允许打印机重定向
	rdp_client_advanced_settings.put_RedirectSmartCards(TRUE); // 允许智能卡重定向
	rdp_client_advanced_settings.put_SmartSizing(FALSE); // 缩放显示以适合控件的工作区
	rdp_client_advanced_settings.put_EnableAutoReconnect(TRUE); // 允许客户端控件在网络断开时自动重新连接到会话
	rdp_client_advanced_settings.put_ConnectionBarShowMinimizeButton(TRUE); // 在连接栏上显示最小化按钮
	rdp_client_advanced_settings.put_ConnectionBarShowRestoreButton(TRUE); // 在连接栏上显示恢复按钮
	rdp_client_advanced_settings.put_RedirectClipboard(TRUE); // 剪贴板重定向
	rdp_client_advanced_settings.put_RedirectDevices(TRUE); // 设备重定向
	rdp_client_advanced_settings.put_EnableCredSspSupport(TRUE); // 为此连接启用了凭据安全服务提供程序
	rdp_client_advanced_settings.put_RelativeMouseMode(TRUE); // 鼠标使用相对模式
	rdp_client_advanced_settings.put_allowBackgroundInput(1); // 启用后台输入后，客户端可以在客户端没有焦点时接受输入
	rdp_client_advanced_settings.put_MinutesToIdleTimeout(240); // 没有用户输入的情况下保持连接的最大时间长度4小时
	rdp_client_advanced_settings.put_keepAliveInterval(10000); // 客户端向服务器发送保持活动消息的时间间隔10秒
	rdp_client_advanced_settings.put_MaximizeShell(1); // 最大化使用 StartProgram 属性启动的程序
	rdp_client_advanced_settings.put_overallConnectionTimeout(600); // 等待连接完成的总时间长度
	rdp_client_advanced_settings.put_shutdownTimeout(600); // 服务器响应断开连接请求的时间长度
	rdp_client_advanced_settings.put_singleConnectionTimeout(600); // 客户端控件等待与 IP 地址的连接的最大时间长度

	m_mstscax.put_DesktopHeight(GetSystemMetrics(SM_CYSCREEN)); // 远程桌面上的高度
	m_mstscax.put_DesktopWidth(GetSystemMetrics(SM_CXSCREEN)); // 远程桌面上的宽度
	m_mstscax.put_Server(m_ip_address.c_str()); // 服务器的名称
	m_mstscax.put_UserName(m_user_name.c_str()); // 用户名登录凭据
	m_mstscax.put_ColorDepth(32); // 颜色深度
	m_mstscax.put_FullScreen(TRUE); // 全屏模式
	m_mstscax.put_ConnectingText(L"Connecting"); // 连接时在控件中居中显示的文本
	m_mstscax.put_DisconnectedText(L"DisConnecting"); // 连接终止前在控件中居中显示的文本
	m_mstscax.put_FullScreenTitle(L"RdpClient"); // 全屏模式时显示的窗口标题
	m_mstscax.put_StartConnected(TRUE); // 启动时立即建立远程桌面会话主机 (RD 会话主机) 服务器连接
	m_mstscax.put_ConnectedStatusText(L"Connecting");

	m_mstscax.Connect();
	return true;
}

bool Ccore_rdp_clientDlg::start_remote_program(std::string exe, std::string argvs)
{
	HRESULT hr = -1;
	ITSRemoteProgram2* remote_program = (ITSRemoteProgram2*)m_mstscax.get_RemoteProgram2();
	if (remote_program)
	{
		hr = remote_program->ServerStartProgram(exe.c_str(), "", "", VARIANT_TRUE, argvs.c_str(), VARIANT_TRUE);
		remote_program->Release();
	}
	return SUCCEEDED(hr);
}

bool Ccore_rdp_clientDlg::send_message(std::wstring buffer, std::wstring window_class)
{
	HWND h = ::FindWindowW(window_class.c_str(),0);
	if (!h) return false;

	COPYDATASTRUCT cds{ 0 };
	cds.lpData = (PVOID)buffer.c_str();
	cds.cbData = buffer.size() * sizeof(wchar_t) + 2;
	::SendMessageW(h, WM_COPYDATA, 0, (LPARAM)&cds);

	return true;
}

std::string Ccore_rdp_clientDlg::get_current_time()
{
	SYSTEMTIME t{ 0 };
	GetLocalTime(&t);

	char s[100]{ 0 };
	sprintf_s(s, 100, "[%d-%d-%d %.2d:%.2d:%.2d] ", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);
	return s;
}

bool Ccore_rdp_clientDlg::send_name_pipe_buffer(std::string name, std::string buffer)
{
	bool ret = false;

	if (WaitNamedPipeA(name.c_str(), NMPWAIT_USE_DEFAULT_WAIT))
	{
		HANDLE h = CreateFileA(name.c_str(), GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (h != INVALID_HANDLE_VALUE)
		{
			DWORD r = 0;
			if (WriteFile(h, buffer.c_str(), (DWORD)buffer.size(), &r, 0)) ret = true;

			CloseHandle(h);
		}
	}

	return ret;
}
