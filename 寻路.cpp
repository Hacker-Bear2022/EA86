#include"dllmain.h"


int ��ͼ_����������(vector<������ > map_way_array, vector<������ >& real_map_way)
{
	int x, y;
	int k = 0;
	������  tmp_coordinate;
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

void ��ͼ_·���㷨(vector<vector<��Ϸ��ͼ>> map_flag, ������  start_point, ������  end_point, int map_width, int map_heigth, vector<������ >& map_way_array)
{
	bool �Ѵ��ڿ����б�, �Ѵ��ڹر��б�;
	������  �����������;
	��ͼ�ڵ� �����ڵ�, ��ʱ�ڵ�;
	vector<��ͼ�ڵ�> �����б�, �ر��б�;
	int ��̱�� = 0;
	int ��СFֵ, Ԥ��Gֵ;
	unsigned int x, y;

	��ʱ�ڵ�.��ǰ����.x = start_point.x;
	��ʱ�ڵ�.��ǰ����.y = start_point.y;
	map_flag[start_point.x][start_point.y].������ɫ = 0x00FF00;
	map_flag[end_point.x][end_point.y].������ɫ = 0x0000FF;
	�����б�.insert(�����б�.begin(), ��ʱ�ڵ�);
	do
	{
		��СFֵ = 0;
		for (y = 0; y < �����б�.size(); y++)
		{
			if (��СFֵ == 0)
			{
				��СFֵ = �����б�[0].��ͼF��;
				��̱�� = y;
			}
			if (�����б�[y].��ͼF�� < ��СFֵ)
			{
				��СFֵ = �����б�[y].��ͼF��;
				��̱�� = y;
			}
		}
		��ʱ�ڵ� = �����б�[��̱��];
		�����б�.erase(�����б�.begin() + ��̱��);
		�ر��б�.insert(�ر��б�.begin(), ��ʱ�ڵ�);
		if (��ʱ�ڵ�.��ǰ����.x != start_point.x || ��ʱ�ڵ�.��ǰ����.y != start_point.y)
		{
			if (��ʱ�ڵ�.��ǰ����.x != end_point.x || ��ʱ�ڵ�.��ǰ����.y != end_point.y)
			{
				map_flag[��ʱ�ڵ�.��ǰ����.x][��ʱ�ڵ�.��ǰ����.y].������ɫ = 0x0080FF;
			}
		}
		for (y = 0; y < �ر��б�.size(); y++)
		{
			if (�ر��б�[y].��ǰ����.x == end_point.x && �ر��б�[y].��ǰ����.y == end_point.y)
			{
				�����ڵ� = �ر��б�[y];
				do
				{
					for (unsigned int x = 0; x < �ر��б�.size(); x++)
					{
						if (�ر��б�[x].��ǰ����.x == �����ڵ�.��������.x && �ر��б�[x].��ǰ����.y == �����ڵ�.��������.y)
						{
							�����ڵ� = �ر��б�[x];
							break;
						}
					}
					if (�����ڵ�.��ǰ����.x != start_point.x || �����ڵ�.��ǰ����.y != start_point.y)
					{
						map_flag[�����ڵ�.��ǰ����.x][�����ڵ�.��ǰ����.y].������ɫ = 0x00D8D8;
						map_way_array.insert(map_way_array.begin(), �����ڵ�.��ǰ����);
					}
				} while (�����ڵ�.��ǰ����.x != start_point.x || �����ڵ�.��ǰ����.y != start_point.y);
				map_way_array.insert(map_way_array.begin(), start_point);
				map_way_array.insert(map_way_array.end(), end_point);
				return;
			}
		}
		for (y = 0; y < 4; y++)
		{
			if (y == 0)
			{
				�����������.x = ��ʱ�ڵ�.��ǰ����.x;
				�����������.y = ��ʱ�ڵ�.��ǰ����.y - 1;
			}
			else if (y == 1)
			{
				�����������.x = ��ʱ�ڵ�.��ǰ����.x - 1;
				�����������.y = ��ʱ�ڵ�.��ǰ����.y;
			}
			else if (y == 2)
			{
				�����������.x = ��ʱ�ڵ�.��ǰ����.x + 1;
				�����������.y = ��ʱ�ڵ�.��ǰ����.y;
			}
			else
			{
				�����������.x = ��ʱ�ڵ�.��ǰ����.x;
				�����������.y = ��ʱ�ڵ�.��ǰ����.y + 1;
			}
			if (�����������.x < 0 || �����������.x >(map_width - 1) || �����������.y < 0 || �����������.y >(map_heigth - 1))
				continue;
			if (map_flag[�����������.x][�����������.y].������ɫ == 0x000000)
				continue;
			�Ѵ��ڹر��б� = false;
			for (x = 0; x < �ر��б�.size(); x++)
			{
				if (�ر��б�[x].��ǰ����.x == �����������.x && �ر��б�[x].��ǰ����.y == �����������.y)
				{
					�Ѵ��ڹر��б� = true;
					break;
				}
			}
			if (�Ѵ��ڹر��б�)
				continue;
			�Ѵ��ڿ����б� = false;
			for (x = 0; x < �����б�.size(); x++)
			{
				if (�����б�[x].��ǰ����.x == �����������.x && �����б�[x].��ǰ����.y == �����������.y)
				{
					if (�����������.x != ��ʱ�ڵ�.��ǰ����.x || �����������.y != ��ʱ�ڵ�.��ǰ����.y)
						Ԥ��Gֵ = 14;
					else
						Ԥ��Gֵ = 10;
					if (��ʱ�ڵ�.��ͼG�� + Ԥ��Gֵ < �����б�[x].��ͼG��)
						�����б�[x].�������� = ��ʱ�ڵ�.��ǰ����;
					�Ѵ��ڿ����б� = true;
					break;
				}
			}
			if (�Ѵ��ڿ����б� == false)
			{
				if (�����������.x == ��ʱ�ڵ�.��ǰ����.x || �����������.y == ��ʱ�ڵ�.��ǰ����.y)
					Ԥ��Gֵ = 10;
				else
					Ԥ��Gֵ = 14;
				�����ڵ�.��ͼG�� = ��ʱ�ڵ�.��ͼG�� + Ԥ��Gֵ;
				�����ڵ�.��ͼH�� = abs(end_point.x - �����������.x) * 10 + abs(end_point.y - �����������.y) * 10;
				�����ڵ�.��ͼF�� = �����ڵ�.��ͼG�� + �����ڵ�.��ͼH��;
				�����ڵ�.��ǰ���� = �����������;
				�����ڵ�.�������� = ��ʱ�ڵ�.��ǰ����;
				�����б�.insert(�����б�.begin(), �����ڵ�);
			}
		}
	} while (�����б�.size() != 0);
}

void ��ͼ_��ʾ��ͼ(vector<vector<��Ϸ��ͼ>> map_array, int map_width, int map_heigth, vector<vector<��Ϸ��ͼ>>& map_flag)
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
			map_flag[(static_cast<__int64>(x) + 1) * 3 - 2][(static_cast<__int64>(y) + 1) * 3 - 2].������ɫ = 0xFFFFFF;
			if (map_array[x][y].��ͼ���)
				map_flag[(static_cast<__int64>(x) + 1) * 3 - 3][(static_cast<__int64>(y) + 1) * 3 - 2].������ɫ = 0xFFFFFF;
			if (map_array[x][y].��ͼ�ұ�)
				map_flag[(static_cast<__int64>(x) + 1) * 3 - 1][(static_cast<__int64>(y) + 1) * 3 - 2].������ɫ = 0xFFFFFF;
			if (map_array[x][y].��ͼ�ϱ�)
				map_flag[(static_cast<__int64>(x) + 1) * 3 - 2][(static_cast<__int64>(y) + 1) * 3 - 3].������ɫ = 0xFFFFFF;
			if (map_array[x][y].��ͼ�±�)
				map_flag[(static_cast<__int64>(x) + 1) * 3 - 2][(static_cast<__int64>(y) + 1) * 3 - 1].������ɫ = 0xFFFFFF;
		}
	}
}

