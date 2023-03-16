
// core_rdp_clientDlg.cpp : ʵ���ļ�
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


// Ccore_rdp_clientDlg �Ի���

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

// Ccore_rdp_clientDlg ��Ϣ�������

BOOL Ccore_rdp_clientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	initialize_parameter();

	// �����ؼ�
	CRect r;
	m_is_create_mstscax = m_mstscax.Create(NULL, WS_VISIBLE | WS_EX_TOPMOST, r, this, IDC_MSTSCAX1);
	if (m_is_create_mstscax) connect();

	SetWindowPos(&CWnd::wndNoTopMost, 2000, 2000, 0, 0, SWP_HIDEWINDOW);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ccore_rdp_clientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
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

	// TODO: �ڴ˴������Ϣ����������
	if (m_is_create_mstscax) GetDlgItem(IDC_MSTSCAX1)->MoveWindow(0, 0, cx, cy, 1);
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ccore_rdp_clientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL Ccore_rdp_clientDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (pCopyDataStruct && pCopyDataStruct->lpData)
	{
		AfxMessageBox((const wchar_t*)pCopyDataStruct->lpData);
	}

	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
}

void Ccore_rdp_clientDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnLButtonDblClk(nFlags, point);
}

// ���ͻ��˿ؼ���ʼ���ӵ�����������Ӧ��IMsTscAx::Connect�ĵ���ʱ����
void Ccore_rdp_clientDlg::OnConnecting()
{
	u_log::info(__FUNCTION__);
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// �ͻ��˿ؼ�����RD�Ự�����������������ӵĹ����е���
void Ccore_rdp_clientDlg::OnConnected()
{
	u_log::info(__FUNCTION__);
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// ���ͻ��˿ؼ��ɹ���¼��RD�Ự����������ʱ���ã�Ȼ����ʾWindows��¼�Ի���
void Ccore_rdp_clientDlg::OnLoginComplete()
{
	u_log::info(__FUNCTION__);
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// ���ͻ��˿ؼ�����RD�Ự�����������Ͽ�����ʱ����
void Ccore_rdp_clientDlg::OnDisconnected(long discReason)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(discReason));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// ���ͻ��˽���ȫ��ģʽʱ���á� ���統�û�����ȫ��ģʽ��ݼ���� (Ctrl+Alt+BREAK) ʱ�������ô��¼�
void Ccore_rdp_clientDlg::OnEnterFullScreenMode()
{
	u_log::info(__FUNCTION__);
}

// �ͻ����˳�ȫ��ģʽʱ���á� ���統�û�����ȫ��ģʽ��ݼ���� (Ctrl+Alt+BREAK) ʱ�������ô��¼�
void Ccore_rdp_clientDlg::OnLeaveFullScreenMode()
{
	u_log::info(__FUNCTION__);
}

// �ͻ����ڿɱ�д�ű�������ͨ���Ͻ�������ʱ����
void Ccore_rdp_clientDlg::OnChannelReceivedData(BSTR chanName, BSTR data)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +to_string(chanName) + std::string{ " " } +to_string(data));
}

// ���ͻ��������л���ȫ��ģʽ��IMsTscAdvancedSettings::put_ContainerHandledFullScreen����ʱ����
void Ccore_rdp_clientDlg::OnRequestGoFullScreen()
{
	u_log::info(__FUNCTION__);
}

// ���ͻ��������˳�ȫ��ģʽ��IMsTscAdvancedSettings::put_ContainerHandledFullScreen����������Ϊ����ֵʱ����
void Ccore_rdp_clientDlg::OnRequestLeaveFullScreen()
{
	u_log::info(__FUNCTION__);
}

// ���ͻ��˿ؼ�������������ʱ����
void Ccore_rdp_clientDlg::OnFatalError(long errorCode)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(errorCode));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// 	���ͻ��˿ؼ�������������������ʱ����
void Ccore_rdp_clientDlg::OnWarning(long warningCode)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(warningCode));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// ������ָʾԶ�������ϵĿͻ��˿ؼ��Ĵ�С�Ѹ�������Ӧ�ͻ��˿��Ʋ���
void Ccore_rdp_clientDlg::OnRemoteDesktopSizeChange(long width, long height)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(width) + std::string{ " " } +std::to_string(height));
}

// ���û���IMsRdpClientAdvancedSettings::put_MinutesToIdleTimeout�������õ�ʱ���ڼ�û�������������ʱ����
void Ccore_rdp_clientDlg::OnIdleTimeoutNotification()
{
	u_log::info(__FUNCTION__);
}

