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

vector<byte> 到字节集(ULONG64  i, int 位数)
{
	if (位数 == 0)
	{
		位数 = 8;
	}
	ULONG64  adr = (ULONG64)&i;
	std::vector<byte>c;
	for (size_t i = 0; i < 位数; i++) {
		c.push_back(*(byte*)adr++);
	}
	return c;
}

void 写字节集(ULONG64 memAddress, const std::vector<byte>& data)
{
	if (IsBadReadPtr(reinterpret_cast<VOID*>(memAddress), 1))
	{
		return;
	}

	DWORD oldProtect;
	SIZE_T sizeToWrite = data.size();

	// 修改内存属性以允许写入
	VirtualProtect(reinterpret_cast<LPVOID>(memAddress), sizeToWrite, PAGE_EXECUTE_READWRITE, &oldProtect);

	// 使用 std::memcpy 复制数据
	std::memcpy(reinterpret_cast<byte*>(memAddress), data.data(), sizeToWrite);

	// 还原原始内存属性
	VirtualProtect(reinterpret_cast<LPVOID>(memAddress), sizeToWrite, oldProtect, &oldProtect);
}

void 写长整数(ULONG64 参_内存地址, ULONG64 参_写入数据)
{
	DWORD oldProtect;

	// 尝试修改内存保护
	__try
	{
		VirtualProtect(reinterpret_cast<LPVOID>(参_内存地址), 8, PAGE_EXECUTE_READWRITE, &oldProtect);

		// 写入数据
		*reinterpret_cast<ULONG64*>(参_内存地址) = 参_写入数据;

		// 还原原始内存保护
		VirtualProtect(reinterpret_cast<LPVOID>(参_内存地址), 8, oldProtect, &oldProtect);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// 如果发生异常（如访问无效内存），则什么也不做
		// 可以在这里添加错误处理逻辑
	}
}

ULONG64 读长整数(ULONG64 参_内存地址)
{
	ULONG64 value = 0;

	// 尝试读取内存
	__try
	{
		value = *reinterpret_cast<ULONG64*>(参_内存地址);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// 如果发生异常（如访问无效内存），返回默认值
		return 0;
	}

	return value;
}

int 取随机数(int 最小值, int 最大值)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(最小值, 最大值);
	int random_number = dis(gen);
	return random_number;
}

DWORD 读整数型(ULONG64 参_内存地址)
{
	DWORD value = 0;

	// 尝试读取内存
	__try
	{
		value = *reinterpret_cast<DWORD*>(参_内存地址);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// 如果发生异常（如访问无效内存），返回默认值
		return 0;
	}

	return value;
}

wstring 读文本(INT64 内存地址, INT 长度)
{
	WCHAR* temp = new WCHAR[长度];
	memset(temp, 0, 长度);
	wstring text = L"";
	if (IsBadReadPtr((PVOID)内存地址, 长度)) return text;
	memcpy(temp, (PVOID)内存地址, 长度);
	text = temp;
	delete[]temp;
	return text;
}

int 提取数字并转换(const std::wstring& str)
{
	// 查找数字的起始位置
	auto start = std::find_if(str.begin(), str.end(), ::iswdigit);
	if (start == str.end()) {
		throw std::invalid_argument("No digits found in the input string.");
	}

	// 查找数字的结束位置
	auto end = std::find_if_not(start, str.end(), ::iswdigit);

	// 提取子字符串
	std::wstring 数字字符串(start, end);

	// 将子字符串转换为int
	try {
		return std::stoi(数字字符串);
	}
	catch (const std::invalid_argument&) {
		throw std::runtime_error("Failed to convert the extracted string to an integer.");
	}
	catch (const std::out_of_range&) {
		throw std::runtime_error("The extracted number is out of range for int.");
	}
}

int 读配置(wstring 节名称 ,wstring 项名称)
{
	wstring 文件路径 = 桌面路径() + L"\\" + L"Path.ini";
	自动循环变量 = false;
	return GetPrivateProfileIntW(节名称.c_str(), 项名称.c_str(), 0, 文件路径.c_str());
}

void 写配置(wstring 节名称 ,wstring 项名称, wstring 数据)
{
	wstring 文件路径 = 桌面路径() + L"\\" + L"Path.ini";
	WritePrivateProfileStringW(节名称.c_str(), 项名称.c_str(), 数据.c_str(), 文件路径.c_str());
}

std::wstring 桌面路径()
{
	LPWSTR path[255];
	ZeroMemory(path, 255);
	SHGetSpecialFolderPath(0, (LPWSTR)path, CSIDL_DESKTOPDIRECTORY, 0);
	wstring 局_路径 = ((LPWSTR)path);
	wstring 局_斜线 = L"\\";
	局_路径 = 局_路径 + 局_斜线;
	return 	局_路径;
}

int 寻找文本(const std::wstring& 欲查找的文本, const std::wstring& 文本)
{
	size_t pos = 欲查找的文本.find(文本);
	if (pos != std::wstring::npos)
	{
		return static_cast<int>(pos);
	}
	else
	{
		return -1; // 返回-1表示未找到文本
	}
}

std::wstring 取现行时间() 
{
	// 获取当前时间点
	auto now = std::chrono::system_clock::now();

	// 转换为 time_t 类型
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	// 获取本地时间
	std::tm tm;
	localtime_s(&tm, &now_c); // 使用 localtime_s 替代 localtime

	// 创建宽字符缓冲区
	wchar_t buffer[30];

	// 格式化时间
	wcsftime(buffer, sizeof(buffer) / sizeof(wchar_t), L"%Y-%m-%d %H:%M:%S", &tm);

	// 返回格式化后的字符串
	return std::wstring(buffer);
}

void 写整数型(ULONG64 参_内存地址, DWORD 参_写入数据)
{
	DWORD oldProtect;

	__try
	{
		VirtualProtect(reinterpret_cast<LPVOID>(参_内存地址), 4, PAGE_EXECUTE_READWRITE, &oldProtect);
		*reinterpret_cast<DWORD*>(参_内存地址) = 参_写入数据;
		VirtualProtect(reinterpret_cast<LPVOID>(参_内存地址), 4, oldProtect, &oldProtect);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// 如果发生异常（如访问无效内存），则什么也不做
	}
}

std::vector<byte> 读字节集(ULONG64 memAddress, DWORD length)
{
	std::vector<byte> result;
	if (IsBadReadPtr(reinterpret_cast<VOID*>(memAddress), length))
	{
		return result; // 返回空向量
	}

	// 预先分配足够的空间
	result.reserve(length);

	// 使用 std::memcpy 复制内存区域
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