#include"dllmain.h"

int 选图次数 = 0;

void 选图界面处理()
{
	选图次数++;
	自动循环变量 = false;
	if (读配置(L"刷图模式", L"剧情升级") == 1 && 读配置(L"刷图模式", L"未央爬楼") != 1 && 读配置(L"刷图模式", L"活动升级") != 1)
	{
		剧情选图处理();
	}
	if (读配置(L"刷图模式", L"剧情升级") != 1 && 读配置(L"刷图模式", L"未央爬楼") != 1 && 读配置(L"刷图模式", L"活动升级") == 1)
	{
		活动升级选图处理();
	}

}

void  剧情选图处理()
{
	if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
	{
		if (选图次数 > 3)
		{
			选图次数 = 0;
			组包卡界面();
		}
		else
		{
			组包进图(Pack.地图编号, Pack.地图难度);
		}

	}
	if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
	{
		if (选图次数 > 3)
		{
			选图次数 = 0;
			组包卡界面();
		}
		else
		{
			组包进图(Pack.地图编号, Pack.地图难度);
		}
		//进图Call(Pack.地图编号, Pack.地图难度,Pack.任务编号);
	}
}

void 活动升级选图处理()
{
	if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
	{
		组包进图(Pack.地图编号, 2);
	}
	if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
	{
		进图Call(Pack.地图编号, 2);
	}
}
