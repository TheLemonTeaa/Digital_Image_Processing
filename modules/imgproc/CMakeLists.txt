set(SOURCES
    color_rgb.dispatch.cxx
    color.cxx
    transfer.cxx
    histogram.cxx
    # histogram.c
    # blur.c
)

add_library(openHL_imgproc STATIC ${SOURCES})

target_link_libraries(openHL_imgproc PRIVATE openHL_core)