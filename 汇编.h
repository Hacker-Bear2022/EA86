#pragma once


vector<BYTE> addByte(vector<BYTE> a, vector<BYTE> b);

vector<byte> ���ֽڼ�(ULONG64  i, int λ�� = NULL);

void д�ֽڼ�(ULONG64 memAddress, const std::vector<byte>& data);

void д������(ULONG64 ��_�ڴ��ַ, ULONG64 ��_д������);

ULONG64 ��������(ULONG64 ��_�ڴ��ַ);

int ȡ�����(int ��Сֵ, int ���ֵ);

DWORD ��������(ULONG64 ��_�ڴ��ַ);

wstring ���ı�(INT64 �ڴ��ַ, INT ����);

int ��ȡ���ֲ�ת��(const std::wstring& str);

int ������(wstring ������, wstring ������);

void д����(wstring ������, wstring ������, wstring ����);

wstring �������ı�(wstring ������, wstring ������);

vector<std::wstring> �������ַ���(const std::wstring& �ı�);

wstring ����·��();

int Ѱ���ı�(const std::wstring& �����ҵ��ı�, const std::wstring& �ı�);

wstring ȡ����ʱ��();

void д������(ULONG64 ��_�ڴ��ַ, DWORD ��_д������);

vector<byte> ���ֽڼ�(ULONG64 memAddress, DWORD length);

ByteArr _AppendToBytes(ByteArr oldBytes, ByteArr newBytes);

ULONG_PTR �����ڴ�(SIZE_T �ڴ��С);

vector<BYTE> AnsiתUnicode(const std::string& str);

wstring boolToWString(bool value);

template<typename Func, typename... Args>

std::future<void> �첽ִ��(Func&& func, Args&&... args)
{
	std::packaged_task<void()> task(std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
	auto future = task.get_future();
	std::thread(std::move(task)).detach(); // �ڵ������߳�����������
	return future;
}