// ���û���ȫ��ģʽ�°����������ϵ���С����ťʱ���á� �������¼�������Ӧ�ó���������С��������
void Ccore_rdp_clientDlg::OnRequestContainerMinimize()
{
	u_log::info(__FUNCTION__);
}

// �ͻ��˵���IMsRdpClient::RequestClose����ʱ����
void Ccore_rdp_clientDlg::OnConfirmClose(VARIANT_BOOL * pfAllowClose)
{
	u_log::info(__FUNCTION__);
}

// ���ͻ��˴ӷ�����������Կʱ�������������е��á� ����NotifyTSPublicKey����VARIANT_TRUEʱ�Ż���ô��¼�
void Ccore_rdp_clientDlg::OnReceivedTSPublicKey(BSTR publicKey, VARIANT_BOOL * pfContinueLogon)
{
	u_log::info(__FUNCTION__);
}

// ���ͻ������Զ���RD�Ự�����������������ӻỰ�Ĺ����е���
void Ccore_rdp_clientDlg::OnAutoReconnecting(long disconnectReason, long attemptCount, AutoReconnectContinueState * pArcContinueStatus)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(disconnectReason) + std::string{ " " } +std::to_string(attemptCount));
}

// ActiveX�ؼ�֮ǰ���õ������֤�Ի���(����֤�����Ի���)
void Ccore_rdp_clientDlg::OnAuthenticationWarningDisplayed()
{
	u_log::info(__FUNCTION__);
}

// ActiveX�ؼ�����õ������֤�Ի���(����֤�����Ի���)
void Ccore_rdp_clientDlg::OnAuthenticationWarningDismissed()
{
	u_log::info(__FUNCTION__);
}

// ��RemoteApp���򽫽�����ص��ͻ��˿ؼ�ʱ����
void Ccore_rdp_clientDlg::OnRemoteProgramResult(BSTR bstrRemoteProgram, RemoteProgramResult lError, VARIANT_BOOL vbIsExecutable)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +to_string(bstrRemoteProgram) + std::string{ " " } +std::to_string(lError));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// ��ʾRemoteApp����ʱ����
void Ccore_rdp_clientDlg::OnRemoteProgramDisplayed(VARIANT_BOOL vbDisplayed, unsigned long uDisplayInformation)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(vbDisplayed) + std::string{ " " } +std::to_string(uDisplayInformation));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// ��ʾRemoteApp����ʱ����
void Ccore_rdp_clientDlg::OnRemoteWindowDisplayed(VARIANT_BOOL vbDisplayed, wireHWND hwnd, RemoteWindowDisplayedAttribute windowAttribute)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(vbDisplayed) + std::string{ " " } +std::to_string((unsigned long)hwnd));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// ������¼�����������¼�¼�ʱ����
void Ccore_rdp_clientDlg::OnLogonError(long lError)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(lError));
	send_message(to_wstring(get_current_time()) + __FUNCTIONW__);
}

// �����ͷŽ�������ʱ���á� ���統�û����� Ctrl+Alt+������� Ctrl+Alt+���Ҽ����ʱ�������ô��¼�
void Ccore_rdp_clientDlg::OnFocusReleased(int iDirection)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(iDirection));
}

// �ؼ���ȡ�û���ʱ����
void Ccore_rdp_clientDlg::OnUserNameAcquired(BSTR bstrUserName)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +to_string(bstrUserName));
}

// �������ģʽ��������ʱ����
void Ccore_rdp_clientDlg::OnMouseInputModeChanged(VARIANT_BOOL fMouseModeRelative)
{
	u_log::info(__FUNCTION__);
}

// �ͻ����յ�ϵͳ��Ϣʱ����
void Ccore_rdp_clientDlg::OnServiceMessageReceived(BSTR serviceMessage)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +to_string(serviceMessage));
}

// ���û��ϵ���������ʱ����
void Ccore_rdp_clientDlg::OnConnectionBarPullDown()
{
	u_log::info(__FUNCTION__);
}

// ������״̬��������ʱ����
void Ccore_rdp_clientDlg::OnNetworkStatusChanged(unsigned long qualityLevel, long bandwidth, long rtt)
{
	u_log::info(__FUNCTION__ + std::string{ " " } +std::to_string(qualityLevel) + std::string{ " " } +std::to_string(bandwidth) + std::string{ " " } +std::to_string(rtt));
}

// ���������е��豸��ť������ʱ����
void Ccore_rdp_clientDlg::OnDevicesButtonPressed()
{
	u_log::info(__FUNCTION__);
}

