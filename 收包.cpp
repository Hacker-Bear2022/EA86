#include "dllmain.h"
INT64 HOOK地址 = NULL;
INT64 收包指针 = NULL;
INT64 包指针 = NULL;
static short 包头部;
static short 包长度;
static bool 初始化;
收包数据 Pack;
bool 自动开关;
int 门票位置;
bool 自动循环变量 = false;
static int 通关次数;

void 收包入口()
{
	INT64 收包地址 = 基址::收包Call + *(INT*)(基址::收包Call + 1) + 5 + 0x90;
	INT64 收包跳回 = 收包地址 + 19;
	HOOK地址 = (INT64)VirtualAlloc(NULL, 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (HOOK地址 != NULL) {
		vector<BYTE> Code(0);
		Code = addByte(Code, { 0x0F, 0x10, 0x1C, 0x24, 0x0F, 0x10, 0x54, 0x24, 0x10, 0x0F, 0x10, 0x4C, 0x24, 0x20, 0x0F, 0x10, 0x44, 0x24, 0x30, 0x48, 0xB8 });
		Code = addByte(Code, 到字节集((INT64)&收包指针));
		Code = addByte(Code, { 0x4C, 0x89, 0x30, 0x50, 0x53, 0x51, 0x52, 0x57, 0x56, 0x55, 0x41, 0x50, 0x41, 0x51, 0x41, 0x52, 0x41, 0x53, 0x41, 0x54, 0x41, 0x55, 0x41, 0x56, 0x41, 0x57, 0x9C, 0x48, 0xB8 });
		Code = addByte(Code, 到字节集((INT64)&收包事件));
		Code = addByte(Code, { 0xFF, 0xD0 });
		Code = addByte(Code, { 0x9D, 0x41, 0x5F, 0x41, 0x5E, 0x41, 0x5D, 0x41, 0x5C, 0x41, 0x5B, 0x41, 0x5A, 0x41, 0x59, 0x41, 0x58, 0x5D, 0x5E, 0x5F, 0x5A, 0x59, 0x5B, 0x58, 0x48, 0xB8 });
		Code = addByte(Code, 到字节集(收包跳回));
		Code = addByte(Code, { 0xFF, 0xE0 });
		写字节集(HOOK地址, Code);
		vector<BYTE> HOOK(0);
		HOOK = addByte(HOOK, { 0x48, 0xB8 });
		HOOK = addByte(HOOK, 到字节集((INT64)HOOK地址));
		HOOK = addByte(HOOK, { 0xFF, 0xE0, 0x90, 0x90 });
		写字节集(收包地址, HOOK);
	}
	return;
}

void 收包事件()
{

	包指针 = 收包指针;// 读长整数(收包指针);
	包头部 = *(SHORT*)(包指针 + 1);
	包长度 = *(int32_t*)(包指针 + 3);
	if (Pack.游戏句柄 == NULL)
	{
		Pack.游戏句柄 = FindWindowW(L"地下城与勇士", NULL);
		if (Pack.游戏句柄 != NULL)
		{
			Pack.窗口消息 = (WNDPROC)SetWindowLongPtr(Pack.游戏句柄, GWLP_WNDPROC, (ULONG64)热键消息);
		}
	}
	if (初始化)
	{
		switch (包头部)
		{
		case 1089:
			处理评分数据();
			break;
		case 28:
			Pack.地图编号 = *(__int32*)(包指针 + 16);
			Pack.地图难度 = *(char*)(包指针 + 20);
			Pack.地图序号 = *(char*)(包指针 + 23);
			Pack.领主坐标.x = *(char*)(包指针 + 24);
			Pack.领主坐标.y = *(char*)(包指针 + 25);
			Pack.地图名称 = (wchar_t*)*(__int64*)(地图Call(Pack.地图编号) + 基址::地图名称);
			//公告(L"地图编号：" + to_wstring(Pack.地图编号) + L"  地图难度:  " + to_wstring(Pack.地图难度));
			//公告(L"领主坐标.x：" + to_wstring(Pack.领主坐标.x) + L"  领主坐标.y:  " + to_wstring(Pack.领主坐标.y));
			break;
		case 29:
			Pack.当前坐标.x = *(char*)(包指针 + 16);
			Pack.当前坐标.y = *(char*)(包指针 + 17);
			//公告(L"当前坐标.x：" + to_wstring(Pack.当前坐标.x) + L"  当前坐标.y:  " + to_wstring(Pack.当前坐标.y));
			keybd_event(81, MapVirtualKey(81, 0), 0, 0);//按下
			break;
		case 38:
			if (包长度 != 27)
			{
				/*Pack.怪物数量 = *(UCHAR*)(包指针 + 18);
				if (Pack.怪物数量 == 48)
				{
					Pack.怪物数量 = 0;
				}
				for (Pack.收包计次 = 0; Pack.收包计次 < Pack.怪物数量; Pack.收包计次++)
				{
					ULONG64 temp = 读长整数(包指针 + 20);
					if (temp > INT_MAX || temp < INT_MIN)
					{
						// 处理超出范围的情况
						// 例如，记录日志或设置一个默认值
						throw std::runtime_error("Invalid coordinates or state encountered.");
					}
					else
					{
						Pack.物品编号 = static_cast<int>(temp) + Pack.收包计次;
						//组包拾取(Pack.物品编号);
					}

				}*/
			}
			break;
		case 31:
			Pack.BOSS死亡 = true;
			通关次数++;
			公告(L"通关次数 ：  " + to_wstring(通关次数));
			break;
		case 261:
			Pack.翻牌奖励 = true;
			break;
		}
	}
}

void 全屏遍历()
{
	公告(L"城镇大区域ID：" + to_wstring(读整数型(基址::城镇大区域)) + L"   城镇小区域ID：" + to_wstring(读整数型(基址::城镇小区域))
		+ L"   城镇坐标X：" + to_wstring(读整数型(基址::城镇坐标X)) + L"   城镇坐标Y：" + to_wstring(读整数型(基址::城镇坐标Y)));
}

LRESULT CALLBACK 热键消息(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_KEYUP)
	{
		if (wParam == VK_HOME && !初始化)
		{

			if (初始化游戏句柄())
			{
				初始化 = true;
			}
		}
		if (初始化)
		{
			switch (wParam)
			{
			case VK_END://END键
				自动线程();
				break;
			case VK_F1:
				倍攻();
				break;
			case VK_F2:
				//跟随BOSS();
				钩子();
				break;
			case VK_F3:
				//全屏遍历();
				//钩子();
				Buff_Call(55);
				Buff_Call(127);
				Buff_Call(164);
				Buff_Call(1013);
				Buff_Call(1035);
				Buff_Call(1102);
				break;
			case VK_F4:
				
				break;
			case VK_DELETE:
				//组包回城();
				break;
			}
		}
	}
	return CallWindowProc(Pack.窗口消息, hWnd, uMsg, wParam, lParam);
}

