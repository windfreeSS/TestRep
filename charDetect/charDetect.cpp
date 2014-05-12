// charDetect.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "charDetect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
/**/
#include "src\uchardet.h"
typedef void* uchardet_t;
/**/

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CcharDetectApp

BEGIN_MESSAGE_MAP(CcharDetectApp, CWinApp)
END_MESSAGE_MAP()


// CcharDetectApp 构造

CcharDetectApp::CcharDetectApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CcharDetectApp 对象

CcharDetectApp theApp;


// CcharDetectApp 初始化

BOOL CcharDetectApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
/* uchardet_new  */
extern "C" __declspec(dllexport) uchardet_t chardet_new(void) 
{  
	return uchardet_new();
}
/* uchardet_delete */
extern "C" __declspec(dllexport) void chardet_delete(uchardet_t ud) 
{  
    uchardet_delete(ud); 
}
/* uchardet_handle_data */
extern "C" __declspec(dllexport) int chardet_handle_data(uchardet_t ud, const char * data, size_t len) 
{  
	return uchardet_handle_data( ud, data,  len);
}
/* uchardet_data_end */
extern "C" __declspec(dllexport) void chardet_data_end(uchardet_t ud) 
{  
    uchardet_data_end(ud);
}
/* uchardet_reset */
extern "C" __declspec(dllexport) void chardet_reset(uchardet_t ud) 
{  
    uchardet_reset(ud);
}
extern "C" __declspec(dllexport) const char* chardet_get_charset(uchardet_t ud) 
{  
	return uchardet_get_charset(ud);
}