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

void ����(std::wstring ����, int ����)
{
	
	LPCWSTR TempStr;
	���� = L"EA86:" + ���� + L" ";
	TempStr = ����.c_str();
	ULONG64 ��������[100] = { NULL };
	*(ULONG64*)((ULONG64)�������� + 8) = (ULONG64)TempStr;
	*(ULONG64*)((ULONG64)�������� + 28) = -1;
	*(ULONG64*)((ULONG64)�������� + 32) = ��ַ::ǳ��ɫ��ַ;  //��ɫA
	if (���� == 1)
	{
		*(ULONG64*)((ULONG64)�������� + 36) = 17;  //ϵͳ
	}
	if (���� == 0)
	{
		*(ULONG64*)((ULONG64)�������� + 36) = 38;  //�����
	}

	*(ULONG64*)((ULONG64)�������� + 108) = 55512;//��ɫB
	EA8_CALL(��ַ::��CALL, (ULONG64)��������);
}


void ͸��call()
{
	ULONG64 ����ָ�� = ��������(��ַ::�����ַB);
	EA8_CALL(��ַ::͸��CALL, ����ָ��, 1, 1, 1);
}

__int64 ��ͼCall(__int32 ��ͼ���)
{
	return EA8_CALL(��ַ::��ͼCALL, ��ͼ���);
}

ULONG64 ����CALL(int ����)
{
	return EA8_CALL(��ַ::�򿪽���CALL, ��������(��ַ::�̵��ַ), ����);
}

void �򿪽���Call(int �������)//10 ������ 13������ 22���ؽ�ɫ
{
	EA8_CALL(��ַ::����CALL, ��������(��ַ::����_Rcx), �������);
}

void �������CALL(int ����λ��,int ��ӱ���)//��ӱ���=1װ��  ��ӱ���=48˾��
{
	EA8_CALL(��ַ::���CALL, ����CALL(��ַ::�ϼܻ���ID), ��ӱ���, ����λ��, 1);
}

void �����ϼ�CALL(int �ϼܽ��)
{
	EA8_CALL(0x145A45440, ��������(0x14CD89510), 0xFFFFFFFF, �ϼܽ��, �ϼܽ��);
}

void ���Call(ULONG64 ��Ʒָ��, int ��Ʒ��ַ)
{

	EA8_CALL(��ַ::һ���ֽ����, ��Ʒָ��, ��Ʒ��ַ, 319);//317����ֽ��  319ϵͳ�ֽ��
}

void �ֽ�Call(ULONG64 ��Ʒָ��)
{
	EA8_CALL(��ַ::�ֽ�CALL, ��������(��Ʒָ��), 65535, 319);//317����ֽ��  319ϵͳ�ֽ��
}

void ���˾��(int ˾��_��)
{
	ULONGLONG ����ָ�� = EA8_CALL(��ַ::�򿪽���CALL, ��������(��ַ::�̵��ַ));
	EA8_CALL(��ַ::˾�����CALL, ����ָ��, ˾��_��);
}

void ˾���볡(int ˾��_��)
{
	EA8_CALL(��ַ::˾�Ͻ�ͼCALL, ��������(��ַ::˾�Ͻ�ͼ_Rcx), ˾��_��);
}

void ����Call()
{
	EA8_CALL(��ַ::����CALL_1, *(__int64*)��ַ::�سǲ���);
	EA8_CALL(��ַ::����CALL_2, *(__int64*)��ַ::�سǲ���, 0, rand() % 5);
	EA8_CALL(��ַ::���ٷ���CALL, *(__int64*)��ַ::�سǲ���);
}

void ѡͼCall()
{
	EA8_CALL(��ַ::ѡͼCALL, *(__int64*)��ַ::��ɫָ��);
}

void �س�Call(__int32 �س�λ��)//0�ٴ� 1���� 2�س�
{
	EA8_CALL(��ַ::�س�CALL, *(__int64*)��ַ::�سǲ���, �س�λ��, 1, 1);
}

void ʰȡCall(ULONG64 ��Ʒָ��)
{
	EA8_CALL(��ַ::ʰȡCALL, ��������(��ַ::������ַ), ��Ʒָ��);
}

