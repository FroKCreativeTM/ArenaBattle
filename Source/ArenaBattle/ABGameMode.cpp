// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"

// 게임 모드의 생성자?
// 결국에는 게임의 기본 폰이나, 상태도, 플레이어 컨트롤러 설정
// 등을 여기서 해준다.
AABGameMode::AABGameMode()
{
	// 기본 폰 정의!
	DefaultPawnClass = AABCharacter::StaticClass();
	// 기본 플레이어 컨트롤러 정의
	PlayerControllerClass = AABPlayerController::StaticClass();
}

void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}