bool ��ͼ_�жϷ���(int cross_orientation, int orientation)
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

void ��ͼ_���ɵ�ͼ(int map_width, int map_heigth, vector<int> map_cross, vector<vector<��Ϸ��ͼ>>& map_room)
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
			map_room[x][y].��ͼ����.x = x;
			map_room[x][y].��ͼ����.y = y;
			map_room[x][y].��ͼͨ�� = map_cross[i];
			map_room[x][y].��ͼ��� = ��ͼ_�жϷ���(map_cross[i], 0);
			map_room[x][y].��ͼ�ұ� = ��ͼ_�жϷ���(map_cross[i], 1);
			map_room[x][y].��ͼ�ϱ� = ��ͼ_�жϷ���(map_cross[i], 2);
			map_room[x][y].��ͼ�±� = ��ͼ_�жϷ���(map_cross[i], 3);
			map_room[x][y].������ɫ = 0xFFFFFF;
			i++;
			if (map_room[x][y].��ͼͨ�� == 0)
				map_room[x][y].������ɫ = 0x000000;
		}
	}
}

int ��ͼ_��ȡ�߷�(vector<int> map_cross, int map_width, int map_heigth, ������  start_point, ������  end_point, vector<������ >& real_map_way)
{
	������  start_coordinate;
	������  end_coordinate;
	vector<vector<��Ϸ��ͼ>> map_flag;
	vector<vector<��Ϸ��ͼ>> map_array;
	vector<������ > cross_way;

	if (start_point.x == end_point.x && start_point.y == end_point.y)
	{
		real_map_way.clear();
		real_map_way.resize(0);
		return 0;
	}
	��ͼ_���ɵ�ͼ(map_width, map_heigth, map_cross, map_array);
	��ͼ_��ʾ��ͼ(map_array, map_width, map_heigth, map_flag);
	start_coordinate.x = start_point.x * 3 - 2;
	start_coordinate.y = start_point.y * 3 - 2;
	end_coordinate.x = end_point.x * 3 - 2;
	end_coordinate.y = end_point.y * 3 - 2;
	��ͼ_·���㷨(map_flag, start_coordinate, end_coordinate, map_width * 3, map_heigth * 3, cross_way);
	return ��ͼ_����������(cross_way, real_map_way);
}

