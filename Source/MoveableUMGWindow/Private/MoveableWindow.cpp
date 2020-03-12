// Copyright by Free2Play-Entertainment (2020)


#include "MoveableWindow.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MoveableWindowManager.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"

void UMoveableWindow::Construct()
{
    UCanvasPanel* Panel = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), "Panel");
    UCanvasPanel* Header = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), "Header");
    WidgetTree->RootWidget = Panel;
    WidgetTree->FindWidget<UCanvasPanel>("Panel")->AddChild(Header);
    DraggingArea = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
    WidgetTree->FindWidget<UCanvasPanel>("Header")->AddChild(DraggingArea);
}

void UMoveableWindow::Tick(float DeltaSeconds)
{
    if(!bIsDragging)
    {
        return;
    }

    APlayerController* Controller = UGameplayStatics::GetPlayerController(this, 0);

    float x;
    float y;
    UWidgetLayoutLibrary::GetMousePositionScaledByDPI(Controller, x, y);
    UWidgetLayoutLibrary::SlotAsCanvasSlot(this)->SetPosition(FVector2D(x,y) - CursorOffset);

    UMoveableWindowManager* Manager = Cast<UMoveableWindowManager>(GetParent());
    if(Manager) { Manager->UpdateOrder(this); }
}

FVector2D UMoveableWindow::GetOffsetToParent(const FVector2D Position)
{
    return Position - UWidgetLayoutLibrary::SlotAsCanvasSlot(this)->GetPosition(); 
}