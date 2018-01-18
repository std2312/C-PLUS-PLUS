
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//                            声明RXDLL中函数

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
函数原型：CString CharToLetterCode(CString string)
主要功能: 返回指定字符串的拼音简码。 
　参数:                                          
	String:要获得拼音简码的字符串。*/ 

typedef CString(_CharToLetterCode)(CString);
extern _CharToLetterCode* CharToLetterCode;
/**************************************************************
CString Padl(CString String, int digit, CString Fill,int Style)
主要功能: 在字符中前添加指定个数的字符。 
　参数:                                          
	String：源字符串 。       
	digit：字符串的长度。                           
	fill: 添充的字符串。
	Style: 决定字符串添充方式 如果为1时，在字符前填充  如果为0 在字符串后填充*/
typedef CString(_Padl)(CString,int,CString,int);
extern _Padl* Padl;
/**************************************************************
CTime CStringTOCTime(CString cDate)
主要功能: 将时间字符串转换成CTime类型。 
　参数:                                          
	cDate：指定字符型字符串 。 */
typedef CTime(_CStringTOCTime)(CString);
extern _CStringTOCTime* CStringTOCTime; 
/**************************************************************
CString CTimeToCString(CTime date)    
主要功能: 将CTime类型数据转换在时间字符串。 
　参数:                                          
	date:CTime类型数据 。*/
typedef CString(_CTimeToCString)(CTime);
extern _CTimeToCString* CTimeToCString; 
/**************************************************************
CString MoneyToChineseCode(CString sMoney)
主要功能: 将阿拉伯数字小写金额转换成汉字大写金额 
　参数:                                          
	sMoney:小写金额字符串。*/
typedef CString(_MoneyToChineseCode)(CString);
extern _MoneyToChineseCode* MoneyToChineseCode; 
