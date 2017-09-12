from distutils.core import setup, Extension

mymod = Extension(
    'mymod',
    sources = ['mymod.c']
)

setup(
    name = 'mymod',
    version = '1.0',
    description = 'This is a demo module',
    ext_modules = [mymod]
)
