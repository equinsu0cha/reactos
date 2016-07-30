#pragma once

/* GDI logical font object */
typedef struct _LFONT TEXTOBJ, *PTEXTOBJ;

typedef struct _LFONT LFONT, *PLFONT;

/*  Internal interface  */

#define  TEXTOBJ_UnlockText(pBMObj) GDIOBJ_vUnlockObject ((POBJ)pBMObj)
NTSTATUS FASTCALL TextIntCreateFontIndirect(CONST LPLOGFONTW lf, HFONT *NewFont);
BOOL FASTCALL InitFontSupport(VOID);
ULONG FASTCALL FontGetObject(PTEXTOBJ TextObj, ULONG Count, PVOID Buffer);

HFONT
NTAPI
GreCreateFontIndirectW(
    _In_ const LOGFONTW *plfw);

BOOL
NTAPI
GreTextOutW(
    _In_ HDC hdc,
    _In_ int xStart,
    _In_ int yStart,
    _In_ LPCWSTR pwcString,
    _In_ int cwc);

BOOL
NTAPI
GreExtTextOutW(
    IN HDC,
    IN INT,
    IN INT,
    IN UINT,
    IN OPTIONAL RECTL*,
    IN LPWSTR,
    IN INT,
    IN OPTIONAL LPINT,
    IN DWORD);

BOOL
WINAPI
GreGetTextMetricsW(
    _In_ HDC hdc,
    _Out_ LPTEXTMETRICW lptm);

BOOL
NTAPI
GreGetTextExtentW(
    HDC hdc,
    LPWSTR lpwsz,
    INT cwc,
    LPSIZE psize,
    UINT flOpts);

BOOL
NTAPI
GreGetTextExtentExW(
    IN HDC hdc,
    IN OPTIONAL LPWSTR lpwsz,
    IN ULONG cwc,
    IN ULONG dxMax,
    OUT OPTIONAL ULONG *pcch,
    OUT OPTIONAL PULONG pdxOut,
    OUT LPSIZE psize,
    IN FLONG fl);
