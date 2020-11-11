#pragma once

#include <windows.h>
#include <vcclr.h>
#using <System.dll>
#using <System.Drawing.dll>
#include <string>
#include <array>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Drawing;
using namespace std;

namespace Aipu2NetLib {

	class UnmanagedAipu
	{
	public:
		UnmanagedAipu();
		~UnmanagedAipu();
		LPCWSTR GetError();
		LPCWSTR GetUser();
		LPCWSTR GetTemplateJSON();
		void ConnectDatabase();
		void InitLibrary();
		void LoadConfiguration(int option);
		void InitWindowMain(int option);
		void RunVideo(int option);
		void LoadConfigurationPipe(int pipeline);
		void ReRunVideo(int option);
		void CloseWindow();
		
		void Terminate();
		void ReloadRecognitionFace();
		
		void SetIsFinishLoadFiles(bool value);
		bool GetIsFinishLoadFiles();
		void RecognitionFaceFiles(string file, int client, int task);
		
		void StatePlay(int option);
		void StatePaused(int option);
		void SetFinishLoop(int option);
		void SetChannel(int value);
		
		void AddCollectionOfImages(string folder, int client, int doing);
		void SetTaskIdentify(int value, int option);
		void ResetEnrollVideo(int option, int value);
		void SetColourTextFrameOne(float red, float green, float blue);
		void SetColourTextFrameTwo(float red, float green, float blue);
		void SetColourTextFrameThree(float red, float green, float blue);
		void SetColourTextFrameFour(float red, float green, float blue);
		void SetNumberPipelines(int value);
		void AddUserEnrollVideo(int channel);		
		void CloseConnectionIdentification(int channel);
		void LoadConnectionIdentification(int channel);
		int GetTaskIdentify();
		void DownConfigurationModel(int channel);
		void LoadConfigurationModel(int channel);
		void LoadConfigurationIdentify(int channel); // CloseConnectionIdentification 
		void LoadConfigurationTracking(int channel); // SetFinishLoop
		bool GetIsLoadConfiguration();
		
	private:
		int channel;
	};

	
	public ref class AipuNet
	{
	public:
		AipuNet();
		~AipuNet();
		property System::String ^  GetError {
			System::String ^ get() {
				return gcnew System::String(implementAipu->GetError());
			}
		}

		property System::String ^  GetUser {
			System::String ^ get() {
				return gcnew System::String(implementAipu->GetUser());
			}
		}

		property System::Boolean GetIsFinishLoadFiles {
			System::Boolean get() {
				return implementAipu->GetIsFinishLoadFiles();
			}
		}

		property System::String ^ GetTemplateJSON {
			System::String ^ get() {
				return gcnew System::String(implementAipu->GetTemplateJSON());
			}
		}

		property System::Int16 GetTaskIdentify {
			System::Int16 get() {
				return implementAipu->GetTaskIdentify();
			}
		}

		property System::Boolean GetIsLoadConfiguration {
			System::Boolean get() {
				return implementAipu->GetIsLoadConfiguration();
			}
		}
		

		void ConnectDatabase();
		void InitLibrary();
		void LoadConfiguration(System::Int32 option);
		void InitWindowMain(System::Int32 option);
		void RunVideo(System::Int32 option);
		void ReRunVideo(System::Int32 option);
		void CloseWindow();
		void SetFinishLoop(System::Int32 option);
		
		void Terminate();
		void ReloadRecognitionFace();
		
		void SetIsFinishLoadFiles(System::Boolean value);
		void RecognitionFaceFiles(System::String ^ file, System::Int32 client, System::Int32 task);
		void AddCollectionOfImages(System::String^ folder, System::Int32  client,
			System::Int32  doing);
		void StatePlay(System::Int32 option);
		void StatePaused(System::Int32 option);
		void SetChannel(System::Int32 value);
		
		void LoadConfigurationPipe(System::Int32 pipeline);
		void SetTaskIdentify(System::Int32 value, System::Int32 option);
		void ResetEnrollVideo(System::Int32 option, System::Int32 value);
		void SetColourTextFrameOne(System::Single red, System::Single green, System::Single blue);
		void SetColourTextFrameTwo(System::Single red, System::Single green, System::Single blue);
		void SetColourTextFrameThree(System::Single red, System::Single green, System::Single blue);
		void SetColourTextFrameFour(System::Single red, System::Single green, System::Single blue);
		void SetNumberPipelines(System::Int32 value);
		void AddUserEnrollVideo(System::Int32 channel);		
		void CloseConnectionIdentification(System::Int32 channel);
		void LoadConnectionIdentification(System::Int32 channel);
		void DownConfigurationModel(System::Int32 channel);
		void LoadConfigurationModel(System::Int32 channel);
		void LoadConfigurationIdentify(System::Int32 channel); // CloseConnectionIdentification 
		void LoadConfigurationTracking(System::Int32 channel); // SetFinishLoop
	protected:
		!AipuNet() {
			delete implementAipu;
		}
	private:
		UnmanagedAipu* implementAipu;
	};
}
