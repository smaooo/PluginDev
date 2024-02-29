#pragma once

#include "Modules/ModuleManager.h"
#include "Engine.h"
#include "Slate/SGameLayerManager.h"
#include "Slate/SceneViewport.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Engine/GameInstance.h"
#include "ExtraWindowGameManager.h"
#include "EngineModule.h"

/**
 * The public interface to this module
 */
class IExtraWindowPlugin : public IModuleInterface
{

public:

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline IExtraWindowPlugin& Get()
	{
		return FModuleManager::LoadModuleChecked< IExtraWindowPlugin >("ExtraWindowPlugin");
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("ExtraWindowPlugin");
	}
};

