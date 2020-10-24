#include "stdafx.h"

#include "Aipu2NetLib.h"
#include <AipuAPI.h>

using namespace Aipu2NetLib;

AipuAPI* aipuApi;

AipuNet::AipuNet() {
	implementAipu = new UnmanagedAipu();
}

AipuNet::~AipuNet() {
	delete implementAipu;
}



void AipuNet::SetChannel(System::Int32 value) {
	implementAipu->SetChannel(value);
}

void AipuNet::ConnectDatabase() {
	implementAipu->ConnectDatabase();
}

void AipuNet::InitLibrary() {
	implementAipu->InitLibrary();
}

void AipuNet::LoadConfiguration(System::Int32 option) {
	implementAipu->LoadConfiguration(option);
}

void AipuNet::InitWindowMain(System::Int32 option) {
	implementAipu->InitWindowMain(option);
}

void AipuNet::RunVideo(System::Int32 option) {
	implementAipu->RunVideo(option);
}

void AipuNet::ReRunVideo(System::Int32 option) {
	implementAipu->ReRunVideo(option);
}

void AipuNet::CloseWindow() {
	implementAipu->CloseWindow();
}

void AipuNet::SetFinishLoop(System::Int32 option) {
	implementAipu->SetFinishLoop(option);
}


void AipuNet::Terminate() {
	implementAipu->Terminate();
}

void AipuNet::ReloadRecognitionFace() {
	implementAipu->ReloadRecognitionFace();
}


void AipuNet::SetIsFinishLoadFiles(System::Boolean value) {
	if (value.Equals(true))
	{
		implementAipu->SetIsFinishLoadFiles(true);
	}
	else {
		implementAipu->SetIsFinishLoadFiles(false);
	}
	
}

void AipuNet::RecognitionFaceFiles(System::String ^ file, System::Int32 client, System::Int32 task) {
	//pin_ptr<const WCHAR> fileFace = PtrToStringChars(file);

	std::string unmanagedFile = msclr::interop::marshal_as<std::string>(file);

	implementAipu->RecognitionFaceFiles(unmanagedFile, client, task);
	
}

//void AipuNet::ResetPerformance(System::Int32 option) {
//	implementAipu->ResetPerformance(option);
//}
//
//void AipuNet::SavePerformance(System::Int32 option) {
//	implementAipu->SavePerformance(option);
//}


void AipuNet::StatePlay(System::Int32 option) {
	implementAipu->StatePlay(option);
}


void AipuNet::StatePaused(System::Int32 option) {
	implementAipu->StatePaused(option);
}

void AipuNet::LoadConfigurationPipe(System::Int32 pipeline) {
	implementAipu->LoadConfigurationPipe(pipeline);
}

void AipuNet::AddCollectionOfImages(System::String^ folder, System::Int32  client,
	System::Int32  doing) {
	std::string unmanagedFolder = msclr::interop::marshal_as<std::string>(folder);


	//pin_ptr<const WCHAR> folderFace = PtrToStringChars(folder);
	implementAipu->AddCollectionOfImages(unmanagedFolder, client, doing);
}

void AipuNet::SetTaskIdentify(System::Int32 value, System::Int32 option) {
	implementAipu->SetTaskIdentify(value, option);
}

void AipuNet::ResetEnrollVideo(System::Int32 option, System::Int32 value) {
	implementAipu->ResetEnrollVideo(option, value);
}

void AipuNet::SetColourTextFrameOne(System::Single red,
	System::Single green, System::Single blue) {
	implementAipu->SetColourTextFrameOne(red, green, blue);
}

void AipuNet::SetColourTextFrameTwo(System::Single red,
	System::Single green, System::Single blue) {
	implementAipu->SetColourTextFrameTwo(red, green, blue);
}

void AipuNet::SetColourTextFrameThree(System::Single red,
	System::Single green, System::Single blue) {
	implementAipu->SetColourTextFrameThree(red, green, blue);
}

void AipuNet::SetColourTextFrameFour(System::Single red,
	System::Single green, System::Single blue) {
	implementAipu->SetColourTextFrameFour(red, green, blue);
}

void AipuNet::SetNumberPipelines(System::Int32 value) {
	implementAipu->SetNumberPipelines(value);
}

void AipuNet::AddUserEnrollVideo(System::Int32 channel) {
	implementAipu->AddUserEnrollVideo(channel);
}

UnmanagedAipu::UnmanagedAipu()
{
	aipuApi = new AipuAPI();
}

