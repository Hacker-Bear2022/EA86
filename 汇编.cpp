#include"dllmain.h"

vector<BYTE> addByte(vector<BYTE> a, vector<BYTE> b) {
	vector<BYTE> ret(a.size() + b.size());
	for (size_t i = 0; i < a.size(); i++)
	{
		ret[i] = a[i];
	}
	for (size_t i = 0; i < b.size(); i++)
	{
		ret[a.size() + i] = b[i];
	}
	return ret;
}

vector<byte> ���ֽڼ�(ULONG64  i, int λ��)
{
	if (λ�� == 0)
	{
		λ�� = 8;
	}
	ULONG64  adr = (ULONG64)&i;
	std::vector<byte>c;
	for (size_t i = 0; i < λ��; i++) {
		c.push_back(*(byte*)adr++);
	}
	return c;
}

void д�ֽڼ�(ULONG64 memAddress, const std::vector<byte>& data)
{
	if (IsBadReadPtr(reinterpret_cast<VOID*>(memAddress), 1))
	{
		return;
	}

	DWORD oldProtect;
	SIZE_T sizeToWrite = data.size();

	// �޸��ڴ�����������д��
	VirtualProtect(reinterpret_cast<LPVOID>(memAddress), sizeToWrite, PAGE_EXECUTE_READWRITE, &oldProtect);

	// ʹ�� std::memcpy ��������
	std::memcpy(reinterpret_cast<byte*>(memAddress), data.data(), sizeToWrite);

	// ��ԭԭʼ�ڴ�����
	VirtualProtect(reinterpret_cast<LPVOID>(memAddress), sizeToWrite, oldProtect, &oldProtect);
}

void д������(ULONG64 ��_�ڴ��ַ, ULONG64 ��_д������)
{
	DWORD oldProtect;

	// �����޸��ڴ汣��
	__try
	{
		VirtualProtect(reinterpret_cast<LPVOID>(��_�ڴ��ַ), 8, PAGE_EXECUTE_READWRITE, &oldProtect);

		// д������
		*reinterpret_cast<ULONG64*>(��_�ڴ��ַ) = ��_д������;

		// ��ԭԭʼ�ڴ汣��
		VirtualProtect(reinterpret_cast<LPVOID>(��_�ڴ��ַ), 8, oldProtect, &oldProtect);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// ��������쳣���������Ч�ڴ棩����ʲôҲ����
		// ������������Ӵ������߼�
	}
}

ULONG64 ��������(ULONG64 ��_�ڴ��ַ)
{
	ULONG64 value = 0;

	// ���Զ�ȡ�ڴ�
	__try
	{
		value = *reinterpret_cast<ULONG64*>(��_�ڴ��ַ);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// ��������쳣���������Ч�ڴ棩������Ĭ��ֵ
		return 0;
	}

	return value;
}

int ȡ�����(int ��Сֵ, int ���ֵ)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(��Сֵ, ���ֵ);
	int random_number = dis(gen);
	return random_number;
}

DWORD ��������(ULONG64 ��_�ڴ��ַ)
{
	DWORD value = 0;

	// ���Զ�ȡ�ڴ�
	__try
	{
		value = *reinterpret_cast<DWORD*>(��_�ڴ��ַ);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// ��������쳣���������Ч�ڴ棩������Ĭ��ֵ
		return 0;
	}

	return value;
}

wstring ���ı�(INT64 �ڴ��ַ, INT ����)
{
	WCHAR* temp = new WCHAR[����];
	memset(temp, 0, ����);
	wstring text = L"";
	if (IsBadReadPtr((PVOID)�ڴ��ַ, ����)) return text;
	memcpy(temp, (PVOID)�ڴ��ַ, ����);
	text = temp;
	delete[]temp;
	return text;
}

