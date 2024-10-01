#include"dllmain.h"


int 地图_整理坐标型(vector<坐标型 > map_way_array, vector<坐标型 >& real_map_way)
{
	int x, y;
	int k = 0;
	坐标型  tmp_coordinate;
	for (unsigned int i = 0; i < map_way_array.size(); i++)
	{
		x = (map_way_array[i].x + 2) % 3;
		y = (map_way_array[i].y + 2) % 3;
		if (x == 0 && y == 0)
		{
			tmp_coordinate.x = (map_way_array[i].x + 2) / 3 - 1;
			tmp_coordinate.y = (map_way_array[i].y + 2) / 3 - 1;
			real_map_way.insert(real_map_way.begin() + k, tmp_coordinate);
			k++;
		}
	}
	return(k);
}

void 地图_路径算法(vector<vector<游戏地图>> map_flag, 坐标型  start_point, 坐标型  end_point, int map_width, int map_heigth, vector<坐标型 >& map_way_array)
{
	bool 已存在开放列表, 已存在关闭列表;
	坐标型  待检测坐标型;
	地图节点 待检测节点, 临时节点;
	vector<地图节点> 开放列表, 关闭列表;
	int 最短编号 = 0;
	int 最小F值, 预测G值;
	unsigned int x, y;

	临时节点.当前坐标.x = start_point.x;
	临时节点.当前坐标.y = start_point.y;
	map_flag[start_point.x][start_point.y].背景颜色 = 0x00FF00;
	map_flag[end_point.x][end_point.y].背景颜色 = 0x0000FF;
	开放列表.insert(开放列表.begin(), 临时节点);
	do
	{
		最小F值 = 0;
		for (y = 0; y < 开放列表.size(); y++)
		{
			if (最小F值 == 0)
			{
				最小F值 = 开放列表[0].地图F点;
				最短编号 = y;
			}
			if (开放列表[y].地图F点 < 最小F值)
			{
				最小F值 = 开放列表[y].地图F点;
				最短编号 = y;
			}
		}
		临时节点 = 开放列表[最短编号];
		开放列表.erase(开放列表.begin() + 最短编号);
		关闭列表.insert(关闭列表.begin(), 临时节点);
		if (临时节点.当前坐标.x != start_point.x || 临时节点.当前坐标.y != start_point.y)
		{
			if (临时节点.当前坐标.x != end_point.x || 临时节点.当前坐标.y != end_point.y)
			{
				map_flag[临时节点.当前坐标.x][临时节点.当前坐标.y].背景颜色 = 0x0080FF;
			}
		}
		for (y = 0; y < 关闭列表.size(); y++)
		{
			if (关闭列表[y].当前坐标.x == end_point.x && 关闭列表[y].当前坐标.y == end_point.y)
			{
				待检测节点 = 关闭列表[y];
				do
				{
					for (unsigned int x = 0; x < 关闭列表.size(); x++)
					{
						if (关闭列表[x].当前坐标.x == 待检测节点.最终坐标.x && 关闭列表[x].当前坐标.y == 待检测节点.最终坐标.y)
						{
							待检测节点 = 关闭列表[x];
							break;
						}
					}
					if (待检测节点.当前坐标.x != start_point.x || 待检测节点.当前坐标.y != start_point.y)
					{
						map_flag[待检测节点.当前坐标.x][待检测节点.当前坐标.y].背景颜色 = 0x00D8D8;
						map_way_array.insert(map_way_array.begin(), 待检测节点.当前坐标);
					}
				} while (待检测节点.当前坐标.x != start_point.x || 待检测节点.当前坐标.y != start_point.y);
				map_way_array.insert(map_way_array.begin(), start_point);
				map_way_array.insert(map_way_array.end(), end_point);
				return;
			}
		}
		for (y = 0; y < 4; y++)
		{
			if (y == 0)
			{
				待检测坐标型.x = 临时节点.当前坐标.x;
				待检测坐标型.y = 临时节点.当前坐标.y - 1;
			}
			else if (y == 1)
			{
				待检测坐标型.x = 临时节点.当前坐标.x - 1;
				待检测坐标型.y = 临时节点.当前坐标.y;
			}
			else if (y == 2)
			{
				待检测坐标型.x = 临时节点.当前坐标.x + 1;
				待检测坐标型.y = 临时节点.当前坐标.y;
			}
			else
			{
				待检测坐标型.x = 临时节点.当前坐标.x;
				待检测坐标型.y = 临时节点.当前坐标.y + 1;
			}
			if (待检测坐标型.x < 0 || 待检测坐标型.x >(map_width - 1) || 待检测坐标型.y < 0 || 待检测坐标型.y >(map_heigth - 1))
				continue;
			if (map_flag[待检测坐标型.x][待检测坐标型.y].背景颜色 == 0x000000)
				continue;
			已存在关闭列表 = false;
			for (x = 0; x < 关闭列表.size(); x++)
			{
				if (关闭列表[x].当前坐标.x == 待检测坐标型.x && 关闭列表[x].当前坐标.y == 待检测坐标型.y)
				{
					已存在关闭列表 = true;
					break;
				}
			}
			if (已存在关闭列表)
				continue;
			已存在开放列表 = false;
			for (x = 0; x < 开放列表.size(); x++)
			{
				if (开放列表[x].当前坐标.x == 待检测坐标型.x && 开放列表[x].当前坐标.y == 待检测坐标型.y)
				{
					if (待检测坐标型.x != 临时节点.当前坐标.x || 待检测坐标型.y != 临时节点.当前坐标.y)
						预测G值 = 14;
					else
						预测G值 = 10;
					if (临时节点.地图G点 + 预测G值 < 开放列表[x].地图G点)
						开放列表[x].最终坐标 = 临时节点.当前坐标;
					已存在开放列表 = true;
					break;
				}
			}
			if (已存在开放列表 == false)
			{
				if (待检测坐标型.x == 临时节点.当前坐标.x || 待检测坐标型.y == 临时节点.当前坐标.y)
					预测G值 = 10;
				else
					预测G值 = 14;
				待检测节点.地图G点 = 临时节点.地图G点 + 预测G值;
				待检测节点.地图H点 = abs(end_point.x - 待检测坐标型.x) * 10 + abs(end_point.y - 待检测坐标型.y) * 10;
				待检测节点.地图F点 = 待检测节点.地图G点 + 待检测节点.地图H点;
				待检测节点.当前坐标 = 待检测坐标型;
				待检测节点.最终坐标 = 临时节点.当前坐标;
				开放列表.insert(开放列表.begin(), 待检测节点);
			}
		}
	} while (开放列表.size() != 0);
}

