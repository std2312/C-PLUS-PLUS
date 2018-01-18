; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMystudentsysDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mystudentsys.h"

ClassCount=29
Class1=CMystudentsysApp
Class2=CMystudentsysDlg
Class3=CAboutDlg

ResourceCount=25
Resource1=IDD_DIgregbreak_input
Resource2=IDR_MAINFRAME
Resource3=IDR_TOOLBAR_teacherinfo
Class4=officeset
Class5=COfficeinfodlg
Resource4=IDD_DIgexaminfo_submark
Resource5=IDD_LOGIN
Resource6=IDD_ABOUTBOX
Class6=CSubjectinfo
Class7=CSubjectdlg
Resource7=IDD_DIgclass_subject
Class8=CTeacherinfoset
Class9=CTeacherinfodlg
Resource8=IDD_DIgteacherinfo
Resource9=IDR_TOOLBAR_officeinfo
Class10=CClassinfoset
Resource10=IDD_DIginfostudent
Class11=CClassinfodlg
Resource11=IDD_DIg_subjectinfo
Class12=CClass_subjectset
Class13=CClass_subjectinfodlg
Resource12=IDD_DIgclassinfo
Resource13=IDD_DIgstudentreport
Class14=CExamkindset
Class15=CExamkinddlg
Resource14=IDD_MYSTUDENTSYS_DIALOG
Resource15=IDR_TOOLBAR_classinfo
Resource16=IDR_TOOLBAR_classsubjectinfo
Class16=CExaminfo_submarkset
Class17=CExaminfo_submarkdlg
Resource17=IDD_DIgstudentinfo
Class18=CStudentinfoset
Class19=CStudentinfo_finddlg
Resource18=IDD_Dlguser
Class20=CRegbrreakinfoset
Class21=CInput_regbreakdlg
Resource19=IDD_Dlgregbreak_find
Class22=CReportdlg
Resource20=IDD_DIggrade_leveldlg
Class23=CRegbreak_finddlg
Resource21=IDD_DIgexamkind
Class24=CGrade_levelset
Class25=CGrade_levelinfodlg
Resource22=IDD_DIgofficeinfo
Class26=CLogin
Class27=CLoginSet
Resource23=IDR_TOOLBAR_examkinds
Class28=CUserdlg
Resource24=IDR_TOOLBAR_subjectinfo
Class29=CInfoStudent
Resource25=IDR_MENU1

[CLS:CMystudentsysApp]
Type=0
HeaderFile=mystudentsys.h
ImplementationFile=mystudentsys.cpp
Filter=N

[CLS:CMystudentsysDlg]
Type=0
HeaderFile=mystudentsysDlg.h
ImplementationFile=mystudentsysDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENU_teacherinfo

[CLS:CAboutDlg]
Type=0
HeaderFile=mystudentsysDlg.h
ImplementationFile=mystudentsysDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYSTUDENTSYS_DIALOG]
Type=1
Class=CMystudentsysDlg
ControlCount=1
Control1=IDC_STATIC,static,1342179342

[CLS:officeset]
Type=0
HeaderFile=officeset.h
ImplementationFile=officeset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=officeset

[DB:officeset]
DB=1
DBType=ODBC
ColumnCount=1
Column1=[Office], 12, 30

[DLG:IDD_DIgofficeinfo]
Type=1
Class=COfficeinfodlg
ControlCount=11
Control1=IDCANCEL,button,1342275584
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_officename,edit,1350631552
Control4=IDC_BUTTON_pre,button,1342275584
Control5=IDC_BUTTON_next,button,1342275584
Control6=IDC_BUTTON_last,button,1342275584
Control7=IDC_BUTTON_first,button,1342275584
Control8=IDC_BUTTON_add,button,1342275584
Control9=IDC_BUTTON_del,button,1342275584
Control10=IDC_BUTTON_save,button,1342275584
Control11=IDC_STATIC,button,1342177287

[CLS:COfficeinfodlg]
Type=0
HeaderFile=Officeinfodlg.h
ImplementationFile=Officeinfodlg.cpp
BaseClass=CDialog
Filter=D
LastObject=COfficeinfodlg
VirtualFilter=dWC

[TB:IDR_TOOLBAR_officeinfo]
Type=1
Class=?
Command1=ID_toolbar_add
Command2=ID_toolbar_save
Command3=ID_toolbar_del
Command4=ID_toolbar_first
Command5=ID_toolbar_pre
Command6=ID_toolbar_next
Command7=ID_toolbar_last
CommandCount=7

