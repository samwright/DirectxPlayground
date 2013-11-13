#include "stdafx.h"
#include "DirectXPipeline.h"
#include "TriangleExercise.h"

struct CUSTOMVERTEX { FLOAT X, Y, Z, RHW; DWORD COLOR; };
#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
char const *TriangleExercise::name = "Triangle Exercise";
LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;

void TriangleExercise::setupPipeline() {
	// create the vertices using the CUSTOMVERTEX struct
	CUSTOMVERTEX vertices[] =
	{
		{ 400.0f, 62.5f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 0, 255), },
		{ 650.0f, 500.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 255, 0), },
		{ 150.0f, 500.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(255, 0, 0), },
	};

	// create a vertex buffer interface called v_buffer
	d3ddev->CreateVertexBuffer(3 * sizeof(CUSTOMVERTEX),
		0,
		CUSTOMFVF,
		D3DPOOL_MANAGED,
		&v_buffer,
		NULL);

	VOID* pVoid;    // a void pointer

	// lock v_buffer and load the vertices into it
	v_buffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, sizeof(vertices));
	v_buffer->Unlock();
}

void TriangleExercise::renderFrame() {
	// select which vertex format we are using
	d3ddev->SetFVF(CUSTOMFVF);

	// select the vertex buffer to display
	d3ddev->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));

	// copy the vertex buffer to the back buffer
	d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}

void TriangleExercise::closePipeline() {
	v_buffer->Release();    // close and release the vertex buffer
}

void TriangleExercise::handle(MSG &msg) {

}