#include "stdafx.h"
#include "ExerciseRegistry.h"
#include "DirectXPipeline.h"

LPDIRECT3D9 d3d = NULL;    // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev = NULL;    // the pointer to the device class

void initD3D(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);    // create the Direct3D interface

	D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information

	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
	d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D


	// create a device class using this information and the info from the d3dpp stuct
	d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev);

	ExerciseRegistry::getInstance()->setupPipeline();
}


// this is the function used to render a single frame
void render_frame(void) 
{
	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);

	d3ddev->BeginScene();    // begins the 3D scene

	// do 3D rendering on the back buffer here
	ExerciseRegistry::getInstance()->renderFrame();

	d3ddev->EndScene();    // ends the 3D scene

	d3ddev->Present(NULL, NULL, NULL, NULL);   // displays the created frame on the screen
}


// this is the function that cleans up Direct3D and COM
void cleanD3D(void)
{
	ExerciseRegistry::getInstance()->closePipeline();
	d3ddev->Release();    // close and release the 3D device
	d3d->Release();    // close and release Direct3D
}

void handle(MSG msg) {
	// Only pass on keyboard messages
	if (msg.message >= WM_KEYFIRST && msg.message <= WM_KEYLAST)
		ExerciseRegistry::getInstance()->handle(msg);
}