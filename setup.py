from setuptools import setup, Extension

class Platform:
    """Represent a platform to compile to"""
    def __init__(self, plaftorm_name, platform_config_path):
        self.platform_name = platform_name
        self.platform_config_path = platform_config_path


BASE_NAME = 'vector_conditional_compile_example'

# Specify C/C++ extensions to build

python_cAPI_sources = ['external/python_bindings']
architectures = []
instruction_sets = []

# Specify external compiled code

# Build the extensions and libraries

built_extensions = []
for arch in architectures:
    # Build top level for this arch
    for instruction_set in intruction_sets:
        if instruction_set.architecture == arch:
            # Build external library to link against

            # Build Python extension for this platform/arch
            current_extension = Extension('{}.{}_{}'.format(BASE_NAME, arch.name, instruction_set.name)),
                sources=python_cAPI_sources,
                language='c',
            )
            built_extensions.append(current_extension)

# create top level module

# Run setup.py to create package

setup(
    name=BASE_NAME,
    version='0.1',
    description='Cross compiled python pacakges',
    author='Janis Lesinskis',
    ext_modules=[built_extensions]
)
