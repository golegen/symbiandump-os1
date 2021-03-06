// Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Example CTestStep derived implementation
// 
//

/**
 @file plugin1Step.cpp
*/
#include "plugin1Step.h"
#include "te_suplprotocolsuitedefs.h"

const TUid KLbsNetworkProtocolInterfaceUid = {0x10281D4A};

/** Destructor
*/
Cplugin1Step::~Cplugin1Step()
	{
	}


/** Constructor
*/
Cplugin1Step::Cplugin1Step()
	{
	SetTestStepName(Kplugin1Step);
	}


/** Perform pre test actions
@return TVerdict test result code
*/
TVerdict Cplugin1Step::doTestStepPreambleL()
	{
	// Call base class method for pre test actions	
	CTe_suplprotocolSuiteStepBase::doTestStepPreambleL();

	return TestStepResult();
	}


/** Perform Cplugin1Step test step.
This test verifies that the Test Protocol Module is shown in the ECOM
list of plug-ins that implement the LBS Network Protocol SPI.

@return TVerdict test result code
*/
TVerdict Cplugin1Step::doTestStepL()
	{
	// List plugin implementations
	RImplInfoPtrArray pluginArray;
	REComSession::ListImplementationsL( KLbsNetworkProtocolInterfaceUid,
										pluginArray );

	// Confirm that at least one plug-in exists
	INFO_PRINTF2(_L("\t Number of plugins listed = %d"), pluginArray.Count());
	if (pluginArray.Count() <= 0)
		{
		SetTestStepResult(EFail);
		}
	else
		{
		// Confirm that one of the plug-ins is the Test Protocol Module
		TInt loop;
		TBool pluginFound(EFalse);
		for (loop = 0; (loop < pluginArray.Count()) && !pluginFound; ++loop)
			{
			CImplementationInformation* pluginImp = pluginArray[loop];
			if (pluginImp->ImplementationUid() == TUid::Uid(KPluginUid))
				{
				pluginFound = ETrue;
				INFO_PRINTF1(_L("\t Test protocol module plug-in UID found"));
				}
			}
		SetTestStepResult(pluginFound ? EPass : EFail);

		// Clear up array
		for (loop = pluginArray.Count(); loop > 0; loop--)
			{
			delete pluginArray[loop - 1];
			}
		}

	// Clear up array
	pluginArray.Close();

	// FinalClose for ECom
	REComSession::FinalClose();
	
	return TestStepResult();
	}



/** Perform post test actions
@return TVerdict test result code
*/
TVerdict Cplugin1Step::doTestStepPostambleL()
	{
	// Call base class method for post test actions	
	CTe_suplprotocolSuiteStepBase::doTestStepPostambleL();
	
	return TestStepResult();
	}
