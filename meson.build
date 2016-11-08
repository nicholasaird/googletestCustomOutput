# Expects gtestLibDep and gmockLibDep to be defined
# in the meson.build file that calls this file.

project('gprint', 'cpp')

gprintSrc = [
    'main/ConfigurableEventListener.cpp'
    , 'main/EventListenerUtils.cpp'
]
gprintInc = include_directories('src/main')
gprintLib = static_library(
    'gprintLib'
    , sources : gprintSrc
    , include_directories : gprintInc
    , dependencies : gtestLibDep
)
gprintLibDep = declare_dependency(
    link_with : gprintLib
    , include_directories : gprintInc
    , dependencies : gtestLibDep
)

gprintGtestMainLib = static_library(
    'gprintGtestMainLib'
    , sources : 'src/gtestMain.cpp'
    , dependencies : gprintLibDep
)

gprintGmockMainLib = static_library(
    'gprintGmockMainLib'
    , sources : 'src/gmockMain.cpp'
    , dependencies : gprintLibDep
)