bool 初始化游戏句柄()
{
	std::wstring desktopPath = 桌面路径() + L"\\" + L"false.ini";
	if (文件是否存在(desktopPath.c_str()) == false)
	{
		写出配置();
	}
	公告(L"  初始化成功" + 取现行时间());
	公告(L"F1 伤害");
	公告(L"F2 全屏");
	公告(L"F3 BUFF");
	公告(L"End 自动");
	return true;
}

void 处理评分数据()
{
	写长整数(读长整数(基址::评分基址) + 基址::评分偏移, 取随机数(501314, 601314));
	透明call();
}


void 自动线程()
{
	if (!自动开关)
	{
		if (读配置(L"刷图模式", L"剧情升级") == 1 || 读配置(L"刷图模式", L"活动升级") == 1)
		{
			SetTimer(Pack.游戏句柄, 200, 10, (TIMERPROC)对话框处理);
		}
		SetTimer(Pack.游戏句柄, 1, 500, (TIMERPROC)自动循环);
		SetTimer(Pack.游戏句柄, 300, 50, (TIMERPROC)按键处理);
		公告(L"自动开关 -- ON ");
	}
	else
	{
		if (读配置(L"刷图模式", L"剧情升级") == 1 || 读配置(L"刷图模式", L"活动升级") == 1)
		{
			KillTimer(Pack.游戏句柄, 200);
		}
		KillTimer(Pack.游戏句柄, 1);
		KillTimer(Pack.游戏句柄, 300);
		公告(L"自动开关 -- OFF ");
	}
	自动开关 = !自动开关;
}

std::wstring boolToWString(bool value) {
	return value ? L"true" : L"false";
}

void 自动循环()
{
	if (自动循环变量)
	{
		return;
	}
	自动循环变量 = !自动循环变量;
	switch (取游戏状态())
	{
	case 0://选择角色
	case 1://城镇处理
		城镇数据处理();
		break;
	case 2://选图界面
		选图界面处理();
		break;
	case 3://图内处理
		图内数据处理();
		break;
	}
}

