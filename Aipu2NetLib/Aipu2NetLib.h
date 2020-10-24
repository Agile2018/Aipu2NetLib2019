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
		//void ResetPerformance(int option);
		//void SavePerformance(int option);
		void AddCollectionOfImages(string folder, int client, int doing);
		void SetTaskIdentify(int value, int option);
		void ResetEnrollVideo(int option, int value);
		void SetColourTextFrameOne(float red, float green, float blue);
		void SetColourTextFrameTwo(float red, float green, float blue);
		void SetColourTextFrameThree(float red, float green, float blue);
		void SetColourTextFrameFour(float red, float green, float blue);
		void SetNumberPipelines(int value);
		void AddUserEnrollVideo(int channel);
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
		//void ResetPerformance(System::Int32 option);
		//void SavePerformance(System::Int32 option);
		void LoadConfigurationPipe(System::Int32 pipeline);
		void SetTaskIdentify(System::Int32 value, System::Int32 option);
		void ResetEnrollVideo(System::Int32 option, System::Int32 value);
		void SetColourTextFrameOne(System::Single red, System::Single green, System::Single blue);
		void SetColourTextFrameTwo(System::Single red, System::Single green, System::Single blue);
		void SetColourTextFrameThree(System::Single red, System::Single green, System::Single blue);
		void SetColourTextFrameFour(System::Single red, System::Single green, System::Single blue);
		void SetNumberPipelines(System::Int32 value);
		void AddUserEnrollVideo(System::Int32 channel);
	protected:
		!AipuNet() {
			delete implementAipu;
		}
	private:
		UnmanagedAipu* implementAipu;
	};
}
