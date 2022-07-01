// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS()
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	// �÷��̸� �����ϴµ���, � ������ ���� �ʿ����.
	// �� �÷��� ��ư ������ ��(��Ȯ�ϴ�.)
	virtual void BeginPlay() override;
	// �÷��̸� ������ ������ �پ��ϴ�.
	// ������ ���ؿ��� ���� ����
	// ������ ���ų�, �÷��̾ �����߰ų� ���
	virtual void EndPlay(const EEndPlayReason::Type EndPlayerReason) override;
	// ���Ϳ� ���� ��� ������Ʈ�� ������ �Ϸ�� ��� ȣ���ϴ� �Լ�
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	// virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Water;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent* Light;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* Splash;

	// �߷��� ������ ���� �ʴ� Ÿ��
	// FloatingPawnMovement
	// ������ �ӵ���� ȸ���ϴ� Ÿ��
	// RotatingMovement
	// ������ ��ġ�� ���͸� �̵���Ű�� Ÿ��
	// InterpMovement
	// ������ �߷��� ������ �޾Ƽ� �������� �׸��� ����ü�� �������� �����ϴ� Ÿ��
	// ProjectileMovement
	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent* Movement;

	UPROPERTY(EditAnywhere, Category=ID)
	int32 ID;

private :
	// AllowPrivateAccess
	// ��� �ڵ� �󿡼��� private 
	// �� �ڵ忡�� �������� ������ �Ұ����ϴ�.
	// �ٵ� �����Ϳ����� ������ �� �ְ� ����� �ʹ�.
	// �׷� �� ��Ÿ �����͸� true�� �ָ� �ȴ�.
	UPROPERTY(EditAnywhere, Category=Stat, Meta=(AllowPrivateAccess=true))
	float RotateSpeed;
};
