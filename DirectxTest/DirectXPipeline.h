#ifndef _DIRECTX_PIPELINE_
#define _DIRECTX_PIPELINE_

// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")

// function prototypes
void initD3D(HWND hWnd);    // sets up and initializes Direct3D
void render_frame(void);    // renders a single frame
void cleanD3D(void);    // closes Direct3D and releases memory
void handle(MSG msg);   // handles message

#endif