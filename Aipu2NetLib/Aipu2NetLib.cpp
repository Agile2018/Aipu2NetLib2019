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

void AipuNet::InitWindowMain(System::Int32 option, System::String^ channels) {
	std::string unmanagedChannels = msclr::interop::marshal_as<std::string>(channels);
	implementAipu->InitWindowMain(option, unmanagedChannels);
}

void AipuNet::RunVideo(System::Int32 option, System::String^ channels) {
	std::string unmanagedChannels = msclr::interop::marshal_as<std::string>(channels);
	implementAipu->RunVideo(option, unmanagedChannels);
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

void AipuNet::RecognitionFaceFiles(System::String^ nameFile,
	System::Int32 client, System::Int32 task) {
	
		
	/*std::vector<string> listFilesUnmanaged;

	for each (auto str in listFiles) {
		std::string unmanagedFile = msclr::interop::marshal_as<std::string>(str);
		listFilesUnmanaged.push_back(unmanagedFile);
	}*/

	std::string unmanagedFile = msclr::interop::marshal_as<std::string>(nameFile);
	implementAipu->RecognitionFaceFiles(unmanagedFile, client, task);
}

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


void AipuNet::SetNumberPipelines(System::Int32 value) {
	implementAipu->SetNumberPipelines(value);
}

void AipuNet::AddUserEnrollVideo(System::Int32 channel) {
	implementAipu->AddUserEnrollVideo(channel);
}

void AipuNet::CloseConnectionIdentification(System::Int32 channel) {
	implementAipu->CloseConnectionIdentification(channel);
}

void AipuNet::LoadConnectionIdentification(System::Int32 channel) {
	implementAipu->LoadConnectionIdentification(channel);
}

void AipuNet::DownConfigurationModel(System::Int32 channel) {
	implementAipu->DownConfigurationModel(channel);
}
void AipuNet::LoadConfigurationModel(System::Int32 channel) {
	implementAipu->LoadConfigurationModel(channel);
}
void AipuNet::LoadConfigurationIdentify(System::Int32 channel) {
	implementAipu->LoadConfigurationIdentify(channel);
}
void AipuNet::LoadConfigurationTracking(System::Int32 channel) {
	implementAipu->LoadConfigurationTracking(channel);
}

void AipuNet::SetColourLabelFrame(System::Int32 indexFrame, System::Single red,
	System::Single green, System::Single blue) {
	implementAipu->SetColourLabelFrame(indexFrame, red, green, blue);
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

void UnmanagedAipu::InitWindowMain(int option, string channels) {
	aipuApi->InitWindowMain(option, channels);
}

void UnmanagedAipu::RunVideo(int option, string channels) {
	aipuApi->RunVideo(option, channels);
}

void UnmanagedAipu::SetFinishLoop(int option) {
	aipuApi->SetFinishLoop(option);
}

void UnmanagedAipu::CloseWindow() {
	aipuApi->CloseWindow();
}


void UnmanagedAipu::RecognitionFaceFiles(string nameFile, int client, int task) {
	
	//wstring lpcwstrToWstring(file);

	//string wStringToString(lpcwstrToWstring.begin(), lpcwstrToWstring.end());	
	
	aipuApi->RecognitionFaceFiles(nameFile, client, task);
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

void UnmanagedAipu::SetNumberPipelines(int value) {
	aipuApi->SetNumberPipelines(value);
}

void UnmanagedAipu::AddUserEnrollVideo(int channel) {
	aipuApi->AddUserEnrollVideo(channel);
}

LPCWSTR UnmanagedAipu::GetTemplateJSON() {
	string templateImage = aipuApi->GetTemplateJSON();
	wstring wideTemplate(templateImage.begin(), templateImage.end());
	const wchar_t* resultTemplate = wideTemplate.c_str();
	return resultTemplate;
}

void UnmanagedAipu::CloseConnectionIdentification(int channel) {
	aipuApi->CloseConnectionIdentification(channel);
}

void UnmanagedAipu::LoadConnectionIdentification(int channel) {
	aipuApi->LoadConnectionIdentification(channel);
}

int UnmanagedAipu::GetTaskIdentify() {
	return aipuApi->GetTaskIdentify(channel);
}

void UnmanagedAipu::DownConfigurationModel(int channel) {
	aipuApi->DownConfigurationModel(channel);
}

void UnmanagedAipu::LoadConfigurationModel(int channel) {
	aipuApi->LoadConfigurationModel(channel);
}
void UnmanagedAipu::LoadConfigurationIdentify(int channel) {
	aipuApi->LoadConfigurationIdentify(channel);
}

void UnmanagedAipu::LoadConfigurationTracking(int channel) {
	aipuApi->LoadConfigurationTracking(channel);
}

bool UnmanagedAipu::GetIsLoadConfiguration() {
	return aipuApi->GetIsLoadConfiguration(channel);
}

void UnmanagedAipu::SetColourLabelFrame(int indexFrame, float red, float green, float blue) {
	aipuApi->SetColourLabelFrame(indexFrame, red, green, blue);
}

