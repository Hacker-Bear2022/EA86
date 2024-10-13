#include"dllmain.h"

bool 倍攻开关;
bool 钩子开关;
int 运算次数 = 0;

void 跟随遍历()
{
	遍历.人物指针 = 读长整数(基址::人物基址B);
	遍历.首部指针 = 读长整数(读长整数(遍历.人物指针 + 基址::地图偏移2) + 基址::地图开始2);
	遍历.尾部指针 = 读长整数(读长整数(遍历.人物指针 + 基址::地图偏移2) + 基址::地图结束2);
	遍历.遍历数量 = (遍历.尾部指针 - 遍历.首部指针) / 24;
	for (size_t i = 0; i < 遍历.遍历数量; i++)
	{
		遍历.遍历指针 = 读长整数(读长整数(遍历.首部指针 + i * 24) + 16) - 48;
		遍历.遍历类型 = 读整数型(遍历.遍历指针 + 基址::类型偏移);
		遍历.遍历阵营 = 读整数型(遍历.遍历指针 + 基址::阵营偏移);
		遍历.怪物血量 = 读长整数(遍历.遍历指针 + 基址::怪物血量);
		if (遍历.遍历类型 == 529 || 遍历.遍历类型 == 273 || 遍历.遍历类型 == 545)
		{
			if (遍历.遍历阵营 != 0)
			{
				int X误差 = 取坐标Call(遍历.遍历指针, 0) - 取坐标Call(遍历.人物指针, 0);
				int Y误差 = 取坐标Call(遍历.遍历指针, 1) - 取坐标Call(遍历.人物指针, 1);
				if ((-30 <= X误差 && X误差 <= 30) || (-10 <= Y误差 && Y误差 <= 10))
				{
					return;
				}
				if (遍历.人物指针 != 遍历.遍历指针)
				{
					坐标Call(遍历.人物指针, 取坐标Call(遍历.遍历指针, 0), 取坐标Call(遍历.遍历指针, 1), 取坐标Call(遍历.遍历指针, 2));
					全局.攻击 = 1;
				}
			}
		}
	}
}

void 跟随BOSS()
{
	BOSS.人物指针 = 读长整数(基址::人物基址B);
	BOSS.首部指针 = 读长整数(读长整数(BOSS.人物指针 + 基址::地图偏移2) + 基址::地图开始2);
	BOSS.尾部指针 = 读长整数(读长整数(BOSS.人物指针 + 基址::地图偏移2) + 基址::地图结束2);
	BOSS.遍历数量 = (BOSS.尾部指针 - BOSS.首部指针) / 24;
	for (size_t i = 0; i < BOSS.遍历数量; i++)
	{
		BOSS.遍历指针 = 读长整数(读长整数(BOSS.首部指针 + i * 24) + 16) - 48;
		BOSS.遍历类型 = 读整数型(BOSS.遍历指针 + 基址::类型偏移);
		BOSS.遍历阵营 = 读整数型(BOSS.遍历指针 + 基址::阵营偏移);
		BOSS.怪物血量 = 读长整数(BOSS.遍历指针 + 基址::怪物血量);
		BOSS.怪物名称 = (wchar_t*)*(INT64*)(BOSS.遍历指针 + 基址::名称偏移);
		if (BOSS.遍历类型 == 529 || BOSS.遍历类型 == 273 || BOSS.遍历类型 == 545)
		{
			if (寻找文本(BOSS.怪物名称, L"领主") != -1)
			{
				坐标Call(BOSS.人物指针, 取坐标Call(BOSS.遍历指针, 0), 取坐标Call(BOSS.遍历指针, 1), 取坐标Call(BOSS.遍历指针, 2));
				全局.攻击 = 1;
			}
		}
	}
}

