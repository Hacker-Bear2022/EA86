#pragma once

typedef ULONG64(__fastcall* _Func_Call)(
	ULONGLONG RCX__,
	ULONGLONG RDX__,
	ULONGLONG R8__,
	ULONGLONG R9__,
	ULONGLONG R10__,
	ULONGLONG R11__,
	ULONGLONG R12__,
	ULONGLONG R13__,
	ULONGLONG R14__,
	ULONGLONG R15__
	);

ULONG64 EA8_CALL(ULONGLONG ADDR__, ULONGLONG RCX__ = 0, ULONGLONG RDX__ = 0, ULONGLONG R8__ = 0, ULONGLONG R9__ = 0, ULONGLONG R10__ = 0, ULONGLONG R11__ = 0, ULONGLONG R12__ = 0, ULONGLONG R13__ = 0, ULONGLONG R14__ = 0, ULONGLONG R15__ = 0);

void 公告(std::wstring 内容, int 类型 = NULL);

void 透明call();

__int64 地图Call(__int32 地图编号);

ULONG64 窗口CALL(int 参数);

void 打开界面Call(int 界面参数);

void 拍卖添加CALL(int 背包位置, int 添加背包);//添加背包=1装备  添加背包=48司南

void 拍卖上架CALL(int 上架金额);

void 添加Call(ULONG64 物品指针, int 物品地址);

void 分解Call(ULONG64 物品指针);

void 添加司南(int 司南_参);

void 司南入场(int 司南_参);

void 翻牌Call();

void 选图Call();

void 回城Call(__int32 回城位置);//0再次 1其他 2回城

void 拾取Call(ULONG64 物品指针);

void 坐标Call(__int64 触发指针, __int32 X, __int32 Y, __int32 Z = NULL);

__int32 取坐标Call(__int64 触发指针, __int32 方向);

void Send_缓冲Call(INT64 数值);

void Send_发包Call();

void 组包选图();

void 组包卡界面();

void 组包拾取(INT 物品编号);

void 组包进图(int 地图编号, int 地图难度, int 任务编号 = NULL);

void 组包选择角色(INT 角色位置);

void 组包返回角色();

void 组包回城();

void 组包过图(int 房间横轴, int 房间纵轴);

void 组包强顺(int 过图方向);

void 过图Call(__int32 方向);

void 接受Call(INT 任务编号);

void 完成Call(INT 任务编号, INT 完成次数);

void 提交Call(INT 任务编号);

void 区域call(__int32 副本);

void 城镇移动Call(int 城镇区域, int 城镇编号, int 城镇横轴, int 城镇纵轴);

void 进图Call(__int64 副本编号, __int64 副本难度, __int64 任务编号 = 0);

void 进入角色Call(__int32 角色位置);

void 角色翻页Call(__int32 角色页位);

void 选择角色Call(__int32 角色位置);

void Buff_Call(int buff标识);

int 次数Call(int 地图编号);