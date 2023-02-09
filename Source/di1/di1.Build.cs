// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class di1 : ModuleRules
{
	public di1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "WebSockets" });
	}
}
