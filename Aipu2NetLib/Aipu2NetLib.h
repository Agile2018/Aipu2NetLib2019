#pragma once

#include <windows.h>
#include <vcclr.h>
#using <System.dll>
#using <System.Drawing.dll>
#include <string>
#include <array>

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
		void RecognitionFaceFiles(LPCWSTR file, int client);
		
		void StatePlay(int option);
		void StatePaused(int option);
		void SetFinishLoop(int option);
		void SetChannel(int value);
		void ResetPerformance(int option);
		void SavePerformance(int option);
		
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
		void RecognitionFaceFiles(System::String ^ file, System::Int32 client);
		
		void StatePlay(System::Int32 option);
		void StatePaused(System::Int32 option);
		void SetChannel(System::Int32 value);
		void ResetPerformance(System::Int32 option);
		void SavePerformance(System::Int32 option);
		void LoadConfigurationPipe(System::Int32 pipeline);
	protected:
		!AipuNet() {
			delete implementAipu;
		}
	private:
		UnmanagedAipu* implementAipu;
	};
}
