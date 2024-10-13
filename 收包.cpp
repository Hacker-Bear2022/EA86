#include "dllmain.h"
INT64 包指针 = NULL;
static short 包头部;
static short 包长度;
static bool 初始化;
收包数据 Pack;
消息返回 全局;
遍历结构 遍历;
BOSS结构 BOSS;
拾取结构 拾取;
bool 未央开关 = true;
bool 剧情开关 = true;
bool 活动开关 = true;
bool 自用开关 = true;
int 门票位置;
int 交易司南;
static int 通关次数;


INT64 收包Hook(INT64 Rcx, INT64 Rdx, INT64 R8)
{
	INT64 rcx{}, rdx{}, r8{}, r9d{};
	INT64 Ret = NULL;
	rcx = Rcx;
	rdx = Rdx;
	r8 = R8;
	收包事件(r8);
	rcx = EA8_CALL(基址::收包Call, rcx, rdx, r8);
	return rcx;
}

void 收包入口()
{
	DWORD old_protect = NULL;
	VirtualProtect((LPVOID)基址::收包跳转, 8, 64, &old_protect);
	INT64 pFunc = (INT64)收包Hook;
	INT64 VirtualAdd = 0x000110DB;
	BYTE Cpi[8]{ 0xFF,0x14,0x25, 0x0, 0x0, 0x0, 0x0, 0x0 };
	*(INT64*)(Cpi + 3) = (INT64)VirtualAdd;
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)VirtualAdd, &pFunc, sizeof(INT64), 0);
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)基址::收包跳转, Cpi, 7, 0);
	VirtualProtect((LPVOID)基址::收包跳转, 8, old_protect, &old_protect);
}


void 收包事件(INT64 _包指针)
{

	包指针 = _包指针;// 读长整数(收包指针);
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
			keybd_event(81, MapVirtualKey(81, 0), 0, 0);//按下
			keybd_event(81, MapVirtualKey(81, 0), 0, 0);//按下
			keybd_event(81, MapVirtualKey(81, 0), 0, 0);//按下
			keybd_event(81, MapVirtualKey(81, 0), KEYEVENTF_KEYUP, 0);//松开
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

HWND hwnd = NULL;
int hwndInt = 0;


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
				break;
			case VK_F1:
				自动未央();
				break;
			case VK_F2:
				自动剧情();
				break;
			case VK_F3:
				活动角色();
				break;
			case VK_F4:
				Buff_Call(55);
				Buff_Call(127);
				Buff_Call(164);
				Buff_Call(1013);
				Buff_Call(1035);
				Buff_Call(1102);
				Buff_Call(296);
				Buff_Call(1211);
				Buff_Call(1297);
				Buff_Call(1299);
				Buff_Call(1303);
				break;
			case VK_F5:
				倍攻();
				break;
			case VK_F6:
				钩子();
				break;
			case VK_F7:
				自用刷图();
				break;
			case VK_DELETE:

				break;
			}
		}
	}
	return CallWindowProc(Pack.窗口消息, hWnd, uMsg, wParam, lParam);
}

bool 初始化游戏句柄()
{
	std::wstring desktopPath = 桌面路径() + L"\\" + L"Path.ini";
	if (文件是否存在(desktopPath.c_str()) == false)
	{
		写出配置();
	}
	SetTimer(Pack.游戏句柄, 1, 1, (TIMERPROC)全局消息处理);
	ReleaseMemory();
	公告(L"  初始化成功" + 取现行时间());
	公告(L"F1 自动未央");
	公告(L"F2 自动剧情");
	公告(L"F3 活动角色");
	公告(L"End 自动");
	return true;
}

void 处理评分数据()
{
	写长整数(读长整数(基址::评分基址) + 基址::评分偏移, 取随机数(501314, 601314));
	透明call();
}

