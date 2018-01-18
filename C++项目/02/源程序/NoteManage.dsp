# Microsoft Developer Studio Project File - Name="NoteManage" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=NoteManage - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "NoteManage.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "NoteManage.mak" CFG="NoteManage - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "NoteManage - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "NoteManage - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "NoteManage - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "NoteManage - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "NoteManage - Win32 Release"
# Name "NoteManage - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\BmpButton.cpp
# End Source File
# Begin Source File

SOURCE=.\Bookdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\NewNotedlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Notedlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NoteManage.cpp
# End Source File
# Begin Source File

SOURCE=.\NoteManage.rc
# End Source File
# Begin Source File

SOURCE=.\NoteManageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NoteSet.cpp
# End Source File
# Begin Source File

SOURCE=.\OftenNotedlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PhoneBookdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PhoneEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\RecvNotedlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Restoredlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SendNotedlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Userdlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\BmpButton.h
# End Source File
# Begin Source File

SOURCE=.\Bookdlg.h
# End Source File
# Begin Source File

SOURCE="..\图书光盘\范例宝典\12\340\SendMsg\dllforvc.h"
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\NewNotedlg.h
# End Source File
# Begin Source File

SOURCE=.\Notedlg.h
# End Source File
# Begin Source File

SOURCE=.\NoteManage.h
# End Source File
# Begin Source File

SOURCE=.\NoteManageDlg.h
# End Source File
# Begin Source File

SOURCE=.\NoteSet.h
# End Source File
# Begin Source File

SOURCE=.\OftenNotedlg.h
# End Source File
# Begin Source File

SOURCE=.\PhoneBookdlg.h
# End Source File
# Begin Source File

SOURCE=.\PhoneEdit.h
# End Source File
# Begin Source File

SOURCE=.\RecvNotedlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Restoredlg.h
# End Source File
# Begin Source File

SOURCE=.\SendNotedlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Userdlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\42.ico
# End Source File
# Begin Source File

SOURCE=.\res\NoteManage.ico
# End Source File
# Begin Source File

SOURCE=.\res\NoteManage.rc2
# End Source File
# Begin Source File

SOURCE=".\res\按部门插入后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\按部门插入前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\按职务插入后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\按职务插入前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\保存后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\保存前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\操作员管理.ico"
# End Source File
# Begin Source File

SOURCE=".\res\插入常用语后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\插入常用语前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\常用语管理.ico"
# End Source File
# Begin Source File

SOURCE=".\res\登录.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\电话簿管理.ico"
# End Source File
# Begin Source File

SOURCE=".\res\电话簿后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\电话簿前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\短信猫设置.ico"
# End Source File
# Begin Source File

SOURCE=".\res\短信群发.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\短信息发送.ico"
# End Source File
# Begin Source File

SOURCE=".\res\短信息接收.ico"
# End Source File
# Begin Source File

SOURCE=".\res\发送信息后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\发送信息前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\返回后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\返回前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\回复后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\回复前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\获取后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\获取前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\清空后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\清空前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\全体员工插入后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\全体员工插入前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\删除后.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\删除前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\添加用户1.BMP"
# End Source File
# Begin Source File

SOURCE=".\res\添加用户2.BMP"
# End Source File
# Begin Source File

SOURCE=".\res\新消息.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\修改按钮前.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\修改后.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
