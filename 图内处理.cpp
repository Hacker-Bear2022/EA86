#include"dllmain.h"

static int 未央图内计次 = 0;

void 处理事件()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			// 如果收到WM_QUIT消息，退出循环
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

// 超级延时函数
void 超级延时(int msec)
{
	LARGE_INTEGER dueTime;
	dueTime.QuadPart = -10 * (LONGLONG)msec * 1000;  // -10 * 毫秒 * 1000 微秒/毫秒

	HANDLE hTimer = CreateWaitableTimerA(NULL, FALSE, NULL);
	if (hTimer == NULL)
	{
		std::cerr << "无法创建定时器: " << GetLastError() << std::endl;
		return;
	}

	if (!SetWaitableTimer(hTimer, &dueTime, 0, NULL, NULL, FALSE))
	{
		std::cerr << "无法设置定时器: " << GetLastError() << std::endl;
		CloseHandle(hTimer);
		return;
	}

	// 等待定时器触发或消息到达
	while (MsgWaitForMultipleObjects(1, &hTimer, FALSE, INFINITE, QS_ALLINPUT) != WAIT_OBJECT_0)
	{
		处理事件();
	}

	CloseHandle(hTimer);
}

void 虚拟热键()
{
	INPUT esc[2] = {};

	// 按下 ESC 键
	esc[0].type = INPUT_KEYBOARD;
	esc[0].ki.wVk = 27;  // ESC 键的虚拟键码
	esc[0].ki.dwFlags = 0;

	// 释放 ESC 键
	esc[1].type = INPUT_KEYBOARD;
	esc[1].ki.wVk = 27;
	esc[1].ki.dwFlags = KEYEVENTF_KEYUP;

	// 发送输入
	SendInput(2, esc, sizeof(INPUT));

	INPUT Spaces[2] = {};

	// 按下 ESC 键
	Spaces[0].type = INPUT_KEYBOARD;
	Spaces[0].ki.wVk = 32;  // ESC 键的虚拟键码
	Spaces[0].ki.dwFlags = 0;

	// 释放 ESC 键
	Spaces[1].type = INPUT_KEYBOARD;
	Spaces[1].ki.wVk = 32;
	Spaces[1].ki.dwFlags = KEYEVENTF_KEYUP;

	// 发送输入
	SendInput(2, Spaces, sizeof(INPUT));

}

void 图内数据处理()
{
	if (读配置(L"刷图模式", L"剧情升级") != 1 && 读配置(L"刷图模式", L"未央爬楼") == 1 && 读配置(L"刷图模式", L"活动升级") != 1)
	{
		未央图内处理数据();
	}
	if (读配置(L"刷图模式", L"剧情升级") == 1 && 读配置(L"刷图模式", L"未央爬楼") != 1 && 读配置(L"刷图模式", L"活动升级") != 1)
	{
		剧情图内处理数据();
	}
	if (读配置(L"刷图模式", L"剧情升级") != 1 && 读配置(L"刷图模式", L"未央爬楼") != 1 && 读配置(L"刷图模式", L"活动升级") == 1)
	{
		活动图内处理数据();
	}
}

void 未央图内处理数据()
{

	未央图内计次++;
	神话公告(to_wstring(未央图内计次));
	if (未央图内计次 == 2)
	{
		未央图内计次 = 0;
		/* -------------------------------------------------------未央爬楼图内处理-------------------------------------------------*/

		if (是否在BOSS房())
		{
			if (Pack.BOSS死亡)
			{
				if (是否有物品() == false)
				{
					if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
					{
						组包回城();
					}
					if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
					{
						回城Call(2);
					}
				}
			}
			else
			{
				跟随遍历();
			}

		}
		else
		{

			if (是否开门())
			{
				神话公告(L"是否开门(真)");
				if (读配置(L"图内处理", L"未央全图") == 1)
				{
					if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
					{
						神话公告(L"组包强顺(未央全图())");
						组包强顺(未央全图());
					}
					if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
					{
						神话公告(L"过图Call(未央全图())");
						过图Call(未央全图());
					}
				}
				else
				{
					if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
					{
						组包强顺(顺图方向());
					}
					if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
					{
						过图Call(顺图方向());
					}
				}
			}
			else
			{
				神话公告(L"是否开门(假)");
				跟随遍历();
				//未开门数据未处理
			}
		}
	}
}

void 剧情图内处理数据()
{
	if (读整数型(读长整数(基址::对话基址) + 0xC) == 1 || 读整数型(基址::对话基址B) == 1)
	{
		/*keybd_event(27, MapVirtualKey(27, 0), 0, 0);//按下
		超级延时(50);
		keybd_event(27, MapVirtualKey(27, 0), KEYEVENTF_KEYUP, 0);//松开
		超级延时(100);
		keybd_event(32, MapVirtualKey(32, 0), 0, 0);//按下
		超级延时(50);
		keybd_event(32, MapVirtualKey(32, 0), KEYEVENTF_KEYUP, 0);//松开
		超级延时(100);*/
		虚拟热键();
	}
	选图次数 = 0;
	/* --------------------------------------------------  剧情升级图内处理-----------------------------------------------------*/
	if (是否在BOSS房())
	{
		if (Pack.BOSS死亡)
		{
			if (读配置(L"图内处理", L"获取翻牌") == 1)
			{
				翻牌Call();
				if (Pack.翻牌奖励)
				{
					if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
					{
						组包回城();
						Pack.翻牌奖励 = false;
					}
					if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
					{
						回城Call(2);
						Pack.翻牌奖励 = false;
					}
				}
			}
			else
			{
				if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
				{
					组包回城();
					Pack.翻牌奖励 = false;
				}
				if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
				{
					回城Call(2);
					Pack.翻牌奖励 = false;
				}
			}
			if (Pack.翻牌奖励)
			{
				if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
				{
					组包回城();
					Pack.翻牌奖励 = false;
				}
				if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
				{
					回城Call(2);
					Pack.翻牌奖励 = false;
				}
			}
		}
		if (!Pack.BOSS死亡)
		{
			跟随BOSS();
		}
	}
	else
	{
		if (是否开门())
		{
			if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
			{
				组包强顺(顺图方向());
			}
			if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
			{
				过图Call(顺图方向());
			}
		}
		else
		{
			跟随遍历();
		}
	}
}
void 活动图内处理数据()
{
	/* -------------------------------------------------------活动升级图内处理-------------------------------------------------*/
	if (读配置(L"刷图模式", L"剧情升级") != 1 && 读配置(L"刷图模式", L"未央爬楼") != 1 && 读配置(L"刷图模式", L"活动升级") == 1)
	{
		if (是否在BOSS房())
		{
			if (Pack.BOSS死亡)
			{
				if (是否有物品() == false)
				{
					if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
					{
						组包回城();
					}
					if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
					{
						回城Call(2);
					}
				}
			}

		}
		else
		{
			if (是否开门())
			{
				if (读配置(L"操作模式", L"发包操作") == 1 && 读配置(L"操作模式", L"模拟操作") != 1)
				{
					组包强顺(顺图方向());
				}
				if (读配置(L"操作模式", L"发包操作") != 1 && 读配置(L"操作模式", L"模拟操作") == 1)
				{
					过图Call(顺图方向());
				}
			}
			else
			{
				跟随遍历();
			}
		}
	}
}