// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABCharacter.h"
#include "ABPlayerController.h"

// ���� ����� ������?
// �ᱹ���� ������ �⺻ ���̳�, ���µ�, �÷��̾� ��Ʈ�ѷ� ����
// ���� ���⼭ ���ش�.
AABGameMode::AABGameMode()
{
	// �⺻ �� ����!
	DefaultPawnClass = AABCharacter::StaticClass();
	// �⺻ �÷��̾� ��Ʈ�ѷ� ����
	PlayerControllerClass = AABPlayerController::StaticClass();
}

void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}
