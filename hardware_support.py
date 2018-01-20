class Architecture:
    """The instruction set architecture"""
    def __init__(self, name, runtime_check):
        """
        :name: The name of the architecture
        :runtime_check: a function to test at runtime if the code is running
                        on this architecture.
        """
        raise NotImplementedError

class InstructionSet:
    """The instruction set being supported"""
    def __init__(self, name, runtime_check):
        """
        :name: The name of the instruction set that needs to be supported
               examples Intel: SSE, AVX
                        ARM: NEON
        :runtime_check: A function to test at runtime if this instruction
                        set is supported
        """
        raise NotImplementedError
