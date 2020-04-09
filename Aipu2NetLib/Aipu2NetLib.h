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
		void InitLibrary();
		void LoadConfiguration(LPCWSTR nameFile);
		void SetIsRegister(bool option);
		void SetFileVideo(LPCWSTR file);
		void SetNameWindow(LPCWSTR name);
		void SetWidthFrame(int value);
		void SetHeightFrame(int value);
		void CaptureFlow(int optionFlow);
		void SetIpCamera(LPCWSTR ip);
		void SetDeviceVideo(LPCWSTR device);
		void SetFaceConfidenceThresh(int value);
		void SetRefreshInterval(int value);
		void SetMinEyeDistance(int minDistance);
		void SetMaxEyeDistance(int maxDistance);
		void SetSequenceFps(int fps);
		void SetClient(int value);
		void SetFlagFlow(bool flag);
		void Terminate();
		void ReloadRecognitionFace();
		void SetConfigurationDatabase();
		void ShowWindow(int option);
		void SetIsFinishLoadFiles(bool value);
		bool GetIsFinishLoadFiles();
		void RecognitionFaceFiles(LPCWSTR file, int client);
		void ResetLowScore();
		int GetCountLowScore();
		void ResetCountNotDetect();
		int GetCountNotDetect();
		void SetDeepTrack(LPCWSTR value);
		void ResetCountRepeatUser();
		int GetCountRepeatUser();
		void InitLibraryIdentify();
		void SetTrackingMode(int mode);
		void SetTrackSpeed(int speed);
		void SetMotionOptimization(int motion);
		void StatePlay();
		void StatePaused();
		void SetFramesTotal(unsigned long int total);
	private:

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

		property System::Int32 GetCountLowScore {
			System::Int32 get() {
				return implementAipu->GetCountLowScore();
			}
		}

		property System::Int32 GetCountNotDetect {
			System::Int32 get() {
				return implementAipu->GetCountNotDetect();
			}
		}

		property System::Int32 GetCountRepeatUser {
			System::Int32 get() {
				return implementAipu->GetCountRepeatUser();
			}
		}

		void InitLibrary();

		void LoadConfiguration(System::String ^ fileString);
		void SetIsRegister(System::Boolean option);
		void SetFileVideo(System::String ^ file);
		void SetNameWindow(System::String ^ name);
		void SetWidthFrame(System::Int32 value);
		void SetHeightFrame(System::Int32 value);
		void CaptureFlow(System::Int32 optionFlow);
		void SetIpCamera(System::String ^ ip);
		void SetDeviceVideo(System::String ^ device);
		void SetFaceConfidenceThresh(System::Int32 value);
		void SetRefreshInterval(System::Int32 value);
		void SetMinEyeDistance(System::Int32 minDistance);
		void SetMaxEyeDistance(System::Int32 maxDistance);
		void SetSequenceFps(System::Int32 fps);
		void SetClient(System::Int32 value);
		void SetFlagFlow(System::Boolean flag);
		void Terminate();
		void ReloadRecognitionFace();
		void SetConfigurationDatabase();
		void ShowWindow(System::Int32 option);
		void SetIsFinishLoadFiles(System::Boolean value);
		void RecognitionFaceFiles(System::String ^ file, System::Int32 client);
		void ResetLowScore();
		void ResetCountNotDetect();
		void SetDeepTrack(System::String ^ value);
		void ResetCountRepeatUser();
		void InitLibraryIdentify();
		void SetTrackingMode(System::Int32 mode);
		void SetTrackSpeed(System::Int32 speed);
		void SetMotionOptimization(System::Int32 motion);
		void StatePlay();
		void StatePaused();
		void SetFramesTotal(System::Int32 total);
	protected:
		!AipuNet() {
			delete implementAipu;
		}
	private:
		UnmanagedAipu* implementAipu;
	};
}
