import os

# Create a debug build by default.
Default('build/debug')

Alias('debug', 'build/debug')
Alias('release', 'build/release')
Alias('all', ['build/debug', 'build/release'])

def build(env, buildDir):
    env.VariantDir(buildDir + '/external', 'external', duplicate=0)
    env.VariantDir(buildDir + '/src', 'src', duplicate=0)
    env.VariantDir(buildDir + '/test', 'test', duplicate=0)
    env.Replace(LINK='g++')
    gtest = SConscript(os.path.join(buildDir, 'external/gtest', 'SConscript'), 'env')
    src = SConscript(os.path.join(buildDir, 'src', 'SConscript'), 'env')
    out = SConscript(os.path.join(buildDir, 'test', 'SConscript'), 'env gtest src')
    #test = Command(target = buildDir+"/testoutput",
    #               source = str(out[0]),
    #               action = str(out[0]))
    #AlwaysBuild(test)

# Debug build.
debug = Environment(CPPPATH=['#/src', '#/external'])
debug.Append(CCFLAGS = '-std=c++14 -O0 -g3 -Wall -ftest-coverage -fprofile-arcs `libpng-config --cflags`')
debug.Append(LINKFLAGS = '-g3 -lgcov -coverage `libpng-config --ldflags`')
build(debug, 'build/debug')

# Release build.
release = Environment(CPPPATH=['#/src', '#/external'])
release.Append(CCFLAGS = '-std=c++14 -O3 -g3 -march=native -mtune=native -mavx `libpng-config --cflags`')
release.Append(LINKFLAGS = '`libpng-config --ldflags`')
build(release, 'build/release')