bool �ж�_�������(������ ����A, ������ ����B)
{
	if (����A.x == ����B.x && ����A.y == ����B.y)
		return true;
	else
		return false;
}

��ͼ���� ��ȡ��ͼ����()
{

	��ͼ����  map_data; __int64 ��ͼָ��, ���ָ��, tmp_address;
	int  map_count;

	��ͼָ�� = ��ͼCall(Pack.��ͼ���);
	���ָ�� = *(__int64*)(��ͼָ�� + ��ַ::���ƫ��);
	map_data.�� = *(int*)(���ָ�� + static_cast<__int64>(Pack.��ͼ���) * 8);
	map_data.�� = *(int*)(���ָ�� + static_cast<__int64>(Pack.��ͼ���) * 8 + 4);
	tmp_address = *(__int64*)(��ͼָ�� + ��ַ::����ƫ��);
	tmp_address = *(__int64*)(tmp_address + static_cast<__int64>(Pack.��ͼ���) * 32 + 8);
	map_count = map_data.�� * map_data.��;
	for (int i = 0; i < map_count; i++)
	{
		map_data.��ͼͨ��.insert(map_data.��ͼͨ��.begin() + i, *(int*)(tmp_address + static_cast<__int64>(i) * 4));
	}
	map_data.��ʼ����.x = Pack.��ǰ����.x + 1;
	map_data.��ʼ����.y = Pack.��ǰ����.y + 1;
	map_data.�յ�����.x = Pack.��������.x + 1;
	map_data.�յ�����.y = Pack.��������.y + 1;
	map_data.����ƣ�� = ��ͼ_��ȡ�߷�(map_data.��ͼͨ��, map_data.��, map_data.��, map_data.��ʼ����, map_data.�յ�����, map_data.��ͼ�߷�);
	if (�ж�_�������(map_data.��ʼ����, map_data.�յ�����) == true)
		return map_data;
	return map_data;
}

int ˳ͼ����()
{
	int x, y;
	��ͼ���� Map_Data;
	Map_Data = ��ȡ��ͼ����();
	if (Map_Data.����ƣ�� < 1)
		return 0;
	x = Map_Data.��ͼ�߷�[0].x - Map_Data.��ͼ�߷�[1].x; //1 - 2
	y = Map_Data.��ͼ�߷�[0].y - Map_Data.��ͼ�߷�[1].y; //1 - 2
	if (x == 0)
	{
		if (y == 1)
			return 2;//��
		else
			return 3;//��
	}
	else if (y == 0)
	{
		if (x == 1)
			return 0;//��
		else
			return 1;//��
	}
	return 0;
}


/*------------------------------δ��ȫͼѰ·----------------------------------------------------*/

static int ˳ͼ����;


