// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"	// for FloatingPawnMovement
#include "ABPawn.generated.h"

// 폰은 액터를 상속받은 클래스이다.
// 폰은 플레이어가 컨트롤러로 조종을 하는 클래스이다.

// 폰의 요소!
UCLASS()
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	// 기본적으로 생성되는 메서드이다.
	// 즉 인풋에 대한 컴포넌트가 이미 설정이 되어있다!
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostInitializeComponents() override;
	// 폰이 플레이어 컨트롤러에 의해 빙의되는 시점
	virtual void PossessedBy(AController* aController) override;

public : 
	// 1. 시각적 요소! -> 애니메이션! (스켈레탈 메시!)
	UPROPERTY(VisibleAnywhere, Category = Visual)
	USkeletalMeshComponent* Mesh;
	// 2. 충돌! (인간형 : 캡슐)
	UPROPERTY(VisibleAnywhere, Category = Collision)
	UCapsuleComponent* Capsule;
	// 3. 움직임 요소
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UFloatingPawnMovement* Movement;
	// 4. 네비게이션(AI 길 찾기, 장판 깔고, 그 위에서 최소 거리를 찾아서 돌아다니는 A* 알고리즘!)
	// 이건 플레이어 용이니까 필요없다
	// 5. 카메라
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

private : 
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
};
