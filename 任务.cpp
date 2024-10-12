#include "dllmain.h"
int static 次数;
任务结构 任务;

bool 跳过数据()
{

	任务.任务地址 = 读长整数(基址::任务基址);
	任务.首地址 = 读长整数(任务.任务地址 + 基址::全部任务首地址);
	任务.尾地址 = 读长整数(任务.任务地址 + 基址::全部任务尾地址);
	任务.任务数量 = (int)((任务.尾地址 - 任务.首地址) / 8);
	for (任务.任务次数 = NULL; 任务.任务次数 < 任务.任务数量; 任务.任务次数++)
	{
		任务.任务指针 = (int)读长整数(任务.首地址 + static_cast<__int64>(任务.任务次数) * 8);
		任务.任务类型 = (int)读长整数(任务.任务指针 + 基址::任务类型);
		if (任务.任务类型 == NULL)
		{
			任务.任务等级 = 读长整数(任务.任务指针 + 基址::任务等级);
			if (任务.任务等级 < 读长整数(基址::角色等级))
			{
				return true;
			}

		}
	}
	return false;
}

bool 是否有主线任务()
{
	任务.任务地址 = 读长整数(基址::任务基址);
	任务.首地址 = 读长整数(任务.任务地址 + 基址::全部任务首地址);
	任务.尾地址 = 读长整数(任务.任务地址 + 基址::全部任务尾地址);
	任务.任务数量 = (int)((任务.尾地址 - 任务.首地址) / 8);
	for (任务.任务次数 = NULL; 任务.任务次数 < 任务.任务数量; 任务.任务次数++)
	{
		任务.任务指针 = (int)读长整数(任务.首地址 + static_cast<__int64>(任务.任务次数) * 8);
		任务.任务类型 = (int)读长整数(任务.任务指针 + 基址::任务类型);
		if (任务.任务类型 == NULL)
		{
			return true;
		}
	}
	return false;
}

int 返回主线()
{
	任务.任务地址 = 读长整数(基址::任务基址);
	任务.首地址 = 读长整数(任务.任务地址 + 基址::全部任务首地址);
	任务.尾地址 = 读长整数(任务.任务地址 + 基址::全部任务尾地址);
	任务.任务数量 = (int)((任务.尾地址 - 任务.首地址) / 8);
	for (任务.任务次数 = NULL; 任务.任务次数 < 任务.任务数量; 任务.任务次数++)
	{
		任务.任务指针 = 读长整数(任务.首地址 + static_cast<__int64>(任务.任务次数) * 8);
		任务.局部编号 = 读整数型(任务.任务指针);
		任务.任务类型 = 读整数型(任务.任务指针 + 基址::任务类型);
		if (任务.任务类型 == NULL)
		{
			任务.任务长度 = 读整数型(任务.任务指针 + 基址::任务大小);
			if (任务.任务长度 > 7)
			{
				任务.任务名称 = (wchar_t*)读长整数(任务.任务指针 + 16);
			}
			else {
				任务.任务名称 = (wchar_t*)(任务.任务指针 + 16);
			}
			任务.任务条件 = (wchar_t*)读长整数(任务.任务指针 + 基址::任务条件);
			return 任务.局部编号;

		}
	}
	return -1;
}

int 返回隐藏()
{
	任务.任务地址 = 读长整数(基址::任务基址);
	任务.首地址 = 读长整数(任务.任务地址 + 基址::已接任务首地址);
	任务.尾地址 = 读长整数(任务.任务地址 + 基址::已接任务尾地址);
	任务.任务数量 = (int)((任务.尾地址 - 任务.首地址) / 16);
	for (任务.任务次数 = NULL; 任务.任务次数 < 任务.任务数量; 任务.任务次数++)
	{
		任务.任务指针 = (int)读长整数(任务.首地址 + static_cast<__int64>(任务.任务次数) * 16);
		任务.局部编号 = (int)读长整数(任务.任务指针);
		任务.任务类型 = (int)读长整数(任务.任务指针 + 基址::任务类型);
		if (任务.任务类型 == 11)
		{
			return 任务.局部编号;
		}
	}
	return -1;
}