int δ��ȫͼ()
{
	if (Ѱ���ı�(Pack.��ͼ����, L"���¹���") != 0)
	{
		if (��ȡ���ֲ�ת��(Pack.��ͼ����) <= 5) return ���¹���1��5��();

		if (��ȡ���ֲ�ת��(Pack.��ͼ����) <= 10) return ���¹���6��10��();

		if (��ȡ���ֲ�ת��(Pack.��ͼ����) > 10) return 0;

	}
	if (Ѱ���ı�(Pack.��ͼ����, L"�׳�����") != 0)
	{
		if (��ȡ���ֲ�ת��(Pack.��ͼ����) <= 5) return �׳�����1��5��();

		if (��ȡ���ֲ�ת��(Pack.��ͼ����) <= 10) return �׳�����6��10��();

		if (��ȡ���ֲ�ת��(Pack.��ͼ����) > 10) return 0;

	}
	if (Ѱ���ı�(Pack.��ͼ����, L"�þ�ǰ��") != 0)
	{
		if (��ȡ���ֲ�ת��(Pack.��ͼ����) <= 5) return �þ�ǰ��1��5��();

		if (��ȡ���ֲ�ת��(Pack.��ͼ����) <= 10)return �þ�ǰ��6��10��();

		if (��ȡ���ֲ�ת��(Pack.��ͼ����) > 10) return 0;

	}
	if (Ѱ���ı�(Pack.��ͼ����, L"δ��֮��") != 0)
	{
		if (��ȡ���ֲ�ת��(Pack.��ͼ����) <= 5) return δ��֮��1��5��();

		if (��ȡ���ֲ�ת��(Pack.��ͼ����) <= 10)return δ��֮��6��10��();

		if (��ȡ���ֲ�ת��(Pack.��ͼ����) > 10) return 0;

	}
	����(L"��������ƥ�䣬����ϵ���۴���");
	return ˳ͼ����();
}

