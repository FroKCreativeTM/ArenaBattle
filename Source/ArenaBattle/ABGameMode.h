// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"	// EngineMinimal.h / ���� ��ũ��
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"

/**
 * ���� �÷��� ��ư�� ������
 * ���� ����� ���ؼ� ������ ���� �ϵ��� ����ȴ�.
 * 1. �÷��̾� ��Ʈ�ѷ� ����
 * 2. �÷��̾� �� ����
 * 3. �÷��̾� ��Ʈ�ѷ��� �÷��̾� ���� ����
 * 4. ������ ���۵ȴ�!
 */
UCLASS()
class ARENABATTLE_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public : 
	AABGameMode();

	// �÷��̾ ���ӿ� �����ϴ� ���� �𸮾��� �α���(Login)�̶� �Ѵ�.
	// �α��� �������� �÷��̾�� �Ҵ��� �÷��̾� ��Ʈ�ѷ��� �����ȴ�.

	// �α����� �Ϸ��ϸ� PostLogin�̶�� �Լ��� ������ �ϰ� �ȴ�.
	// �� �Լ� ���ο��� �÷��̾ ������ ���� �����ϰ�, �÷��̾� ��Ʈ�ѷ���
	// �� ���� �����ϴ� �۾��� ��������.
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