int ��ȡ���ֲ�ת��(const std::wstring& str)
{
	// �������ֵ���ʼλ��
	auto start = std::find_if(str.begin(), str.end(), ::iswdigit);
	if (start == str.end()) {
		throw std::invalid_argument("No digits found in the input string.");
	}

	// �������ֵĽ���λ��
	auto end = std::find_if_not(start, str.end(), ::iswdigit);

	// ��ȡ���ַ���
	std::wstring �����ַ���(start, end);

	// �����ַ���ת��Ϊint
	try {
		return std::stoi(�����ַ���);
	}
	catch (const std::invalid_argument&) {
		throw std::runtime_error("Failed to convert the extracted string to an integer.");
	}
	catch (const std::out_of_range&) {
		throw std::runtime_error("The extracted number is out of range for int.");
	}
}

int ������(wstring ������ ,wstring ������)
{
	wstring �ļ�·�� = ����·��() + L"\\" + L"Path.ini";
	�Զ�ѭ������ = false;
	return GetPrivateProfileIntW(������.c_str(), ������.c_str(), 0, �ļ�·��.c_str());
}

void д����(wstring ������ ,wstring ������, wstring ����)
{
	wstring �ļ�·�� = ����·��() + L"\\" + L"Path.ini";
	WritePrivateProfileStringW(������.c_str(), ������.c_str(), ����.c_str(), �ļ�·��.c_str());
}

std::wstring ����·��()
{
	LPWSTR path[255];
	ZeroMemory(path, 255);
	SHGetSpecialFolderPath(0, (LPWSTR)path, CSIDL_DESKTOPDIRECTORY, 0);
	wstring ��_·�� = ((LPWSTR)path);
	wstring ��_б�� = L"\\";
	��_·�� = ��_·�� + ��_б��;
	return 	��_·��;
}

int Ѱ���ı�(const std::wstring& �����ҵ��ı�, const std::wstring& �ı�)
{
	size_t pos = �����ҵ��ı�.find(�ı�);
	if (pos != std::wstring::npos)
	{
		return static_cast<int>(pos);
	}
	else
	{
		return -1; // ����-1��ʾδ�ҵ��ı�
	}
}

std::wstring ȡ����ʱ��() 
{
	// ��ȡ��ǰʱ���
	auto now = std::chrono::system_clock::now();

	// ת��Ϊ time_t ����
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	// ��ȡ����ʱ��
	std::tm tm;
	localtime_s(&tm, &now_c); // ʹ�� localtime_s ��� localtime

	// �������ַ�������
	wchar_t buffer[30];

	// ��ʽ��ʱ��
	wcsftime(buffer, sizeof(buffer) / sizeof(wchar_t), L"%Y-%m-%d %H:%M:%S", &tm);

	// ���ظ�ʽ������ַ���
	return std::wstring(buffer);
}

void д������(ULONG64 ��_�ڴ��ַ, DWORD ��_д������)
{
	DWORD oldProtect;

	__try
	{
		VirtualProtect(reinterpret_cast<LPVOID>(��_�ڴ��ַ), 4, PAGE_EXECUTE_READWRITE, &oldProtect);
		*reinterpret_cast<DWORD*>(��_�ڴ��ַ) = ��_д������;
		VirtualProtect(reinterpret_cast<LPVOID>(��_�ڴ��ַ), 4, oldProtect, &oldProtect);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// ��������쳣���������Ч�ڴ棩����ʲôҲ����
	}
}

std::vector<byte> ���ֽڼ�(ULONG64 memAddress, DWORD length)
{
	std::vector<byte> result;
	if (IsBadReadPtr(reinterpret_cast<VOID*>(memAddress), length))
	{
		return result; // ���ؿ�����
	}

	// Ԥ�ȷ����㹻�Ŀռ�
	result.reserve(length);

	// ʹ�� std::memcpy �����ڴ�����
	std::memcpy(result.data(), reinterpret_cast<const byte*>(memAddress), length);

	return result;
}

ByteArr _AppendToBytes(ByteArr oldBytes, ByteArr newBytes)
{
	ByteArr bytes = oldBytes;
	if (newBytes.size() == 0)
	{
		return bytes;
	}
	for (DWORD i = 1; i <= newBytes.size(); i++)
	{
		bytes.push_back(newBytes[i - (DWORD)1]);
	}
	return bytes;
}