void 地图_显示地图(vector<vector<游戏地图>> map_array, int map_width, int map_heigth, vector<vector<游戏地图>>& map_flag)
{
	map_flag.clear();
	map_flag.resize(static_cast<__int64>(map_width) * 3);
	for (int x = 0; x < map_width * 3; x++)
	{
		map_flag[x].resize(static_cast<__int64>(map_heigth) * 3);
	}
	for (int y = 0; y < map_heigth; y++)
	{
		for (int x = 0; x < map_width; x++)
		{
			map_flag[(static_cast<__int64>(x) + 1) * 3 - 2][(static_cast<__int64>(y) + 1) * 3 - 2].背景颜色 = 0xFFFFFF;
			if (map_array[x][y].地图左边)
				map_flag[(static_cast<__int64>(x) + 1) * 3 - 3][(static_cast<__int64>(y) + 1) * 3 - 2].背景颜色 = 0xFFFFFF;
			if (map_array[x][y].地图右边)
				map_flag[(static_cast<__int64>(x) + 1) * 3 - 1][(static_cast<__int64>(y) + 1) * 3 - 2].背景颜色 = 0xFFFFFF;
			if (map_array[x][y].地图上边)
				map_flag[(static_cast<__int64>(x) + 1) * 3 - 2][(static_cast<__int64>(y) + 1) * 3 - 3].背景颜色 = 0xFFFFFF;
			if (map_array[x][y].地图下边)
				map_flag[(static_cast<__int64>(x) + 1) * 3 - 2][(static_cast<__int64>(y) + 1) * 3 - 1].背景颜色 = 0xFFFFFF;
		}
	}
}

