import os
import shutil

rootEnv = Environment(CCFLAGS = '-Wall')
environments = []
for flags in [['-O2'], ['-g']]:
    env = rootEnv.Clone()
    env.Append(CCFLAGS = flags)
    environments.append(env)
directories = ["release", "debug"]

buildDir = 'bin'
for env, dir in zip(environments, directories):
    SConscript(
        'src/SConscript', 
        variant_dir=os.path.join(buildDir, dir),
        exports={'env': env},
        duplicate=False)
Clean('.', buildDir)