int 获取任务地图(int 任务编号)
{

	任务.任务地址 = 读长整数(基址::任务基址);
	任务.首地址 = 读长整数(任务.任务地址 + 基址::已接任务首地址);
	任务.尾地址 = 读长整数(任务.任务地址 + 基址::已接任务尾地址);
	任务.任务数量 = (int)((任务.尾地址 - 任务.首地址) / 16);
	for (任务.任务次数 = NULL; 任务.任务次数 < 任务.任务数量; 任务.任务次数++)
	{
		任务.任务指针 = 读长整数(任务.首地址 + static_cast<__int64>(任务.任务次数) * 16);

		if (读长整数(任务.任务指针) == 任务编号)
		{
			INT64 编号地址 = 读长整数(任务.任务指针 + 基址::任务副本);

			return (int)读长整数(编号地址);
		}
	}
	return 0;
}

int 任务是否完成(int 对象编号) /*0未接任务 1已结人 2 任务完成*/
{

	任务.任务地址 = 读长整数(基址::任务基址);
	任务.首地址 = 读长整数(任务.任务地址 + 基址::已接任务首地址);
	任务.尾地址 = 读长整数(任务.任务地址 + 基址::已接任务尾地址);
	任务.任务数量 = (int)((任务.尾地址 - 任务.首地址) / 16);
	for (任务.任务次数 = NULL; 任务.任务次数 < 任务.任务数量; 任务.任务次数++)
	{
		任务.任务指针 = 读长整数(任务.首地址 + static_cast<__int64>(任务.任务次数) * 16);
		任务.局部编号 = 读整数型(任务.任务指针);
		if (任务.局部编号 == 对象编号)
		{
			任务.局部解密 = 读整数型(任务.首地址 + static_cast<__int64>(任务.任务次数) * 16 + 8);
			if (任务.局部解密 > 0)
			{
				return 1;
			}
			else if (任务.局部解密 == 0)
			{
				return 2;
			}
		}
	}
	return 0;
}

int 获取处理方式(int 对象编号)/*1城镇2刷图*/
{
	任务.任务地址 = 读长整数(基址::任务基址);
	任务.首地址 = 读长整数(任务.任务地址 + 基址::全部任务首地址);
	任务.尾地址 = 读长整数(任务.任务地址 + 基址::全部任务尾地址);
	任务.任务数量 = (int)((任务.尾地址 - 任务.首地址) / 8);
	for (任务.任务次数 = NULL; 任务.任务次数 < 任务.任务数量; 任务.任务次数++)
	{
		任务.任务指针 = 读长整数(任务.首地址 + static_cast<__int64>(任务.任务次数) * 8);
		if (读长整数(任务.任务指针) == 对象编号)
		{
			任务.任务条件 = (wchar_t*)读长整数(任务.任务指针 + 基址::任务条件);
			if (
				wcsstr(任务.任务条件, TEXT("[meet npc]")) != NULL ||
				wcsstr(任务.任务条件, TEXT("[seek n meet npc]")) != NULL ||
				wcsstr(任务.任务条件, TEXT("[reach the range]")) != NULL ||
				wcsstr(任务.任务条件, TEXT("[look cinematic]")) != NULL ||
				wcsstr(任务.任务条件, TEXT("[quest clear]")) != NULL ||
				wcsstr(任务.任务条件, TEXT("[question]")) != NULL
				)
			{
				return 1;
			}
			if (
				wcsstr(任务.任务条件, TEXT("[hunt monster]")) != NULL ||
				wcsstr(任务.任务条件, TEXT("[condition under clear]")) != NULL ||
				wcsstr(任务.任务条件, TEXT("[clear map]")) != NULL ||
				wcsstr(任务.任务条件, TEXT("[hunt enemy]")) != NULL ||
				wcsstr(任务.任务条件, TEXT("[seeking]")) != NULL
				)
			{
				return 2;
			}

		}
	}
	return 0;
}

void 获取处理结果(int 对象编号)
{
	bool result = false;
	int 完成状态 = -1, 处理方式 = -1;
	完成状态 = 任务是否完成(对象编号);
	处理方式 = 获取处理方式(对象编号);
	switch (完成状态)
	{
	case 0:
		接受Call(对象编号);
		break;
	case 1:
		完成Call(对象编号, 完成状态);
		break;
	case 2:
		提交Call(对象编号);
		Pack.地图编号 = 0;
		break;
	}
	switch (处理方式)
	{
	case 0:
		接受Call(对象编号);
		break;
	case 1:
		完成Call(对象编号, 完成状态);
		break;
	case 2:
		if (完成状态 != 2)
		{
			Pack.任务编号 = 对象编号;
			Pack.地图编号 = 获取任务地图(对象编号);
			区域call(Pack.地图编号);
			Pack.地图难度 = 0;
			Sleep(1000);
			全局.选图 = 1;
		}
		break;
	}
}

