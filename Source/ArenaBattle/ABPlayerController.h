// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/PlayerController.h"
#include "ABPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public : 
	virtual void PostInitializeComponents() override;
	// 플레이어 컨트롤러가 폰에 빙의되는 시점
	virtual void OnPossess(APawn* aPawn) override;
};
