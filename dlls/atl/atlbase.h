/*
 * Implementation of the Active Template Library (atl.dll)
 *
 * Copyright 2004 Aric Stewart for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

typedef HRESULT (WINAPI _ATL_CREATORFUNC)(void* pv, REFIID riid, LPVOID* ppv);
typedef HRESULT (WINAPI _ATL_CREATORARGFUNC)(void* pv, REFIID riid, LPVOID* ppv, DWORD dw);
typedef HRESULT (WINAPI _ATL_MODULEFUNC)(DWORD dw);
typedef LPCSTR (WINAPI _ATL_DESCRIPTIONFUNCA)();
typedef LPCWSTR (WINAPI _ATL_DESCRIPTIONFUNCW)();
typedef const struct _ATL_CATMAP_ENTRY* (_ATL_CATMAPFUNC)();
typedef void (WINAPI _ATL_TERMFUNC)(DWORD dw);

typedef struct _ATL_OBJMAP_ENTRYA_TAG
{
    const CLSID* pclsid;
    HRESULT (WINAPI *pfnUpdateRegistry)(BOOL bRegister);
    _ATL_CREATORFUNC* pfnGetClassObject;
    _ATL_CREATORFUNC* pfnCreateInstance;
    IUnknown* pCF;
    DWORD dwRegister;
    _ATL_DESCRIPTIONFUNCA* pfnGetObjectDescription;
    _ATL_CATMAPFUNC* pfnGetCategoryMap;
    void (WINAPI *pfnObjectMain)(BOOL bStarting);
}_ATL_OBJMAP_ENTRYA;

typedef struct _ATL_OBJMAP_ENTRYW_TAG
{
    const CLSID* pclsid;
    HRESULT (WINAPI *pfnUpdateRegistry)(BOOL bRegister);
    _ATL_CREATORFUNC* pfnGetClassObject;
    _ATL_CREATORFUNC* pfnCreateInstance;
    IUnknown* pCF;
    DWORD dwRegister;
    _ATL_DESCRIPTIONFUNCW* pfnGetObjectDescription;
    _ATL_CATMAPFUNC* pfnGetCategoryMap;
    void (WINAPI *pfnObjectMain)(BOOL bStarting);
} _ATL_OBJMAP_ENTRYW;


typedef struct _ATL_TERMFUNC_ELEM_TAG
{
    _ATL_TERMFUNC* pFunc;
    DWORD dw;
    struct _ATL_TERMFUNC_ELEM_TAG* pNext;
} _ATL_TERMFUNC_ELEM;

typedef struct _AtlCreateWndData_TAG
{
    void* m_pThis;
    DWORD m_dwThreadID;
    struct _AtlCreateWndData_TAG* m_pNext;
} _AtlCreateWndData;

typedef struct _ATL_MODULEA_TAG
{
    UINT cbSize;
    HINSTANCE m_hInst;
    HINSTANCE m_hInstResource;
    HINSTANCE m_hInstTypeLib;
    _ATL_OBJMAP_ENTRYA* m_pObjMap;
    LONG m_nLockCnt;
    HANDLE m_hHeap;
    union
    {
        CRITICAL_SECTION m_csTypeInfoHolder;
        CRITICAL_SECTION m_csStaticDataInit;
    } u;
    CRITICAL_SECTION m_csWindowCreate;
    CRITICAL_SECTION m_csObjMap;

    DWORD dwAtlBuildVer;
    _AtlCreateWndData* m_pCreateWndList;
    BOOL m_bDestroyHeap;
    GUID* pguidVer;
    DWORD m_dwHeaps;
    HANDLE* m_phHeaps;
    int m_nHeap;
    _ATL_TERMFUNC_ELEM* m_pTermFuncs;
} _ATL_MODULEA;

typedef struct _ATL_MODULEW_TAG
{
    UINT cbSize;
    HINSTANCE m_hInst;
    HINSTANCE m_hInstResource;
    HINSTANCE m_hInstTypeLib;
    _ATL_OBJMAP_ENTRYW* m_pObjMap;
    LONG m_nLockCnt;
    HANDLE m_hHeap;
    union
    {
        CRITICAL_SECTION m_csTypeInfoHolder;
        CRITICAL_SECTION m_csStaticDataInit;
    } u;
    CRITICAL_SECTION m_csWindowCreate;
    CRITICAL_SECTION m_csObjMap;

    DWORD dwAtlBuildVer;
    _AtlCreateWndData* m_pCreateWndList;
    BOOL m_bDestroyHeap;
    GUID* pguidVer;
    DWORD m_dwHeaps;
    HANDLE* m_phHeaps;
    int m_nHeap;
    _ATL_TERMFUNC_ELEM* m_pTermFuncs;
} _ATL_MODULEW;

typedef struct _ATL_INTMAP_ENTRY_TAG
{
    const IID* piid;
    DWORD dw;
    _ATL_CREATORARGFUNC* pFunc;
} _ATL_INTMAP_ENTRY;

HRESULT WINAPI AtlModuleInit(_ATL_MODULEA* pM, _ATL_OBJMAP_ENTRYA* p, HINSTANCE h);
HRESULT WINAPI AtlModuleRegisterClassObjects(_ATL_MODULEA* pM, DWORD dwClsContext, DWORD dwFlags);
HRESULT WINAPI AtlModuleUnregisterServerEx(_ATL_MODULEA* pM, BOOL bUnRegTypeLib, const CLSID* pCLSID);
HRESULT WINAPI AtlModuleTerm(_ATL_MODULEA* pM);
HRESULT WINAPI AtlInternalQueryInterface(LPVOID pThis,
        const _ATL_INTMAP_ENTRY* pEntries, REFIID iid, LPVOID* ppvObject);