void ����Call(__int64 ����ָ��, __int32 X, __int32 Y, __int32 Z)
{
	EA8_CALL(��ַ::����CALL, ����ָ��, X, Y, Z);
}

__int32 ȡ����Call(__int64 ����ָ��, __int32 ����)
{
	return (__int32)EA8_CALL(*(__int64*)(*(__int64*)����ָ�� + ��ַ::ȡ����CALL), ����ָ��, ����);
}

void Send_����Call(INT64 ��ֵ) {
	EA8_CALL(��ַ::����CALL, ��ַ::������ַ, ��ֵ);
}

void Send_����Call() {
	EA8_CALL(��ַ::����CALL);
}

void Send_����Call(ULONG64 ��ͷ, int ����)
{
	ULONG64 ������ = NULL;

	if (���� == 1)������ = 0x146104690;
	if (���� == 2)������ = 0x146104A80;
	if (���� == 4)������ = 0x1461046B0;
	if (���� == 8)������ = 0x1461046D0;
	EA8_CALL(������, ��ַ::������ַ, ��ͷ);
}

void ���ѡͼ() 
{
	Send_����Call(15);
	Send_����Call(0, 4);
	Send_����Call();
}

void ����ֽ�(int λ��)
{
	Send_����Call(26);
	Send_����Call(0, 1);
	Send_����Call(65535, 2);
	Send_����Call(317, 4);
	Send_����Call(1, 1);
	Send_����Call(static_cast<__int64>(λ��) + 9, 2);
	Send_����Call();
}

void �������(int λ��)
{
	Send_����Call(22);
	Send_����Call(317, 4);
	Send_����Call(95, 4);
	Send_����Call(420609, 1);
	Send_����Call(0, 1);
	Send_����Call(static_cast<__int64>(λ��) + 9, 2);
	Send_����Call(1, 4);
	Send_����Call(static_cast<__int64>(λ��) * 2 + 21, 4);
	Send_����Call();
}

void ����ֽ�(int λ��)
{
	Send_����Call(26);
	Send_����Call(47, 1);
	Send_����Call(65535, 2);
	Send_����Call(317, 4);
	Send_����Call(1, 1);
	Send_����Call(λ��, 2);
	Send_����Call();
}

void ���������()
{
	Send_����Call(132);
	Send_����Call();
}

int ��ʶCall()
{
	return (int)EA8_CALL(��ַ::��ʶCALL);
}

