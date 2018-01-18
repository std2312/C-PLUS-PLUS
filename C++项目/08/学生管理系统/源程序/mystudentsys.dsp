# Microsoft Developer Studio Project File - Name="mystudentsys" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=mystudentsys - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mystudentsys.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mystudentsys.mak" CFG="mystudentsys - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mystudentsys - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "mystudentsys - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mystudentsys - Win32 Release"

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

!ELSEIF  "$(CFG)" == "mystudentsys - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "C:\Program Files\HTML Help Workshop\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 HtmlHelp.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"C:\Program Files\HTML Help Workshop\include"

!ENDIF 

# Begin Target

# Name "mystudentsys - Win32 Release"
# Name "mystudentsys - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Class_subjectinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Class_subjectset.cpp
# End Source File
# Begin Source File

SOURCE=.\Classinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Classinfoset.cpp
# End Source File
# Begin Source File

SOURCE=.\Examinfo_submarkdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Examinfo_submarkset.cpp
# End Source File
# Begin Source File

SOURCE=.\Examkinddlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Examkindset.cpp
# End Source File
# Begin Source File

SOURCE=.\excel9.cpp
# End Source File
# Begin Source File

SOURCE=.\Grade_levelinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Grade_levelset.cpp
# End Source File
# Begin Source File

SOURCE=.\InfoStudent.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_regbreakdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginSet.cpp
# End Source File
# Begin Source File

SOURCE=.\mystudentsys.cpp
# End Source File
# Begin Source File

SOURCE=.\mystudentsys.rc
# End Source File
# Begin Source File

SOURCE=.\mystudentsysDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Officeinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=.\officeset.cpp
# End Source File
# Begin Source File

SOURCE=.\Regbreak_finddlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Regbrreakinfoset.cpp
# End Source File
# Begin Source File

SOURCE=.\Reportdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Studentinfo_finddlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Studentinfoset.cpp
# End Source File
# Begin Source File

SOURCE=.\Subjectdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Subjectinfo.cpp
# End Source File
# Begin Source File

SOURCE=.\Teacherinfodlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Teacherinfoset.cpp
# End Source File
# Begin Source File

SOURCE=.\Userdlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Class_subjectinfodlg.h
# End Source File
# Begin Source File

SOURCE=.\Class_subjectset.h
# End Source File
# Begin Source File

SOURCE=.\Classinfodlg.h
# End Source File
# Begin Source File

SOURCE=.\Classinfoset.h
# End Source File
# Begin Source File

SOURCE=.\Examinfo_submarkdlg.h
# End Source File
# Begin Source File

SOURCE=.\Examinfo_submarkset.h
# End Source File
# Begin Source File

SOURCE=.\Examkinddlg.h
# End Source File
# Begin Source File

SOURCE=.\Examkindset.h
# End Source File
# Begin Source File

SOURCE=.\excel9.h
# End Source File
# Begin Source File

SOURCE=.\ExternDllHeader.h
# End Source File
# Begin Source File

SOURCE=.\Grade_levelinfodlg.h
# End Source File
# Begin Source File

SOURCE=.\Grade_levelset.h
# End Source File
# Begin Source File

SOURCE=.\htmlhelp.h
# End Source File
# Begin Source File

SOURCE=.\InfoStudent.h
# End Source File
# Begin Source File

SOURCE=.\Input_regbreakdlg.h
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\LoginSet.h
# End Source File
# Begin Source File

SOURCE=.\mystudentsys.h
# End Source File
# Begin Source File

SOURCE=.\mystudentsysDlg.h
# End Source File
# Begin Source File

SOURCE=.\Officeinfodlg.h
# End Source File
# Begin Source File

SOURCE=.\officeset.h
# End Source File
# Begin Source File

SOURCE=.\Regbreak_finddlg.h
# End Source File
# Begin Source File

SOURCE=.\Regbrreakinfoset.h
# End Source File
# Begin Source File

SOURCE=.\Reportdlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Studentinfo_finddlg.h
# End Source File
# Begin Source File

SOURCE=.\Studentinfoset.h
# End Source File
# Begin Source File

SOURCE=.\Subjectdlg.h
# End Source File
# Begin Source File

SOURCE=.\Subjectinfo.h
# End Source File
# Begin Source File

SOURCE=.\Teacherinfodlg.h
# End Source File
# Begin Source File

SOURCE=.\Teacherinfoset.h
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

SOURCE=.\res\ace.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hua.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mystudentsys.ico
# End Source File
# Begin Source File

SOURCE=.\res\mystudentsys.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar_.bmp
# End Source File
# Begin Source File

SOURCE=".\res\°´Å¥.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\htmlhelp.lib
# End Source File
# End Target
# End Project
