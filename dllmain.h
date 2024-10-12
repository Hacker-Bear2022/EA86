#pragma once



#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include<atlstr.h>
#include <ShlObj.h>
#include <time.h>
#include <tuple>
#include <cwchar>
#include <stdexcept>
#include <map>
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <future>
#include <atomic>
#include <functional>
#include <psapi.h>
#include <tlhelp32.h>
#include <sstream>






#define ByteArr vector<byte>

using namespace std;
typedef vector<unsigned char> Bytes;



#include <codecvt>
#include <locale>
#include <sys/stat.h>
#include<random>
#include"基址.h"
#include"CALL.h"
#include"任务.h"
#include"寻路.h"
#include"收包.h"
#include"汇编.h"
#include"判断.h"
#include"城镇处理.h"
#include"图内处理.h"
#include"选图处理.h"
#include"功能.h"
