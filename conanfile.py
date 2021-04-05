from conans import ConanFile


class OpenGL(ConanFile):
    settings = "os", "arch", "build_type", "compiler"
    requires = (
        "opengl/system",
        "glfw/3.3.3",
        "glew/2.2.0",
        "cimg/2.9.4",
        "glm/0.9.9.8"
    )
    generators = "cmake"

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin") # From bin to bin
        self.copy("*.dylib*", dst="bin", src="venv/Lib") # From lib to bin
