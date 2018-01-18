# Microsoft Developer Studio Project File - Name="bbb" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=bbb - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "bbb.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "bbb.mak" CFG="bbb - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "bbb - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "bbb - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "bbb - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
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

!ELSEIF  "$(CFG)" == "bbb - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
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

# Name "bbb - Win32 Release"
# Name "bbb - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\bbb.cpp
# End Source File
# Begin Source File

SOURCE=.\bbb.rc
# End Source File
# Begin Source File

SOURCE=.\bbbDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CustomGrid.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBookAdjust2.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBookAdjustPrice2.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBookInfo1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBookInput2.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBookKinds1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBookPrice2.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBookSale2.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgConfigM.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgDeskInfo1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgInputBack2.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgInputBackQuery3.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgInputQuery3.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLogin.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOperator1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgProviderInfo1.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSaleBack2.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSaleBackQuery3.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSaleQuery3.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgStoreInfo1.cpp
# End Source File
# Begin Source File

SOURCE=.\KeyEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\MyCoolMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintFram.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintView.cpp
# End Source File
# Begin Source File

SOURCE=.\Report.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TabSheet.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\bbb.h
# End Source File
# Begin Source File

SOURCE=.\bbbDlg.h
# End Source File
# Begin Source File

SOURCE=.\CustomGrid.h
# End Source File
# Begin Source File

SOURCE=.\DlgBookAdjust2.h
# End Source File
# Begin Source File

SOURCE=.\DlgBookAdjustPrice2.h
# End Source File
# Begin Source File

SOURCE=.\DlgBookInfo1.h
# End Source File
# Begin Source File

SOURCE=.\DlgBookInput2.h
# End Source File
# Begin Source File

SOURCE=.\DlgBookKinds1.h
# End Source File
# Begin Source File

SOURCE=.\DlgBookPrice2.h
# End Source File
# Begin Source File

SOURCE=.\DlgBookSale2.h
# End Source File
# Begin Source File

SOURCE=.\DlgConfigM.h
# End Source File
# Begin Source File

SOURCE=.\DlgDeskInfo1.h
# End Source File
# Begin Source File

SOURCE=.\DlgInputBack2.h
# End Source File
# Begin Source File

SOURCE=.\DlgInputBackQuery3.h
# End Source File
# Begin Source File

SOURCE=.\DlgInputQuery3.h
# End Source File
# Begin Source File

SOURCE=.\DlgLogin.h
# End Source File
# Begin Source File

SOURCE=.\DlgOperator1.h
# End Source File
# Begin Source File

SOURCE=.\DlgProviderInfo1.h
# End Source File
# Begin Source File

SOURCE=.\DlgSaleBack2.h
# End Source File
# Begin Source File

SOURCE=.\DlgSaleBackQuery3.h
# End Source File
# Begin Source File

SOURCE=.\DlgSaleQuery3.h
# End Source File
# Begin Source File

SOURCE=.\DlgStoreInfo1.h
# End Source File
# Begin Source File

SOURCE=.\KeyEdit.h
# End Source File
# Begin Source File

SOURCE=.\MyCoolMenu.h
# End Source File
# Begin Source File

SOURCE=.\PrintDoc.h
# End Source File
# Begin Source File

SOURCE=.\PrintFram.h
# End Source File
# Begin Source File

SOURCE=.\PrintView.h
# End Source File
# Begin Source File

SOURCE=.\pub.h
# End Source File
# Begin Source File

SOURCE=.\Report.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TabSheet.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\1-1-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\1-1-2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\1-1-3.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\1-1-4.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\a.bmp
# End Source File
# Begin Source File

SOURCE=.\res\a1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\aa.bmp
# End Source File
# Begin Source File

SOURCE=.\res\aaa.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ADD.ICO
# End Source File
# Begin Source File

SOURCE=.\res\b.bmp
# End Source File
# Begin Source File

SOURCE=.\res\b1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BaseInfo.ico
# End Source File
# Begin Source File

SOURCE=.\res\bb.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bbb.ico
# End Source File
# Begin Source File

SOURCE=.\res\bbb.rc2
# End Source File
# Begin Source File

SOURCE=.\res\bj.bmp
# End Source File
# Begin Source File

SOURCE=.\res\c1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\clipboard02.ico
# End Source File
# Begin Source File

SOURCE=.\res\d1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\DEL.ICO
# End Source File
# Begin Source File

SOURCE=".\res\DE图书管理系统主界面2.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\end.ico
# End Source File
# Begin Source File

SOURCE=.\res\FindInfo.ico
# End Source File
# Begin Source File

SOURCE=.\res\first.ico
# End Source File
# Begin Source File

SOURCE=".\res\folder users.ico"
# End Source File
# Begin Source File

SOURCE=.\res\icon14.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\res\InputStore.ico
# End Source File
# Begin Source File

SOURCE=.\res\Left6_32x32x256.ico
# End Source File
# Begin Source File

SOURCE=.\res\mainfram.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MessageMode.ico
# End Source File
# Begin Source File

SOURCE=.\res\MODFY.ico
# End Source File
# Begin Source File

SOURCE=.\res\MsgNoRead.ico
# End Source File
# Begin Source File

SOURCE=.\res\QUERY.ICO
# End Source File
# Begin Source File

SOURCE=".\res\Recycle Red.ico"
# End Source File
# Begin Source File

SOURCE=.\res\Recycle.ico
# End Source File
# Begin Source File

SOURCE=.\res\Right6_32x32x256.ico
# End Source File
# Begin Source File

SOURCE=".\res\Shut Down.ico"
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar2.bmp
# End Source File
# Begin Source File

SOURCE=".\res\按钮-1 拷贝.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\按钮-2 拷贝.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\按钮-3 拷贝.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\按钮-4 拷贝.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\图片2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\资产设备管理系统主界面.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
