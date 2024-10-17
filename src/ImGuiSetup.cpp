//#include "Setup.h"
//#include <windows.h>
//#include "Globals.h"
//
//bool init = false;
//
//void DrawRendering(HDC hdc)
//{
//	if (!init)
//	{
//		SetupRendering(hdc);
//	}
//
//	auto hglrc = wglGetCurrentContext();
//
//	wglMakeCurrent(hdc, hglrc);
//
//	// Retrieve the display (window) size from the game
//	RECT gameWindowRect;
//	HWND hwnd = FindWindowA(NULL, "AssaultCube"); // Replace this with the correct window name if necessary
//	if (hwnd && GetClientRect(hwnd, &gameWindowRect))
//	{
//		// Set ImGui display size manually
//		ImGuiIO& io = ImGui::GetIO();
//		io.DisplaySize = ImVec2((float)(gameWindowRect.right - gameWindowRect.left), (float)(gameWindowRect.bottom - gameWindowRect.top));
//	}
//	else
//	{
//		std::cerr << "Failed to retrieve window dimensions.\n";
//	}
//
//	// Start ImGui frame
//	ImGui_ImplOpenGL3_NewFrame();
//	ImGui::NewFrame();
//
//	ImGui::Begin("Hello assaultcube", NULL);
//	ImGui::Text("This is the first window");
//
//	ImGui::End();
//	ImGui::Render();
//	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//}
//
//void SetupRendering(HDC hdc)
//{
//	// Ensure OpenGL context is properly active
//	HGLRC hglrc = wglGetCurrentContext();
//
//	if (!hdc || !hglrc)
//	{
//		std::cerr << "Failed to get OpenGL context.\n";
//		return;
//	}
//
//	if (!wglMakeCurrent(hdc, hglrc))
//	{
//		std::cerr << "Failed to activate OpenGL context.\n";
//		return;
//	}
//
//	// Initialize ImGui
//	IMGUI_CHECKVERSION();
//	ImGui::CreateContext();
//
//	// Initialize ImGui for OpenGL 3
//	if (!ImGui_ImplOpenGL3_Init("#version 150"))  // Adjust the version string based on your OpenGL version.
//	{
//		std::cerr << "Failed to initialize ImGui OpenGL3 backend.\n";
//		return;
//	}
//
//	// Initialize the ImGui Win32 backend if the game uses Win32 (skip if unnecessary)
//	// ImGui_ImplWin32_Init(hwnd);  // Uncomment and pass the window handle if using Win32.
//
//	// Set ImGui style (you can customize this if needed)
//	ImGui::StyleColorsDark();
//
//	init = true;  // Ensure you only initialize once
//}
//
//
//void glfw_error_callback(int error, const char* description)
//{
//	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
//}
//
//////{
////	//int SetupImgui()
//////{
////#pragma region GLFW_START_UP
////	// Initialize GLFW
////  //glfwSetErrorCallback(glfw_error_callback);
////  //if (!glfwInit())
////  //    return -1;
////
////  //// Setup OpenGL context version (here we're using 3.3)
////  //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////  //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////  //glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
////
////
////
////  //// Create a GLFW window
////  //GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui Example", NULL, NULL);
////  //if (window == NULL)
////  //    return -1;
////  //glfwMakeContextCurrent(window);
////  //glfwSwapInterval(1); // Enable vsync
////
////  //// Initialize GLEW to manage OpenGL extensions
////  //if (glewInit() != GLEW_OK)
////  //    return -1;
////#pragma endregion
////
////
////	//// Setup Dear ImGui context
////	//IMGUI_CHECKVERSION();
////	//ImGui::CreateContext();
////	//ImGuiIO& io = ImGui::GetIO(); (void)io;
////
////	//// Setup ImGui style
////	//ImGui::StyleColorsDark();
////
////	//// Setup Platform/Renderer bindings
////	////ImGui_ImplGlfw_InitForOpenGL(window, true);
////	//ImGui_ImplOpenGL3_Init("#version 330");
////
////	//// Main loop
////	//while (!glfwWindowShouldClose(window)) {
////	//    glfwPollEvents();
////
////
////
////		// Create a simple ImGui window
////		//{
////			//ImGui::ShowDemoWindow();
////			//Draw();
////		   /* ImGui::Begin("Hello, world!");
////			ImGui::Text("This is some text.");
////			ImGui::SliderFloat("Float", &somefloat, 0.0f, 1.0f);
////			ImGui::End()*/;
////			//}
////
////			// Render ImGui
////			//ImGui::Render();
////			////glViewport(0, 0, 1280, 720);
////			////glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
////			////glClear(GL_COLOR_BUFFER_BIT);
////			//ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
////
////			// Swap buffers
////			//glfwSwapBuffers(window);
////
////		//}
////
////		//// Cleanup
////		//ImGui_ImplOpenGL3_Shutdown();
////		//ImGui_ImplGlfw_Shutdown();
////		//ImGui::DestroyContext();
////
////		//glfwDestroyWindow(window);
////		//glfwTerminate();
////
////		//return 0;
//////}