void ���ʰȡ(INT ��Ʒ���) 
{
	Send_����Call(43);
	Send_����Call(��Ʒ���, 4);
	Send_����Call(0, 1);
	Send_����Call(1, 1);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(��ʶCall(), 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(��ʶCall(), 2);
	Send_����Call(��ʶCall(), 2);
	Send_����Call();
}

void �����ͼ(int ��ͼ���, int ��ͼ�Ѷ�, int ������)
{
	Send_����Call(16);
	Send_����Call(��ͼ���, 4);
	Send_����Call(��ͼ�Ѷ�, 1);
	Send_����Call(0, 2);
	Send_����Call(0, 1);
	Send_����Call(0, 1);
	Send_����Call(65535, 2);
	Send_����Call(0, 4);
	Send_����Call(0, 1);
	Send_����Call(0, 4);
	Send_����Call(0, 1);
	Send_����Call(0, 4);
	Send_����Call();
}

void ���ѡ���ɫ(INT ��ɫλ��)
{
	Send_����Call(4);
	Send_����Call(��ɫλ��, 2);
	Send_����Call();
}

void ������ؽ�ɫ()
{
	Send_����Call(7);
	Send_����Call();
}

void ����س�()
{
	Send_����Call(42);
	Send_����Call();
}

void �����ͼ(int �������, int ��������)
{
	Send_����Call(45);
	Send_����Call(�������, 1);
	Send_����Call(��������, 1);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(0, 1);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(0, 4);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(0, 2);
	Send_����Call(30,2 );
	Send_����Call(0, 2);
	Send_����Call(5, 2);
	Send_����Call(0, 4);
	Send_����Call(28, 2);
	Send_����Call(35, 2);
	Send_����Call(3, 2);
	Send_����Call(185362, 8);
	Send_����Call(127984, 4);
	Send_����Call(0, 2);
	Send_����Call(1, 1);
	Send_����Call();
}

void ���ǿ˳(int ��ͼ����)
{
	if (��ͼ���� == 0)
	{
		�����ͼ(Pack.��ǰ����.x - 1, Pack.��ǰ����.y);
	}
	if (��ͼ���� == 1)
	{
		�����ͼ(Pack.��ǰ����.x + 1, Pack.��ǰ����.y);
	}
	if (��ͼ���� == 2)
	{
		�����ͼ(Pack.��ǰ����.x, Pack.��ǰ����.y - 1);
	}
	if (��ͼ���� == 3)
	{
		�����ͼ(Pack.��ǰ����.x, Pack.��ǰ����.y + 1);
	}
}

void ��ͼCall(__int32 ����)
{
	__int64 �հ׵�ַ[100] = { 0 };
	EA8_CALL(��ַ::��ͼCALL, ��������(��������(��������(��ַ::������) + ��ַ::ʱ���ַ) + ��ַ::˳ͼƫ��), ����, (__int64)&�հ׵�ַ, 0xFFFFFFFF);
}

void ����Call(INT ������)
{
	EA8_CALL(��ַ::����CALL, ��ַ::�����ַ, ������);
}

void ���Call(INT ������, INT ��ɴ���)
{
	if (��ɴ��� == NULL)
	{
		��ɴ��� = 1;
	}
	for (size_t i = 0; i < ��ɴ���; ++i)
	{
		EA8_CALL(��ַ::���CALL, ��������(��ַ::�����ַ), ������, 0xFFFFFFFF, 0xFFFFFFFF);
	}
}

void �ύCall(INT ������)
{
	EA8_CALL(��ַ::�ύCALL, ��������(��ַ::�����ַ), ������, 0xFFFFFFFF, 1);
}

void ����call(__int32 ����)
{
	int ������, С����, X, Y;
	EA8_CALL(��ַ::����CALL, *(ULONG64*)��ַ::�������, -1, ����, *(ULONG64*)(��ַ::�������) +��ַ::����ƫ�� - 0x40);
	������ = *(int*)(*(ULONG64*)(��ַ::�������) +��ַ::����ƫ��);
	С���� = *(int*)(*(ULONG64*)(��ַ::�������) +��ַ::����ƫ�� + 4);
	X = *(int*)(*(ULONG64*)(��ַ::�������) +��ַ::����ƫ�� + 8);
	Y = *(int*)(*(ULONG64*)(��ַ::�������) +��ַ::����ƫ�� + 12);
	�����ƶ�Call(������, С����, X, Y);
}

void �����ƶ�Call(int ��������, int ������, int �������, int ��������)
{
	ULONG64 ����ָ�� = ��������(��ַ::��ɫָ��);
	ULONG64 ����ָ�� = ��ַ::����˲��_Rdx;
	д������(����ָ��, ��������);
	д������(����ָ�� + 4, ������);
	д������(����ָ�� + 8, �������);
	д������(����ָ�� + 12, ��������);
	EA8_CALL(��ַ::����˲��CALL, ����ָ��, ����ָ��);
}

void ��ͼCall(__int64 �������, __int64 �����Ѷ�, __int64 ������)
{
	if (������ > 0)
	{
		EA8_CALL(��ַ::��ͼCALL, *(__int64*)��ַ::��ɫָ��, ������, 0, 0, 0, 0xFFFFFFFF);
	}
	else
	{
		EA8_CALL(��ַ::��ͼCALL, *(__int64*)��ַ::��ɫָ��, �������, �����Ѷ�, 0, 0, 0xFFFFFFFF);
	}
}

void �����ɫCall(__int32 ��ɫλ��)
{
	EA8_CALL(��ַ::ѡ���ɫCALL, *(__int32*)(*(__int64*)��ַ::��ɫ��ַ + ��ַ::��ɫ��ʼָ��), ��ɫλ��, 0, 0);
}

void ��ɫ��ҳCall(__int32 ��ɫҳλ)
{
	EA8_CALL(��ַ::��ɫ��ҳCALL, *(__int32*)(*(__int64*)��ַ::��ɫ��ַ + ��ַ::��ɫ��ʼָ��), ��ɫҳλ);
}

void ѡ���ɫCall(__int32 ��ɫλ��)
{
	if (��ɫλ�� > 39)
	{
		��ɫ��ҳCall(9);
	}
	else if (��ɫλ�� > 35)
	{
		��ɫ��ҳCall(8);
	}
	else if (��ɫλ�� > 31)
	{
		��ɫ��ҳCall(7);
	}
	else if (��ɫλ�� > 27)
	{
		��ɫ��ҳCall(6);
	}
	else if (��ɫλ�� > 23)
	{
		��ɫ��ҳCall(5);
	}
	else if (��ɫλ�� > 19)
	{
		��ɫ��ҳCall(4);
	}
	else if (��ɫλ�� > 15)
	{
		��ɫ��ҳCall(3);
	}
	else if (��ɫλ�� > 11)
	{
		��ɫ��ҳCall(2);
	}
	else if (��ɫλ�� > 7)
	{
		��ɫ��ҳCall(1);
	}
	else {
		��ɫ��ҳCall(0);
	}
	�����ɫCall(��ɫλ��);
}

void Buff_Call(int buff��ʶ)
{
	INT64 ��Ч�հ׵�ַ[300] = { NULL };
	EA8_CALL(��ַ::��Ч����CALL, (INT64)&��Ч�հ׵�ַ + 8, 1);
	EA8_CALL(��ַ::��Ч����CALL, (INT64)&��Ч�հ׵�ַ + 8, 2);
	EA8_CALL(��ַ::BUFF����2, EA8_CALL(��ַ::��Ч�ͷ�CALL), EA8_CALL(��ַ::BUFF����1, ��������(��ַ::��Ч��ַ), buff��ʶ, (INT64)&��Ч�հ׵�ַ));
}

void ����Call(ULONG64 ��Ʒָ��)
{
	EA8_CALL(��ַ::����CALL, ��������(��ַ::������ַ), ��Ʒָ��);
}

wstring ����Call(DWORD64 ��Ʊָ��) 
{
	DWORD64 ָ�� = EA8_CALL(��ַ::�򿪽���CALL, ��������(��ַ::�̵��ַ), ��ַ::����ID_edx, ��Ʊָ��);
	DWORD64 �� = ��������(ָ�� + ��ַ::������);
	DWORD64 β = ��������(ָ�� + ��ַ::����β);
	DWORD64 ���� = (DWORD64)(β - ��) / ��ַ::�������;

	wstring ��������;

	for (int i = 1; i < ����; i++)
	{
		DWORD64 ָ�� = ��������(�� + (static_cast<__int64>(i) - 1) * ��ַ::������� + 32);
		if (ָ�� > 0 && ָ�� < 9999999999)
		{
			wchar_t* ��ʱ�ı� = (wchar_t*)ָ��;
			�������� += ��ʱ�ı�;
			�������� += L"|";
		}
	}

	return ��������;

}

void ����Call()
{
	if (ȡ��Ϸ״̬() != 3)
	{
		return;
	}
	ULONG64 �հ׵�ַ[100] = { NULL };
	ULONG64 ����״̬ = ����Ч��(4);
	*(ULONG64*)((ULONG64)�հ׵�ַ + 8) = ����״̬;
	*(ULONG64*)(����״̬) = 0;
	*(ULONG64*)((ULONG64)�հ׵�ַ + 16) = ����״̬ + 4;
	*(ULONG64*)((ULONG64)�հ׵�ַ + 24) = ����״̬ + 4;
	��ȡ����(8, (ULONG64)�հ׵�ַ);
}

void ��ȡ����(int ����id, ULONG64 �հ�)
{
	EA8_CALL(��ַ::����CALL, ��������(��ַ::�����ַB), ����id, �հ�, 1);
}

ULONG64 ����Ч��(int ����)
{
	return EA8_CALL(��ַ::���ݴ���_����, ����);
}