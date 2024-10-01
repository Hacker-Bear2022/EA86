#pragma once

struct 任务结构
{
	INT64 任务地址;
	INT64 首地址;
	INT64 尾地址;
	int 任务数量;
	int 任务次数;
	INT64 任务指针;
	int 任务类型;
	ULONG64 任务等级;
	int 局部编号;
	int 任务长度;
	LPCWSTR 任务名称;
	LPCWSTR 任务条件;
	int 任务副本;
	int 局部解密;
};

extern 任务结构 任务;

bool 跳过数据();

bool 是否有主线任务();

int 返回主线();

int 返回隐藏();

int 获取任务地图(int 任务编号);

int 任务是否完成(int 对象编号);

int 获取处理方式(int 对象编号);

bool 获取处理结果(int 对象编号);
