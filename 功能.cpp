#include"dllmain.h"

bool 倍攻开关;
bool 钩子开关;
int 运算次数 = 0;

void 跟随遍历()
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
		if (遍历类型 == 529 || 遍历类型 == 273 || 遍历类型 == 545)
		{
			if (遍历阵营 != 0)
			{
				if (人物指针 != 遍历指针)
				{
					坐标Call(人物指针, 取坐标Call(遍历指针, 0), 取坐标Call(遍历指针, 1), 取坐标Call(遍历指针, 2));
				}
				自动循环变量 = false;
			}
		}
	}
}

void 跟随BOSS()
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
		wstring 怪物名称 = (wchar_t*)*(INT64*)(遍历指针 + 基址::名称偏移);
		if (遍历类型 == 529 || 遍历类型 == 273 || 遍历类型 == 545)
		{
			if (寻找文本(怪物名称, L"领主") != -1)
			{
				坐标Call(人物指针, 取坐标Call(遍历指针, 0), 取坐标Call(遍历指针, 1), 取坐标Call(遍历指针, 2));
				自动循环变量 = false;
			}
		}
	}
}

void 倍攻()
{
	static vector<byte> 还原 = 读字节集(基址::独家伤害, 6);

	if (!倍攻开关)
	{
		vector<byte> oldBytes = { 199, 2 };
		vector<byte> newBytes = 到字节集(5201314, 4);
		vector<byte> Bytes = _AppendToBytes(oldBytes, newBytes);
		写字节集(基址::独家伤害, Bytes);
	}
	else
	{
		写字节集(基址::独家伤害, 还原);
	}

	倍攻开关 = !倍攻开关;
}

void 钩子()
{
	vector<byte> static 还原;
	if (钩子开关 == false)
	{
		还原 = 读字节集(基址::全局钩子, 6);
		写字节集(基址::全局钩子, { 144,144,144,144,144,144 });
		钩子开关 = true;
	}
	else
	{
		写字节集(基址::全局钩子, 还原);
		钩子开关 = false;
	}
}

int 获取地图编号(ULONG64 角色等级)
{
	switch (角色等级) {
	case 1:
		return 9501;
	case 5:
		return 9507;
	case 10:
		return 9502;
	case 15:
		return 9503;
	case 20:
		return 9504;
	case 25:
		return 9511;
	case 28:
		return 9512;
	case 30:
		return 9513;
	case 34:
		return 9514;
	case 38:
		return 9533;
	case 40:
		return 9534;
	case 43:
		return 9561;
	case 46:
		return 9562;
	case 49:
		return 9563;
	case 51:
		return 9531;
	case 54:
		return 9532;
	case 56:
		return 9572;
	case 58:
		return 9573;
	case 62:
		return 9574;
	case 64:
		return 9524;
	case 65:
		return 9525;
	case 66:
		return 9526;
	case 69:
		return 9551;
	case 71:
		return 9552;
	case 73:
		return 9553;
	case 74:
		return 9554;
	case 75:
		return 9555;
	case 76:
		return 9556;
	case 78:
	{
		if (运算次数 == 0)
		{
			return 9505;
		}
		else if (运算次数 == 1)
		{
			return 9506;
		}
		break; // 如果已经处理了两次，跳出 case 80
	}
	case 79:
		return 9591;
	case 80:
	{
		if (运算次数 == 2)
		{
			return 9592;
		}
		else if (运算次数 == 3)
		{
			return 9593;
		}
		break; // 如果已经处理了两次，跳出 case 80
	}
	case 81:
		return 9594;
	case 82: {
		if (运算次数 == 4)
		{
			return 9557;
		}
		else if (运算次数 == 5)
		{
			return 9558;
		}
		break; // 如果已经处理了两次，跳出 case 82
	}
	case 83:
		return 100003945;
	case 84:
		return 100003946;
	case 85:
		return 100003940;
	case 86:
		return 100003941;
	case 87:
		return 100003944;
	case 88:
		return 9541;
	case 92:
		return 100003016;
	case 94:
		return 100003017;
	case 95:
		return 100003018;
	case 97:
		return 100003019;
	case 100:
		return 100003421;
	case 101:
		return 100003422;
	case 102:
		return 100003423;
	case 103:
		return 100003424;
	case 104:
		return 100003425;
	case 105:
		return 100003426;
	case 107:
		return 100003427;
	case 108:
		return 100003428;
	case 109:
		return 100003429;
	default:
		// 如果角色等级不在上述范围内，可以返回一个默认值或处理错误
		std::cerr << "未知的角色等级: " << 角色等级 << std::endl;
		return 0; // 或者抛出异常、记录日志等
	}
	return 0;
}

