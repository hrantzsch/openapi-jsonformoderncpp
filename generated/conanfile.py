from conans import ConanFile, CMake, tools
from shutil import copytree
import os

class GeneratedDtos(ConanFile):
    name = "myPetProject"
    homepage = "https://github.com/petstore/petproject"
    generators = "cmake_find_package"
    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False]}
    default_options = {"shared": True}

    _source_subfolder = "sources"
    _build_subfolder = "build"

    def requirements(self):
        self.requires("nlohmann_json/3.7.3")

    def source(self):
        if not self.homepage.startswith("http"):
            # _temporary_ hack to debug locally
            copytree(self.homepage, self._source_subfolder)
        else:
            tools.get(self.homepage, destination=self._source_subfolder)

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure(build_folder=self._build_subfolder, source_folder=self._source_subfolder)
        return cmake

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["myPetProject"]
