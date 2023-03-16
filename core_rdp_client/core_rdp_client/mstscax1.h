#pragma once

// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装器类

// 注意:  不要修改此文件的内容。  如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////
// CMstscax1 包装器类

class CMstscax1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMstscax1)
public:
	CLSID const& GetClsid()
	{
		// https://docs.microsoft.com/en-us/windows/win32/termserv/using-remote-desktop-web-connection
		// 54D38BF7-B1EF-4479-9674-1BD6EA465258
		static CLSID const clsid
			= { 0x54D38BF7, 0xB1EF, 0x4479,{ 0x96, 0x74, 0x1B, 0xD6, 0xEA, 0x46, 0x52, 0x58 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 特性
public:
enum
{
    autoReconnectContinueAutomatic = 0,
    autoReconnectContinueStop = 1,
    autoReconnectContinueManual = 2
}__MIDL___MIDL_itf_mstsax_0000_0043_0001;
enum
{
    remoteAppResultOk = 0,
    remoteAppResultLocked = 1,
    remoteAppResultProtocolError = 2,
    remoteAppResultNotInWhitelist = 3,
    remoteAppResultNetworkPathDenied = 4,
    remoteAppResultFileNotFound = 5,
    remoteAppResultFailure = 6,
    remoteAppResultHookNotLoaded = 7
}__MIDL___MIDL_itf_mstsax_0000_0057_0001;
enum
{
    remoteAppWindowNone = 0,
    remoteAppWindowDisplayed = 1,
    remoteAppShellIconDisplayed = 2
}__MIDL___MIDL_itf_mstsax_0000_0057_0002;
enum
{
    exDiscReasonNoInfo = 0,
    exDiscReasonAPIInitiatedDisconnect = 1,
    exDiscReasonAPIInitiatedLogoff = 2,
    exDiscReasonServerIdleTimeout = 3,
    exDiscReasonServerLogonTimeout = 4,
    exDiscReasonReplacedByOtherConnection = 5,
    exDiscReasonOutOfMemory = 6,
    exDiscReasonServerDeniedConnection = 7,
    exDiscReasonServerDeniedConnectionFips = 8,
    exDiscReasonServerInsufficientPrivileges = 9,
    exDiscReasonServerFreshCredsRequired = 10,
    exDiscReasonRpcInitiatedDisconnectByUser = 11,
    exDiscReasonLogoffByUser = 12,
    exDiscReasonLicenseInternal = 256,
    exDiscReasonLicenseNoLicenseServer = 257,
    exDiscReasonLicenseNoLicense = 258,
    exDiscReasonLicenseErrClientMsg = 259,
    exDiscReasonLicenseHwidDoesntMatchLicense = 260,
    exDiscReasonLicenseErrClientLicense = 261,
    exDiscReasonLicenseCantFinishProtocol = 262,
    exDiscReasonLicenseClientEndedProtocol = 263,
    exDiscReasonLicenseErrClientEncryption = 264,
    exDiscReasonLicenseCantUpgradeLicense = 265,
    exDiscReasonLicenseNoRemoteConnections = 266,
    exDiscReasonLicenseCreatingLicStoreAccDenied = 267,
    exDiscReasonRdpEncInvalidCredentials = 768,
    exDiscReasonProtocolRangeStart = 4096,
    exDiscReasonProtocolRangeEnd = 32767
}__MIDL___MIDL_itf_mstsax_0000_0000_0001;
enum
{
    controlCloseCanProceed = 0,
    controlCloseWaitForEvents = 1
}__MIDL_IMsRdpClient_0001;
enum
{
    RedirectionWarningTypeDefault = 0,
    RedirectionWarningTypeUnsigned = 1,
    RedirectionWarningTypeUnknown = 2,
    RedirectionWarningTypeUser = 3,
    RedirectionWarningTypeThirdPartySigned = 4,
    RedirectionWarningTypeTrusted = 5,
    RedirectionWarningTypeMax = 5
}__MIDL_IMsRdpClientNonScriptable4_0001;
enum
{
    RemoteSessionActionCharms = 0,
    RemoteSessionActionAppbar = 1,
    RemoteSessionActionSnap = 2,
    RemoteSessionActionStartScreen = 3,
    RemoteSessionActionAppSwitch = 4,
    RemoteSessionActionActionCenter = 5
}__MIDL___MIDL_itf_mstsax_0000_0000_0004;
enum
{
    FullMode = 0,
    ThinClientMode = 1,
    SmallCacheMode = 2
}__MIDL___MIDL_itf_mstsax_0000_0000_0003;
enum
{
    controlReconnectStarted = 0,
    controlReconnectBlocked = 1
}__MIDL_IMsRdpClient8_0001;
enum
{
    encodingQualityLow = 0,
    encodingQualityMedium = 1,
    encodingQualityHigh = 2
}__MIDL___MIDL_itf_mstsax_0000_0008_0001;
enum
{
    RemoteActionCharms = 0,
    RemoteActionAppbar = 1,
    RemoteActionSnap = 2,
    RemoteActionStartScreen = 3,
    RemoteActionAppSwitch = 4
}__MIDL_IRemoteDesktopClientActions_0001;
enum
{
    SnapshotEncodingDataUri = 0
}__MIDL_IRemoteDesktopClientActions_0002;
enum
{
    SnapshotFormatPng = 0,
    SnapshotFormatJpeg = 1,
    SnapshotFormatBmp = 2
}__MIDL_IRemoteDesktopClientActions_0003;


// 操作
public:

// IMsRdpClient7

// Functions
//

	void put_Server(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Server()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Domain(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Domain()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_UserName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_UserName()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_DisconnectedText(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_DisconnectedText()
	{
		CString result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_ConnectingText(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ConnectingText()
	{
		CString result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	short get_Connected()
	{
		short result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
		return result;
	}
	void put_DesktopWidth(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_DesktopWidth()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_DesktopHeight(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_DesktopHeight()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_StartConnected(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_StartConnected()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_HorizontalScrollBarVisible()
	{
		long result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_VerticalScrollBarVisible()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_FullScreenTitle(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_CipherStrength()
	{
		long result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_Version()
	{
		CString result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long get_SecuredSettingsEnabled()
	{
		long result;
		InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_SecuredSettings()
	{
		LPDISPATCH result;
		InvokeHelper(0x61, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AdvancedSettings()
	{
		LPDISPATCH result;
		InvokeHelper(0x62, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Debugger()
	{
		LPDISPATCH result;
		InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Connect()
	{
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Disconnect()
	{
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void CreateVirtualChannels(LPCTSTR newVal)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_EMPTY, NULL, parms, newVal);
	}
	void SendOnVirtualChannel(LPCTSTR chanName, LPCTSTR ChanData)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_EMPTY, NULL, parms, chanName, ChanData);
	}
	void put_ColorDepth(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x64, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ColorDepth()
	{
		long result;
		InvokeHelper(0x64, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AdvancedSettings2()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_SecuredSettings2()
	{
		LPDISPATCH result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_ExtendedDisconnectReason()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_FullScreen(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x68, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_FullScreen()
	{
		BOOL result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetVirtualChannelOptions(LPCTSTR chanName, long chanOptions)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_EMPTY, NULL, parms, chanName, chanOptions);
	}
	long GetVirtualChannelOptions(LPCTSTR chanName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_I4, (void*)&result, parms, chanName);
		return result;
	}
	long RequestClose()
	{
		long result;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AdvancedSettings3()
	{
		LPDISPATCH result;
		InvokeHelper(0xc8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void put_ConnectedStatusText(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ConnectedStatusText()
	{
		CString result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AdvancedSettings4()
	{
		LPDISPATCH result;
		InvokeHelper(0x12c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AdvancedSettings5()
	{
		LPDISPATCH result;
		InvokeHelper(0x190, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_TransportSettings()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AdvancedSettings6()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString GetErrorDescription(unsigned long disconnectReason, unsigned long ExtendedDisconnectReason)
	{
		CString result;
		static BYTE parms[] = VTS_UI4 VTS_UI4 ;
		InvokeHelper(0x1f7, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, disconnectReason, ExtendedDisconnectReason);
		return result;
	}
	LPDISPATCH get_RemoteProgram()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_MsRdpClientShell()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AdvancedSettings7()
	{
		LPDISPATCH result;
		InvokeHelper(0x1fb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_TransportSettings2()
	{
		LPDISPATCH result;
		InvokeHelper(0x1fa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AdvancedSettings8()
	{
		LPDISPATCH result;
		InvokeHelper(0x258, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_TransportSettings3()
	{
		LPDISPATCH result;
		InvokeHelper(0x259, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString GetStatusText(unsigned long statusCode)
	{
		CString result;
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x25a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, statusCode);
		return result;
	}
	LPDISPATCH get_SecuredSettings3()
	{
		LPDISPATCH result;
		InvokeHelper(0x25b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_RemoteProgram2()
	{
		LPDISPATCH result;
		InvokeHelper(0x25c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

// Properties
//



};
