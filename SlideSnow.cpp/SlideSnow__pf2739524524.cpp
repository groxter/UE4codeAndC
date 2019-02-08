#include "tutorial.h"
#include "SlideSnow__pf2739524524.h"
#include "GeneratedCodeHelpers.h"
#include "Runtime/Engine/Classes/Engine/InputAxisDelegateBinding.h"
#include "Runtime/Engine/Classes/Engine/InputKeyDelegateBinding.h"
#include "Runtime/Engine/Classes/Engine/SimpleConstructionScript.h"
#include "Runtime/Engine/Classes/Engine/SCS_Node.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SkinnedMeshComponent.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineBaseTypes.h"
#include "Runtime/Engine/Classes/Engine/AssetUserData.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphPin.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Engine/NetSerialization.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/Info.h"
#include "Runtime/Engine/Classes/Components/BillboardComponent.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "Runtime/Engine/Classes/Engine/TextureDefines.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_AssetUserData.h"
#include "Runtime/Engine/Classes/GameFramework/LocalMessage.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineReplStructs.h"
#include "Runtime/CoreUObject/Public/UObject/CoreOnline.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/NavMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/MovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PhysicsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/Volume.h"
#include "Runtime/Engine/Classes/Engine/Brush.h"
#include "Runtime/Engine/Classes/Components/BrushComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetup.h"
#include "Runtime/Engine/Classes/PhysicsEngine/AggregateGeom.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphereElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ShapeElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BoxElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphylElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConvexElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/TaperedCapsuleElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetupEnums.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterial.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsSettingsEnums.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterialPropertyBase.h"
#include "Runtime/Engine/Classes/Vehicles/TireType.h"
#include "Runtime/Engine/Classes/Engine/DataAsset.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodyInstance.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationTypes.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAgentInterface.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationData.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationDataInterface.h"
#include "Runtime/AIModule/Classes/AIResourceInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/PathFollowingAgentInterface.h"
#include "Runtime/AIModule/Classes/BrainComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardData.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig.h"
#include "Runtime/AIModule/Classes/Perception/AISense.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionSystem.h"
#include "Runtime/AIModule/Classes/Perception/AISenseEvent.h"
#include "Runtime/AIModule/Classes/Actions/PawnActionsComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnAction.h"
#include "Runtime/AIModule/Classes/AITypes.h"
#include "Runtime/GameplayTasks/Classes/GameplayTasksComponent.h"
#include "Runtime/GameplayTasks/Classes/GameplayTask.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskOwnerInterface.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskResource.h"
#include "Runtime/NavigationSystem/Public/NavFilters/NavigationQueryFilter.h"
#include "Runtime/NavigationSystem/Public/NavAreas/NavArea.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreaBase.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTCompositeNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTTaskNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTService.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTAuxiliaryNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTDecorator.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionListenerInterface.h"
#include "Runtime/AIModule/Classes/GenericTeamAgentInterface.h"
#include "Runtime/Engine/Public/VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "Runtime/Engine/Classes/GameFramework/EngineMessage.h"
#include "Runtime/Engine/Classes/GameFramework/DamageType.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationAvoidanceTypes.h"
#include "Runtime/Engine/Classes/GameFramework/RootMotionSource.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Runtime/Engine/Public/AI/RVOAvoidanceInterface.h"
#include "Runtime/Engine/Classes/Interfaces/NetworkPredictionInterface.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Animation/AnimCompositeBase.h"
#include "Runtime/Engine/Classes/Animation/AnimSequenceBase.h"
#include "Runtime/Engine/Classes/Animation/Skeleton.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSocket.h"
#include "Runtime/Engine/Classes/Animation/SmartName.h"
#include "Runtime/Engine/Classes/Animation/BlendProfile.h"
#include "Runtime/Engine/Public/BoneContainer.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_PreviewMeshProvider.h"
#include "Runtime/Engine/Classes/Animation/AnimMetaData.h"
#include "Runtime/Engine/Public/Animation/AnimTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimLinkableElement.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "Runtime/Engine/Public/Animation/AnimCurveTypes.h"
#include "Runtime/Engine/Classes/Curves/RichCurve.h"
#include "Runtime/Engine/Classes/Curves/IndexedCurve.h"
#include "Runtime/Engine/Classes/Curves/KeyHandle.h"
#include "Runtime/Engine/Public/AlphaBlend.h"
#include "Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "Runtime/Engine/Classes/Curves/CurveBase.h"
#include "Runtime/Engine/Classes/Animation/AnimEnums.h"
#include "Runtime/Engine/Classes/Animation/TimeStretchCurve.h"
#include "Runtime/Engine/Classes/Engine/Player.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstDirector.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInst.h"
#include "Runtime/Engine/Classes/GameFramework/HUD.h"
#include "Runtime/Engine/Classes/Engine/Canvas.h"
#include "Runtime/Engine/Classes/Debug/ReporterGraph.h"
#include "Runtime/Engine/Classes/Debug/ReporterBase.h"
#include "Runtime/Engine/Classes/Engine/Font.h"
#include "Runtime/Engine/Classes/Engine/FontImportOptions.h"
#include "Runtime/SlateCore/Public/Fonts/CompositeFont.h"
#include "Runtime/SlateCore/Public/Fonts/FontProviderInterface.h"
#include "Runtime/Engine/Classes/Materials/MaterialInterface.h"
#include "Runtime/Engine/Classes/Engine/SubsurfaceProfile.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Public/MaterialShared.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpression.h"
#include "Runtime/Engine/Classes/Materials/MaterialFunction.h"
#include "Runtime/Engine/Classes/Materials/MaterialFunctionInterface.h"
#include "Runtime/Engine/Classes/Materials/MaterialParameterCollection.h"
#include "Runtime/Engine/Classes/Engine/BlendableInterface.h"
#include "Runtime/Engine/Classes/GameFramework/DebugTextInfo.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "Runtime/Engine/Classes/Camera/CameraTypes.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
#include "Runtime/Engine/Classes/Engine/TextureCube.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier.h"
#include "Runtime/Engine/Classes/Particles/EmitterCameraLensEffectBase.h"
#include "Runtime/Engine/Classes/Particles/Emitter.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystem.h"
#include "Runtime/Engine/Classes/Particles/ParticleEmitter.h"
#include "Runtime/Engine/Public/ParticleHelper.h"
#include "Runtime/Engine/Classes/Particles/ParticleLODLevel.h"
#include "Runtime/Engine/Classes/Particles/ParticleModuleRequired.h"
#include "Runtime/Engine/Classes/Particles/ParticleModule.h"
#include "Runtime/Engine/Classes/Particles/ParticleSpriteEmitter.h"
#include "Runtime/Engine/Classes/Distributions/DistributionFloat.h"
#include "Runtime/Engine/Classes/Distributions/Distribution.h"
#include "Runtime/Engine/Classes/Particles/SubUVAnimation.h"
#include "Runtime/Engine/Classes/Particles/TypeData/ParticleModuleTypeDataBase.h"
#include "Runtime/Engine/Classes/Particles/Spawn/ParticleModuleSpawn.h"
#include "Runtime/Engine/Classes/Particles/Spawn/ParticleModuleSpawnBase.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventGenerator.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventBase.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventSendToGame.h"
#include "Runtime/Engine/Classes/Particles/Orbit/ParticleModuleOrbit.h"
#include "Runtime/Engine/Classes/Particles/Orbit/ParticleModuleOrbitBase.h"
#include "Runtime/Engine/Classes/Distributions/DistributionVector.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventReceiverBase.h"
#include "Runtime/Engine/Classes/Engine/InterpCurveEdSetup.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemReplay.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Materials/MaterialLayersFunctions.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceBasePropertyOverrides.h"
#include "Runtime/Engine/Public/StaticParameterSet.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier_CameraShake.h"
#include "Runtime/Engine/Classes/Camera/CameraShake.h"
#include "Runtime/Engine/Classes/Camera/CameraAnim.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroup.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrack.h"
#include "Runtime/Engine/Classes/Camera/CameraAnimInst.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupInst.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstMove.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/GameFramework/CheatManager.h"
#include "Runtime/Engine/Classes/Engine/DebugCameraController.h"
#include "Runtime/Engine/Classes/Components/DrawFrustumComponent.h"
#include "Runtime/Engine/Classes/GameFramework/ForceFeedbackEffect.h"
#include "Runtime/Engine/Classes/Engine/NetConnection.h"
#include "Runtime/Engine/Classes/Engine/ChildConnection.h"
#include "Runtime/Engine/Classes/Engine/PackageMapClient.h"
#include "Runtime/Engine/Classes/Engine/NetDriver.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Engine/Level.h"
#include "Runtime/Engine/Classes/Components/ModelComponent.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_CollisionDataProvider.h"
#include "Runtime/Engine/Classes/Engine/LevelActorContainer.h"
#include "Runtime/Engine/Classes/Engine/LevelScriptActor.h"
#include "Runtime/Engine/Classes/Engine/NavigationObjectBase.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationDataChunk.h"
#include "Runtime/Engine/Classes/Engine/MapBuildDataRegistry.h"
#include "Runtime/Engine/Classes/GameFramework/WorldSettings.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemConfig.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPhysicsVolume.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsCollisionHandler.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Runtime/Engine/Classes/Sound/SoundClass.h"
#include "Runtime/Engine/Classes/Sound/SoundMix.h"
#include "Runtime/Engine/Classes/Sound/SoundConcurrency.h"
#include "Runtime/Engine/Classes/Sound/SoundAttenuation.h"
#include "Runtime/Engine/Classes/Engine/Attenuation.h"
#include "Runtime/Engine/Public/IAudioExtensionPlugin.h"
#include "Runtime/Engine/Classes/Sound/SoundSubmix.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectSubmix.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectPreset.h"
#include "Runtime/Engine/Public/IAmbisonicsMixer.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Runtime/AudioPlatformConfiguration/Public/AudioCompressionSettings.h"
#include "Runtime/Engine/Classes/Sound/SoundGroups.h"
#include "Runtime/Engine/Classes/Engine/CurveTable.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectSource.h"
#include "Runtime/Engine/Classes/Sound/SoundSourceBusSend.h"
#include "Runtime/Engine/Classes/Sound/SoundSourceBus.h"
#include "Runtime/Engine/Classes/GameFramework/GameModeBase.h"
#include "Runtime/Engine/Classes/GameFramework/GameSession.h"
#include "Runtime/Engine/Classes/GameFramework/GameStateBase.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawn.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPawn.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Public/PerPlatformProperties.h"
#include "Runtime/Engine/Public/Components.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshSocket.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavCollisionBase.h"
#include "Runtime/Engine/Classes/Engine/TextureStreamingTypes.h"
#include "Runtime/Engine/Classes/GameFramework/FloatingPawnMovement.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawnMovement.h"
#include "Runtime/Engine/Classes/Engine/ServerStatReplicator.h"
#include "Runtime/Engine/Classes/GameFramework/GameNetworkManager.h"
#include "Runtime/Engine/Classes/Sound/AudioVolume.h"
#include "Runtime/Engine/Classes/Sound/ReverbEffect.h"
#include "Runtime/Engine/Classes/Engine/BookMark.h"
#include "Runtime/Engine/Classes/Engine/BookmarkBase.h"
#include "DmgTypeBP_Environmental__pf1001828891.h"
#include "Runtime/Engine/Classes/Components/LineBatchComponent.h"
#include "Runtime/Engine/Classes/Engine/LevelStreaming.h"
#include "Runtime/Engine/Classes/Engine/LevelStreamingVolume.h"
#include "Runtime/Engine/Classes/Engine/DemoNetDriver.h"
#include "Runtime/Engine/Classes/Particles/ParticleEventManager.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemBase.h"
#include "Runtime/Engine/Classes/AI/AISystemBase.h"
#include "Runtime/Engine/Classes/AI/Navigation/AvoidanceManager.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Runtime/Engine/Classes/Engine/ScriptViewportClient.h"
#include "Runtime/Engine/Classes/Engine/Console.h"
#include "Runtime/Engine/Classes/Engine/DebugDisplayProperty.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/GameFramework/GameUserSettings.h"
#include "Runtime/Engine/Classes/Engine/AssetManager.h"
#include "Runtime/Engine/Classes/Engine/EngineCustomTimeStep.h"
#include "Runtime/Engine/Classes/Engine/TimecodeProvider.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineSession.h"
#include "Runtime/Engine/Classes/Materials/MaterialParameterCollectionInstance.h"
#include "Runtime/Engine/Classes/Engine/WorldComposition.h"
#include "Runtime/Engine/Classes/Particles/WorldPSCPool.h"
#include "Runtime/Engine/Classes/Engine/Channel.h"
#include "Runtime/Engine/Classes/Engine/ReplicationDriver.h"
#include "Runtime/Engine/Classes/GameFramework/TouchInterface.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Widget.h"
#include "Runtime/UMG/Public/Components/Visual.h"
#include "Runtime/UMG/Public/Components/PanelSlot.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Components/SlateWrapperTypes.h"
#include "Runtime/UMG/Public/Slate/WidgetTransform.h"
#include "Runtime/SlateCore/Public/Layout/Clipping.h"
#include "Runtime/UMG/Public/Blueprint/WidgetNavigation.h"
#include "Runtime/SlateCore/Public/Input/NavigationReply.h"
#include "Runtime/SlateCore/Public/Types/SlateEnums.h"
#include "Runtime/UMG/Public/Binding/PropertyBinding.h"
#include "Runtime/UMG/Public/Binding/DynamicPropertyPath.h"
#include "Runtime/PropertyPath/Public/PropertyPathHelpers.h"
#include "Runtime/SlateCore/Public/Layout/Geometry.h"
#include "Runtime/SlateCore/Public/Input/Events.h"
#include "Runtime/SlateCore/Public/Styling/SlateColor.h"
#include "Runtime/SlateCore/Public/Styling/SlateBrush.h"
#include "Runtime/SlateCore/Public/Layout/Margin.h"
#include "Runtime/SlateCore/Public/Styling/SlateTypes.h"
#include "Runtime/UMG/Public/Animation/UMGSequencePlayer.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimation.h"
#include "Runtime/MovieScene/Public/MovieSceneSequence.h"
#include "Runtime/MovieScene/Public/MovieSceneSignedObject.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationTemplate.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTrackIdentifier.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationTrack.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSegment.h"
#include "Runtime/MovieScene/Public/MovieSceneTrack.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvalTemplate.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTrackImplementation.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationField.h"
#include "Runtime/MovieScene/Public/MovieSceneFrameMigration.h"
#include "Runtime/MovieScene/Public/MovieSceneSequenceID.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationKey.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceHierarchy.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceTransform.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceInstanceData.h"
#include "Runtime/MovieScene/Public/MovieSceneSection.h"
#include "Runtime/MovieScene/Public/MovieScene.h"
#include "Runtime/MovieScene/Public/MovieSceneSpawnable.h"
#include "Runtime/MovieScene/Public/MovieScenePossessable.h"
#include "Runtime/MovieScene/Public/MovieSceneBinding.h"
#include "Runtime/MovieScene/Public/MovieSceneFwd.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimationBinding.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/Slate/Public/Widgets/Layout/Anchors.h"
#include "Runtime/UMG/Public/Blueprint/DragDropOperation.h"
#include "Runtime/UMG/Public/Components/NamedSlotInterface.h"
#include "Runtime/Engine/Classes/Haptics/HapticFeedbackEffect_Base.h"
#include "Runtime/Engine/Classes/Engine/LatentActionManager.h"
#include "Runtime/Engine/Classes/Matinee/MatineeActor.h"
#include "Runtime/Engine/Classes/Matinee/InterpData.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupDirector.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavRelevantInterface.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Runtime/Engine/Public/SkeletalMeshReductionSettings.h"
#include "Runtime/Engine/Classes/Animation/AnimSequence.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsAsset.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicalAnimationComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintTemplate.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintInstance.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintTypes.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintDrives.h"
#include "Runtime/Engine/Classes/EditorFramework/ThumbnailInfo.h"
#include "Runtime/Engine/Public/Animation/NodeMappingContainer.h"
#include "Runtime/Engine/Public/Animation/NodeMappingProviderInterface.h"
#include "Runtime/Engine/Classes/Animation/MorphTarget.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Public/Animation/AnimNotifyQueue.h"
#include "Runtime/Engine/Public/Animation/PoseSnapshot.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingAssetInterface.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSampling.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshLODSettings.h"
#include "Runtime/Engine/Classes/Engine/Blueprint.h"
#include "Runtime/Engine/Classes/Engine/BlueprintCore.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/Engine/TimelineTemplate.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Curves/CurveVector.h"
#include "Runtime/Engine/Classes/Curves/CurveLinearColor.h"
#include "Runtime/Engine/Classes/Engine/InheritableComponentHandler.h"
#include "Runtime/Engine/Classes/Animation/AnimBlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/Engine/DynamicBlueprintBinding.h"
#include "Runtime/Engine/Classes/Animation/AnimStateMachineTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimClassInterface.h"
#include "Runtime/Engine/Public/SingleAnimationPlayData.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingSimulationFactoryInterface.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingSimulationInteractor.h"
#include "Runtime/ClothingSystemRuntime/Public/ClothingSimulationFactory.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/NavigationSystem/Public/NavAreas/NavArea_Obstacle.h"
#include "Runtime/Engine/Classes/Components/ArrowComponent.h"


