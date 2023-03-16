#pragma warning(disable : 4267)
#include "stdafx.h"
#include "log.h"

namespace u_log
{
	HANDLE m_file = INVALID_HANDLE_VALUE;

	std::string get_current_dir()
	{
		char buffer[500]{ 0 };
		GetModuleFileNameA(NULL, buffer, 500);
		(strrchr(buffer, '\\'))[1] = 0;
		return std::string(buffer);
	}

	bool initialize()
	{
		if (m_file != INVALID_HANDLE_VALUE) return true;
		else
		{
			SYSTEMTIME t{ 0 };
			GetLocalTime(&t);

			std::string name = std::to_string(t.wYear) + "_" + std::to_string(t.wMonth);
			std::string dir = get_current_dir() + name;
			std::string log = dir + "\\" + name + "_" + std::to_string(t.wDay) + "_core_rdp_client_log.txt";
			CreateDirectoryA(dir.c_str(), 0);

			// 尝试打开文件
			m_file = CreateFileA(log.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
			if (m_file == INVALID_HANDLE_VALUE) // 文件不存在
			{
				// 创建新的文件
				m_file = CreateFileA(log.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
			}
			else // 文件存在
			{
				// 移动读写位置到末尾
				SetFilePointer(m_file, GetFileSize(m_file, 0), 0, FILE_BEGIN);
			}

			return m_file != INVALID_HANDLE_VALUE;
		}
	}

	void write(std::string buf)
	{
		if (initialize())
		{
			SYSTEMTIME t{ 0 };
			GetLocalTime(&t);

			char st[100]{ 0 };
			sprintf_s(st, 100, "[%d-%d-%d %.2d:%.2d:%.2d] [%d %d] ",
				t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond,
				GetCurrentProcessId(),
				GetCurrentThreadId());

			std::string p = st + buf;
			DWORD r = 0;
			BOOL status = WriteFile(m_file, p.c_str(), (DWORD)p.size(), &r, 0);
			if (status == FALSE)
			{
				CloseHandle(m_file);
				m_file = INVALID_HANDLE_VALUE;
			}
			else FlushFileBuffers(m_file);

			close();
		}
	}

	void close()
	{
		if (m_file != INVALID_HANDLE_VALUE)
		{
			FlushFileBuffers(m_file);
			CloseHandle(m_file);
			m_file = INVALID_HANDLE_VALUE;
		}
	}

	void err(std::string s)
	{
		std::string a = "[error] " + s + " \r\n";
		OutputDebugStringA(a.c_str());
		write(a);
	}
	void warning(std::string s)
	{
		std::string a = "[warning] " + s + " \r\n";
		OutputDebugStringA(a.c_str());
		write(a);
	}
	void info(std::string s)
	{
		std::string a = "[information] " + s + " \r\n";
		OutputDebugStringA(a.c_str());
		write(a);
	}
}