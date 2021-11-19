// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"


/*void UMenuWidget::Join(FString sIP)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, sIP);
}*/

/*void UMenuWidget::Host(FString sIP)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, sIP);
}*/

void UMenuWidget::Commande(FString sCommande)
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->ConsoleCommand(*sCommande);
}
