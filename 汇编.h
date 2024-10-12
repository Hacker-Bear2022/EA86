#pragma once


vector<BYTE> addByte(vector<BYTE> a, vector<BYTE> b);

vector<byte> 到字节集(ULONG64  i, int 位数 = NULL);

void 写字节集(ULONG64 memAddress, const std::vector<byte>& data);

void 写长整数(ULONG64 参_内存地址, ULONG64 参_写入数据);

ULONG64 读长整数(ULONG64 参_内存地址);

int 取随机数(int 最小值, int 最大值);

DWORD 读整数型(ULONG64 参_内存地址);

wstring 读文本(INT64 内存地址, INT 长度);

int 提取数字并转换(const std::wstring& str);

int 读配置(wstring 节名称, wstring 项名称);

void 写配置(wstring 节名称, wstring 项名称, wstring 数据);

wstring 读配置文本(wstring 节名称, wstring 项名称);

vector<std::wstring> 解析子字符串(const std::wstring& 文本);

wstring 桌面路径();

int 寻找文本(const std::wstring& 欲查找的文本, const std::wstring& 文本);

wstring 取现行时间();

void 写整数型(ULONG64 参_内存地址, DWORD 参_写入数据);

vector<byte> 读字节集(ULONG64 memAddress, DWORD length);

ByteArr _AppendToBytes(ByteArr oldBytes, ByteArr newBytes);

ULONG_PTR 创建内存(SIZE_T 内存大小);

vector<BYTE> Ansi转Unicode(const std::string& str);

wstring boolToWString(bool value);

template<typename Func, typename... Args>

std::future<void> 异步执行(Func&& func, Args&&... args)
{
	std::packaged_task<void()> task(std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
	auto future = task.get_future();
	std::thread(std::move(task)).detach(); // 在单独的线程中运行任务
	return future;
}