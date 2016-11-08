# Expects gtestLibDep and gmockLibDep to be defined
# in the meson.build file that calls this file.

# gprint library
gprintSrc = [
    'src/main/ConfigurableEventListener.cpp'
    , 'src/main/TestListenerUtils.cpp'
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

# gprint library (gtest main)
gprintGtestMainLib = static_library(
    'gprintGtestMainLib'
    , sources : 'src/gtestMain.cpp'
    , dependencies : [gprintLibDep, gtestLibDep]
)
gprintGtestMainLibDep = declare_dependency(
    link_with : gprintGtestMainLib
    , include_directories : gprintInc
    , dependencies : [gprintLibDep, gtestLibDep]
)

# gprint library (gmock main)
gprintGmockMainLib = static_library(
    'gprintGmockMainLib'
    , sources : 'src/gmockMain.cpp'
    , dependencies : [gprintLibDep, gtestLibDep, gmockLibDep]
)
gprintGmockMainLibDep = declare_dependency(
    link_with : gprintGmockMainLib
    , include_directories : gprintInc
    , dependencies : [gprintLibDep, gtestLibDep, gmockLibDep]
)
