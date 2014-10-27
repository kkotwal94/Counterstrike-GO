// CounterStrikeD3D.cpp : Defines the exported functions for the DLL application.
#include "stdafx.h"
#include "ModelRec.h"
#include <windows.h>
#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
using namespace std;
LPDIRECT3DTEXTURE9 texRed, texGreen, texYellow, texOrange, texBlue, texCyan, texPink, texPurple, texWhite, texBlack, texSteelBlue, texBrown, texTeal, texLightSteelBlue, texLightBlue, texSalmon, texLime, texElectricLime, texGold, texOrangeRed, texGreenYellow, texAquaMarine, texSkyBlue, texSlateBlue, texCrimson, texDarkOliveGreen, texPaleGreen, texDarkGoldenRod, texFireBrick, texDarkBlue, texDarkerBlue, texDarkYellow, texLightYellow;
int chams;
//=====================================================================================
HRESULT GenerateTexture(IDirect3DDevice9 *pD3Ddev, IDirect3DTexture9 **ppD3Dtex, DWORD colour32)
{
	if (FAILED(pD3Ddev->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex, NULL)))
		return E_FAIL;

	WORD colour16 = ((WORD)((colour32 >> 28) & 0xF) << 12)
		| (WORD)(((colour32 >> 20) & 0xF) << 8)
		| (WORD)(((colour32 >> 12) & 0xF) << 4)
		| (WORD)(((colour32 >> 4) & 0xF) << 0);

	D3DLOCKED_RECT d3dlr;
	(*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
	WORD *pDst16 = (WORD*)d3dlr.pBits;

	for (int xy = 0; xy < 8 * 8; xy++)
		*pDst16++ = colour16;

	(*ppD3Dtex)->UnlockRect(0);

	return S_OK;
}


//=====================================================================================

typedef HRESULT(WINAPI* CreateDevice_Prototype)        (LPDIRECT3D9, UINT, D3DDEVTYPE, HWND, DWORD, D3DPRESENT_PARAMETERS*, LPDIRECT3DDEVICE9*);
typedef HRESULT(WINAPI* Reset_Prototype)               (LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
typedef HRESULT(WINAPI* EndScene_Prototype)            (LPDIRECT3DDEVICE9);
typedef HRESULT(WINAPI* DrawIndexedPrimitive_Prototype)(LPDIRECT3DDEVICE9, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);

CreateDevice_Prototype         CreateDevice_Pointer = NULL;
Reset_Prototype                Reset_Pointer = NULL;
EndScene_Prototype             EndScene_Pointer = NULL;
DrawIndexedPrimitive_Prototype DrawIndexedPrimitive_Pointer = NULL;

HRESULT WINAPI Direct3DCreate9_VMTable(VOID);
HRESULT WINAPI CreateDevice_Detour(LPDIRECT3D9, UINT, D3DDEVTYPE, HWND, DWORD, D3DPRESENT_PARAMETERS*, LPDIRECT3DDEVICE9*);
HRESULT WINAPI Reset_Detour(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
HRESULT WINAPI EndScene_Detour(LPDIRECT3DDEVICE9);
HRESULT WINAPI DrawIndexedPrimitive_Detour(LPDIRECT3DDEVICE9, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);

DWORD WINAPI VirtualMethodTableRepatchingLoopToCounterExtensionRepatching(LPVOID);
PDWORD Direct3D_VMTable = NULL;

//=====================================================================================

BOOL WINAPI DllMain(HINSTANCE hinstModule, DWORD dwReason, LPVOID lpvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hinstModule);

		if (Direct3DCreate9_VMTable() == D3D_OK)
			return TRUE;
	}

	return FALSE;
}

//=====================================================================================

HRESULT WINAPI Direct3DCreate9_VMTable(VOID)
{
	LPDIRECT3D9 Direct3D_Object = Direct3DCreate9(D3D_SDK_VERSION);

	if (Direct3D_Object == NULL)
		return D3DERR_INVALIDCALL;

	Direct3D_VMTable = (PDWORD)*(PDWORD)Direct3D_Object;
	Direct3D_Object->Release();

	DWORD dwProtect;

	if (VirtualProtect(&Direct3D_VMTable[16], sizeof(DWORD), PAGE_READWRITE, &dwProtect) != 0)
	{
		*(PDWORD)&CreateDevice_Pointer = Direct3D_VMTable[16];
		*(PDWORD)&Direct3D_VMTable[16] = (DWORD)CreateDevice_Detour;

		if (VirtualProtect(&Direct3D_VMTable[16], sizeof(DWORD), dwProtect, &dwProtect) == 0)
			return D3DERR_INVALIDCALL;
	}
	else
		return D3DERR_INVALIDCALL;

	return D3D_OK;
}