int ���¹���1��5��()
{
	switch (Pack.��ǰ����.x)
	{
	case 0:
		if (Pack.��ǰ����.y == 1)
		{
			˳ͼ���� = 1;
			return 1; // ��
		}
	case 1:
		if (Pack.��ǰ����.y == 0) return 1; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 1) return 3; // ��
		if (Pack.��ǰ����.y == 2)
		{
			˳ͼ���� = 2;
			return 2; // ��
		}
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 2) return 1; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 3) return 2; // ��
	case 2:
		if (Pack.��ǰ����.y == 0) return 1; // ��
		if (Pack.��ǰ����.y == 1)
		{
			˳ͼ���� = 3;
			return 0; // ��
		}
	case 3:
		if (Pack.��ǰ����.y == 0) return 3; // ��
	}
	// ���û��ƥ������������Է���һ��Ĭ��ֵ���׳��쳣
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int �׳�����1��5��()
{
	switch (Pack.��ǰ����.x) {
	case 0:
		if (Pack.��ǰ����.y == 1) return 1; // ��
	case 1:
		if (Pack.��ǰ����.y == 1) return 2; // ��
		if (Pack.��ǰ����.y == 0) return 1; // ��
	case 2:
		if (Pack.��ǰ����.y == 0) return 3; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 1) return 1; // ��
		if (Pack.��ǰ����.y == 1) return 3; // ��
		if (Pack.��ǰ����.y == 2)
		{
			˳ͼ���� = 1;
			return 2; // ��
		}
	}
	// ���û��ƥ������������Է���һ��Ĭ��ֵ���׳��쳣
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int �þ�ǰ��1��5��()
{
	switch (Pack.��ǰ����.x) {
	case 0:
		if (Pack.��ǰ����.y == 1)
		{
			˳ͼ���� = 1;
			return 1; // ��
		}
		break;
	case 1:
		switch (Pack.��ǰ����.y)
		{
		case 1:
			if (˳ͼ���� == 1)
			{
				return 3; // ��
			}
			if (˳ͼ���� == 2)
			{
				return 1; // ��
			}
		case 2:
			˳ͼ���� = 2;
			return 2; // ��
		}
		break;
	case 2:
		switch (Pack.��ǰ����.y)
		{
		case 0:
			˳ͼ���� = 3;
			return 3; // ��
		case 1:
			if (˳ͼ���� == 2) return 2; // ��
			if (˳ͼ���� == 3) return 1; // ��
		}
	}
	// ���û��ƥ������������Է���һ��Ĭ��ֵ���׳��쳣
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int δ��֮��1��5��()
{
	switch (Pack.��ǰ����.x)
	{
	case 0:
		if (Pack.��ǰ����.y == 1) ˳ͼ���� = 1; return 1; // ��
		break;
	case 1:
		if (Pack.��ǰ����.y == 1) return 1; // ��
	case 2:
		if (Pack.��ǰ����.y == 1) return 1; // ��
	case 3:
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 1) return 2; // ��
		if (Pack.��ǰ����.y == 0)
		{
			˳ͼ���� = 2;
			return 3; // ��
		}
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 2) return 1; // ��
	}
	// ���û��ƥ������������Է���һ��Ĭ��ֵ���׳��쳣
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int ���¹���6��10��()
{
	switch (Pack.��ǰ����.x)
	{
	case 0:
		if (Pack.��ǰ����.y == 1)
		{
			˳ͼ���� = 1;
			return 1; // ��
		}
	case 1:
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 1) return 3; // ��
		if (Pack.��ǰ����.y == 2)
		{
			˳ͼ���� = 2;
			return 2; // ��
		}
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 2) return 1; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 3) return 2; // ��
		if (Pack.��ǰ����.y == 0)
		{
			˳ͼ���� = 4;
			return 1; // ��
		}
	case 2:
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 2) return 3; // ��
		if (Pack.��ǰ����.y == 2)
		{
			˳ͼ���� = 3;
			return 2; // ��
		}
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 3) return 0; // ��
		if (Pack.��ǰ����.y == 0)  return 1; // ��
	case 3:
		if (Pack.��ǰ����.y == 0 && ˳ͼ���� == 4) return 1; // ��
		if (Pack.��ǰ����.y == 0 && ˳ͼ���� == 5) return 3; // ��
	case 4:
		if (Pack.��ǰ����.y == 0)
		{
			˳ͼ���� = 5;
			return 0; // ��
		}
	}
	// ���û��ƥ������������Է���һ��Ĭ��ֵ���׳��쳣
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int �׳�����6��10��()
{
	switch (Pack.��ǰ����.x)
	{
	case 0:
		if (Pack.��ǰ����.y == 1) return 1; // ��
	case 1:
		if (Pack.��ǰ����.y == 1) return 2; // ��
		if (Pack.��ǰ����.y == 0)
		{
			˳ͼ���� = 1;
			return 1; // ��
		}
	case 2:
		if (Pack.��ǰ����.y == 0) return 1; // ��
		if (Pack.��ǰ����.y == 1)
		{
			˳ͼ���� = 3;
			return 1; // ��
		}
	case 3:
		if (Pack.��ǰ����.y == 0) return 3; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 1) return 3; // ��
		if (Pack.��ǰ����.y == 2)
		{
			˳ͼ���� = 2;
			return 2; // ��
		}
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 2) return 0; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 3) return 1; // ��
	}
	// ���û��ƥ������������Է���һ��Ĭ��ֵ���׳��쳣
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int �þ�ǰ��6��10��()
{
	switch (Pack.��ǰ����.x) {
	case 0:
		if (Pack.��ǰ����.y == 1) {
			˳ͼ���� = 1;
			return 1; // ������
		}
	case 1:
		if (Pack.��ǰ����.y == 0)
		{
			˳ͼ���� = 4;
			return 1; // ��
		}
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 1) return 3; // ������
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 2) return 1; // ��
		{
			˳ͼ���� = 3;
			return 1; // ��
		}
		if (Pack.��ǰ����.y == 2 && ˳ͼ���� == 1) return 1; // ������
		if (Pack.��ǰ����.y == 2 && ˳ͼ���� == 2) return 2; // ������
	case 2:
		if (Pack.��ǰ����.y == 0 && ˳ͼ���� == 4) return 3; // ��
		if (Pack.��ǰ����.y == 0 && ˳ͼ���� == 3) return 0; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 4) return 1; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 3) return 2; // ��
		if (Pack.��ǰ����.y == 2)
		{
			˳ͼ���� = 2;
			return 0; // ��
		}
	}

	// ���û��ƥ�������������-1���׳��쳣
	throw std::runtime_error("Invalid coordinates or state encountered.");
}

int δ��֮��6��10��()
{
	switch (Pack.��ǰ����.x) {
	case 0:
		if (Pack.��ǰ����.y == 1) {
			˳ͼ���� = 1;
			return 1;// ��
		}
	case 1:
		if (Pack.��ǰ����.y == 1) {
			return 1;// ��
		}
	case 2:
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 1) return 3; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 2) return 1; // ��
		if (Pack.��ǰ����.y == 2)
		{
			˳ͼ���� = 2;
			return 2;// ��
		}
	case 3:
		if (Pack.��ǰ����.y == 1) {
			return 1;// ��
		}
	case 4:
		if (Pack.��ǰ����.y == 0)
		{
			˳ͼ���� = 3;
			return 3; // ��
		}
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 2) return 2; // ��
		if (Pack.��ǰ����.y == 1 && ˳ͼ���� == 3) return 1; // ��
	}

	// ���û��ƥ�������������-1���׳��쳣
	throw std::runtime_error("Invalid coordinates or state encountered.");
}