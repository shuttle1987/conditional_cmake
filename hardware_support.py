class Architecture:
    """The instruction set architecture"""
    def __init__(self, name, runtime_check):
        """
        :name: The name of the architecture
        :runtime_check: a function to test at runtime if the code is running
                        on this architecture.
        """
        self.name = name
        self.runtime_check = runtime_check

    def __repr__(self):
        return "Architecture({},{})".format(
            self.name,
            self.runtime_check
        )


class InstructionSet:
    """The instruction set being supported"""
    def __init__(self, architecture, name, runtime_check):
        """
        :name: The name of the instruction set that needs to be supported
               examples Intel: SSE, AVX
                        ARM: NEON
        :runtime_check: A function to test at runtime if this instruction
                        set is supported
        """
        self.architecture = architecture
        self.name = name
        self.runtime_check = runtime_check

    def __repr__(self):
        return "InstructionSet({},{},{})".format(
            self.architecture,
            self.name,
            self.runtime_check
        )