bool 地图_判断方向(int cross_orientation, int orientation)
{
	unsigned char orientation_array[4];
	unsigned char orientation_vector[16][4] = { { 0, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 1, 1, 0 }, { 1, 0, 0, 0 }, { 1, 1, 0, 0 }, { 1, 0, 1, 0 }, { 1, 1, 1, 0 },
   { 0, 0, 0, 1 }, { 0, 1, 0, 1 }, { 0, 0, 1, 1 }, { 0, 1, 1, 1 }, { 1, 0, 0, 1 }, { 1, 1, 0, 1 }, { 1, 0, 1, 1 }, { 1, 1, 1, 1 } };
	if (cross_orientation >= 0 && cross_orientation <= 15)
		for (int i = 0; i < 4; i++)
			orientation_array[i] = orientation_vector[cross_orientation][i];
	else
		for (int i = 0; i < 4; i++)
			orientation_array[i] = 0;
	if (orientation_array[orientation] == 1)
		return true;
	else
		return false;
}

void 地图_生成地图(int map_width, int map_heigth, vector<int> map_cross, vector<vector<游戏地图>>& map_room)
{
	map_room.clear();
	map_room.resize(map_width);
	for (int x = 0; x < map_width; x++)
	{
		map_room[x].resize(map_heigth);
	}
	int i = 0;
	for (int y = 0; y < map_heigth; y++)
	{
		for (int x = 0; x < map_width; x++)
		{
			map_room[x][y].地图坐标.x = x;
			map_room[x][y].地图坐标.y = y;
			map_room[x][y].地图通道 = map_cross[i];
			map_room[x][y].地图左边 = 地图_判断方向(map_cross[i], 0);
			map_room[x][y].地图右边 = 地图_判断方向(map_cross[i], 1);
			map_room[x][y].地图上边 = 地图_判断方向(map_cross[i], 2);
			map_room[x][y].地图下边 = 地图_判断方向(map_cross[i], 3);
			map_room[x][y].背景颜色 = 0xFFFFFF;
			i++;
			if (map_room[x][y].地图通道 == 0)
				map_room[x][y].背景颜色 = 0x000000;
		}
	}
}

int 地图_获取走法(vector<int> map_cross, int map_width, int map_heigth, 坐标型  start_point, 坐标型  end_point, vector<坐标型 >& real_map_way)
{
	坐标型  start_coordinate;
	坐标型  end_coordinate;
	vector<vector<游戏地图>> map_flag;
	vector<vector<游戏地图>> map_array;
	vector<坐标型 > cross_way;

	if (start_point.x == end_point.x && start_point.y == end_point.y)
	{
		real_map_way.clear();
		real_map_way.resize(0);
		return 0;
	}
	地图_生成地图(map_width, map_heigth, map_cross, map_array);
	地图_显示地图(map_array, map_width, map_heigth, map_flag);
	start_coordinate.x = start_point.x * 3 - 2;
	start_coordinate.y = start_point.y * 3 - 2;
	end_coordinate.x = end_point.x * 3 - 2;
	end_coordinate.y = end_point.y * 3 - 2;
	地图_路径算法(map_flag, start_coordinate, end_coordinate, map_width * 3, map_heigth * 3, cross_way);
	return 地图_整理坐标型(cross_way, real_map_way);
}

bool 判断_坐标相等(坐标型 索引A, 坐标型 索引B)
{
	if (索引A.x == 索引B.x && 索引A.y == 索引B.y)
		return true;
	else
		return false;
}

