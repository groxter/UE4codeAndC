#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
class USpringArmComponent;
class UCameraComponent;
class UParticleSystemComponent;
class USkeletalMeshComponent;
#include "SlideSnow__pf2739524524.generated.h"
UCLASS(config=Game, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/migrate/SlideSnow.SlideSnow_C", OverrideNativeName="SlideSnow_C"))
class ASlideSnow_C__pf2739524524 : public ACharacter
{
public:
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="SpringArm"))
	USpringArmComponent* bpv__SpringArm__pf;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="CameraRear"))
	UCameraComponent* bpv__CameraRear__pf;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="snowSlide"))
	UParticleSystemComponent* bpv__snowSlide__pf;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="CameraFront"))
	UCameraComponent* bpv__CameraFront__pf;
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="Snow"))
	USkeletalMeshComponent* bpv__Snow__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Tina Health", Category="Default", OverrideNativeName="TinaHealth"))
	float bpv__TinaHealth__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Ammo", Category="Default", OverrideNativeName="ammo"))
	int32 bpv__ammo__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Total Ammo", Category="Default", OverrideNativeName="totalAmmo"))
	int32 bpv__totalAmmo__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Points", Category="Default", OverrideNativeName="points"))
	int32 bpv__points__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Posesed", Category="Default", OverrideNativeName="posesed"))
	bool bpv__posesed__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Slide Right", Category="Default", OverrideNativeName="slideRight"))
	bool bpv__slideRight__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Slide Left", Category="Default", OverrideNativeName="slideLeft"))
	bool bpv__slideLeft__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Camera Rear Rotation", Category="Default", OverrideNativeName="cameraRearRotation"))
	FRotator bpv__cameraRearRotation__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Camera Front Rotation", Category="Default", OverrideNativeName="cameraFrontRotation"))
	FRotator bpv__cameraFrontRotation__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputAxisEvent_AxisValue"))
	float b0l__K2Node_InputAxisEvent_AxisValue__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key3"))
	FKey b0l__K2Node_InputKeyEvent_Key3__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="Temp_struct_Variable"))
	FKey b0l__Temp_struct_Variable__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key2"))
	FKey b0l__K2Node_InputKeyEvent_Key2__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key1"))
	FKey b0l__K2Node_InputKeyEvent_Key1__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="Temp_struct_Variable1"))
	FKey b0l__Temp_struct_Variable1__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key"))
	FKey b0l__K2Node_InputKeyEvent_Key__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_Event_DeltaSeconds"))
	float b0l__K2Node_Event_DeltaSeconds__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_InputKeyEvent_Key4"))
	FKey b0l__K2Node_InputKeyEvent_Key4__pf;
	ASlideSnow_C__pf2739524524(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	void bpf__ExecuteUbergraph_SlideSnow__pf_0(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_SlideSnow__pf_1(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_SlideSnow__pf_2(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_SlideSnow__pf_3(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_SlideSnow__pf_4(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_SlideSnow__pf_5(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_SlideSnow__pf_6(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_SlideSnow__pf_7(int32 bpp__EntryPoint__pf);
	UFUNCTION(meta=(OverrideNativeName="InpAxisEvt_MoveRight_K2Node_InputAxisEvent_0"))
	virtual void bpf__InpAxisEvt_MoveRight_K2Node_InputAxisEvent_0__pf(float bpp__AxisValue__pf);
	UFUNCTION(meta=(DisplayName="Tick", ToolTip="Event called every frame", CppFromBpEvent, OverrideNativeName="ReceiveTick"))
	virtual void bpf__ReceiveTick__pf(float bpp__DeltaSeconds__pf);
	UFUNCTION(meta=(DisplayName="BeginPlay", ToolTip="Event when play begins for this actor.", CppFromBpEvent, OverrideNativeName="ReceiveBeginPlay"))
	virtual void bpf__ReceiveBeginPlay__pf();
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_SpaceBar_K2Node_InputKeyEvent_0"))
	virtual void bpf__InpActEvt_SpaceBar_K2Node_InputKeyEvent_0__pf(FKey bpp__Key__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_A_K2Node_InputKeyEvent_1"))
	virtual void bpf__InpActEvt_A_K2Node_InputKeyEvent_1__pf(FKey bpp__Key__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_A_K2Node_InputKeyEvent_2"))
	virtual void bpf__InpActEvt_A_K2Node_InputKeyEvent_2__pf(FKey bpp__Key__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_D_K2Node_InputKeyEvent_3"))
	virtual void bpf__InpActEvt_D_K2Node_InputKeyEvent_3__pf(FKey bpp__Key__pf);
	UFUNCTION(meta=(OverrideNativeName="InpActEvt_D_K2Node_InputKeyEvent_4"))
	virtual void bpf__InpActEvt_D_K2Node_InputKeyEvent_4__pf(FKey bpp__Key__pf);
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", DisplayName="Construction Script", ToolTip="Construction script, the place to spawn components and do other setup.@note Name used in CreateBlueprint function@param       Location        The location.@param       Rotation        The rotation.", Category, CppFromBpEvent, OverrideNativeName="UserConstructionScript"))
	virtual void bpf__UserConstructionScript__pf();
public:
};
