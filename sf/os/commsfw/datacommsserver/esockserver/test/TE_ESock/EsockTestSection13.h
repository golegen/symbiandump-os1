// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// This is the header file for ESOCK test section 13
// 
//


#if (!defined __ESOCKTEST_13_H__)
#define __ESOCKTEST_13_H__

#include "TestStepEsock.h"

class CEsockTest13_1 : public CESockTestStep_OOMCapable
	{
	public:
		static const TDesC& GetTestName();
		~CEsockTest13_1();
		
		virtual enum TVerdict easyTestStepL();
		
	};

class CEsockTest13_2 : public CESockTestStep_OOMCapable
	{
	public:
		static const TDesC& GetTestName();
		~CEsockTest13_2();
		
		virtual enum TVerdict easyTestStepL();
		
	};

#endif //(__ESOCKTEST_13_H__)