地图数据 获取地图数据()
{

	地图数据  map_data; __int64 地图指针, 宽高指针, tmp_address;
	int  map_count;

	地图指针 = 地图Call(Pack.地图编号);
	宽高指针 = *(__int64*)(地图指针 + 基址::宽高偏移);
	map_data.宽 = *(int*)(宽高指针 + static_cast<__int64>(Pack.地图序号) * 8);
	map_data.高 = *(int*)(宽高指针 + static_cast<__int64>(Pack.地图序号) * 8 + 4);
	tmp_address = *(__int64*)(地图指针 + 基址::数组偏移);
	tmp_address = *(__int64*)(tmp_address + static_cast<__int64>(Pack.地图序号) * 32 + 8);
	map_count = map_data.宽 * map_data.高;
	for (int i = 0; i < map_count; i++)
	{
		map_data.地图通道.insert(map_data.地图通道.begin() + i, *(int*)(tmp_address + static_cast<__int64>(i) * 4));
	}
	map_data.起始坐标.x = Pack.当前坐标.x + 1;
	map_data.起始坐标.y = Pack.当前坐标.y + 1;
	map_data.终点坐标.x = Pack.领主坐标.x + 1;
	map_data.终点坐标.y = Pack.领主坐标.y + 1;
	map_data.消耗疲劳 = 地图_获取走法(map_data.地图通道, map_data.宽, map_data.高, map_data.起始坐标, map_data.终点坐标, map_data.地图走法);
	if (判断_坐标相等(map_data.起始坐标, map_data.终点坐标) == true)
		return map_data;
	return map_data;
}

int 顺图方向()
{
	int x, y;
	地图数据 Map_Data;
	Map_Data = 获取地图数据();
	if (Map_Data.消耗疲劳 < 1)
		return 0;
	x = Map_Data.地图走法[0].x - Map_Data.地图走法[1].x; //1 - 2
	y = Map_Data.地图走法[0].y - Map_Data.地图走法[1].y; //1 - 2
	if (x == 0)
	{
		if (y == 1)
			return 2;//上
		else
			return 3;//下
	}
	else if (y == 0)
	{
		if (x == 1)
			return 0;//左
		else
			return 1;//右
	}
	return 0;
}


/*------------------------------未央全图寻路----------------------------------------------------*/

static int 顺图变量;


int 未央全图()
{
	if (寻找文本(Pack.地图名称, L"残月宫阙") != 0)
	{
		if (提取数字并转换(Pack.地图名称) <= 5) return 残月宫阙1至5阶();

		if (提取数字并转换(Pack.地图名称) <= 10) return 残月宫阙6至10阶();

		if (提取数字并转换(Pack.地图名称) > 10) return 0;

	}
	if (寻找文本(Pack.地图名称, L"沧池竹林") != 0)
	{
		if (提取数字并转换(Pack.地图名称) <= 5) return 沧池竹林1至5阶();

		if (提取数字并转换(Pack.地图名称) <= 10) return 沧池竹林6至10阶();

		if (提取数字并转换(Pack.地图名称) > 10) return 0;

	}
	if (寻找文本(Pack.地图名称, L"幻境前殿") != 0)
	{
		if (提取数字并转换(Pack.地图名称) <= 5) return 幻境前殿1至5阶();

		if (提取数字并转换(Pack.地图名称) <= 10)return 幻境前殿6至10阶();

		if (提取数字并转换(Pack.地图名称) > 10) return 0;

	}
	if (寻找文本(Pack.地图名称, L"未央之脊") != 0)
	{
		if (提取数字并转换(Pack.地图名称) <= 5) return 未央之脊1至5阶();

		if (提取数字并转换(Pack.地图名称) <= 10)return 未央之脊6至10阶();

		if (提取数字并转换(Pack.地图名称) > 10) return 0;

	}
	公告(L"数据暂无匹配，请联系销售处理");
	return 顺图方向();
}

