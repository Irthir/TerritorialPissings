// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"


void UMenuWidget::Join(FString sIP)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, sIP);
}

void UMenuWidget::Host()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Host"));

	FString sCommande = "open MainLevel?listen";

	GetWorld()->Exec(GetWorld(), *sCommande);

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, *sCommande);
}