//=====================================================================================

HRESULT WINAPI CreateDevice_Detour(LPDIRECT3D9 Direct3D_Object, UINT Adapter, D3DDEVTYPE DeviceType, HWND FocusWindow,
	DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* PresentationParameters,
	LPDIRECT3DDEVICE9* Returned_Device_Interface)
{
	HRESULT Returned_Result = CreateDevice_Pointer(Direct3D_Object, Adapter, DeviceType, FocusWindow, BehaviorFlags,
		PresentationParameters, Returned_Device_Interface);

	DWORD dwProtect;

	if (VirtualProtect(&Direct3D_VMTable[16], sizeof(DWORD), PAGE_READWRITE, &dwProtect) != 0)
	{
		*(PDWORD)&Direct3D_VMTable[16] = *(PDWORD)&CreateDevice_Pointer;
		CreateDevice_Pointer = NULL;

		if (VirtualProtect(&Direct3D_VMTable[16], sizeof(DWORD), dwProtect, &dwProtect) == 0)
			return D3DERR_INVALIDCALL;
	}
	else
		return D3DERR_INVALIDCALL;

	if (Returned_Result == D3D_OK)
	{
		Direct3D_VMTable = (PDWORD)*(PDWORD)*Returned_Device_Interface;

		*(PDWORD)&Reset_Pointer = (DWORD)Direct3D_VMTable[16];
		*(PDWORD)&EndScene_Pointer = (DWORD)Direct3D_VMTable[42];
		*(PDWORD)&DrawIndexedPrimitive_Pointer = (DWORD)Direct3D_VMTable[82];

		if (CreateThread(NULL, 0, VirtualMethodTableRepatchingLoopToCounterExtensionRepatching, NULL, 0, NULL) == NULL)
			return D3DERR_INVALIDCALL;
	}

	return Returned_Result;
}

//=====================================================================================

HRESULT WINAPI Reset_Detour(LPDIRECT3DDEVICE9 Device_Interface, D3DPRESENT_PARAMETERS* PresentationParameters)
{
	return Reset_Pointer(Device_Interface, PresentationParameters);
}

//=====================================================================================

