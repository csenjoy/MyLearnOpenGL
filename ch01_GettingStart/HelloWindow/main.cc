#include <glad/glad.h>
#include <GLFW/glfw3.h>


#define LOG_ERROR(...)

static void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

static void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

int main(int argc, char **argv) {

  /**
   * @brief # glfwInit and glfwWindowHint
   *
   */
  int ret = glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


#if (MAC_OS_X)
  /**
   * @brief Note that on Mac OS X you need to add GLFW_OPENGL_FORWARD_COMPAT
   * 
   */
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  /**
   * @brief Make sure you have OpenGL versions 3.3 or higher installed on your system
   *At Window downlaod glview tool application.
  */


  /**
   * @brief  # Create glfw Window
   *          ## Ceate GLFWwindow
   *
  */
  GLFWwindow *window = glfwCreateWindow(800, 600, "Hello GLFW3", NULL, NULL);
  if (window == nullptr) {
    LOG_ERROR("Failed to create GLFW window");
    glfwTerminate();
    return -1;
  }
  /**
   * @brief Fix glfwGetProcAddress("glGetString") return nullptr
   * 
   */
  glfwMakeContextCurrent(window);
  /**
   * @brief # gladLoadGLLoader
   *          ## GLAD manages function pointers for OpenGL so we want to initialize GLAD before
   *           we call any OpenGL function
  */
  ret = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  if (!ret) {
    LOG_ERROR("Failed to initialize GLAD");
    return -1;
  }

  /**
   * @brief # glViewPort
   *          ## Tell OpenGL the rendering size of the window.
   *          ## The coordinate (0,0) is the lower left corner of window.
   *          ## We could actually set the size samller than the size used create window
   * 
   *          ## OpenGL coordinates range (-1,1). so (-0.5, 0.5) would be mapped to (800 / 4 * 1, 600 / 4 * 3)
   */
  glViewport(0, 0, 800, 600);

  /**
   * @brief # glfwSetFramebufferSizeCallback to register window framebuffer size changed callback
   * 
   */
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  /**
   * @brief # glfwPollEvents to ready your engines
   * 
   */
  while(!glfwWindowShouldClose(window)) {
    processInput(window);
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  /**
   * @brief # glfwTerminate to exit 
   * 
   */
  glfwTerminate();
  return 0;
}