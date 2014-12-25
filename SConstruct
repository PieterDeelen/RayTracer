import os

# Create a debug build by default.
Default('build/debug')

Alias('debug', 'build/debug')
Alias('release', 'build/release')
Alias('all', ['build/debug', 'build/release'])

def build(env, buildDir):
    env.VariantDir(buildDir, 'src', duplicate=1)
    Export('env')
    SConscript(os.path.join(buildDir, 'SConscript'))

def build_test(env, buildDir):
    env.VariantDir(buildDir, 'test', duplicate=1)
    Export('env')
    SConscript(os.path.join(buildDir, 'SConscript'))

# Debug build.
debug = Environment(CPPPATH=['#/src'])
debug.Append(CCFLAGS = '-std=c++14 -O0 -g -Wall')
debug.Append(LINKFLAGS = '-g')
build(debug, 'build/debug')

test = Environment(CPPPATH=['#/src', '#/test', '#/external'])
test.Append(CCFLAGS = '-std=c++14 -O0 -g -Wall')
test.Append(LINKFLAGS = '-g')
build_test(test, 'build/test')

# Release build.
release = Environment(CPPPATH=['#/src'])
release.Append(CCFLAGS = '-std=c++14 -O3 -march=native -mtune=native -mavx -fomit-frame-pointer')
build(release, 'build/release')
