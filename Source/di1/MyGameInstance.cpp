// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "WebSocketsModule.h"

void UMyGameInstance::Init()
{
	Super::Init();
	if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
	{
		FModuleManager::Get().LoadModule("WebSockets");
	}

	WebSocket = FWebSocketsModule::Get().CreateWebSocket("wss://gtg3p8yh66.execute-api.us-east-1.amazonaws.com/production/");


	WebSocket->OnConnected().AddLambda([]()
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Successfully connected hehe");
		});

	WebSocket->OnConnectionError().AddLambda([](const FString& Error)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, Error);

		});

	WebSocket->OnClosed().AddLambda([](int32 StatusCode, const FString& Reason, bool bWasClean)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, bWasClean ? FColor::Green : FColor::Red, "Connection Closed" + Reason);
		});

	WebSocket->OnMessage().AddLambda([this](const FString& MessageString)
		{
			s = MessageString;
			s1 = MessageString;
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "Recieved message " + MessageString);
		});

	WebSocket->OnMessageSent().AddLambda([](const FString& MessageString)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Sent message" + MessageString);
		});

	WebSocket->Connect();
}


void UMyGameInstance::Shutdown()
{
	{
		if (WebSocket->IsConnected())
		{
			WebSocket->Close();
		}
		Super::Shutdown();
	}
}