int 残月宫阙1至5阶()
{
	switch (Pack.当前坐标.x)
	{
	case 0:
		if (Pack.当前坐标.y == 1)
		{
			顺图变量 = 1;
			return 1; // 右
		}
	case 1:
		if (Pack.当前坐标.y == 0) return 1; // 右
		if (Pack.当前坐标.y == 1 && 顺图变量 == 1) return 3; // 下
		if (Pack.当前坐标.y == 2)
		{
			顺图变量 = 2;
			return 2; // 上
		}
		if (Pack.当前坐标.y == 1 && 顺图变量 == 2) return 1; // 右
		if (Pack.当前坐标.y == 1 && 顺图变量 == 3) return 2; // 上
	case 2:
		if (Pack.当前坐标.y == 0) return 1; // 右
		if (Pack.当前坐标.y == 1)
		{
			顺图变量 = 3;
			return 0; // 左
		}
	case 3:
		if (Pack.当前坐标.y == 0) return 3; // 下
	}
	// 如果没有匹配的条件，可以返回一个默认值或抛出异常
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int 沧池竹林1至5阶()
{
	switch (Pack.当前坐标.x) {
	case 0:
		if (Pack.当前坐标.y == 1) return 1; // 右
	case 1:
		if (Pack.当前坐标.y == 1) return 2; // 上
		if (Pack.当前坐标.y == 0) return 1; // 右
	case 2:
		if (Pack.当前坐标.y == 0) return 3; // 下
		if (Pack.当前坐标.y == 1 && 顺图变量 == 1) return 1; // 右
		if (Pack.当前坐标.y == 1) return 3; // 下
		if (Pack.当前坐标.y == 2)
		{
			顺图变量 = 1;
			return 2; // 上
		}
	}
	// 如果没有匹配的条件，可以返回一个默认值或抛出异常
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int 幻境前殿1至5阶()
{
	switch (Pack.当前坐标.x) {
	case 0:
		if (Pack.当前坐标.y == 1)
		{
			顺图变量 = 1;
			return 1; // 右
		}
		break;
	case 1:
		switch (Pack.当前坐标.y)
		{
		case 1:
			if (顺图变量 == 1)
			{
				return 3; // 下
			}
			if (顺图变量 == 2)
			{
				return 1; // 右
			}
		case 2:
			顺图变量 = 2;
			return 2; // 上
		}
		break;
	case 2:
		switch (Pack.当前坐标.y)
		{
		case 0:
			顺图变量 = 3;
			return 3; // 下
		case 1:
			if (顺图变量 == 2) return 2; // 上
			if (顺图变量 == 3) return 1; // 右
		}
	}
	// 如果没有匹配的条件，可以返回一个默认值或抛出异常
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int 未央之脊1至5阶()
{
	switch (Pack.当前坐标.x)
	{
	case 0:
		if (Pack.当前坐标.y == 1) 顺图变量 = 1; return 1; // 右
		break;
	case 1:
		if (Pack.当前坐标.y == 1) return 1; // 右
	case 2:
		if (Pack.当前坐标.y == 1) return 1; // 右
	case 3:
		if (Pack.当前坐标.y == 1 && 顺图变量 == 1) return 2; // 上
		if (Pack.当前坐标.y == 0)
		{
			顺图变量 = 2;
			return 3; // 下
		}
		if (Pack.当前坐标.y == 1 && 顺图变量 == 2) return 1; // 右
	}
	// 如果没有匹配的条件，可以返回一个默认值或抛出异常
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int 残月宫阙6至10阶()
{
	switch (Pack.当前坐标.x)
	{
	case 0:
		if (Pack.当前坐标.y == 1)
		{
			顺图变量 = 1;
			return 1; // 右
		}
	case 1:
		if (Pack.当前坐标.y == 1 && 顺图变量 == 1) return 3; // 下
		if (Pack.当前坐标.y == 2)
		{
			顺图变量 = 2;
			return 2; // 上
		}
		if (Pack.当前坐标.y == 1 && 顺图变量 == 2) return 1; // 右
		if (Pack.当前坐标.y == 1 && 顺图变量 == 3) return 2; // 上
		if (Pack.当前坐标.y == 0)
		{
			顺图变量 = 4;
			return 1; // 右
		}
	case 2:
		if (Pack.当前坐标.y == 1 && 顺图变量 == 2) return 3; // 下
		if (Pack.当前坐标.y == 2)
		{
			顺图变量 = 3;
			return 2; // 上
		}
		if (Pack.当前坐标.y == 1 && 顺图变量 == 3) return 0; // 左
		if (Pack.当前坐标.y == 0)  return 1; // 右
	case 3:
		if (Pack.当前坐标.y == 0 && 顺图变量 == 4) return 1; // 右
		if (Pack.当前坐标.y == 0 && 顺图变量 == 5) return 3; // 下
	case 4:
		if (Pack.当前坐标.y == 0)
		{
			顺图变量 = 5;
			return 0; // 左
		}
	}
	// 如果没有匹配的条件，可以返回一个默认值或抛出异常
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int 沧池竹林6至10阶()
{
	switch (Pack.当前坐标.x)
	{
	case 0:
		if (Pack.当前坐标.y == 1) return 1; // 右
	case 1:
		if (Pack.当前坐标.y == 1) return 2; // 上
		if (Pack.当前坐标.y == 0)
		{
			顺图变量 = 1;
			return 1; // 右
		}
	case 2:
		if (Pack.当前坐标.y == 0) return 1; // 右
		if (Pack.当前坐标.y == 1)
		{
			顺图变量 = 3;
			return 1; // 右
		}
	case 3:
		if (Pack.当前坐标.y == 0) return 3; // 下
		if (Pack.当前坐标.y == 1 && 顺图变量 == 1) return 3; // 下
		if (Pack.当前坐标.y == 2)
		{
			顺图变量 = 2;
			return 2; // 上
		}
		if (Pack.当前坐标.y == 1 && 顺图变量 == 2) return 0; // 左
		if (Pack.当前坐标.y == 1 && 顺图变量 == 3) return 1; // 右
	}
	// 如果没有匹配的条件，可以返回一个默认值或抛出异常
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int 幻境前殿6至10阶()
{
	switch (Pack.当前坐标.x) {
	case 0:
		if (Pack.当前坐标.y == 1) {
			顺图变量 = 1;
			return 1; // 右完善
		}
	case 1:
		if (Pack.当前坐标.y == 0)
		{
			顺图变量 = 4;
			return 1; // 右
		}
		if (Pack.当前坐标.y == 1 && 顺图变量 == 1) return 3; // 下完善
		if (Pack.当前坐标.y == 1 && 顺图变量 == 2) return 1; // 右
		{
			顺图变量 = 3;
			return 1; // 右
		}
		if (Pack.当前坐标.y == 2 && 顺图变量 == 1) return 1; // 右完善
		if (Pack.当前坐标.y == 2 && 顺图变量 == 2) return 2; // 上完善
	case 2:
		if (Pack.当前坐标.y == 0 && 顺图变量 == 4) return 3; // 下
		if (Pack.当前坐标.y == 0 && 顺图变量 == 3) return 0; // 左
		if (Pack.当前坐标.y == 1 && 顺图变量 == 4) return 1; // 右
		if (Pack.当前坐标.y == 1 && 顺图变量 == 3) return 2; // 上
		if (Pack.当前坐标.y == 2)
		{
			顺图变量 = 2;
			return 0; // 左
		}
	}

	// 如果没有匹配的条件，返回-1或抛出异常
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int 未央之脊6至10阶()
{
	switch (Pack.当前坐标.x) {
	case 0:
		if (Pack.当前坐标.y == 1) {
			顺图变量 = 1;
			return 1;// 右
		}
	case 1:
		if (Pack.当前坐标.y == 1) {
			return 1;// 右
		}
	case 2:
		if (Pack.当前坐标.y == 1 && 顺图变量 == 1) return 3; // 下
		if (Pack.当前坐标.y == 1 && 顺图变量 == 2) return 1; // 右
		if (Pack.当前坐标.y == 2)
		{
			顺图变量 = 2;
			return 2;// 上
		}
	case 3:
		if (Pack.当前坐标.y == 1) {
			return 1;// 右
		}
	case 4:
		if (Pack.当前坐标.y == 0)
		{
			顺图变量 = 3;
			return 3; // 下
		}
		if (Pack.当前坐标.y == 1 && 顺图变量 == 2) return 2; // 上
		if (Pack.当前坐标.y == 1 && 顺图变量 == 3) return 1; // 右
	}

	// 如果没有匹配的条件，返回-1或抛出异常
	throw std::runtime_error("Invalid coordinates or state encountered.");
}