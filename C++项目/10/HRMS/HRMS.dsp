# Microsoft Developer Studio Project File - Name="HRMS" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=HRMS - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "HRMS.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "HRMS.mak" CFG="HRMS - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "HRMS - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "HRMS - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HRMS - Win32 Release"

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

!ELSEIF  "$(CFG)" == "HRMS - Win32 Debug"

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

# Name "HRMS - Win32 Release"
# Name "HRMS - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADOOperation.cpp
# End Source File
# Begin Source File

SOURCE=.\ADOView.cpp
# End Source File
# Begin Source File

SOURCE=.\AgreementListDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ApplerInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\ApplerList.cpp
# End Source File
# Begin Source File

SOURCE=.\ApplerSearchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ApplyEmployeeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AssessDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AssessList.cpp
# End Source File
# Begin Source File

SOURCE=.\AssessSearchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BargainDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DeptDutyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DeptInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EditableListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\FileInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\FileRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\FindDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FindEmployeeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HRMS.cpp
# End Source File
# Begin Source File

SOURCE=.\HRMS.rc
# End Source File
# Begin Source File

SOURCE=.\HRMSDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HumanRemoveDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LaborageRecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LaborRecorDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LabRecSearchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LandingDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LeaveItemDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LeaveList.cpp
# End Source File
# Begin Source File

SOURCE=.\LoadInTempDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\msword9.cpp
# End Source File
# Begin Source File

SOURCE=.\PayClipDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PayListDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PayListSeachDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintPreviewDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintView.cpp
# End Source File
# Begin Source File

SOURCE=.\ReqCheckDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ReqChkList.cpp
# End Source File
# Begin Source File

SOURCE=.\ReqSeachDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RequestInfListDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchRequestDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TemLoadDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TimeCardDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TimeCardList.cpp
# End Source File
# Begin Source File

SOURCE=.\UserRegDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADOOperation.h
# End Source File
# Begin Source File

SOURCE=.\ADOView.h
# End Source File
# Begin Source File

SOURCE=.\AgreementListDlg.h
# End Source File
# Begin Source File

SOURCE=.\ApplerInfo.h
# End Source File
# Begin Source File

SOURCE=.\ApplerList.h
# End Source File
# Begin Source File

SOURCE=.\ApplerSearchDlg.h
# End Source File
# Begin Source File

SOURCE=.\ApplyEmployeeDlg.h
# End Source File
# Begin Source File

SOURCE=.\AssessDlg.h
# End Source File
# Begin Source File

SOURCE=.\AssessList.h
# End Source File
# Begin Source File

SOURCE=.\AssessSearchDlg.h
# End Source File
# Begin Source File

SOURCE=.\BargainDlg.h
# End Source File
# Begin Source File

SOURCE=.\DeptDutyDlg.h
# End Source File
# Begin Source File

SOURCE=.\DeptInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditableListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\FileInfo.h
# End Source File
# Begin Source File

SOURCE=.\FileRecord.h
# End Source File
# Begin Source File

SOURCE=.\FindDlg.h
# End Source File
# Begin Source File

SOURCE=.\FindEmployeeDlg.h
# End Source File
# Begin Source File

SOURCE=.\HRMS.h
# End Source File
# Begin Source File

SOURCE=.\HRMSDlg.h
# End Source File
# Begin Source File

SOURCE=.\HumanRemoveDlg.h
# End Source File
# Begin Source File

SOURCE=.\LaborageListPrintView.h
# End Source File
# Begin Source File

SOURCE=.\LaborageRecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\LaborRecorDlg.h
# End Source File
# Begin Source File

SOURCE=.\LabRecSearchDlg.h
# End Source File
# Begin Source File

SOURCE=.\LandingDlg.h
# End Source File
# Begin Source File

SOURCE=.\LeaveItemDlg.h
# End Source File
# Begin Source File

SOURCE=.\LeaveList.h
# End Source File
# Begin Source File

SOURCE=.\LoadInTempDlg.h
# End Source File
# Begin Source File

SOURCE=.\msword9.h
# End Source File
# Begin Source File

SOURCE=.\PayClipDlg.h
# End Source File
# Begin Source File

SOURCE=.\PayListDlg.h
# End Source File
# Begin Source File

SOURCE=.\PayListSeachDlg.h
# End Source File
# Begin Source File

SOURCE=.\PrintPreviewDlg.h
# End Source File
# Begin Source File

SOURCE=.\PrintView.h
# End Source File
# Begin Source File

SOURCE=.\ReqCheckDlg.h
# End Source File
# Begin Source File

SOURCE=.\ReqChkList.h
# End Source File
# Begin Source File

SOURCE=.\ReqSeachDlg.h
# End Source File
# Begin Source File

SOURCE=.\RequestInfListDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SearchRequestDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TemLoadDlg.h
# End Source File
# Begin Source File

SOURCE=.\TimeCardDlg.h
# End Source File
# Begin Source File

SOURCE=.\TimeCardList.h
# End Source File
# Begin Source File

SOURCE=.\UserRegDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\down.bmp
# End Source File
# Begin Source File

SOURCE=.\res\down01.bmp
# End Source File
# Begin Source File

SOURCE=.\res\down02.bmp
# End Source File
# Begin Source File

SOURCE=.\res\HRMS.ico
# End Source File
# Begin Source File

SOURCE=.\res\HRMS.rc2
# End Source File
# Begin Source File

SOURCE=.\res\icon.ico
# End Source File
# Begin Source File

SOURCE=.\res\main.bmp
# End Source File
# Begin Source File

SOURCE=.\res\over.bmp
# End Source File
# Begin Source File

SOURCE=.\res\up.bmp
# End Source File
# Begin Source File

SOURCE=.\res\up01.bmp
# End Source File
# Begin Source File

SOURCE=.\res\up02.bmp
# End Source File
# Begin Source File

SOURCE=".\res\∞Ô÷˙.ico"
# End Source File
# Begin Source File

SOURCE=".\res\±ÍÃ‚¿∏.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\≥ˆ«⁄π‹¿Ì.ico"
# End Source File
# Begin Source File

SOURCE=".\res\µ«¬º.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\µ«¬º±≥æ∞.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\–Ω◊ ¬º»Î.ico"
# End Source File
# Begin Source File

SOURCE=".\res\“µº®øº∫À.ico"
# End Source File
# Begin Source File

SOURCE=".\res\”√»À…Í«Î.ico"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
