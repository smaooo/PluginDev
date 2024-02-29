// Copyright Epic Games, Inc. All Rights Reserved.

#include "Text_RandomizerBPLibrary.h"
#include "Text_Randomizer.h"
#include "Misc/Paths.h"
#include "Math/UnrealMathUtility.h"
#include "CoreMinimal.h"

UText_RandomizerBPLibrary::UText_RandomizerBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FString JustifyText(const FString& Text, int32 LineWidth)
{
    TArray<FString> Lines;
    Text.ParseIntoArrayLines(Lines);

    for (int32 i = 0; i < Lines.Num(); i++)
    {
        TArray<FString> Words;
        Lines[i].ParseIntoArray(Words, TEXT(" "), true);

        if (Words.Num() > 1) // Justify only if there's more than one word
        {
            int32 TotalSpacesNeeded = LineWidth - Lines[i].Len() + (Words.Num() - 1); // Calculate extra spaces needed
            int32 SpaceBetweenWords = TotalSpacesNeeded / (Words.Num() - 1);
            int32 ExtraSpaces = TotalSpacesNeeded % (Words.Num() - 1);

            FString JustifiedLine;
            for (int32 WordIndex = 0; WordIndex < Words.Num(); WordIndex++)
            {
                JustifiedLine += Words[WordIndex];
                if (WordIndex < Words.Num() - 1) // Don't add spaces after the last word
                {
                    int32 SpacesToAdd = SpaceBetweenWords + (ExtraSpaces-- > 0 ? 1 : 0); // Distribute extra spaces evenly
                    JustifiedLine += FString::ChrN(SpacesToAdd, ' ');
                }
            }
            Lines[i] = JustifiedLine;
        }
    }

    return FString::Join(Lines, TEXT("\n"));
}


FString WrapText(const FString& Text, int32 LineLength)
{
    FString WrappedText;
    FString CurrentLine;
    TArray<FString> Words;

    // Split the text into words
    Text.ParseIntoArray(Words, TEXT(" "), true);

    for (const FString& Word : Words)
    {
        // If adding the next word exceeds the line length, append the current line to WrappedText and start a new line
        if ((CurrentLine.Len() + 1 + Word.Len()) > LineLength)
        {
            WrappedText += CurrentLine + TEXT("\n");
            CurrentLine = Word;
        }
        else
        {
            // If not the first word in the line, add a space before the word
            if (!CurrentLine.IsEmpty())
            {
                CurrentLine += TEXT(" ");
            }
            CurrentLine += Word;
        }
    }

    // Add the final line to WrappedText
    if (!CurrentLine.IsEmpty())
    {
        WrappedText += CurrentLine;
    }

    return WrappedText;
}



bool UText_RandomizerBPLibrary::GetRandomSubText(FString path, int minCharacter, int characterNum, int charLineCount, bool justify, FString& RandomText) {
	FString fullPath = FPaths::ProjectContentDir();
	fullPath.Append(path);

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	if (!FileManager.FileExists(*fullPath)) return false;

	FString FileContent;

	if (FFileHelper::LoadFileToString(FileContent, *fullPath)) {
		const int length = FileContent.Len();
		const int start = FMath::RandRange(0, length - characterNum);

		const int begin = FileContent.Find(TEXT(". "), ESearchCase::IgnoreCase, ESearchDir::FromStart, start) + 2;
		FString text = FileContent.Mid(begin, characterNum);
		int end = text.Find(TEXT(". "), ESearchCase::IgnoreCase, ESearchDir::FromEnd);

		if (end == INDEX_NONE) {
			end = text.Find(TEXT(" "), ESearchCase::IgnoreCase, ESearchDir::FromEnd);
			text = text.Left(end) + "...", charLineCount;
		}
		else {
			if (text.Left(end).Len() < minCharacter) {
				end = text.Find(TEXT(" "), ESearchCase::IgnoreCase, ESearchDir::FromEnd);
				text = text.Left(end) + "...", charLineCount;
			}
			else {
				text = text.Left(end + 1), charLineCount;
			}
		}

		text = WrapText(text, charLineCount);
        if (justify) {
			text = JustifyText(text, charLineCount);
		}
		RandomText = text;
        return true;
	}
	else {
		return false;
	}

}

