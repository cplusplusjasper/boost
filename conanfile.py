import os
from conans import ConanFile, CMake

class BOOSTMANConan(ConanFile):
	settings = "os", "compiler", "build_type", "arch"
	requires = "boost/1.75.0@"
	generators = "cmake"

	def imports(self):
		self.copy("*.h", dst="include", src="src")
		self.copy("*.lib", dst="lib", keep_path=False)
		if "cmake_multi" in self.generators:
			self.copy("*.dll", dst="bin/" + str(self.settings.build_type), keep_path=False, excludes="*pgrlm*")
		else:
			self.copy("*.dll", dst="bin/", keep_path=False, excludes="*pgrlm*")
		self.copy("*.dylib", dst="lib", keep_path=False)
		self.copy("*.so", dst="lib", keep_path=False)
		self.copy("*.a", dst="lib", keep_path=False)
