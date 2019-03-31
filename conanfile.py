from conans import ConanFile
from conans.tools import os_info

class TrompeloeilExample(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'cmake'

    def requirements(self):
        self.requires('Catch2/2.7.0@catchorg/stable')
        self.requires('trompeloeil/v33@rollbear/stable')
