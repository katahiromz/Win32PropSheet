#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <assert.h>
#include "resource.h"

#define USEHICON
#define MODELESS
#define PROPTITLE
//#define WIZARD
//#define NOAPPLYNOW
//#define PARENT

#ifdef PARENT
    #undef MODELESS
#endif

HPROPSHEETPAGE g_hpsp[3];

BOOL Page0_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

void Page0_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
    case edt1:
        if (codeNotify == EN_CHANGE)
        {
            PropSheet_Changed(::GetParent(hwnd), hwnd);
            break;
        }
        break;
    case psh1:
        PropSheet_PressButton(::GetParent(hwnd), PSBTN_APPLYNOW);
        break;
    case psh2:
        PropSheet_UnChanged(::GetParent(hwnd), hwnd);
        break;
    }
}

LRESULT Page0_OnNotify(HWND hwnd, int idFrom, LPNMHDR pnmhdr)
{
    PSHNOTIFY *pNotify = (PSHNOTIFY *)pnmhdr;
    switch (pnmhdr->code)
    {
    case PSN_KILLACTIVE:
        SetWindowLongPtr(hwnd, DWLP_MSGRESULT, FALSE);
        return TRUE;
    case PSN_APPLY:
        MessageBox(hwnd, TEXT("Page0 applied!"), TEXT("Info"), MB_ICONINFORMATION);
        //SetWindowLongPtr(hwnd, DWLP_MSGRESULT, PSNRET_INVALID_NOCHANGEPAGE); // Prevent
        SetWindowLongPtr(hwnd, DWLP_MSGRESULT, PSNRET_NOERROR); // Continue
        return TRUE;
    case PSN_WIZBACK:
        PropSheet_SetCurSel(::GetParent(hwnd), NULL, 0);
        break;
    case PSN_QUERYCANCEL:
    case PSN_WIZFINISH:
        ::DestroyWindow(::GetParent(hwnd));
        break;
    case PSN_WIZNEXT:
        PropSheet_SetCurSel(::GetParent(hwnd), NULL, 1);
        break;
    }
    return 0;
}

INT_PTR CALLBACK
Page0DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_INITDIALOG, Page0_OnInitDialog);
        HANDLE_MSG(hwnd, WM_COMMAND, Page0_OnCommand);
        HANDLE_MSG(hwnd, WM_NOTIFY, Page0_OnNotify);
    }
    return 0;
}

BOOL Page1_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

void Page1_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
    case edt1:
        if (codeNotify == EN_CHANGE)
        {
            PropSheet_Changed(::GetParent(hwnd), hwnd);
            break;
        }
        break;
    case psh1:
        PropSheet_PressButton(::GetParent(hwnd), PSBTN_APPLYNOW);
        break;
    case psh2:
        PropSheet_UnChanged(::GetParent(hwnd), hwnd);
        break;
    }
}

LRESULT Page1_OnNotify(HWND hwnd, int idFrom, LPNMHDR pnmhdr)
{
    PSHNOTIFY *pNotify = (PSHNOTIFY *)pnmhdr;
    switch (pnmhdr->code)
    {
    case PSN_KILLACTIVE:
        SetWindowLongPtr(hwnd, DWLP_MSGRESULT, FALSE);
        return TRUE;
    case PSN_APPLY:
        MessageBox(hwnd, TEXT("Page1 applied!"), TEXT("Info"), MB_ICONINFORMATION);
        //SetWindowLongPtr(hwnd, DWLP_MSGRESULT, PSNRET_INVALID_NOCHANGEPAGE); // Prevent
        SetWindowLongPtr(hwnd, DWLP_MSGRESULT, PSNRET_NOERROR); // Continue
        return TRUE;
    case PSN_WIZBACK:
        PropSheet_SetCurSel(::GetParent(hwnd), NULL, 0);
        break;
    case PSN_QUERYCANCEL:
    case PSN_WIZFINISH:
        ::DestroyWindow(::GetParent(hwnd));
        break;
    case PSN_WIZNEXT:
        PropSheet_SetCurSel(::GetParent(hwnd), NULL, 2);
        break;
    }
    return 0;
}

INT_PTR CALLBACK
Page1DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_INITDIALOG, Page1_OnInitDialog);
        HANDLE_MSG(hwnd, WM_COMMAND, Page1_OnCommand);
        HANDLE_MSG(hwnd, WM_NOTIFY, Page1_OnNotify);
    }
    return 0;
}

BOOL Page2_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

void Page2_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
    case edt1:
        if (codeNotify == EN_CHANGE)
        {
            PropSheet_Changed(::GetParent(hwnd), hwnd);
            break;
        }
        break;
    case psh1:
        PropSheet_PressButton(::GetParent(hwnd), PSBTN_APPLYNOW);
        break;
    case psh2:
        PropSheet_UnChanged(::GetParent(hwnd), hwnd);
        break;
    }
}

