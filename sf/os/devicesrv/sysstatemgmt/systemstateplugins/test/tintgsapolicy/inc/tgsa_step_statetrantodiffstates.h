// Copyright (c) 2008-2010 Nokia Corporation and/or its subsidiary(-ies).
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

/**
 @file
 @test
 @internalComponent - Internal Symbian test code 
*/
 

#ifndef __TGSA_STEP_STATETRANTODIFFSTATES_H__
#define __TGSA_STEP_STATETRANTODIFFSTATES_H__

#include <test/testexecutestepbase.h>
#include <s32file.h>

_LIT(KTGsaStateTranFromNormalStep,"GsaStateTranFromNormalStep");
_LIT(KTGsaStateTranFromStartupStep,"GsaStateTranFromStartupStep");

class CGsaStateTranToDiffStatesTest : public CTestStep
	{
public:
	CGsaStateTranToDiffStatesTest(const TDesC& aProcessName);
	~CGsaStateTranToDiffStatesTest();

	//from CTestStep
	TVerdict doTestStepPreambleL();
	TVerdict doTestStepL();
	TVerdict doTestStepPostambleL();
	
private:
	void DoStateRequestTransitionToDiffStatesL();
	void CurrentSystemStateForStateTranTestL(RFileReadStream& aFileReadStream, TInt aSystemState);

private:
	const TDesC& iProcessName;
	};

#endif	// __TGSA_STEP_STATETRANTODIFFSTATES_H__


