#pragma once

#include <string>

using namespace std;

//compiler switch
#if BUILDING_DLL //c++/preprocessor
	#define TEngineAPI _declspec(dllexport)
#else
	#define TEngineAPI _declspec(dllimport)
#endif

extern "C" string TEngineAPI GetTestString();