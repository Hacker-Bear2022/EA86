
#include"dllmain.h"


int 取游戏状态()
{
	return (int)读长整数(基址::游戏状态);
}

bool 交易上架()
{
	ULONG64 背包地址 = 读长整数(读长整数(基址::司南背包) + 基址::物品栏偏移);
	for (int i = 0; i < 101; i++)
	{
		ULONG64 物品地址 = 读长整数(读长整数(背包地址 + static_cast<__int64>(i) * 8) - 72 + 16);
		if (物品地址 != 0)
		{
			wstring 物品名称 = 读文本(读长整数(物品地址 + 基址::物品名称偏移), 50);
			int 交易类型 = 读整数型(物品地址 + 基址::物品交易类型);
			int 司南类型 = 读整数型(读长整数(物品地址 + 基址::司南类型_1) + 基址::司南类型_2);
			if (交易类型 == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool 是否在BOSS房()
{
	坐标型 局_普通房间;
	坐标型 局_领主房间;
	局_普通房间 = Pack.当前坐标;
	局_领主房间 = Pack.领主坐标;
	if (局_普通房间.x == 局_领主房间.x && 局_普通房间.y == 局_领主房间.y)
	{
		自动循环变量 = false;
		return true;
	}
	else
	{
		自动循环变量 = false;
		return false;
	}
}

bool 是否开门()//0开1关
{
	if (读整数型(读长整数(读长整数(基址::人物基址B) + 基址::地图偏移2) + 基址::是否开门) == 0)
	{
		自动循环变量 = false;
		return true;
	}
	else
	{
		自动循环变量 = false;
		return false;
	}
}

bool BOSS死亡()
{
	int 房间数据 = 读整数型(读长整数(读长整数(读长整数(基址::房间编号) + 基址::时间基址) + 基址::门型偏移) + 基址::篝火判断);
	if (房间数据 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool 是否有物品()
{
	ULONG64 人物指针 = 读长整数(基址::人物基址B);
	ULONG64 首部指针 = 读长整数(读长整数(人物指针 + 基址::地图偏移2) + 基址::地图开始2);
	ULONG64 尾部指针 = 读长整数(读长整数(人物指针 + 基址::地图偏移2) + 基址::地图结束2);
	ULONG64 遍历数量 = (尾部指针 - 首部指针) / 24;
	for (size_t i = 0; i < 遍历数量; i++)
	{
		ULONG64 遍历指针 = 读长整数(读长整数(首部指针 + i * 24) + 16) - 48;
		int 遍历类型 = 读整数型(遍历指针 + 基址::类型偏移);
		int 遍历阵营 = 读整数型(遍历指针 + 基址::阵营偏移);
		ULONG64 怪物血量 = 读长整数(遍历指针 + 基址::怪物血量);
		if (遍历阵营 == 200 && 遍历类型 == 289)
		{
			return true;
		}
	}
	return false;
}

bool 文件是否存在(const wchar_t* 文件名) 
{
	DWORD fileAttributes = GetFileAttributesW(文件名);
	return (fileAttributes != INVALID_FILE_ATTRIBUTES && !(fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}