MapInfo 获取地图信息(ULONG64 地图编号)
{
	auto it = 地图信息.find(地图编号);
	if (it != 地图信息.end())
	{
		return it->second;
	}
	else
	{
		std::cerr << "未知的地图编号: " << 地图编号 << std::endl;
		return MapInfo(); // 返回一个默认构造的MapInfo对象
	}
}

void 对话框处理()//ESC键和空格键
{
	if (读整数型(读长整数(基址::对话基址) + 0xC) == 0)
	{
		keybd_event(27, MapVirtualKey(27, 0), KEYEVENTF_KEYUP, 0);//松开
	}
	else
	{
		keybd_event(27, MapVirtualKey(27, 0), 0, 0);//按下
	}
	if (读整数型(基址::对话基址B) == 0)
	{
		
		keybd_event(32, MapVirtualKey(32, 0), KEYEVENTF_KEYUP, 0);//松开
	}
	else
	{
		keybd_event(32, MapVirtualKey(32, 0), 0, 0);//按下
	}
}

void 按键处理()//X键
{
	if (!是否开门())
	{
		keybd_event(88, MapVirtualKey(88, 0), 0, 0);//按下
	}
	else
	{
		keybd_event(88, MapVirtualKey(88, 0), KEYEVENTF_KEYUP, 0);//松开
	}
}

void 拾取遍历()
{
	ULONG64 人物指针 = 读长整数(基址::人物基址B);
	ULONG64 首部指针 = 读长整数(读长整数(读长整数(基址::人物基址B) + 基址::地图偏移2) + 基址::地图开始2);
	ULONG64 尾部指针 = 读长整数(读长整数(读长整数(基址::人物基址B) + 基址::地图偏移2) + 基址::地图结束2);
	ULONG64 遍历数量 = (尾部指针 - 首部指针) / 24;
	for (size_t i = 0; i < 遍历数量; i++)
	{
		ULONG64 遍历指针 = 读长整数(读长整数(首部指针 + i * 24) + 16) - 48;
		int 遍历类型 = 读整数型(遍历指针 + 基址::类型偏移);
		int 遍历阵营 = 读整数型(遍历指针 + 基址::阵营偏移);
		int 遍历代码 = 读整数型(遍历指针 + 基址::代码偏移);
		wstring 怪物名称 = (wchar_t*)*(INT64*)(遍历指针 + 基址::名称偏移);
		if (遍历类型 == 289)
		{
			INT64 物品指针 = *(INT64*)(遍历指针 + 基址::地面物品);
			wstring 物品名称 = (wchar_t*)*(INT64*)(物品指针 + 基址::物品名称);
			if (读配置(L"装备获取", L"获取装备") == 1)
			{
				if (读配置(L"装备获取", L"直接入包") == 1 && 读配置(L"装备获取", L"直接拾取") != 1)
				{
					空入Call(物品指针);
				}
				if (读配置(L"装备获取", L"直接拾取") == 1 && 读配置(L"装备获取", L"直接入包") != 1)
				{
					写字节集(基址::自动捡物, { 144,144 });
					坐标Call(人物指针, 取坐标Call(遍历指针, 0), 取坐标Call(遍历指针, 1), 取坐标Call(遍历指针, 2));
				}
			}
			
		}
	}
}
