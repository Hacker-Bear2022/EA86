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

std::wstring 桌面路径();

int 寻找文本(const std::wstring& 欲查找的文本, const std::wstring& 文本);

std::wstring 取现行时间();

void 写整数型(ULONG64 参_内存地址, DWORD 参_写入数据);

std::vector<byte> 读字节集(ULONG64 memAddress, DWORD length);

ByteArr _AppendToBytes(ByteArr oldBytes, ByteArr newBytes);