void 倍攻()
{
	static vector<byte> 还原 = 读字节集(基址::独家伤害, 6);

	if (!倍攻开关)
	{
		int 伤害 = 取随机数(1000000, 5000000);
		vector<byte> oldBytes = { 199, 2 };
		vector<byte> newBytes = 到字节集(伤害, 4);
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
	if (GetForegroundWindow() == Pack.游戏句柄)
	{
		if (读整数型(读长整数(基址::对话基址) + 0xC) == 1 || 读整数型(基址::对话基址B) == 1)
		{
			keybd_event(27, MapVirtualKey(27, 0), 0, 0);//按下
			Sleep(1000);
			keybd_event(27, MapVirtualKey(27, 0), KEYEVENTF_KEYUP, 0);//松开
			keybd_event(32, MapVirtualKey(32, 0), 0, 0);//按下
			Sleep(100);
			keybd_event(32, MapVirtualKey(32, 0), KEYEVENTF_KEYUP, 0);//松开
		}
	}

}

void 按键处理()//X键
{
	if (读整数型(读长整数(基址::对话基址) + 0xC) != 1 || 读整数型(基址::对话基址B) != 1)
	{
		if (GetForegroundWindow() == Pack.游戏句柄)
		{
			keybd_event(88, MapVirtualKey(88, 0), 0, 0);//按下
		}
		else
		{
			keybd_event(88, MapVirtualKey(88, 0), KEYEVENTF_KEYUP, 0);//松开
		}
	}
	else
	{
		return;
	}
}

void 拾取遍历()
{
	拾取.人物指针 = 读长整数(基址::人物基址B);
	拾取.首部指针 = 读长整数(读长整数(读长整数(基址::人物基址B) + 基址::地图偏移2) + 基址::地图开始2);
	拾取.尾部指针 = 读长整数(读长整数(读长整数(基址::人物基址B) + 基址::地图偏移2) + 基址::地图结束2);
	拾取.遍历数量 = (拾取.尾部指针 - 拾取.首部指针) / 24;
	for (size_t i = 0; i < 拾取.遍历数量; i++)
	{
		拾取.遍历指针 = 读长整数(读长整数(拾取.首部指针 + i * 24) + 16) - 48;
		拾取.遍历类型 = 读整数型(拾取.遍历指针 + 基址::类型偏移);
		拾取.遍历阵营 = 读整数型(拾取.遍历指针 + 基址::阵营偏移);
		拾取.遍历代码 = 读整数型(拾取.遍历指针 + 基址::代码偏移);
		拾取.怪物名称 = (wchar_t*)*(INT64*)(拾取.遍历指针 + 基址::名称偏移);
		if (拾取.遍历类型 == 289 && 拾取.遍历阵营 == 200)
		{
			拾取.物品指针 = *(INT64*)(拾取.遍历指针 + 基址::地面物品);
			拾取.怪物名称 = (wchar_t*)*(INT64*)(拾取.物品指针 + 基址::物品名称);
			if (读配置(L"装备获取", L"获取装备") == 1)
			{
				if (读配置(L"装备获取", L"直接入包") == 1 && 读配置(L"装备获取", L"直接拾取") != 1)
				{
					空入Call(遍历.遍历指针);

				}
				if (读配置(L"装备获取", L"直接拾取") == 1 && 读配置(L"装备获取", L"直接入包") != 1)
				{
					写字节集(基址::自动捡物, { 144,144 });
					坐标Call(拾取.人物指针, 取坐标Call(拾取.遍历指针, 0), 取坐标Call(拾取.遍历指针, 1), 取坐标Call(拾取.遍历指针, 2));
				}
			}

		}
	}
}

void 地图遍历()
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
		int 怪物代码 = 读整数型(遍历指针 + 基址::代码偏移);
		公告(L"遍历指针 ： " + to_wstring(遍历指针) + L" 遍历类型 ： " + to_wstring(遍历类型) + L" 遍历阵营 ： " + to_wstring(遍历阵营) + L" 怪物名称 ： " + 怪物名称 + L" 怪物代码 ： " + to_wstring(怪物代码) + L" 怪物血量 ： " + to_wstring(怪物血量));

	}
}

