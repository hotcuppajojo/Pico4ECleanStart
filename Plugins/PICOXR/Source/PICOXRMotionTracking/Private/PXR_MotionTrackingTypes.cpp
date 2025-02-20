// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include "PXR_MotionTrackingTypes.h"
#include "PXR_HMDPrivate.h"
#include "PXR_HMD.h"

FPXRFaceTrackingData::FPXRFaceTrackingData()
	: TimeStamp(0)
	, LaughingProb(0.0f)
	, EyeValid(false)
	, FaceValid(false)
{
	BlendShapeWeights.SetNum(static_cast<int32>(EPXRFaceBlendShape::COUNT));
}

FPXRFaceTrackingDataGetInfo::FPXRFaceTrackingDataGetInfo()
	: DisplayTime(0)
{
}

FPXREyeTrackingDataGetInfo::FPXREyeTrackingDataGetInfo()
	: DisplayTime(0)
	, QueryPosition(true)
	, QueryOrientation(true)
{
}

FPXRPerEyeData::FPXRPerEyeData()
	:EyeType(EPICOEye::Center)
	, Position(0, 0, 0)
	, Orientation(0, 0, 0)
	, bIsPoseValid(false)
	, Openness(0.0f)
	, bIsOpennessValid(false)
{
}

FPXREyeTrackingData::FPXREyeTrackingData()
{
	PerEyeDatas.SetNum(static_cast<int32>(EPICOEye::COUNT));
}

FPXRBodyTrackingState::FPXRBodyTrackingState()
{
	CurrentTrackingMode = EPXRBodyTrackingMode::PXR_BTM_DISABLE;
	TrackingStateCode = EPXRTrackingStateCode::PXR_MT_FAILURE;
	TrackingStatusCode = EPXRBodyTrackingStatusCode();
	TrackingErrorCode = EPXRBodyTrackingErrorCode();
	ConnectedFitnessBand.Empty();
	ConnectedBandCount = 0;
}

FPXRBodyTrackingStartInfo::FPXRBodyTrackingStartInfo()
{
	StartMode = EPXRBodyTrackingMode::PXR_BTM_DISABLE;
}

FPXRBodyTrackingDataGetInfo::FPXRBodyTrackingDataGetInfo()
{
	DisplayTime=0.f;
}

FPXRBodyTrackingData::FPXRBodyTrackingData()
{
	RoleDatas.SetNum(BODY_TRACKING_DATA_ROLE_NUM_MAX);
}

FPXRMotionConnectState::FPXRMotionConnectState()
{
	TrackerSum=0;
	TrackersSNArray.Empty();
}

FPXRMotionTrackerLocation::FPXRMotionTrackerLocation()
{
	Pose = FTransform();
	AngularVelocity = FVector::ZeroVector;
	LinearVelocity = FVector::ZeroVector;
	AngularAcceleration = FVector::ZeroVector;
	LinearAcceleration = FVector::ZeroVector;
}

FPXRMotionTrackerLocations::FPXRMotionTrackerLocations()
{
	TrackerSN = "";
	LocalPose = FPXRMotionTrackerLocation();
	GlobalPose = FPXRMotionTrackerLocation();
}

FPXREyeTrackingState::FPXREyeTrackingState()
{
	CurrentTrackingMode = EPXREyeTrackingMode::PXR_ETM_NONE;
	TrackingStateCode = EPXRTrackingStateCode::PXR_MT_FAILURE;
}

FPXREyeTrackingStartInfo::FPXREyeTrackingStartInfo()
	:NeedCalibration(false)
{
	StartMode = EPXREyeTrackingMode::PXR_ETM_BOTH;
}

FPXRFaceTrackingState::FPXRFaceTrackingState()
{
	CurrentTrackingMode = EPXRFaceTrackingMode::PXR_FTM_NONE;
	TrackingStateCode = EPXRTrackingStateCode::PXR_MT_FAILURE;
}

FPXRFaceTrackingStartInfo::FPXRFaceTrackingStartInfo()
{
	StartMode = EPXRFaceTrackingMode::PXR_FTM_FACE;
}

FPXRFaceTrackingStopInfo::FPXRFaceTrackingStopInfo()
	:Pause(false)
{
}
