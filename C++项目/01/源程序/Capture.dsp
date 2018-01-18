# Microsoft Developer Studio Project File - Name="Capture" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Capture - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Capture.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Capture.mak" CFG="Capture - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Capture - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Capture - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Capture - Win32 Release"

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

!ELSEIF  "$(CFG)" == "Capture - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Sa7134Capture.lib MediaTransmit.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Capture - Win32 Release"
# Name "Capture - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Autodlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Capture.cpp
# End Source File
# Begin Source File

SOURCE=.\Capture.rc
# End Source File
# Begin Source File

SOURCE=.\CaptureDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ControlForm.cpp
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\Managedlg.cpp
# End Source File
# Begin Source File

SOURCE=.\mediaplayer2.cpp
# End Source File
# Begin Source File

SOURCE=.\mediaplayerdvd.cpp
# End Source File
# Begin Source File

SOURCE=.\mscomm.cpp
# End Source File
# Begin Source File

SOURCE=.\Panel.cpp
# End Source File
# Begin Source File

SOURCE=.\Playdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PreView.cpp
# End Source File
# Begin Source File

SOURCE=.\StageButton.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Autodlg.h
# End Source File
# Begin Source File

SOURCE=.\Capture.h
# End Source File
# Begin Source File

SOURCE=.\CaptureDlg.h
# End Source File
# Begin Source File

SOURCE=.\ControlForm.h
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\Managedlg.h
# End Source File
# Begin Source File

SOURCE=.\mediaplayer2.h
# End Source File
# Begin Source File

SOURCE=.\mediaplayerdvd.h
# End Source File
# Begin Source File

SOURCE=.\mscomm.h
# End Source File
# Begin Source File

SOURCE=.\Panel.h
# End Source File
# Begin Source File

SOURCE=.\Playdlg.h
# End Source File
# Begin Source File

SOURCE=.\PreView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Sa7134Capture.h
# End Source File
# Begin Source File

SOURCE=.\StageButton.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\07.ico
# End Source File
# Begin Source File

SOURCE=.\res\42.ico
# End Source File
# Begin Source File

SOURCE=.\res\BackGround.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BK.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BottomBand.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Capture.ico
# End Source File
# Begin Source File

SOURCE=.\res\Capture.rc2
# End Source File
# Begin Source File

SOURCE=.\res\closebutton.bmp
# End Source File
# Begin Source File

SOURCE=.\res\closehotbutton.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftBand.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LeftTitle.bmp
# End Source File
# Begin Source File

SOURCE=.\res\maxbutton.bmp
# End Source File
# Begin Source File

SOURCE=.\res\maxhotbutton.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MidTitle.bmp
# End Source File
# Begin Source File

SOURCE=.\res\minbutton.bmp
# End Source File
# Begin Source File

SOURCE=.\res\minhotbutton.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RightBand.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RightTitle.bmp
# End Source File
# Begin Source File

SOURCE=".\res\°´Å¥.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\µÇÂ¼.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\avi_001.avi
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section Capture : {648A5600-2C6E-101B-82B6-000000000014}
# 	2:21:DefaultSinkHeaderFile:mscomm.h
# 	2:16:DefaultSinkClass:CMSComm
# End Section
# Section Capture : {E6E17E90-DF38-11CF-8E74-00A0C90F26F8}
# 	2:5:Class:CMSComm
# 	2:10:HeaderFile:mscomm.h
# 	2:8:ImplFile:mscomm.cpp
# End Section
# Section Capture : {20D4F5E0-5475-11D2-9774-0000F80855E6}
# 	2:5:Class:CMediaPlayer2
# 	2:10:HeaderFile:mediaplayer2.h
# 	2:8:ImplFile:mediaplayer2.cpp
# End Section
# Section Capture : {22D6F312-B0F6-11D0-94AB-0080C74C7E95}
# 	2:21:DefaultSinkHeaderFile:mediaplayer2.h
# 	2:16:DefaultSinkClass:CMediaPlayer2
# End Section
# Section Capture : {746EB440-3835-11D2-9774-0000F80855E6}
# 	2:5:Class:CMediaPlayerDvd
# 	2:10:HeaderFile:mediaplayerdvd.h
# 	2:8:ImplFile:mediaplayerdvd.cpp
# End Section
