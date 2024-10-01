#include"dllmain.h"


ULONG64 EA8_CALL(ULONGLONG ADDR__, ULONGLONG RCX__, ULONGLONG RDX__, ULONGLONG R8__, ULONGLONG R9__, ULONGLONG R10__, ULONGLONG R11__, ULONGLONG R12__, ULONGLONG R13__, ULONGLONG R14__, ULONGLONG R15__)
{
	_Func_Call MyFastCall = (_Func_Call)ADDR__;

	return MyFastCall(RCX__,
		RDX__,
		R8__,
		R9__,
		R10__,
		R11__,
		R12__,
		R13__,
		R14__,
		R15__);
}

void 神话公告(std::wstring 内容, int 类型)
{
	LPCWSTR TempStr;
	内容 = L"EA8:" + 内容 + L" ";
	TempStr = 内容.c_str();
	ULONG64 公告数组[100] = { NULL };
	*(ULONG64*)((ULONG64)公告数组 + 8) = (ULONG64)TempStr;
	*(ULONG64*)((ULONG64)公告数组 + 28) = -1;
	*(ULONG64*)((ULONG64)公告数组 + 32) = 基址::浅灰色基址;  //颜色A
	if (类型 == 1)
	{
		*(ULONG64*)((ULONG64)公告数组 + 36) = 17;  //系统
	}
	if (类型 == 0)
	{
		*(ULONG64*)((ULONG64)公告数组 + 36) = 38;  //聊天框
	}

	*(ULONG64*)((ULONG64)公告数组 + 108) = 55512;//颜色B
	EA8_CALL(基址::神话CALL, (ULONG64)公告数组);
}

void 透明call()
{
	ULONG64 人物指针 = 读长整数(基址::人物基址B);
	EA8_CALL(基址::透明CALL, 人物指针, 1, 1, 1);
}

__int64 地图Call(__int32 地图编号)
{
	return EA8_CALL(基址::地图CALL, 地图编号);
}

ULONG64 窗口CALL(int 参数)
{
	return EA8_CALL(基址::打开界面CALL, 读长整数(基址::商店基址), 参数);
}

void 打开界面Call(int 界面参数)//10 打开邮箱 13拍卖行 22反回角色
{
	EA8_CALL(基址::界面CALL, 读长整数(基址::界面_Rcx), 界面参数);
}

void 拍卖添加CALL(int 背包位置,int 添加背包)//添加背包=1装备  添加背包=48司南
{
	EA8_CALL(基址::添加CALL, 窗口CALL(基址::上架货物ID), 添加背包, 背包位置, 1);
}

void 拍卖上架CALL(int 上架金额)
{
	EA8_CALL(0x145A45440, 读长整数(0x14CD89510), 0xFFFFFFFF, 上架金额, 上架金额);
}

void 添加Call(ULONG64 物品指针, int 物品地址)
{

	EA8_CALL(基址::一键分解添加, 物品指针, 物品地址, 317);//317自身分解机  319系统分解机
}

void 分解Call(ULONG64 物品指针)
{
	EA8_CALL(基址::分解CALL, 读长整数(物品指针), 65535, 317);//317自身分解机  319系统分解机
}

void 添加司南(int 司南_参)
{
	ULONGLONG 触发指针 = EA8_CALL(基址::打开界面CALL, 读长整数(基址::商店基址));
	EA8_CALL(基址::司南添加CALL, 触发指针, 司南_参);
	Sleep(200);
	司南入场(司南_参);
}

void 司南入场(int 司南_参)
{
	EA8_CALL(基址::司南进图CALL, 读长整数(基址::司南进图_Rcx), 司南_参);
	if (基址::门票判断 + 基址::门票判断偏移 == 3)
	{
		
	}
}

void 翻牌Call()
{
	EA8_CALL(基址::翻牌CALL_1, *(__int64*)基址::回城参数);
	EA8_CALL(基址::翻牌CALL_2, *(__int64*)基址::回城参数, 0, rand() % 5);
	EA8_CALL(基址::快速翻牌CALL, *(__int64*)基址::回城参数);
	自动循环变量 = false;
}

void 选图Call()
{
	EA8_CALL(基址::选图CALL, *(__int64*)基址::角色指针);
	自动循环变量 = false;
}

void 回城Call(__int32 回城位置)//0再次 1其他 2回城
{
	EA8_CALL(基址::回城CALL, *(__int64*)基址::回城参数, 回城位置, 1, 1);
	自动循环变量 = false;
}

