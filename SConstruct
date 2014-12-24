import os

# Create a debug build by default.
Default('build/debug')

Alias('debug', 'build/debug')
Alias('release', 'build/release')
Alias('all', ['build/debug', 'build/release'])

def build(env, buildDir):
    env.VariantDir(buildDir, 'src', duplicate=1	)
    Export('env')
    SConscript(os.path.join(buildDir, 'SConscript'))

# Debug build.
debug = Environment(CPPPATH=['#/src'])
debug.Append(CCFLAGS = '-O0 -g -Wall')
debug.Append(LINKFLAGS = '-g')
build(debug, 'build/debug')

# Release build.
release = Environment(CPPPATH=['#/src'])
release.Append(CCFLAGS = '-O3 -march=native -mtune=native -mavx -fomit-frame-pointer')
build(release, 'build/release')
