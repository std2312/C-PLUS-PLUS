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

SOURCE="..\ͼ�����\��������\12\340\SendMsg\dllforvc.h"
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

SOURCE=".\res\�����Ų����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�����Ų���ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ְ������.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ְ�����ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����Ա����.ico"
# End Source File
# Begin Source File

SOURCE=".\res\���볣�����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���볣����ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���������.ico"
# End Source File
# Begin Source File

SOURCE=".\res\��¼.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�绰������.ico"
# End Source File
# Begin Source File

SOURCE=".\res\�绰����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�绰��ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����è����.ico"
# End Source File
# Begin Source File

SOURCE=".\res\����Ⱥ��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����Ϣ����.ico"
# End Source File
# Begin Source File

SOURCE=".\res\����Ϣ����.ico"
# End Source File
# Begin Source File

SOURCE=".\res\������Ϣ��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\������Ϣǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���غ�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�ظ���.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�ظ�ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ȡ��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��ȡǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\��պ�.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\���ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ȫ��Ա�������.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ȫ��Ա������ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ɾ����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ɾ��ǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\����û�1.BMP"
# End Source File
# Begin Source File

SOURCE=".\res\����û�2.BMP"
# End Source File
# Begin Source File

SOURCE=".\res\����Ϣ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�޸İ�ťǰ.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�޸ĺ�.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
