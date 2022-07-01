// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"	// EngineMinimal.h / 각종 매크로
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"

/**
 * 게임 플레이 버튼이 눌리면
 * 게임 모드의 의해서 다음과 같은 일들이 진행된다.
 * 1. 플레이어 컨트롤러 생성
 * 2. 플레이어 폰 생성
 * 3. 플레이어 컨트롤러가 플레이어 폰에 빙의
 * 4. 게임이 시작된다!
 */
UCLASS()
class ARENABATTLE_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public : 
	AABGameMode();

	// 플레이어가 게임에 입장하는 것을 언리얼은 로그인(Login)이라 한다.
	// 로그인 과정에서 플레이어에게 할당할 플레이어 컨트롤러가 생성된다.

	// 로그인을 완료하면 PostLogin이라는 함수를 실행을 하게 된다.
	// 이 함수 내부에서 플레이어가 조종할 폰을 생성하고, 플레이어 컨트롤러가
	// 그 폰에 빙의하는 작업이 거쳐진다.
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
