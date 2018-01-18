///////////////////////////////////////////////////////////////////////////////////////////
#ifndef __PUB_H
#define __PUB_H

//图书调拨主结构
typedef struct _tag_BookMoveMain
{
	CString strAdjustNo;  //调拨单号
	CString strCKName;    //仓库
	CString strDesk;      //柜台
	CString strOperator;   //操作员
	DATE    datetime;     //时间
}BOOK_MOVE_MAIN, *LPBOOK_MOVE_MAIN;

//图书调拨明细
typedef struct _tag_BookMove
{
	CString strAdjustNo;  //调拨单号
	CString strDXCode;    //条形码
	double  dCount;       //数量
}BOOK_MOVE, *LPBOOK_MOVE;

//图书仓库
typedef struct _tag_BookStorage
{
	CString strDXCode; //条形码
	CString strCKName; //仓库
	double  dCount;    //数量
}BOOK_STOREAGE, *LPBOOK_STOREAGE;

//图书种类
typedef struct _tag_BookKinds
{
	CString strKinds;  //图书种类
}BOOK_KINDS, *LPBOOK_KINDS;

//商品销售主结构
typedef struct _tag_SellMain
{
	CString strSellNo;   //销售单号
	CString strCustomer;   //顾客
	CString strOperator; //操作员
	double  dZHE;        //折扣
	double  dTotalMoney; //总计
	double  dSrcMoney;   //应收金额
	double  dDesMoney;   //实收金额
	DATE    datetime;    //时间
	CString strCounter;     //柜台
}SELL_MAIN, *LPSELL_MAIN;

//供应商信息结构
typedef struct _tag_ProviderInfo
{
	CString strProName;    //供应商名称
	CString strCEO;        //法人
	CString strManager;    //负责人
	CString strPhone;      //联系电话
	CString strAddress;    //详细地址
	CString strNetAddress; //网址
	CString strEmail;      //邮箱
}PROVIDER_INFO, *LPPROVIDER_INFO;

//仓库信息结构
typedef struct _tag_StorageInfo
{
	CString strCK; //仓库
}STOREAGE_INFO, *LPSTOREAGE_INFO;

//柜台信息结构
typedef struct _tag_Counter_Info
{
	CString strCounterName;  //柜台名称
}COUNTER_INFO, *LPCOUNTER_INFO;

//图书信息表结构
typedef struct _tag_BookInfo  
{
	CString  strBookName;  //书籍名称
	CString  strZHJCode;   //助记码
	CString  strDXCode;    //条形码
	CString  strAuthor;	   //作者
	CString  strPublic;    //出版社
	double   dPrice;       //价格
	CString  strMark;      //备注
	CString  strKinds;      //种类
}BOOK_INFO, *LPBOOK_INFO;

//商品销售明细结构
typedef struct _tag_SellSub
{
	CString strSellNo;  //销售单号
	CString strDXCode;  //条形码
	double  dPrice;     //单价
	double  dCount;     //数量
	double  dZHE;       //折扣
	double  dMoney;     //金额
}SELL_SUB, *LPSELL_SUB; 

//操作员信息结构
typedef struct _tag_Operator
{
	CString strOperName;  //操作员名称
	CString strOperPass;  //操作员密码
	int     iOperLevel;   //操作员级别
}OPERATOR, *LPOPERATOR;

//图书入库结构
typedef struct _tag_InStorageMain
{
	CString strInStorageNo; //入库单号
	CString strProvider;    //供应商
	CString strOperator;    //操作员
	double  dZHE;           //折扣
	double  dTotallMoney;   //总计
	double  dSrcMoney;      //应付金额
	double  dDesMoney;      //实付金额
	DATE    datetime;       //时间
}IN_STORAGE_MAIN, *LPIN_STORAGE_MAIN;

//柜台图书结构
typedef struct _tag_CounterBook
{
	CString strTXCode;  //条形码
	CString strCounter; //柜台名称
	double  dCount;     //数量
}COUNTER_BOOK, *LPCOUNTER_BOOK;

//入库明细结构
typedef struct _tag_InStorageSub
{
	CString strInStorageNo; //入库单号
	CString strTXCode;      //条形码
	double  dPrice;         //单价
	double  dCount;         //数量
	double  dZHE;           //折扣
	double  dMoney;         //金额
	CString strStorageName; //仓库名称
}IN_STORAGE_SUB, *LPIN_STORAGE_SUB;

//销售退货明细结构
typedef struct _tag_CancelSell_Sub
{
	CString strCancelSellNo;
	CString strTXCode;
	double  dPrice;
	double  dCount;
	double  dZHE;
	double  dMoney;
}CANCEL_SELL_SUB, *LPCANCEL_SELL_SUB;

//条形码
typedef struct _tag_TXCode
{
	CString strTXCode; //条形码
	double  dMoney;    //售价
}TX_CODE, *LPTX_CODE;

//入库退货明细结构
typedef struct _tag_CancelInStorageSub
{
	CString strCancelNo;    //退货单号
	CString strTXCode;      //条形码
	double  dPrice;         //单价
	double  dCount;         //数量
	double  dZHE;           //折扣
	double  dMoney;         //金额
	CString strStorageName; //仓库名称
}CANCELI_IN_STORAGE_SUB, *LPCANCELI_IN_STORAGE_SUB;

//入库退货主结构
typedef struct _tag_CancelInStorageMain
{
	CString strCancelNo;  //退货单号
	CString strProvider;  //供应商
	CString strOperator;  //操作员
	double  dZHE;         //折扣
	double  dSrcMoney;    //应付金额
	double  dDesMoney;    //实付金额
	DATE    datetime;     //时间
}CANCELI_IN_STORAGE_MAIN, *LPCANCELI_IN_STORAGE_MAIN;

//销售退货主结构
typedef struct _tag_CancelSellMain
{
	CString strCancelSellNo;  //销售退货单号
	CString strCustomer;      //顾客
	CString strOperator;      //操作员
	double  dZHE;             //折扣
	double  dTotallMoney;     //总计
	double  dSrcMoney;        //应付金额
	double  dDesMoney;        //实付金额
	DATE    datetime;         //时间
	CString strCounter;	      //柜台
}CANCEL_SELL_MAIN, *LPCANCEL_SELL_MAIN;

#endif