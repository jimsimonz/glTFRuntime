// Copyright 2020-2022, Roberto De Ioris.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundWave.h"
#include "glTFRuntimeSoundWave.generated.h"

/**
 * 
 */
UCLASS()
class GLTFRUNTIME_API UglTFRuntimeSoundWave : public USoundWave
{
	GENERATED_BODY()

public:
	UglTFRuntimeSoundWave();

	virtual int32 GeneratePCMData(uint8* PCMData, const int32 SamplesNeeded, const int32 Clock) override;
	virtual bool HasCompressedData(FName Format, ITargetPlatform* TargetPlatform) const override { return false; }

	virtual void SetRuntimeAudioData(const uint8* AudioData, const int64 AudioDataSize)
	{
		RuntimeAudioData.Empty();
		RuntimeAudioData.Append(AudioData, AudioDataSize);
		RuntimeAudioOffset = 0;
	}

	UFUNCTION(BlueprintCallable, Category="glTFRuntime")
	void ResetAudioOffset();

	UFUNCTION(BlueprintCallable, Category = "glTFRuntime")
	UglTFRuntimeSoundWave* DuplicateRuntimeSoundWave();

protected:
	TArray64<uint8> RuntimeAudioData;
	int64 RuntimeAudioOffset;
	
};
