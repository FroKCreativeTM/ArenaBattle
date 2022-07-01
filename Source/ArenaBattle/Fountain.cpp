// Fill out your copyright notice in the Description page of Project Settings.

#include "Fountain.h"
#include "ArenaBattle.h"

// Sets default values
AFountain::AFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("LIGHT"));
	Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SPLASH"));
	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MOVEMENT"));

	RootComponent = Body;
	Water->SetupAttachment(Body);
	Light->SetupAttachment(Body);
	Splash->SetupAttachment(Body);

	Water->SetRelativeLocation(FVector(0.f, 0.f, 135.f));
	Light->SetRelativeLocation(FVector(0.f, 0.f, 195.f));
	Splash->SetRelativeLocation(FVector(0.f, 0.f, 195.f));

	// 일단 리소스를 불러온다.
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_BODY(TEXT("/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01"));

	// 에셋을 불러오는데 성공했다면
	if (SM_BODY.Succeeded())
	{
		// 실존하는 오브젝트를 Body(StaticMeshComponent)에 붙여준다.
		Body->SetStaticMesh(SM_BODY.Object);
	}

	// 일단 리소스를 불러온다.
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_WATER(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Meshes/Env/SM_Plains_Fountain_02.SM_Plains_Fountain_02"));

	// 에셋을 불러오는데 성공했다면
	if (SM_WATER.Succeeded())
	{
		// 실존하는 오브젝트를 Body(StaticMeshComponent)에 붙여준다.
		Water->SetStaticMesh(SM_WATER.Object);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem>
		SM_SPLASH(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_Base_01.P_Water_Fountain_Splash_Base_01"));

	// 에셋을 불러오는데 성공했다면
	if (SM_SPLASH.Succeeded())
	{
		// 실존하는 오브젝트를 Body(StaticMeshComponent)에 붙여준다.
		Splash->SetTemplate(SM_SPLASH.Object);
	}

	RotateSpeed = 30.f;
	// 이 경우는 DeltaTime을 알아서 계산을 해준다.
	Movement->RotationRate = FRotator(0.f, RotateSpeed, 0.f);
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	// C++보단 Java같은 언어에서 자주 사용하는 방식
	// 부모 클래스의 행동부터 진행한 다음에 
	// 내 클래스의 고유한 행동을 하는 방식
	Super::BeginPlay();
	
	// 로그를 남기는 방법은 다음과 같다.
	ABLOG_S(Warning);
	ABLOG(Warning, TEXT("Actor Name : %s, ID : %d, Location X : %.3f"), *GetName(), ID, GetActorLocation().X);
}

void AFountain::EndPlay(const EEndPlayReason::Type EndPlayerReason)
{
	// 부모가 할 일 먼저!
	Super::EndPlay(EndPlayerReason);
	ABLOG_S(Warning);
}

void AFountain::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

// Called every frame
// 1 frame <----------------> 2 frame <----------------> 3 frame
//             DeltaTime                   DeltaTime
// DeltaTime : 엔진이 프레임과 프레임간 시간을 측정해서 이를 Tick 함수에 전달을 한다.
// 예로 들어서 정말 이상적인 60fps(frame per second)이라고 가정하자.
// 1000ms(1s) / 60(frame) = 16.66666666666667ms
// 60프레임 상 deltatime -> 16.66666666666667ms
// 유니티에서는 Update();
//void AFountain::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	// 시간이 흐르면서!
//	// 회전 시킨다.
//	// 각 프레임 시간마다 스피드만큼 돈 결과물을 반환
//	// 즉 스피드만큼 yaw회전(z축 기준 회전)을 진행한다.
//	// AddActorLocalRotation(FRotator(0.f, RotateSpeed * DeltaTime, 0.f));
//	// 단 움직임이란 요소는 여기다가 구현해도 무방한데
//	// 좀 더 정교하고 일반적인 움직임들은 구현을 우리가 일일히 할 필요가 있을까?
//	// 제공을 한다.
//}