void 跟随未央柱子()
{
	ULONG64 人物指针 = 读长整数(基址::人物基址B);
	ULONG64 首部指针 = 读长整数(读长整数(人物指针 + 基址::地图偏移2) + 基址::地图开始2);
	ULONG64 尾部指针 = 读长整数(读长整数(人物指针 + 基址::地图偏移2) + 基址::地图结束2);
	ULONG64 遍历数量 = (尾部指针 - 首部指针) / 24;
	for (size_t i = 0; i < 遍历数量; i++)
	{
		ULONG64 遍历指针 = 读长整数(读长整数(首部指针 + i * 24) + 16) - 48;
		int 怪物代码 = 读整数型(遍历指针 + 基址::代码偏移);

		if (怪物代码 == 407001243 || 怪物代码 == 407001241 || 怪物代码 == 407001242 || 怪物代码 == 407001240 || 怪物代码 == 490002230)
		{
			坐标Call(人物指针, 取坐标Call(遍历指针, 0), 取坐标Call(遍历指针, 1), 取坐标Call(遍历指针, 2));
		}
	}
}

void ReleaseMemory()
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	size_t before = pmc.WorkingSetSize;

	EmptyWorkingSet(GetCurrentProcess());

	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	size_t after = pmc.WorkingSetSize;

	std::cout << "释放前: " << before / 1024 << " KB\n";
	std::cout << "释放后: " << after / 1024 << " KB\n";
}

void 自用对话框()//ESC键和空格键
{
	if (运算次数 > 5)
	{
		keybd_event(27, MapVirtualKey(27, 0), 0, 0);//按下ESC
		Sleep(3000);
		keybd_event(27, MapVirtualKey(27, 0), KEYEVENTF_KEYUP, 0);//松开ESC
		运算次数 = 0;
	}

	if (读整数型(读长整数(基址::对话基址) + 0xC) == 1 || 读整数型(基址::对话基址B) == 1)
	{
		运算次数++;
		keybd_event(27, MapVirtualKey(27, 0), 0, 0);//按下
		Sleep(300);
		keybd_event(27, MapVirtualKey(27, 0), KEYEVENTF_KEYUP, 0);//松开
		Sleep(300);
		keybd_event(32, MapVirtualKey(32, 0), 0, 0);//按下空格
		Sleep(300);
		keybd_event(32, MapVirtualKey(32, 0), KEYEVENTF_KEYUP, 0);//松开空格
	}

}

void 自用拾取()
{
	拾取.人物指针 = 读长整数(基址::人物基址B);
	拾取.首部指针 = 读长整数(读长整数(读长整数(基址::人物基址B) + 基址::地图偏移2) + 基址::地图开始2);
	拾取.尾部指针 = 读长整数(读长整数(读长整数(基址::人物基址B) + 基址::地图偏移2) + 基址::地图结束2);
	拾取.遍历数量 = (拾取.尾部指针 - 拾取.首部指针) / 24;
	for (size_t i = 0; i < 拾取.遍历数量; i++)
	{
		拾取.遍历指针 = 读长整数(读长整数(拾取.首部指针 + i * 24) + 16) - 48;
		拾取.遍历类型 = 读整数型(拾取.遍历指针 + 基址::类型偏移);
		拾取.遍历阵营 = 读整数型(拾取.遍历指针 + 基址::阵营偏移);
		拾取.遍历代码 = 读整数型(拾取.遍历指针 + 基址::代码偏移);
		拾取.怪物名称 = (wchar_t*)*(INT64*)(拾取.遍历指针 + 基址::名称偏移);
		if (拾取.遍历类型 == 289 && 拾取.遍历阵营 == 200)
		{
			拾取.物品指针 = *(INT64*)(拾取.遍历指针 + 基址::地面物品);
			拾取.怪物名称 = (wchar_t*)*(INT64*)(拾取.物品指针 + 基址::物品名称);
			写字节集(基址::自动捡物, { 144,144 });
			坐标Call(拾取.遍历指针, 取坐标Call(拾取.人物指针, 0), 取坐标Call(拾取.人物指针, 1), 取坐标Call(拾取.人物指针, 2));
		}
	}
}
