#include "Setup.h"
#include <windows.h>
#include "Globals.h"

void Draw()
{
    ImGui::Begin("Hello AssaultCube", NULL, 
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_MenuBar);

    ImGui::Text("This is the first window");
    ImGui::SliderInt("LocalPlayer Health", &LocalPlayer->Health, 10, 10000);

    //print enemeny positions
    ImGui::Text("Printing local player positon: X: %f Y: %f Z: %f", LocalPlayer->HeadPos.x, LocalPlayer->HeadPos.y, LocalPlayer->HeadPos.z);
    ImGui::SliderFloat("Local player foot height", &LocalPlayer->FeetPos.z, 0.0f, 100.0f);


    //draw a cirlce in centre of screen
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImVec2 screenSize = ImGui::GetWindowSize();
    draw_list->AddRectFilled(ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), ImColor(255, 0, 0, 128));

    ImGui::End();
}


void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int SetupImgui()
{
    // Initialize GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return -1;

    // Setup OpenGL context version (here we're using 3.3)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);



    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui Example", NULL, NULL);
    if (window == NULL)
        return -1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize GLEW to manage OpenGL extensions
    if (glewInit() != GLEW_OK)
        return -1;

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Create a simple ImGui window
        {
            //ImGui::ShowDemoWindow();
            Draw();
           /* ImGui::Begin("Hello, world!");
            ImGui::Text("This is some text.");
            ImGui::SliderFloat("Float", &somefloat, 0.0f, 1.0f);
            ImGui::End()*/;
        }

        // Render ImGui
        ImGui::Render();
        glViewport(0, 0, 1280, 720);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(window);

        //close out of imgui menu
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            break;
        }
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}