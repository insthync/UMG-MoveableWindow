// Copyright by Free2Play-Entertainment (2020)


#include "MoveableWindowManager.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanelSlot.h"

void UMoveableWindowManager::UpdateOrder(UWidget* Window)
{
    int32 WindowIndex = Children.Find(Window);
    if(WindowIndex == -1)
    {
        UWidgetLayoutLibrary::SlotAsCanvasSlot(Window)->ZOrder = Children.Add(Window) + 1;
        InvalidateLayoutAndVolatility();
    }

    for(int i = 0; i < Children.Num(); i++)
    {
        if(i != WindowIndex)
        {
            if(UWidgetLayoutLibrary::SlotAsCanvasSlot(Children[i])->ZOrder >= UWidgetLayoutLibrary::SlotAsCanvasSlot(Window)->ZOrder)
            {
                UWidgetLayoutLibrary::SlotAsCanvasSlot(Children[i])->ZOrder -= 1;
            }
        }
    }

    UWidgetLayoutLibrary::SlotAsCanvasSlot(Window)->ZOrder = Children.Num();
    InvalidateLayoutAndVolatility();
}