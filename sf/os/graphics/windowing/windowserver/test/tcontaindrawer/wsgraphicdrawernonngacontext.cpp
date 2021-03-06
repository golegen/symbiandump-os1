// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#undef SYMBIAN_GRAPHICS_GCE

#include "wsgraphicdrawercontext.h"
#include <graphics/wsgraphicdrawerinterface.h>
#include <bitstd.h>

MWsGraphicDrawerContext* CWsGraphicDrawerNonNgaContext::NewL()
	{
	return new(ELeave) CWsGraphicDrawerNonNgaContext();
	}

void CWsGraphicDrawerNonNgaContext::Destroy()
	{
	delete this;
	}

void CWsGraphicDrawerNonNgaContext::DrawEllipse(MWsGc& aGc, const TRect& aRect, const TRgb& aColor) const
	{
	aGc.PushBitGcSettings();
	CFbsBitGc& bitGc = aGc.BitGc();
	bitGc.SetBrushStyle(CGraphicsContext::ESolidBrush);
	bitGc.SetBrushColor(aColor);
	bitGc.DrawEllipse(aRect);
	aGc.PopBitGcSettings();
	}