int 思南背包遍历(int 内容, int 开始阶段, int 结束阶段)
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
	for (int i = 开始阶段; i <= 结束阶段; ++i)
	{
		if (i == 内容) continue; // 跳过已经检查过的特定阶数
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
	写配置(L"门票设置", L"司南开始", L"1	好多开始刷？？？？？");
	写配置(L"门票设置", L"司南结束", L"5	刷到好多停？？？？？");
	写配置(L"门票设置", L"单人试炼", L"1	此项=0表示单人试炼不刷=1表示优先处理");
	写配置(L"门票设置", L"拍卖售票", L"1	此项=1表示上架拍卖可交易门票，为0表示不上架");
	写配置(L"装备", L"处理装备", L"1	此项=1开启=0关闭，此项不开启，后续不生效");
	写配置(L"装备", L"分解装备", L"1	此项=1分解=0不处理");
	写配置(L"装备", L"出售装备", L"1	此项=1出售=0不处理");
	写配置(L"装备", L"白装", L"1		此项=1出售=0分解");
	写配置(L"装备", L"蓝装", L"1		此项=1出售=0分解");
	写配置(L"装备", L"紫装", L"1		此项=1出售=0分解");
	写配置(L"装备", L"辟邪玉", L"1		此项=1分解=0不处理");
	写配置(L"装备", L"玉荣", L"1		多少以下的分解为0不分解");
	写配置(L"装备", L"保留词条", L"冰属性抗性增加|命中率增加|		自行理解吧");
	写配置(L"图内处理", L"获取翻牌", L"1	要不要翻牌奖励？？？1要0不要");
	写配置(L"图内处理", L"未央全图", L"1	此项=1未央全图=0直通BOSS");
	写配置(L"刷图模式", L"未央爬楼", L"1	此项=1未央爬楼=0不处理  此项不可和其余两项同时开启");
	写配置(L"刷图模式", L"剧情升级", L"0	此项=1剧情升级=0不处理  此项不可和其余两项同时开启");
	写配置(L"刷图模式", L"活动升级", L"0	此项=1活动升级=0不处理  此项不可和其余两项同时开启");
	写配置(L"操作模式", L"发包操作", L"0	此项=1活动升级=0不处理  此项不可和其余两项同时开启");
	写配置(L"操作模式", L"模拟操作", L"1	此项=1活动升级=0不处理  此项不可和其余两项同时开启");
	写配置(L"装备获取", L"获取装备", L"1	此项=1下两项方可生效，否则不生效");
	写配置(L"装备获取", L"直接拾取", L"0	此项=1为装备坐标拾取=0不处理此项不可和下一项同时开启");
	写配置(L"装备获取", L"直接入包", L"1	此项=1为装备直接入保=0不处理此项不可和上一项同时开启");
	写配置(L"剩余疲劳", L"留多少点", L"100	留几点疲劳？？？？？？？？？？？？？");
	写配置(L"其他设置", L"角色数量", L"1	刷几个？？？？？");
}

void 自动未央()
{
	if (未央开关)
	{
		if (读配置(L"刷图模式", L"未央爬楼") == 1)
		{
			std::thread 未央句柄(未央线程);
			未央句柄.detach();
		}
		公告(L"Automatic ending -- ON ");
	}
	else
	{
		公告(L"Automatic ending -- OFF ");
	}
	未央开关 = !未央开关;
}

void 未央线程()
{
	while (!未央开关)
	{
		ReleaseMemory();
		Sleep(500);
		switch (取游戏状态())
		{
		case 0:
		{
			std::unique_ptr<std::thread> 选择角色(new std::thread(选择角色任务));
			if (选择角色->joinable()) {
				选择角色->join(); // 等待选择角色任务完成
			}
		}
		break;
		case 1:
		{
			std::unique_ptr<std::thread> 未央城镇(new std::thread(未央城镇处理));
			if (未央城镇->joinable()) {
				未央城镇->join(); // 等待未央城镇处理完成
			}
		}
		break;
		case 3:
			std::unique_ptr<std::thread> 未央图内(new std::thread(未央图内处理数据));
			if (未央图内->joinable()) {
				未央图内->join(); // 等待未央城镇处理完成
			}
			break;
		}
	}
}

void 自动剧情()
{
	if (剧情开关)
	{
		if (读配置(L"刷图模式", L"剧情升级") == 1)
		{
			std::thread 剧情句柄(剧情线程);
			剧情句柄.detach();
		}
		公告(L"Automatic plot -- ON ");
	}
	else
	{
		公告(L"Automatic plot -- OFF ");
	}
	剧情开关 = !剧情开关;
}

void 剧情线程()
{
	while (!剧情开关)
	{
		ReleaseMemory();
		Sleep(1500);
		std::unique_ptr<std::thread> 对话任务(new std::thread(对话框处理));
		if (对话任务->joinable()) {
			对话任务->join(); // 等待选择角色任务完成
		}
		switch (取游戏状态())
		{
		case 0:
		{
			std::unique_ptr<std::thread> 选择角色(new std::thread(选择角色任务));
			if (选择角色->joinable()) {
				选择角色->join();
			}
		}
		break;
		case 1:
		{
			std::unique_ptr<std::thread> 剧情城镇(new std::thread(剧情城镇处理));
			if (剧情城镇->joinable()) {
				剧情城镇->join();
			}
		}
		break;
		case 2:
		{
			{
				std::unique_ptr<std::thread> 剧情选图(new std::thread(剧情选图处理));
				if (剧情选图->joinable()) {
					剧情选图->join();
				}
			}
		}
		break;
		case 3:
			std::unique_ptr<std::thread> 剧情图内(new std::thread(剧情图内处理数据));
			if (剧情图内->joinable()) {
				剧情图内->join();
			}
			break;
		}
	}
}