[DLG:IDD_DIg_subjectinfo]
Type=1
Class=CSubjectdlg
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_subjectname,edit,1350631552
Control4=IDC_subjectid,edit,1350631552
Control5=IDC_STATIC,button,1342177287

[CLS:CSubjectinfo]
Type=0
HeaderFile=Subjectinfo.h
ImplementationFile=Subjectinfo.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CSubjectinfo

[DB:CSubjectinfo]
DB=1
DBType=ODBC
ColumnCount=2
Column1=[subject], 12, 30
Column2=[code], 12, 30

[CLS:CSubjectdlg]
Type=0
HeaderFile=Subjectdlg.h
ImplementationFile=Subjectdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_BTNsave
VirtualFilter=dWC

[TB:IDR_TOOLBAR_subjectinfo]
Type=1
Class=?
Command1=ID_subjectinfo_toolbar_add
Command2=ID_subjectinfo_toolbar_save
Command3=ID_subjectinfo_toolbar_del
Command4=ID_subjectinfo_toolbar_first
Command5=ID_subjectinfo_toolbar_pre
Command6=ID_subjectinfo_toolbar_next
Command7=ID_subjectinfo_toolbar_last
CommandCount=7

[DLG:IDD_DIgteacherinfo]
Type=1
Class=CTeacherinfodlg
ControlCount=13
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_teachername,edit,1350631552
Control9=IDC_teacherid,edit,1350631552
Control10=IDC_teacherkonwledge,edit,1350631552
Control11=IDC_teacheroffice,edit,1350631552
Control12=IDC_teacherlevel,edit,1350631552
Control13=IDC_COMBO_teachersex,combobox,1344340226

[CLS:CTeacherinfoset]
Type=0
HeaderFile=Teacherinfoset.h
ImplementationFile=Teacherinfoset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CTeacherinfoset

[DB:CTeacherinfoset]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[teacherid], 12, 30
Column2=[teachername], 12, 30
Column3=[sex], 12, 10
Column4=[office], 12, 30
Column5=[knowledge], 12, 30
Column6=[Level], 12, 30

[CLS:CTeacherinfodlg]
Type=0
HeaderFile=Teacherinfodlg.h
ImplementationFile=Teacherinfodlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_teacherinfo_toolbar_save
VirtualFilter=dWC

[TB:IDR_TOOLBAR_teacherinfo]
Type=1
Class=?
Command1=ID_teacherinfo_toolbar_add
Command2=ID_teacherinfo_toolbar_save
Command3=ID_teacherinfo_toolbar_del
Command4=ID_teacherinfo_toolbar_first
Command5=ID_teacherinfo_toolbar_pre
Command6=ID_teacherinfo_toolbar_next
Command7=ID_teacherinfo_toolbar_last
CommandCount=7

[CLS:CClassinfoset]
Type=0
HeaderFile=Classinfoset.h
ImplementationFile=Classinfoset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CClassinfoset

[DB:CClassinfoset]
DB=1
DBType=ODBC
ColumnCount=2
Column1=[classname], 12, 30
Column2=[teacher], 12, 30

[DLG:IDD_DIgclassinfo]
Type=1
Class=CClassinfodlg
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_classname,edit,1350631552
Control5=IDC_EDIT_classteacher,edit,1350631552

[TB:IDR_TOOLBAR_classinfo]
Type=1
Class=?
Command1=ID_classinfo_toolbar_add
Command2=ID_classinfo_toolbar_save
Command3=ID_classinfo_toolbar_del
Command4=ID_classinfo_toolbar_first
Command5=ID_classinfo_toolbar_pre
Command6=ID_classinfo_toolbar_next
Command7=ID_classinfo_toolbar_last
CommandCount=7

[CLS:CClassinfodlg]
Type=0
HeaderFile=Classinfodlg.h
ImplementationFile=Classinfodlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CClassinfodlg
VirtualFilter=dWC

[CLS:CClass_subjectset]
Type=0
HeaderFile=Class_subjectset.h
ImplementationFile=Class_subjectset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CClass_subjectset

[DB:CClass_subjectset]
DB=1
DBType=ODBC
ColumnCount=2
Column1=[classname], 12, 30
Column2=[code], 12, 30

[DLG:IDD_DIgclass_subject]
Type=1
Class=CClass_subjectinfodlg
ControlCount=5
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDITclassname,edit,1350631552
Control5=IDC_EDITclassid,edit,1350631552

[CLS:CClass_subjectinfodlg]
Type=0
HeaderFile=Class_subjectinfodlg.h
ImplementationFile=Class_subjectinfodlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDITclassid
VirtualFilter=dWC

