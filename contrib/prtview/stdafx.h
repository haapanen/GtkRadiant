/*
PrtView plugin for GtkRadiant
Copyright (C) 2001 Geoffrey Dewan, Loki software and qeradiant.com

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __PRTVIEW_AFX_H__
#define __PRTVIEW_AFX_H__

#include <gtk/gtk.h>

#if defined(__linux__) || defined(__APPLE__)
#include <GL/glx.h>

// Necessary for proper boolean type declaration
#include "qertypes.h"

typedef guint32 COLORREF;
typedef void* LPVOID;
typedef char* LPCSTR;
typedef void* HMODULE;
typedef int 	BOOL;

#define RGB(r, g, b) ((guint32)(((guint8) (r) | ((guint16) (g) << 8))|(((guint32) (guint8) (b)) << 16)))
#define GetRValue(rgb)      ((guint8)(rgb))
#define GetGValue(rgb)      ((guint8)(((guint16)(rgb)) >> 8))
#define GetBValue(rgb)      ((guint8)((rgb)>>16))

#define _MAX_PATH PATH_MAX

#define IDOK                1
#define IDCANCEL            2

#endif // __linux__

#include "synapse.h"

// plugin
#include "iplugin.h"
#define USE_QERTABLE_DEFINE
#include "qerplugin.h"
#include "ibspfrontend.h"
#include "igl.h"
#include "version.h"

// PrtView
#include "gtkdlgs.h"
#include "prtview.h"
#include "portals.h"

#define MSG_PREFIX "Portal Viewer plugin: "
#define PRTVIEW_MINOR "prtview"

#define UPDATE_2D (W_XY | W_XZ | W_YZ)
#define UPDATE_3D (W_CAMERA)
#define UPDATE_ALL (UPDATE_2D | UPDATE_3D)

int INIGetInt(char *key, int def);
void INISetInt(char *key, int val, char *comment = NULL);

extern bool interfaces_started;

extern _QERFuncTable_1 g_FuncTable;
extern _QERQglTable g_QglTable;

#endif