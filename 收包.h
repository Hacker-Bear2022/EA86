#pragma once

extern int 门票位置;
extern int 交易司南;
extern bool 未央开关;
extern bool 剧情开关;
extern bool 活动开关;
extern bool 自用开关;



void 收包入口();

void 收包事件(INT64 _包指针);

LRESULT CALLBACK 热键消息(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool 初始化游戏句柄();

void 处理评分数据();

int 思南背包遍历(int 内容, int 开始阶段, int 结束阶段);

void 写出配置();

void 自动未央();

void 未央线程();

void 自动剧情();

void 剧情线程();

void 活动角色();

void 活动线程();

void 全局消息处理();

void 自用线程();

void 自用刷图();



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

struct 消息返回
{
	int 选图;
	int 进图;
	int 翻牌;
	int 回城;
	int 过图;
	int 跟随;
	int 攻击;
	int 拾取;
	int 添加司南;
	int 司南入场;
	消息返回() :
		选图(0),
		进图(0),
		翻牌(0),
		回城(0),
		过图(0),
		跟随(0),
		攻击(0),
		拾取(0),
		添加司南(0),
		司南入场(0)
	{}
};

extern 消息返回 全局;

struct 遍历结构
{
	ULONG64 人物指针;
	ULONG64 首部指针;
	ULONG64 尾部指针;
	ULONG64 遍历数量;
	ULONG64 遍历指针;
	ULONG64 物品指针;
	int 遍历类型;
	int 遍历阵营;
	int 遍历代码;
	ULONG64 怪物血量;
	wstring 怪物名称;
	遍历结构() :
		人物指针(0),
		首部指针(0),
		尾部指针(0),
		遍历数量(0),
		遍历指针(0),
		物品指针(0),
		遍历类型(0),
		遍历阵营(0),
		遍历代码(0),
		怪物血量(0),
		怪物名称(L"")
	{}
};

extern 遍历结构 遍历;

struct BOSS结构
{
	ULONG64 人物指针;
	ULONG64 首部指针;
	ULONG64 尾部指针;
	ULONG64 遍历数量;
	ULONG64 遍历指针;
	ULONG64 物品指针;
	int 遍历类型;
	int 遍历阵营;
	int 遍历代码;
	ULONG64 怪物血量;
	wstring 怪物名称;
	BOSS结构() :
		人物指针(0),
		首部指针(0),
		尾部指针(0),
		遍历数量(0),
		遍历指针(0),
		物品指针(0),
		遍历类型(0),
		遍历阵营(0),
		遍历代码(0),
		怪物血量(0),
		怪物名称(L"")
	{}
};

extern BOSS结构 BOSS;

struct 拾取结构
{
	ULONG64 人物指针;
	ULONG64 首部指针;
	ULONG64 尾部指针;
	ULONG64 遍历数量;
	ULONG64 遍历指针;
	ULONG64 物品指针;
	int 遍历类型;
	int 遍历阵营;
	int 遍历代码;
	ULONG64 怪物血量;
	wstring 怪物名称;
	拾取结构() :
		人物指针(0),
		首部指针(0),
		尾部指针(0),
		遍历数量(0),
		遍历指针(0),
		物品指针(0),
		遍历类型(0),
		遍历阵营(0),
		遍历代码(0),
		怪物血量(0),
		怪物名称(L"")
	{}
};

extern 拾取结构 拾取;