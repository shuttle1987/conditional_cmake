"""Utilities for building binaries"""

class BuildSystem:
    """Build system configuration"""
    def __init__(self, project_name, source_directory):
        self.project_name = project_name
        self.source_directory = source_directory

    def build_binaries(self):
        raise NotImplementedError("Implement this in child classes")


class CMakeBuild(BuildSystem):
    def __init__(self):
        raise NotImplementedError