[TB:IDR_TOOLBAR_classsubjectinfo]
Type=1
Class=?
Command1=ID_classsubjectinfo_toolbar_add
Command2=ID_classsubjectinfo_toolbar_save
Command3=ID_classsubjectinfo_toolbar_del
Command4=ID_classsubjectinfo_toolbar_first
Command5=ID_classsubjectinfo_toolbar_pre
Command6=ID_classsubjectinfo_toolbar_next
Command7=ID_classsubjectinfo_toolbar_last
CommandCount=7

[CLS:CExamkindset]
Type=0
HeaderFile=Examkindset.h
ImplementationFile=Examkindset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CExamkindset

[DB:CExamkindset]
DB=1
DBType=ODBC
ColumnCount=1
Column1=[kind], 12, 30

[DLG:IDD_DIgexamkind]
Type=1
Class=CExamkinddlg
ControlCount=3
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_examkind,edit,1350631552

[CLS:CExamkinddlg]
Type=0
HeaderFile=Examkinddlg.h
ImplementationFile=Examkinddlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CExamkinddlg
VirtualFilter=dWC

[TB:IDR_TOOLBAR_examkinds]
Type=1
Class=?
Command1=ID_toolbar_examkind_add
Command2=ID_toolbar_examkind_save
Command3=ID_toolbar_examkind_del
Command4=ID_toolbar_examkind_first
Command5=ID_toolbar_examkind_pre
Command6=ID_toolbar_examkind_next
Command7=ID_toolbar_examkind_last
CommandCount=7

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENU_officeinfo
Command2=ID_MENU_subjectinfo
Command3=ID_MENU_teacherinfo
Command4=ID_MENU_classinfo
Command5=ID_MENU_classsubject
Command6=ID_MENU_examkind
Command7=ID_MENU_infostudent
Command8=ID_MENU_inputmarks
Command9=ID_MENU_gradeleveldlg
Command10=ID_MENU_regbreakinfo
Command11=ID_MENU_studentinfo
Command12=ID_MENU_markreport
Command13=ID_MENU_findbreakinfo
Command14=ID_MENU_user
Command15=ID_MENU_exit
Command16=ID_MENU_help
Command17=ID_ABOUT
CommandCount=17

[CLS:CExaminfo_submarkset]
Type=0
HeaderFile=Examinfo_submarkset.h
ImplementationFile=Examinfo_submarkset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CExaminfo_submarkset

[DB:CExaminfo_submarkset]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[studentid], 12, 30
Column2=[code], 12, 30
Column3=[grade], 6, 8
Column4=[kind], 12, 30
Column5=[examdate], 11, 16

[DLG:IDD_DIgexaminfo_submark]
Type=1
Class=CExaminfo_submarkdlg
ControlCount=13
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_sutentid,edit,1350631552
Control9=IDC_examsubject,edit,1350631552
Control10=IDC_submarks,edit,1350631552
Control11=IDC_examkind,edit,1350631552
Control12=IDC_inputsave_marks,button,1342242816
Control13=IDC_examdate_picker,SysDateTimePick32,1342242848

[CLS:CExaminfo_submarkdlg]
Type=0
HeaderFile=Examinfo_submarkdlg.h
ImplementationFile=Examinfo_submarkdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CExaminfo_submarkdlg
VirtualFilter=dWC

[CLS:CStudentinfoset]
Type=0
HeaderFile=Studentinfoset.h
ImplementationFile=Studentinfoset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CStudentinfoset

[DB:CStudentinfoset]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[studentid], 12, 30
Column2=[studentname], 12, 30
Column3=[sex], 12, 10
Column4=[age], 6, 8
Column5=[addr], 12, 30
Column6=[phone], 12, 30
Column7=[class], 12, 30

[DLG:IDD_DIgstudentinfo]
Type=1
Class=CStudentinfo_finddlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_findstudent_id,edit,1350631552
Control3=IDC_findstudentinfo,button,1342242816
Control4=IDC_LIST1,SysListView32,1350631425

[CLS:CStudentinfo_finddlg]
Type=0
HeaderFile=Studentinfo_finddlg.h
ImplementationFile=Studentinfo_finddlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_findstudentinfo
VirtualFilter=dWC

[CLS:CRegbrreakinfoset]
Type=0
HeaderFile=Regbrreakinfoset.h
ImplementationFile=Regbrreakinfoset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CRegbrreakinfoset]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[studentid], 12, 30
Column2=[breakcontent], 12, 100
Column3=[handleresult], 12, 100
Column4=[memo], 12, 100
Column5=[breaktime], 11, 16