// ���ͻ��˿ؼ��Զ��������ӵ�Զ�̻Ựʱ����
void Ccore_rdp_clientDlg::OnAutoReconnected()
{
	u_log::info(__FUNCTION__);
}

// ���ͻ������Զ���RD�Ự�����������������ӻỰ�Ĺ����е���
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
		rdp_client_non_script->put_RedirectDynamicDevices(VARIANT_TRUE); // �ض���Ự��ö�ٵĶ�̬���ӵ�PnP������
		rdp_client_non_script->put_RedirectDynamicDrives(VARIANT_TRUE); // �ض���Ự��ö�ٵĶ�̬���ӵ�PnP������
		rdp_client_non_script->put_WarnAboutClipboardRedirection(VARIANT_FALSE); // Ӧ��ʾ��ȫ����Ի����Ծ����û��йؼ������ض������Ϣ
		rdp_client_non_script->put_UIParentWindowHandle((wireHWND)GetSafeHwnd()); // �ؼ������ڵĴ��ھ��
		rdp_client_non_script->put_AllowPromptingForCredentials(VARIANT_TRUE); // ������ʾ�û�����ƾ��
		rdp_client_non_script->put_DisableRemoteAppCapsCheck(VARIANT_FALSE); // ���������Ƿ��� RemoteApp ����
		rdp_client_non_script->put_AllowCredentialSaving(VARIANT_TRUE); // ��ʾ���ڱ���ƾ�ݵĸ�ѡ��
		rdp_client_non_script->put_LaunchedViaClientShellInterface(VARIANT_TRUE); // ʹ��Զ������ Web ���� (RD Web Access) �ӿ������ͻ��˿ؼ�
		rdp_client_non_script->put_MarkRdpSettingsSecure(VARIANT_TRUE); // ���Ϊ��ȫ
		rdp_client_non_script->put_PromptForCredsOnClient(VARIANT_TRUE); // ��ʾ��ʾ����ƾ�ݵĶԻ���
		rdp_client_non_script->put_TrustedZoneSite(VARIANT_TRUE); // �û��������ӵ���վλ���û��ͻ��˼������������վ���б���
		rdp_client_non_script->put_WarnAboutPrinterRedirection(VARIANT_TRUE); // �����ض���Ի����������Ự֮ǰ��ʾ�йش�ӡ���ض������Ϣ
		rdp_client_non_script->put_ConnectionBarText(L"Connecting"); // �������������ı�
		rdp_client_non_script->put_EnableCredSspSupport(VARIANT_TRUE); // Ϊ������������ƾ�ݰ�ȫ�����ṩ���� (CredSSP)
		rdp_client_non_script->put_PromptForCredentials(VARIANT_FALSE); // Ϊ���Ӳ�����ƾ�ݶԻ������ʾ
		rdp_client_non_script->put_ShowRedirectionWarningDialog(VARIANT_FALSE); // ����ʾ�ض��򾯸�Ի���
		rdp_client_non_script->put_WarnAboutSendingCredentials(VARIANT_TRUE); // �����й��������Ự֮ǰ��Զ�̷���������ƾ�ݵľ���
		rdp_client_non_script->Release();
	}

	IMsRdpClientSecuredSettings2* rdp_client_secured_settings = (IMsRdpClientSecuredSettings2*)m_mstscax.get_SecuredSettings2();
	if (rdp_client_secured_settings)
	{
		rdp_client_secured_settings->put_AudioRedirectionMode(0); // �������ض��򵽿ͻ���
		rdp_client_secured_settings->put_KeyboardHookMode(0); // ��Զ�̷�������Ӧ�ü����
		rdp_client_secured_settings->Release();
	}

	ITSRemoteProgram2* remote_program = (ITSRemoteProgram2*)m_mstscax.get_RemoteProgram2();
	if (remote_program)
	{
		remote_program->put_RemoteProgramMode(VARIANT_TRUE);
		remote_program->Release();
	}

	CMsRdpClientAdvancedSettings8 rdp_client_advanced_settings(m_mstscax.get_AdvancedSettings8());
	rdp_client_advanced_settings.put_BitmapPeristence(1); // ����λͼ����
	rdp_client_advanced_settings.put_Compress(1); // ����ѹ��
	rdp_client_advanced_settings.put_DisableRdpdr(FALSE); // ���ô�ӡ���ͼ������ض���
	rdp_client_advanced_settings.put_AcceleratorPassthrough(1); // �����̼���������
	rdp_client_advanced_settings.put_CachePersistenceActive(1); // ʹ�ó־�λͼ����
	rdp_client_advanced_settings.put_ClearTextPassword(m_pass_word.c_str()); // ��½����
	rdp_client_advanced_settings.put_DisableCtrlAltDel(0); // ����ʾ Winlogon �еĳ�ʼ˵����Ļ
	rdp_client_advanced_settings.put_DisplayConnectionBar(TRUE); // ʹ��������
	rdp_client_advanced_settings.put_DoubleClickDetect(1); // ʶ���������˫��
	rdp_client_advanced_settings.put_EnableWindowsKey(1); // ��Զ�̻Ự��ʹ�� Windows ��
	rdp_client_advanced_settings.put_GrabFocusOnConnect(TRUE); // �ͻ��˿ؼ�������ʱӦ���н���
	rdp_client_advanced_settings.put_PerformanceFlags(0x00000001); // ���������������������
	rdp_client_advanced_settings.put_RDPPort(_wtoi(m_server_port.c_str())); // ���Ӷ˿�
	rdp_client_advanced_settings.put_RedirectDrives(TRUE); // ��������������ض���
	rdp_client_advanced_settings.put_RedirectPorts(TRUE); // �����ض��򱾵ض˿�
	rdp_client_advanced_settings.put_RedirectPrinters(TRUE); // �����ӡ���ض���
	rdp_client_advanced_settings.put_RedirectSmartCards(TRUE); // �������ܿ��ض���
	rdp_client_advanced_settings.put_SmartSizing(FALSE); // ������ʾ���ʺϿؼ��Ĺ�����
	rdp_client_advanced_settings.put_EnableAutoReconnect(TRUE); // ����ͻ��˿ؼ�������Ͽ�ʱ�Զ��������ӵ��Ự
	rdp_client_advanced_settings.put_ConnectionBarShowMinimizeButton(TRUE); // ������������ʾ��С����ť
	rdp_client_advanced_settings.put_ConnectionBarShowRestoreButton(TRUE); // ������������ʾ�ָ���ť
	rdp_client_advanced_settings.put_RedirectClipboard(TRUE); // �������ض���
	rdp_client_advanced_settings.put_RedirectDevices(TRUE); // �豸�ض���
	rdp_client_advanced_settings.put_EnableCredSspSupport(TRUE); // Ϊ������������ƾ�ݰ�ȫ�����ṩ����
	rdp_client_advanced_settings.put_RelativeMouseMode(TRUE); // ���ʹ�����ģʽ
	rdp_client_advanced_settings.put_allowBackgroundInput(1); // ���ú�̨����󣬿ͻ��˿����ڿͻ���û�н���ʱ��������
	rdp_client_advanced_settings.put_MinutesToIdleTimeout(240); // û���û����������±������ӵ����ʱ�䳤��4Сʱ
	rdp_client_advanced_settings.put_keepAliveInterval(10000); // �ͻ�������������ͱ��ֻ��Ϣ��ʱ����10��
	rdp_client_advanced_settings.put_MaximizeShell(1); // ���ʹ�� StartProgram ���������ĳ���
	rdp_client_advanced_settings.put_overallConnectionTimeout(600); // �ȴ�������ɵ���ʱ�䳤��
	rdp_client_advanced_settings.put_shutdownTimeout(600); // ��������Ӧ�Ͽ����������ʱ�䳤��
	rdp_client_advanced_settings.put_singleConnectionTimeout(600); // �ͻ��˿ؼ��ȴ��� IP ��ַ�����ӵ����ʱ�䳤��

	m_mstscax.put_DesktopHeight(GetSystemMetrics(SM_CYSCREEN)); // Զ�������ϵĸ߶�
	m_mstscax.put_DesktopWidth(GetSystemMetrics(SM_CXSCREEN)); // Զ�������ϵĿ��
	m_mstscax.put_Server(m_ip_address.c_str()); // ������������
	m_mstscax.put_UserName(m_user_name.c_str()); // �û�����¼ƾ��
	m_mstscax.put_ColorDepth(32); // ��ɫ���
	m_mstscax.put_FullScreen(TRUE); // ȫ��ģʽ
	m_mstscax.put_ConnectingText(L"Connecting"); // ����ʱ�ڿؼ��о�����ʾ���ı�
	m_mstscax.put_DisconnectedText(L"DisConnecting"); // ������ֹǰ�ڿؼ��о�����ʾ���ı�
	m_mstscax.put_FullScreenTitle(L"RdpClient"); // ȫ��ģʽʱ��ʾ�Ĵ��ڱ���
	m_mstscax.put_StartConnected(TRUE); // ����ʱ��������Զ������Ự���� (RD �Ự����) ����������
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