#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
PRAGMA_DISABLE_OPTIMIZATION
ASlideSnow_C__pf2739524524::ASlideSnow_C__pf2739524524(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if(HasAnyFlags(RF_ClassDefaultObject) && (ASlideSnow_C__pf2739524524::StaticClass() == GetClass()))
	{
		ASlideSnow_C__pf2739524524::__CustomDynamicClassInitialization(CastChecked<UDynamicClass>(GetClass()));
	}
	
	auto __Local__0 = CastChecked<UCapsuleComponent>(this->GetDefaultSubobjectByName(TEXT("CollisionCylinder")), ECastCheckedType::NullAllowed);
	auto __Local__1 = CastChecked<UCharacterMovementComponent>(this->GetDefaultSubobjectByName(TEXT("CharMoveComp")), ECastCheckedType::NullAllowed);
	auto __Local__2 = CastChecked<USkeletalMeshComponent>(this->GetDefaultSubobjectByName(TEXT("CharacterMesh0")), ECastCheckedType::NullAllowed);
	if(__Local__0)
	{
		// --- Default subobject 'CollisionCylinder' //
		__Local__0->AreaClass = UNavArea_Obstacle::StaticClass();
		static TWeakObjectPtr<UProperty> __Local__4{};
		const UProperty* __Local__3 = __Local__4.Get();
		if (nullptr == __Local__3)
		{
			__Local__3 = (UActorComponent::StaticClass())->FindPropertyByName(FName(TEXT("bCanEverAffectNavigation")));
			check(__Local__3);
			__Local__4 = __Local__3;
		}
		(((UBoolProperty*)__Local__3)->SetPropertyValue_InContainer((__Local__0), false, 0));
		// --- END default subobject 'CollisionCylinder' //
	}
	if(__Local__1)
	{
		// --- Default subobject 'CharMoveComp' //
		__Local__1->MaxWalkSpeed = 1000.000000f;
		__Local__1->MaxAcceleration = 9000.000000f;
		static TWeakObjectPtr<UProperty> __Local__6{};
		const UProperty* __Local__5 = __Local__6.Get();
		if (nullptr == __Local__5)
		{
			__Local__5 = (UNavMovementComponent::StaticClass())->FindPropertyByName(FName(TEXT("bUseAccelerationForPaths")));
			check(__Local__5);
			__Local__6 = __Local__5;
		}
		(((UBoolProperty*)__Local__5)->SetPropertyValue_InContainer((__Local__1), false, 0));
		static TWeakObjectPtr<UProperty> __Local__8{};
		const UProperty* __Local__7 = __Local__8.Get();
		if (nullptr == __Local__7)
		{
			__Local__7 = (UActorComponent::StaticClass())->FindPropertyByName(FName(TEXT("bCanEverAffectNavigation")));
			check(__Local__7);
			__Local__8 = __Local__7;
		}
		(((UBoolProperty*)__Local__7)->SetPropertyValue_InContainer((__Local__1), false, 0));
		// --- END default subobject 'CharMoveComp' //
	}
	if(__Local__2)
	{
		// --- Default subobject 'CharacterMesh0' //
		__Local__2->ClothingSimulationFactory = UClothingSimulationFactoryNv::StaticClass();
		__Local__2->SkeletalMesh = CastChecked<USkeletalMesh>(CastChecked<UDynamicClass>(ASlideSnow_C__pf2739524524::StaticClass())->UsedAssets[0], ECastCheckedType::NullAllowed);
		__Local__2->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPose;
		__Local__2->bRenderCustomDepth = true;
		auto& __Local__9 = (*(AccessPrivateProperty<UCapsuleComponent*>((__Local__2), USceneComponent::__PPO__AttachParent() )));
		__Local__9 = __Local__0;
		__Local__2->RelativeLocation = FVector(9.088317, -1.232606, -70.000000);
		__Local__2->RelativeRotation = FRotator(0.000000, -50.000153, 0.000000);
		__Local__2->RelativeScale3D = FVector(0.100000, 0.100000, 0.100000);
		static TWeakObjectPtr<UProperty> __Local__11{};
		const UProperty* __Local__10 = __Local__11.Get();
		if (nullptr == __Local__10)
		{
			__Local__10 = (UActorComponent::StaticClass())->FindPropertyByName(FName(TEXT("bCanEverAffectNavigation")));
			check(__Local__10);
			__Local__11 = __Local__10;
		}
		(((UBoolProperty*)__Local__10)->SetPropertyValue_InContainer((__Local__2), false, 0));
		// --- END default subobject 'CharacterMesh0' //
	}
	bpv__Snow__pf = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Snow"));
	bpv__CameraFront__pf = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraFront"));
	bpv__snowSlide__pf = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("snowSlide"));
	bpv__SpringArm__pf = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	bpv__CameraRear__pf = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraRear"));
	bpv__Snow__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__Snow__pf->AttachToComponent(__Local__0, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__Snow__pf->ClothingSimulationFactory = UClothingSimulationFactoryNv::StaticClass();
	bpv__Snow__pf->SkeletalMesh = CastChecked<USkeletalMesh>(CastChecked<UDynamicClass>(ASlideSnow_C__pf2739524524::StaticClass())->UsedAssets[1], ECastCheckedType::NullAllowed);
	bpv__Snow__pf->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	bpv__Snow__pf->OverrideMaterials = TArray<UMaterialInterface*> ();
	bpv__Snow__pf->OverrideMaterials.Reserve(12);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->OverrideMaterials.Add(nullptr);
	bpv__Snow__pf->bRenderCustomDepth = true;
	bpv__Snow__pf->RelativeLocation = FVector(-9.999962, -0.000001, -80.000000);
	bpv__Snow__pf->RelativeRotation = FRotator(0.000000, -90.000214, 0.000000);
	bpv__Snow__pf->RelativeScale3D = FVector(0.070000, 0.070000, 0.070000);
	static TWeakObjectPtr<UProperty> __Local__13{};
	const UProperty* __Local__12 = __Local__13.Get();
	if (nullptr == __Local__12)
	{
		__Local__12 = (UActorComponent::StaticClass())->FindPropertyByName(FName(TEXT("bCanEverAffectNavigation")));
		check(__Local__12);
		__Local__13 = __Local__12;
	}
	(((UBoolProperty*)__Local__12)->SetPropertyValue_InContainer((bpv__Snow__pf), false, 0));
	bpv__CameraFront__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__CameraFront__pf->AttachToComponent(__Local__0, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__CameraFront__pf->RelativeLocation = FVector(1440.000000, -0.004418, 0.000000);
	bpv__CameraFront__pf->RelativeRotation = FRotator(0.000000, 179.999756, 0.000000);
	(((UBoolProperty*)__Local__12)->SetPropertyValue_InContainer((bpv__CameraFront__pf), false, 0));
	bpv__snowSlide__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__snowSlide__pf->AttachToComponent(__Local__0, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__snowSlide__pf->RelativeLocation = FVector(0.000000, 0.000000, -80.000000);
	bpv__snowSlide__pf->RelativeRotation = FRotator(0.000000, -179.999512, 0.000000);
	bpv__snowSlide__pf->bAutoActivate = false;
	(((UBoolProperty*)__Local__12)->SetPropertyValue_InContainer((bpv__snowSlide__pf), false, 0));
	bpv__SpringArm__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__SpringArm__pf->AttachToComponent(__Local__0, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__SpringArm__pf->bEnableCameraLag = true;
	(((UBoolProperty*)__Local__12)->SetPropertyValue_InContainer((bpv__SpringArm__pf), false, 0));
	bpv__CameraRear__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__CameraRear__pf->AttachToComponent(bpv__SpringArm__pf, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__CameraRear__pf->RelativeLocation = FVector(-260.000000, 0.000000, 0.000000);
	bpv__CameraRear__pf->RelativeRotation = FRotator(0.000000, 0.000000, 0.000110);
	(((UBoolProperty*)__Local__12)->SetPropertyValue_InContainer((bpv__CameraRear__pf), false, 0));
	bpv__TinaHealth__pf = 0.000000f;
	bpv__ammo__pf = 0;
	bpv__totalAmmo__pf = 0;
	bpv__points__pf = 0;
	bpv__posesed__pf = false;
	bpv__slideRight__pf = false;
	bpv__slideLeft__pf = false;
	bpv__cameraRearRotation__pf = FRotator(0.000000, 0.000000, 0.000000);
	bpv__cameraFrontRotation__pf = FRotator(0.000000, 0.000000, 0.000000);
	auto& __Local__14 = (*(AccessPrivateProperty<USkeletalMeshComponent*>((this), ACharacter::__PPO__Mesh() )));
	__Local__14 = __Local__2;
	auto& __Local__15 = (*(AccessPrivateProperty<UCharacterMovementComponent*>((this), ACharacter::__PPO__CharacterMovement() )));
	__Local__15 = __Local__1;
	auto& __Local__16 = (*(AccessPrivateProperty<UCapsuleComponent*>((this), ACharacter::__PPO__CapsuleComponent() )));
	__Local__16 = __Local__0;
}
PRAGMA_ENABLE_OPTIMIZATION
void ASlideSnow_C__pf2739524524::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	if(bpv__Snow__pf)
	{
		bpv__Snow__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__CameraFront__pf)
	{
		bpv__CameraFront__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__snowSlide__pf)
	{
		bpv__snowSlide__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__SpringArm__pf)
	{
		bpv__SpringArm__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__CameraRear__pf)
	{
		bpv__CameraRear__pf->CreationMethod = EComponentCreationMethod::Native;
	}
}
PRAGMA_DISABLE_OPTIMIZATION
void ASlideSnow_C__pf2739524524::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
	auto __Local__17 = NewObject<USceneComponent>(InDynamicClass, USceneComponent::StaticClass(), TEXT("DefaultSceneRoot_GEN_VARIABLE"));
	InDynamicClass->ComponentTemplates.Add(__Local__17);
	auto __Local__18 = NewObject<UInputAxisDelegateBinding>(InDynamicClass, UInputAxisDelegateBinding::StaticClass(), TEXT("InputAxisDelegateBinding_1"));
	InDynamicClass->DynamicBindingObjects.Add(__Local__18);
	auto __Local__19 = NewObject<UInputKeyDelegateBinding>(InDynamicClass, UInputKeyDelegateBinding::StaticClass(), TEXT("InputKeyDelegateBinding_1"));
	InDynamicClass->DynamicBindingObjects.Add(__Local__19);
	static TWeakObjectPtr<UProperty> __Local__21{};
	const UProperty* __Local__20 = __Local__21.Get();
	if (nullptr == __Local__20)
	{
		__Local__20 = (UActorComponent::StaticClass())->FindPropertyByName(FName(TEXT("bCanEverAffectNavigation")));
		check(__Local__20);
		__Local__21 = __Local__20;
	}
	(((UBoolProperty*)__Local__20)->SetPropertyValue_InContainer((__Local__17), false, 0));
	__Local__18->InputAxisDelegateBindings = TArray<FBlueprintInputAxisDelegateBinding> ();
	__Local__18->InputAxisDelegateBindings.AddUninitialized(1);
	FBlueprintInputAxisDelegateBinding::StaticStruct()->InitializeStruct(__Local__18->InputAxisDelegateBindings.GetData(), 1);
	auto& __Local__22 = __Local__18->InputAxisDelegateBindings[0];
	__Local__22.InputAxisName = FName(TEXT("MoveRight"));
	__Local__22.FunctionNameToBind = FName(TEXT("InpAxisEvt_MoveRight_K2Node_InputAxisEvent_0"));
	__Local__19->InputKeyDelegateBindings = TArray<FBlueprintInputKeyDelegateBinding> ();
	__Local__19->InputKeyDelegateBindings.AddUninitialized(5);
	FBlueprintInputKeyDelegateBinding::StaticStruct()->InitializeStruct(__Local__19->InputKeyDelegateBindings.GetData(), 5);
	auto& __Local__23 = __Local__19->InputKeyDelegateBindings[0];
	__Local__23.InputChord.Key = FKey(TEXT("D"));
	__Local__23.InputKeyEvent = EInputEvent::IE_Released;
	__Local__23.FunctionNameToBind = FName(TEXT("InpActEvt_D_K2Node_InputKeyEvent_4"));
	auto& __Local__24 = __Local__19->InputKeyDelegateBindings[1];
	__Local__24.InputChord.Key = FKey(TEXT("SpaceBar"));
	__Local__24.FunctionNameToBind = FName(TEXT("InpActEvt_SpaceBar_K2Node_InputKeyEvent_0"));
	auto& __Local__25 = __Local__19->InputKeyDelegateBindings[2];
	__Local__25.InputChord.Key = FKey(TEXT("A"));
	__Local__25.FunctionNameToBind = FName(TEXT("InpActEvt_A_K2Node_InputKeyEvent_1"));
	auto& __Local__26 = __Local__19->InputKeyDelegateBindings[3];
	__Local__26.InputChord.Key = FKey(TEXT("A"));
	__Local__26.InputKeyEvent = EInputEvent::IE_Released;
	__Local__26.FunctionNameToBind = FName(TEXT("InpActEvt_A_K2Node_InputKeyEvent_2"));
	auto& __Local__27 = __Local__19->InputKeyDelegateBindings[4];
	__Local__27.InputChord.Key = FKey(TEXT("D"));
	__Local__27.FunctionNameToBind = FName(TEXT("InpActEvt_D_K2Node_InputKeyEvent_3"));
}
PRAGMA_ENABLE_OPTIMIZATION
void ASlideSnow_C__pf2739524524::bpf__ExecuteUbergraph_SlideSnow__pf_0(int32 bpp__EntryPoint__pf)
{
	FRotator bpfv__CallFunc_K2_GetActorRotation_ReturnValue__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_GetForwardVector_ReturnValue__pf(EForceInit::ForceInit);
	UPawnMovementComponent* bpfv__CallFunc_GetMovementComponent_ReturnValue__pf{};
	bool bpfv__CallFunc_IsFalling_ReturnValue__pf{};
	TArray< int32, TInlineAllocator<8> > __StateStack;

	int32 __CurrentState = bpp__EntryPoint__pf;
	do
	{
		switch( __CurrentState )
		{
		case 20:
			{
			}
		case 21:
			{
				if (!bpv__posesed__pf)
				{
					__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
					break;
				}
			}
		case 22:
			{
				__StateStack.Push(23);
				__CurrentState = 25;
				break;
			}
		case 23:
			{
			}
		case 24:
			{
				bpfv__CallFunc_GetMovementComponent_ReturnValue__pf = GetMovementComponent();
				if(::IsValid(bpfv__CallFunc_GetMovementComponent_ReturnValue__pf))
				{
					bpfv__CallFunc_IsFalling_ReturnValue__pf = bpfv__CallFunc_GetMovementComponent_ReturnValue__pf->IsFalling();
				}
				if (!bpfv__CallFunc_IsFalling_ReturnValue__pf)
				{
					__CurrentState = 26;
					break;
				}
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 25:
			{
				bpfv__CallFunc_K2_GetActorRotation_ReturnValue__pf = AActor::K2_GetActorRotation();
				bpfv__CallFunc_GetForwardVector_ReturnValue__pf = UKismetMathLibrary::GetForwardVector(bpfv__CallFunc_K2_GetActorRotation_ReturnValue__pf);
				AddMovementInput(bpfv__CallFunc_GetForwardVector_ReturnValue__pf, 4.000000, false);
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 26:
			{
				if(::IsValid(bpv__snowSlide__pf))
				{
					bpv__snowSlide__pf->USceneComponent::SetVisibility(true, false);
				}
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( __CurrentState != -1 );
}
void ASlideSnow_C__pf2739524524::bpf__ExecuteUbergraph_SlideSnow__pf_1(int32 bpp__EntryPoint__pf)
{
	bool bpfv__CallFunc_IsActive_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 13);
	Jump();
	if(::IsValid(bpv__snowSlide__pf))
	{
		bpfv__CallFunc_IsActive_ReturnValue__pf = bpv__snowSlide__pf->IsActive();
	}
	if (!bpfv__CallFunc_IsActive_ReturnValue__pf)
	{
		return; //KCST_EndOfThreadIfNot
	}
	if(::IsValid(bpv__snowSlide__pf))
	{
		bpv__snowSlide__pf->USceneComponent::SetVisibility(false, false);
	}
	return; //KCST_EndOfThread
}
void ASlideSnow_C__pf2739524524::bpf__ExecuteUbergraph_SlideSnow__pf_2(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 7);
	b0l__Temp_struct_Variable1__pf = b0l__K2Node_InputKeyEvent_Key2__pf;
	bpv__slideLeft__pf = false;
	return; //KCST_EndOfThread
}
void ASlideSnow_C__pf2739524524::bpf__ExecuteUbergraph_SlideSnow__pf_3(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 28);
	b0l__Temp_struct_Variable__pf = b0l__K2Node_InputKeyEvent_Key4__pf;
	// optimized KCST_UnconditionalGoto
	bpv__slideRight__pf = false;
	return; //KCST_EndOfThread
}
void ASlideSnow_C__pf2739524524::bpf__ExecuteUbergraph_SlideSnow__pf_4(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 10);
	b0l__Temp_struct_Variable1__pf = b0l__K2Node_InputKeyEvent_Key1__pf;
	bpv__slideLeft__pf = true;
	return; //KCST_EndOfThread
}
void ASlideSnow_C__pf2739524524::bpf__ExecuteUbergraph_SlideSnow__pf_5(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 17);
	if(::IsValid(bpv__CameraFront__pf))
	{
		bpv__CameraFront__pf->SetActive(false, false);
	}
	if(::IsValid(bpv__CameraRear__pf))
	{
		bpv__CameraRear__pf->SetActive(true, false);
	}
	return; //KCST_EndOfThread
}
void ASlideSnow_C__pf2739524524::bpf__ExecuteUbergraph_SlideSnow__pf_6(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 4);
	b0l__Temp_struct_Variable__pf = b0l__K2Node_InputKeyEvent_Key3__pf;
	bpv__slideRight__pf = true;
	return; //KCST_EndOfThread
}
void ASlideSnow_C__pf2739524524::bpf__ExecuteUbergraph_SlideSnow__pf_7(int32 bpp__EntryPoint__pf)
{
	float bpfv__CallFunc_Multiply_FloatFloat_ReturnValue__pf{};
	float bpfv__CallFunc_Multiply_FloatFloat_ReturnValue1__pf{};
	FRotator bpfv__CallFunc_K2_GetActorRotation_ReturnValue__pf(EForceInit::ForceInit);
	FVector bpfv__CallFunc_GetRightVector_ReturnValue__pf(EForceInit::ForceInit);
	check(bpp__EntryPoint__pf == 1);
	bpfv__CallFunc_Multiply_FloatFloat_ReturnValue1__pf = UKismetMathLibrary::Multiply_FloatFloat(b0l__K2Node_InputAxisEvent_AxisValue__pf, 4.000000);
	bpfv__CallFunc_K2_GetActorRotation_ReturnValue__pf = AActor::K2_GetActorRotation();
	bpfv__CallFunc_GetRightVector_ReturnValue__pf = UKismetMathLibrary::GetRightVector(bpfv__CallFunc_K2_GetActorRotation_ReturnValue__pf);
	AddMovementInput(bpfv__CallFunc_GetRightVector_ReturnValue__pf, bpfv__CallFunc_Multiply_FloatFloat_ReturnValue1__pf, false);
	bpfv__CallFunc_Multiply_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Multiply_FloatFloat(b0l__K2Node_InputAxisEvent_AxisValue__pf, 2.000000);
	AddControllerYawInput(bpfv__CallFunc_Multiply_FloatFloat_ReturnValue__pf);
	return; //KCST_EndOfThread
}
void ASlideSnow_C__pf2739524524::bpf__InpAxisEvt_MoveRight_K2Node_InputAxisEvent_0__pf(float bpp__AxisValue__pf)
{
	b0l__K2Node_InputAxisEvent_AxisValue__pf = bpp__AxisValue__pf;
	bpf__ExecuteUbergraph_SlideSnow__pf_7(1);
}
void ASlideSnow_C__pf2739524524::bpf__ReceiveTick__pf(float bpp__DeltaSeconds__pf)
{
	b0l__K2Node_Event_DeltaSeconds__pf = bpp__DeltaSeconds__pf;
	bpf__ExecuteUbergraph_SlideSnow__pf_0(20);
}
void ASlideSnow_C__pf2739524524::bpf__ReceiveBeginPlay__pf()
{
	bpf__ExecuteUbergraph_SlideSnow__pf_5(17);
}
void ASlideSnow_C__pf2739524524::bpf__InpActEvt_SpaceBar_K2Node_InputKeyEvent_0__pf(FKey bpp__Key__pf)
{
	b0l__K2Node_InputKeyEvent_Key__pf = bpp__Key__pf;
	bpf__ExecuteUbergraph_SlideSnow__pf_1(13);
}
void ASlideSnow_C__pf2739524524::bpf__InpActEvt_A_K2Node_InputKeyEvent_1__pf(FKey bpp__Key__pf)
{
	b0l__K2Node_InputKeyEvent_Key1__pf = bpp__Key__pf;
	bpf__ExecuteUbergraph_SlideSnow__pf_4(10);
}
void ASlideSnow_C__pf2739524524::bpf__InpActEvt_A_K2Node_InputKeyEvent_2__pf(FKey bpp__Key__pf)
{
	b0l__K2Node_InputKeyEvent_Key2__pf = bpp__Key__pf;
	bpf__ExecuteUbergraph_SlideSnow__pf_2(7);
}
void ASlideSnow_C__pf2739524524::bpf__InpActEvt_D_K2Node_InputKeyEvent_3__pf(FKey bpp__Key__pf)
{
	b0l__K2Node_InputKeyEvent_Key3__pf = bpp__Key__pf;
	bpf__ExecuteUbergraph_SlideSnow__pf_6(4);
}
void ASlideSnow_C__pf2739524524::bpf__InpActEvt_D_K2Node_InputKeyEvent_4__pf(FKey bpp__Key__pf)
{
	b0l__K2Node_InputKeyEvent_Key4__pf = bpp__Key__pf;
	bpf__ExecuteUbergraph_SlideSnow__pf_3(28);
}
void ASlideSnow_C__pf2739524524::bpf__UserConstructionScript__pf()
{
}
PRAGMA_DISABLE_OPTIMIZATION
void ASlideSnow_C__pf2739524524::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{0, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  SkeletalMesh /Game/migrate/Tina_AndersenVersionFinal.Tina_AndersenVersionFinal 
		{1, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  SkeletalMesh /Game/migrate/SnowCinematics.SnowCinematics 
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
PRAGMA_DISABLE_OPTIMIZATION
void ASlideSnow_C__pf2739524524::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_DirectlyUsedAssets(AssetsToLoad);
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{2, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.SkeletalMeshComponent 
		{3, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/ClothingSystemRuntime.ClothingSimulationFactoryNv 
		{4, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.CameraComponent 
		{5, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.ParticleSystemComponent 
		{6, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.SpringArmComponent 
		{7, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.SceneComponent 
		{8, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/InputCore.Key 
		{9, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.PawnMovementComponent 
		{10, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetMathLibrary 
		{11, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.Actor 
		{12, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.Character 
		{13, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.PointerToUberGraphFrame 
		{14, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/NavigationSystem.NavArea_Obstacle 
		{15, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/AIModule.AIController 
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
struct FRegisterHelper__ASlideSnow_C__pf2739524524
{
	FRegisterHelper__ASlideSnow_C__pf2739524524()
	{
		FConvertedBlueprintsDependencies::Get().RegisterConvertedClass(TEXT("/Game/migrate/SlideSnow"), &ASlideSnow_C__pf2739524524::__StaticDependenciesAssets);
	}
	static FRegisterHelper__ASlideSnow_C__pf2739524524 Instance;
};
FRegisterHelper__ASlideSnow_C__pf2739524524 FRegisterHelper__ASlideSnow_C__pf2739524524::Instance;
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