[DLG:IDD_DIgregbreak_input]
Type=1
Class=CInput_regbreakdlg
ControlCount=13
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_regbreakstudentid,edit,1350631552
Control9=IDC_regbreak_content,edit,1350631556
Control10=IDC_regbreak_result,edit,1350631552
Control11=IDC_regbreak_memo,edit,1350631552
Control12=IDC_regbreak_date,SysDateTimePick32,1342242848
Control13=IDC_Btn_inputregbreak,button,1342242816

[CLS:CInput_regbreakdlg]
Type=0
HeaderFile=Input_regbreakdlg.h
ImplementationFile=Input_regbreakdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_Btn_inputregbreak

[DLG:IDD_DIgstudentreport]
Type=1
Class=CReportdlg
ControlCount=3
Control1=IDC_Btnreport,button,1342242816
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352

[CLS:CReportdlg]
Type=0
HeaderFile=Reportdlg.h
ImplementationFile=Reportdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CReportdlg
VirtualFilter=dWC

[DLG:IDD_Dlgregbreak_find]
Type=1
Class=CRegbreak_finddlg
ControlCount=14
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_studentid,edit,1350631552
Control4=IDC_Btnfind_regbreakinfo,button,1342242816
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_regfind_date,SysDateTimePick32,1342242848
Control11=IDC_EDIT_regcontent,edit,1350631552
Control12=IDC_EDIT_reghandleresult,edit,1350631552
Control13=IDC_EDIT_regmemo,edit,1350631552
Control14=IDC_LIST2,SysListView32,1350631425

[CLS:CRegbreak_finddlg]
Type=0
HeaderFile=Regbreak_finddlg.h
ImplementationFile=Regbreak_finddlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CRegbreak_finddlg
VirtualFilter=dWC

[CLS:CGrade_levelset]
Type=0
HeaderFile=Grade_levelset.h
ImplementationFile=Grade_levelset.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CGrade_levelset

[DB:CGrade_levelset]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[grade_level], 1, 10
Column2=[up_grade], 6, 8
Column3=[low_grade], 6, 8

[DLG:IDD_DIggrade_leveldlg]
Type=1
Class=CGrade_levelinfodlg
ControlCount=13
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_upgrade,edit,1350631552
Control5=IDC_EDIT_lowgrade,edit,1350631552
Control6=IDC_Btn_setgradelevel,button,1342242816
Control7=IDC_LIST3,SysListView32,1350631425
Control8=IDC_Btn_findbest,button,1342242816
Control9=IDC_Btnfindbetter,button,1342242816
Control10=IDC_Btnfindnormal,button,1342242816
Control11=IDC_Btnfindworse,button,1342242816
Control12=IDC_COMBO1,combobox,1344339970
Control13=IDC_STATIC,static,1342308352

[CLS:CGrade_levelinfodlg]
Type=0
HeaderFile=Grade_levelinfodlg.h
ImplementationFile=Grade_levelinfodlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENU_help
VirtualFilter=dWC

[DLG:IDD_LOGIN]
Type=1
Class=CLogin
ControlCount=6
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631584
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CLoginSet]
Type=0
HeaderFile=LoginSet.h
ImplementationFile=LoginSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CLoginSet

[DB:CLoginSet]
DB=1
DBType=ODBC
ColumnCount=2
Column1=[username], 12, 20
Column2=[password], 12, 10

[DLG:IDD_Dlguser]
Type=1
Class=CUserdlg
ControlCount=9
Control1=IDC_LIST1,SysListView32,1350631424
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_BUTTADD,button,1342242816
Control7=IDC_BUTMOD,button,1342242816
Control8=IDC_BUTDEL,button,1342242816
Control9=IDCANCEL,button,1342242816

[CLS:CUserdlg]
Type=0
HeaderFile=Userdlg.h
ImplementationFile=Userdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTADD

[DLG:IDD_DIginfostudent]
Type=1
Class=CInfoStudent
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_studentsex,edit,1350631552
Control8=IDC_studentage,edit,1350631552
Control9=IDC_studentphone,edit,1350631552
Control10=IDC_studentname,edit,1350631552
Control11=IDC_studentclass,edit,1350631552
Control12=IDC_studentaddr,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_findstudent_id,edit,1350631552

[CLS:CInfoStudent]
Type=0
HeaderFile=InfoStudent.h
ImplementationFile=InfoStudent.cpp
BaseClass=CDialog
Filter=D
LastObject=CInfoStudent
VirtualFilter=dWC

