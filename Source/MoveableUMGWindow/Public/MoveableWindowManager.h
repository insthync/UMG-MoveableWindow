// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "MoveableWindowManager.generated.h"

/**
 * 
 */
UCLASS()
class MOVEABLEUMGWINDOW_API UMoveableWindowManager : public UCanvasPanel
{
	GENERATED_BODY()
	
	TArray<UWidget*> Children;

public:

	UFUNCTION(BlueprintCallable)
	void UpdateOrder(UWidget* Window);
};
