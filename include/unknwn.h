/*** Autogenerated by WIDL 0.1 from unknwn.idl - Do not edit ***/
#include "rpc.h"
#include "rpcndr.h"

#ifndef __WIDL_UNKNWN_H
#define __WIDL_UNKNWN_H
#ifdef __cplusplus
extern "C" {
#endif
#include "wtypes.h"
#if defined(ICOM_MSVTABLE_COMPAT) && (!defined(__cplusplus) || defined(CINTERFACE))
# define ICOM_MSVTABLE_COMPAT_FIELDS long dummyRTTI1,dummyRTTI2;
# define ICOM_MSVTABLE_COMPAT_DummyRTTIVALUE 0,0,
#else
# define ICOM_MSVTABLE_COMPAT_FIELDS
# define ICOM_MSVTABLE_COMPAT_DummyRTTIVALUE
#endif
typedef struct IUnknown IUnknown;
typedef IUnknown *LPUNKNOWN;

/*****************************************************************************
 * IUnknown interface
 */
DEFINE_GUID(IID_IUnknown, 0x00000000, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)
#ifdef ICOM_USE_COM_INTERFACE_ATTRIBUTE
struct __attribute__((com_interface)) IUnknown
#else
struct IUnknown
#endif
{
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        REFIID riid,
        void** ppvObject) = 0;

    virtual ULONG STDMETHODCALLTYPE AddRef(
        ) = 0;

    virtual ULONG STDMETHODCALLTYPE Release(
        ) = 0;

};
#else
typedef struct IUnknownVtbl IUnknownVtbl;
struct IUnknown {
    const IUnknownVtbl* lpVtbl;
};
struct IUnknownVtbl {
    ICOM_MSVTABLE_COMPAT_FIELDS

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IUnknown* This,
        REFIID riid,
        void** ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IUnknown* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IUnknown* This);

};

/*** IUnknown methods ***/
#define IUnknown_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
#define IUnknown_AddRef(p) (p)->lpVtbl->AddRef(p)
#define IUnknown_Release(p) (p)->lpVtbl->Release(p)

#endif

#define IUnknown_METHODS \
    ICOM_MSVTABLE_COMPAT_FIELDS \
    /*** IUnknown methods ***/ \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(ULONG,AddRef)(THIS) PURE; \
    STDMETHOD_(ULONG,Release)(THIS) PURE;

HRESULT CALLBACK IUnknown_QueryInterface_Proxy(
    IUnknown* This,
    REFIID riid,
    void** ppvObject);
void __RPC_STUB IUnknown_QueryInterface_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
ULONG CALLBACK IUnknown_AddRef_Proxy(
    IUnknown* This);
void __RPC_STUB IUnknown_AddRef_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
ULONG CALLBACK IUnknown_Release_Proxy(
    IUnknown* This);
void __RPC_STUB IUnknown_Release_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

typedef struct IClassFactory IClassFactory;
typedef IClassFactory *LPCLASSFACTORY;

/*****************************************************************************
 * IClassFactory interface
 */
DEFINE_GUID(IID_IClassFactory, 0x00000001, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)
struct IClassFactory : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE CreateInstance(
        IUnknown* pUnkOuter,
        REFIID riid,
        void** ppvObject) = 0;

    virtual HRESULT STDMETHODCALLTYPE LockServer(
        BOOL fLock) = 0;

};
#else
typedef struct IClassFactoryVtbl IClassFactoryVtbl;
struct IClassFactory {
    const IClassFactoryVtbl* lpVtbl;
};
struct IClassFactoryVtbl {
    ICOM_MSVTABLE_COMPAT_FIELDS

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IClassFactory* This,
        REFIID riid,
        void** ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IClassFactory* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IClassFactory* This);

    /*** IClassFactory methods ***/
    HRESULT (STDMETHODCALLTYPE *CreateInstance)(
        IClassFactory* This,
        IUnknown* pUnkOuter,
        REFIID riid,
        void** ppvObject);

    HRESULT (STDMETHODCALLTYPE *LockServer)(
        IClassFactory* This,
        BOOL fLock);

};

/*** IUnknown methods ***/
#define IClassFactory_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
#define IClassFactory_AddRef(p) (p)->lpVtbl->AddRef(p)
#define IClassFactory_Release(p) (p)->lpVtbl->Release(p)
/*** IClassFactory methods ***/
#define IClassFactory_CreateInstance(p,a,b,c) (p)->lpVtbl->CreateInstance(p,a,b,c)
#define IClassFactory_LockServer(p,a) (p)->lpVtbl->LockServer(p,a)

#endif

#define IClassFactory_METHODS \
    ICOM_MSVTABLE_COMPAT_FIELDS \
    /*** IUnknown methods ***/ \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(ULONG,AddRef)(THIS) PURE; \
    STDMETHOD_(ULONG,Release)(THIS) PURE; \
    /*** IClassFactory methods ***/ \
    STDMETHOD_(HRESULT,CreateInstance)(THIS_ IUnknown* pUnkOuter, REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(HRESULT,LockServer)(THIS_ BOOL fLock) PURE;

HRESULT CALLBACK IClassFactory_RemoteCreateInstance_Proxy(
    IClassFactory* This,
    REFIID riid,
    IUnknown** ppvObject);
void __RPC_STUB IClassFactory_RemoteCreateInstance_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IClassFactory_CreateInstance_Proxy(
    IClassFactory* This,
    IUnknown* pUnkOuter,
    REFIID riid,
    void** ppvObject);
HRESULT __RPC_STUB IClassFactory_CreateInstance_Stub(
    IClassFactory* This,
    REFIID riid,
    IUnknown** ppvObject);
HRESULT CALLBACK IClassFactory_RemoteLockServer_Proxy(
    IClassFactory* This,
    BOOL fLock);
void __RPC_STUB IClassFactory_RemoteLockServer_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IClassFactory_LockServer_Proxy(
    IClassFactory* This,
    BOOL fLock);
HRESULT __RPC_STUB IClassFactory_LockServer_Stub(
    IClassFactory* This,
    BOOL fLock);

#ifdef __cplusplus
}
#endif
#endif /* __WIDL_UNKNWN_H */