int 思南背包遍历(int 内容)
{
	ULONG64 背包地址 = 读长整数(读长整数(基址::司南背包) + 基址::物品栏偏移);
	auto 检查阶数 = [&](int 阶数)
	{
		for (int i = 0; i < 101; i++)
		{
			ULONG64 物品地址 = 读长整数(读长整数(背包地址 + static_cast<__int64>(i) * 8) - 72 + 16);
			if (物品地址 != 0) {
				wstring 物品名称 = 读文本(读长整数(物品地址 + 基址::物品名称偏移), 50);
				int 交易类型 = 读整数型(物品地址 + 基址::物品交易类型);
				int 司南类型 = 读整数型(读长整数(物品地址 + 基址::司南类型_1) + 基址::司南类型_2);
				if (寻找文本(物品名称, L"试炼") == -1)
				{
					int 当前阶数 = 提取数字并转换(物品名称);
					if (当前阶数 == 阶数)
					{
						if (交易类型 == 5) // 0可交易 5不可交易
						{
							if (司南类型 == 0) // 0单人 2组队
							{
								return i;
							}
						}
						else
						{
							整理司南背包();
						}
					}
				}
				else if (寻找文本(物品名称, L"试炼") != -1)
				{
					if (司南类型 == 0)
					{
						if (读配置(L"门票设置", L"单人试炼") == 1)
						{
							return i;
						}
					}
				}
			}
		}
		return -1; // 如果没有找到匹配项，返回-1
	};
	// 检查传入的阶数
	int 结果 = 检查阶数(内容);
	if (结果 != -1) return 结果;

	// 从当前阶数+1开始检查后续阶数
	for (int i = 内容 + 1; i <= 18; ++i)
	{
		结果 = 检查阶数(i);
		if (结果 != -1) return 结果;
	}

	return -1; // 如果没有找到匹配项，返回-1
}

void 写出配置()
{
	写配置(L"单人价格", L"1阶", L"100000	此项为单人1阶拍卖上架价格，如需上架更多依次类推");
	写配置(L"单人价格", L"2阶", L"100000	如需启用，必须设置拍卖收票=1");
	写配置(L"单人价格", L"3阶", L"100000");
	写配置(L"单人价格", L"4阶", L"100000");
	写配置(L"单人价格", L"5阶", L"100000");
	写配置(L"单人价格", L"6阶", L"100000");
	写配置(L"单人价格", L"7阶", L"100000");
	写配置(L"单人价格", L"8阶", L"100000");
	写配置(L"单人价格", L"9阶", L"100000");
	写配置(L"组队价格", L"1阶", L"100000	此项为组队1阶拍卖上架价格，如需上架更多依次类推");
	写配置(L"组队价格", L"2阶", L"100000	如需启用，必须设置拍卖收票=1");
	写配置(L"组队价格", L"3阶", L"100000");
	写配置(L"组队价格", L"4阶", L"100000");
	写配置(L"组队价格", L"5阶", L"100000");
	写配置(L"组队价格", L"6阶", L"100000");
	写配置(L"组队价格", L"7阶", L"100000");
	写配置(L"组队价格", L"8阶", L"100000");
	写配置(L"组队价格", L"9阶", L"100000");
	写配置(L"门票设置", L"司南开始", L"1	此项表示司南门票走1阶开始爬楼，如需更改自行修改为2 3 4 5");
	写配置(L"门票设置", L"单人试炼", L"1	此项=0表示单人试炼不刷=1表示直接刷掉");
	写配置(L"门票设置", L"拍卖售票", L"1	此项=1表示上架拍卖可交易门票，为0表示不上架");
	写配置(L"装备处理", L"分解装备", L"1	此项=1分解蓝白紫装=0不处理");
	写配置(L"装备处理", L"辟邪玉", L"1	此项=1分解辟邪玉=0不处理");
	写配置(L"装备处理", L"玉荣", L"1	此项=1分解玉荣=0不处理");
	写配置(L"图内处理", L"获取翻牌", L"1	此项=1分解玉荣=0不处理");
	写配置(L"图内处理", L"未央全图", L"1	此项=1未央全图=0直通BOSS");
	写配置(L"刷图模式", L"未央爬楼", L"1	此项=1未央爬楼=0不处理  此项不可和其余两项同时开启");
	写配置(L"刷图模式", L"剧情升级", L"0	此项=1剧情升级=0不处理  此项不可和其余两项同时开启");
	写配置(L"刷图模式", L"活动升级", L"0	此项=1活动升级=0不处理  此项不可和其余两项同时开启");
	写配置(L"操作模式", L"发包操作", L"1	此项=1活动升级=0不处理  此项不可和其余两项同时开启");
	写配置(L"操作模式", L"模拟操作", L"0	此项=1活动升级=0不处理  此项不可和其余两项同时开启");
	写配置(L"装备获取", L"获取装备", L"1	此项=1下两项方可生效，否则不生效");
	写配置(L"装备获取", L"直接拾取", L"1	此项=1为装备坐标拾取=0不处理此项不可和下一项同时开启");
	写配置(L"装备获取", L"直接入包", L"0	此项=1为装备直接入保=0不处理此项不可和上一项同时开启");
}


