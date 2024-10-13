#include"dllmain.h"

int 未央计次 = 0;
int 角色位置 = 0;


void 城镇数据处理()
{
	if (取剩余疲劳() >= 读配置(L"剩余疲劳", L"留多少点"))
	{
		if (读配置(L"刷图模式", L"剧情升级") == 0 && 读配置(L"刷图模式", L"未央爬楼") == 1 && 读配置(L"刷图模式", L"活动升级") == 0)
		{
			未央城镇处理();
		}
		if (读配置(L"刷图模式", L"剧情升级") == 1 && 读配置(L"刷图模式", L"未央爬楼") == 0 && 读配置(L"刷图模式", L"活动升级") == 0)
		{
			剧情城镇处理();
		}
		if (读配置(L"刷图模式", L"剧情升级") == 0 && 读配置(L"刷图模式", L"未央爬楼") == 0 && 读配置(L"刷图模式", L"活动升级") == 1)
		{
			活动城镇处理();
		}
	}
	else
	{
		角色位置 = 判断当前角色位置() + 1;
		if (角色位置 >= 取角色数量())
		{
			公告(L"角色完毕，无号可刷");

		}
		else
		{
			if (角色位置 >= 读配置(L"其他设置", L"角色数量"))
			{
				公告(L"角色完毕，无号可刷");

			}
			else
			{
				打开界面Call(22);
			}
		}
	}
}

void 选择角色任务()
{
	组包选择角色(角色位置);
}

void 未央城镇处理()
{
	if (读整数型(基址::城镇大区域) != 126)
	{
		未央开关 = !未央开关;
		return;
	}
	if (读整数型(基址::城镇小区域) != 2)
	{
		std::unique_ptr<std::thread> 未央门口(new std::thread(城镇移动Call, 126, 2, 26, 335));
		if (未央门口->joinable()) {
			未央门口->join();
		}
	}
	if (读配置(L"装备", L"处理装备") == 1)
	{
		std::unique_ptr<std::thread> 处理装备线程(new std::thread(装备处理));
		if (处理装备线程->joinable()) {
			处理装备线程->join();
		}
	}
	if (读配置(L"装备", L"处理装备") == 1 && 读配置(L"装备", L"玉荣") != 0)
	{
		std::unique_ptr<std::thread> 处理玉荣线程(new std::thread(分解玉荣));
		if (处理玉荣线程->joinable()) {
			处理玉荣线程->join();
		}
	}
	if (读配置(L"装备", L"处理装备") == 1 && 读配置(L"装备", L"辟邪玉") == 1)
	{
		std::unique_ptr<std::thread> 处理辟邪玉线程(new std::thread(分解辟邪玉));
		if (处理辟邪玉线程->joinable()) {
			处理辟邪玉线程->join();
		}
	}
	if (读配置(L"门票设置", L"拍卖售票") == 1)
	{
		if (交易上架() == true)
		{
			std::unique_ptr<std::thread> 上架门票线程(new std::thread(整理司南背包));
			if (上架门票线程->joinable()) {
				上架门票线程->join();
			}
		}
		else
		{
			门票位置 = 思南背包遍历(读配置(L"门票设置", L"司南开始"), 读配置(L"门票设置", L"司南开始"), 读配置(L"门票设置", L"司南结束"));
			全局.添加司南 = 1;
			Sleep(800);
			全局.司南入场 = 1;
		}
	}
	else
	{
		门票位置 = 思南背包遍历(读配置(L"门票设置", L"司南开始"), 读配置(L"门票设置", L"司南开始"), 读配置(L"门票设置", L"司南结束"));
		全局.添加司南 = 1;
		Sleep(800);
		全局.司南入场 = 1;
	}
}

void 剧情城镇处理()
{
	if (读配置(L"装备", L"处理装备") == 1)
	{
		std::unique_ptr<std::thread> 处理装备线程(new std::thread(装备处理));
		if (处理装备线程->joinable()) {
			处理装备线程->join();
		}
	}
	if (是否有主线任务())
	{
		if (返回隐藏() > 0)
		{
			获取处理结果(返回隐藏());
		}
		if (返回主线() > 0)
		{
			获取处理结果(返回主线());

		}
	}
}

void 活动城镇处理()
{
	if (读配置(L"装备", L"处理装备") == 1)
	{
		std::unique_ptr<std::thread> 处理装备线程(new std::thread(装备处理));
		if (处理装备线程->joinable()) {
			处理装备线程->join();
		}
	}
	Sleep(500);
	if (取角色等级() == 110)
	{
		公告(L"当前等级为110级，已到达满级");
	}
	Pack.地图编号 = 获取地图编号(取角色等级());
	if (Pack.地图编号 == 9505 || Pack.地图编号 == 9506 || Pack.地图编号 == 9592 || Pack.地图编号 == 9593 || Pack.地图编号 == 9557 || Pack.地图编号 == 9558)
	{
		运算次数++;
	}
	if (Pack.地图编号 != 0)
	{
		MapInfo 地图区域 = 获取地图信息(Pack.地图编号);
		int 自身大区域 = 读整数型(基址::城镇大区域);
		int 自身小区域 = 读整数型(基址::城镇小区域);
		if (自身大区域 != 地图区域.大 || 自身小区域 != 地图区域.小)
		{
			城镇移动Call(地图区域.大, 地图区域.小, 地图区域.X, 地图区域.Y);
		}
		else
		{
			if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
			{
				组包选图();
			}
			if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
			{
				if (取角色等级() == 78)
				{
					组包选图();
				}
				else
				{
					全局.选图 = 1;
				}
			}
		}
	}
}

