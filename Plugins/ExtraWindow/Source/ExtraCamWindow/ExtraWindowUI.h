#pragma once

#include "Blueprint/UserWidget.h"
#include "Engine/GameEngine.h"
#include "Slate/SGameLayerManager.h"
#include "Slate/SceneViewport.h"
#include "Runtime/Slate/Public/Widgets/Layout/SConstraintCanvas.h"
#include "ExtraWindowGameInstance.h"
#include "ExtraWindowUI.generated.h"

UCLASS()
class UExtraWindowUI : public UUserWidget
{
	GENERATED_BODY()

		UExtraWindowUI(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExtraWindow")
		bool bExtraWindowCreated;

	UFUNCTION(BlueprintCallable, Category = "ExtraWindow")
		bool CreateExtraWindowUI();

	UFUNCTION(BlueprintCallable, Category = "ExtraWindow")
		void UpdateExtraWindowUI(float DeltaSeconds);

	UFUNCTION(BlueprintPure, Category = "ExtraWindow")
		FText GetFloatAsTextWithPrecision(float inFloat);

	UFUNCTION(BlueprintPure, Category = "ExtraWindow")
		static bool GetWINLeftMouseButtonDown();

	UFUNCTION(BlueprintCallable, Category = "Extra Window|UI")
		static void GetResolutionMonitor(bool isSecondMonitor, FVector2D& MonitorPosition, FVector2D& MonitorResolution);

	void CloseExtraWindowUI();

private:

	bool isEditor = false;

	UGameViewportClient* ExtraWindowViewportClient;
	TSharedPtr<FSceneViewport> ExtraWindowSceneViewport;
	FNumberFormattingOptions NumberFormat;
	FVector2D GameWindowLocation;
	FVector2D GameWindowSize;

	void OnExtraWindowWindowClosed(const TSharedRef<SWindow>& WindowBeingClosed);
};