void 拾取Call(ULONG64 物品指针)
{
	EA8_CALL(基址::拾取CALL, 读长整数(基址::背包基址), 物品指针);
}

void 坐标Call(__int64 触发指针, __int32 X, __int32 Y, __int32 Z)
{
	EA8_CALL(基址::坐标CALL, 触发指针, X, Y, Z);
}

__int32 取坐标Call(__int64 触发指针, __int32 方向)
{
	return (__int32)EA8_CALL(*(__int64*)(*(__int64*)触发指针 + 基址::取坐标CALL), 触发指针, 方向);
}

void Send_缓冲Call(INT64 数值) {
	EA8_CALL(基址::缓冲CALL, 基址::发包基址, 数值);
}

void Send_发包Call() {
	EA8_CALL(基址::发包CALL);
}

void Send_加密Call(ULONG64 包头, int 长度)
{
	ULONG64 包参数 = NULL;

	if (长度 == 1)包参数 = 0x146104690;
	if (长度 == 2)包参数 = 0x146104A80;
	if (长度 == 4)包参数 = 0x1461046B0;
	if (长度 == 8)包参数 = 0x1461046D0;
	EA8_CALL(包参数, 基址::发包基址, 包头);
}

void 组包选图() 
{
	Send_缓冲Call(15);
	Send_加密Call(0, 4);
	Send_发包Call();
	自动循环变量 = false;
}

void 组包卡界面()
{
	Send_缓冲Call(132);
	Send_发包Call();
	自动循环变量 = false;
}

int 标识Call()
{
	return (int)EA8_CALL(基址::标识CALL);
}

