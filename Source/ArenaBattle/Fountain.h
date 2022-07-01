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
	// 플레이를 시작하는데는, 어떤 사유가 굳이 필요없다.
	// 즉 플레이 버튼 누르면 끝(명확하다.)
	virtual void BeginPlay() override;
	// 플레이를 끝내는 이유는 다양하다.
	// 엔진의 기준에서 봤을 때는
	// 오류가 났거나, 플레이어가 종료했거나 등등
	virtual void EndPlay(const EEndPlayReason::Type EndPlayerReason) override;
	// 액터에 속한 모든 컴포넌트의 세팅이 완료된 경우 호출하는 함수
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

	// 중력의 영향을 받지 않는 타입
	// FloatingPawnMovement
	// 지정한 속도대로 회전하는 타입
	// RotatingMovement
	// 지정한 위치로 액터를 이동시키는 타입
	// InterpMovement
	// 액터의 중력의 영향을 받아서 포물선을 그리는 투사체의 움직임을 제공하는 타입
	// ProjectileMovement
	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent* Movement;

	UPROPERTY(EditAnywhere, Category=ID)
	int32 ID;

private :
	// AllowPrivateAccess
	// 얘는 코드 상에서는 private 
	// 즉 코드에서 직접적인 접근이 불가능하다.
	// 근데 에디터에서는 수정할 수 있게 만들고 싶다.
	// 그럼 이 메타 데이터를 true로 주면 된다.
	UPROPERTY(EditAnywhere, Category=Stat, Meta=(AllowPrivateAccess=true))
	float RotateSpeed;
};
