import os

# Create a debug build by default.
Default('build/debug')

Alias('debug', 'build/debug')
Alias('release', 'build/release')
Alias('all', ['build/debug', 'build/release'])

def build(env, buildDir):
    env.VariantDir(buildDir + '/external', 'external', duplicate=1)
    env.VariantDir(buildDir + '/src', 'src', duplicate=1)
    env.VariantDir(buildDir + '/test', 'test', duplicate=1)
    Export('env')
    SConscript(os.path.join(buildDir, 'external', 'SConscript'))
    SConscript(os.path.join(buildDir, 'src', 'SConscript'))
    SConscript(os.path.join(buildDir, 'test', 'SConscript'))

# Debug build.
debug = Environment(CPPPATH=['#/src'])
debug.Append(CCFLAGS = '-std=c++14 -O0 -g -Wall')
debug.Append(LINKFLAGS = '-g')
build(debug, 'build/debug')

# Release build.
release = Environment(CPPPATH=['#/src'])
release.Append(CCFLAGS = '-std=c++14 -O3 -march=native -mtune=native -mavx -fomit-frame-pointer')
build(release, 'build/release')
