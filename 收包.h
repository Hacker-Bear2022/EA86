#pragma once

extern int 门票位置;

extern bool 自动循环变量;




void 收包入口();

void 收包事件();

LRESULT CALLBACK 热键消息(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool 初始化游戏句柄();

void 处理评分数据();

void 自动线程();

void 自动循环();

int 思南背包遍历(int 内容);

void 写出配置();

struct 坐标型
{
	int x;
	int y;
	int z;
};

extern 坐标型 坐标;

struct 收包数据
{
	wstring 地图名称;
	HWND 游戏句柄;
	WNDPROC 窗口消息;
	坐标型 当前坐标;
	坐标型 领主坐标;
	int 地图编号;
	int 地图难度;
	int 地图序号;
	int 怪物数量;
	int 创建数量;
	int 拾取变量;
	int 拾取数量;
	int 收包计次;
	int 物品编号;
	int 通关计次;
	int 疲劳值;
	int 包头;
	bool BOSS死亡;
	bool 翻牌奖励;
	int 任务编号;

	vector<short>怪物ID;
	收包数据() :
		地图名称(L""),
		游戏句柄(nullptr),
		窗口消息(nullptr),
		当前坐标{ 0, 0, 0 },
		领主坐标{ 0, 0, 0 },
		地图编号(0),
		地图难度(0),
		地图序号(0),
		怪物数量(0),
		创建数量(0),
		拾取变量(0),
		拾取数量(0),
		收包计次(0),
		物品编号(0), // 初始化物品编号为0
		通关计次(0),
		疲劳值(0),
		包头(0),
		怪物ID(),
		BOSS死亡(false),
		翻牌奖励(false),
		任务编号(0)
	{}
};

extern 收包数据 Pack;

struct 游戏地图
{
	坐标型  地图坐标;
	bool 地图左边;
	bool 地图右边;
	bool 地图上边;
	bool 地图下边;
	int 地图通道;
	int 背景颜色;
};

extern 游戏地图 游戏地图大小;

struct 地图数据
{
	wchar_t* 地图名称;
	int 地图编号;
	vector<int> 地图通道;
	坐标型  起始坐标;
	坐标型  终点坐标;
	int 宽;
	int 高;
	vector<坐标型 > 地图走法;
	int 消耗疲劳;
	地图数据() :
		起始坐标{ 0, 0, 0 },
		终点坐标{ 0, 0, 0 },
		宽(0),
		高(0)
	{}
};

extern 地图数据 游戏地图宽高;

struct 地图节点
{
	int 地图F点;
	int 地图G点;
	int 地图H点;
	坐标型  当前坐标;
	坐标型  最终坐标;
};

extern 地图节点 地图节点坐标;