void 活动角色()
{
	if (活动开关)
	{
		if (读配置(L"刷图模式", L"未央爬楼") == 1)
		{
			std::thread 活动句柄(剧情线程);
			活动句柄.detach();
		}
		公告(L"Automatic plot -- ON ");
	}
	else
	{
		公告(L"Automatic plot -- OFF ");
	}
	活动开关 = !活动开关;
}

void 活动线程()
{
	while (!活动开关)
	{
		ReleaseMemory();
		Sleep(500);
		std::unique_ptr<std::thread> 对话任务(new std::thread(对话框处理));
		if (对话任务->joinable()) {
			对话任务->join(); // 等待选择角色任务完成
		}
		switch (取游戏状态())
		{
		case 0:
		{
			std::unique_ptr<std::thread> 选择角色(new std::thread(选择角色任务));
			if (选择角色->joinable()) {
				选择角色->join(); // 等待选择角色任务完成
			}
		}
		break;
		case 1:
		{
			std::unique_ptr<std::thread> 活动城镇(new std::thread(活动城镇处理));
			if (活动城镇->joinable()) {
				活动城镇->join(); // 等待未央城镇处理完成
			}
		}
		break;
		case 3:
		{
			std::unique_ptr<std::thread> 活动图内(new std::thread(活动图内处理数据));
			if (活动图内->joinable()) {
				活动图内->join(); // 等待未央城镇处理完成
			}
		}
		break;
		}
	}
}

void 全局消息处理()
{
	if (全局.选图 == 1)
	{
		选图Call();
		全局.选图 = 0;
	}
	if (全局.进图 == 1)
	{
		进图Call(Pack.地图编号, Pack.地图难度);
		全局.进图 = 0;
	}
	if (全局.进图 == 2)
	{
		进图Call(Pack.地图编号, 2);
		全局.进图 = 0;
	}
	if (全局.翻牌 == 1)
	{
		翻牌Call();
		全局.翻牌 = 0;
	}
	if (全局.回城 == 1)
	{
		回城Call(2);
		全局.回城 = 0;
	}
	if (全局.过图 == 1)
	{
		if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
		{
			组包强顺(顺图方向());
		}
		if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
		{
			过图Call(顺图方向());
		}
		全局.过图 = 0;
	}
	if (全局.跟随 == 1)
	{
		跟随遍历();
		全局.跟随 = 0;
	}
	if (全局.跟随 == 2)
	{
		跟随BOSS();
		全局.跟随 = 0;
	}
	if (全局.攻击 == 1)
	{
		攻击Call();
		全局.攻击 = 0;
	}
	if (全局.拾取 == 1)
	{
		拾取遍历();
		全局.拾取 = 0;
	}
	if (全局.拾取 == 2)
	{
		自用拾取();
		全局.拾取 = 0;
	}
	if (全局.添加司南 == 1)
	{
		添加司南(门票位置);
		全局.添加司南 = 0;
	}
	if (全局.司南入场 == 1)
	{
		司南入场(门票位置);
		全局.司南入场 = 0;
	}
	if (全局.过图 == 2)
	{
		if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
		{
			组包强顺(1);
		}
		if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
		{
			过图Call(1);
		}
		全局.过图 = 0;
	}
	if (全局.过图 == 3)
	{
		if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
		{
			int 地图反馈 = 未央全图();
			组包强顺(地图反馈);
		}
		if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
		{
			int 地图反馈 = 未央全图();
			过图Call(地图反馈);
		}
		全局.过图 = 0;
	}
}

void 自用刷图()
{
	if (自用开关)
	{
		std::thread 自用句柄(自用线程);
		自用句柄.detach();
	}
	else
	{
	}
	自用开关 = !自用开关;
}

void 自用线程()
{
	while (!自用开关)
	{
		ReleaseMemory();
		std::unique_ptr<std::thread> 对话任务(new std::thread(自用对话框));
		if (对话任务->joinable()) {
			对话任务->join(); // 等待选择角色任务完成
		}
		switch (取游戏状态())
		{
		case 1:
		{
			std::unique_ptr<std::thread> 自用城镇(new std::thread(自用城镇处理));
			if (自用城镇->joinable()) {
				自用城镇->join();
			}
		}
		break;
		case 3:
			std::unique_ptr<std::thread> 自用图内(new std::thread(自用图内处理数据));
			if (自用图内->joinable()) {
				自用图内->join();
			}
			break;
		}
	}
}