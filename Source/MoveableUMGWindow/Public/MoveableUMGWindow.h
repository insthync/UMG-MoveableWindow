// Copyright (c) 2017 Bay

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FMoveableUMGWindowModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
