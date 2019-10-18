project('CrapCasting', 'cpp')

incdir = include_directories('include')
opencv_dep = dependency('opencv4')
caca_dep = dependency('caca')

crapcasting_sources = files(['src/raycasting/maprenderer.cpp',
                             'src/raycasting/ProjectionRenderer.cpp',
                             'src/raycasting/CvProjectionRenderer.cpp',
                             'src/raycasting/CacaProjectionRenderer.cpp'])
                                                              
crapcasting = shared_library('crapcasting', [crapcasting_sources],
                              dependencies: [opencv_dep, caca_dep],
                              include_directories: incdir)

executable('crapcasting-run', 'src/run/main.cpp',
                               dependencies: [opencv_dep, caca_dep],
                               include_directories: incdir, link_with: crapcasting)
