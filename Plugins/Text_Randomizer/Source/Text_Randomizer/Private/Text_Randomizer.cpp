// Copyright Epic Games, Inc. All Rights Reserved.

#include "Text_Randomizer.h"

#define LOCTEXT_NAMESPACE "FText_RandomizerModule"

void FText_RandomizerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FText_RandomizerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FText_RandomizerModule, Text_Randomizer)