UnmanagedAipu::~UnmanagedAipu()
{
	//delete aipuApi;
}

LPCWSTR UnmanagedAipu::GetError() {
	string messageReceived = aipuApi->GetMessageError();
	wstring wideMessage(messageReceived.begin(), messageReceived.end());
	const wchar_t* resultMessage = wideMessage.c_str();
	return resultMessage;
}

LPCWSTR UnmanagedAipu::GetUser() {
	string user = aipuApi->GetUserJSON();
	wstring wideUser(user.begin(), user.end());
	const wchar_t* resultUser = wideUser.c_str();	
	return resultUser;

}

//void UnmanagedAipu::ResetPerformance(int option) {
//	aipuApi->ResetPerformance(option);
//}
//
//void UnmanagedAipu::SavePerformance(int option) {
//	aipuApi->SavePerformance(option);
//}

void UnmanagedAipu::SetChannel(int value) {
	channel = value;
}

void UnmanagedAipu::ConnectDatabase() {
	aipuApi->ConnectDatabase();
}

void UnmanagedAipu::InitLibrary() {
	aipuApi->InitLibrary();
}

void UnmanagedAipu::LoadConfiguration(int option) {
	aipuApi->LoadConfiguration(option);
}

void UnmanagedAipu::ReRunVideo(int option) {
	aipuApi->ReRunVideo(option);
}

void UnmanagedAipu::InitWindowMain(int option) {
	aipuApi->InitWindowMain(option);
}

void UnmanagedAipu::RunVideo(int option) {
	aipuApi->RunVideo(option);
}

void UnmanagedAipu::SetFinishLoop(int option) {
	aipuApi->SetFinishLoop(option);
}

void UnmanagedAipu::CloseWindow() {
	aipuApi->CloseWindow();
}


void UnmanagedAipu::RecognitionFaceFiles(string file, int client, int task) {
	
	//wstring lpcwstrToWstring(file);

	//string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());	
	try
	{
		aipuApi->RecognitionFaceFiles(file, client, task);
	}
	catch (const std::exception& ex)
	{
		printf(ex.what());
	}
	
}

void UnmanagedAipu::Terminate() {
	aipuApi->Terminate();
}

void UnmanagedAipu::ReloadRecognitionFace() {
	aipuApi->ReloadRecognitionFace();
}

void UnmanagedAipu::SetIsFinishLoadFiles(bool value) {
	aipuApi->SetIsFinishLoadFiles(channel, value);
}

bool UnmanagedAipu::GetIsFinishLoadFiles() {
	return aipuApi->GetIsFinishLoadFiles(channel);
}


void UnmanagedAipu::StatePlay(int option) {
	aipuApi->StatePlay(option);
}

void UnmanagedAipu::StatePaused(int option) {
	aipuApi->StatePaused(option);
}

void UnmanagedAipu::LoadConfigurationPipe(int pipeline) {
	aipuApi->LoadConfigurationPipe(pipeline);
}

void UnmanagedAipu::AddCollectionOfImages(string folder, int client, int doing) {
	//wstring lpcwstrToWstring(folder);
	//string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());
	try
	{		
		aipuApi->AddCollectionOfImages(folder, client, doing);
	}
	catch (const std::exception& ex)
	{
		printf(ex.what());
	}
	
}

void UnmanagedAipu::SetTaskIdentify(int value, int option) {
	aipuApi->SetTaskIdentify(value, option);
}

void UnmanagedAipu::ResetEnrollVideo(int option, int value) {
	aipuApi->ResetEnrollVideo(option, value);
}

void UnmanagedAipu::SetColourTextFrameOne(float red, float green, float blue) {
	aipuApi->SetColourTextFrameOne(red, green, blue);
}

void UnmanagedAipu::SetColourTextFrameTwo(float red, float green, float blue) {
	aipuApi->SetColourTextFrameTwo(red, green, blue);
}

void UnmanagedAipu::SetColourTextFrameThree(float red, float green, float blue) {
	aipuApi->SetColourTextFrameThree(red, green, blue);
}

void UnmanagedAipu::SetColourTextFrameFour(float red, float green, float blue) {
	aipuApi->SetColourTextFrameFour(red, green, blue);
}

void UnmanagedAipu::SetNumberPipelines(int value) {
	aipuApi->SetNumberPipelines(value);
}

void UnmanagedAipu::AddUserEnrollVideo(int channel) {
	aipuApi->AddUserEnrollVideo(channel);
}