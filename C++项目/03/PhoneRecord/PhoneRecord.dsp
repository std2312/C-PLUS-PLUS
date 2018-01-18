# Microsoft Developer Studio Project File - Name="PhoneRecord" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=PhoneRecord - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PhoneRecord.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PhoneRecord.mak" CFG="PhoneRecord - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PhoneRecord - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PhoneRecord - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PhoneRecord - Win32 Release"

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

!ELSEIF  "$(CFG)" == "PhoneRecord - Win32 Debug"

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

# Name "PhoneRecord - Win32 Release"
# Name "PhoneRecord - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseButton.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmployeeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Logindlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ManufactureDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PhoneBook.cpp
# End Source File
# Begin Source File

SOURCE=.\PhoneinDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PhoneoutDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PhoneRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\PhoneRecord.rc
# End Source File
# Begin Source File

SOURCE=.\PhoneRecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\BaseButton.h
# End Source File
# Begin Source File

SOURCE=.\ClientDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmployeeDlg.h
# End Source File
# Begin Source File

SOURCE=.\Logindlg.h
# End Source File
# Begin Source File

SOURCE=.\ManufactureDlg.h
# End Source File
# Begin Source File

SOURCE=.\NewSig.h
# End Source File
# Begin Source File

SOURCE=.\PhoneBook.h
# End Source File
# Begin Source File

SOURCE=.\PhoneinDlg.h
# End Source File
# Begin Source File

SOURCE=.\PhoneoutDlg.h
# End Source File
# Begin Source File

SOURCE=.\PhoneRecord.h
# End Source File
# Begin Source File

SOURCE=.\PhoneRecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\RecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Tc08a32.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\BUTDOWN.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BUTMOVE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BUTUP.bmp
# End Source File
# Begin Source File

SOURCE=.\res\PhoneRecord.ico
# End Source File
# Begin Source File

SOURCE=.\res\PhoneRecord.rc2
# End Source File
# Begin Source File

SOURCE=".\res\��Ʒ.ico"
# End Source File
# Begin Source File

SOURCE=".\res\Ա��.ico"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