void 整理司南背包()
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
				if (司南类型 == 0)
				{
					int 售卖价格 = 读配置(L"单人价格", to_wstring(提取数字并转换(物品名称)) + L"阶");
					拍卖添加CALL(i, 48);
					Sleep(300);
					拍卖上架CALL(售卖价格);
				}
				if (司南类型 == 2)
				{
					int 售卖价格 = 读配置(L"组队价格", to_wstring(提取数字并转换(物品名称)) + L"阶");
					拍卖添加CALL(i, 48);
					Sleep(300);
					拍卖上架CALL(售卖价格);
				}
			}
		}
	}
	门票位置 = 思南背包遍历(读配置(L"门票设置", L"司南开始"), 读配置(L"门票设置", L"司南开始"), 读配置(L"门票设置", L"司南结束"));
	全局.添加司南 = 1;
	Sleep(800);
	全局.司南入场 = 1;
}

void 装备处理()
{
	int 装备件数 = 0;
	DWORD64 背包地址 = 读长整数(读长整数(基址::背包基址) + 基址::物品栏偏移) + 72;
	for (int i = 0; i <= 55; i++)
	{
		ULONG64 物品地址 = 读长整数(读长整数(背包地址 + static_cast<__int64>(i) * 8) - 72 + 16);
		if (物品地址 > 0)
		{
			wstring 物品名称 = (wchar_t*)*(INT64*)(物品地址 + 基址::物品名称偏移);
			int 物品属性 = 读整数型(物品地址 + 基址::装备品级);
			if (读配置(L"装备", L"分解装备") == 1 || 读配置(L"装备", L"出售装备") == 1)
			{
				if (读配置(L"装备", L"白装") == 0 && 物品属性 == 0)//分解白装
				{
					组包分解(i);
				}
				if (读配置(L"装备", L"蓝装") == 0 && 物品属性 == 1)//分解蓝装
				{
					组包分解(i);
				}
				if (读配置(L"装备", L"紫装") == 0 && 物品属性 == 2)//分解紫装
				{
					组包分解(i);
				}
				if (读配置(L"装备", L"白装") == 1 && 物品属性 == 0)//出售白装
				{
					组包卖物(i);
				}
				if (读配置(L"装备", L"蓝装") == 1 && 物品属性 == 1)//出售蓝装
				{
					组包卖物(i);
				}
				if (读配置(L"装备", L"紫装") == 1 && 物品属性 == 2)//出售紫装
				{
					组包卖物(i);
				}
			}
		}
	}
}

void 分解玉荣()
{
	//分解玉荣
	DWORD64 背包地址 = 读长整数(读长整数(基址::玉荣背包) + 基址::物品栏偏移) + 基址::玉荣栏偏移;
	DWORD64 数量 = 0;
	for (int i = 0; i < 100; i++)
	{
		DWORD64 物品地址 = 读长整数(读长整数(背包地址 + static_cast<__int64>(i) * 8) - 72 + 16);
		if (物品地址 > 0)
		{
			int 玉荣力 = 读整数型(物品地址 + 基址::玉荣力偏移);
			if (玉荣力 < 读配置(L"装备", L"玉荣"))
			{
				特殊分解(i + 100);
			}
		}
	}
}

void 分解辟邪玉()
{
	//分解辟邪玉
	DWORD64 背包地址 = 读长整数(读长整数(基址::玉荣背包) + 基址::物品栏偏移);
	DWORD64 数量 = 0;
	for (int i = 0; i < 100; i++)
	{
		DWORD64 物品地址 = 读长整数(读长整数(背包地址 + static_cast<__int64>(i) * 8) - 72 + 16);
		if (物品地址 > 0)
		{
			wstring 物品名称 = (wchar_t*)*(INT64*)(物品地址 + 基址::物品名称偏移);
			int 物品属性 = 读整数型(物品地址 + 基址::装备品级);
			int 交易类型 = 读整数型(物品地址 + 基址::物品交易类型);
			wstring 词条 = 词条Call(物品地址);
			// 查找子字符串
			std::wstring 配置文本 = 读配置文本(L"装备", L"保留词条");
			std::vector<std::wstring> 子字符串列表 = 解析子字符串(配置文本);
			// 查找子字符串
			bool 找到任何子字符串 = false;
			for (const auto& 子字符串 : 子字符串列表) {
				size_t found = 词条.find(子字符串);
				if (found != std::wstring::npos) {
					std::wcout << L"找到子字符串: " << 子字符串 << L" 在位置: " << found << std::endl;
					找到任何子字符串 = true;
					break; // 如果只需要找到一个子字符串就可以退出
				}
			}
			if (!找到任何子字符串)
			{
				特殊分解(i);
			}
		}
	}
}

void 自用城镇处理()
{
	if (取角色等级() < 110)
	{
		Pack.地图编号 = 获取地图编号(取角色等级());
		if (Pack.地图编号 != 0)
		{
			MapInfo 地图区域 = 获取地图信息(Pack.地图编号);
			int 自身大区域 = 读整数型(基址::城镇大区域);
			int 自身小区域 = 读整数型(基址::城镇小区域);
			if (自身大区域 != 地图区域.大 || 自身小区域 != 地图区域.小)
			{
				城镇移动Call(地图区域.大, 地图区域.小, 地图区域.X, 地图区域.Y);
			}
		}
	}
}