LRESULT Page2_OnNotify(HWND hwnd, int idFrom, LPNMHDR pnmhdr)
{
    PSHNOTIFY *pNotify = (PSHNOTIFY *)pnmhdr;
    switch (pnmhdr->code)
    {
    case PSN_KILLACTIVE:
        SetWindowLongPtr(hwnd, DWLP_MSGRESULT, FALSE);
        return TRUE;
    case PSN_APPLY:
        MessageBox(hwnd, TEXT("Page2 applied!"), TEXT("Info"), MB_ICONINFORMATION);
        //SetWindowLongPtr(hwnd, DWLP_MSGRESULT, PSNRET_INVALID_NOCHANGEPAGE); // Prevent
        SetWindowLongPtr(hwnd, DWLP_MSGRESULT, PSNRET_NOERROR); // Continue
        return TRUE;
    case PSN_WIZBACK:
        PropSheet_SetCurSel(::GetParent(hwnd), NULL, 1);
        break;
    case PSN_QUERYCANCEL:
    case PSN_WIZFINISH:
        ::DestroyWindow(::GetParent(hwnd));
        break;
    case PSN_WIZNEXT:
        PropSheet_SetCurSel(::GetParent(hwnd), NULL, 0);
        break;
    }
    return 0;
}

INT_PTR CALLBACK
Page2DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_INITDIALOG, Page2_OnInitDialog);
        HANDLE_MSG(hwnd, WM_COMMAND, Page2_OnCommand);
        HANDLE_MSG(hwnd, WM_NOTIFY, Page2_OnNotify);
    }
    return 0;
}

INT DoIt(HINSTANCE hInstance, HWND hwndParent)
{
    PROPSHEETPAGE psp = { sizeof(psp) };
    psp.dwFlags = PSP_DEFAULT;
    psp.hInstance = hInstance;

    INT iPage = 0;

    psp.pszTemplate = MAKEINTRESOURCE(IDD_PAGE0);
    psp.pfnDlgProc = Page0DlgProc;
    g_hpsp[iPage++] = ::CreatePropertySheetPage(&psp);

    psp.pszTemplate = MAKEINTRESOURCE(IDD_PAGE1);
    psp.pfnDlgProc = Page1DlgProc;
    g_hpsp[iPage++] = ::CreatePropertySheetPage(&psp);

    psp.pszTemplate = MAKEINTRESOURCE(IDD_PAGE2);
    psp.pfnDlgProc = Page2DlgProc;
    g_hpsp[iPage++] = ::CreatePropertySheetPage(&psp);

    assert(iPage <= _countof(g_hpsp));

    PROPSHEETHEADER psh = { sizeof(psh) };
    psh.dwFlags = PSH_DEFAULT;
#ifdef NOAPPLYNOW
    psh.dwFlags |= PSH_NOAPPLYNOW;
#endif
#ifdef PROPTITLE
    psh.dwFlags |= PSH_PROPTITLE;
#endif
    psh.hInstance = hInstance;
    psh.hwndParent = hwndParent;
    psh.nPages = iPage;
    psh.phpage = g_hpsp;
    psh.pszCaption = TEXT("Win32PropSheet");

#ifdef USEHICON
    psh.dwFlags |= PSH_USEHICON;
    psh.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
#endif

#ifdef WIZARD
    psh.dwFlags |= PSH_WIZARD;
#endif
    
#ifdef MODELESS
    psh.dwFlags |= PSH_MODELESS;
    HWND hwndPropSheetModeless = (HWND)::PropertySheet(&psh);
    assert(hwndPropSheetModeless);

    MSG msg;
    while (::GetMessage(&msg, NULL, 0, 0))
    {
        if (!PropSheet_GetCurrentPageHwnd(hwndPropSheetModeless))
        {
            ::DestroyWindow(hwndPropSheetModeless);
            break;
        }

        if (PropSheet_IsDialogMessage(hwndPropSheetModeless, &msg))
            continue;

        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }
#else
    ::PropertySheet(&psh);
#endif

    return 0;
}

void Parent_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
    case IDOK:
        DoIt(GetModuleHandle(NULL), hwnd);
        break;
    case IDCANCEL:
        EndDialog(hwnd, id);
        break;
    }
}

INT_PTR CALLBACK
ParentDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_COMMAND, Parent_OnCommand);
    }
    return 0;
}

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    ::InitCommonControls();

#ifdef PARENT
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_PARENT), NULL, ParentDialogProc);
    return 0;
#else
    return DoIt(hInstance, NULL);
#endif
}
