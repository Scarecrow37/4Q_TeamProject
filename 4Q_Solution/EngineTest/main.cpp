#include "pch.h"
#include "GameApplication.h"\

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	GameApplication app(hInstance);

	app.InitializeManagers();
	app.CreateContents();
	app.InitializeContents();
	app.Run(nCmdShow);
	app.FinalizeContents();
	app.DeleteContents();
	app.FinalizeManagers();

	return 0;
}