HRESULT WINAPI EndScene_Detour(LPDIRECT3DDEVICE9 Device_Interface)
{
	GenerateTexture(Device_Interface, &texGreen, D3DCOLOR_ARGB(255, 0, 255, 0));
	GenerateTexture(Device_Interface, &texRed, D3DCOLOR_ARGB(255, 255, 0, 0));
	GenerateTexture(Device_Interface, &texBlue, D3DCOLOR_ARGB(255, 0, 0, 255));
	GenerateTexture(Device_Interface, &texOrange, D3DCOLOR_ARGB(255, 255, 165, 0));
	GenerateTexture(Device_Interface, &texYellow, D3DCOLOR_ARGB(255, 255, 255, 0));
	GenerateTexture(Device_Interface, &texPink, D3DCOLOR_ARGB(255, 255, 192, 203));
	GenerateTexture(Device_Interface, &texCyan, D3DCOLOR_ARGB(255, 0, 255, 255));
	GenerateTexture(Device_Interface, &texPurple, D3DCOLOR_ARGB(255, 160, 32, 240));
	GenerateTexture(Device_Interface, &texBlack, D3DCOLOR_ARGB(255, 0, 0, 0));
	GenerateTexture(Device_Interface, &texWhite, D3DCOLOR_ARGB(255, 255, 255, 255));
	GenerateTexture(Device_Interface, &texSteelBlue, D3DCOLOR_ARGB(255, 33, 104, 140));
	GenerateTexture(Device_Interface, &texLightSteelBlue, D3DCOLOR_ARGB(255, 201, 255, 255));
	GenerateTexture(Device_Interface, &texLightBlue, D3DCOLOR_ARGB(255, 26, 140, 306));
	GenerateTexture(Device_Interface, &texSalmon, D3DCOLOR_ARGB(255, 196, 112, 112));
	GenerateTexture(Device_Interface, &texBrown, D3DCOLOR_ARGB(255, 168, 99, 20));
	GenerateTexture(Device_Interface, &texTeal, D3DCOLOR_ARGB(255, 38, 140, 140));
	GenerateTexture(Device_Interface, &texLime, D3DCOLOR_ARGB(255, 50, 205, 50));
	GenerateTexture(Device_Interface, &texElectricLime, D3DCOLOR_ARGB(255, 204, 255, 0));
	GenerateTexture(Device_Interface, &texGold, D3DCOLOR_ARGB(255, 255, 215, 0));
	GenerateTexture(Device_Interface, &texOrangeRed, D3DCOLOR_ARGB(255, 255, 69, 0));
	GenerateTexture(Device_Interface, &texGreenYellow, D3DCOLOR_ARGB(255, 173, 255, 47));
	GenerateTexture(Device_Interface, &texAquaMarine, D3DCOLOR_ARGB(255, 127, 255, 212));
	GenerateTexture(Device_Interface, &texSkyBlue, D3DCOLOR_ARGB(255, 0, 191, 255));
	GenerateTexture(Device_Interface, &texSlateBlue, D3DCOLOR_ARGB(255, 132, 112, 255));
	GenerateTexture(Device_Interface, &texCrimson, D3DCOLOR_ARGB(255, 220, 20, 60));
	GenerateTexture(Device_Interface, &texDarkOliveGreen, D3DCOLOR_ARGB(255, 188, 238, 104));
	GenerateTexture(Device_Interface, &texPaleGreen, D3DCOLOR_ARGB(255, 154, 255, 154));
	GenerateTexture(Device_Interface, &texDarkGoldenRod, D3DCOLOR_ARGB(255, 255, 185, 15));
	GenerateTexture(Device_Interface, &texFireBrick, D3DCOLOR_ARGB(255, 255, 48, 48));
	GenerateTexture(Device_Interface, &texDarkBlue, D3DCOLOR_ARGB(255, 0, 0, 204));
	GenerateTexture(Device_Interface, &texDarkerBlue, D3DCOLOR_ARGB(255, 0, 0, 153));
	GenerateTexture(Device_Interface, &texDarkYellow, D3DCOLOR_ARGB(255, 255, 204, 0));
	GenerateTexture(Device_Interface, &texLightYellow, D3DCOLOR_ARGB(255, 255, 255, 153));
	if (GetAsyncKeyState(VK_F1) & 1) // if we click f1
	{
		chams = !chams;
	} // chams = on
	return EndScene_Pointer(Device_Interface);
}

//=====================================================================================

HRESULT WINAPI DrawIndexedPrimitive_Detour(LPDIRECT3DDEVICE9 Device_Interface, D3DPRIMITIVETYPE Type, INT BaseIndex,
	UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount)
{
	LPDIRECT3DVERTEXBUFFER9 Stream_Data;
	UINT Offset = 0;
	UINT Stride = 32;

	if (Device_Interface->GetStreamSource(0, &Stream_Data, &Offset, &Stride) == D3D_OK)
		Stream_Data->Release();
	if (chams) {
		if (ct_gign || ct_seal || ct_fbi || ct_idf || ct_sas || ct_swat || ct_gsg9)
		{
			Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
			Device_Interface->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
			Device_Interface->SetTexture(0, texBlue);
			Device_Interface->SetRenderState(D3DRS_LIGHTING, false);
			DrawIndexedPrimitive_Pointer(Device_Interface, Type, BaseIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
			Device_Interface->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			Device_Interface->SetTexture(0, texGreen);
		}

		if (t_pirate || t_phoenix || t_anarchiste || t_elitecrew || t_separatiste || t_professionnel || t_balkan)
		{
			Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
			Device_Interface->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
			Device_Interface->SetTexture(0, texRed);
			Device_Interface->SetRenderState(D3DRS_LIGHTING, false);
			DrawIndexedPrimitive_Pointer(Device_Interface, Type, BaseIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
			Device_Interface->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			Device_Interface->SetTexture(0, texOrange);
		}

	}

	return DrawIndexedPrimitive_Pointer(Device_Interface, Type, BaseIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
}

//=====================================================================================

DWORD WINAPI VirtualMethodTableRepatchingLoopToCounterExtensionRepatching(LPVOID Param)
{
	UNREFERENCED_PARAMETER(Param);

	while (1)
	{
		Sleep(100);

		*(PDWORD)&Direct3D_VMTable[16] = (DWORD)Reset_Detour;
		*(PDWORD)&Direct3D_VMTable[42] = (DWORD)EndScene_Detour;
		*(PDWORD)&Direct3D_VMTable[82] = (DWORD)DrawIndexedPrimitive_Detour;
	}

	return 1;
}

//=====================================================================================


