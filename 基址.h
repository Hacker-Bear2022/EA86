#pragma once
namespace 基址
{
	constexpr auto 浅灰色基址 = 0xDDDDDDDD;    // 5450252528   不用更新  
	constexpr auto 时间基址 = 0x20A050;    // 2138192   不用更新  
	constexpr auto 新人物基址 = 0x14CD36B58;    // 5583891288   创新中心获取  
	constexpr auto 人物基址B = 0x14C382CB0;    // 5573717168   创新中心获取 
	constexpr auto 独家收包 = 0x144DC40FF;    // 5450252543   创新中心获取  
	constexpr auto 商店基址 = 0x14C4160E0;    // 5574320352   创新中心获取  
	constexpr auto 收包Call = 0x144DC40F0;    // 5450252528   创新中心获取  
	constexpr auto 收包跳转 = 0x144DC5D2B;    // 5450259755   创新中心获取 
	constexpr auto 神话CALL = 0x14498F160;    // 5445841248   创新中心获取
	constexpr auto 透明CALL = 0x146135170;    // 5470638448   创新中心获取
	constexpr auto 地图CALL = 0x1446C4380;    // 5442913152   创新中心获取
	constexpr auto 界面CALL = 0x144A91ED0;    // 5446901456   创新中心获取
	constexpr auto 缓冲CALL = 0x146103680;    // 5470434944   创新中心获取  
	constexpr auto 发包CALL = 0x146104520;    // 5470438688   创新中心获取
	constexpr auto 标识CALL = 0x1461FBF10;    // 5471452944   创新中心获取
	constexpr auto 发包基址 = 0x14CD93450;    // 5584270416   创新中心获取 
	constexpr auto 对话基址 = 0x14C24BC58;    // 5572443224   创新中心获取  
	constexpr auto 对话基址B = 0x14CD8CF78;    // 5584244600   创新中心获取
	constexpr auto 玉荣背包 = 0x14C416138;    // 5574320440   创新中心获取
	constexpr auto 打开界面CALL = 0x145A09E70;    // 5463121520   创新中心获取
	constexpr auto 评分基址 = 0x14C414D80;    // 5574315392   创新中心获取
	constexpr auto 城镇大区域 = 0x14C3D14BC;    // 5574038716   创新中心获取  
	constexpr auto 城镇小区域 = 0x14C3D14C0;    // 5574038720   创新中心获取  
	constexpr auto 城镇坐标X = 0x14D134888;    // 5588076680   创新中心获取  
	constexpr auto 城镇坐标Y = 0x14D13488C;    // 5588076684   创新中心获取   
	constexpr auto 界面_Rcx = 0x14C3FE910;    // 5574224144   创新中心获取  
	constexpr auto 全局钩子 = 0x1450E5E95;    // 5453536917   创新中心获取
	constexpr auto 最大疲劳 = 0x14CD36A9C;    // 5583891100   创新中心获取  
	constexpr auto 当前疲劳 = 0x14CD36B0C;    // 5583891212   创新中心获取 
	constexpr auto 特效缓冲CALL = 0x1401DF850;    // 5370673232   创新中心获取  
	constexpr auto 特效释放CALL = 0x1442606E0;    // 5438310112   创新中心获取  
	constexpr auto BUFF参数2 = 0x144267020;    // 5438337056   创新中心获取  
	constexpr auto BUFF参数1 = 0x14425B560;    // 5438289248   创新中心获取  
	constexpr auto 特效基址 = 0x14C3F0378;    // 5574165368   创新中心获取  
	constexpr auto 次数CALL = 0x1422536E0; //7度_获取
	constexpr auto 次数_RCX = 0x14C2451F0; //7度_获取
	constexpr auto 添加CALL = 0x145A456C0;    //45 8B 46 08 8B D6 44 8B C8 48 8B CD E8
	constexpr auto 确认CALL = 0x145A45440;    //45 8B CE 45 8B C4 41 8B D7 48 8B CF E8
	constexpr auto 门票判断 = 0x14C3F7308;    //45 33 C9 BA 1D 07 00 00 48 83 C4 28
	constexpr auto 门票判断偏移 = 0x2AE00;    // 
	constexpr auto 翻牌CALL_1 = 0x145E31580;  //7度_获取
	constexpr auto 独家伤害 = 0x1450F7287; //7度_获取
	constexpr auto 目录基址 = 0x14DA1B7A0; //7度_获取
	constexpr auto 游戏状态 = 0x14BEEB490;    // 5568902288   创新中心获取 
	constexpr auto 司南背包 = 0x14C416140;    // 5574320448   创新中心获取  
	constexpr auto 背包基址 = 0x14C4160E8;    // 5574320360   创新中心获取 
	constexpr auto 一键分解添加 = 0x144E8A930;    // 5451065648   创新中心获取
	constexpr auto 分解CALL = 0x144E9D0D0;    // 5451141328   创新中心获取
	constexpr auto 司南添加CALL = 0x1422EF720;    // 5405341472   创新中心获取  
	constexpr auto 司南进图_Rcx = 0x14C3C1B08;    // 5573974792   创新中心获取  
	constexpr auto 司南进图CALL = 0x1422D23B0;    // 5405221808   创新中心获取
	constexpr auto 翻牌CALL_2 = 0x145E318E0;    // 5467478240   创新中心获取  
	constexpr auto 快速翻牌CALL = 0x145E1BFC0;    // 5467389888   创新中心获取 
	constexpr auto 房间编号 = 0x14C4160D0;    // 5574320336   创新中心获取
	constexpr auto 回城参数 = 0x14CD89070;    // 5584228464   创新中心获取 
	constexpr auto 回城CALL = 0x145E310F0;    // 5467476208   创新中心获取
	constexpr auto 拾取CALL = 0x144E8CC80;    // 5451074688   创新中心获取
	constexpr auto 过图CALL = 0x14419E250;    // 5437514320   创新中心获取
	constexpr auto 接受CALL = 0x144667C10;    // 5442534416   创新中心获取
	constexpr auto 完成CALL = 0x144668220;    // 5442535968   创新中心获取  
	constexpr auto 提交CALL = 0x144667D00;    // 5442534656   创新中心获取 
	constexpr auto 区域CALL = 0x146052E20;    // 5469711904   创新中心获取  
	constexpr auto 进图CALL = 0x1460D7B80;    // 5470256000   创新中心获取
	constexpr auto 选图CALL = 0x146093D20;    // 5469977888   创新中心获取
	constexpr auto 坐标CALL = 0x144F37600;    // 5451773440   创新中心获取
	constexpr auto 空入CALL = 0x144E9C940;    // 5451139392   创新中心获取 
	constexpr auto 角色翻页CALL = 0x1406937E0;    // 5375604704   创新中心获取
	constexpr auto 选择角色CALL = 0x140690520;    // 5375591712   创新中心获取
	constexpr auto 城镇瞬移CALL = 0x14609BAE0;    // 5470010080   创新中心获取
	constexpr auto 动作CALL = 0x14502E800;    // 5452785664   创新中心获取
	constexpr auto 取坐标CALL = 0x0001E0;    // 480   创新中心获取 
	constexpr auto 角色基址 = 0x14C415D10;    // 5574319376   创新中心获取 
	constexpr auto 数据处理_申请 = 0x1461EE4B0;    // 5471397040   创新中心获取
	constexpr auto 自动捡物 = 0x1451727CF;    // 5454112719   创新中心获取  
	constexpr auto 任务基址 = 0x14C4161D0;    // 5574320592   创新中心获取
	constexpr auto 角色等级 = 0x14C3FADF0;    // 5574209008   创新中心获取
	constexpr auto 区域参数 = 0x14CD925D0;    // 5584266704   创新中心获取 
	constexpr auto 角色指针 = 0x14C415E20;    // 5574319648   创新中心获取
	constexpr auto 城镇瞬移_Rdx = 0x14C3E5A18;    // 5574122008   创新中心获取 
	constexpr auto 门型偏移 = 0x0001E8;    // 488   创新中心获取
	constexpr auto 篝火判断 = 0x001FA0;    // 8096   创新中心获取  
	constexpr auto 评分偏移 = 0x000088;    // 136   创新中心获取
	constexpr auto 地图名称 = 0x000458;    // 1112   创新中心获取
	constexpr auto 地图偏移2 = 0x000230;    // 560   创新中心获取 
	constexpr auto 地图开始2 = 0x0001B8;    // 440   创新中心获取  
	constexpr auto 地图结束2 = 0x0001C0;    // 448   创新中心获取
	constexpr auto 宽高偏移 = 0x0008E0;    // 2272   创新中心获取
	constexpr auto 数组偏移 = 0x000900;    // 2304   创新中心获取
	constexpr auto 上架货物ID = 0x0003C7;    // 2304   创新中心获取
	constexpr auto 物品栏偏移 = 0x0000A8;    // 168   创新中心获取
	constexpr auto 物品交易类型 = 0x0000D0;    // 208   创新中心获取
	constexpr auto 司南类型_1 = 0x000280;    // 640   创新中心获取  
	constexpr auto 司南类型_2 = 0x0000E4;    // 228   创新中心获取
	constexpr auto 物品名称偏移 = 0x40;		 //7度_获取
	constexpr auto 装备品级 = 0x0002F8;    // 760   创新中心获取 
	constexpr auto 是否开门 = 0x0002CC;    // 716   创新中心获取 
	constexpr auto 类型偏移 = 0x0001F4;    // 500   创新中心获取
	constexpr auto 阵营偏移 = 0x0011A0;    // 4512   创新中心获取
	constexpr auto 怪物血量 = 0x0056F0;    // 22256   创新中心获取
	constexpr auto 地面物品 = 0x003158;    // 12632   创新中心获取 
	constexpr auto 物品名称 = 0x000040;    // 64   创新中心获取
	constexpr auto 顺图偏移 = 0x000140;    // 320   创新中心获取
	constexpr auto 全部任务首地址 = 0x0000A8;    // 168   创新中心获取  
	constexpr auto 全部任务尾地址 = 0x0000B0;    // 176   创新中心获取
	constexpr auto 已接任务首地址 = 0x000010;    // 16   创新中心获取  
	constexpr auto 已接任务尾地址 = 0x000018;    // 24   创新中心获取
	constexpr auto 任务类型 = 0x000218;    // 536   创新中心获取 
	constexpr auto 任务等级 = 0x000328;    // 808   创新中心获取
	constexpr auto 任务大小 = 0x000028;    // 40   创新中心获取
	constexpr auto 任务条件 = 0x0004D0;    // 1232   创新中心获取
	constexpr auto 任务副本 = 0x0004A8;    // 1192   创新中心获取
	constexpr auto 区域偏移 = 0x0CE3A8;    // 844712   创新中心获取
	constexpr auto 角色初始指针 = 0x0001D8;    // 472   创新中心获取
	constexpr auto 名称偏移 = 0x000B10;    // 2832   创新中心获取
	constexpr auto 代码偏移 = 0x000B08;    // 2824   创新中心获取  
	constexpr auto 玉荣栏偏移 = 0x000320;         // 心悦基址 
	constexpr auto 玉荣力偏移 = 0x000668;    // 1640   创新中心获取
	constexpr auto 词条ID_edx = 0x0006B6;    // 1718   创新中心获取
	constexpr auto 词条首 = 0x0005F0;    // 1520   创新中心获取  
	constexpr auto 词条尾 = 0x0005F8;    // 1528   创新中心获取  
	constexpr auto 词条间隔 = 0x0000E0;    // 224   创新中心获取
	constexpr auto 当前角色位置 = 0x000390;    // 912   创新中心获取  
	constexpr auto 角色总数偏移 = 0x000614;    // 1556   创新中心获取  

}