void 组包拾取(INT 物品编号) 
{
	Send_缓冲Call(43);
	Send_加密Call(物品编号, 4);
	Send_加密Call(0, 1);
	Send_加密Call(1, 1);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(标识Call(), 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(标识Call(), 2);
	Send_加密Call(标识Call(), 2);
	Send_发包Call();
}

void 组包进图(int 地图编号, int 地图难度, int 任务编号)
{
	Send_缓冲Call(16);
	Send_加密Call(地图编号, 4);
	Send_加密Call(地图难度, 1);
	Send_加密Call(0, 2);
	Send_加密Call(0, 1);
	Send_加密Call(0, 1);
	Send_加密Call(65535, 2);
	Send_加密Call(0, 4);
	Send_加密Call(0, 1);
	Send_加密Call(0, 4);
	Send_加密Call(0, 1);
	Send_加密Call(0, 4);
	Send_发包Call();
}

void 组包选择角色(INT 角色位置)
{
	Send_缓冲Call(4);
	Send_加密Call(角色位置, 2);
	Send_发包Call();
}

void 组包返回角色()
{
	Send_缓冲Call(7);
	Send_发包Call();
}

void 组包回城()
{
	Send_缓冲Call(42);
	Send_发包Call();
	自动循环变量 = false;
}

void 组包过图(int 房间横轴, int 房间纵轴)
{
	Send_缓冲Call(45);
	Send_加密Call(房间横轴, 1);
	Send_加密Call(房间纵轴, 1);
	Send_加密Call(1465, 4);
	Send_加密Call(214, 4);
	Send_加密Call(0, 1);
	Send_加密Call(35812, 2);
	Send_加密Call(7, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	Send_加密Call(0, 4);
	Send_加密Call(247, 2);
	Send_加密Call(30, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 2);
	Send_加密Call(30, 2);
	Send_加密Call(11, 2);
	Send_加密Call(0, 2);
	Send_加密Call(0, 4);
	Send_加密Call(30, 2);
	Send_加密Call(41, 2);
	Send_加密Call(3, 2);
	Send_加密Call(250184, 8);
	Send_加密Call(24189, 4);
	Send_加密Call(0, 2);
	Send_加密Call(0, 1);
	Send_发包Call();
}

void 组包强顺(int 过图方向)
{
	if (过图方向 == 0)
	{
		组包过图(Pack.当前坐标.x - 1, Pack.当前坐标.y);
		自动循环变量 = false;
	}
	if (过图方向 == 1)
	{
		组包过图(Pack.当前坐标.x + 1, Pack.当前坐标.y);
		自动循环变量 = false;
	}
	if (过图方向 == 2)
	{
		组包过图(Pack.当前坐标.x, Pack.当前坐标.y - 1);
		自动循环变量 = false;
	}
	if (过图方向 == 3)
	{
		组包过图(Pack.当前坐标.x, Pack.当前坐标.y + 1);
		自动循环变量 = false;
	}
}

void 过图Call(__int32 方向)
{
	__int64 空白地址[100] = { 0 };
	EA8_CALL(基址::过图CALL, 读长整数(读长整数(读长整数(基址::房间编号) + 基址::时间基址) + 基址::顺图偏移), 方向, (__int64)&空白地址, 0xFFFFFFFF);
}

void 接受Call(INT 任务编号)
{
	EA8_CALL(基址::接受CALL, 基址::任务基址, 任务编号);
}

void 完成Call(INT 任务编号, INT 完成次数)
{
	if (完成次数 == NULL)
	{
		完成次数 = 1;
	}
	for (size_t i = 0; i < 完成次数; ++i)
	{
		EA8_CALL(基址::完成CALL, 读长整数(基址::任务基址), 任务编号, 0xFFFFFFFF, 0xFFFFFFFF);
	}
}

void 提交Call(INT 任务编号)
{
	EA8_CALL(基址::提交CALL, 读长整数(基址::任务基址), 任务编号, 0xFFFFFFFF, 1);
}

void 区域call(__int32 副本)
{
	int 大区域, 小区域, X, Y;
	EA8_CALL(基址::区域CALL, *(ULONG64*)基址::区域参数, -1, 副本, *(ULONG64*)(基址::区域参数) +基址::区域偏移 - 0x40);
	大区域 = *(int*)(*(ULONG64*)(基址::区域参数) +基址::区域偏移);
	小区域 = *(int*)(*(ULONG64*)(基址::区域参数) +基址::区域偏移 + 4);
	X = *(int*)(*(ULONG64*)(基址::区域参数) +基址::区域偏移 + 8);
	Y = *(int*)(*(ULONG64*)(基址::区域参数) +基址::区域偏移 + 12);
	城镇移动Call(大区域, 小区域, X, Y);
}

void 城镇移动Call(int 城镇区域, int 城镇编号, int 城镇横轴, int 城镇纵轴)
{
	ULONG64 触发指针 = 读长整数(基址::角色指针);
	ULONG64 城镇指针 = 基址::城镇瞬移_Rdx;
	写整数型(城镇指针, 城镇区域);
	写整数型(城镇指针 + 4, 城镇编号);
	写整数型(城镇指针 + 8, 城镇横轴);
	写整数型(城镇指针 + 12, 城镇纵轴);
	EA8_CALL(基址::城镇瞬移CALL, 触发指针, 城镇指针);
}

void 进图Call(__int64 副本编号, __int64 副本难度, __int64 任务编号)
{
	if (任务编号 > 0)
	{
		EA8_CALL(基址::进图CALL, *(__int64*)基址::角色指针, 任务编号, 0, 0, 0, 0xFFFFFFFF);
	}
	else
	{
		EA8_CALL(基址::进图CALL, *(__int64*)基址::角色指针, 副本编号, 副本难度, 0, 0, 0xFFFFFFFF);
	}
}

void 进入角色Call(__int32 角色位置)
{
	EA8_CALL(基址::选择角色CALL, *(__int32*)(*(__int64*)基址::角色基址 + 基址::角色初始指针), 角色位置, 0, 0);
}

void 角色翻页Call(__int32 角色页位)
{
	EA8_CALL(基址::角色翻页CALL, *(__int32*)(*(__int64*)基址::角色基址 + 基址::角色初始指针), 角色页位);
}

void 选择角色Call(__int32 角色位置)
{
	if (角色位置 > 39)
	{
		角色翻页Call(9);
	}
	else if (角色位置 > 35)
	{
		角色翻页Call(8);
	}
	else if (角色位置 > 31)
	{
		角色翻页Call(7);
	}
	else if (角色位置 > 27)
	{
		角色翻页Call(6);
	}
	else if (角色位置 > 23)
	{
		角色翻页Call(5);
	}
	else if (角色位置 > 19)
	{
		角色翻页Call(4);
	}
	else if (角色位置 > 15)
	{
		角色翻页Call(3);
	}
	else if (角色位置 > 11)
	{
		角色翻页Call(2);
	}
	else if (角色位置 > 7)
	{
		角色翻页Call(1);
	}
	else {
		角色翻页Call(0);
	}
	进入角色Call(角色位置);
}


