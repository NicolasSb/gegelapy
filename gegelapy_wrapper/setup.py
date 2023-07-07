from setuptools import setup, Extension

library_dirs = ['/usr/local/lib/']
runtime_library_dirs = ['/usr/local/lib/']

extensions = [
    Extension('data._dataHandler', ['data/_dataHandler.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('data._pointerWrapper', ['data/_pointerWrapper.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('file._parametersParser', ['file/_parametersParser.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('file._tpgGraphDotExporter', ['file/_tpgGraphDotExporter.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('instructions._lambdaInstruction', ['instructions/_lambdaInstruction.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('instructions._set', ['instructions/_set.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('learn._learningAgent', ['learn/_learningAgent.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('learn._learningEnvironment', ['learn/_learningEnvironment.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('learn._learningParameters', ['learn/_learningParameters.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('learn._parallelLearningAgent', ['learn/_parallelLearningAgent.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('log._laBasicLogger', ['log/_laBasicLogger.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('log._laPolicyStatsLogger', ['log/_laPolicyStatsLogger.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('mutator._rng', ['mutator/_rng.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('tpg._policyStats', ['tpg/_policyStats.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs),
    Extension('tpg._tpgExecutionEngine', ['tpg/_tpgExecutionEngine.cpp'], libraries=['GEGELATI'], include_dirs=['/usr/local/include/GEGELATI/include/'], runtime_library_dirs=runtime_library_dirs)
]

setup(
    name='gegelapy',
    version='1.0',
    packages=['data', 'file', 'instructions', 'learn', 'log', 'mutator', 'tpg'],
    ext_modules=extensions
)
