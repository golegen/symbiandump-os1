// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#include <eikstart.h> 
#include <eikapp.h>
#include "ssmtestapppanic.h"
#include "ssmtestapps.h"

/**
Standard DLL entry point function.
Creates and returns an instance of the CApaApplication-derived class.
@return an instance of the CApaApplication-derived class
*/
TInt E32Main()
	{
	return EikStart::RunApplication( CTestApplication::NewApplication );
	}

CTestApplication::CTestApplication()
	{
	}

CTestApplication::~CTestApplication()
	{
	}
		
/**
@return The application's UID 
*/
TUid CTestApplication::AppDllUid() const
	{
	const TUid dll = {KTestAppPanicUid};
	return dll;
	}

/**
@return CTestApplication or NULL if KErrNoMemory
*/
CApaApplication* CTestApplication::NewApplication()
	{
	// As the framework has at this point not started up enough, and therefore the TRAP-harness and 
	// exception handlers aren�t available yet, this factory function is a non-leaving function and 
	// can't use the new(Eleave) operator.
	return new CTestApplication();
	}
	
/**
Called by the UI framework at application start-up to create an instance of the document class.
@leave	KErrNoMemory
@return A CTestDocument
*/
CApaDocument* CTestApplication::CreateDocumentL()
	{
	return CTestDocument::NewL(*this);
	}

CTestDocument::CTestDocument(CEikApplication& aApp) : CEikDocument(aApp)
	{
	}

CTestDocument::~CTestDocument()
	{
	}

/**
Factory function for this class
@return a new CTestDocument instance.
*/
CTestDocument* CTestDocument::NewL(CEikApplication& aApp)
	{
	return new(ELeave) CTestDocument(aApp);
	}


/**
Called by the UI framework to construct the application UI class. 
Note that the app UI's ConstructL() is called by the UI framework.
*/
CEikAppUi* CTestDocument::CreateAppUiL()
	{
	return new(ELeave) CTestAppUi();
	}



TBool CTestAppUi::FrameworkCallsRendezvous() const
	{
	User::SetJustInTime( EFalse );
	User::Panic( _L("TAppPanic"), KSsTestAppPanicNumber );

	return EFalse;	
	}
	
	
	
CTestAppUi::CTestAppUi()
	{
	}



CTestAppUi::~CTestAppUi()
	{
	}



void CTestAppUi::ConstructL()
	{
	// Complete the UI framework's construction of the App UI.
	BaseConstructL(CEikAppUi::ENoAppResourceFile);
	}
