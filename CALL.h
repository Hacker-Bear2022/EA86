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

void ����(std::wstring ����, int ���� = NULL);

void ͸��call();

__int64 ��ͼCall(__int32 ��ͼ���);

ULONG64 ����CALL(int ����);

void �򿪽���Call(int �������);

void �������CALL(int ����λ��, int ��ӱ���);//��ӱ���=1װ��  ��ӱ���=48˾��

void �����ϼ�CALL(int �ϼܽ��);

void ���Call(ULONG64 ��Ʒָ��, int ��Ʒ��ַ);

void �ֽ�Call(ULONG64 ��Ʒָ��);

void ���˾��(int ˾��_��);

void ˾���볡(int ˾��_��);

void ����Call();

void ѡͼCall();

void �س�Call(__int32 �س�λ��);//0�ٴ� 1���� 2�س�

void ʰȡCall(ULONG64 ��Ʒָ��);

void ����Call(__int64 ����ָ��, __int32 X, __int32 Y, __int32 Z = NULL);

__int32 ȡ����Call(__int64 ����ָ��, __int32 ����);

void Send_����Call(INT64 ��ֵ);

void Send_����Call();

void ���ѡͼ();

void ���������();

void ���ʰȡ(INT ��Ʒ���);

void �����ͼ(int ��ͼ���, int ��ͼ�Ѷ�, int ������ = NULL);

void ���ѡ���ɫ(INT ��ɫλ��);

void ������ؽ�ɫ();

void ����س�();

void �����ͼ(int �������, int ��������);

void ���ǿ˳(int ��ͼ����);

void ��ͼCall(__int32 ����);

void ����Call(INT ������);

void ���Call(INT ������, INT ��ɴ���);

void �ύCall(INT ������);

void ����call(__int32 ����);

void �����ƶ�Call(int ��������, int ������, int �������, int ��������);

void ��ͼCall(__int64 �������, __int64 �����Ѷ�, __int64 ������ = 0);

void �����ɫCall(__int32 ��ɫλ��);

void ��ɫ��ҳCall(__int32 ��ɫҳλ);

void ѡ���ɫCall(__int32 ��ɫλ��);

void Buff_Call(int buff��ʶ);

int ����Call(int ��ͼ���);