# Microsoft Developer Studio Project File - Name="SuperMarket" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SuperMarket - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SuperMarket.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SuperMarket.mak" CFG="SuperMarket - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SuperMarket - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SuperMarket - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SuperMarket - Win32 Release"

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

!ELSEIF  "$(CFG)" == "SuperMarket - Win32 Debug"

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

# Name "SuperMarket - Win32 Release"
# Name "SuperMarket - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\Backdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Backquerydlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Daydlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DepotBackdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Depotbqdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DepotCountdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Depotdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Employees.cpp
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\Monthdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Providedlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Sellquerydlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Shangpindlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SuperMarket.cpp
# End Source File
# Begin Source File

SOURCE=.\SuperMarket.rc
# End Source File
# Begin Source File

SOURCE=.\SuperMarketDlg.cpp
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

SOURCE=.\Backdlg.h
# End Source File
# Begin Source File

SOURCE=.\Backquerydlg.h
# End Source File
# Begin Source File

SOURCE=.\Daydlg.h
# End Source File
# Begin Source File

SOURCE=.\DepotBackdlg.h
# End Source File
# Begin Source File

SOURCE=.\Depotbqdlg.h
# End Source File
# Begin Source File

SOURCE=.\DepotCountdlg.h
# End Source File
# Begin Source File

SOURCE=.\Depotdlg.h
# End Source File
# Begin Source File

SOURCE=.\Employees.h
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\Monthdlg.h
# End Source File
# Begin Source File

SOURCE=.\Providedlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Sellquerydlg.h
# End Source File
# Begin Source File

SOURCE=.\Shangpindlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SuperMarket.h
# End Source File
# Begin Source File

SOURCE=.\SuperMarketDlg.h
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

SOURCE=.\res\SuperMarket.ico
# End Source File
# Begin Source File

SOURCE=.\res\SuperMarket.rc2
# End Source File
# Begin Source File

SOURCE=".\res\超市进销存.BMP"
# End Source File
# Begin Source File

SOURCE=".\res\登录.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\库存信息.ico"
# End Source File
# Begin Source File

SOURCE=".\res\日结查询.ico"
# End Source File
# Begin Source File

SOURCE=".\res\入库登记.ico"
# End Source File
# Begin Source File

SOURCE=".\res\商品信息.ico"
# End Source File
# Begin Source File

SOURCE=".\res\销售查询.ico"
# End Source File
# Begin Source File

SOURCE=".\res\用户管理.ico"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
